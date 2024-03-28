/* File:         CANCommon.c
 * Authors:      Jaden Bottemiller, Benton Kwong, Dylan Tomberlin.
 * Organization: Husky Robotics Team
 * 
 * This file includes fuction definitions for Common Mode CAN Communication
 * using the Hindsight CAN Communication standard.
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */

#include "CANPacket.h"
#include "CANCommon.h"
#include "Port.h"
// Assembles Emergency Stop Packet with given parameters
// Inputs:
//      packet:                     CAN Packet to assemble (will overwrite).
//      targetDeviceGroup:          Group to target
//      targetDeviceSerialNumber:   Serial number of target device
//      errorCode:                  Emergency stop error code. E.G. ESTOP_ERR_GENERAL
void AssembleEmergencyStopPacket(CANPacket *packet,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerialNumber,
    uint8_t errorCode)
{
    packet->dlc = DLC_ESTOP;
    packet->id = ConstructCANID(PACKET_PRIORITY_HIGH, targetDeviceGroup, targetDeviceSerialNumber);
    int nextByte = WriteSenderSerialAndPacketID(packet->data, ID_ESTOP);
    packet->data[nextByte] = errorCode;
}

// Assembles Emergency Stop Packet with given parameters.
// This will broadcast the emergency stop command to a desired device group.
// Inputs:
//      packet:                     CAN Packet to assemble (will overwrite).
//      deviceGroup:                Group to target
//      errorCode:                  Emergency stop error code. E.G. ESTOP_ERR_GENERAL
void AssembleGroupBroadcastingEmergencyStopPacket(CANPacket *packet, 
    uint8_t groupCode, 
    uint8_t errorCode)
{
    AssembleEmergencyStopPacket(packet, groupCode, DEVICE_SERIAL_BROADCAST, errorCode);
}

// Assembles Emergency Stop Packet with given parameters.
// This will broadcast the emergency stop command to all devices
// Inputs:
//      packet:                     CAN Packet to assemble (will overwrite).
//      errorCode:                  Emergency stop error code. E.G. ESTOP_ERR_GENERAL
void AssembleBrodcastEmergencyStopPacket(CANPacket *packet, 
    uint8_t errorCode)
{
    AssembleGroupBroadcastingEmergencyStopPacket(packet, DEVICE_GROUP_BROADCAST, errorCode);
}

// Gets the Error Code reported from an emergency stop packet.
// Inputs:
//      packet:     Packet to check.
uint8_t GetEmergencyStopErrorCode(CANPacket *packet)
{
    if (PacketIsOfID(packet, ID_ESTOP))
    {
        return packet->data[2];
    }
    else { return -1; }
}

// Validates the Heartbeat Packet, returns time between previous Heartbeat packets
// Inputs:
//      packet:         CAN Packet to check
//      lastHeartbeat:  Timestamp (ms) of last detected heartbeat
// Outputs:
//                  Time (in ms) between this heartbeat and the previous detected heartbeat
//                  Negative value if packet is not valid heartbeat packet
uint32_t GetTimeBetweenHeartbeatPacket(CANPacket *packet, uint32_t lastHeartbeat)
{
    if (PacketIsOfID(packet, ID_HEARTBEAT)) 
    {
        return GetHeartbeatTimeStamp(packet) - lastHeartbeat;
    }
    else { return -1; }
}

// Validates the Heartbeat Packet, returns time between previous Heartbeat packets
// Inputs:
//      packet:         CAN Packet to check
//      lastHeartbeat:  Timestamp (ms) of last detected heartbeat
// Outputs:
//                  Time (in ms) of the timestamp within the packet
//                  Default return value is uint32 max value, which is used
//                  if the packet is corrupt or not a heartbeat packet.
uint32_t GetHeartbeatTimeStamp(CANPacket *packet)
{
    if (PacketIsOfID(packet, ID_HEARTBEAT)) 
    {
        uint32_t time = ((uint32_t)packet->data[3] << 24);
        time |= ((uint32_t)packet->data[4] << 16);
        time |= ((uint32_t)packet->data[5] << 8);
        time |= packet->data[6]; 
        return time;
    }
    else { return -1; }
}

// Validates the Heartbeat Packet, returns the heartbeat leniency code of the packet
// Inputs:
//      packet:     CAN Packet to check
// Outputs:
//                  Heartbeat leniency code of given packet
uint8_t GetHeartbeatLeniencyCode(CANPacket *packet)
{
    if (PacketIsOfID(packet, ID_HEARTBEAT))
    {
        return packet->data[2];
    } else {
        return 0x00;
    }
}

// Assembles Heartbeat Packet with given parameters
// Inputs:
//      packetToAssemble:       CAN Packet to assemble (will overwrite).
//      broadcast:              1 if broadcast to all devices. 0 to return to MAIN_CPU / Jetson.
//      heartbeatLeniencyCode:  Max time between heartbeats before system automatically enters a safe operating condition.
//      timestamp:              Current timestamp as seen by the sender device. (ms)
//TODO, upon approval from @jaden, delete senderGroup and senderSerial params, as these are handled by getLocal functs
void AssembleHeartbeatPacket(CANPacket *packetToAssemble, 
    int broadcast, 
    uint8_t heartbeatLeniencyCode,
    uint32_t timestamp)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_HIGH, DEVICE_GROUP_BROADCAST, DEVICE_SERIAL_BROADCAST);
    if (!broadcast)
    { 
        packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_HIGH, DEVICE_GROUP_JETSON, DEVICE_SERIAL_JETSON);
    }
    packetToAssemble->dlc = DLC_HEARTBEAT;
    int nextByte = WriteSenderSerialAndPacketID(packetToAssemble->data, ID_HEARTBEAT);
    packetToAssemble->data[nextByte] = heartbeatLeniencyCode;
    PackIntIntoDataMSBFirst(packetToAssemble->data, timestamp, nextByte + 1);
}

