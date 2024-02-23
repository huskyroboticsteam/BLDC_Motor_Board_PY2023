/***************************************************************************//**
* \file .h
* \version 4.0
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_Current_Sensor_I2C_H)
#define CY_SCB_PVT_Current_Sensor_I2C_H

#include "Current_Sensor_I2C.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define Current_Sensor_I2C_SetI2CExtClkInterruptMode(interruptMask) Current_Sensor_I2C_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define Current_Sensor_I2C_ClearI2CExtClkInterruptSource(interruptMask) Current_Sensor_I2C_CLEAR_INTR_I2C_EC(interruptMask)
#define Current_Sensor_I2C_GetI2CExtClkInterruptSource()                (Current_Sensor_I2C_INTR_I2C_EC_REG)
#define Current_Sensor_I2C_GetI2CExtClkInterruptMode()                  (Current_Sensor_I2C_INTR_I2C_EC_MASK_REG)
#define Current_Sensor_I2C_GetI2CExtClkInterruptSourceMasked()          (Current_Sensor_I2C_INTR_I2C_EC_MASKED_REG)

#if (!Current_Sensor_I2C_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define Current_Sensor_I2C_SetSpiExtClkInterruptMode(interruptMask) \
                                                                Current_Sensor_I2C_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define Current_Sensor_I2C_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                Current_Sensor_I2C_CLEAR_INTR_SPI_EC(interruptMask)
    #define Current_Sensor_I2C_GetExtSpiClkInterruptSource()                 (Current_Sensor_I2C_INTR_SPI_EC_REG)
    #define Current_Sensor_I2C_GetExtSpiClkInterruptMode()                   (Current_Sensor_I2C_INTR_SPI_EC_MASK_REG)
    #define Current_Sensor_I2C_GetExtSpiClkInterruptSourceMasked()           (Current_Sensor_I2C_INTR_SPI_EC_MASKED_REG)
#endif /* (!Current_Sensor_I2C_CY_SCBIP_V1) */

#if(Current_Sensor_I2C_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void Current_Sensor_I2C_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (Current_Sensor_I2C_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (Current_Sensor_I2C_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_Current_Sensor_I2C_CUSTOM_INTR_HANDLER)
    extern cyisraddress Current_Sensor_I2C_customIntrHandler;
#endif /* !defined (CY_REMOVE_Current_Sensor_I2C_CUSTOM_INTR_HANDLER) */
#endif /* (Current_Sensor_I2C_SCB_IRQ_INTERNAL) */

extern Current_Sensor_I2C_BACKUP_STRUCT Current_Sensor_I2C_backup;

#if(Current_Sensor_I2C_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 Current_Sensor_I2C_scbMode;
    extern uint8 Current_Sensor_I2C_scbEnableWake;
    extern uint8 Current_Sensor_I2C_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 Current_Sensor_I2C_mode;
    extern uint8 Current_Sensor_I2C_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * Current_Sensor_I2C_rxBuffer;
    extern uint8   Current_Sensor_I2C_rxDataBits;
    extern uint32  Current_Sensor_I2C_rxBufferSize;

    extern volatile uint8 * Current_Sensor_I2C_txBuffer;
    extern uint8   Current_Sensor_I2C_txDataBits;
    extern uint32  Current_Sensor_I2C_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 Current_Sensor_I2C_numberOfAddr;
    extern uint8 Current_Sensor_I2C_subAddrSize;
#endif /* (Current_Sensor_I2C_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (Current_Sensor_I2C_SCB_MODE_I2C_CONST_CFG || \
        Current_Sensor_I2C_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 Current_Sensor_I2C_IntrTxMask;
#endif /* (! (Current_Sensor_I2C_SCB_MODE_I2C_CONST_CFG || \
              Current_Sensor_I2C_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(Current_Sensor_I2C_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define Current_Sensor_I2C_SCB_MODE_I2C_RUNTM_CFG     (Current_Sensor_I2C_SCB_MODE_I2C      == Current_Sensor_I2C_scbMode)
    #define Current_Sensor_I2C_SCB_MODE_SPI_RUNTM_CFG     (Current_Sensor_I2C_SCB_MODE_SPI      == Current_Sensor_I2C_scbMode)
    #define Current_Sensor_I2C_SCB_MODE_UART_RUNTM_CFG    (Current_Sensor_I2C_SCB_MODE_UART     == Current_Sensor_I2C_scbMode)
    #define Current_Sensor_I2C_SCB_MODE_EZI2C_RUNTM_CFG   (Current_Sensor_I2C_SCB_MODE_EZI2C    == Current_Sensor_I2C_scbMode)
    #define Current_Sensor_I2C_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (Current_Sensor_I2C_SCB_MODE_UNCONFIG == Current_Sensor_I2C_scbMode)

    /* Defines wakeup enable */
    #define Current_Sensor_I2C_SCB_WAKE_ENABLE_CHECK       (0u != Current_Sensor_I2C_scbEnableWake)
#endif /* (Current_Sensor_I2C_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!Current_Sensor_I2C_CY_SCBIP_V1)
    #define Current_Sensor_I2C_SCB_PINS_NUMBER    (7u)
#else
    #define Current_Sensor_I2C_SCB_PINS_NUMBER    (2u)
#endif /* (!Current_Sensor_I2C_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_Current_Sensor_I2C_H) */


/* [] END OF FILE */
