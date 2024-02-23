/***************************************************************************//**
* \file TMC6100_SPI_PINS.h
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

#if !defined(CY_SCB_PINS_TMC6100_SPI_H)
#define CY_SCB_PINS_TMC6100_SPI_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define TMC6100_SPI_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define TMC6100_SPI_REMOVE_RX_SCL_MOSI_PIN      (1u)
#define TMC6100_SPI_REMOVE_TX_SDA_MISO_PIN      (1u)
#define TMC6100_SPI_REMOVE_CTS_SCLK_PIN      (1u)
#define TMC6100_SPI_REMOVE_RTS_SS0_PIN      (1u)
#define TMC6100_SPI_REMOVE_SS1_PIN                 (1u)
#define TMC6100_SPI_REMOVE_SS2_PIN                 (1u)
#define TMC6100_SPI_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define TMC6100_SPI_REMOVE_I2C_PINS                (1u)
#define TMC6100_SPI_REMOVE_SPI_MASTER_PINS         (1u)
#define TMC6100_SPI_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define TMC6100_SPI_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define TMC6100_SPI_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define TMC6100_SPI_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define TMC6100_SPI_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define TMC6100_SPI_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define TMC6100_SPI_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define TMC6100_SPI_REMOVE_SPI_SLAVE_PINS          (0u)
#define TMC6100_SPI_REMOVE_SPI_SLAVE_MOSI_PIN      (0u)
#define TMC6100_SPI_REMOVE_SPI_SLAVE_MISO_PIN      (0u)
#define TMC6100_SPI_REMOVE_UART_TX_PIN             (1u)
#define TMC6100_SPI_REMOVE_UART_RX_TX_PIN          (1u)
#define TMC6100_SPI_REMOVE_UART_RX_PIN             (1u)
#define TMC6100_SPI_REMOVE_UART_RX_WAKE_PIN        (1u)
#define TMC6100_SPI_REMOVE_UART_RTS_PIN            (1u)
#define TMC6100_SPI_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define TMC6100_SPI_RX_WAKE_SCL_MOSI_PIN (0u == TMC6100_SPI_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define TMC6100_SPI_RX_SCL_MOSI_PIN     (0u == TMC6100_SPI_REMOVE_RX_SCL_MOSI_PIN)
#define TMC6100_SPI_TX_SDA_MISO_PIN     (0u == TMC6100_SPI_REMOVE_TX_SDA_MISO_PIN)
#define TMC6100_SPI_CTS_SCLK_PIN     (0u == TMC6100_SPI_REMOVE_CTS_SCLK_PIN)
#define TMC6100_SPI_RTS_SS0_PIN     (0u == TMC6100_SPI_REMOVE_RTS_SS0_PIN)
#define TMC6100_SPI_SS1_PIN                (0u == TMC6100_SPI_REMOVE_SS1_PIN)
#define TMC6100_SPI_SS2_PIN                (0u == TMC6100_SPI_REMOVE_SS2_PIN)
#define TMC6100_SPI_SS3_PIN                (0u == TMC6100_SPI_REMOVE_SS3_PIN)

/* Mode defined pins */
#define TMC6100_SPI_I2C_PINS               (0u == TMC6100_SPI_REMOVE_I2C_PINS)
#define TMC6100_SPI_SPI_MASTER_PINS        (0u == TMC6100_SPI_REMOVE_SPI_MASTER_PINS)
#define TMC6100_SPI_SPI_MASTER_SCLK_PIN    (0u == TMC6100_SPI_REMOVE_SPI_MASTER_SCLK_PIN)
#define TMC6100_SPI_SPI_MASTER_MOSI_PIN    (0u == TMC6100_SPI_REMOVE_SPI_MASTER_MOSI_PIN)
#define TMC6100_SPI_SPI_MASTER_MISO_PIN    (0u == TMC6100_SPI_REMOVE_SPI_MASTER_MISO_PIN)
#define TMC6100_SPI_SPI_MASTER_SS0_PIN     (0u == TMC6100_SPI_REMOVE_SPI_MASTER_SS0_PIN)
#define TMC6100_SPI_SPI_MASTER_SS1_PIN     (0u == TMC6100_SPI_REMOVE_SPI_MASTER_SS1_PIN)
#define TMC6100_SPI_SPI_MASTER_SS2_PIN     (0u == TMC6100_SPI_REMOVE_SPI_MASTER_SS2_PIN)
#define TMC6100_SPI_SPI_MASTER_SS3_PIN     (0u == TMC6100_SPI_REMOVE_SPI_MASTER_SS3_PIN)
#define TMC6100_SPI_SPI_SLAVE_PINS         (0u == TMC6100_SPI_REMOVE_SPI_SLAVE_PINS)
#define TMC6100_SPI_SPI_SLAVE_MOSI_PIN     (0u == TMC6100_SPI_REMOVE_SPI_SLAVE_MOSI_PIN)
#define TMC6100_SPI_SPI_SLAVE_MISO_PIN     (0u == TMC6100_SPI_REMOVE_SPI_SLAVE_MISO_PIN)
#define TMC6100_SPI_UART_TX_PIN            (0u == TMC6100_SPI_REMOVE_UART_TX_PIN)
#define TMC6100_SPI_UART_RX_TX_PIN         (0u == TMC6100_SPI_REMOVE_UART_RX_TX_PIN)
#define TMC6100_SPI_UART_RX_PIN            (0u == TMC6100_SPI_REMOVE_UART_RX_PIN)
#define TMC6100_SPI_UART_RX_WAKE_PIN       (0u == TMC6100_SPI_REMOVE_UART_RX_WAKE_PIN)
#define TMC6100_SPI_UART_RTS_PIN           (0u == TMC6100_SPI_REMOVE_UART_RTS_PIN)
#define TMC6100_SPI_UART_CTS_PIN           (0u == TMC6100_SPI_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (TMC6100_SPI_RX_WAKE_SCL_MOSI_PIN)
    #include "TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (TMC6100_SPI_RX_SCL_MOSI) */

#if (TMC6100_SPI_RX_SCL_MOSI_PIN)
    #include "TMC6100_SPI_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (TMC6100_SPI_RX_SCL_MOSI) */

#if (TMC6100_SPI_TX_SDA_MISO_PIN)
    #include "TMC6100_SPI_uart_tx_i2c_sda_spi_miso.h"
#endif /* (TMC6100_SPI_TX_SDA_MISO) */

#if (TMC6100_SPI_CTS_SCLK_PIN)
    #include "TMC6100_SPI_uart_cts_spi_sclk.h"
#endif /* (TMC6100_SPI_CTS_SCLK) */

#if (TMC6100_SPI_RTS_SS0_PIN)
    #include "TMC6100_SPI_uart_rts_spi_ss0.h"
#endif /* (TMC6100_SPI_RTS_SS0_PIN) */

#if (TMC6100_SPI_SS1_PIN)
    #include "TMC6100_SPI_spi_ss1.h"
#endif /* (TMC6100_SPI_SS1_PIN) */

#if (TMC6100_SPI_SS2_PIN)
    #include "TMC6100_SPI_spi_ss2.h"
