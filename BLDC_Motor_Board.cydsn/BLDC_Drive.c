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
int8_t currentRotorState = 0;

uint8_t rotorStates[6] = {0b001001,
                          0b011000,
                          0b010010,
                          0b000110,
                          0b100100,
                          0b100001};

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
        Timer_Rotor_Delay_Start(); // resume timer
        delay_ms = (float)(1 << 15)*10000/currentSpeed/MAX_RPM; //TODO: FIX THIS
    }
    else {
        delay_ms = 0;
        // stop motor (stop state machine)
        UH_Write(0);
        UL_Write(0);
        VH_Write(0);
        VL_Write(0);
        WH_Write(0);
        WL_Write(0);
        Timer_Rotor_Delay_Stop(); // pause timer
    }
    
    Timer_Rotor_Delay_WritePeriod(delay_ms); // convert to ticks
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


void updateRotorState() {
    // make a state variable for direction and stop, direction - drive it backwards, stop - stop the 
    
    // hallState.A = HALL1_Read();
    // hallState.B = HALL2_Read();
    // hallState.C = HALL3_Read();
    // 
    // // forward
    // coilState.UH = !hallState.B && hallState.C;
	// coilState.UL = !hallState.C && hallState.B;
	// coilState.VH = !hallState.C && hallState.A;
	// coilState.VL = !hallState.A && hallState.C;
	// coilState.WH = !hallState.A && hallState.B;
	// coilState.WL = !hallState.B && hallState.A;
    
    currentRotorState += currentDir;
    
    if (currentRotorState <= -1) {
        currentRotorState = 5;
    } else if (currentRotorState >= 6) {
        currentRotorState = 0;
    }
    uint8_t state = rotorStates[currentRotorState];
    
    
    // write registers in UVW
    UH_Write((state & (1 << 0)) != 0);
    UL_Write((state & (1 << 1)) != 0);
    VH_Write((state & (1 << 2)) != 0);
    VL_Write((state & (1 << 3)) != 0);
    WH_Write((state & (1 << 4)) != 0);
    WL_Write((state & (1 << 5)) != 0);
}