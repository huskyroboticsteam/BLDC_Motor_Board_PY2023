/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <stdio.h>
#ifndef MotorDrive
    #define MotorDrive
#endif

void set_speed(int16_t speed, uint8_t disable_limit, uint8_t limitSW);
int16_t GetCurrentSpeed();
void readHallState();
void commutateMotor(uint8_t hallState);