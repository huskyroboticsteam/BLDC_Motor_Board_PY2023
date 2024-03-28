/* File:         CANPacket.h
 * Authors:      Jaden Bottemiller, Benton Kwong, Dylan Tomberlin.
 * Organization: Husky Robotics Team
 * 
 * This file includes fuction prototypes for CAN Packet manipulation
 * using the Hindsight CAN Communication standard.
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */

#pragma once

#include <stdint.h>
#include "CANSerialNumbers.h"

typedef struct
{
    uint16_t id;
    uint8_t dlc;
    uint8_t data[8];
} CANPacket;

CANPacket ConstructCANPacket(uint16_t id, uint8_t dlc, uint8_t* data);
uint16_t ConstructCANID(uint8_t priority, uint8_t devGroup, uint8_t devSerial);

//Private library functions
int WriteSenderSerialAndPacketID(uint8_t *data, uint8_t packetID);
int WritePacketIDOnly(uint8_t *data, uint8_t packetID);

uint8_t GetPacketPriority(CANPacket *packet);

uint8_t GetDeviceGroupCode(CANPacket *packet);
uint8_t GetDeviceSerialNumber(CANPacket *packet);
uint8_t GetSenderDeviceSerialNumber(CANPacket *packet);
uint8_t GetSenderDeviceGroupCode(CANPacket *packet);

int PacketIsInGroup(CANPacket *packet, uint8_t expectedType);
int SenderPacketIsInGroup(CANPacket *packet, uint8_t expectedType);
int SenderPacketIsOfDevice(CANPacket *packet, uint8_t expectedType);
int TargetsDevice(CANPacket *packet, uint8_t targetDeviceGroup, uint8_t targetDeviceSerialNumber);

int GetPacketID(CANPacket *packet);
int PacketIsOfID(CANPacket *packet, uint8_t expectedID);

void PackIntIntoDataMSBFirst(uint8_t *data, int32_t dataToPack, int startIndex);
void PackShortIntoDataMSBFirst(uint8_t *data, int16_t dataToPack, int startIndex);
/**
 * @brief Read at most 4 bytes into a signed int.
 *
 * @param data The array of bytes to read from, storing the bytes in big-endian order.
 * @param startIndex The index of the MSB.
 * @param endIndex The index after the LSB.
 * @return int32_t The decoded integer.
 *
 * @warning Be careful using this for unsigned data, as it could overflow.
 */
int32_t DecodeBytesToIntMSBFirst(const uint8_t *data, int startIndex, int endIndex);

// Device group nibbles
#define DEVICE_GROUP_BROADCAST          (uint8_t) 0x00
#define DEVICE_GROUP_RESERVED           (uint8_t) 0x01 // DO NOT USE. For future expansion
#define DEVICE_GROUP_JETSON             (uint8_t) 0x02
#define DEVICE_GROUP_MASTER             DEVICE_GROUP_JETSON
#define DEVICE_GROUP_POWER              (uint8_t) 0x03
#define DEVICE_GROUP_MOTOR_CONTROL      (uint8_t) 0x04
#define DEVICE_GROUP_TELEMETRY          (uint8_t) 0x05
#define DEVICE_GROUP_GPIO_BOARDS        (uint8_t) 0x06
#define DEVICE_GROUP_SCIENCE            (uint8_t) 0x07

// Priority bits
#define PACKET_PRIORITY_HIGH            (uint8_t) 0x00
#define PACKET_PRIORITY_NORMAL          (uint8_t) 0x01
#define PACKET_GROUP_NO_SENDER_SERIAL   (uint8_t) 0x0C

// GPIO Board Packet IDs
#define ID_GPIO_BOARD_PWM_SET_STATE     (uint8_t) 0x00
#define ID_GPIO_BOARD_PWM_SET           (uint8_t) 0x01
#define ID_GPIO_BOARD_ADC_EN_SET        (uint8_t) 0x02
#define ID_GPIO_BOARD_ADC_READ          (uint8_t) 0x03
#define ID_GPIO_BOARD_ADC_READ_RESPONSE (uint8_t) 0x04
#define ID_GPIO_BOARD_IO_SET_STATE      (uint8_t) 0x05
#define ID_GPIO_BOARD_IO_READ           (uint8_t) 0x06
#define ID_GPIO_BOARD_IO_READ_RESPONSE  (uint8_t) 0x07
#define ID_GPIO_BOARD_IO_WRITE          (uint8_t) 0x08

// Power Distribution Packet IDs
/*No longer needed, some of this was put into telemetry, other was put into CANPower.h

#define ID_POWER_DIST_RAIL_SET_STATE    (uint8_t) 0x00
#define ID_POWER_DIST_RAIL_REQ_STATE    (uint8_t) 0x01
#define ID_POWER_DIST_RAIL_RESPONSE     (uint8_t) 0x02
#define ID_POWER_DIST_OVC_LIM_SET       (uint8_t) 0x03
*/

// Telemetry Packet IDs
#define ID_TELEMETRY_SET_MAG_OFFSET     (uint8_t) 0x00
