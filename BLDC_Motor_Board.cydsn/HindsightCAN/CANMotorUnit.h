/* File:         CANMotorUnit.h
 * Authors:      Jaden Bottemiller, Benton Kwong, Dylan Tomberlin.
 * Organization: Husky Robotics Team
 * 
 * This file includes fuction prototypes for CAN Packet manipulation
 * using the Hindsight CAN Communication standard. Specific files
 * for the motor unit boards.
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */

#include "CANPacket.h"

// TODO: Add parameters to packet assembly
//Mode set (PWM or PID)
void AssembleModeSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint8_t mode);
uint8_t GetModeFromPacket(CANPacket *packet);

//PWM value and direction set
void AssemblePWMDirSetPacket(CANPacket *packetToAssemble, 
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    int16_t PWMSet);
int16_t GetPWMFromPacket(CANPacket *packet);
int32_t GetDirectionFromPacket(CANPacket *packet);

//PID postional target set
void AssemblePIDTargetSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    int32_t target);
int32_t GetPIDTargetFromPacket(CANPacket *packet);

//P coeffiecent set
void AssemblePSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    int32_t pCoef);
int32_t GetPFromPacket(CANPacket *packet);

//I coeffiecent set
void AssembleISetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    int32_t iCoef);
int32_t GetIFromPacket(CANPacket *packet);

//D coeffiecent set
void AssembleDSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    int32_t dCoef);
int32_t GetDFromPacket(CANPacket *packet);

//Initialize with mode (motors shall not move until have been inited)
void AssembleInitializePacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint8_t initMode);
uint8_t GetInitModeFromPacket(CANPacket *packet);

//Limit switch alert 
//each bit represents one limit switch, 1 for closed, 0 for open,
//switch number corresponds to the bit number
void AssembleLimitSwitchAlertPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint8_t switches);
uint8_t GetLimStatusFromPacket(CANPacket *packet);

//Encoder pulses per joint revolution set
void AssembleEncoderPPJRSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint32_t pulses);
uint32_t GetEncoderPPJRFromPacket(CANPacket *packet);

//Maximum joint rotations set
void AssembleMaxJointRevolutionPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint32_t revolutions);
uint32_t GetMaxJointRevolutionsFromPacket(CANPacket *packet);


// Potentiometer configuration packets
/**
 * @brief Assemble a packet to set the high point of the potentiometer.
 *
 * This, along with AssemblePotLoSetPacket() are required to initialize the potentiometer.
 * Behavior is undefined if only one packet is sent and not the other.
 *
 * @param packetToAssemble The packet to write the data into.
 * @param targetDeviceGroup The group of the target device.
 * @param targetDeviceSerial Ther serial code of the target device.
 * @param adcHi The raw ADC value of the pot at the max.
 * @param mdegHi The joint pos in millideg at the max.
 *
 * @see https://github.com/huskyroboticsteam/HindsightCAN/wiki/Motor-Unit-Packets
 */
void AssemblePotHiSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint16_t adcHi,
    int32_t mdegHi);

/**
 * @brief Assemble a packet to set the low point of the potentiometer.
 *
 * This, along with AssemblePotHiSetPacket() are required to initialize the potentiometer.
 * Behavior is undefined if only one packet is sent and not the other.
 *
 * @param packetToAssemble The packet to write the data into.
 * @param targetDeviceGroup The group of the target device.
 * @param targetDeviceSerial Ther serial code of the target device.
 * @param adcHi The raw ADC value of the pot at the low.
 * @param mdegHi The joint pos in millideg at the low.
 *
 * @see https://github.com/huskyroboticsteam/HindsightCAN/wiki/Motor-Unit-Packets
 */
void AssemblePotLoSetPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint16_t adcLo,
    int32_t mdegLo);

/**
 * @brief Get the raw ADC value from a pot initialization packet.
 *
 * @param packet The packet, produced by either AssemblePotHiSetPacket()
 *               or AssemblePotLoSetPacket(), to read from.
 * @return uint16_t The raw ADC value.
 */
uint16_t GetPotInitADCFromPacket(const CANPacket *packet);

