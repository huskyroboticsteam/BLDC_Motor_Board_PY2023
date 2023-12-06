#ifndef MOTORBOARDCAN_H
#define MOTORBOARDCAN_H

#include <project.h>
#include "../HindsightCAN/CANLibrary.h"
    
void NextStateFromCAN(CANPacket *receivedPacket, CANPacket *packetToSend);
void SendEncoderData(CANPacket *packetToSend);

#define NO_NEW_CAN_PACKET 0xFFFF

#endif