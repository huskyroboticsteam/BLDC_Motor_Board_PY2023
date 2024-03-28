/*
 * Authors: Austin Chan
 * Documentation: ClickUp
 * 
 * Port specific notes:
 * Design must include a CAN block called CAN (not CAN0 or variation)
 * Must auto generate code within PSoC IDE to use APIs
 */
#if CHIP_TYPE == CHIP_TYPE_PSOC_CY8C4248AZI_L485

#include "../Port.h"
#include "project.h"
    
//Flag internal to this port, 0xFF if no message waiting, doubles as mailbox number
volatile uint8_t messagePresentFlag = 0xFF;
volatile uint8_t messageReadFlag = 0x0;
uint8_t FIFOSize(void);
void countAddFIFO(void);
void countRemoveFIFO(void);

#define FIFO_SIZE   16
volatile CANPacket latestMessage[FIFO_SIZE];//internal to this port acts like a FIFO with 10 packet storage
volatile uint8_t latestMessageHead = 0; //which index to read
volatile uint8_t latestMessageTail = 0; //which index to write to next
volatile uint8_t latestMessageFull = 0; //FIFO is full

#define STATUS_MAILBOX0 0x1
#define STATUS_MAILBOX1 0x2
#define STATUS_MAILBOX2 0x4
#define STATUS_MAILBOX3 0x8
#define STATUS_MAILBOX4 0x10
#define STATUS_MAILBOX5 0x20


CY_ISR_PROTO(CAN_FLAG_ISR);

int deviceAddress;
int deviceGroup;
CAN_RX_CFG rxMailbox;
void InitCAN(int deviceGroupInput, int deviceAddressInput)
{
    CAN_Start();//must name CAN Top Design block as "CAN"
    
    //TODO: I'm sure there's a better way of doing this part
    deviceGroup = deviceGroupInput & 0xF; // 4bits of ID
    deviceAddress = deviceAddressInput & (0x3f);//6bits of ID
    
    //sets up inidvidual recieve mailbox (3rd priority mailbox)
    rxMailbox.rxmailbox = 0;
    rxMailbox.rxacr = ((deviceGroup << 6)|(deviceAddress)) << 21;  // first 11 bits are the CAN ID that is not extended
    rxMailbox.rxamr = 0x801FFFFF; // what bits to ignore
    rxMailbox.rxcmd = CAN_RX_CMD_REG(CAN_RX_MAILBOX_0);//need to know what this is
    CAN_RxBufConfig(&rxMailbox);
    
    //setup broadcast recieve mailbox (1st priority mailbox)
    rxMailbox.rxmailbox = 1;
    rxMailbox.rxacr = ((0x0 << 6)|(0x0)) << 21; //0x20F<<21; // first 11 bits are the CAN ID that is not extended
    rxMailbox.rxamr = 0x801FFFFF; // what bits to ignore
    rxMailbox.rxcmd = CAN_RX_CMD_REG(CAN_RX_MAILBOX_1);//need to know what this is
    CAN_RxBufConfig(&rxMailbox);
    
    //setup group broadcast recieve mailbox (2nd priority mailbox)
    rxMailbox.rxmailbox = 2;
    rxMailbox.rxacr = ((deviceGroup << 6)|(0x3F)) << 21; //0x20F<<21; // first 11 bits are the CAN ID that is not extended
    rxMailbox.rxamr = 0x801FFFFF; // what bits to ignore
    rxMailbox.rxcmd = CAN_RX_CMD_REG(CAN_RX_MAILBOX_2);//need to know what this is
    CAN_RxBufConfig(&rxMailbox);
    
    CAN_GlobalIntEnable();
    CyIntSetVector(CAN_ISR_NUMBER, CAN_FLAG_ISR);
    //CY_ISR_PROTO(CAN_FLAG_ISR);
    
}
int SendCANPacket(CANPacket *packetToSend)
{
    if(!packetToSend) {return ERROR_NULL_POINTER;}
    CAN_TX_MSG PSoCMessage;//CAN structure
    CAN_DATA_BYTES_MSG PSoCData;//CAN data
    PSoCMessage.id = packetToSend->id;
    PSoCMessage.rtr = 0x0;
    PSoCMessage.ide = 0x0;//Not extended
    PSoCMessage.dlc = packetToSend->dlc;
    PSoCMessage.irq = 0x0;
    PSoCMessage.msg = &PSoCData;
    
    memcpy(PSoCData.byte, packetToSend->data, 8);

    if(CAN_SendMsg(&PSoCMessage) == CYRET_SUCCESS) {
        return ERROR_NONE;
    } else
    {
        return ERROR_GENERIC_ERROR;
    }
}
//
int PollAndReceiveCANPacket(CANPacket *receivedPacket)
{
    if(!receivedPacket) {
        return ERROR_NULL_POINTER;
    }
    volatile uint8_t size = FIFOSize();
    if(size)
    {
        *(receivedPacket) = latestMessage[latestMessageHead];
        countRemoveFIFO();
        return ERROR_NONE;
    }
    return 0x02; //No message received error
}