/**
 * @brief Get the joint position from a pot initialization packet.
 *
 * @param packet The packet, produced by either AssemblePotHiSetPacket()
 *               or AssemblePotLoSetPacket(), to read from.
 * @return int32_t The joint position in millidegrees.
 */
int32_t GetPotInitmDegFromPacket(const CANPacket *packet);

//Initialize Encoder Settings
void AssembleEncoderInitializePacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint8_t encoderType,
    uint8_t angleDirection,
    uint8_t zeroAngle);
uint8_t GetEncoderTypeFromPacket(CANPacket *packet);
uint8_t GetEncoderDirectionFromPacket(CANPacket *packet);
uint8_t GetEncoderZeroFromPacket(CANPacket *packet);

void AssembleMaxPIDPWMPacket(CANPacket *packetToAssemble, 
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint16_t PWMSetMax);
uint16_t GetMaxPIDPWMFromPacket(CANPacket *packet);

/**
 * @brief Assemble a packet to initialize the PCA servo
 *
 * @param packetToAssemble The packet to write the data into.
 * @param targetDeviceGroup The group of the target device.
 * @param targetDeviceSerial The serial code of the target device.
 * @param serverNum The servo number
 * @param angle The angle degree in millidegrees
 *
 * @see https://github.com/huskyroboticsteam/HindsightCAN/wiki/Motor-Unit-Packets
 */
void AssemblePCAServoPacket(CANPacket *packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint8_t serverNum,
    int32_t angle);

/**
 * @brief Get the PCA servo angle value from its packet
 *
 * @param packet The packet, produced by AssemblePCAServoPacket, to read from.
 * @return int32_t The angle in millidegrees.
 */
int32_t GetAngleValueFromPacket(const CANPacket *packet);

/**
 * @brief Get the PCA servo number from its packet
 *
 * @param packet The packet, produced by AssemblePCAServoPacket, to read from.
 * @return uint8_t the servo num.
 */
uint8_t GetServoNumFromPacket(const CANPacket *packet); 

/**
 * @brief Assemble a packet to set the encoder bounds on limit switch interrupt
 *
 * @param packetToAssemble The packet to write the data into.
 * @param targetDeviceGroup The group of the target device.
 * @param targetDeviceSerial The serial code of the target device.
 * @param limSwNum The limit switch that the encoder bound should be associated
 *                 with.
 * @param encoderBound The count the encoder should be set to when the given
 *                     limit switch is hit.
 *
 * @see https://github.com/huskyroboticsteam/HindsightCAN/wiki/Motor-Unit-Packets
 */
void AssembleLimSwEncoderBoundPacket(CANPacket* packetToAssemble,
    uint8_t targetDeviceGroup,
    uint8_t targetDeviceSerial,
    uint8_t limSwNum,
    int32_t encoderBound);

/*
 * @brief Get encoder bound value from the limit switch encoder bound packet
 *
 * @param packet The packet, produced by AssembleLimSwEncoderBoundPacket, to
 *               read from.
 *
 * @return int32_t The encoder bound limit.
 */
int32_t GetEncoderValueFromPacket(const CANPacket* packet);

/*
 * @brief Get limit switch number associated with encoder bound.
 *
 * @param packet The packet, produced by AssembleLimSwEncoderBoundPacket, to
 *               read from.
 *
 * @return uint8_t The limit switch associated with the encoder bound.
 */
uint8_t GetLimSwNumFromPacket(const CANPacket* packet);

// Motor Unit Packet IDs
#define ID_MOTOR_UNIT_MODE_SEL          (uint8_t) 0x00
#define ID_MOTOR_UNIT_PWM_DIR_SET       (uint8_t) 0x03
#define ID_MOTOR_UNIT_PID_POS_TGT_SET   (uint8_t) 0x04
#define ID_MOTOR_UNIT_PID_P_SET         (uint8_t) 0x05
#define ID_MOTOR_UNIT_PID_I_SET         (uint8_t) 0x06
#define ID_MOTOR_UNIT_PID_D_SET         (uint8_t) 0x07
#define ID_MOTOR_UNIT_INIT              (uint8_t) 0x08
#define ID_MOTOR_UNIT_LIM_ALERT         (uint8_t) 0x09
#define ID_MOTOR_UNIT_ENC_PPJR_SET      (uint8_t) 0x0A
#define ID_MOTOR_UNIT_MAX_JNT_REV_SET   (uint8_t) 0x0B
#define ID_MOTOR_UNIT_ENC_INIT          (uint8_t) 0x0C
#define ID_MOTOR_UNIT_MAX_PID_PWM       (uint8_t) 0x0D
#define ID_MOTOR_UNIT_POT_INIT_LO       (uint8_t) 0x0F
#define ID_MOTOR_UNIT_POT_INIT_HI       (uint8_t) 0x10
#define ID_MOTOR_UNIT_PCA_SERVO         (uint8_t) 0x11
#define ID_MOTOR_UNIT_SET_ENCODER_BOUND (uint8_t) 0x12

