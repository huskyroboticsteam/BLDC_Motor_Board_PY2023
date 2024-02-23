/*******************************************************************************
* File Name: UH.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "UH.h"

static UH_BACKUP_STRUCT  UH_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: UH_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet UH_SUT.c usage_UH_Sleep_Wakeup
*******************************************************************************/
void UH_Sleep(void)
{
    #if defined(UH__PC)
        UH_backup.pcState = UH_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            UH_backup.usbState = UH_CR1_REG;
            UH_USB_POWER_REG |= UH_USBIO_ENTER_SLEEP;
            UH_CR1_REG &= UH_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(UH__SIO)
        UH_backup.sioState = UH_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        UH_SIO_REG &= (uint32)(~UH_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: UH_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to UH_Sleep() for an example usage.
*******************************************************************************/
void UH_Wakeup(void)
{
    #if defined(UH__PC)
        UH_PC = UH_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            UH_USB_POWER_REG &= UH_USBIO_EXIT_SLEEP_PH1;
            UH_CR1_REG = UH_backup.usbState;
            UH_USB_POWER_REG &= UH_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(UH__SIO)
        UH_SIO_REG = UH_backup.sioState;
    #endif
}


/* [] END OF FILE */
