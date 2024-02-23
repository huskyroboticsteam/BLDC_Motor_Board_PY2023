/***************************************************************************//**
* \file Current_Sensor_I2C_PINS.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
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

#if !defined(CY_SCB_PINS_Current_Sensor_I2C_H)
#define CY_SCB_PINS_Current_Sensor_I2C_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define Current_Sensor_I2C_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define Current_Sensor_I2C_REMOVE_RX_SCL_MOSI_PIN      (1u)
#define Current_Sensor_I2C_REMOVE_TX_SDA_MISO_PIN      (1u)
#define Current_Sensor_I2C_REMOVE_CTS_SCLK_PIN      (1u)
#define Current_Sensor_I2C_REMOVE_RTS_SS0_PIN      (1u)
#define Current_Sensor_I2C_REMOVE_SS1_PIN                 (1u)
#define Current_Sensor_I2C_REMOVE_SS2_PIN                 (1u)
#define Current_Sensor_I2C_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define Current_Sensor_I2C_REMOVE_I2C_PINS                (0u)
#define Current_Sensor_I2C_REMOVE_SPI_MASTER_PINS         (1u)
#define Current_Sensor_I2C_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define Current_Sensor_I2C_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define Current_Sensor_I2C_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define Current_Sensor_I2C_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define Current_Sensor_I2C_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define Current_Sensor_I2C_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define Current_Sensor_I2C_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define Current_Sensor_I2C_REMOVE_SPI_SLAVE_PINS          (1u)
#define Current_Sensor_I2C_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define Current_Sensor_I2C_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define Current_Sensor_I2C_REMOVE_UART_TX_PIN             (1u)
#define Current_Sensor_I2C_REMOVE_UART_RX_TX_PIN          (1u)
#define Current_Sensor_I2C_REMOVE_UART_RX_PIN             (1u)
#define Current_Sensor_I2C_REMOVE_UART_RX_WAKE_PIN        (1u)
#define Current_Sensor_I2C_REMOVE_UART_RTS_PIN            (1u)
#define Current_Sensor_I2C_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_PIN (0u == Current_Sensor_I2C_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define Current_Sensor_I2C_RX_SCL_MOSI_PIN     (0u == Current_Sensor_I2C_REMOVE_RX_SCL_MOSI_PIN)
#define Current_Sensor_I2C_TX_SDA_MISO_PIN     (0u == Current_Sensor_I2C_REMOVE_TX_SDA_MISO_PIN)
#define Current_Sensor_I2C_CTS_SCLK_PIN     (0u == Current_Sensor_I2C_REMOVE_CTS_SCLK_PIN)
#define Current_Sensor_I2C_RTS_SS0_PIN     (0u == Current_Sensor_I2C_REMOVE_RTS_SS0_PIN)
#define Current_Sensor_I2C_SS1_PIN                (0u == Current_Sensor_I2C_REMOVE_SS1_PIN)
#define Current_Sensor_I2C_SS2_PIN                (0u == Current_Sensor_I2C_REMOVE_SS2_PIN)
#define Current_Sensor_I2C_SS3_PIN                (0u == Current_Sensor_I2C_REMOVE_SS3_PIN)

/* Mode defined pins */
#define Current_Sensor_I2C_I2C_PINS               (0u == Current_Sensor_I2C_REMOVE_I2C_PINS)
#define Current_Sensor_I2C_SPI_MASTER_PINS        (0u == Current_Sensor_I2C_REMOVE_SPI_MASTER_PINS)
#define Current_Sensor_I2C_SPI_MASTER_SCLK_PIN    (0u == Current_Sensor_I2C_REMOVE_SPI_MASTER_SCLK_PIN)
#define Current_Sensor_I2C_SPI_MASTER_MOSI_PIN    (0u == Current_Sensor_I2C_REMOVE_SPI_MASTER_MOSI_PIN)
#define Current_Sensor_I2C_SPI_MASTER_MISO_PIN    (0u == Current_Sensor_I2C_REMOVE_SPI_MASTER_MISO_PIN)
#define Current_Sensor_I2C_SPI_MASTER_SS0_PIN     (0u == Current_Sensor_I2C_REMOVE_SPI_MASTER_SS0_PIN)
#define Current_Sensor_I2C_SPI_MASTER_SS1_PIN     (0u == Current_Sensor_I2C_REMOVE_SPI_MASTER_SS1_PIN)
#define Current_Sensor_I2C_SPI_MASTER_SS2_PIN     (0u == Current_Sensor_I2C_REMOVE_SPI_MASTER_SS2_PIN)
#define Current_Sensor_I2C_SPI_MASTER_SS3_PIN     (0u == Current_Sensor_I2C_REMOVE_SPI_MASTER_SS3_PIN)
#define Current_Sensor_I2C_SPI_SLAVE_PINS         (0u == Current_Sensor_I2C_REMOVE_SPI_SLAVE_PINS)
#define Current_Sensor_I2C_SPI_SLAVE_MOSI_PIN     (0u == Current_Sensor_I2C_REMOVE_SPI_SLAVE_MOSI_PIN)
#define Current_Sensor_I2C_SPI_SLAVE_MISO_PIN     (0u == Current_Sensor_I2C_REMOVE_SPI_SLAVE_MISO_PIN)
#define Current_Sensor_I2C_UART_TX_PIN            (0u == Current_Sensor_I2C_REMOVE_UART_TX_PIN)
#define Current_Sensor_I2C_UART_RX_TX_PIN         (0u == Current_Sensor_I2C_REMOVE_UART_RX_TX_PIN)
#define Current_Sensor_I2C_UART_RX_PIN            (0u == Current_Sensor_I2C_REMOVE_UART_RX_PIN)
#define Current_Sensor_I2C_UART_RX_WAKE_PIN       (0u == Current_Sensor_I2C_REMOVE_UART_RX_WAKE_PIN)
#define Current_Sensor_I2C_UART_RTS_PIN           (0u == Current_Sensor_I2C_REMOVE_UART_RTS_PIN)
#define Current_Sensor_I2C_UART_CTS_PIN           (0u == Current_Sensor_I2C_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (Current_Sensor_I2C_RX_WAKE_SCL_MOSI_PIN)
    #include "Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (Current_Sensor_I2C_RX_SCL_MOSI) */

#if (Current_Sensor_I2C_RX_SCL_MOSI_PIN)
    #include "Current_Sensor_I2C_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (Current_Sensor_I2C_RX_SCL_MOSI) */

#if (Current_Sensor_I2C_TX_SDA_MISO_PIN)
    #include "Current_Sensor_I2C_uart_tx_i2c_sda_spi_miso.h"
#endif /* (Current_Sensor_I2C_TX_SDA_MISO) */

#if (Current_Sensor_I2C_CTS_SCLK_PIN)
    #include "Current_Sensor_I2C_uart_cts_spi_sclk.h"
#endif /* (Current_Sensor_I2C_CTS_SCLK) */