// Packet DLCs
#define DLC_MOTOR_UNIT_MODE_SEL             (uint8_t) 0x02
#define DLC_MOTOR_UNIT_PWM_DIR_SET          (uint8_t) 0x03
#define DLC_MOTOR_UNIT_PID_POS_TGT_SET      (uint8_t) 0x05
#define DLC_MOTOR_UNIT_PID_P_SET            (uint8_t) 0x05
#define DLC_MOTOR_UNIT_PID_I_SET            (uint8_t) 0x05
#define DLC_MOTOR_UNIT_PID_D_SET            (uint8_t) 0x05
#define DLC_MOTOR_UNIT_INIT                 (uint8_t) 0x02
#define DLC_MOTOR_UNIT_LIM_ALERT            (uint8_t) 0x04
#define DLC_MOTOR_UNIT_ENC_PPJR_SET         (uint8_t) 0x05
#define DLC_MOTOR_UNIT_MAX_JNT_REV_SET      (uint8_t) 0x02
#define DLC_MOTOR_UNIT_ENC_INIT             (uint8_t) 0x02
#define DLC_MOTOR_UNIT_MAX_PID_PWM          (uint8_t) 0x03
#define DLC_MOTOR_UNIT_POT_INIT             (uint8_t) 0x07
#define DLC_MOTOR_UNIT_PCA_SERVO            (uint8_t) 0x06
#define DLC_MOTOR_UNIT_ENCODER_BOUND        (uint8_t) 0x06

//Packet priorities 
#define PRIO_MOTOR_UNIT_MODE_SEL            PACKET_PRIORITY_NORMAL
#define PRIO_MOTOR_UNIT_PWM_DIR_SET         PACKET_PRIORITY_NORMAL
#define PRIO_MOTOR_UNIT_PID_POS_TGT_SET     PACKET_PRIORITY_NORMAL
#define PRIO_MOTOR_UNIT_PID_P_SET           PACKET_PRIORITY_NORMAL
#define PRIO_MOTOR_UNIT_PID_I_SET           PACKET_PRIORITY_NORMAL
#define PRIO_MOTOR_UNIT_PID_D_SET           PACKET_PRIORITY_NORMAL
#define PRIO_MOTOR_UNIT_INIT                PACKET_PRIORITY_NORMAL
#define PRIO_MOTOR_UNIT_LIM_ALERT           PACKET_PRIORITY_HIGH
#define PRIO_MOTOR_UNIT_ENC_PPJR_SET        PACKET_PRIORITY_NORMAL
#define PRIO_MOTOR_UNIT_MAX_JNT_REV_SET     PACKET_PRIORITY_NORMAL
#define PRIO_MOTOR_UNIT_ENC_INIT            PACKET_PRIORITY_NORMAL
#define PRIO_MOTOR_UNIT_MAX_PID_PWM         PACKET_PRIORITY_NORMAL
#define PRIO_MOTOR_UNIT_POT_INIT            PACKET_PRIORITY_NORMAL
#define PRIO_MOTOR_UNIT_PCA_SERVO           PACKET_PRIORITY_NORMAL
#define PRIO_MOTOR_UNIT_SET_ENCODER_BOUND   PACKET_PRIORITY_NORMAL

// Motor Unit Mode IDs
#define MOTOR_UNIT_MODE_PWM             (uint8_t) 0x00
#define MOTOR_UNIT_MODE_PID             (uint8_t) 0x01
