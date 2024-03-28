/* File:         CANPower.h
 * Authors:      Jaden Bottemiller, Benton Kwong, Dylan Tomberlin.
 * Organization: Husky Robotics Team
 * 
 * This file includes fuction prototypes for the power boards CAN Communication
 * using the Hindsight CAN Communication standard.
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */

#pragma once

#include "CANPacket.h"


void AssemblePowerRailsSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerialNumber,
    uint8_t state);
uint8_t GetPowerRailsStateFromPacket(CANPacket *packet);


void AssembleOverCurrentPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerialNumber,
    uint8_t railNumber,
    uint32_t currentLim);
uint8_t GetOverCurrentRailNumFromPacket(CANPacket *packetToAssemble);
uint8_t GetOverCurrentLimitFromPacket(CANPacket *packetToAssemble);


//TODO: Should we include all of this stuff in CANPacket.h?
// Motor Unit Packet IDs
#define ID_POWER_RAIL_SET               (uint8_t) 0x00
#define ID_POWER_CURRENT_LIM_SET        (uint8_t) 0x01

// Packet DLCs
#define DLC_POWER_RAIL_SET              (uint8_t) 0x02
#define DLC_POWER_CURRENT_LIM_SET       (uint8_t) 0x05

//Packet priorities
#define PRIO_POWER_RAIL_SET             PACKET_PRIORITY_HIGH
#define PRIO_POWER_CURRENT_LIM_SET      PACKET_PRIORITY_NORMAL