#if (Current_Sensor_I2C_RTS_SS0_PIN)
    #include "Current_Sensor_I2C_uart_rts_spi_ss0.h"
#endif /* (Current_Sensor_I2C_RTS_SS0_PIN) */

#if (Current_Sensor_I2C_SS1_PIN)
    #include "Current_Sensor_I2C_spi_ss1.h"
#endif /* (Current_Sensor_I2C_SS1_PIN) */

#if (Current_Sensor_I2C_SS2_PIN)
    #include "Current_Sensor_I2C_spi_ss2.h"
#endif /* (Current_Sensor_I2C_SS2_PIN) */

#if (Current_Sensor_I2C_SS3_PIN)
    #include "Current_Sensor_I2C_spi_ss3.h"
#endif /* (Current_Sensor_I2C_SS3_PIN) */

#if (Current_Sensor_I2C_I2C_PINS)
    #include "Current_Sensor_I2C_scl.h"
    #include "Current_Sensor_I2C_sda.h"
#endif /* (Current_Sensor_I2C_I2C_PINS) */

#if (Current_Sensor_I2C_SPI_MASTER_PINS)
#if (Current_Sensor_I2C_SPI_MASTER_SCLK_PIN)
    #include "Current_Sensor_I2C_sclk_m.h"
#endif /* (Current_Sensor_I2C_SPI_MASTER_SCLK_PIN) */

#if (Current_Sensor_I2C_SPI_MASTER_MOSI_PIN)
    #include "Current_Sensor_I2C_mosi_m.h"
#endif /* (Current_Sensor_I2C_SPI_MASTER_MOSI_PIN) */

#if (Current_Sensor_I2C_SPI_MASTER_MISO_PIN)
    #include "Current_Sensor_I2C_miso_m.h"
#endif /*(Current_Sensor_I2C_SPI_MASTER_MISO_PIN) */
#endif /* (Current_Sensor_I2C_SPI_MASTER_PINS) */

#if (Current_Sensor_I2C_SPI_SLAVE_PINS)
    #include "Current_Sensor_I2C_sclk_s.h"
    #include "Current_Sensor_I2C_ss_s.h"

#if (Current_Sensor_I2C_SPI_SLAVE_MOSI_PIN)
    #include "Current_Sensor_I2C_mosi_s.h"
#endif /* (Current_Sensor_I2C_SPI_SLAVE_MOSI_PIN) */

#if (Current_Sensor_I2C_SPI_SLAVE_MISO_PIN)
    #include "Current_Sensor_I2C_miso_s.h"
#endif /*(Current_Sensor_I2C_SPI_SLAVE_MISO_PIN) */
#endif /* (Current_Sensor_I2C_SPI_SLAVE_PINS) */

#if (Current_Sensor_I2C_SPI_MASTER_SS0_PIN)
    #include "Current_Sensor_I2C_ss0_m.h"
#endif /* (Current_Sensor_I2C_SPI_MASTER_SS0_PIN) */

#if (Current_Sensor_I2C_SPI_MASTER_SS1_PIN)
    #include "Current_Sensor_I2C_ss1_m.h"
#endif /* (Current_Sensor_I2C_SPI_MASTER_SS1_PIN) */

#if (Current_Sensor_I2C_SPI_MASTER_SS2_PIN)
    #include "Current_Sensor_I2C_ss2_m.h"
#endif /* (Current_Sensor_I2C_SPI_MASTER_SS2_PIN) */

#if (Current_Sensor_I2C_SPI_MASTER_SS3_PIN)
    #include "Current_Sensor_I2C_ss3_m.h"
#endif /* (Current_Sensor_I2C_SPI_MASTER_SS3_PIN) */

#if (Current_Sensor_I2C_UART_TX_PIN)
    #include "Current_Sensor_I2C_tx.h"
#endif /* (Current_Sensor_I2C_UART_TX_PIN) */

#if (Current_Sensor_I2C_UART_RX_TX_PIN)
    #include "Current_Sensor_I2C_rx_tx.h"
#endif /* (Current_Sensor_I2C_UART_RX_TX_PIN) */

#if (Current_Sensor_I2C_UART_RX_PIN)
    #include "Current_Sensor_I2C_rx.h"
#endif /* (Current_Sensor_I2C_UART_RX_PIN) */

#if (Current_Sensor_I2C_UART_RX_WAKE_PIN)
    #include "Current_Sensor_I2C_rx_wake.h"
#endif /* (Current_Sensor_I2C_UART_RX_WAKE_PIN) */

#if (Current_Sensor_I2C_UART_RTS_PIN)
    #include "Current_Sensor_I2C_rts.h"
#endif /* (Current_Sensor_I2C_UART_RTS_PIN) */

#if (Current_Sensor_I2C_UART_CTS_PIN)
    #include "Current_Sensor_I2C_cts.h"
#endif /* (Current_Sensor_I2C_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (Current_Sensor_I2C_RX_SCL_MOSI_PIN)
    #define Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    
    #define Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_MASK      (Current_Sensor_I2C_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_POS       (Current_Sensor_I2C_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_SEL_GPIO  (Current_Sensor_I2C_uart_rx_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_SEL_I2C   (Current_Sensor_I2C_uart_rx_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_SEL_SPI   (Current_Sensor_I2C_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_SEL_UART  (Current_Sensor_I2C_uart_rx_i2c_scl_spi_mosi__0__HSIOM_UART)
    
#elif (Current_Sensor_I2C_RX_WAKE_SCL_MOSI_PIN)
    #define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    
    #define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_MASK      (Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_POS       (Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_SEL_GPIO  (Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C   (Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI   (Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART  (Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_UART)    
   
    #define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_INTCFG_REG (*(reg32 *) Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_INTCFG_PTR ( (reg32 *) Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK ((uint32) Current_Sensor_I2C_INTCFG_TYPE_MASK << \
                                                                           Current_Sensor_I2C_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#else
    /* None of pins Current_Sensor_I2C_RX_SCL_MOSI_PIN or Current_Sensor_I2C_RX_WAKE_SCL_MOSI_PIN present.*/
#endif /* (Current_Sensor_I2C_RX_SCL_MOSI_PIN) */

#if (Current_Sensor_I2C_TX_SDA_MISO_PIN)
    #define Current_Sensor_I2C_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define Current_Sensor_I2C_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    
    #define Current_Sensor_I2C_TX_SDA_MISO_HSIOM_MASK      (Current_Sensor_I2C_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define Current_Sensor_I2C_TX_SDA_MISO_HSIOM_POS       (Current_Sensor_I2C_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_TX_SDA_MISO_HSIOM_SEL_GPIO  (Current_Sensor_I2C_uart_tx_i2c_sda_spi_miso__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_TX_SDA_MISO_HSIOM_SEL_I2C   (Current_Sensor_I2C_uart_tx_i2c_sda_spi_miso__0__HSIOM_I2C)
    #define Current_Sensor_I2C_TX_SDA_MISO_HSIOM_SEL_SPI   (Current_Sensor_I2C_uart_tx_i2c_sda_spi_miso__0__HSIOM_SPI)
    #define Current_Sensor_I2C_TX_SDA_MISO_HSIOM_SEL_UART  (Current_Sensor_I2C_uart_tx_i2c_sda_spi_miso__0__HSIOM_UART)