#endif /* (TMC6100_SPI_SS2_PIN) */

#if (TMC6100_SPI_SS3_PIN)
    #include "TMC6100_SPI_spi_ss3.h"
#endif /* (TMC6100_SPI_SS3_PIN) */

#if (TMC6100_SPI_I2C_PINS)
    #include "TMC6100_SPI_scl.h"
    #include "TMC6100_SPI_sda.h"
#endif /* (TMC6100_SPI_I2C_PINS) */

#if (TMC6100_SPI_SPI_MASTER_PINS)
#if (TMC6100_SPI_SPI_MASTER_SCLK_PIN)
    #include "TMC6100_SPI_sclk_m.h"
#endif /* (TMC6100_SPI_SPI_MASTER_SCLK_PIN) */

#if (TMC6100_SPI_SPI_MASTER_MOSI_PIN)
    #include "TMC6100_SPI_mosi_m.h"
#endif /* (TMC6100_SPI_SPI_MASTER_MOSI_PIN) */

#if (TMC6100_SPI_SPI_MASTER_MISO_PIN)
    #include "TMC6100_SPI_miso_m.h"
#endif /*(TMC6100_SPI_SPI_MASTER_MISO_PIN) */
#endif /* (TMC6100_SPI_SPI_MASTER_PINS) */

#if (TMC6100_SPI_SPI_SLAVE_PINS)
    #include "TMC6100_SPI_sclk_s.h"
    #include "TMC6100_SPI_ss_s.h"

#if (TMC6100_SPI_SPI_SLAVE_MOSI_PIN)
    #include "TMC6100_SPI_mosi_s.h"
#endif /* (TMC6100_SPI_SPI_SLAVE_MOSI_PIN) */

#if (TMC6100_SPI_SPI_SLAVE_MISO_PIN)
    #include "TMC6100_SPI_miso_s.h"
#endif /*(TMC6100_SPI_SPI_SLAVE_MISO_PIN) */
#endif /* (TMC6100_SPI_SPI_SLAVE_PINS) */

#if (TMC6100_SPI_SPI_MASTER_SS0_PIN)
    #include "TMC6100_SPI_ss0_m.h"
#endif /* (TMC6100_SPI_SPI_MASTER_SS0_PIN) */

#if (TMC6100_SPI_SPI_MASTER_SS1_PIN)
    #include "TMC6100_SPI_ss1_m.h"
#endif /* (TMC6100_SPI_SPI_MASTER_SS1_PIN) */

#if (TMC6100_SPI_SPI_MASTER_SS2_PIN)
    #include "TMC6100_SPI_ss2_m.h"
#endif /* (TMC6100_SPI_SPI_MASTER_SS2_PIN) */

#if (TMC6100_SPI_SPI_MASTER_SS3_PIN)
    #include "TMC6100_SPI_ss3_m.h"
#endif /* (TMC6100_SPI_SPI_MASTER_SS3_PIN) */

#if (TMC6100_SPI_UART_TX_PIN)
    #include "TMC6100_SPI_tx.h"
#endif /* (TMC6100_SPI_UART_TX_PIN) */

#if (TMC6100_SPI_UART_RX_TX_PIN)
    #include "TMC6100_SPI_rx_tx.h"
#endif /* (TMC6100_SPI_UART_RX_TX_PIN) */

#if (TMC6100_SPI_UART_RX_PIN)
    #include "TMC6100_SPI_rx.h"
#endif /* (TMC6100_SPI_UART_RX_PIN) */

#if (TMC6100_SPI_UART_RX_WAKE_PIN)
    #include "TMC6100_SPI_rx_wake.h"
#endif /* (TMC6100_SPI_UART_RX_WAKE_PIN) */

#if (TMC6100_SPI_UART_RTS_PIN)
    #include "TMC6100_SPI_rts.h"
#endif /* (TMC6100_SPI_UART_RTS_PIN) */

#if (TMC6100_SPI_UART_CTS_PIN)
    #include "TMC6100_SPI_cts.h"
#endif /* (TMC6100_SPI_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (TMC6100_SPI_RX_SCL_MOSI_PIN)
    #define TMC6100_SPI_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) TMC6100_SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define TMC6100_SPI_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    
    #define TMC6100_SPI_RX_SCL_MOSI_HSIOM_MASK      (TMC6100_SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define TMC6100_SPI_RX_SCL_MOSI_HSIOM_POS       (TMC6100_SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define TMC6100_SPI_RX_SCL_MOSI_HSIOM_SEL_GPIO  (TMC6100_SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define TMC6100_SPI_RX_SCL_MOSI_HSIOM_SEL_I2C   (TMC6100_SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define TMC6100_SPI_RX_SCL_MOSI_HSIOM_SEL_SPI   (TMC6100_SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define TMC6100_SPI_RX_SCL_MOSI_HSIOM_SEL_UART  (TMC6100_SPI_uart_rx_i2c_scl_spi_mosi__0__HSIOM_UART)
    
#elif (TMC6100_SPI_RX_WAKE_SCL_MOSI_PIN)
    #define TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_REG   (*(reg32 *) TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    
    #define TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_MASK      (TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_POS       (TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_SEL_GPIO  (TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C   (TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI   (TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART  (TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_UART)    
   
    #define TMC6100_SPI_RX_WAKE_SCL_MOSI_INTCFG_REG (*(reg32 *) TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define TMC6100_SPI_RX_WAKE_SCL_MOSI_INTCFG_PTR ( (reg32 *) TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define TMC6100_SPI_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define TMC6100_SPI_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK ((uint32) TMC6100_SPI_INTCFG_TYPE_MASK << \
                                                                           TMC6100_SPI_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#else
    /* None of pins TMC6100_SPI_RX_SCL_MOSI_PIN or TMC6100_SPI_RX_WAKE_SCL_MOSI_PIN present.*/
#endif /* (TMC6100_SPI_RX_SCL_MOSI_PIN) */

#if (TMC6100_SPI_TX_SDA_MISO_PIN)
    #define TMC6100_SPI_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) TMC6100_SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define TMC6100_SPI_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    
    #define TMC6100_SPI_TX_SDA_MISO_HSIOM_MASK      (TMC6100_SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define TMC6100_SPI_TX_SDA_MISO_HSIOM_POS       (TMC6100_SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
    #define TMC6100_SPI_TX_SDA_MISO_HSIOM_SEL_GPIO  (TMC6100_SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM_GPIO)
    #define TMC6100_SPI_TX_SDA_MISO_HSIOM_SEL_I2C   (TMC6100_SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM_I2C)
    #define TMC6100_SPI_TX_SDA_MISO_HSIOM_SEL_SPI   (TMC6100_SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM_SPI)
    #define TMC6100_SPI_TX_SDA_MISO_HSIOM_SEL_UART  (TMC6100_SPI_uart_tx_i2c_sda_spi_miso__0__HSIOM_UART)
#endif /* (TMC6100_SPI_TX_SDA_MISO_PIN) */

