/*
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */
#if CHIP_TYPE == CHIP_TYPE_AT90CANxxx

#include "Port.h"
#include <stddef.h>

#ifndef F_CPU
#define F_CPU 16000000L
#endif

#include "config.h"

#define CAN_1000_BAUD 0x020413L
#define CAN_500_BAUD 0x060413L
#define CAN_250_BAUD 0x0E0413L
#define CAN_125_BAUD 0x1E0413L
#define CAN_100_BAUD 0x260413L

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t msgs_av; //Number of messages unclaimed messages
volatile uint8_t rxed_mobs[2]; //Tracks which MObs have messages received

uint8_t devGrp, devSer;

/*Selects the MOB to operate on*/
void inline select_mob(uint8_t mob){
	CANPAGE = ((mob & 0x0F) << 4);
}

/*Disables the interrupt for the specified MOb*/
void disable_mob_interrupt(uint8_t mob){
	if(mob < 8){
		CANIE2 &= ~(1 << mob);
		} else {
		CANIE1 &= ~(1 << (mob - 8));
	}
}

/*Enable the interrupt for the specified MOb*/
void enable_mob_interrupt(uint8_t mob){
	if(mob < 8){
		CANIE2 |= (1 << mob);
		} else {
		CANIE1 |= (1 << (mob - 8));
	}
}

/*CAN controller interrupt handler*/
ISR(CANIT_vect){
	uint8_t canpage = CANPAGE; //Save CAN page
	if((CANHPMOB & 0xF0) != 0xF0){ //Message io?
		int mob = (CANHPMOB >> 4);
		select_mob(mob);
		if(CANSTMOB & (1 << TXOK)){ //TX
			/*Reset the MOb*/
			CANSTMOB &= 0;
			CANCDMOB = 0;
			enable_mob_interrupt(mob);
		} else { //RX
			msgs_av++; //Increase count of messages
			rxed_mobs[!!(mob & 8)] |= (1 << (mob & 7)); // Mark which MOb has a message
			CANSTMOB &= 0; //Reset the MOb
			disable_mob_interrupt(mob);
		}
	} else {
		CANGIT |= 0; //Error interrupt - Handle these?
	}
	CANPAGE = canpage; //restore CAN page
}

/*Reset the receive filter for the given MOb*/
void set_mob_rx_filter(int mob){
	select_mob(mob);
	uint16_t RX_mask = 0x3FF; // mask out priority bit, compare on everything else
	uint16_t RX_tag = 0x3F; //0th MOb is for broadcast packets, group = 0, serial = 0x3F
	if(mob > 0 && mob <= 2){ //1st und 2nd MOb is for device group broadcasts, match device group and 0x3F serial
		RX_tag = (devGrp << 6) | 0x3F;
	} else if(mob > 2 && mob <= 4){ //2nd and 3rd MOb is for the device specific message. Match the whole ID
		RX_tag = (devGrp << 6) | devSer;
	}

	CANIDM4 = 0;
	CANIDM3 = 0;
	CANIDT4 = 0;
	CANIDT3 = 0;
	CANIDT2 = ((RX_tag & 7) << 5);
	CANIDT1 = ((RX_tag & 0x7F8) >> 3);
	CANIDM2 = ((RX_mask & 7) << 5);
	CANIDM1 = ((RX_mask & 0x7F8) >> 3);
}

