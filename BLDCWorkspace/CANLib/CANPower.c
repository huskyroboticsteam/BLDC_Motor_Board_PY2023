/* File:         CANPower.c
 * Authors:      Jaden Bottemiller, Benton Kwong, Dylan Tomberlin.
 * Organization: Husky Robotics Team
 * 
 * This file includes fuction implementations for the power boards CAN Communication
 * using the Hindsight CAN Communication standard.
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */
#include "CANPower.h"
#include "CANPacket.h"

//Power Rail Set State
void AssemblePowerRailsSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerialNumber,
    uint8_t state)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerialNumber);
    packetToAssemble->dlc = DLC_POWER_RAIL_SET;
    int nextByte = WriteSenderSerialAndPacketID(packetToAssemble->data, ID_POWER_RAIL_SET);
    packetToAssemble->data[nextByte] = state;
    
}
uint8_t GetPowerRailsStateFromPacket(CANPacket *packet)
{
    return packet->data[2];
}


//Power Set Over Current Limit
void AssembleOverCurrentPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerialNumber,
    uint8_t railNumber,
    uint32_t currentLim)
{
    packetToAssemble->id = ConstructCANID(PRIO_POWER_CURRENT_LIM_SET, targetDeviceGroup, targetDeviceSerialNumber);
    packetToAssemble->dlc = DLC_POWER_CURRENT_LIM_SET;
    int nextByte = WriteSenderSerialAndPacketID(packetToAssemble->data, ID_POWER_CURRENT_LIM_SET);
    packetToAssemble->data[nextByte] = railNumber;
    PackIntIntoDataMSBFirst(packetToAssemble->data, currentLim, nextByte + 1);
}
uint8_t GetOverCurrentRailNumFromPacket(CANPacket *packetToAssemble)
{
    return packetToAssemble->data[2];
}
uint8_t GetOverCurrentLimitFromPacket(CANPacket *packetToAssemble)
{
    return DecodeBytesToIntMSBFirst(packetToAssemble->data, 3, 6);
}