#if (TMC6100_SPI_CTS_SCLK_PIN)
    #define TMC6100_SPI_CTS_SCLK_HSIOM_REG   (*(reg32 *) TMC6100_SPI_uart_cts_spi_sclk__0__HSIOM)
    #define TMC6100_SPI_CTS_SCLK_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_uart_cts_spi_sclk__0__HSIOM)
    
    #define TMC6100_SPI_CTS_SCLK_HSIOM_MASK      (TMC6100_SPI_uart_cts_spi_sclk__0__HSIOM_MASK)
    #define TMC6100_SPI_CTS_SCLK_HSIOM_POS       (TMC6100_SPI_uart_cts_spi_sclk__0__HSIOM_SHIFT)
    #define TMC6100_SPI_CTS_SCLK_HSIOM_SEL_GPIO  (TMC6100_SPI_uart_cts_spi_sclk__0__HSIOM_GPIO)
    #define TMC6100_SPI_CTS_SCLK_HSIOM_SEL_I2C   (TMC6100_SPI_uart_cts_spi_sclk__0__HSIOM_I2C)
    #define TMC6100_SPI_CTS_SCLK_HSIOM_SEL_SPI   (TMC6100_SPI_uart_cts_spi_sclk__0__HSIOM_SPI)
    #define TMC6100_SPI_CTS_SCLK_HSIOM_SEL_UART  (TMC6100_SPI_uart_cts_spi_sclk__0__HSIOM_UART)
#endif /* (TMC6100_SPI_CTS_SCLK_PIN) */

#if (TMC6100_SPI_RTS_SS0_PIN)
    #define TMC6100_SPI_RTS_SS0_HSIOM_REG   (*(reg32 *) TMC6100_SPI_uart_rts_spi_ss0__0__HSIOM)
    #define TMC6100_SPI_RTS_SS0_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_uart_rts_spi_ss0__0__HSIOM)
    
    #define TMC6100_SPI_RTS_SS0_HSIOM_MASK      (TMC6100_SPI_uart_rts_spi_ss0__0__HSIOM_MASK)
    #define TMC6100_SPI_RTS_SS0_HSIOM_POS       (TMC6100_SPI_uart_rts_spi_ss0__0__HSIOM_SHIFT)
    #define TMC6100_SPI_RTS_SS0_HSIOM_SEL_GPIO  (TMC6100_SPI_uart_rts_spi_ss0__0__HSIOM_GPIO)
    #define TMC6100_SPI_RTS_SS0_HSIOM_SEL_I2C   (TMC6100_SPI_uart_rts_spi_ss0__0__HSIOM_I2C)
    #define TMC6100_SPI_RTS_SS0_HSIOM_SEL_SPI   (TMC6100_SPI_uart_rts_spi_ss0__0__HSIOM_SPI)
#if !(TMC6100_SPI_CY_SCBIP_V0 || TMC6100_SPI_CY_SCBIP_V1)
    #define TMC6100_SPI_RTS_SS0_HSIOM_SEL_UART  (TMC6100_SPI_uart_rts_spi_ss0__0__HSIOM_UART)
#endif /* !(TMC6100_SPI_CY_SCBIP_V0 || TMC6100_SPI_CY_SCBIP_V1) */
#endif /* (TMC6100_SPI_RTS_SS0_PIN) */

#if (TMC6100_SPI_SS1_PIN)
    #define TMC6100_SPI_SS1_HSIOM_REG  (*(reg32 *) TMC6100_SPI_spi_ss1__0__HSIOM)
    #define TMC6100_SPI_SS1_HSIOM_PTR  ( (reg32 *) TMC6100_SPI_spi_ss1__0__HSIOM)
    
    #define TMC6100_SPI_SS1_HSIOM_MASK     (TMC6100_SPI_spi_ss1__0__HSIOM_MASK)
    #define TMC6100_SPI_SS1_HSIOM_POS      (TMC6100_SPI_spi_ss1__0__HSIOM_SHIFT)
    #define TMC6100_SPI_SS1_HSIOM_SEL_GPIO (TMC6100_SPI_spi_ss1__0__HSIOM_GPIO)
    #define TMC6100_SPI_SS1_HSIOM_SEL_I2C  (TMC6100_SPI_spi_ss1__0__HSIOM_I2C)
    #define TMC6100_SPI_SS1_HSIOM_SEL_SPI  (TMC6100_SPI_spi_ss1__0__HSIOM_SPI)
#endif /* (TMC6100_SPI_SS1_PIN) */

#if (TMC6100_SPI_SS2_PIN)
    #define TMC6100_SPI_SS2_HSIOM_REG     (*(reg32 *) TMC6100_SPI_spi_ss2__0__HSIOM)
    #define TMC6100_SPI_SS2_HSIOM_PTR     ( (reg32 *) TMC6100_SPI_spi_ss2__0__HSIOM)
    
    #define TMC6100_SPI_SS2_HSIOM_MASK     (TMC6100_SPI_spi_ss2__0__HSIOM_MASK)
    #define TMC6100_SPI_SS2_HSIOM_POS      (TMC6100_SPI_spi_ss2__0__HSIOM_SHIFT)
    #define TMC6100_SPI_SS2_HSIOM_SEL_GPIO (TMC6100_SPI_spi_ss2__0__HSIOM_GPIO)
    #define TMC6100_SPI_SS2_HSIOM_SEL_I2C  (TMC6100_SPI_spi_ss2__0__HSIOM_I2C)
    #define TMC6100_SPI_SS2_HSIOM_SEL_SPI  (TMC6100_SPI_spi_ss2__0__HSIOM_SPI)
#endif /* (TMC6100_SPI_SS2_PIN) */

#if (TMC6100_SPI_SS3_PIN)
    #define TMC6100_SPI_SS3_HSIOM_REG     (*(reg32 *) TMC6100_SPI_spi_ss3__0__HSIOM)
    #define TMC6100_SPI_SS3_HSIOM_PTR     ( (reg32 *) TMC6100_SPI_spi_ss3__0__HSIOM)
    
    #define TMC6100_SPI_SS3_HSIOM_MASK     (TMC6100_SPI_spi_ss3__0__HSIOM_MASK)
    #define TMC6100_SPI_SS3_HSIOM_POS      (TMC6100_SPI_spi_ss3__0__HSIOM_SHIFT)
    #define TMC6100_SPI_SS3_HSIOM_SEL_GPIO (TMC6100_SPI_spi_ss3__0__HSIOM_GPIO)
    #define TMC6100_SPI_SS3_HSIOM_SEL_I2C  (TMC6100_SPI_spi_ss3__0__HSIOM_I2C)
    #define TMC6100_SPI_SS3_HSIOM_SEL_SPI  (TMC6100_SPI_spi_ss3__0__HSIOM_SPI)
#endif /* (TMC6100_SPI_SS3_PIN) */

