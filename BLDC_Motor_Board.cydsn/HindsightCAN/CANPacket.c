/* File:         CANPacket.c
 * Authors:      Jaden Bottemiller, Benton Kwong, Dylan Tomberlin.
 * Organization: Husky Robotics Team
 * 
 * This file includes fuction definitions for CAN Packet manipulation
 * using the Hindsight CAN Communication standard.
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */

#include "CANPacket.h"
#include "Port.h"

// Constructs a CAN ID according to standards set by electronics subsystem
// for hindsight (PY2020 rover). Not compatible with Orpheus (PY2019)
// Inputs: 
//      priority:   A byte determing if the packet should be prioritized
//                  High priority would mean setting this value to 0
//                  Low priority would mean setting this value to 1
//      devGroup:   ID of device group
//      devSerial:  Serial value of device in the device group
// Output:
//      CANID:      CAN ID with correct formatting        
uint16_t ConstructCANID(uint8_t priority, uint8_t devGroup, uint8_t devSerial)
{
    uint16_t CANID = 0x0000;
    CANID = CANID | ((priority & 0x01) << 10);
    CANID = CANID | ((devGroup & 0x0F) << 6);
    CANID = CANID | (devSerial & 0x3F);

    return CANID;
}

// Creates a CANPacket that can be used by fuctions in this file
// Inputs:
//      id:         CAN ID for the packet
//      dlc:        Data length for the packet. It's the number of bytes used
//                  in data payload for packet
//      data:       An array of bytes used for sending data over CAN
// Outputs:
//      CANPacket:  A struct used for storing the parts needed for a CAN Packet
CANPacket ConstructCANPacket(uint16_t id, uint8_t dlc, uint8_t* data)
{
    CANPacket cp;
    cp.id = id;
    cp.dlc = dlc;   
    for(int i = 0; i < dlc; i++)
    {
        cp.data[i] = data[i];
    }

    return cp;
}

// Writes sender group, serial number, and packet ID to data bytes. Writes to bytes 0 and 1 in data.
// DO NOT OVERWRITE BYTES 0 AND 1 AFTER CALLING THIS FUNCTION.
// Inputs:
//      data:           Data to write to.
//TODO, upon approval from @jaden, delete senderGroup and senderSerial params, as these are handled by getLocal functs
//      senderGroup:    Device group the sender device is a part of.
//      senderSerial:   Device serial number for sender.
//      packetID:       ID for packet to be sent.
// Output:
//                      Index of next byte in `data` that can be written
int WriteSenderSerialAndPacketID(uint8_t *data, uint8_t packetID)
{
    data[0] = packetID;
    data[1] = getLocalDeviceGroup();
    data[2] = getLocalDeviceSerial();
    return 3;
}

// Writes packet ID to data bytes. Writes to byte 0 data.
// DO NOT OVERWRITE BYTE 0 AFTER CALLING THIS FUNCTION.
// Inputs:
//      data:           Data to write to.
//      packetID:       ID for packet to be sent.
// Outputs:
//                      Index to next byte in `data` that can be written;
int WritePacketIDOnly(uint8_t *data, uint8_t packetID)
{
    data[0] =  packetID;
    return 1;
}

// Gets the priority  of a given packet
// Inputs:
//      packet:     CAN Packet to analyze
// Outputs:
//      priority    byte representing packet priority,
//                  (0 for high, 1 for low)
uint8_t GetPacketPriority(CANPacket *packet)
{
    return (packet->id >> 10) & 0x1;
}

// Gets the device serial number from CAN packet
// Inputs:
//      packet:     CAN Packet to analyze
// Outputs:
//                  A byte representing the device
//                  serial number.
uint8_t GetDeviceSerialNumber(CANPacket *packet)
{
    uint8_t id = (packet->id & 0x00FF);
    // Strip fo only serial number portion of id
    return id & 0x3F;
}

// Returns Sender device serial number as 
//      packet:       CAN packet from which to resolve serial number
// Outputs:
//                  A byte representing the sender device number
uint8_t GetSenderDeviceSerialNumber(CANPacket *packet)
{
    return packet->data[2];
}