#endif /* (Current_Sensor_I2C_TX_SDA_MISO_PIN) */

#if (Current_Sensor_I2C_CTS_SCLK_PIN)
    #define Current_Sensor_I2C_CTS_SCLK_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_uart_cts_spi_sclk__0__HSIOM)
    #define Current_Sensor_I2C_CTS_SCLK_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_uart_cts_spi_sclk__0__HSIOM)
    
    #define Current_Sensor_I2C_CTS_SCLK_HSIOM_MASK      (Current_Sensor_I2C_uart_cts_spi_sclk__0__HSIOM_MASK)
    #define Current_Sensor_I2C_CTS_SCLK_HSIOM_POS       (Current_Sensor_I2C_uart_cts_spi_sclk__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_CTS_SCLK_HSIOM_SEL_GPIO  (Current_Sensor_I2C_uart_cts_spi_sclk__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_CTS_SCLK_HSIOM_SEL_I2C   (Current_Sensor_I2C_uart_cts_spi_sclk__0__HSIOM_I2C)
    #define Current_Sensor_I2C_CTS_SCLK_HSIOM_SEL_SPI   (Current_Sensor_I2C_uart_cts_spi_sclk__0__HSIOM_SPI)
    #define Current_Sensor_I2C_CTS_SCLK_HSIOM_SEL_UART  (Current_Sensor_I2C_uart_cts_spi_sclk__0__HSIOM_UART)
#endif /* (Current_Sensor_I2C_CTS_SCLK_PIN) */

#if (Current_Sensor_I2C_RTS_SS0_PIN)
    #define Current_Sensor_I2C_RTS_SS0_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_uart_rts_spi_ss0__0__HSIOM)
    #define Current_Sensor_I2C_RTS_SS0_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_uart_rts_spi_ss0__0__HSIOM)
    
    #define Current_Sensor_I2C_RTS_SS0_HSIOM_MASK      (Current_Sensor_I2C_uart_rts_spi_ss0__0__HSIOM_MASK)
    #define Current_Sensor_I2C_RTS_SS0_HSIOM_POS       (Current_Sensor_I2C_uart_rts_spi_ss0__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_RTS_SS0_HSIOM_SEL_GPIO  (Current_Sensor_I2C_uart_rts_spi_ss0__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_RTS_SS0_HSIOM_SEL_I2C   (Current_Sensor_I2C_uart_rts_spi_ss0__0__HSIOM_I2C)
    #define Current_Sensor_I2C_RTS_SS0_HSIOM_SEL_SPI   (Current_Sensor_I2C_uart_rts_spi_ss0__0__HSIOM_SPI)
#if !(Current_Sensor_I2C_CY_SCBIP_V0 || Current_Sensor_I2C_CY_SCBIP_V1)
    #define Current_Sensor_I2C_RTS_SS0_HSIOM_SEL_UART  (Current_Sensor_I2C_uart_rts_spi_ss0__0__HSIOM_UART)
#endif /* !(Current_Sensor_I2C_CY_SCBIP_V0 || Current_Sensor_I2C_CY_SCBIP_V1) */
#endif /* (Current_Sensor_I2C_RTS_SS0_PIN) */

#if (Current_Sensor_I2C_SS1_PIN)
    #define Current_Sensor_I2C_SS1_HSIOM_REG  (*(reg32 *) Current_Sensor_I2C_spi_ss1__0__HSIOM)
    #define Current_Sensor_I2C_SS1_HSIOM_PTR  ( (reg32 *) Current_Sensor_I2C_spi_ss1__0__HSIOM)
    
    #define Current_Sensor_I2C_SS1_HSIOM_MASK     (Current_Sensor_I2C_spi_ss1__0__HSIOM_MASK)
    #define Current_Sensor_I2C_SS1_HSIOM_POS      (Current_Sensor_I2C_spi_ss1__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_SS1_HSIOM_SEL_GPIO (Current_Sensor_I2C_spi_ss1__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_SS1_HSIOM_SEL_I2C  (Current_Sensor_I2C_spi_ss1__0__HSIOM_I2C)
    #define Current_Sensor_I2C_SS1_HSIOM_SEL_SPI  (Current_Sensor_I2C_spi_ss1__0__HSIOM_SPI)
#endif /* (Current_Sensor_I2C_SS1_PIN) */

#if (Current_Sensor_I2C_SS2_PIN)
    #define Current_Sensor_I2C_SS2_HSIOM_REG     (*(reg32 *) Current_Sensor_I2C_spi_ss2__0__HSIOM)
    #define Current_Sensor_I2C_SS2_HSIOM_PTR     ( (reg32 *) Current_Sensor_I2C_spi_ss2__0__HSIOM)
    
    #define Current_Sensor_I2C_SS2_HSIOM_MASK     (Current_Sensor_I2C_spi_ss2__0__HSIOM_MASK)
    #define Current_Sensor_I2C_SS2_HSIOM_POS      (Current_Sensor_I2C_spi_ss2__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_SS2_HSIOM_SEL_GPIO (Current_Sensor_I2C_spi_ss2__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_SS2_HSIOM_SEL_I2C  (Current_Sensor_I2C_spi_ss2__0__HSIOM_I2C)
    #define Current_Sensor_I2C_SS2_HSIOM_SEL_SPI  (Current_Sensor_I2C_spi_ss2__0__HSIOM_SPI)
#endif /* (Current_Sensor_I2C_SS2_PIN) */

#if (Current_Sensor_I2C_SS3_PIN)
    #define Current_Sensor_I2C_SS3_HSIOM_REG     (*(reg32 *) Current_Sensor_I2C_spi_ss3__0__HSIOM)
    #define Current_Sensor_I2C_SS3_HSIOM_PTR     ( (reg32 *) Current_Sensor_I2C_spi_ss3__0__HSIOM)
    
    #define Current_Sensor_I2C_SS3_HSIOM_MASK     (Current_Sensor_I2C_spi_ss3__0__HSIOM_MASK)
    #define Current_Sensor_I2C_SS3_HSIOM_POS      (Current_Sensor_I2C_spi_ss3__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_SS3_HSIOM_SEL_GPIO (Current_Sensor_I2C_spi_ss3__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_SS3_HSIOM_SEL_I2C  (Current_Sensor_I2C_spi_ss3__0__HSIOM_I2C)
    #define Current_Sensor_I2C_SS3_HSIOM_SEL_SPI  (Current_Sensor_I2C_spi_ss3__0__HSIOM_SPI)
#endif /* (Current_Sensor_I2C_SS3_PIN) */

