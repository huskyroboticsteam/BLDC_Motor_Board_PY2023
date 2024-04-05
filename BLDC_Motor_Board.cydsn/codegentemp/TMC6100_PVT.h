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

#if !defined(CY_SCB_PVT_TMC6100_H)
#define CY_SCB_PVT_TMC6100_H

#include "TMC6100.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define TMC6100_SetI2CExtClkInterruptMode(interruptMask) TMC6100_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define TMC6100_ClearI2CExtClkInterruptSource(interruptMask) TMC6100_CLEAR_INTR_I2C_EC(interruptMask)
#define TMC6100_GetI2CExtClkInterruptSource()                (TMC6100_INTR_I2C_EC_REG)
#define TMC6100_GetI2CExtClkInterruptMode()                  (TMC6100_INTR_I2C_EC_MASK_REG)
#define TMC6100_GetI2CExtClkInterruptSourceMasked()          (TMC6100_INTR_I2C_EC_MASKED_REG)

#if (!TMC6100_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define TMC6100_SetSpiExtClkInterruptMode(interruptMask) \
                                                                TMC6100_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define TMC6100_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                TMC6100_CLEAR_INTR_SPI_EC(interruptMask)
    #define TMC6100_GetExtSpiClkInterruptSource()                 (TMC6100_INTR_SPI_EC_REG)
    #define TMC6100_GetExtSpiClkInterruptMode()                   (TMC6100_INTR_SPI_EC_MASK_REG)
    #define TMC6100_GetExtSpiClkInterruptSourceMasked()           (TMC6100_INTR_SPI_EC_MASKED_REG)
#endif /* (!TMC6100_CY_SCBIP_V1) */

#if(TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void TMC6100_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (TMC6100_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_TMC6100_CUSTOM_INTR_HANDLER)
    extern cyisraddress TMC6100_customIntrHandler;
#endif /* !defined (CY_REMOVE_TMC6100_CUSTOM_INTR_HANDLER) */
#endif /* (TMC6100_SCB_IRQ_INTERNAL) */

extern TMC6100_BACKUP_STRUCT TMC6100_backup;

#if(TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 TMC6100_scbMode;
    extern uint8 TMC6100_scbEnableWake;
    extern uint8 TMC6100_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 TMC6100_mode;
    extern uint8 TMC6100_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * TMC6100_rxBuffer;
    extern uint8   TMC6100_rxDataBits;
    extern uint32  TMC6100_rxBufferSize;

    extern volatile uint8 * TMC6100_txBuffer;
    extern uint8   TMC6100_txDataBits;
    extern uint32  TMC6100_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 TMC6100_numberOfAddr;
    extern uint8 TMC6100_subAddrSize;
#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (TMC6100_SCB_MODE_I2C_CONST_CFG || \
        TMC6100_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 TMC6100_IntrTxMask;
#endif /* (! (TMC6100_SCB_MODE_I2C_CONST_CFG || \
              TMC6100_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define TMC6100_SCB_MODE_I2C_RUNTM_CFG     (TMC6100_SCB_MODE_I2C      == TMC6100_scbMode)
    #define TMC6100_SCB_MODE_SPI_RUNTM_CFG     (TMC6100_SCB_MODE_SPI      == TMC6100_scbMode)
    #define TMC6100_SCB_MODE_UART_RUNTM_CFG    (TMC6100_SCB_MODE_UART     == TMC6100_scbMode)
    #define TMC6100_SCB_MODE_EZI2C_RUNTM_CFG   (TMC6100_SCB_MODE_EZI2C    == TMC6100_scbMode)
    #define TMC6100_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (TMC6100_SCB_MODE_UNCONFIG == TMC6100_scbMode)

    /* Defines wakeup enable */
    #define TMC6100_SCB_WAKE_ENABLE_CHECK       (0u != TMC6100_scbEnableWake)
#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!TMC6100_CY_SCBIP_V1)
    #define TMC6100_SCB_PINS_NUMBER    (7u)
#else
    #define TMC6100_SCB_PINS_NUMBER    (2u)
#endif /* (!TMC6100_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_TMC6100_H) */


/* [] END OF FILE */
