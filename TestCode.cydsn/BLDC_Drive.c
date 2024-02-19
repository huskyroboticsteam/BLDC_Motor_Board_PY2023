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

// Define Hall effect sensor pins:
#define HALL_A_PIN
#define HALL_B_PIN
#define HALL_C_PIN

#define PHASE_U_PIN
#define PHASE_V_PIN
#define PHASE_W_PIN

#define MAX_RPM 1000

// Timer
float delay_ms;

void commutateMotor(uint8_t hallState) {
    // determine the motor phase to energize based on the hall state
        
        // TODO: implement th appropriate logic to switch the motor phases
}

// -32768 <= speed < 32768
void set_speed(int16_t speed, uint8_t disable_limit, uint8 limitSW) {
    #ifdef PRINT_PWM_COMMAND
    sprintf(txData, "PWM:%d disable_limit: %d\r\n",compare,disable_limit);
    UART_UartPutString(txData); 
    #endif
    
    invalidate = 0;
    if (speed < 0 && (!(limitSW & 0b10) || disable_limit) ) { // check if speed is negative, if not (hit the bottom limit switch) || limit switch is disabled
        currentDir = 0;
        currentSpeed = -speed;
    } else if (speed > 0 && (!(limitSW & 0b01) || disable_limit) ){ // check if speed is positive, if not (hit the top limit switch) || limit switch is disabled
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


// State of U, V, and W inductors high (polarity) and low (enable)
uint8_t UHstate = 0;
uint8_t ULstate = 0;
uint8_t VHstate = 0;
uint8_t VLstate = 0;
uint8_t WHstate = 0;
uint8_t WLstate = 0;

// Hall effect sensor binary data
uint8_t hall1State;
uint8_t hall2State;
uint8_t hall3State;

uint8_t BLDC_state;
// FSM changing through states
// "--state = X" means "don't-care"
// Read the states
void readHallState() {
    hall1State = HALL1_Read();
    hall2State = HALL2_Read();
    hall3State = HALL3_Read();
    
	// State 1 (001)
	if (~hall1State && ~hall2State && hall3State) {
        UHstate = 1;
		ULstate = 1;
		// VHstate = X;
		VLstate = 0;
		WHstate = 0;
		WLstate = 1;
	}

	// State 2 (101)
	if (~hall1State && hall2State && hall3State) {
		// UHstate = X;
		ULstate = 0;
		VHstate = 1;
		VLstate = 0;
		WHstate = 0;
		WLstate = 1;
	}

	// State 3 (100)
	if (~hall1State && hall2State && hall3State) {
		UHstate = 0;
		ULstate = 1;
		VHstate = 1;
		VLstate = 1;
		// WHstate = X;
		WLstate = 0;
	}

    // State 4 (110)
    if (hall1State && ~hall2State && ~hall3State) {
		UHstate = 0;
		ULstate = 1;
		// VHstate = X;
		VLstate = 0;
		WHstate = 0;
		WLstate = 1;
    }
	    // State 5 (010)
    if (hall1State && ~hall2State && hall3State) {
		// UHstate = X;
		ULstate = 1;
		VHstate = 0;
		VLstate = 1;
		WHstate = 0;
		WLstate = 1;
    }
	    // State 6 (011)
    if (hall1State && hall2State && ~hall3State) {
		UHstate = 1;
		ULstate = 1;
		// VHstate = X;
		VLstate = 1;
		WHstate = 0;
		WLstate = 1;
    }
    
    UH_Write(UHstate);
    UL_Write(ULstate);
    VH_Write(VHstate);
    VL_Write(VLstate);
    WH_Write(WHstate);
    WL_Write(WLstate);
    
}