/* File:         CANMotorUnit.c
 * Authors:      Jaden Bottemiller, Benton Kwong, Dylan Tomberlin, Austin Chan.
 * Organization: Husky Robotics Team
 *
 * This file includes function definitions for CAN Packet manipulation
 * using the Hindsight CAN Communication standard. Specific files
 * for the motor unit boards.
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */

#include "CANPacket.h"
#include "CANMotorUnit.h"
#include "Port.h"

void AssembleModeSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint8_t mode)
{
    packetToAssemble->id = ConstructCANID(PRIO_MOTOR_UNIT_MODE_SEL, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_MODE_SEL;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_MODE_SEL);
    packetToAssemble->data[nextByte] = mode;
}

uint8_t GetModeFromPacket(CANPacket *packet)
{
    return packet->data[1];
}


void AssemblePWMDirSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    int16_t PWMSet)
{
    packetToAssemble->id = ConstructCANID(PRIO_MOTOR_UNIT_PWM_DIR_SET, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_PWM_DIR_SET;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_PWM_DIR_SET);
    PackShortIntoDataMSBFirst(packetToAssemble->data, PWMSet, nextByte);
}

int16_t GetPWMFromPacket(CANPacket *packet)
{
    return DecodeBytesToIntMSBFirst(packet->data, 1, 2);
}

//Returns 2's compliment MSB (0 for stopped or forward, 1 for reverse)
int32_t GetDirectionFromPacket(CANPacket *packet)
{
    return ((packet->data[1]) >> 7) & 0x1;
}

void AssemblePIDTargetSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    int32_t target)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_PID_POS_TGT_SET;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_PID_POS_TGT_SET);
    PackIntIntoDataMSBFirst(packetToAssemble->data, target, nextByte);
}

int32_t GetPIDTargetFromPacket(CANPacket *packet)
{
    return DecodeBytesToIntMSBFirst(packet->data, DLC_MOTOR_UNIT_PID_POS_TGT_SET - 4, DLC_MOTOR_UNIT_PID_POS_TGT_SET);
}

void AssemblePSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    int32_t pCoef)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_PID_P_SET;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_PID_P_SET);
    PackIntIntoDataMSBFirst(packetToAssemble->data, pCoef, nextByte);
}

int32_t GetPFromPacket(CANPacket *packet)
{
    return DecodeBytesToIntMSBFirst(packet->data, DLC_MOTOR_UNIT_PID_P_SET - 4, DLC_MOTOR_UNIT_PID_P_SET );
}

void AssembleISetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    int32_t iCoef)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_PID_I_SET;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_PID_I_SET);
    PackIntIntoDataMSBFirst(packetToAssemble->data, iCoef, nextByte);
}

int32_t GetIFromPacket(CANPacket *packet)
{
    return DecodeBytesToIntMSBFirst(packet->data, DLC_MOTOR_UNIT_PID_I_SET - 4, DLC_MOTOR_UNIT_PID_I_SET );
}

void AssembleDSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    int32_t dCoef)
{
    packetToAssemble->id = ConstructCANID(PACKET_PRIORITY_NORMAL, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_PID_D_SET;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_PID_D_SET);
    PackIntIntoDataMSBFirst(packetToAssemble->data, dCoef, nextByte);
}

int32_t GetDFromPacket(CANPacket *packet)
{
    return DecodeBytesToIntMSBFirst(packet->data, DLC_MOTOR_UNIT_PID_D_SET - 4, DLC_MOTOR_UNIT_PID_D_SET);
}

void AssembleInitializePacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint8_t initMode)
{
    packetToAssemble->id = ConstructCANID(PRIO_MOTOR_UNIT_INIT, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_INIT;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_INIT);
    packetToAssemble->data[nextByte] = initMode;
}
uint8_t GetInitModeFromPacket(CANPacket *packet)
{
    return packet->data[1];
}

void AssembleLimitSwitchAlertPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint8_t switches)
{
    packetToAssemble->id = ConstructCANID(PRIO_MOTOR_UNIT_LIM_ALERT, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_LIM_ALERT;
    int nextByte = WriteSenderSerialAndPacketID(packetToAssemble->data, ID_MOTOR_UNIT_LIM_ALERT);
    packetToAssemble->data[nextByte] = switches;
}
uint8_t GetLimStatusFromPacket(CANPacket *packet)
{
    return packet->data[1];
}

void AssembleEncoderPPJRSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint32_t pulses)
{
    packetToAssemble->id = ConstructCANID(PRIO_MOTOR_UNIT_ENC_PPJR_SET, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_ENC_PPJR_SET;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_ENC_PPJR_SET);
    PackIntIntoDataMSBFirst(packetToAssemble->data, pulses, nextByte);
}

uint32_t GetEncoderPPJRFromPacket(CANPacket *packet)
{
    return DecodeBytesToIntMSBFirst(packet->data, 1, 4);
}

void AssembleMaxJointRevolutionPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint32_t revolutions)
{
    packetToAssemble->id = ConstructCANID(PRIO_MOTOR_UNIT_MAX_JNT_REV_SET, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_MAX_JNT_REV_SET;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_MAX_JNT_REV_SET);
    PackIntIntoDataMSBFirst(packetToAssemble->data, revolutions, nextByte);

}
uint32_t GetMaxJointRevolutionsFromPacket(CANPacket *packet)
{
    return DecodeBytesToIntMSBFirst(packet->data, 1, 4);
}

void AssemblePotHiSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint16_t adcHi,
    int32_t mdegHi)
{
    packetToAssemble->id = ConstructCANID(PRIO_MOTOR_UNIT_POT_INIT, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_POT_INIT;

    int idx = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_POT_INIT_HI);
    PackShortIntoDataMSBFirst(packetToAssemble->data, adcHi, idx);
    idx += 2;
    PackIntIntoDataMSBFirst(packetToAssemble->data, mdegHi, idx);
}

void AssemblePotLoSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint16_t adcLo,
    int32_t mdegLo)
{
    packetToAssemble->id = ConstructCANID(PRIO_MOTOR_UNIT_POT_INIT, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_POT_INIT;

    int idx = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_POT_INIT_LO);
    PackShortIntoDataMSBFirst(packetToAssemble->data, adcLo, idx);
    idx += 2;
    PackIntIntoDataMSBFirst(packetToAssemble->data, mdegLo, idx);
}

uint16_t GetPotADCFromPacket(const CANPacket *packet)
{
    return DecodeBytesToIntMSBFirst(packet->data, 1, 2);
}

int32_t GetPotmDegFromPacket(const CANPacket *packet)
{
    return DecodeBytesToIntMSBFirst(packet->data, 3, 6);
}

void AssembleEncoderInitializePacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint8_t encoderType,
    uint8_t angleDirection,
    uint8_t zeroAngle)
{
    packetToAssemble->id = ConstructCANID(PRIO_MOTOR_UNIT_ENC_INIT, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_ENC_INIT;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_ENC_INIT);
    packetToAssemble->data[nextByte] = 0;
    if(encoderType)
    {
        packetToAssemble->data[nextByte] |= 0b100;
    }
    if(angleDirection)
    {
        packetToAssemble->data[nextByte] |= 0b010;
    }
    if(zeroAngle)
    {
        packetToAssemble->data[nextByte] |= 0b001;
    }
}

uint8_t GetEncoderTypeFromPacket(CANPacket *packet)
{
    return(packet->data[1] & 0b100);
}
uint8_t GetEncoderDirectionFromPacket(CANPacket *packet)
{
    return(packet->data[1] & 0b010);
}
uint8_t GetEncoderZeroFromPacket(CANPacket *packet)
{
    return(packet->data[1] & 0b001);
}

void AssembleMaxPIDPWMPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint16_t PWMSetMax)
    {
    packetToAssemble->id = ConstructCANID(PRIO_MOTOR_UNIT_MAX_PID_PWM, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_MAX_PID_PWM;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, DLC_MOTOR_UNIT_MAX_PID_PWM);
    PackShortIntoDataMSBFirst(packetToAssemble->data, PWMSetMax, nextByte);
}

uint16_t GetMaxPIDPWMFromPacket(CANPacket *packet)
{
    return DecodeBytesToIntMSBFirst(packet->data, 1, 2);
}

void AssemblePCAServoPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint8_t servoNum,
    int32_t angle) 
{
    packetToAssemble->id = ConstructCANID(PRIO_MOTOR_UNIT_PCA_SERVO, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_PCA_SERVO;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_PCA_SERVO);
    packetToAssemble->data[nextByte] = servoNum;
    nextByte++;
    PackIntIntoDataMSBFirst(packetToAssemble->data, angle, nextByte);
}

int32_t GetAngleValueFromPacket(const CANPacket *packet)
{
    return DecodeBytesToIntMSBFirst(packet->data, 2, 5);
}

uint8_t GetServoNumFromPacket(const CANPacket *packet)
{
    return packet->data[1];
}

void AssembleLimSwEncoderBoundPacket(CANPacket* packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint8_t limSwNum,
    int32_t encoderBound)
{
    packetToAssemble->id = ConstructCANID(PRIO_MOTOR_UNIT_SET_ENCODER_BOUND, targetDeviceGroup, targetDeviceSerial);
    packetToAssemble->dlc = DLC_MOTOR_UNIT_ENCODER_BOUND;
    int nextByte = WritePacketIDOnly(packetToAssemble->data, ID_MOTOR_UNIT_SET_ENCODER_BOUND);
    packetToAssemble->data[nextByte] = limSwNum;
    nextByte++;
    PackIntIntoDataMSBFirst(packetToAssemble->data, encoderBound, nextByte);
}

int32_t GetEncoderValueFromPacket(const CANPacket* packet) {
    return DecodeBytesToIntMSBFirst(packet->data, 2, 5);
}

uint8_t GetLimSwNumFromPacket(const CANPacket* packet) {
    return packet->data[1];
}
