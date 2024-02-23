/*

    Rotor FSM:
        - Phase shifting logic
        
*/

// -------------------------------------------------------------------------WE ARE NOT USING PWM
#include <project.h>
#include <stdio.h>
#include "main.h"
#include <stdint.h>
#include "BLDC_Drive.h"
#include <project.h>

uint8_t invalidate = 0;
extern char txData[TX_DATA_SIZE];

int32_t currentSpeed = 0;
int8_t currentDir = 0;

#define MAX_RPM 1000

// Timer
float delay_ms;

void commutateMotor(uint8_t hallState) {
    // determine the motor phase to energize based on the hall state
        
        // TODO: implement th appropriate logic to switch the motor phases
}

// -32768 <= speed < 32768
void set_speed(int16_t speed, uint8_t disable_limit) {
    #ifdef PRINT_PWM_COMMAND
    sprintf(txData, "PWM:%d disable_limit: %d\r\n",compare,disable_limit);
    UART_UartPutString(txData); 
    #endif
   
    uint8 limitSW = disable_limit ? 0 : Limit_Register_Read();
    
    invalidate = 0;
    if (speed < 0 && !(limitSW & 0b10)) { // check if speed is negative, if not (hit the bottom limit switch) || limit switch is disabled
        currentDir = 0;
        currentSpeed = -speed;
    } else if (speed > 0 && !(limitSW & 0b01)){ // check if speed is positive, if not (hit the top limit switch) || limit switch is disabled
        currentDir = 1;
        currentSpeed = speed;
    } else { // set speed = 0; (special case
        currentSpeed = 0;
    }
    
    if (currentSpeed != 0) {
        delay_ms = (float)(1 << 15)*10000/currentSpeed/MAX_RPM;
    }
    else {
        delay_ms = 0;
        // stop motor (stop state machine)
        
    }
}

int16_t GetCurrentSpeed() {
    return currentSpeed;
}

struct CoilState coilState = {0,0,0,0,0,0};
struct HallState hallState = {0,0,0};

// FSM changing through states
// "--state = X" means "don't-care"
// Read the states

// turn this into a long case statement???

// add a method that stops this finite state machine


void readHallState() {
    hallState.A = HALL1_Read();
    hallState.B = HALL2_Read();
    hallState.C = HALL3_Read();
    
    coilState.UH = !hallState.B && hallState.C;
	coilState.UL = !hallState.C && hallState.B;
	coilState.VH = !hallState.C && hallState.A;
	coilState.VL = !hallState.A && hallState.C;
	coilState.WH = !hallState.A && hallState.B;
	coilState.WL = !hallState.B && hallState.A;
    
    // write registers in UVW
    UH_Write(coilState.UH);
    UL_Write(coilState.UL);
    VH_Write(coilState.VH);
    VL_Write(coilState.VL);
    WH_Write(coilState.WH);
    WL_Write(coilState.WL);
}