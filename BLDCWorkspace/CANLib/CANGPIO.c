/* File:         CANGPIO.c
 * Authors:      Jaden Bottemiller, Benton Kwong, Dylan Tomberlin.
 * Organization: Husky Robotics Team
 * 
 * This file includes fuction implementations for the GPIO board CAN Communication
 * using the Hindsight CAN Communication standard.
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */
//#include "CANPacket.h"
#include "CANGPIO.h"

//Set PWM Frequency Packet
//Assembles a CAN Packet to set GPIO PWM Frequency
//  Inputs: CANPacket pointer to assemble packet
//          targetGroup & targetSerial - for CAN ID
//          pwmChannel - board specific PWM channel
//          frequency - frequency in Hz
void AssembleGPIOSetPWMFrequencyPacket(CANPacket *packetToAssemble, 
    uint8_t targetDeviceGroup, 
    uint8_t targetDeviceSerial,
    uint8_t pwmChannel,
    uint16_t frequency){

    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_GPIO_PWM_FREQ;

    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_GPIO_PWM_FREQ);
    packetToAssemble->data[nextByte++] = pwmChannel;
    PackIntIntoDataMSBFirst(packetToAssemble->data, frequency, nextByte); //consider making a 16bit version of this function?

}

//returns GPIO PWM Channel
//accepts packet to return data from
uint8_t GetGPIOPWMChannelFromPacket(CANPacket *packet){
    return packet->data[1];
}
//returns GPIO PWM frequency
//accepts packet to return data from
uint16_t GetGPIOPWMFrequencyFromPacket(CANPacket *packet){
    return DecodeBytesToIntMSBFirst(packet->data, 2, 3);
}

//Set PWM Duty Cycle
//Assembles a CAN Packet to set GPIO PWM Duty Cycle
//  Inputs: CANPacket pointer to assemble packet
//          targetGroup & targetSerial - for CAN ID
//          pwmChannel - board specific PWM channel
//          dutyCycle - duty cycle resolution
void AssembleGPIOSetPWMDutyCyclePacket(CANPacket *packetToAssemble, 
    uint8_t targetDeviceGroup, 
    uint8_t targetDeviceSerial,
    uint8_t pwmChannel,
    uint16_t dutyCycle){

    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_GPIO_PWM_DUTY_CYCLE;

    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_GPIO_PWM_DUTY_CYCLE);
    packetToAssemble->data[nextByte++] = pwmChannel;
    PackIntIntoDataMSBFirst(packetToAssemble->data, dutyCycle, nextByte);
}

//returns GPIO PWM duty cycle
//accepts packet to return data from
uint16_t GetGPIOPWMDutyCycle(CANPacket *packetToAssemble){
    return DecodeBytesToIntMSBFirst(packetToAssemble->data, 2, 3);
}


//Set ADC State
//Assembles a CAN Packet to set GPIO ADC
//  Inputs: CANPacket pointer to assemble packet
//          targetGroup & targetSerial - for CAN ID
//          ADCChannel - board specific ADC channel
//          state - bool (1 enable 0 disable)
void AssembleGPIOSetADCStateConfiguration(CANPacket *packetToAssemble, 
    uint8_t targetDeviceGroup, 
    uint8_t targetDeviceSerial,
    uint8_t ADCChannel,
    uint8_t state){

    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_GPIO_ADC_STATE;

    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_GPIO_ADC_STATE);
    packetToAssemble->data[nextByte++] = ADCChannel;
    packetToAssemble->data[nextByte] = state;
}
//returns GPIO ADC channel
//accepts packet to return data from
uint8_t GetGPIOADCChannelFromPacket(CANPacket *packet){
    return packet->data[1];
}
//returns GPIO ADC state
//accepts packet to return data from
uint8_t GetGPIOADCStateFromPacket(CANPacket *packet){
    return packet->data[2];
}


//Set GPIO Configuration
//Assembles a CAN Packet to set GPIO Config
//  Inputs: CANPacket pointer to assemble packet
//          targetGroup & targetSerial - for CAN ID
//          GPIORegister - GPIO Register 
//          GPIO bit number - (number is the bit which is being set)
//          GPIO bit state - off, in, out, in/out, adc, pwm
void AssembleGPIOSetConfigurationPacket(CANPacket *packetToAssemble, 
    uint8_t targetDeviceGroup, 
    uint8_t targetDeviceSerial,
    uint8_t GPIORegister,
    uint8_t bitNumber,
    uint8_t bitConfig){

    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_GPIO_CONFIG;

    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_GPIO_CONFIG);
    packetToAssemble->data[nextByte++] = GPIORegister;
    packetToAssemble->data[nextByte++] = bitNumber;
    packetToAssemble->data[nextByte] = bitConfig;
    
}
//returns GPIO register
//accepts packet to return data from
uint8_t GetGPIORegisterFromPacket(CANPacket *packet){
    return packet->data[1];
}
//returns GPIO bit number
//accepts packet to return data from
uint8_t GetGPIOBitNumberFromPacket(CANPacket *packet){
    return packet->data[2];
}
//returns GPIO bit config
//accepts packet to return data from
uint8_t GetGPIOBitConfigFromPacket(CANPacket *packet){
    return packet->data[3];
}


//GPIO Write
//Assembles a CAN Packet to set GPIO Config
//  Inputs: CANPacket pointer to assemble packet
//          targetGroup & targetSerial - for CAN ID
//          GPIORegister - GPIO Register 
//          GPIO bit number - (number is the bit which is being set)
//          GPIO bit writevalues - off, on, flip
void AssembleGPIOWrite(CANPacket *packetToAssemble, 
    uint8_t targetDeviceGroup, 
    uint8_t targetDeviceSerial,
    uint8_t GPIORegister,
    uint8_t bitNumber,
    uint8_t bitWriteValue){

    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_GPIO_WRITE;

    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_GPIO_WRITE);
    packetToAssemble->data[nextByte++] = GPIORegister;
    packetToAssemble->data[nextByte++] = bitNumber;
    packetToAssemble->data[nextByte] = bitWriteValue;

}

//returns GPIO write values
//accepts packet to return data from
uint8_t GetGPIOWriteValuesFromPacket(CANPacket *packet){
        return packet->data[3];
}