#if (Current_Sensor_I2C_I2C_PINS)
    #define Current_Sensor_I2C_SCL_HSIOM_REG  (*(reg32 *) Current_Sensor_I2C_scl__0__HSIOM)
    #define Current_Sensor_I2C_SCL_HSIOM_PTR  ( (reg32 *) Current_Sensor_I2C_scl__0__HSIOM)
    
    #define Current_Sensor_I2C_SCL_HSIOM_MASK     (Current_Sensor_I2C_scl__0__HSIOM_MASK)
    #define Current_Sensor_I2C_SCL_HSIOM_POS      (Current_Sensor_I2C_scl__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_SCL_HSIOM_SEL_GPIO (Current_Sensor_I2C_sda__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_SCL_HSIOM_SEL_I2C  (Current_Sensor_I2C_sda__0__HSIOM_I2C)
    
    #define Current_Sensor_I2C_SDA_HSIOM_REG  (*(reg32 *) Current_Sensor_I2C_sda__0__HSIOM)
    #define Current_Sensor_I2C_SDA_HSIOM_PTR  ( (reg32 *) Current_Sensor_I2C_sda__0__HSIOM)
    
    #define Current_Sensor_I2C_SDA_HSIOM_MASK     (Current_Sensor_I2C_sda__0__HSIOM_MASK)
    #define Current_Sensor_I2C_SDA_HSIOM_POS      (Current_Sensor_I2C_sda__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_SDA_HSIOM_SEL_GPIO (Current_Sensor_I2C_sda__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_SDA_HSIOM_SEL_I2C  (Current_Sensor_I2C_sda__0__HSIOM_I2C)
#endif /* (Current_Sensor_I2C_I2C_PINS) */

#if (Current_Sensor_I2C_SPI_SLAVE_PINS)
    #define Current_Sensor_I2C_SCLK_S_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_sclk_s__0__HSIOM)
    #define Current_Sensor_I2C_SCLK_S_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_sclk_s__0__HSIOM)
    
    #define Current_Sensor_I2C_SCLK_S_HSIOM_MASK      (Current_Sensor_I2C_sclk_s__0__HSIOM_MASK)
    #define Current_Sensor_I2C_SCLK_S_HSIOM_POS       (Current_Sensor_I2C_sclk_s__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_SCLK_S_HSIOM_SEL_GPIO  (Current_Sensor_I2C_sclk_s__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_SCLK_S_HSIOM_SEL_SPI   (Current_Sensor_I2C_sclk_s__0__HSIOM_SPI)
    
    #define Current_Sensor_I2C_SS0_S_HSIOM_REG    (*(reg32 *) Current_Sensor_I2C_ss0_s__0__HSIOM)
    #define Current_Sensor_I2C_SS0_S_HSIOM_PTR    ( (reg32 *) Current_Sensor_I2C_ss0_s__0__HSIOM)
    
    #define Current_Sensor_I2C_SS0_S_HSIOM_MASK       (Current_Sensor_I2C_ss0_s__0__HSIOM_MASK)
    #define Current_Sensor_I2C_SS0_S_HSIOM_POS        (Current_Sensor_I2C_ss0_s__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_SS0_S_HSIOM_SEL_GPIO   (Current_Sensor_I2C_ss0_s__0__HSIOM_GPIO)  
    #define Current_Sensor_I2C_SS0_S_HSIOM_SEL_SPI    (Current_Sensor_I2C_ss0_s__0__HSIOM_SPI)
#endif /* (Current_Sensor_I2C_SPI_SLAVE_PINS) */

#if (Current_Sensor_I2C_SPI_SLAVE_MOSI_PIN)
    #define Current_Sensor_I2C_MOSI_S_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_mosi_s__0__HSIOM)
    #define Current_Sensor_I2C_MOSI_S_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_mosi_s__0__HSIOM)
    
    #define Current_Sensor_I2C_MOSI_S_HSIOM_MASK      (Current_Sensor_I2C_mosi_s__0__HSIOM_MASK)
    #define Current_Sensor_I2C_MOSI_S_HSIOM_POS       (Current_Sensor_I2C_mosi_s__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_MOSI_S_HSIOM_SEL_GPIO  (Current_Sensor_I2C_mosi_s__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_MOSI_S_HSIOM_SEL_SPI   (Current_Sensor_I2C_mosi_s__0__HSIOM_SPI)
#endif /* (Current_Sensor_I2C_SPI_SLAVE_MOSI_PIN) */

#if (Current_Sensor_I2C_SPI_SLAVE_MISO_PIN)
    #define Current_Sensor_I2C_MISO_S_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_miso_s__0__HSIOM)
    #define Current_Sensor_I2C_MISO_S_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_miso_s__0__HSIOM)
    
    #define Current_Sensor_I2C_MISO_S_HSIOM_MASK      (Current_Sensor_I2C_miso_s__0__HSIOM_MASK)
    #define Current_Sensor_I2C_MISO_S_HSIOM_POS       (Current_Sensor_I2C_miso_s__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_MISO_S_HSIOM_SEL_GPIO  (Current_Sensor_I2C_miso_s__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_MISO_S_HSIOM_SEL_SPI   (Current_Sensor_I2C_miso_s__0__HSIOM_SPI)
#endif /* (Current_Sensor_I2C_SPI_SLAVE_MISO_PIN) */

#if (Current_Sensor_I2C_SPI_MASTER_MISO_PIN)
    #define Current_Sensor_I2C_MISO_M_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_miso_m__0__HSIOM)
    #define Current_Sensor_I2C_MISO_M_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_miso_m__0__HSIOM)
    
    #define Current_Sensor_I2C_MISO_M_HSIOM_MASK      (Current_Sensor_I2C_miso_m__0__HSIOM_MASK)
    #define Current_Sensor_I2C_MISO_M_HSIOM_POS       (Current_Sensor_I2C_miso_m__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_MISO_M_HSIOM_SEL_GPIO  (Current_Sensor_I2C_miso_m__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_MISO_M_HSIOM_SEL_SPI   (Current_Sensor_I2C_miso_m__0__HSIOM_SPI)
#endif /* (Current_Sensor_I2C_SPI_MASTER_MISO_PIN) */

#if (Current_Sensor_I2C_SPI_MASTER_MOSI_PIN)
    #define Current_Sensor_I2C_MOSI_M_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_mosi_m__0__HSIOM)
    #define Current_Sensor_I2C_MOSI_M_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_mosi_m__0__HSIOM)
    
    #define Current_Sensor_I2C_MOSI_M_HSIOM_MASK      (Current_Sensor_I2C_mosi_m__0__HSIOM_MASK)
    #define Current_Sensor_I2C_MOSI_M_HSIOM_POS       (Current_Sensor_I2C_mosi_m__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_MOSI_M_HSIOM_SEL_GPIO  (Current_Sensor_I2C_mosi_m__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_MOSI_M_HSIOM_SEL_SPI   (Current_Sensor_I2C_mosi_m__0__HSIOM_SPI)
#endif /* (Current_Sensor_I2C_SPI_MASTER_MOSI_PIN) */

