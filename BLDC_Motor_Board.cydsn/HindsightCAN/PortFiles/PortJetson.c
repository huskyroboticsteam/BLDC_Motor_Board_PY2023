/*
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */
#if CHIP_TYPE == CHIP_TYPE_JETSON

#include "../Port.h"

void InitCAN(int deviceGroup, int deviceAddress) {}

int SendCANPacket(CANPacket *packetToSend) {
    return 0;
}

int PollAndReceiveCANPacket(CANPacket *receivedPacket) {
    return 0;
}

uint8_t getLocalDeviceSerial()
{
    return DEVICE_SERIAL_JETSON;
}

uint8_t getLocalDeviceGroup()
{
    return DEVICE_GROUP_JETSON;
}

uint8_t getChipType()
{
    return CHIP_TYPE; 
    //Should be same for all ports, just not sure where to put it.
}

#endif //CHIP_TYPE == CHIP_TYPE_TEMPLATE