#if (TMC6100_SPI_I2C_PINS)
    #define TMC6100_SPI_SCL_HSIOM_REG  (*(reg32 *) TMC6100_SPI_scl__0__HSIOM)
    #define TMC6100_SPI_SCL_HSIOM_PTR  ( (reg32 *) TMC6100_SPI_scl__0__HSIOM)
    
    #define TMC6100_SPI_SCL_HSIOM_MASK     (TMC6100_SPI_scl__0__HSIOM_MASK)
    #define TMC6100_SPI_SCL_HSIOM_POS      (TMC6100_SPI_scl__0__HSIOM_SHIFT)
    #define TMC6100_SPI_SCL_HSIOM_SEL_GPIO (TMC6100_SPI_sda__0__HSIOM_GPIO)
    #define TMC6100_SPI_SCL_HSIOM_SEL_I2C  (TMC6100_SPI_sda__0__HSIOM_I2C)
    
    #define TMC6100_SPI_SDA_HSIOM_REG  (*(reg32 *) TMC6100_SPI_sda__0__HSIOM)
    #define TMC6100_SPI_SDA_HSIOM_PTR  ( (reg32 *) TMC6100_SPI_sda__0__HSIOM)
    
    #define TMC6100_SPI_SDA_HSIOM_MASK     (TMC6100_SPI_sda__0__HSIOM_MASK)
    #define TMC6100_SPI_SDA_HSIOM_POS      (TMC6100_SPI_sda__0__HSIOM_SHIFT)
    #define TMC6100_SPI_SDA_HSIOM_SEL_GPIO (TMC6100_SPI_sda__0__HSIOM_GPIO)
    #define TMC6100_SPI_SDA_HSIOM_SEL_I2C  (TMC6100_SPI_sda__0__HSIOM_I2C)
#endif /* (TMC6100_SPI_I2C_PINS) */

#if (TMC6100_SPI_SPI_SLAVE_PINS)
    #define TMC6100_SPI_SCLK_S_HSIOM_REG   (*(reg32 *) TMC6100_SPI_sclk_s__0__HSIOM)
    #define TMC6100_SPI_SCLK_S_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_sclk_s__0__HSIOM)
    
    #define TMC6100_SPI_SCLK_S_HSIOM_MASK      (TMC6100_SPI_sclk_s__0__HSIOM_MASK)
    #define TMC6100_SPI_SCLK_S_HSIOM_POS       (TMC6100_SPI_sclk_s__0__HSIOM_SHIFT)
    #define TMC6100_SPI_SCLK_S_HSIOM_SEL_GPIO  (TMC6100_SPI_sclk_s__0__HSIOM_GPIO)
    #define TMC6100_SPI_SCLK_S_HSIOM_SEL_SPI   (TMC6100_SPI_sclk_s__0__HSIOM_SPI)
    
    #define TMC6100_SPI_SS0_S_HSIOM_REG    (*(reg32 *) TMC6100_SPI_ss0_s__0__HSIOM)
    #define TMC6100_SPI_SS0_S_HSIOM_PTR    ( (reg32 *) TMC6100_SPI_ss0_s__0__HSIOM)
    
    #define TMC6100_SPI_SS0_S_HSIOM_MASK       (TMC6100_SPI_ss0_s__0__HSIOM_MASK)
    #define TMC6100_SPI_SS0_S_HSIOM_POS        (TMC6100_SPI_ss0_s__0__HSIOM_SHIFT)
    #define TMC6100_SPI_SS0_S_HSIOM_SEL_GPIO   (TMC6100_SPI_ss0_s__0__HSIOM_GPIO)  
    #define TMC6100_SPI_SS0_S_HSIOM_SEL_SPI    (TMC6100_SPI_ss0_s__0__HSIOM_SPI)
#endif /* (TMC6100_SPI_SPI_SLAVE_PINS) */

#if (TMC6100_SPI_SPI_SLAVE_MOSI_PIN)
    #define TMC6100_SPI_MOSI_S_HSIOM_REG   (*(reg32 *) TMC6100_SPI_mosi_s__0__HSIOM)
    #define TMC6100_SPI_MOSI_S_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_mosi_s__0__HSIOM)
    
    #define TMC6100_SPI_MOSI_S_HSIOM_MASK      (TMC6100_SPI_mosi_s__0__HSIOM_MASK)
    #define TMC6100_SPI_MOSI_S_HSIOM_POS       (TMC6100_SPI_mosi_s__0__HSIOM_SHIFT)
    #define TMC6100_SPI_MOSI_S_HSIOM_SEL_GPIO  (TMC6100_SPI_mosi_s__0__HSIOM_GPIO)
    #define TMC6100_SPI_MOSI_S_HSIOM_SEL_SPI   (TMC6100_SPI_mosi_s__0__HSIOM_SPI)
#endif /* (TMC6100_SPI_SPI_SLAVE_MOSI_PIN) */

#if (TMC6100_SPI_SPI_SLAVE_MISO_PIN)
    #define TMC6100_SPI_MISO_S_HSIOM_REG   (*(reg32 *) TMC6100_SPI_miso_s__0__HSIOM)
    #define TMC6100_SPI_MISO_S_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_miso_s__0__HSIOM)
    
    #define TMC6100_SPI_MISO_S_HSIOM_MASK      (TMC6100_SPI_miso_s__0__HSIOM_MASK)
    #define TMC6100_SPI_MISO_S_HSIOM_POS       (TMC6100_SPI_miso_s__0__HSIOM_SHIFT)
    #define TMC6100_SPI_MISO_S_HSIOM_SEL_GPIO  (TMC6100_SPI_miso_s__0__HSIOM_GPIO)
    #define TMC6100_SPI_MISO_S_HSIOM_SEL_SPI   (TMC6100_SPI_miso_s__0__HSIOM_SPI)
#endif /* (TMC6100_SPI_SPI_SLAVE_MISO_PIN) */

#if (TMC6100_SPI_SPI_MASTER_MISO_PIN)
    #define TMC6100_SPI_MISO_M_HSIOM_REG   (*(reg32 *) TMC6100_SPI_miso_m__0__HSIOM)
    #define TMC6100_SPI_MISO_M_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_miso_m__0__HSIOM)
    
    #define TMC6100_SPI_MISO_M_HSIOM_MASK      (TMC6100_SPI_miso_m__0__HSIOM_MASK)
    #define TMC6100_SPI_MISO_M_HSIOM_POS       (TMC6100_SPI_miso_m__0__HSIOM_SHIFT)
    #define TMC6100_SPI_MISO_M_HSIOM_SEL_GPIO  (TMC6100_SPI_miso_m__0__HSIOM_GPIO)
    #define TMC6100_SPI_MISO_M_HSIOM_SEL_SPI   (TMC6100_SPI_miso_m__0__HSIOM_SPI)
#endif /* (TMC6100_SPI_SPI_MASTER_MISO_PIN) */

#if (TMC6100_SPI_SPI_MASTER_MOSI_PIN)
    #define TMC6100_SPI_MOSI_M_HSIOM_REG   (*(reg32 *) TMC6100_SPI_mosi_m__0__HSIOM)
    #define TMC6100_SPI_MOSI_M_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_mosi_m__0__HSIOM)
    
    #define TMC6100_SPI_MOSI_M_HSIOM_MASK      (TMC6100_SPI_mosi_m__0__HSIOM_MASK)
    #define TMC6100_SPI_MOSI_M_HSIOM_POS       (TMC6100_SPI_mosi_m__0__HSIOM_SHIFT)
    #define TMC6100_SPI_MOSI_M_HSIOM_SEL_GPIO  (TMC6100_SPI_mosi_m__0__HSIOM_GPIO)
    #define TMC6100_SPI_MOSI_M_HSIOM_SEL_SPI   (TMC6100_SPI_mosi_m__0__HSIOM_SPI)
