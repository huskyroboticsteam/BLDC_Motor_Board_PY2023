#include "CANPacket.h"
#include "CANCommon.h"
#include "CANScience.h"
#include "CANMotorUnit.h"

void AssembleScienceLazySusanPosSetPacket(CANPacket *packetToAssemble,
										  uint8_t targetDeviceGroup,
										  uint8_t targetDeviceSerial,
										  uint8_t position)
{
	packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerial);
	packetToAssemble->dlc = 2;
	WritePacketIDOnly(packetToAssemble->data, ID_SCIENCE_LAZY_SUSAN_POS_SET);
	packetToAssemble->data[1] = position;
}

void AssembleScienceServoPacket(CANPacket *packetToAssemble,
	uint8_t targetGroup,
	uint8_t targetSerial,
	uint8_t servo,
	uint8_t degrees)
{
	packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetGroup, targetSerial);
	packetToAssemble->dlc = 3;
	WritePacketIDOnly(packetToAssemble->data, ID_SCIENCE_SERVO_SET);
	packetToAssemble->data[1] = servo;
	packetToAssemble->data[2] = degrees;
}

void AssembleScienceContServoPowerSetPacket(CANPacket *packetToAssemble,
											uint8_t targetDeviceGroup,
											uint8_t targetDeviceSerial,
											uint8_t servo,
											int8_t power)
{
	packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerial);
	packetToAssemble->dlc = 3;
	WritePacketIDOnly(packetToAssemble->data, ID_SCIENCE_CONT_SERVO_POWER_SET);
	packetToAssemble->data[1] = servo;
	packetToAssemble->data[2] = power;
}

int8_t GetScienceContServoPowerFromPacket(const CANPacket *packet) {
	return packet->data[2];
}

uint8_t GetScienceServoAngleFromPacket(const CANPacket *packet){
	return packet->data[2];
}

uint8_t GetScienceLazySusanPosFromPacket(const CANPacket *packet) {
    return packet->data[1];
}

uint8_t GetScienceServoIDFromPacket(const CANPacket *packet){
	return packet->data[1];
}


