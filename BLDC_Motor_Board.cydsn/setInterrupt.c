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
#include "BLDC_Drive.h"

volatile uint32 milliseconds;
//volatile uint16 ms,seconds, minutes, hours;
//volatile int16 MsLedCounter;

// can change name of milliseconditerrupt
CY_ISR(Period_Reset_Handler) {
    milliseconds++;
    // anything to do at a 15ms period, e.g. error LED
}

void init_milliseconds() {
    milliseconds = 0;
    isr_Period_Reset_StartEx(Period_Reset_Handler);
    isr_Hall_StartEx(updateRotorState); // use a pointer to updateRotorState function (when the interrupt is triggered, call the function, don't call it now)
}