uint8_t getLocalDeviceSerial()
{
    return deviceAddress; 
}
uint8_t getLocalDeviceGroup()
{
    return deviceGroup;
}

uint8_t getChipType()
{
    return CHIP_TYPE; 
}

//helper function calculate size of Fifo
uint8_t FIFOSize(){
    if(latestMessageFull) {
        return FIFO_SIZE;
    }
    else if(latestMessageHead < latestMessageTail) {
        return latestMessageTail - latestMessageHead;
    }
    else if(latestMessageHead > latestMessageTail) {
        return (FIFO_SIZE - latestMessageHead) + latestMessageTail;
    }
    else { // latestMessageHead == latestMessageTail && !latestMessageFull
        return 0;
    }
}

void countAddFIFO(){ 
    latestMessageTail++;
    if(latestMessageTail >= FIFO_SIZE){
        latestMessageTail = 0;
    }
    if(latestMessageFull) {
        latestMessageHead++;
        if(latestMessageHead >= FIFO_SIZE) {
            latestMessageHead = 0;
        }
    }
    latestMessageFull = (latestMessageHead == latestMessageTail);
}

void countRemoveFIFO(){
    if(FIFOSize() > 0) {
        latestMessageHead++;
        if(latestMessageHead >= FIFO_SIZE) {
            latestMessageHead = 0;
        }
    }
}



CY_ISR(CAN_FLAG_ISR)
{

    //*(reg32*)0x402F0000 = CAN_RX_MESSAGE_MASK & CAN_SST_FAILURE_MASK & CAN_CRC_ERROR_MASK; //Clear Receive Message flag
    CAN_INT_SR_REG = CAN_RX_MESSAGE_MASK;
    uint32_t statusReg = (uint32_t) CAN_BUF_SR_REG; //Hardcoded for speed, translation from reg
    uint8_t mailbox;
    
    if(statusReg & 0b1) { // mailbox0 is full (individual)
        mailbox = CAN_RX_MAILBOX_0;
    }
    else if(statusReg & 0b10) { // mailbox1 is full (broadcast)
        mailbox = CAN_RX_MAILBOX_1;
    }    
    else if(statusReg & 0b100) { // mailbox2 is full (group broadcast)
        mailbox = CAN_RX_MAILBOX_2;
    } 
    else if(statusReg & 0b1000) { // mailbox3 is full currently recieves anything enable in top design 
        mailbox = CAN_RX_MAILBOX_3;
    }
    
    latestMessage[latestMessageTail].id = CAN_GET_RX_ID(mailbox);
    latestMessage[latestMessageTail].dlc = CAN_GET_DLC(mailbox);
    latestMessage[latestMessageTail].data[0] = CAN_RX_DATA_BYTE1(mailbox);
    latestMessage[latestMessageTail].data[1] = CAN_RX_DATA_BYTE2(mailbox);
    latestMessage[latestMessageTail].data[2] = CAN_RX_DATA_BYTE3(mailbox);
    latestMessage[latestMessageTail].data[3] = CAN_RX_DATA_BYTE4(mailbox);
    latestMessage[latestMessageTail].data[4] = CAN_RX_DATA_BYTE5(mailbox);
    latestMessage[latestMessageTail].data[5] = CAN_RX_DATA_BYTE6(mailbox);
    latestMessage[latestMessageTail].data[6] = CAN_RX_DATA_BYTE7(mailbox);
    latestMessage[latestMessageTail].data[7] = CAN_RX_DATA_BYTE8(mailbox);
    countAddFIFO();

    //CAN_ReceiveMsg(messagePresentFlag);
    CAN_RX_ACK_MESSAGE(mailbox);
}
#endif //CHIP_TYPE == CHIP_TYPE_PSOC_CY8C4248AZI_L485
