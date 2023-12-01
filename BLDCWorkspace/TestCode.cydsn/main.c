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
#include "project.h"
#include "../CANLib/CANPacket.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        LEDReg_Control = 1;
        CyDelay(500);
        LEDReg_Control = 0;
        CyDelay(500);
        LEDReg_Control = 1;
        
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