/*Initalizes and enables the CAN controller
Parameters:
uint32_t rate: the baud rate selection
uint8_t txmobs: how many MOBs to dedicate to transmission
uint8_t mode: The mode to operate the CAN controller in
*/
void init_CAN(uint32_t rate, uint16_t deviceGroup, uint16_t deviceSerial){
	CANGCON |= (1<<SWRES); //reset the CAN controller
	devGrp = deviceGroup; //Save the device group and serial
	devSer = deviceSerial;
	_delay_ms(100); //The CAN controller is a slow bitch to reset. Twiddle our thumbs while it resets
	/*Set up the rate*/
	CANBT1 = (uint32_t)(rate & 0xFF0000L) >> 16;
	CANBT2 = (uint32_t)(rate & 0x00FF00L) >> 8;
	CANBT3 = (uint32_t)(rate & 0x0000FFL);
	CANGIE = (1 << CANIT) | (1 << ENRX) | (1 << ENTX); //Enable CAN interrupts
	CANTCON = 255; //Set the can timer to run at 1/2048th of F_CPU
	rxed_mobs[0] = rxed_mobs[1] = 0;
	uint8_t i;
	/*Initialize MOBs*/
	for(i = 0;i < 15;i++){
		if(i <= 4){ /*MObs <= 4 are RX mobs*/
			/*Set up the match registers*/
			CANSTMOB &= 0;
			set_mob_rx_filter(i);
			CANCDMOB = (1 << CONMOB1); //Mark RX mobs
			enable_mob_interrupt(i); // enable the receive interrupt
		} else {
			CANCDMOB = 0; //Mark as TX MOb
		}
	}
	msgs_av = 0;
	//Enable the CAN controller
	CANGCON = (1 << ENASTB);
}

/*Returns the number of CAN messages waiting*/
uint8_t inline CAN_msg_available(){
	return msgs_av;
}

/*Finds a free MOb or returns -1 if they're all used*/
int8_t find_free_mob(){
	uint8_t i;
	uint8_t status;
	for(i = 0;i < 15;i++){
		select_mob(i);
		status = CANCDMOB;
		if(!(status & ((1 << CONMOB1) | (1 << CONMOB0)))){
			return i;
		}
	}
	return -1;
}


void InitCAN(int deviceGroup, int deviceAddress)
{
    init_CAN(CAN_125_BAUD, deviceGroup, deviceAddress);
}

int SendCANPacket(CANPacket *packetToSend)
{
    uint8_t i;
	int8_t mob = find_free_mob();
	if(mob == -1){
		return 0x02; //No MObs available
	}
	select_mob(mob);
	CANSTMOB &= 0;
	CANCDMOB = packetToSend->dlc & 0x0F;
	for(i = 0;i < packetToSend->dlc && i < 8;i++){ //Copy the data into the MOb
		CANMSG = packetToSend->data[i];
	}
	CANIDT4 = 0; //CAN v2.0 - we don't care
	CANIDT3 = 0;
	CANIDT2 = ((packetToSend->id & 7) << 5);
	CANIDT1 = ((packetToSend->id & 0x7F8) >> 3);
	CANCDMOB |= (1<<CONMOB0);
	enable_mob_interrupt(mob); //Enable MOb interrupt
	return 0;
}

int PollAndReceiveCANPacket(CANPacket *receivedPacket)
{
	if(receivedPacket == NULL){
		return 0x02;
	}

	uint8_t i, mob;
	if(!CAN_msg_available()){
		return 0x01;
	}
	/*Find a MOb with a message*/
	for(i = 0;i < 16;i++){
		if(i == 15) return 0x01;
		select_mob(i);
		if(rxed_mobs[!!(i & 8)] & (1 << (i & 7))){
			break;
		}
	}
	mob = i;
	receivedPacket->dlc = CANCDMOB & 0x0F; //Length in the lower 8 bits
	receivedPacket->id = (CANIDT2 >> 5) | ((uint16_t)CANIDT1 << 3);
	for(i = 0;i < receivedPacket->dlc && i < 8;i++){
		receivedPacket->data[i] = CANMSG; //Get the data from the MOb and copy it into the buffer
	}
	//Atomically decrement the number of messages available
	cli();
	msgs_av--;
	sei();
	/*Reset the MOb*/
	set_mob_rx_filter(mob);
	enable_mob_interrupt(mob);
	rxed_mobs[!!(mob & 8)] &= ~(1 << (mob & 7)); //Mark that the message has been taken
	CANCDMOB = (1<<CONMOB1); //Re-enable recieve
	return 0;
    
}

uint8_t getLocalDeviceSerial()
{
    /*Return the DIP switch value*/
    return devSer;
}
uint8_t getLocalDeviceGroup()
{
    //Definitely board specific.
    return devGrp; // example value (also used for testing)
}

uint8_t getChipType()
{
    return CHIP_TYPE; 
    //Should be same for all ports, just not sure where to put it.
}
#endif //CHIP_TYPE == CHIP_TYPE_ATMEL90CANxxx
