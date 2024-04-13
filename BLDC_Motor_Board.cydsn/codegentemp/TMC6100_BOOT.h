/***************************************************************************//**
* \file TMC6100_BOOT.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2014-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_TMC6100_H)
#define CY_SCB_BOOT_TMC6100_H

#include "TMC6100_PVT.h"

#if (TMC6100_SCB_MODE_I2C_INC)
    #include "TMC6100_I2C.h"
#endif /* (TMC6100_SCB_MODE_I2C_INC) */

#if (TMC6100_SCB_MODE_EZI2C_INC)
    #include "TMC6100_EZI2C.h"
#endif /* (TMC6100_SCB_MODE_EZI2C_INC) */

#if (TMC6100_SCB_MODE_SPI_INC || TMC6100_SCB_MODE_UART_INC)
    #include "TMC6100_SPI_UART.h"
#endif /* (TMC6100_SCB_MODE_SPI_INC || TMC6100_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define TMC6100_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_TMC6100) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (TMC6100_SCB_MODE_I2C_INC)
    #define TMC6100_I2C_BTLDR_COMM_ENABLED     (TMC6100_BTLDR_COMM_ENABLED && \
                                                            (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             TMC6100_I2C_SLAVE_CONST))
#else
     #define TMC6100_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (TMC6100_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (TMC6100_SCB_MODE_EZI2C_INC)
    #define TMC6100_EZI2C_BTLDR_COMM_ENABLED   (TMC6100_BTLDR_COMM_ENABLED && \
                                                         TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define TMC6100_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (TMC6100_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (TMC6100_SCB_MODE_SPI_INC)
    #define TMC6100_SPI_BTLDR_COMM_ENABLED     (TMC6100_BTLDR_COMM_ENABLED && \
                                                            (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             TMC6100_SPI_SLAVE_CONST))
#else
        #define TMC6100_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (TMC6100_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (TMC6100_SCB_MODE_UART_INC)
       #define TMC6100_UART_BTLDR_COMM_ENABLED    (TMC6100_BTLDR_COMM_ENABLED && \
                                                            (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (TMC6100_UART_RX_DIRECTION && \
                                                              TMC6100_UART_TX_DIRECTION)))
#else
     #define TMC6100_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (TMC6100_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define TMC6100_BTLDR_COMM_MODE_ENABLED    (TMC6100_I2C_BTLDR_COMM_ENABLED   || \
                                                     TMC6100_SPI_BTLDR_COMM_ENABLED   || \
                                                     TMC6100_EZI2C_BTLDR_COMM_ENABLED || \
                                                     TMC6100_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (TMC6100_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void TMC6100_I2CCyBtldrCommStart(void);
    void TMC6100_I2CCyBtldrCommStop (void);
    void TMC6100_I2CCyBtldrCommReset(void);
    cystatus TMC6100_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus TMC6100_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (TMC6100_SCB_MODE_I2C_CONST_CFG)
        #define TMC6100_CyBtldrCommStart   TMC6100_I2CCyBtldrCommStart
        #define TMC6100_CyBtldrCommStop    TMC6100_I2CCyBtldrCommStop
        #define TMC6100_CyBtldrCommReset   TMC6100_I2CCyBtldrCommReset
        #define TMC6100_CyBtldrCommRead    TMC6100_I2CCyBtldrCommRead
        #define TMC6100_CyBtldrCommWrite   TMC6100_I2CCyBtldrCommWrite
    #endif /* (TMC6100_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (TMC6100_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (TMC6100_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void TMC6100_EzI2CCyBtldrCommStart(void);
    void TMC6100_EzI2CCyBtldrCommStop (void);
    void TMC6100_EzI2CCyBtldrCommReset(void);
    cystatus TMC6100_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus TMC6100_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (TMC6100_SCB_MODE_EZI2C_CONST_CFG)
        #define TMC6100_CyBtldrCommStart   TMC6100_EzI2CCyBtldrCommStart
        #define TMC6100_CyBtldrCommStop    TMC6100_EzI2CCyBtldrCommStop
        #define TMC6100_CyBtldrCommReset   TMC6100_EzI2CCyBtldrCommReset
        #define TMC6100_CyBtldrCommRead    TMC6100_EzI2CCyBtldrCommRead
        #define TMC6100_CyBtldrCommWrite   TMC6100_EzI2CCyBtldrCommWrite
    #endif /* (TMC6100_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (TMC6100_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (TMC6100_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void TMC6100_SpiCyBtldrCommStart(void);
    void TMC6100_SpiCyBtldrCommStop (void);
    void TMC6100_SpiCyBtldrCommReset(void);
    cystatus TMC6100_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus TMC6100_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (TMC6100_SCB_MODE_SPI_CONST_CFG)
        #define TMC6100_CyBtldrCommStart   TMC6100_SpiCyBtldrCommStart
        #define TMC6100_CyBtldrCommStop    TMC6100_SpiCyBtldrCommStop
        #define TMC6100_CyBtldrCommReset   TMC6100_SpiCyBtldrCommReset
        #define TMC6100_CyBtldrCommRead    TMC6100_SpiCyBtldrCommRead
        #define TMC6100_CyBtldrCommWrite   TMC6100_SpiCyBtldrCommWrite
    #endif /* (TMC6100_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (TMC6100_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (TMC6100_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void TMC6100_UartCyBtldrCommStart(void);
    void TMC6100_UartCyBtldrCommStop (void);
    void TMC6100_UartCyBtldrCommReset(void);
    cystatus TMC6100_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus TMC6100_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (TMC6100_SCB_MODE_UART_CONST_CFG)
        #define TMC6100_CyBtldrCommStart   TMC6100_UartCyBtldrCommStart
        #define TMC6100_CyBtldrCommStop    TMC6100_UartCyBtldrCommStop
        #define TMC6100_CyBtldrCommReset   TMC6100_UartCyBtldrCommReset
        #define TMC6100_CyBtldrCommRead    TMC6100_UartCyBtldrCommRead
        #define TMC6100_CyBtldrCommWrite   TMC6100_UartCyBtldrCommWrite
    #endif /* (TMC6100_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (TMC6100_UART_BTLDR_COMM_ENABLED) */

/**
* \addtogroup group_bootloader
* @{
*/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (TMC6100_BTLDR_COMM_ENABLED)
    #if (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void TMC6100_CyBtldrCommStart(void);
        void TMC6100_CyBtldrCommStop (void);
        void TMC6100_CyBtldrCommReset(void);
        cystatus TMC6100_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus TMC6100_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_TMC6100)
        #define CyBtldrCommStart    TMC6100_CyBtldrCommStart
        #define CyBtldrCommStop     TMC6100_CyBtldrCommStop
        #define CyBtldrCommReset    TMC6100_CyBtldrCommReset
        #define CyBtldrCommWrite    TMC6100_CyBtldrCommWrite
        #define CyBtldrCommRead     TMC6100_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_TMC6100) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (TMC6100_BTLDR_COMM_ENABLED) */

/** @} group_bootloader */

/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define TMC6100_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define TMC6100_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define TMC6100_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define TMC6100_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef TMC6100_SPI_BYTE_TO_BYTE
    #define TMC6100_SPI_BYTE_TO_BYTE   (20u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef TMC6100_UART_BYTE_TO_BYTE
    #define TMC6100_UART_BYTE_TO_BYTE  (2500u)
#endif /* TMC6100_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_TMC6100_H) */


/* [] END OF FILE */
