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

#if !defined(CY_SCB_PVT_TMC6100_SPI_H)
#define CY_SCB_PVT_TMC6100_SPI_H

#include "TMC6100_SPI.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define TMC6100_SPI_SetI2CExtClkInterruptMode(interruptMask) TMC6100_SPI_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define TMC6100_SPI_ClearI2CExtClkInterruptSource(interruptMask) TMC6100_SPI_CLEAR_INTR_I2C_EC(interruptMask)
#define TMC6100_SPI_GetI2CExtClkInterruptSource()                (TMC6100_SPI_INTR_I2C_EC_REG)
#define TMC6100_SPI_GetI2CExtClkInterruptMode()                  (TMC6100_SPI_INTR_I2C_EC_MASK_REG)
#define TMC6100_SPI_GetI2CExtClkInterruptSourceMasked()          (TMC6100_SPI_INTR_I2C_EC_MASKED_REG)

#if (!TMC6100_SPI_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define TMC6100_SPI_SetSpiExtClkInterruptMode(interruptMask) \
                                                                TMC6100_SPI_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define TMC6100_SPI_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                TMC6100_SPI_CLEAR_INTR_SPI_EC(interruptMask)
    #define TMC6100_SPI_GetExtSpiClkInterruptSource()                 (TMC6100_SPI_INTR_SPI_EC_REG)
    #define TMC6100_SPI_GetExtSpiClkInterruptMode()                   (TMC6100_SPI_INTR_SPI_EC_MASK_REG)
    #define TMC6100_SPI_GetExtSpiClkInterruptSourceMasked()           (TMC6100_SPI_INTR_SPI_EC_MASKED_REG)
#endif /* (!TMC6100_SPI_CY_SCBIP_V1) */

#if(TMC6100_SPI_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void TMC6100_SPI_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (TMC6100_SPI_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (TMC6100_SPI_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_TMC6100_SPI_CUSTOM_INTR_HANDLER)
    extern cyisraddress TMC6100_SPI_customIntrHandler;
#endif /* !defined (CY_REMOVE_TMC6100_SPI_CUSTOM_INTR_HANDLER) */
#endif /* (TMC6100_SPI_SCB_IRQ_INTERNAL) */

extern TMC6100_SPI_BACKUP_STRUCT TMC6100_SPI_backup;

#if(TMC6100_SPI_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 TMC6100_SPI_scbMode;
    extern uint8 TMC6100_SPI_scbEnableWake;
    extern uint8 TMC6100_SPI_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 TMC6100_SPI_mode;
    extern uint8 TMC6100_SPI_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * TMC6100_SPI_rxBuffer;
    extern uint8   TMC6100_SPI_rxDataBits;
    extern uint32  TMC6100_SPI_rxBufferSize;

    extern volatile uint8 * TMC6100_SPI_txBuffer;
    extern uint8   TMC6100_SPI_txDataBits;
    extern uint32  TMC6100_SPI_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 TMC6100_SPI_numberOfAddr;
    extern uint8 TMC6100_SPI_subAddrSize;
#endif /* (TMC6100_SPI_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (TMC6100_SPI_SCB_MODE_I2C_CONST_CFG || \
        TMC6100_SPI_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 TMC6100_SPI_IntrTxMask;
#endif /* (! (TMC6100_SPI_SCB_MODE_I2C_CONST_CFG || \
              TMC6100_SPI_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(TMC6100_SPI_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define TMC6100_SPI_SCB_MODE_I2C_RUNTM_CFG     (TMC6100_SPI_SCB_MODE_I2C      == TMC6100_SPI_scbMode)
    #define TMC6100_SPI_SCB_MODE_SPI_RUNTM_CFG     (TMC6100_SPI_SCB_MODE_SPI      == TMC6100_SPI_scbMode)
    #define TMC6100_SPI_SCB_MODE_UART_RUNTM_CFG    (TMC6100_SPI_SCB_MODE_UART     == TMC6100_SPI_scbMode)
    #define TMC6100_SPI_SCB_MODE_EZI2C_RUNTM_CFG   (TMC6100_SPI_SCB_MODE_EZI2C    == TMC6100_SPI_scbMode)
    #define TMC6100_SPI_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (TMC6100_SPI_SCB_MODE_UNCONFIG == TMC6100_SPI_scbMode)

    /* Defines wakeup enable */
    #define TMC6100_SPI_SCB_WAKE_ENABLE_CHECK       (0u != TMC6100_SPI_scbEnableWake)
#endif /* (TMC6100_SPI_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!TMC6100_SPI_CY_SCBIP_V1)
    #define TMC6100_SPI_SCB_PINS_NUMBER    (7u)
#else
    #define TMC6100_SPI_SCB_PINS_NUMBER    (2u)
#endif /* (!TMC6100_SPI_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_TMC6100_SPI_H) */


/* [] END OF FILE */
