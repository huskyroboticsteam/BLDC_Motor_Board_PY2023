/* File:         Port.h
 * Authors:      Jaden Bottemiller, Benton Kwong, Dylan Tomberlin
 * Organization: Husky Robotics Team
 * 
 * This file includes function prototypes for all functions which must be
 * implemented for each ported device.  Just make a .c file called
 * Port[DeviceName].c based on PortTemplate.
 *
 * Compile insturctions: in addition to cross compiling, you will need to
 * define the constant CHIP_TYPE in your compiler options.  On GCC, use
 * -D CHIP_TYPE=CHIP_TYPE_TEMPLATE
 *  But obviously substitute template for your own constant.  Add it to the list
 *  of constants below if its not already been defined.
 * Documentation: https://huskyroboticsteam.slite.com/app/channels/iU0BryG7M9/collections/aXvWTcIR6c/notes/4otlSFsSp2
 */
#pragma once

#include "CANPacket.h"


void InitCAN(int deviceGroup, int deviceAddress);

//TODO: define constants for these error codes
//Returns 0x0 for successful send
//returns 0x1 for generic error
//returns 0x2 all output buffers are full
//Reserve higher numbers for future error codes
int SendCANPacket(CANPacket *packetToSend);

//Returns 0x0 for SUCCESSFUL packet return
//Returns 0x1 for no message received
//Returns 0x2 for generic error
//Reserve higher numbers for future error codes
int PollAndReceiveCANPacket(CANPacket *receivedPacket);

uint8_t getLocalDeviceSerial();
uint8_t getLocalDeviceGroup();

//Returns constant 
uint8_t getChipType();

//Chip type constants
//TODO: Find specific chip names
#define CHIP_TYPE_TEMPLATE              0x00
#define CHIP_TYPE_STM32Fxxx             0x01
#define CHIP_TYPE_PSOC_CY8C4248AZI_L485 0x02
#define CHIP_TYPE_AT90CANxxx            0x03

//Error code constants
#define ERROR_NONE              0x00
#define ERROR_GENERIC_ERROR     0x01
#define ERROR_NULL_POINTER      0x02 
