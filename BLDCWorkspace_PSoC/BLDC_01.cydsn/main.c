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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        Pin_Red_Write( ~ Pin_Red_Read() );
        CyDelay( 500);
        Pin_Red_Write(0);
        Pin_Green_Write( ~ Pin_Green_Read() );
        CyDelay( 500);
        Pin_Green_Write(0);
        Pin_Blue_Write( ~ Pin_Blue_Read() );
        CyDelay( 500);
        Pin_Blue_Write(0);
    }
}

/* [] END OF FILE */