void AssembleFailReportPacket(CANPacket *packetToAssemble, 
    uint8_t targetGroup, 
    uint8_t targetSerial,
    uint8_t failedPacketID)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetGroup, targetSerial);
    packetToAssemble->dlc = DLC_FAIL_REPORT;
    int nextByte = WriteSenderSerialAndPacketID(packetToAssemble->data, ID_FAIL_REPORT);
    packetToAssemble->data[nextByte] = failedPacketID;
}

// Assembles override protection packet with given parameters
// Inputs:
//      packetToAssemble:       CAN Packet to assemble (will overwrite).
//      targetGroup:            Device gorup of target device.
//      targetSerial:           Device serial of target device.
void AssembleOverrideProtectionPacket(CANPacket *packetToAssemble, uint8_t targetGroup, uint8_t targetSerial)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetGroup, targetSerial);
    packetToAssemble->dlc = DLC_OVRD_PROTECTION;
    WritePacketIDOnly(packetToAssemble->data, ID_OVRD_PROTECTION);
}

void AssembleChipTypePullPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_CHIP_TYPE_PULL;
    int nextByte = WriteSenderSerialAndPacketID(packetToAssemble->data, ID_CHIP_TYPE_PULL);
    packetToAssemble->data[nextByte] = getChipType();
}

void AssembleChipTypeReportPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_CHIP_TYPE_REP;
    int nextByte = WriteSenderSerialAndPacketID(packetToAssemble->data, ID_CHIP_TYPE_REP);
    packetToAssemble->data[nextByte] = getChipType();
}

uint8_t GetChipTypeFromPacket(CANPacket *packet)
{
    return packet->data[1];
}

void AssembleTelemetryTimingPacket(CANPacket *packetToAssemble, 
    uint8_t targetGroup, 
    uint8_t targetSerial, 
    uint8_t telemetryTypeCode,
    uint32_t msBetweenReports)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetGroup, targetSerial);
    packetToAssemble->dlc = DLC_TELEMETRY_TIMING;
    int nextByte = WriteSenderSerialAndPacketID(packetToAssemble->data, ID_TELEMETRY_TIMING);
    packetToAssemble->data[nextByte] = telemetryTypeCode;
    PackIntIntoDataMSBFirst(packetToAssemble->data, msBetweenReports, nextByte + 1);
}
uint32_t GetTelemetryTimingFromPacket(CANPacket *packetToAssemble)
{
    return DecodeTelemetryDataUnsigned(packetToAssemble);
}

void AssembleTelemetryPullPacket(CANPacket *packetToAssemble, 
    uint8_t targetGroup, 
    uint8_t targetSerial, 
    uint8_t telemetryTypeCode)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetGroup, targetSerial);
    packetToAssemble->dlc = DLC_TELEMETRY_PULL;
    int nextByte = WriteSenderSerialAndPacketID(packetToAssemble->data, ID_TELEMETRY_PULL);
    packetToAssemble->data[nextByte] = telemetryTypeCode;
}

void AssembleTelemetryReportPacket(CANPacket *packetToAssemble, 
    uint8_t targetGroup, 
    uint8_t targetSerial,
    uint8_t telemetryTypeCode,
    int32_t data)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetGroup, targetSerial);
    packetToAssemble->dlc = DLC_TELEMETRY_REPORT;
    int nextByte = WriteSenderSerialAndPacketID(packetToAssemble->data, ID_TELEMETRY_REPORT);
    packetToAssemble->data[nextByte] = telemetryTypeCode;
    PackIntIntoDataMSBFirst(packetToAssemble->data, data, nextByte + 1);
}

int32_t DecodeTelemetryDataSigned(CANPacket *packet)
{
    return DecodeBytesToIntMSBFirst(packet->data, 4, 8);
}

uint32_t DecodeTelemetryDataUnsigned(CANPacket *packet)
{
    return (uint32_t) DecodeTelemetryDataSigned(packet);
}

uint8_t DecodeTelemetryType(CANPacket *packet)
{
    return packet->data[3];
}

void AssembleRGBColorPacket(CANPacket *packetToAssemble,
    uint8_t targetGroup,
    uint8_t targetSerial,
    uint8_t addrLED,
    uint8_t R,
    uint8_t G,
    uint8_t B)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetGroup, targetSerial);
    packetToAssemble->dlc = DLC_LED_COLOR;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_LED_COLOR);
    packetToAssemble->data[nextByte] = R;
    packetToAssemble->data[nextByte + 1] = G;
    packetToAssemble->data[nextByte + 2] = B;
    packetToAssemble->data[nextByte + 3] = addrLED;   
}