#if (Current_Sensor_I2C_SPI_MASTER_SCLK_PIN)
    #define Current_Sensor_I2C_SCLK_M_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_sclk_m__0__HSIOM)
    #define Current_Sensor_I2C_SCLK_M_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_sclk_m__0__HSIOM)
    
    #define Current_Sensor_I2C_SCLK_M_HSIOM_MASK      (Current_Sensor_I2C_sclk_m__0__HSIOM_MASK)
    #define Current_Sensor_I2C_SCLK_M_HSIOM_POS       (Current_Sensor_I2C_sclk_m__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_SCLK_M_HSIOM_SEL_GPIO  (Current_Sensor_I2C_sclk_m__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_SCLK_M_HSIOM_SEL_SPI   (Current_Sensor_I2C_sclk_m__0__HSIOM_SPI)
#endif /* (Current_Sensor_I2C_SPI_MASTER_SCLK_PIN) */

#if (Current_Sensor_I2C_SPI_MASTER_SS0_PIN)
    #define Current_Sensor_I2C_SS0_M_HSIOM_REG    (*(reg32 *) Current_Sensor_I2C_ss0_m__0__HSIOM)
    #define Current_Sensor_I2C_SS0_M_HSIOM_PTR    ( (reg32 *) Current_Sensor_I2C_ss0_m__0__HSIOM)
    
    #define Current_Sensor_I2C_SS0_M_HSIOM_MASK       (Current_Sensor_I2C_ss0_m__0__HSIOM_MASK)
    #define Current_Sensor_I2C_SS0_M_HSIOM_POS        (Current_Sensor_I2C_ss0_m__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_SS0_M_HSIOM_SEL_GPIO   (Current_Sensor_I2C_ss0_m__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_SS0_M_HSIOM_SEL_SPI    (Current_Sensor_I2C_ss0_m__0__HSIOM_SPI)
#endif /* (Current_Sensor_I2C_SPI_MASTER_SS0_PIN) */

#if (Current_Sensor_I2C_SPI_MASTER_SS1_PIN)
    #define Current_Sensor_I2C_SS1_M_HSIOM_REG    (*(reg32 *) Current_Sensor_I2C_ss1_m__0__HSIOM)
    #define Current_Sensor_I2C_SS1_M_HSIOM_PTR    ( (reg32 *) Current_Sensor_I2C_ss1_m__0__HSIOM)
    
    #define Current_Sensor_I2C_SS1_M_HSIOM_MASK       (Current_Sensor_I2C_ss1_m__0__HSIOM_MASK)
    #define Current_Sensor_I2C_SS1_M_HSIOM_POS        (Current_Sensor_I2C_ss1_m__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_SS1_M_HSIOM_SEL_GPIO   (Current_Sensor_I2C_ss1_m__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_SS1_M_HSIOM_SEL_SPI    (Current_Sensor_I2C_ss1_m__0__HSIOM_SPI)
#endif /* (Current_Sensor_I2C_SPI_MASTER_SS1_PIN) */

#if (Current_Sensor_I2C_SPI_MASTER_SS2_PIN)
    #define Current_Sensor_I2C_SS2_M_HSIOM_REG    (*(reg32 *) Current_Sensor_I2C_ss2_m__0__HSIOM)
    #define Current_Sensor_I2C_SS2_M_HSIOM_PTR    ( (reg32 *) Current_Sensor_I2C_ss2_m__0__HSIOM)
    
    #define Current_Sensor_I2C_SS2_M_HSIOM_MASK       (Current_Sensor_I2C_ss2_m__0__HSIOM_MASK)
    #define Current_Sensor_I2C_SS2_M_HSIOM_POS        (Current_Sensor_I2C_ss2_m__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_SS2_M_HSIOM_SEL_GPIO   (Current_Sensor_I2C_ss2_m__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_SS2_M_HSIOM_SEL_SPI    (Current_Sensor_I2C_ss2_m__0__HSIOM_SPI)
#endif /* (Current_Sensor_I2C_SPI_MASTER_SS2_PIN) */

#if (Current_Sensor_I2C_SPI_MASTER_SS3_PIN)
    #define Current_Sensor_I2C_SS3_M_HSIOM_REG    (*(reg32 *) Current_Sensor_I2C_ss3_m__0__HSIOM)
    #define Current_Sensor_I2C_SS3_M_HSIOM_PTR    ( (reg32 *) Current_Sensor_I2C_ss3_m__0__HSIOM)
    
    #define Current_Sensor_I2C_SS3_M_HSIOM_MASK      (Current_Sensor_I2C_ss3_m__0__HSIOM_MASK)
    #define Current_Sensor_I2C_SS3_M_HSIOM_POS       (Current_Sensor_I2C_ss3_m__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_SS3_M_HSIOM_SEL_GPIO  (Current_Sensor_I2C_ss3_m__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_SS3_M_HSIOM_SEL_SPI   (Current_Sensor_I2C_ss3_m__0__HSIOM_SPI)
#endif /* (Current_Sensor_I2C_SPI_MASTER_SS3_PIN) */

#if (Current_Sensor_I2C_UART_RX_PIN)
    #define Current_Sensor_I2C_RX_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_rx__0__HSIOM)
    #define Current_Sensor_I2C_RX_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_rx__0__HSIOM)
    
    #define Current_Sensor_I2C_RX_HSIOM_MASK      (Current_Sensor_I2C_rx__0__HSIOM_MASK)
    #define Current_Sensor_I2C_RX_HSIOM_POS       (Current_Sensor_I2C_rx__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_RX_HSIOM_SEL_GPIO  (Current_Sensor_I2C_rx__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_RX_HSIOM_SEL_UART  (Current_Sensor_I2C_rx__0__HSIOM_UART)
#endif /* (Current_Sensor_I2C_UART_RX_PIN) */

#if (Current_Sensor_I2C_UART_RX_WAKE_PIN)
    #define Current_Sensor_I2C_RX_WAKE_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_rx_wake__0__HSIOM)
    #define Current_Sensor_I2C_RX_WAKE_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_rx_wake__0__HSIOM)
    
    #define Current_Sensor_I2C_RX_WAKE_HSIOM_MASK      (Current_Sensor_I2C_rx_wake__0__HSIOM_MASK)
    #define Current_Sensor_I2C_RX_WAKE_HSIOM_POS       (Current_Sensor_I2C_rx_wake__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_RX_WAKE_HSIOM_SEL_GPIO  (Current_Sensor_I2C_rx_wake__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_RX_WAKE_HSIOM_SEL_UART  (Current_Sensor_I2C_rx_wake__0__HSIOM_UART)
#endif /* (Current_Sensor_I2C_UART_WAKE_RX_PIN) */