#endif /* (TMC6100_SPI_SPI_MASTER_MOSI_PIN) */

#if (TMC6100_SPI_SPI_MASTER_SCLK_PIN)
    #define TMC6100_SPI_SCLK_M_HSIOM_REG   (*(reg32 *) TMC6100_SPI_sclk_m__0__HSIOM)
    #define TMC6100_SPI_SCLK_M_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_sclk_m__0__HSIOM)
    
    #define TMC6100_SPI_SCLK_M_HSIOM_MASK      (TMC6100_SPI_sclk_m__0__HSIOM_MASK)
    #define TMC6100_SPI_SCLK_M_HSIOM_POS       (TMC6100_SPI_sclk_m__0__HSIOM_SHIFT)
    #define TMC6100_SPI_SCLK_M_HSIOM_SEL_GPIO  (TMC6100_SPI_sclk_m__0__HSIOM_GPIO)
    #define TMC6100_SPI_SCLK_M_HSIOM_SEL_SPI   (TMC6100_SPI_sclk_m__0__HSIOM_SPI)
#endif /* (TMC6100_SPI_SPI_MASTER_SCLK_PIN) */

#if (TMC6100_SPI_SPI_MASTER_SS0_PIN)
    #define TMC6100_SPI_SS0_M_HSIOM_REG    (*(reg32 *) TMC6100_SPI_ss0_m__0__HSIOM)
    #define TMC6100_SPI_SS0_M_HSIOM_PTR    ( (reg32 *) TMC6100_SPI_ss0_m__0__HSIOM)
    
    #define TMC6100_SPI_SS0_M_HSIOM_MASK       (TMC6100_SPI_ss0_m__0__HSIOM_MASK)
    #define TMC6100_SPI_SS0_M_HSIOM_POS        (TMC6100_SPI_ss0_m__0__HSIOM_SHIFT)
    #define TMC6100_SPI_SS0_M_HSIOM_SEL_GPIO   (TMC6100_SPI_ss0_m__0__HSIOM_GPIO)
    #define TMC6100_SPI_SS0_M_HSIOM_SEL_SPI    (TMC6100_SPI_ss0_m__0__HSIOM_SPI)
#endif /* (TMC6100_SPI_SPI_MASTER_SS0_PIN) */

#if (TMC6100_SPI_SPI_MASTER_SS1_PIN)
    #define TMC6100_SPI_SS1_M_HSIOM_REG    (*(reg32 *) TMC6100_SPI_ss1_m__0__HSIOM)
    #define TMC6100_SPI_SS1_M_HSIOM_PTR    ( (reg32 *) TMC6100_SPI_ss1_m__0__HSIOM)
    
    #define TMC6100_SPI_SS1_M_HSIOM_MASK       (TMC6100_SPI_ss1_m__0__HSIOM_MASK)
    #define TMC6100_SPI_SS1_M_HSIOM_POS        (TMC6100_SPI_ss1_m__0__HSIOM_SHIFT)
    #define TMC6100_SPI_SS1_M_HSIOM_SEL_GPIO   (TMC6100_SPI_ss1_m__0__HSIOM_GPIO)
    #define TMC6100_SPI_SS1_M_HSIOM_SEL_SPI    (TMC6100_SPI_ss1_m__0__HSIOM_SPI)
#endif /* (TMC6100_SPI_SPI_MASTER_SS1_PIN) */

#if (TMC6100_SPI_SPI_MASTER_SS2_PIN)
    #define TMC6100_SPI_SS2_M_HSIOM_REG    (*(reg32 *) TMC6100_SPI_ss2_m__0__HSIOM)
    #define TMC6100_SPI_SS2_M_HSIOM_PTR    ( (reg32 *) TMC6100_SPI_ss2_m__0__HSIOM)
    
    #define TMC6100_SPI_SS2_M_HSIOM_MASK       (TMC6100_SPI_ss2_m__0__HSIOM_MASK)
    #define TMC6100_SPI_SS2_M_HSIOM_POS        (TMC6100_SPI_ss2_m__0__HSIOM_SHIFT)
    #define TMC6100_SPI_SS2_M_HSIOM_SEL_GPIO   (TMC6100_SPI_ss2_m__0__HSIOM_GPIO)
    #define TMC6100_SPI_SS2_M_HSIOM_SEL_SPI    (TMC6100_SPI_ss2_m__0__HSIOM_SPI)
#endif /* (TMC6100_SPI_SPI_MASTER_SS2_PIN) */

#if (TMC6100_SPI_SPI_MASTER_SS3_PIN)
    #define TMC6100_SPI_SS3_M_HSIOM_REG    (*(reg32 *) TMC6100_SPI_ss3_m__0__HSIOM)
    #define TMC6100_SPI_SS3_M_HSIOM_PTR    ( (reg32 *) TMC6100_SPI_ss3_m__0__HSIOM)
    
    #define TMC6100_SPI_SS3_M_HSIOM_MASK      (TMC6100_SPI_ss3_m__0__HSIOM_MASK)
    #define TMC6100_SPI_SS3_M_HSIOM_POS       (TMC6100_SPI_ss3_m__0__HSIOM_SHIFT)
    #define TMC6100_SPI_SS3_M_HSIOM_SEL_GPIO  (TMC6100_SPI_ss3_m__0__HSIOM_GPIO)
    #define TMC6100_SPI_SS3_M_HSIOM_SEL_SPI   (TMC6100_SPI_ss3_m__0__HSIOM_SPI)
#endif /* (TMC6100_SPI_SPI_MASTER_SS3_PIN) */

#if (TMC6100_SPI_UART_RX_PIN)
    #define TMC6100_SPI_RX_HSIOM_REG   (*(reg32 *) TMC6100_SPI_rx__0__HSIOM)
    #define TMC6100_SPI_RX_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_rx__0__HSIOM)
    
    #define TMC6100_SPI_RX_HSIOM_MASK      (TMC6100_SPI_rx__0__HSIOM_MASK)
    #define TMC6100_SPI_RX_HSIOM_POS       (TMC6100_SPI_rx__0__HSIOM_SHIFT)
    #define TMC6100_SPI_RX_HSIOM_SEL_GPIO  (TMC6100_SPI_rx__0__HSIOM_GPIO)
    #define TMC6100_SPI_RX_HSIOM_SEL_UART  (TMC6100_SPI_rx__0__HSIOM_UART)
#endif /* (TMC6100_SPI_UART_RX_PIN) */

