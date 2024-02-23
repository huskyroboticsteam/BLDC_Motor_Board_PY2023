/*******************************************************************************
* File Name: WH.c  
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
#include "WH.h"

static WH_BACKUP_STRUCT  WH_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: WH_Sleep
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
*  \snippet WH_SUT.c usage_WH_Sleep_Wakeup
*******************************************************************************/
void WH_Sleep(void)
{
    #if defined(WH__PC)
        WH_backup.pcState = WH_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            WH_backup.usbState = WH_CR1_REG;
            WH_USB_POWER_REG |= WH_USBIO_ENTER_SLEEP;
            WH_CR1_REG &= WH_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(WH__SIO)
        WH_backup.sioState = WH_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        WH_SIO_REG &= (uint32)(~WH_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: WH_Wakeup
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
*  Refer to WH_Sleep() for an example usage.
*******************************************************************************/
void WH_Wakeup(void)
{
    #if defined(WH__PC)
        WH_PC = WH_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            WH_USB_POWER_REG &= WH_USBIO_EXIT_SLEEP_PH1;
            WH_CR1_REG = WH_backup.usbState;
            WH_USB_POWER_REG &= WH_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(WH__SIO)
        WH_SIO_REG = WH_backup.sioState;
    #endif
}


/* [] END OF FILE */