#if (Current_Sensor_I2C_UART_CTS_PIN)
    #define Current_Sensor_I2C_CTS_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_cts__0__HSIOM)
    #define Current_Sensor_I2C_CTS_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_cts__0__HSIOM)
    
    #define Current_Sensor_I2C_CTS_HSIOM_MASK      (Current_Sensor_I2C_cts__0__HSIOM_MASK)
    #define Current_Sensor_I2C_CTS_HSIOM_POS       (Current_Sensor_I2C_cts__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_CTS_HSIOM_SEL_GPIO  (Current_Sensor_I2C_cts__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_CTS_HSIOM_SEL_UART  (Current_Sensor_I2C_cts__0__HSIOM_UART)
#endif /* (Current_Sensor_I2C_UART_CTS_PIN) */

#if (Current_Sensor_I2C_UART_TX_PIN)
    #define Current_Sensor_I2C_TX_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_tx__0__HSIOM)
    #define Current_Sensor_I2C_TX_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_tx__0__HSIOM)
    
    #define Current_Sensor_I2C_TX_HSIOM_MASK      (Current_Sensor_I2C_tx__0__HSIOM_MASK)
    #define Current_Sensor_I2C_TX_HSIOM_POS       (Current_Sensor_I2C_tx__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_TX_HSIOM_SEL_GPIO  (Current_Sensor_I2C_tx__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_TX_HSIOM_SEL_UART  (Current_Sensor_I2C_tx__0__HSIOM_UART)
#endif /* (Current_Sensor_I2C_UART_TX_PIN) */

#if (Current_Sensor_I2C_UART_RX_TX_PIN)
    #define Current_Sensor_I2C_RX_TX_HSIOM_REG   (*(reg32 *) Current_Sensor_I2C_rx_tx__0__HSIOM)
    #define Current_Sensor_I2C_RX_TX_HSIOM_PTR   ( (reg32 *) Current_Sensor_I2C_rx_tx__0__HSIOM)
    
    #define Current_Sensor_I2C_RX_TX_HSIOM_MASK      (Current_Sensor_I2C_rx_tx__0__HSIOM_MASK)
    #define Current_Sensor_I2C_RX_TX_HSIOM_POS       (Current_Sensor_I2C_rx_tx__0__HSIOM_SHIFT)
    #define Current_Sensor_I2C_RX_TX_HSIOM_SEL_GPIO  (Current_Sensor_I2C_rx_tx__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_RX_TX_HSIOM_SEL_UART  (Current_Sensor_I2C_rx_tx__0__HSIOM_UART)
#endif /* (Current_Sensor_I2C_UART_RX_TX_PIN) */

#if (Current_Sensor_I2C_UART_RTS_PIN)
    #define Current_Sensor_I2C_RTS_HSIOM_REG      (*(reg32 *) Current_Sensor_I2C_rts__0__HSIOM)
    #define Current_Sensor_I2C_RTS_HSIOM_PTR      ( (reg32 *) Current_Sensor_I2C_rts__0__HSIOM)
    
    #define Current_Sensor_I2C_RTS_HSIOM_MASK     (Current_Sensor_I2C_rts__0__HSIOM_MASK)
    #define Current_Sensor_I2C_RTS_HSIOM_POS      (Current_Sensor_I2C_rts__0__HSIOM_SHIFT)    
    #define Current_Sensor_I2C_RTS_HSIOM_SEL_GPIO (Current_Sensor_I2C_rts__0__HSIOM_GPIO)
    #define Current_Sensor_I2C_RTS_HSIOM_SEL_UART (Current_Sensor_I2C_rts__0__HSIOM_UART)    
#endif /* (Current_Sensor_I2C_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* HSIOM switch values. */ 
#define Current_Sensor_I2C_HSIOM_DEF_SEL      (0x00u)
#define Current_Sensor_I2C_HSIOM_GPIO_SEL     (0x00u)
/* The HSIOM values provided below are valid only for Current_Sensor_I2C_CY_SCBIP_V0 
* and Current_Sensor_I2C_CY_SCBIP_V1. It is not recommended to use them for 
* Current_Sensor_I2C_CY_SCBIP_V2. Use pin name specific HSIOM constants provided 
* above instead for any SCB IP block version.
*/
#define Current_Sensor_I2C_HSIOM_UART_SEL     (0x09u)
#define Current_Sensor_I2C_HSIOM_I2C_SEL      (0x0Eu)
#define Current_Sensor_I2C_HSIOM_SPI_SEL      (0x0Fu)

/* Pins settings index. */
#define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define Current_Sensor_I2C_RX_SCL_MOSI_PIN_INDEX       (0u)
#define Current_Sensor_I2C_TX_SDA_MISO_PIN_INDEX       (1u)
#define Current_Sensor_I2C_CTS_SCLK_PIN_INDEX       (2u)
#define Current_Sensor_I2C_RTS_SS0_PIN_INDEX       (3u)
#define Current_Sensor_I2C_SS1_PIN_INDEX                  (4u)
#define Current_Sensor_I2C_SS2_PIN_INDEX                  (5u)
#define Current_Sensor_I2C_SS3_PIN_INDEX                  (6u)

/* Pins settings mask. */
#define Current_Sensor_I2C_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << Current_Sensor_I2C_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define Current_Sensor_I2C_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << Current_Sensor_I2C_RX_SCL_MOSI_PIN_INDEX)
#define Current_Sensor_I2C_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << Current_Sensor_I2C_TX_SDA_MISO_PIN_INDEX)
#define Current_Sensor_I2C_CTS_SCLK_PIN_MASK     ((uint32) 0x01u << Current_Sensor_I2C_CTS_SCLK_PIN_INDEX)
#define Current_Sensor_I2C_RTS_SS0_PIN_MASK     ((uint32) 0x01u << Current_Sensor_I2C_RTS_SS0_PIN_INDEX)
#define Current_Sensor_I2C_SS1_PIN_MASK                ((uint32) 0x01u << Current_Sensor_I2C_SS1_PIN_INDEX)
#define Current_Sensor_I2C_SS2_PIN_MASK                ((uint32) 0x01u << Current_Sensor_I2C_SS2_PIN_INDEX)
#define Current_Sensor_I2C_SS3_PIN_MASK                ((uint32) 0x01u << Current_Sensor_I2C_SS3_PIN_INDEX)

/* Pin interrupt constants. */
#define Current_Sensor_I2C_INTCFG_TYPE_MASK           (0x03u)
#define Current_Sensor_I2C_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants. */
#define Current_Sensor_I2C_PIN_DM_ALG_HIZ  (0u)
#define Current_Sensor_I2C_PIN_DM_DIG_HIZ  (1u)
#define Current_Sensor_I2C_PIN_DM_OD_LO    (4u)
#define Current_Sensor_I2C_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define Current_Sensor_I2C_DM_MASK    (0x7u)
#define Current_Sensor_I2C_DM_SIZE    (3u)
#define Current_Sensor_I2C_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) Current_Sensor_I2C_DM_MASK << (Current_Sensor_I2C_DM_SIZE * (pos)))) >> \
                                                              (Current_Sensor_I2C_DM_SIZE * (pos)) )

