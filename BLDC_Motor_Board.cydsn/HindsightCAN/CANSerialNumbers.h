/* File:         CANSerialNumbers.h
 * Authors:      Jaden Bottemiller, Benton Kwong, Dylan Tomberlin
 * Organization: Husky Robotics Team
 * 
 * This file defines the serial numbers for each device
 * on the Hindsight (PY2020 Rover). Sorted by Device Group
 * 
 * Serial Numbers are 6bits wide.
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */

// BROADCAST GROUP
// Use this serial number and the BROADCAST device group to
// broadcast a packet to all devices.
// Use this serial number and a specific device group to 
// broadcast a packet to all devices within a group.
#pragma once

#define DEVICE_SERIAL_BROADCAST         (uint8_t) 0x00

// JETSON GROUP
#define DEVICE_SERIAL_JETSON            (uint8_t) 0x01

// MOTOR UNIT GROUP
#define DEVICE_SERIAL_MOTOR_BASE                (uint8_t) 0x01
#define DEVICE_SERIAL_MOTOR_SHOULDER            (uint8_t) 0x02
#define DEVICE_SERIAL_MOTOR_ELBOW               (uint8_t) 0x03
#define DEVICE_SERIAL_MOTOR_FOREARM             (uint8_t) 0x04
#define DEVICE_SERIAL_MOTOR_WRIST               (uint8_t) 0x05
#define DEVICE_SERIAL_MOTOR_HAND                (uint8_t) 0x06
#define DEVICE_SERIAL_LINEAR_ACTUATOR           (uint8_t) 0x07

#define DEVICE_SERIAL_MOTOR_CHASSIS_FL          (uint8_t) 0x08 //Front Left
#define DEVICE_SERIAL_MOTOR_CHASSIS_FR          (uint8_t) 0x09
#define DEVICE_SERIAL_MOTOR_CHASSIS_BL          (uint8_t) 0x0a 
#define DEVICE_SERIAL_MOTOR_CHASSIS_BR          (uint8_t) 0x0b //Back Right

#define DEVICE_SERIAL_MOTOR_CHASSIS_FL_SW       (uint8_t) 0x18 //Front Left
#define DEVICE_SERIAL_MOTOR_CHASSIS_FR_SW       (uint8_t) 0x19
#define DEVICE_SERIAL_MOTOR_CHASSIS_BL_SW       (uint8_t) 0x1a 
#define DEVICE_SERIAL_MOTOR_CHASSIS_BR_SW       (uint8_t) 0x1b //Back Right

//Power group
#define DEVICE_SERIAL_POWER_BATT_MAN            (uint8_t) 0x01
#define DEVICE_SERIAL_POWER_CHASSIS_MAIN        (uint8_t) 0x02
#define DEVICE_SERIAL_POWER_CHASSIS_DRIVE_L     (uint8_t) 0x03 //Left
#define DEVICE_SERIAL_POWER_CHASSIS_DRIVE_R     (uint8_t) 0x04 //Right
#define DEVICE_SERIAL_POWER_ARM_LOWER_1         (uint8_t) 0x05 //may have more arm
#define DEVICE_SERIAL_POWER_ARM_UPPER_1         (uint8_t) 0x06
#define DEVICE_SERIAL_POWER_SCIENCE             (uint8_t) 0x07

//Telemetry group
#define DEVICE_SERIAL_TELEM_LOCALIZATION        (uint8_t) 0x01
#define DEVICE_SERIAL_TELEM_IMU                 (uint8_t) 0x02
#define DEVICE_SERIAL_TELEM_TEMPERATURE (uint8_t)0x03

// Science group
#define DEVICE_SERIAL_SCIENCE_STATION           ((uint8_t) 0x01)
#define DEVICE_SERIAL_DRILL_ARM_MOTOR           (uint8_t) 0x02
#define DEVICE_SERIAL_DRILL_MOTOR               (uint8_t) 0x03

//Group numbers
/*
#define DEVICE_GROUP_BROADCAST  0x0
#define DEVICE_GROUP_RESERVED   0x1
#define DEVICE_GROUP_MASTER     0x2
#define DEVICE_GROUP_POWER      0x3
#define DEVICE_GROUP_MOTORS     0x4
#define DEVICE_GROUP_TELEM      0x5
#define DEVICE_GROUP_GPIO       0x6
*/
