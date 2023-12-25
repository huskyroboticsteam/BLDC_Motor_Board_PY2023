#ifndef CAN_SCIENCE_H
#define CAN_SCIENCE_H

/**
   Telemetry ID for the temperature sensor on the science station.
 */
#define CAN_SCIENCE_SENSOR_TEMPERATURE PACKET_TELEMETRY_SENSOR1
/**
   Telemetry ID for the UV sensor on the science station.
 */
#define CAN_SCIENCE_SENSOR_UV PACKET_TELEMETRY_SENSOR2
/**
   Telemetry ID for the moisture sensor on the science station.
 */
#define CAN_SCIENCE_SENSOR_MOISTURE PACKET_TELEMETRY_SENSOR3

/**
   Packet ID for the Lazy Susan position set packet.
 */
#define ID_SCIENCE_LAZY_SUSAN_POS_SET ((uint8_t)0x0C)
/**
   Packet ID for the positional servo set packet.
 */
#define ID_SCIENCE_SERVO_SET            ((uint8_t) 0x0D)
/**
   Packet ID for the continuous rotation servo power set packet.
 */
#define ID_SCIENCE_CONT_SERVO_POWER_SET ((uint8_t) 0x0E)

#include "CANPacket.h"

/**
 * @brief Assemble a packet to set the position of a servo for the science station.
 *
 * @warning This packet is intended only for positional servos; the behavior is undefined if a
 * continuous rotation servo is used.
 *
 * @param packetToAssemble The packet to write the data into.
 * @param targetDeviceGroup The group of the target device.
 * @param targetDeviceSerial Ther serial code of the target device.
 * @param servo The ID of the servo.
 * @param degrees The position of the servo in degrees, from 0-179.
 *
 * @see https://github.com/huskyroboticsteam/HindsightCAN/wiki/Science-(Sensor)-Board-Packets
 */
void AssembleScienceServoPacket(CANPacket *packetToAssemble,
                                uint8_t targetGroup, uint8_t targetSerial,
                                uint8_t servo, uint8_t degrees);

/**
 * @brief Assemble a packet to set the position of the Lazy Susan on the science
 * station.
 *
 * Sets the position of the first cup (whichever cup is closest to the funnel on
 * startup) to one of twelve positions around the circle, where 0 is the funnel. Even
 * positions are under holes in the divider and odd positions are in between holes.
 *
 * @param packetToAssemble The packet to write the data into.
 * @param targetDeviceGroup The group of the target device.
 * @param targetDeviceSerial Ther serial code of the target device.
 * @param position The position, from 0-11. 
 *
 * @warning Behavior is undefined if a position above 11 is given.
 *
 * @see https://github.com/huskyroboticsteam/HindsightCAN/wiki/Science-(Sensor)-Board-Packets
 */
void AssembleScienceLazySusanPosSetPacket(CANPacket *packetToAssemble,
                                          uint8_t targetDeviceGroup,
                                          uint8_t targetDeviceSerial,
                                          uint8_t position);

/**
 * @brief Assemble a packet to set the power of a continuous rotation servo on
 * the science station.
 *
 * @warning This packet is intended only for continuous rotation servos; the
 * behavior is undefined if a positional servo is used.
 *
 * @param packetToAssemble The packet to write the data into.
 * @param targetDeviceGroup The group of the target device.
 * @param targetDeviceSerial Ther serial code of the target device.
 * @param servo The ID of the servo.
 * @param power The power of the servo, from -100 to 100.
 *
 * @warning Behavior is undefined if the power is outside of the [-100, 100]
 * range.
 * 
 * @see https://github.com/huskyroboticsteam/HindsightCAN/wiki/Science-(Sensor)-Board-Packets
 */
void AssembleScienceContServoPowerSetPacket(CANPacket *packetToAssemble,
											uint8_t targetDeviceGroup,
											uint8_t targetDeviceSerial,
											uint8_t servo,
											int8_t power);

/**
 *  @brief Gets the servo ID from a science station servo packet.
 *  @param A CANPacket, that is one of the two science station servo-related packets.
 *  @return The servo ID for the packet.
 *
 *  @warning This function is intended to be used only on servo-related packets; return value
 *  is undefined if packet is not a servo packet.
 */
uint8_t GetScienceServoIDFromPacket(const CANPacket *packet);

/**
 *  @brief Gets the servo angle from a science station servo set packet.
 *  @param A science station servo set packet, as a CANPacket
 *  @return The servo angle in this packet.
 *
 *  @warning This function is intended to be used only on positional servo set packets; return
 *  value is undefined otherwise.
 */
uint8_t GetScienceServoAngleFromPacket(const CANPacket *packet);

/**
 *  @brief Gets the Lazy Susan position from a science station Lazy Susan position set packet.
 *  @param A science station Lazy Susan position set packet, as a CANPacket
 *  @return The Lazy Susan position in this packet.
 *
 *  @warning This function is intended to be used only on Lazy Susan packets; return value
 *  is undefined otherwise.
 */
uint8_t GetScienceLazySusanPosFromPacket(const CANPacket *packet);

/**
 *  @brief Gets the servo power from a science station continuous rotation servo set packet.
 *  @param A science station continuous rotation servo set packet, as a CANPacket
 *  @return The servo power in this packet.
 *
 *  @warning This function is intended to be used only on continuous rotation servo set
 *  packets; return value is undefined otherwise.
 */
int8_t GetScienceContServoPowerFromPacket(const CANPacket *packet);

#endif
