/*******************************************************************************
* File Name: DRV_EN.c  
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
#include "DRV_EN.h"

static DRV_EN_BACKUP_STRUCT  DRV_EN_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: DRV_EN_Sleep
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
*  \snippet DRV_EN_SUT.c usage_DRV_EN_Sleep_Wakeup
*******************************************************************************/
void DRV_EN_Sleep(void)
{
    #if defined(DRV_EN__PC)
        DRV_EN_backup.pcState = DRV_EN_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            DRV_EN_backup.usbState = DRV_EN_CR1_REG;
            DRV_EN_USB_POWER_REG |= DRV_EN_USBIO_ENTER_SLEEP;
            DRV_EN_CR1_REG &= DRV_EN_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DRV_EN__SIO)
        DRV_EN_backup.sioState = DRV_EN_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        DRV_EN_SIO_REG &= (uint32)(~DRV_EN_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: DRV_EN_Wakeup
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
*  Refer to DRV_EN_Sleep() for an example usage.
*******************************************************************************/
void DRV_EN_Wakeup(void)
{
    #if defined(DRV_EN__PC)
        DRV_EN_PC = DRV_EN_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            DRV_EN_USB_POWER_REG &= DRV_EN_USBIO_EXIT_SLEEP_PH1;
            DRV_EN_CR1_REG = DRV_EN_backup.usbState;
            DRV_EN_USB_POWER_REG &= DRV_EN_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DRV_EN__SIO)
        DRV_EN_SIO_REG = DRV_EN_backup.sioState;
    #endif
}


/* [] END OF FILE */