#if (TMC6100_SPI_UART_RX_WAKE_PIN)
    #define TMC6100_SPI_RX_WAKE_HSIOM_REG   (*(reg32 *) TMC6100_SPI_rx_wake__0__HSIOM)
    #define TMC6100_SPI_RX_WAKE_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_rx_wake__0__HSIOM)
    
    #define TMC6100_SPI_RX_WAKE_HSIOM_MASK      (TMC6100_SPI_rx_wake__0__HSIOM_MASK)
    #define TMC6100_SPI_RX_WAKE_HSIOM_POS       (TMC6100_SPI_rx_wake__0__HSIOM_SHIFT)
    #define TMC6100_SPI_RX_WAKE_HSIOM_SEL_GPIO  (TMC6100_SPI_rx_wake__0__HSIOM_GPIO)
    #define TMC6100_SPI_RX_WAKE_HSIOM_SEL_UART  (TMC6100_SPI_rx_wake__0__HSIOM_UART)
#endif /* (TMC6100_SPI_UART_WAKE_RX_PIN) */

#if (TMC6100_SPI_UART_CTS_PIN)
    #define TMC6100_SPI_CTS_HSIOM_REG   (*(reg32 *) TMC6100_SPI_cts__0__HSIOM)
    #define TMC6100_SPI_CTS_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_cts__0__HSIOM)
    
    #define TMC6100_SPI_CTS_HSIOM_MASK      (TMC6100_SPI_cts__0__HSIOM_MASK)
    #define TMC6100_SPI_CTS_HSIOM_POS       (TMC6100_SPI_cts__0__HSIOM_SHIFT)
    #define TMC6100_SPI_CTS_HSIOM_SEL_GPIO  (TMC6100_SPI_cts__0__HSIOM_GPIO)
    #define TMC6100_SPI_CTS_HSIOM_SEL_UART  (TMC6100_SPI_cts__0__HSIOM_UART)
#endif /* (TMC6100_SPI_UART_CTS_PIN) */

#if (TMC6100_SPI_UART_TX_PIN)
    #define TMC6100_SPI_TX_HSIOM_REG   (*(reg32 *) TMC6100_SPI_tx__0__HSIOM)
    #define TMC6100_SPI_TX_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_tx__0__HSIOM)
    
    #define TMC6100_SPI_TX_HSIOM_MASK      (TMC6100_SPI_tx__0__HSIOM_MASK)
    #define TMC6100_SPI_TX_HSIOM_POS       (TMC6100_SPI_tx__0__HSIOM_SHIFT)
    #define TMC6100_SPI_TX_HSIOM_SEL_GPIO  (TMC6100_SPI_tx__0__HSIOM_GPIO)
    #define TMC6100_SPI_TX_HSIOM_SEL_UART  (TMC6100_SPI_tx__0__HSIOM_UART)
#endif /* (TMC6100_SPI_UART_TX_PIN) */

#if (TMC6100_SPI_UART_RX_TX_PIN)
    #define TMC6100_SPI_RX_TX_HSIOM_REG   (*(reg32 *) TMC6100_SPI_rx_tx__0__HSIOM)
    #define TMC6100_SPI_RX_TX_HSIOM_PTR   ( (reg32 *) TMC6100_SPI_rx_tx__0__HSIOM)
    
    #define TMC6100_SPI_RX_TX_HSIOM_MASK      (TMC6100_SPI_rx_tx__0__HSIOM_MASK)
    #define TMC6100_SPI_RX_TX_HSIOM_POS       (TMC6100_SPI_rx_tx__0__HSIOM_SHIFT)
    #define TMC6100_SPI_RX_TX_HSIOM_SEL_GPIO  (TMC6100_SPI_rx_tx__0__HSIOM_GPIO)
    #define TMC6100_SPI_RX_TX_HSIOM_SEL_UART  (TMC6100_SPI_rx_tx__0__HSIOM_UART)
#endif /* (TMC6100_SPI_UART_RX_TX_PIN) */

#if (TMC6100_SPI_UART_RTS_PIN)
    #define TMC6100_SPI_RTS_HSIOM_REG      (*(reg32 *) TMC6100_SPI_rts__0__HSIOM)
    #define TMC6100_SPI_RTS_HSIOM_PTR      ( (reg32 *) TMC6100_SPI_rts__0__HSIOM)
    
    #define TMC6100_SPI_RTS_HSIOM_MASK     (TMC6100_SPI_rts__0__HSIOM_MASK)
    #define TMC6100_SPI_RTS_HSIOM_POS      (TMC6100_SPI_rts__0__HSIOM_SHIFT)    
    #define TMC6100_SPI_RTS_HSIOM_SEL_GPIO (TMC6100_SPI_rts__0__HSIOM_GPIO)
    #define TMC6100_SPI_RTS_HSIOM_SEL_UART (TMC6100_SPI_rts__0__HSIOM_UART)    
#endif /* (TMC6100_SPI_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* HSIOM switch values. */ 
#define TMC6100_SPI_HSIOM_DEF_SEL      (0x00u)
#define TMC6100_SPI_HSIOM_GPIO_SEL     (0x00u)
/* The HSIOM values provided below are valid only for TMC6100_SPI_CY_SCBIP_V0 
* and TMC6100_SPI_CY_SCBIP_V1. It is not recommended to use them for 
* TMC6100_SPI_CY_SCBIP_V2. Use pin name specific HSIOM constants provided 
* above instead for any SCB IP block version.
*/
#define TMC6100_SPI_HSIOM_UART_SEL     (0x09u)
#define TMC6100_SPI_HSIOM_I2C_SEL      (0x0Eu)
#define TMC6100_SPI_HSIOM_SPI_SEL      (0x0Fu)

/* Pins settings index. */
#define TMC6100_SPI_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define TMC6100_SPI_RX_SCL_MOSI_PIN_INDEX       (0u)
#define TMC6100_SPI_TX_SDA_MISO_PIN_INDEX       (1u)
#define TMC6100_SPI_CTS_SCLK_PIN_INDEX       (2u)
#define TMC6100_SPI_RTS_SS0_PIN_INDEX       (3u)
#define TMC6100_SPI_SS1_PIN_INDEX                  (4u)
#define TMC6100_SPI_SS2_PIN_INDEX                  (5u)
#define TMC6100_SPI_SS3_PIN_INDEX                  (6u)

/* Pins settings mask. */
#define TMC6100_SPI_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << TMC6100_SPI_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define TMC6100_SPI_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << TMC6100_SPI_RX_SCL_MOSI_PIN_INDEX)
#define TMC6100_SPI_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << TMC6100_SPI_TX_SDA_MISO_PIN_INDEX)
#define TMC6100_SPI_CTS_SCLK_PIN_MASK     ((uint32) 0x01u << TMC6100_SPI_CTS_SCLK_PIN_INDEX)
#define TMC6100_SPI_RTS_SS0_PIN_MASK     ((uint32) 0x01u << TMC6100_SPI_RTS_SS0_PIN_INDEX)
#define TMC6100_SPI_SS1_PIN_MASK                ((uint32) 0x01u << TMC6100_SPI_SS1_PIN_INDEX)
#define TMC6100_SPI_SS2_PIN_MASK                ((uint32) 0x01u << TMC6100_SPI_SS2_PIN_INDEX)
#define TMC6100_SPI_SS3_PIN_MASK                ((uint32) 0x01u << TMC6100_SPI_SS3_PIN_INDEX)