// Gets the device group code from CAN packet
// Inputs:
//      packet:     CAN Packet to analyze
// Outputs:
//                  A byte representing the device
//                  group code.
uint8_t GetDeviceGroupCode(CANPacket *packet)
{
    uint8_t group = 0;
    int id = packet->id;
    group = (uint8_t) ((id & 0x03C0) >> 6);
    return group;
}

// Gets the sender device group number from the payload data
// Inputs:
//      data:       Address of the byte array of the payload from CAN packet
// Outputs:
//                  A byte representing the sender device number
uint8_t GetSenderDeviceGroupCode(CANPacket *packet)
{
    return packet->data[1];
}

// Ensures that the given packet is of a specified group
// Inputs:
//      packet:         CAN Packet to check
//      expectedType:   ExpectedType of CAN packet
// Outputs:
//                  0 if packet not of expectedType,
//                  Other int otherwise
int PacketIsInGroup(CANPacket *packet, uint8_t expectedType) 
{
    return GetDeviceGroupCode(packet) == expectedType;
}

int SenderPacketIsInGroup(CANPacket *packet, uint8_t expectedType)
{
    return GetSenderDeviceGroupCode(packet) == expectedType;
}

int SenderPacketIsOfDevice(CANPacket *packet, uint8_t expectedType)
{
    return GetSenderDeviceSerialNumber(packet) == expectedType;
}

int GetPacketID(CANPacket *packet)
{
    return packet->data[0];
}

int PacketIsOfID(CANPacket *packet, uint8_t expectedID)
{
    return GetPacketID(packet) == expectedID;
}

// Determines if a given packet targets a specific device
// Useful for determing if a packet should be interpreted by
// the device
// Inputs:
//      packet:                     CAN Packet to check
//      targetDeviceGroup:          Device group of target device
//      targetDeviceSerialNumber:   Serial number of target device
// Outputs:
//                  Returns 0 if packet does not target device
//                  Returns any other int if packet does
int TargetsDevice(CANPacket *packet, uint8_t targetDeviceGroup, uint8_t targetDeviceSerialNumber)
{
    uint8_t packetGroup = GetDeviceGroupCode(packet);
    if (packetGroup == targetDeviceGroup) 
    {
        uint8_t serialNumber = GetDeviceSerialNumber(packet);
        // Return if serial number matches target
        // Otherwise only return true if packet is broadcast to group
        return serialNumber == DEVICE_SERIAL_BROADCAST || serialNumber == targetDeviceSerialNumber;
    }
    // Otherwise only return true if packet is broadcast to all devices
    return packetGroup == DEVICE_GROUP_BROADCAST;
}

void PackIntIntoDataMSBFirst(uint8_t *data, int32_t dataToPack, int startIndex)
{
    data[startIndex]     = (dataToPack & 0xFF000000) >> 24;
    data[startIndex + 1] = (dataToPack & 0x00FF0000) >> 16;
    data[startIndex + 2] = (dataToPack & 0x0000FF00) >> 8;
    data[startIndex + 3] = (dataToPack & 0x000000FF);
}

void PackShortIntoDataMSBFirst(uint8_t *data, int16_t dataToPack, int startIndex)
{
	data[startIndex + 0] = (dataToPack & 0xFF00) >> 8;
	data[startIndex + 1] = (dataToPack & 0x00FF);
}

int32_t DecodeBytesToIntMSBFirst(const uint8_t *data, int startIndex, int endIndex)
{
    int length = 4;
    int32_t decodedData = 0; 

    if (endIndex > 0 && startIndex >= 0) {
        length = endIndex - startIndex + 1;
        if (length > 4) { length = 4; }
        if (length < 1) { length = 0; }
    }

    for (int i = 0; i < length; i++) 
    {
        decodedData |= (int32_t)data[startIndex + i] << (int32_t)(8 * (length-1-i));
    }
    return decodedData;
}
