/*
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */
#if CHIP_TYPE == CHIP_TYPE_TEMPLATE//Replace this with the chip you are porting

#include "../Port.h"

void InitCAN(int deviceGroup, int deviceAddress)
{
    // Implement hardware initialization of CAN
    // Including receive filters
}
int SendCANPacket(CANPacket *packetToSend)
{
    //Implement sending/ queing to send packet
}
int PollAndReceiveCANPacket(CANPacket *receivedPacket)
{
    //Implement get next CAN packet from buffers/registers
}

uint8_t getLocalDeviceSerial()
{
    //Reading DIP switches? Hard coded?
    //This might be board specific, rather than chip specific.
    return DEVICE_SERIAL_MOTOR_CHASSIS_FR; // example value (also used for testing)
}
uint8_t getLocalDeviceGroup()
{
    //Definitely board specific.
    return DEVICE_GROUP_MOTOR_CONTROL; // example value (also used for testing)
}

uint8_t getChipType()
{
    return CHIP_TYPE; 
    //Should be same for all ports, just not sure where to put it.
}
#endif //CHIP_TYPE == CHIP_TYPE_TEMPLATE
