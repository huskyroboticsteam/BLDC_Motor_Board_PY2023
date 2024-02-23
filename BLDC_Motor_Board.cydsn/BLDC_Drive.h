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

// State of U, V, and W inductors (H-L)
struct CoilState
{
    uint8_t UH : 1;
    uint8_t UL : 1;
    uint8_t VH : 1;
    uint8_t VL : 1;
    uint8_t WH : 1;
    uint8_t WL : 1;
};

// State of U, V, and W inductors (H-L)
struct HallState
{
    uint8_t A : 1;
    uint8_t B : 1;
    uint8_t C : 1;
};

void set_speed(int16_t speed, uint8_t disable_limit, uint8_t limitSW);
int16_t GetCurrentSpeed();
void readHallState();
void commutateMotor(uint8_t hallState);