#if (Current_Sensor_I2C_TX_SDA_MISO_PIN)
    #define Current_Sensor_I2C_CHECK_TX_SDA_MISO_PIN_USED \
                (Current_Sensor_I2C_PIN_DM_ALG_HIZ != \
                    Current_Sensor_I2C_GET_P4_PIN_DM(Current_Sensor_I2C_uart_tx_i2c_sda_spi_miso_PC, \
                                                   Current_Sensor_I2C_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (Current_Sensor_I2C_TX_SDA_MISO_PIN) */

#if (Current_Sensor_I2C_RTS_SS0_PIN)
    #define Current_Sensor_I2C_CHECK_RTS_SS0_PIN_USED \
                (Current_Sensor_I2C_PIN_DM_ALG_HIZ != \
                    Current_Sensor_I2C_GET_P4_PIN_DM(Current_Sensor_I2C_uart_rts_spi_ss0_PC, \
                                                   Current_Sensor_I2C_uart_rts_spi_ss0_SHIFT))
#endif /* (Current_Sensor_I2C_RTS_SS0_PIN) */

/* Set bits-mask in register */
#define Current_Sensor_I2C_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define Current_Sensor_I2C_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define Current_Sensor_I2C_SET_HSIOM_SEL(reg, mask, pos, sel) Current_Sensor_I2C_SET_REGISTER_BITS(reg, mask, pos, sel)
#define Current_Sensor_I2C_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        Current_Sensor_I2C_SET_REGISTER_BITS(reg, mask, pos, intType)
#define Current_Sensor_I2C_SET_INP_DIS(reg, mask, val) Current_Sensor_I2C_SET_REGISTER_BIT(reg, mask, val)

/* Current_Sensor_I2C_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  Current_Sensor_I2C_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (Current_Sensor_I2C_CY_SCBIP_V0)
#if (Current_Sensor_I2C_I2C_PINS)
    #define Current_Sensor_I2C_SET_I2C_SCL_DR(val) Current_Sensor_I2C_scl_Write(val)

    #define Current_Sensor_I2C_SET_I2C_SCL_HSIOM_SEL(sel) \
                          Current_Sensor_I2C_SET_HSIOM_SEL(Current_Sensor_I2C_SCL_HSIOM_REG,  \
                                                         Current_Sensor_I2C_SCL_HSIOM_MASK, \
                                                         Current_Sensor_I2C_SCL_HSIOM_POS,  \
                                                         (sel))
    #define Current_Sensor_I2C_WAIT_SCL_SET_HIGH  (0u == Current_Sensor_I2C_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (Current_Sensor_I2C_RX_WAKE_SCL_MOSI_PIN)
    #define Current_Sensor_I2C_SET_I2C_SCL_DR(val) \
                            Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define Current_Sensor_I2C_SET_I2C_SCL_HSIOM_SEL(sel) \
                    Current_Sensor_I2C_SET_HSIOM_SEL(Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define Current_Sensor_I2C_WAIT_SCL_SET_HIGH  (0u == Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (Current_Sensor_I2C_RX_SCL_MOSI_PIN)
    #define Current_Sensor_I2C_SET_I2C_SCL_DR(val) \
                            Current_Sensor_I2C_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define Current_Sensor_I2C_SET_I2C_SCL_HSIOM_SEL(sel) \
                            Current_Sensor_I2C_SET_HSIOM_SEL(Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_REG,  \
                                                           Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_MASK, \
                                                           Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define Current_Sensor_I2C_WAIT_SCL_SET_HIGH  (0u == Current_Sensor_I2C_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define Current_Sensor_I2C_SET_I2C_SCL_DR(val)        do{ /* Does nothing */ }while(0)
    #define Current_Sensor_I2C_SET_I2C_SCL_HSIOM_SEL(sel) do{ /* Does nothing */ }while(0)

    #define Current_Sensor_I2C_WAIT_SCL_SET_HIGH  (0u)
#endif /* (Current_Sensor_I2C_I2C_PINS) */

/* SCB I2C: sda signal */
#if (Current_Sensor_I2C_I2C_PINS)
    #define Current_Sensor_I2C_WAIT_SDA_SET_HIGH  (0u == Current_Sensor_I2C_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (Current_Sensor_I2C_TX_SDA_MISO_PIN)
    #define Current_Sensor_I2C_WAIT_SDA_SET_HIGH  (0u == Current_Sensor_I2C_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define Current_Sensor_I2C_WAIT_SDA_SET_HIGH  (0u)
#endif /* (Current_Sensor_I2C_MOSI_SCL_RX_PIN) */
#endif /* (Current_Sensor_I2C_CY_SCBIP_V0) */

/* Clear UART wakeup source */
#if (Current_Sensor_I2C_RX_SCL_MOSI_PIN)
    #define Current_Sensor_I2C_CLEAR_UART_RX_WAKE_INTR        do{ /* Does nothing */ }while(0)
    
#elif (Current_Sensor_I2C_RX_WAKE_SCL_MOSI_PIN)
    #define Current_Sensor_I2C_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) Current_Sensor_I2C_uart_rx_wake_i2c_scl_spi_mosi_ClearInterrupt(); \
            }while(0)

#elif(Current_Sensor_I2C_UART_RX_WAKE_PIN)
    #define Current_Sensor_I2C_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) Current_Sensor_I2C_rx_wake_ClearInterrupt(); \
            }while(0)
#else
#endif /* (Current_Sensor_I2C_RX_SCL_MOSI_PIN) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define Current_Sensor_I2C_REMOVE_MOSI_SCL_RX_WAKE_PIN    Current_Sensor_I2C_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define Current_Sensor_I2C_REMOVE_MOSI_SCL_RX_PIN         Current_Sensor_I2C_REMOVE_RX_SCL_MOSI_PIN
#define Current_Sensor_I2C_REMOVE_MISO_SDA_TX_PIN         Current_Sensor_I2C_REMOVE_TX_SDA_MISO_PIN
#ifndef Current_Sensor_I2C_REMOVE_SCLK_PIN
#define Current_Sensor_I2C_REMOVE_SCLK_PIN                Current_Sensor_I2C_REMOVE_CTS_SCLK_PIN
#endif /* Current_Sensor_I2C_REMOVE_SCLK_PIN */
#ifndef Current_Sensor_I2C_REMOVE_SS0_PIN
#define Current_Sensor_I2C_REMOVE_SS0_PIN                 Current_Sensor_I2C_REMOVE_RTS_SS0_PIN
#endif /* Current_Sensor_I2C_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define Current_Sensor_I2C_MOSI_SCL_RX_WAKE_PIN   Current_Sensor_I2C_RX_WAKE_SCL_MOSI_PIN
#define Current_Sensor_I2C_MOSI_SCL_RX_PIN        Current_Sensor_I2C_RX_SCL_MOSI_PIN
#define Current_Sensor_I2C_MISO_SDA_TX_PIN        Current_Sensor_I2C_TX_SDA_MISO_PIN
#ifndef Current_Sensor_I2C_SCLK_PIN
#define Current_Sensor_I2C_SCLK_PIN               Current_Sensor_I2C_CTS_SCLK_PIN
#endif /* Current_Sensor_I2C_SCLK_PIN */
#ifndef Current_Sensor_I2C_SS0_PIN
#define Current_Sensor_I2C_SS0_PIN                Current_Sensor_I2C_RTS_SS0_PIN
#endif /* Current_Sensor_I2C_SS0_PIN */

