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

#include "setInterrupt.h"
#include "project.h"

volatile uint32 milliseconds;
//volatile uint16 ms,seconds, minutes, hours;
//volatile int16 MsLedCounter;

// can change name of milliseconditerrupt
CY_ISR(MillisecondInterrupt) {
    milliseconds++;
    
}

void init_milliseconds() {
    milliseconds = 0;
    isr_1_StartEx(MillisecondInterrupt);
    
}