/* Pin interrupt constants. */
#define TMC6100_SPI_INTCFG_TYPE_MASK           (0x03u)
#define TMC6100_SPI_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants. */
#define TMC6100_SPI_PIN_DM_ALG_HIZ  (0u)
#define TMC6100_SPI_PIN_DM_DIG_HIZ  (1u)
#define TMC6100_SPI_PIN_DM_OD_LO    (4u)
#define TMC6100_SPI_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define TMC6100_SPI_DM_MASK    (0x7u)
#define TMC6100_SPI_DM_SIZE    (3u)
#define TMC6100_SPI_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) TMC6100_SPI_DM_MASK << (TMC6100_SPI_DM_SIZE * (pos)))) >> \
                                                              (TMC6100_SPI_DM_SIZE * (pos)) )

#if (TMC6100_SPI_TX_SDA_MISO_PIN)
    #define TMC6100_SPI_CHECK_TX_SDA_MISO_PIN_USED \
                (TMC6100_SPI_PIN_DM_ALG_HIZ != \
                    TMC6100_SPI_GET_P4_PIN_DM(TMC6100_SPI_uart_tx_i2c_sda_spi_miso_PC, \
                                                   TMC6100_SPI_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (TMC6100_SPI_TX_SDA_MISO_PIN) */

#if (TMC6100_SPI_RTS_SS0_PIN)
    #define TMC6100_SPI_CHECK_RTS_SS0_PIN_USED \
                (TMC6100_SPI_PIN_DM_ALG_HIZ != \
                    TMC6100_SPI_GET_P4_PIN_DM(TMC6100_SPI_uart_rts_spi_ss0_PC, \
                                                   TMC6100_SPI_uart_rts_spi_ss0_SHIFT))
#endif /* (TMC6100_SPI_RTS_SS0_PIN) */

/* Set bits-mask in register */
#define TMC6100_SPI_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define TMC6100_SPI_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define TMC6100_SPI_SET_HSIOM_SEL(reg, mask, pos, sel) TMC6100_SPI_SET_REGISTER_BITS(reg, mask, pos, sel)
#define TMC6100_SPI_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        TMC6100_SPI_SET_REGISTER_BITS(reg, mask, pos, intType)
#define TMC6100_SPI_SET_INP_DIS(reg, mask, val) TMC6100_SPI_SET_REGISTER_BIT(reg, mask, val)

/* TMC6100_SPI_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  TMC6100_SPI_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (TMC6100_SPI_CY_SCBIP_V0)
#if (TMC6100_SPI_I2C_PINS)
    #define TMC6100_SPI_SET_I2C_SCL_DR(val) TMC6100_SPI_scl_Write(val)

    #define TMC6100_SPI_SET_I2C_SCL_HSIOM_SEL(sel) \
                          TMC6100_SPI_SET_HSIOM_SEL(TMC6100_SPI_SCL_HSIOM_REG,  \
                                                         TMC6100_SPI_SCL_HSIOM_MASK, \
                                                         TMC6100_SPI_SCL_HSIOM_POS,  \
                                                         (sel))
    #define TMC6100_SPI_WAIT_SCL_SET_HIGH  (0u == TMC6100_SPI_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (TMC6100_SPI_RX_WAKE_SCL_MOSI_PIN)
    #define TMC6100_SPI_SET_I2C_SCL_DR(val) \
                            TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define TMC6100_SPI_SET_I2C_SCL_HSIOM_SEL(sel) \
                    TMC6100_SPI_SET_HSIOM_SEL(TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define TMC6100_SPI_WAIT_SCL_SET_HIGH  (0u == TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (TMC6100_SPI_RX_SCL_MOSI_PIN)
    #define TMC6100_SPI_SET_I2C_SCL_DR(val) \
                            TMC6100_SPI_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define TMC6100_SPI_SET_I2C_SCL_HSIOM_SEL(sel) \
                            TMC6100_SPI_SET_HSIOM_SEL(TMC6100_SPI_RX_SCL_MOSI_HSIOM_REG,  \
                                                           TMC6100_SPI_RX_SCL_MOSI_HSIOM_MASK, \
                                                           TMC6100_SPI_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define TMC6100_SPI_WAIT_SCL_SET_HIGH  (0u == TMC6100_SPI_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define TMC6100_SPI_SET_I2C_SCL_DR(val)        do{ /* Does nothing */ }while(0)
    #define TMC6100_SPI_SET_I2C_SCL_HSIOM_SEL(sel) do{ /* Does nothing */ }while(0)

    #define TMC6100_SPI_WAIT_SCL_SET_HIGH  (0u)
#endif /* (TMC6100_SPI_I2C_PINS) */

/* SCB I2C: sda signal */
#if (TMC6100_SPI_I2C_PINS)
    #define TMC6100_SPI_WAIT_SDA_SET_HIGH  (0u == TMC6100_SPI_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (TMC6100_SPI_TX_SDA_MISO_PIN)
    #define TMC6100_SPI_WAIT_SDA_SET_HIGH  (0u == TMC6100_SPI_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define TMC6100_SPI_WAIT_SDA_SET_HIGH  (0u)
#endif /* (TMC6100_SPI_MOSI_SCL_RX_PIN) */
#endif /* (TMC6100_SPI_CY_SCBIP_V0) */

/* Clear UART wakeup source */
#if (TMC6100_SPI_RX_SCL_MOSI_PIN)
    #define TMC6100_SPI_CLEAR_UART_RX_WAKE_INTR        do{ /* Does nothing */ }while(0)
    
#elif (TMC6100_SPI_RX_WAKE_SCL_MOSI_PIN)
    #define TMC6100_SPI_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) TMC6100_SPI_uart_rx_wake_i2c_scl_spi_mosi_ClearInterrupt(); \
            }while(0)

#elif(TMC6100_SPI_UART_RX_WAKE_PIN)
    #define TMC6100_SPI_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) TMC6100_SPI_rx_wake_ClearInterrupt(); \
            }while(0)
#else
#endif /* (TMC6100_SPI_RX_SCL_MOSI_PIN) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define TMC6100_SPI_REMOVE_MOSI_SCL_RX_WAKE_PIN    TMC6100_SPI_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define TMC6100_SPI_REMOVE_MOSI_SCL_RX_PIN         TMC6100_SPI_REMOVE_RX_SCL_MOSI_PIN
#define TMC6100_SPI_REMOVE_MISO_SDA_TX_PIN         TMC6100_SPI_REMOVE_TX_SDA_MISO_PIN
#ifndef TMC6100_SPI_REMOVE_SCLK_PIN
#define TMC6100_SPI_REMOVE_SCLK_PIN                TMC6100_SPI_REMOVE_CTS_SCLK_PIN
#endif /* TMC6100_SPI_REMOVE_SCLK_PIN */
#ifndef TMC6100_SPI_REMOVE_SS0_PIN
#define TMC6100_SPI_REMOVE_SS0_PIN                 TMC6100_SPI_REMOVE_RTS_SS0_PIN
#endif /* TMC6100_SPI_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define TMC6100_SPI_MOSI_SCL_RX_WAKE_PIN   TMC6100_SPI_RX_WAKE_SCL_MOSI_PIN
#define TMC6100_SPI_MOSI_SCL_RX_PIN        TMC6100_SPI_RX_SCL_MOSI_PIN
#define TMC6100_SPI_MISO_SDA_TX_PIN        TMC6100_SPI_TX_SDA_MISO_PIN
#ifndef TMC6100_SPI_SCLK_PIN
#define TMC6100_SPI_SCLK_PIN               TMC6100_SPI_CTS_SCLK_PIN
#endif /* TMC6100_SPI_SCLK_PIN */
#ifndef TMC6100_SPI_SS0_PIN
#define TMC6100_SPI_SS0_PIN                TMC6100_SPI_RTS_SS0_PIN
#endif /* TMC6100_SPI_SS0_PIN */

