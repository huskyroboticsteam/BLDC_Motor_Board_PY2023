/*******************************************************************************
* File Name: ADC_Pot_INT.c
* Version 2.50
*
*  Description:
*    This file contains the code that operates during the ADC_SAR interrupt
*    service routine.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_Pot.h"
#include "cyapicallbacks.h"


/******************************************************************************
* Custom Declarations and Variables
* - add user inlcude files, prototypes and variables between the following
*   #START and #END tags
******************************************************************************/
/* `#START ADC_SYS_VAR`  */

/* `#END`  */

#if(ADC_Pot_IRQ_REMOVE == 0u)


    /******************************************************************************
    * Function Name: ADC_Pot_ISR
    *******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Reentrant:
    *  No.
    *
    ******************************************************************************/
    CY_ISR( ADC_Pot_ISR )
    {
        uint32 intr_status;

        /* Read interrupt status register */
        intr_status = ADC_Pot_SAR_INTR_REG;

        #ifdef ADC_Pot_ISR_INTERRUPT_CALLBACK
            ADC_Pot_ISR_InterruptCallback();
        #endif /* ADC_Pot_ISR_INTERRUPT_CALLBACK */


        /************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        *************************************************************************/
        /* `#START MAIN_ADC_ISR`  */

        /* `#END`  */
        
        /* Clear handled interrupt */
        ADC_Pot_SAR_INTR_REG = intr_status;
    }

#endif   /* End ADC_Pot_IRQ_REMOVE */


/* [] END OF FILE */