#if (Current_Sensor_I2C_MOSI_SCL_RX_WAKE_PIN)
    #define Current_Sensor_I2C_MOSI_SCL_RX_WAKE_HSIOM_REG     Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define Current_Sensor_I2C_MOSI_SCL_RX_WAKE_HSIOM_PTR     Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define Current_Sensor_I2C_MOSI_SCL_RX_WAKE_HSIOM_MASK    Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define Current_Sensor_I2C_MOSI_SCL_RX_WAKE_HSIOM_POS     Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define Current_Sensor_I2C_MOSI_SCL_RX_WAKE_INTCFG_REG    Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define Current_Sensor_I2C_MOSI_SCL_RX_WAKE_INTCFG_PTR    Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define Current_Sensor_I2C_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define Current_Sensor_I2C_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  Current_Sensor_I2C_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (Current_Sensor_I2C_RX_WAKE_SCL_MOSI_PIN) */

#if (Current_Sensor_I2C_MOSI_SCL_RX_PIN)
    #define Current_Sensor_I2C_MOSI_SCL_RX_HSIOM_REG      Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_REG
    #define Current_Sensor_I2C_MOSI_SCL_RX_HSIOM_PTR      Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_PTR
    #define Current_Sensor_I2C_MOSI_SCL_RX_HSIOM_MASK     Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_MASK
    #define Current_Sensor_I2C_MOSI_SCL_RX_HSIOM_POS      Current_Sensor_I2C_RX_SCL_MOSI_HSIOM_POS
#endif /* (Current_Sensor_I2C_MOSI_SCL_RX_PIN) */

#if (Current_Sensor_I2C_MISO_SDA_TX_PIN)
    #define Current_Sensor_I2C_MISO_SDA_TX_HSIOM_REG      Current_Sensor_I2C_TX_SDA_MISO_HSIOM_REG
    #define Current_Sensor_I2C_MISO_SDA_TX_HSIOM_PTR      Current_Sensor_I2C_TX_SDA_MISO_HSIOM_REG
    #define Current_Sensor_I2C_MISO_SDA_TX_HSIOM_MASK     Current_Sensor_I2C_TX_SDA_MISO_HSIOM_REG
    #define Current_Sensor_I2C_MISO_SDA_TX_HSIOM_POS      Current_Sensor_I2C_TX_SDA_MISO_HSIOM_REG
#endif /* (Current_Sensor_I2C_MISO_SDA_TX_PIN_PIN) */

#if (Current_Sensor_I2C_SCLK_PIN)
    #ifndef Current_Sensor_I2C_SCLK_HSIOM_REG
    #define Current_Sensor_I2C_SCLK_HSIOM_REG     Current_Sensor_I2C_CTS_SCLK_HSIOM_REG
    #define Current_Sensor_I2C_SCLK_HSIOM_PTR     Current_Sensor_I2C_CTS_SCLK_HSIOM_PTR
    #define Current_Sensor_I2C_SCLK_HSIOM_MASK    Current_Sensor_I2C_CTS_SCLK_HSIOM_MASK
    #define Current_Sensor_I2C_SCLK_HSIOM_POS     Current_Sensor_I2C_CTS_SCLK_HSIOM_POS
    #endif /* Current_Sensor_I2C_SCLK_HSIOM_REG */
#endif /* (Current_Sensor_I2C_SCLK_PIN) */

#if (Current_Sensor_I2C_SS0_PIN)
    #ifndef Current_Sensor_I2C_SS0_HSIOM_REG
    #define Current_Sensor_I2C_SS0_HSIOM_REG      Current_Sensor_I2C_RTS_SS0_HSIOM_REG
    #define Current_Sensor_I2C_SS0_HSIOM_PTR      Current_Sensor_I2C_RTS_SS0_HSIOM_PTR
    #define Current_Sensor_I2C_SS0_HSIOM_MASK     Current_Sensor_I2C_RTS_SS0_HSIOM_MASK
    #define Current_Sensor_I2C_SS0_HSIOM_POS      Current_Sensor_I2C_RTS_SS0_HSIOM_POS
    #endif /* Current_Sensor_I2C_SS0_HSIOM_REG */
#endif /* (Current_Sensor_I2C_SS0_PIN) */

#define Current_Sensor_I2C_MOSI_SCL_RX_WAKE_PIN_INDEX Current_Sensor_I2C_RX_WAKE_SCL_MOSI_PIN_INDEX
#define Current_Sensor_I2C_MOSI_SCL_RX_PIN_INDEX      Current_Sensor_I2C_RX_SCL_MOSI_PIN_INDEX
#define Current_Sensor_I2C_MISO_SDA_TX_PIN_INDEX      Current_Sensor_I2C_TX_SDA_MISO_PIN_INDEX
#ifndef Current_Sensor_I2C_SCLK_PIN_INDEX
#define Current_Sensor_I2C_SCLK_PIN_INDEX             Current_Sensor_I2C_CTS_SCLK_PIN_INDEX
#endif /* Current_Sensor_I2C_SCLK_PIN_INDEX */
#ifndef Current_Sensor_I2C_SS0_PIN_INDEX
#define Current_Sensor_I2C_SS0_PIN_INDEX              Current_Sensor_I2C_RTS_SS0_PIN_INDEX
#endif /* Current_Sensor_I2C_SS0_PIN_INDEX */

#define Current_Sensor_I2C_MOSI_SCL_RX_WAKE_PIN_MASK Current_Sensor_I2C_RX_WAKE_SCL_MOSI_PIN_MASK
#define Current_Sensor_I2C_MOSI_SCL_RX_PIN_MASK      Current_Sensor_I2C_RX_SCL_MOSI_PIN_MASK
#define Current_Sensor_I2C_MISO_SDA_TX_PIN_MASK      Current_Sensor_I2C_TX_SDA_MISO_PIN_MASK
#ifndef Current_Sensor_I2C_SCLK_PIN_MASK
#define Current_Sensor_I2C_SCLK_PIN_MASK             Current_Sensor_I2C_CTS_SCLK_PIN_MASK
#endif /* Current_Sensor_I2C_SCLK_PIN_MASK */
#ifndef Current_Sensor_I2C_SS0_PIN_MASK
#define Current_Sensor_I2C_SS0_PIN_MASK              Current_Sensor_I2C_RTS_SS0_PIN_MASK
#endif /* Current_Sensor_I2C_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_Current_Sensor_I2C_H) */


/* [] END OF FILE */