#if (TMC6100_SPI_MOSI_SCL_RX_WAKE_PIN)
    #define TMC6100_SPI_MOSI_SCL_RX_WAKE_HSIOM_REG     TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define TMC6100_SPI_MOSI_SCL_RX_WAKE_HSIOM_PTR     TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define TMC6100_SPI_MOSI_SCL_RX_WAKE_HSIOM_MASK    TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define TMC6100_SPI_MOSI_SCL_RX_WAKE_HSIOM_POS     TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define TMC6100_SPI_MOSI_SCL_RX_WAKE_INTCFG_REG    TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define TMC6100_SPI_MOSI_SCL_RX_WAKE_INTCFG_PTR    TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define TMC6100_SPI_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define TMC6100_SPI_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  TMC6100_SPI_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (TMC6100_SPI_RX_WAKE_SCL_MOSI_PIN) */

#if (TMC6100_SPI_MOSI_SCL_RX_PIN)
    #define TMC6100_SPI_MOSI_SCL_RX_HSIOM_REG      TMC6100_SPI_RX_SCL_MOSI_HSIOM_REG
    #define TMC6100_SPI_MOSI_SCL_RX_HSIOM_PTR      TMC6100_SPI_RX_SCL_MOSI_HSIOM_PTR
    #define TMC6100_SPI_MOSI_SCL_RX_HSIOM_MASK     TMC6100_SPI_RX_SCL_MOSI_HSIOM_MASK
    #define TMC6100_SPI_MOSI_SCL_RX_HSIOM_POS      TMC6100_SPI_RX_SCL_MOSI_HSIOM_POS
#endif /* (TMC6100_SPI_MOSI_SCL_RX_PIN) */

#if (TMC6100_SPI_MISO_SDA_TX_PIN)
    #define TMC6100_SPI_MISO_SDA_TX_HSIOM_REG      TMC6100_SPI_TX_SDA_MISO_HSIOM_REG
    #define TMC6100_SPI_MISO_SDA_TX_HSIOM_PTR      TMC6100_SPI_TX_SDA_MISO_HSIOM_REG
    #define TMC6100_SPI_MISO_SDA_TX_HSIOM_MASK     TMC6100_SPI_TX_SDA_MISO_HSIOM_REG
    #define TMC6100_SPI_MISO_SDA_TX_HSIOM_POS      TMC6100_SPI_TX_SDA_MISO_HSIOM_REG
#endif /* (TMC6100_SPI_MISO_SDA_TX_PIN_PIN) */

#if (TMC6100_SPI_SCLK_PIN)
    #ifndef TMC6100_SPI_SCLK_HSIOM_REG
    #define TMC6100_SPI_SCLK_HSIOM_REG     TMC6100_SPI_CTS_SCLK_HSIOM_REG
    #define TMC6100_SPI_SCLK_HSIOM_PTR     TMC6100_SPI_CTS_SCLK_HSIOM_PTR
    #define TMC6100_SPI_SCLK_HSIOM_MASK    TMC6100_SPI_CTS_SCLK_HSIOM_MASK
    #define TMC6100_SPI_SCLK_HSIOM_POS     TMC6100_SPI_CTS_SCLK_HSIOM_POS
    #endif /* TMC6100_SPI_SCLK_HSIOM_REG */
#endif /* (TMC6100_SPI_SCLK_PIN) */

#if (TMC6100_SPI_SS0_PIN)
    #ifndef TMC6100_SPI_SS0_HSIOM_REG
    #define TMC6100_SPI_SS0_HSIOM_REG      TMC6100_SPI_RTS_SS0_HSIOM_REG
    #define TMC6100_SPI_SS0_HSIOM_PTR      TMC6100_SPI_RTS_SS0_HSIOM_PTR
    #define TMC6100_SPI_SS0_HSIOM_MASK     TMC6100_SPI_RTS_SS0_HSIOM_MASK
    #define TMC6100_SPI_SS0_HSIOM_POS      TMC6100_SPI_RTS_SS0_HSIOM_POS
    #endif /* TMC6100_SPI_SS0_HSIOM_REG */
#endif /* (TMC6100_SPI_SS0_PIN) */

#define TMC6100_SPI_MOSI_SCL_RX_WAKE_PIN_INDEX TMC6100_SPI_RX_WAKE_SCL_MOSI_PIN_INDEX
#define TMC6100_SPI_MOSI_SCL_RX_PIN_INDEX      TMC6100_SPI_RX_SCL_MOSI_PIN_INDEX
#define TMC6100_SPI_MISO_SDA_TX_PIN_INDEX      TMC6100_SPI_TX_SDA_MISO_PIN_INDEX
#ifndef TMC6100_SPI_SCLK_PIN_INDEX
#define TMC6100_SPI_SCLK_PIN_INDEX             TMC6100_SPI_CTS_SCLK_PIN_INDEX
#endif /* TMC6100_SPI_SCLK_PIN_INDEX */
#ifndef TMC6100_SPI_SS0_PIN_INDEX
#define TMC6100_SPI_SS0_PIN_INDEX              TMC6100_SPI_RTS_SS0_PIN_INDEX
#endif /* TMC6100_SPI_SS0_PIN_INDEX */

#define TMC6100_SPI_MOSI_SCL_RX_WAKE_PIN_MASK TMC6100_SPI_RX_WAKE_SCL_MOSI_PIN_MASK
#define TMC6100_SPI_MOSI_SCL_RX_PIN_MASK      TMC6100_SPI_RX_SCL_MOSI_PIN_MASK
#define TMC6100_SPI_MISO_SDA_TX_PIN_MASK      TMC6100_SPI_TX_SDA_MISO_PIN_MASK
#ifndef TMC6100_SPI_SCLK_PIN_MASK
#define TMC6100_SPI_SCLK_PIN_MASK             TMC6100_SPI_CTS_SCLK_PIN_MASK
#endif /* TMC6100_SPI_SCLK_PIN_MASK */
#ifndef TMC6100_SPI_SS0_PIN_MASK
#define TMC6100_SPI_SS0_PIN_MASK              TMC6100_SPI_RTS_SS0_PIN_MASK
#endif /* TMC6100_SPI_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_TMC6100_SPI_H) */


/* [] END OF FILE */
