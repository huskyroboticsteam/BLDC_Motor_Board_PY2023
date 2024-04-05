/***************************************************************************//**
* \file TMC6100_PM.c
* \version 4.0
*
* \brief
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "TMC6100.h"
#include "TMC6100_PVT.h"

#if(TMC6100_SCB_MODE_I2C_INC)
    #include "TMC6100_I2C_PVT.h"
#endif /* (TMC6100_SCB_MODE_I2C_INC) */

#if(TMC6100_SCB_MODE_EZI2C_INC)
    #include "TMC6100_EZI2C_PVT.h"
#endif /* (TMC6100_SCB_MODE_EZI2C_INC) */

#if(TMC6100_SCB_MODE_SPI_INC || TMC6100_SCB_MODE_UART_INC)
    #include "TMC6100_SPI_UART_PVT.h"
#endif /* (TMC6100_SCB_MODE_SPI_INC || TMC6100_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(TMC6100_SCB_MODE_UNCONFIG_CONST_CFG || \
   (TMC6100_SCB_MODE_I2C_CONST_CFG   && (!TMC6100_I2C_WAKE_ENABLE_CONST))   || \
   (TMC6100_SCB_MODE_EZI2C_CONST_CFG && (!TMC6100_EZI2C_WAKE_ENABLE_CONST)) || \
   (TMC6100_SCB_MODE_SPI_CONST_CFG   && (!TMC6100_SPI_WAKE_ENABLE_CONST))   || \
   (TMC6100_SCB_MODE_UART_CONST_CFG  && (!TMC6100_UART_WAKE_ENABLE_CONST)))

    TMC6100_BACKUP_STRUCT TMC6100_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: TMC6100_Sleep
****************************************************************************//**
*
*  Prepares the TMC6100 component to enter Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has an influence on this 
*  function implementation:
*  - Checked: configures the component to be wakeup source from Deep Sleep.
*  - Unchecked: stores the current component state (enabled or disabled) and 
*    disables the component. See SCB_Stop() function for details about component 
*    disabling.
*
*  Call the TMC6100_Sleep() function before calling the 
*  CyPmSysDeepSleep() function. 
*  Refer to the PSoC Creator System Reference Guide for more information about 
*  power management functions and Low power section of this document for the 
*  selected mode.
*
*  This function should not be called before entering Sleep.
*
*******************************************************************************/
void TMC6100_Sleep(void)
{
#if(TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)

    if(TMC6100_SCB_WAKE_ENABLE_CHECK)
    {
        if(TMC6100_SCB_MODE_I2C_RUNTM_CFG)
        {
            TMC6100_I2CSaveConfig();
        }
        else if(TMC6100_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            TMC6100_EzI2CSaveConfig();
        }
    #if(!TMC6100_CY_SCBIP_V1)
        else if(TMC6100_SCB_MODE_SPI_RUNTM_CFG)
        {
            TMC6100_SpiSaveConfig();
        }
        else if(TMC6100_SCB_MODE_UART_RUNTM_CFG)
        {
            TMC6100_UartSaveConfig();
        }
    #endif /* (!TMC6100_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        TMC6100_backup.enableState = (uint8) TMC6100_GET_CTRL_ENABLED;

        if(0u != TMC6100_backup.enableState)
        {
            TMC6100_Stop();
        }
    }

#else

    #if (TMC6100_SCB_MODE_I2C_CONST_CFG && TMC6100_I2C_WAKE_ENABLE_CONST)
        TMC6100_I2CSaveConfig();

    #elif (TMC6100_SCB_MODE_EZI2C_CONST_CFG && TMC6100_EZI2C_WAKE_ENABLE_CONST)
        TMC6100_EzI2CSaveConfig();

    #elif (TMC6100_SCB_MODE_SPI_CONST_CFG && TMC6100_SPI_WAKE_ENABLE_CONST)
        TMC6100_SpiSaveConfig();

    #elif (TMC6100_SCB_MODE_UART_CONST_CFG && TMC6100_UART_WAKE_ENABLE_CONST)
        TMC6100_UartSaveConfig();

    #else

        TMC6100_backup.enableState = (uint8) TMC6100_GET_CTRL_ENABLED;

        if(0u != TMC6100_backup.enableState)
        {
            TMC6100_Stop();
        }

    #endif /* defined (TMC6100_SCB_MODE_I2C_CONST_CFG) && (TMC6100_I2C_WAKE_ENABLE_CONST) */

#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: TMC6100_Wakeup
****************************************************************************//**
*
*  Prepares the TMC6100 component for Active mode operation after 
*  Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has influence on this 
*  function implementation:
*  - Checked: restores the component Active mode configuration.
*  - Unchecked: enables the component if it was enabled before enter Deep Sleep.
*
*  This function should not be called after exiting Sleep.
*
*  \sideeffect
*   Calling the TMC6100_Wakeup() function without first calling the 
*   TMC6100_Sleep() function may produce unexpected behavior.
*
*******************************************************************************/
void TMC6100_Wakeup(void)
{
#if(TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)

    if(TMC6100_SCB_WAKE_ENABLE_CHECK)
    {
        if(TMC6100_SCB_MODE_I2C_RUNTM_CFG)
        {
            TMC6100_I2CRestoreConfig();
        }
        else if(TMC6100_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            TMC6100_EzI2CRestoreConfig();
        }
    #if(!TMC6100_CY_SCBIP_V1)
        else if(TMC6100_SCB_MODE_SPI_RUNTM_CFG)
        {
            TMC6100_SpiRestoreConfig();
        }
        else if(TMC6100_SCB_MODE_UART_RUNTM_CFG)
        {
            TMC6100_UartRestoreConfig();
        }
    #endif /* (!TMC6100_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != TMC6100_backup.enableState)
        {
            TMC6100_Enable();
        }
    }

#else

    #if (TMC6100_SCB_MODE_I2C_CONST_CFG  && TMC6100_I2C_WAKE_ENABLE_CONST)
        TMC6100_I2CRestoreConfig();

    #elif (TMC6100_SCB_MODE_EZI2C_CONST_CFG && TMC6100_EZI2C_WAKE_ENABLE_CONST)
        TMC6100_EzI2CRestoreConfig();

    #elif (TMC6100_SCB_MODE_SPI_CONST_CFG && TMC6100_SPI_WAKE_ENABLE_CONST)
        TMC6100_SpiRestoreConfig();

    #elif (TMC6100_SCB_MODE_UART_CONST_CFG && TMC6100_UART_WAKE_ENABLE_CONST)
        TMC6100_UartRestoreConfig();

    #else

        if(0u != TMC6100_backup.enableState)
        {
            TMC6100_Enable();
        }

    #endif /* (TMC6100_I2C_WAKE_ENABLE_CONST) */

#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
