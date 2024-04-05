/***************************************************************************//**
* \file TMC6100_SPI.c
* \version 4.0
*
* \brief
*  This file provides the source code to the API for the SCB Component in
*  SPI mode.
*
* Note:
*
*******************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "TMC6100_PVT.h"
#include "TMC6100_SPI_UART_PVT.h"

#if(TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Configuration Structure Initialization
    ***************************************/

    const TMC6100_SPI_INIT_STRUCT TMC6100_configSpi =
    {
        TMC6100_SPI_MODE,
        TMC6100_SPI_SUB_MODE,
        TMC6100_SPI_CLOCK_MODE,
        TMC6100_SPI_OVS_FACTOR,
        TMC6100_SPI_MEDIAN_FILTER_ENABLE,
        TMC6100_SPI_LATE_MISO_SAMPLE_ENABLE,
        TMC6100_SPI_WAKE_ENABLE,
        TMC6100_SPI_RX_DATA_BITS_NUM,
        TMC6100_SPI_TX_DATA_BITS_NUM,
        TMC6100_SPI_BITS_ORDER,
        TMC6100_SPI_TRANSFER_SEPARATION,
        0u,
        NULL,
        0u,
        NULL,
        (uint32) TMC6100_SCB_IRQ_INTERNAL,
        TMC6100_SPI_INTR_RX_MASK,
        TMC6100_SPI_RX_TRIGGER_LEVEL,
        TMC6100_SPI_INTR_TX_MASK,
        TMC6100_SPI_TX_TRIGGER_LEVEL,
        (uint8) TMC6100_SPI_BYTE_MODE_ENABLE,
        (uint8) TMC6100_SPI_FREE_RUN_SCLK_ENABLE,
        (uint8) TMC6100_SPI_SS_POLARITY
    };


    /*******************************************************************************
    * Function Name: TMC6100_SpiInit
    ****************************************************************************//**
    *
    *  Configures the TMC6100 for SPI operation.
    *
    *  This function is intended specifically to be used when the TMC6100 
    *  configuration is set to “Unconfigured TMC6100” in the customizer. 
    *  After initializing the TMC6100 in SPI mode using this function, 
    *  the component can be enabled using the TMC6100_Start() or 
    * TMC6100_Enable() function.
    *  This function uses a pointer to a structure that provides the configuration 
    *  settings. This structure contains the same information that would otherwise 
    *  be provided by the customizer settings.
    *
    *  \param config: pointer to a structure that contains the following list of 
    *   fields. These fields match the selections available in the customizer. 
    *   Refer to the customizer for further description of the settings.
    *
    *******************************************************************************/
    void TMC6100_SpiInit(const TMC6100_SPI_INIT_STRUCT *config)
    {
        if(NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due to bad function parameter */
        }
        else
        {
            /* Configure pins */
            TMC6100_SetPins(TMC6100_SCB_MODE_SPI, config->mode, TMC6100_DUMMY_PARAM);

            /* Store internal configuration */
            TMC6100_scbMode       = (uint8) TMC6100_SCB_MODE_SPI;
            TMC6100_scbEnableWake = (uint8) config->enableWake;
            TMC6100_scbEnableIntr = (uint8) config->enableInterrupt;

            /* Set RX direction internal variables */
            TMC6100_rxBuffer      =         config->rxBuffer;
            TMC6100_rxDataBits    = (uint8) config->rxDataBits;
            TMC6100_rxBufferSize  =         config->rxBufferSize;

            /* Set TX direction internal variables */
            TMC6100_txBuffer      =         config->txBuffer;
            TMC6100_txDataBits    = (uint8) config->txDataBits;
            TMC6100_txBufferSize  =         config->txBufferSize;

            /* Configure SPI interface */
            TMC6100_CTRL_REG     = TMC6100_GET_CTRL_OVS(config->oversample)           |
                                            TMC6100_GET_CTRL_BYTE_MODE(config->enableByteMode) |
                                            TMC6100_GET_CTRL_EC_AM_MODE(config->enableWake)    |
                                            TMC6100_CTRL_SPI;

            TMC6100_SPI_CTRL_REG = TMC6100_GET_SPI_CTRL_CONTINUOUS    (config->transferSeperation)  |
                                            TMC6100_GET_SPI_CTRL_SELECT_PRECEDE(config->submode &
                                                                          TMC6100_SPI_MODE_TI_PRECEDES_MASK) |
                                            TMC6100_GET_SPI_CTRL_SCLK_MODE     (config->sclkMode)            |
                                            TMC6100_GET_SPI_CTRL_LATE_MISO_SAMPLE(config->enableLateSampling)|
                                            TMC6100_GET_SPI_CTRL_SCLK_CONTINUOUS(config->enableFreeRunSclk)  |
                                            TMC6100_GET_SPI_CTRL_SSEL_POLARITY (config->polaritySs)          |
                                            TMC6100_GET_SPI_CTRL_SUB_MODE      (config->submode)             |
                                            TMC6100_GET_SPI_CTRL_MASTER_MODE   (config->mode);

            /* Configure RX direction */
            TMC6100_RX_CTRL_REG     =  TMC6100_GET_RX_CTRL_DATA_WIDTH(config->rxDataBits)         |
                                                TMC6100_GET_RX_CTRL_BIT_ORDER (config->bitOrder)           |
                                                TMC6100_GET_RX_CTRL_MEDIAN    (config->enableMedianFilter) |
                                                TMC6100_SPI_RX_CTRL;

            TMC6100_RX_FIFO_CTRL_REG = TMC6100_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(config->rxTriggerLevel);

            /* Configure TX direction */
            TMC6100_TX_CTRL_REG      = TMC6100_GET_TX_CTRL_DATA_WIDTH(config->txDataBits) |
                                                TMC6100_GET_TX_CTRL_BIT_ORDER (config->bitOrder)   |
                                                TMC6100_SPI_TX_CTRL;

            TMC6100_TX_FIFO_CTRL_REG = TMC6100_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(config->txTriggerLevel);

            /* Configure interrupt with SPI handler but do not enable it */
            CyIntDisable    (TMC6100_ISR_NUMBER);
            CyIntSetPriority(TMC6100_ISR_NUMBER, TMC6100_ISR_PRIORITY);
            (void) CyIntSetVector(TMC6100_ISR_NUMBER, &TMC6100_SPI_UART_ISR);

            /* Configure interrupt sources */
            TMC6100_INTR_I2C_EC_MASK_REG = TMC6100_NO_INTR_SOURCES;
            TMC6100_INTR_SPI_EC_MASK_REG = TMC6100_NO_INTR_SOURCES;
            TMC6100_INTR_SLAVE_MASK_REG  = TMC6100_GET_SPI_INTR_SLAVE_MASK(config->rxInterruptMask);
            TMC6100_INTR_MASTER_MASK_REG = TMC6100_GET_SPI_INTR_MASTER_MASK(config->txInterruptMask);
            TMC6100_INTR_RX_MASK_REG     = TMC6100_GET_SPI_INTR_RX_MASK(config->rxInterruptMask);
            TMC6100_INTR_TX_MASK_REG     = TMC6100_GET_SPI_INTR_TX_MASK(config->txInterruptMask);
            
            /* Configure TX interrupt sources to restore. */
            TMC6100_IntrTxMask = LO16(TMC6100_INTR_TX_MASK_REG);

            /* Set active SS0 */
            TMC6100_SpiSetActiveSlaveSelect(TMC6100_SPI_SLAVE_SELECT0);

            /* Clear RX buffer indexes */
            TMC6100_rxBufferHead     = 0u;
            TMC6100_rxBufferTail     = 0u;
            TMC6100_rxBufferOverflow = 0u;

            /* Clear TX buffer indexes */
            TMC6100_txBufferHead = 0u;
            TMC6100_txBufferTail = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: TMC6100_SpiInit
    ****************************************************************************//**
    *
    *  Configures the SCB for the SPI operation.
    *
    *******************************************************************************/
    void TMC6100_SpiInit(void)
    {
        /* Configure SPI interface */
        TMC6100_CTRL_REG     = TMC6100_SPI_DEFAULT_CTRL;
        TMC6100_SPI_CTRL_REG = TMC6100_SPI_DEFAULT_SPI_CTRL;

        /* Configure TX and RX direction */
        TMC6100_RX_CTRL_REG      = TMC6100_SPI_DEFAULT_RX_CTRL;
        TMC6100_RX_FIFO_CTRL_REG = TMC6100_SPI_DEFAULT_RX_FIFO_CTRL;

        /* Configure TX and RX direction */
        TMC6100_TX_CTRL_REG      = TMC6100_SPI_DEFAULT_TX_CTRL;
        TMC6100_TX_FIFO_CTRL_REG = TMC6100_SPI_DEFAULT_TX_FIFO_CTRL;

        /* Configure interrupt with SPI handler but do not enable it */
    #if(TMC6100_SCB_IRQ_INTERNAL)
            CyIntDisable    (TMC6100_ISR_NUMBER);
            CyIntSetPriority(TMC6100_ISR_NUMBER, TMC6100_ISR_PRIORITY);
            (void) CyIntSetVector(TMC6100_ISR_NUMBER, &TMC6100_SPI_UART_ISR);
    #endif /* (TMC6100_SCB_IRQ_INTERNAL) */

        /* Configure interrupt sources */
        TMC6100_INTR_I2C_EC_MASK_REG = TMC6100_SPI_DEFAULT_INTR_I2C_EC_MASK;
        TMC6100_INTR_SPI_EC_MASK_REG = TMC6100_SPI_DEFAULT_INTR_SPI_EC_MASK;
        TMC6100_INTR_SLAVE_MASK_REG  = TMC6100_SPI_DEFAULT_INTR_SLAVE_MASK;
        TMC6100_INTR_MASTER_MASK_REG = TMC6100_SPI_DEFAULT_INTR_MASTER_MASK;
        TMC6100_INTR_RX_MASK_REG     = TMC6100_SPI_DEFAULT_INTR_RX_MASK;
        TMC6100_INTR_TX_MASK_REG     = TMC6100_SPI_DEFAULT_INTR_TX_MASK;

        /* Configure TX interrupt sources to restore. */
        TMC6100_IntrTxMask = LO16(TMC6100_INTR_TX_MASK_REG);
            
        /* Set active SS0 for master */
    #if (TMC6100_SPI_MASTER_CONST)
        TMC6100_SpiSetActiveSlaveSelect(TMC6100_SPI_SLAVE_SELECT0);
    #endif /* (TMC6100_SPI_MASTER_CONST) */

    #if(TMC6100_INTERNAL_RX_SW_BUFFER_CONST)
        TMC6100_rxBufferHead     = 0u;
        TMC6100_rxBufferTail     = 0u;
        TMC6100_rxBufferOverflow = 0u;
    #endif /* (TMC6100_INTERNAL_RX_SW_BUFFER_CONST) */

    #if(TMC6100_INTERNAL_TX_SW_BUFFER_CONST)
        TMC6100_txBufferHead = 0u;
        TMC6100_txBufferTail = 0u;
    #endif /* (TMC6100_INTERNAL_TX_SW_BUFFER_CONST) */
    }
#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: TMC6100_SpiPostEnable
****************************************************************************//**
*
*  Restores HSIOM settings for the SPI master output pins (SCLK and/or SS0-SS3) 
*  to be controlled by the SCB SPI.
*
*******************************************************************************/
void TMC6100_SpiPostEnable(void)
{
#if(TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)

    if (TMC6100_CHECK_SPI_MASTER)
    {
    #if (TMC6100_CTS_SCLK_PIN)
        /* Set SCB SPI to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_CTS_SCLK_HSIOM_REG, TMC6100_CTS_SCLK_HSIOM_MASK,
                                       TMC6100_CTS_SCLK_HSIOM_POS, TMC6100_CTS_SCLK_HSIOM_SEL_SPI);
    #endif /* (TMC6100_CTS_SCLK_PIN) */

    #if (TMC6100_RTS_SS0_PIN)
        /* Set SCB SPI to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_RTS_SS0_HSIOM_REG, TMC6100_RTS_SS0_HSIOM_MASK,
                                       TMC6100_RTS_SS0_HSIOM_POS, TMC6100_RTS_SS0_HSIOM_SEL_SPI);
    #endif /* (TMC6100_RTS_SS0_PIN) */

    #if (TMC6100_SS1_PIN)
        /* Set SCB SPI to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_SS1_HSIOM_REG, TMC6100_SS1_HSIOM_MASK,
                                       TMC6100_SS1_HSIOM_POS, TMC6100_SS1_HSIOM_SEL_SPI);
    #endif /* (TMC6100_SS1_PIN) */

    #if (TMC6100_SS2_PIN)
        /* Set SCB SPI to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_SS2_HSIOM_REG, TMC6100_SS2_HSIOM_MASK,
                                       TMC6100_SS2_HSIOM_POS, TMC6100_SS2_HSIOM_SEL_SPI);
    #endif /* (TMC6100_SS2_PIN) */

    #if (TMC6100_SS3_PIN)
        /* Set SCB SPI to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_SS3_HSIOM_REG, TMC6100_SS3_HSIOM_MASK,
                                       TMC6100_SS3_HSIOM_POS, TMC6100_SS3_HSIOM_SEL_SPI);
    #endif /* (TMC6100_SS3_PIN) */
    }

#else

    #if (TMC6100_SPI_MASTER_SCLK_PIN)
        /* Set SCB SPI to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_SCLK_M_HSIOM_REG, TMC6100_SCLK_M_HSIOM_MASK,
                                       TMC6100_SCLK_M_HSIOM_POS, TMC6100_SCLK_M_HSIOM_SEL_SPI);
    #endif /* (TMC6100_MISO_SDA_TX_PIN_PIN) */

    #if (TMC6100_SPI_MASTER_SS0_PIN)
        /* Set SCB SPI to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_SS0_M_HSIOM_REG, TMC6100_SS0_M_HSIOM_MASK,
                                       TMC6100_SS0_M_HSIOM_POS, TMC6100_SS0_M_HSIOM_SEL_SPI);
    #endif /* (TMC6100_SPI_MASTER_SS0_PIN) */

    #if (TMC6100_SPI_MASTER_SS1_PIN)
        /* Set SCB SPI to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_SS1_M_HSIOM_REG, TMC6100_SS1_M_HSIOM_MASK,
                                       TMC6100_SS1_M_HSIOM_POS, TMC6100_SS1_M_HSIOM_SEL_SPI);
    #endif /* (TMC6100_SPI_MASTER_SS1_PIN) */

    #if (TMC6100_SPI_MASTER_SS2_PIN)
        /* Set SCB SPI to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_SS2_M_HSIOM_REG, TMC6100_SS2_M_HSIOM_MASK,
                                       TMC6100_SS2_M_HSIOM_POS, TMC6100_SS2_M_HSIOM_SEL_SPI);
    #endif /* (TMC6100_SPI_MASTER_SS2_PIN) */

    #if (TMC6100_SPI_MASTER_SS3_PIN)
        /* Set SCB SPI to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_SS3_M_HSIOM_REG, TMC6100_SS3_M_HSIOM_MASK,
                                       TMC6100_SS3_M_HSIOM_POS, TMC6100_SS3_M_HSIOM_SEL_SPI);
    #endif /* (TMC6100_SPI_MASTER_SS3_PIN) */

#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Restore TX interrupt sources. */
    TMC6100_SetTxInterruptMode(TMC6100_IntrTxMask);
}


/*******************************************************************************
* Function Name: TMC6100_SpiStop
****************************************************************************//**
*
*  Changes the HSIOM settings for the SPI master output pins 
*  (SCLK and/or SS0-SS3) to keep them inactive after the block is disabled. 
*  The output pins are controlled by the GPIO data register.
*
*******************************************************************************/
void TMC6100_SpiStop(void)
{
#if(TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)

    if (TMC6100_CHECK_SPI_MASTER)
    {
    #if (TMC6100_CTS_SCLK_PIN)
        /* Set output pin state after block is disabled */
        TMC6100_uart_cts_spi_sclk_Write(TMC6100_GET_SPI_SCLK_INACTIVE);

        /* Set GPIO to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_CTS_SCLK_HSIOM_REG, TMC6100_CTS_SCLK_HSIOM_MASK,
                                       TMC6100_CTS_SCLK_HSIOM_POS, TMC6100_CTS_SCLK_HSIOM_SEL_GPIO);
    #endif /* (TMC6100_uart_cts_spi_sclk_PIN) */

    #if (TMC6100_RTS_SS0_PIN)
        /* Set output pin state after block is disabled */
        TMC6100_uart_rts_spi_ss0_Write(TMC6100_GET_SPI_SS0_INACTIVE);

        /* Set GPIO to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_RTS_SS0_HSIOM_REG, TMC6100_RTS_SS0_HSIOM_MASK,
                                       TMC6100_RTS_SS0_HSIOM_POS, TMC6100_RTS_SS0_HSIOM_SEL_GPIO);
    #endif /* (TMC6100_uart_rts_spi_ss0_PIN) */

    #if (TMC6100_SS1_PIN)
        /* Set output pin state after block is disabled */
        TMC6100_spi_ss1_Write(TMC6100_GET_SPI_SS1_INACTIVE);

        /* Set GPIO to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_SS1_HSIOM_REG, TMC6100_SS1_HSIOM_MASK,
                                       TMC6100_SS1_HSIOM_POS, TMC6100_SS1_HSIOM_SEL_GPIO);
    #endif /* (TMC6100_SS1_PIN) */

    #if (TMC6100_SS2_PIN)
        /* Set output pin state after block is disabled */
        TMC6100_spi_ss2_Write(TMC6100_GET_SPI_SS2_INACTIVE);

        /* Set GPIO to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_SS2_HSIOM_REG, TMC6100_SS2_HSIOM_MASK,
                                       TMC6100_SS2_HSIOM_POS, TMC6100_SS2_HSIOM_SEL_GPIO);
    #endif /* (TMC6100_SS2_PIN) */

    #if (TMC6100_SS3_PIN)
        /* Set output pin state after block is disabled */
        TMC6100_spi_ss3_Write(TMC6100_GET_SPI_SS3_INACTIVE);

        /* Set GPIO to drive output pin */
        TMC6100_SET_HSIOM_SEL(TMC6100_SS3_HSIOM_REG, TMC6100_SS3_HSIOM_MASK,
                                       TMC6100_SS3_HSIOM_POS, TMC6100_SS3_HSIOM_SEL_GPIO);
    #endif /* (TMC6100_SS3_PIN) */
    
        /* Store TX interrupt sources (exclude level triggered) for master. */
        TMC6100_IntrTxMask = LO16(TMC6100_GetTxInterruptMode() & TMC6100_INTR_SPIM_TX_RESTORE);
    }
    else
    {
        /* Store TX interrupt sources (exclude level triggered) for slave. */
        TMC6100_IntrTxMask = LO16(TMC6100_GetTxInterruptMode() & TMC6100_INTR_SPIS_TX_RESTORE);
    }

#else

#if (TMC6100_SPI_MASTER_SCLK_PIN)
    /* Set output pin state after block is disabled */
    TMC6100_sclk_m_Write(TMC6100_GET_SPI_SCLK_INACTIVE);

    /* Set GPIO to drive output pin */
    TMC6100_SET_HSIOM_SEL(TMC6100_SCLK_M_HSIOM_REG, TMC6100_SCLK_M_HSIOM_MASK,
                                   TMC6100_SCLK_M_HSIOM_POS, TMC6100_SCLK_M_HSIOM_SEL_GPIO);
#endif /* (TMC6100_MISO_SDA_TX_PIN_PIN) */

#if (TMC6100_SPI_MASTER_SS0_PIN)
    /* Set output pin state after block is disabled */
    TMC6100_ss0_m_Write(TMC6100_GET_SPI_SS0_INACTIVE);

    /* Set GPIO to drive output pin */
    TMC6100_SET_HSIOM_SEL(TMC6100_SS0_M_HSIOM_REG, TMC6100_SS0_M_HSIOM_MASK,
                                   TMC6100_SS0_M_HSIOM_POS, TMC6100_SS0_M_HSIOM_SEL_GPIO);
#endif /* (TMC6100_SPI_MASTER_SS0_PIN) */

#if (TMC6100_SPI_MASTER_SS1_PIN)
    /* Set output pin state after block is disabled */
    TMC6100_ss1_m_Write(TMC6100_GET_SPI_SS1_INACTIVE);

    /* Set GPIO to drive output pin */
    TMC6100_SET_HSIOM_SEL(TMC6100_SS1_M_HSIOM_REG, TMC6100_SS1_M_HSIOM_MASK,
                                   TMC6100_SS1_M_HSIOM_POS, TMC6100_SS1_M_HSIOM_SEL_GPIO);
#endif /* (TMC6100_SPI_MASTER_SS1_PIN) */

#if (TMC6100_SPI_MASTER_SS2_PIN)
    /* Set output pin state after block is disabled */
    TMC6100_ss2_m_Write(TMC6100_GET_SPI_SS2_INACTIVE);

    /* Set GPIO to drive output pin */
    TMC6100_SET_HSIOM_SEL(TMC6100_SS2_M_HSIOM_REG, TMC6100_SS2_M_HSIOM_MASK,
                                   TMC6100_SS2_M_HSIOM_POS, TMC6100_SS2_M_HSIOM_SEL_GPIO);
#endif /* (TMC6100_SPI_MASTER_SS2_PIN) */

#if (TMC6100_SPI_MASTER_SS3_PIN)
    /* Set output pin state after block is disabled */
    TMC6100_ss3_m_Write(TMC6100_GET_SPI_SS3_INACTIVE);

    /* Set GPIO to drive output pin */
    TMC6100_SET_HSIOM_SEL(TMC6100_SS3_M_HSIOM_REG, TMC6100_SS3_M_HSIOM_MASK,
                                   TMC6100_SS3_M_HSIOM_POS, TMC6100_SS3_M_HSIOM_SEL_GPIO);
#endif /* (TMC6100_SPI_MASTER_SS3_PIN) */

    #if (TMC6100_SPI_MASTER_CONST)
        /* Store TX interrupt sources (exclude level triggered). */
        TMC6100_IntrTxMask = LO16(TMC6100_GetTxInterruptMode() & TMC6100_INTR_SPIM_TX_RESTORE);
    #else
        /* Store TX interrupt sources (exclude level triggered). */
        TMC6100_IntrTxMask = LO16(TMC6100_GetTxInterruptMode() & TMC6100_INTR_SPIS_TX_RESTORE);
    #endif /* (TMC6100_SPI_MASTER_CONST) */

#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (TMC6100_SPI_MASTER_CONST)
    /*******************************************************************************
    * Function Name: TMC6100_SetActiveSlaveSelect
    ****************************************************************************//**
    *
    *  Selects one of the four slave select lines to be active during the transfer.
    *  After initialization the active slave select line is 0.
    *  The component should be in one of the following states to change the active
    *  slave select signal source correctly:
    *   - The component is disabled.
    *   - The component has completed transfer (TX FIFO is empty and the
    *     SCB_INTR_MASTER_SPI_DONE status is set).
    *
    *  This function does not check that these conditions are met.
    *  This function is only applicable to SPI Master mode of operation.
    *
    *  \param slaveSelect: slave select line which will be active while the following
    *   transfer.
    *   - TMC6100_SPI_SLAVE_SELECT0 - Slave select 0.
    *   - TMC6100_SPI_SLAVE_SELECT1 - Slave select 1.
    *   - TMC6100_SPI_SLAVE_SELECT2 - Slave select 2.
    *   - TMC6100_SPI_SLAVE_SELECT3 - Slave select 3.
    *
    *******************************************************************************/
    void TMC6100_SpiSetActiveSlaveSelect(uint32 slaveSelect)
    {
        uint32 spiCtrl;

        spiCtrl = TMC6100_SPI_CTRL_REG;

        spiCtrl &= (uint32) ~TMC6100_SPI_CTRL_SLAVE_SELECT_MASK;
        spiCtrl |= (uint32)  TMC6100_GET_SPI_CTRL_SS(slaveSelect);

        TMC6100_SPI_CTRL_REG = spiCtrl;
    }
#endif /* (TMC6100_SPI_MASTER_CONST) */


#if !(TMC6100_CY_SCBIP_V0 || TMC6100_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: TMC6100_SpiSetSlaveSelectPolarity
    ****************************************************************************//**
    *
    *  Sets active polarity for slave select line.
    *  The component should be in one of the following states to change the active
    *  slave select signal source correctly:
    *   - The component is disabled.
    *   - The component has completed transfer.
    *  
    *  This function does not check that these conditions are met.
    *
    *  \param slaveSelect: slave select line to change active polarity.
    *   - TMC6100_SPI_SLAVE_SELECT0 - Slave select 0.
    *   - TMC6100_SPI_SLAVE_SELECT1 - Slave select 1.
    *   - TMC6100_SPI_SLAVE_SELECT2 - Slave select 2.
    *   - TMC6100_SPI_SLAVE_SELECT3 - Slave select 3.
    *
    *  \param polarity: active polarity of slave select line.
    *   - TMC6100_SPI_SS_ACTIVE_LOW  - Slave select is active low.
    *   - TMC6100_SPI_SS_ACTIVE_HIGH - Slave select is active high.
    *
    *******************************************************************************/
    void TMC6100_SpiSetSlaveSelectPolarity(uint32 slaveSelect, uint32 polarity)
    {
        uint32 ssPolarity;

        /* Get position of the polarity bit associated with slave select line */
        ssPolarity = TMC6100_GET_SPI_CTRL_SSEL_POLARITY((uint32) 1u << slaveSelect);

        if (0u != polarity)
        {
            TMC6100_SPI_CTRL_REG |= (uint32)  ssPolarity;
        }
        else
        {
            TMC6100_SPI_CTRL_REG &= (uint32) ~ssPolarity;
        }
    }
#endif /* !(TMC6100_CY_SCBIP_V0 || TMC6100_CY_SCBIP_V1) */


#if(TMC6100_SPI_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: TMC6100_SpiSaveConfig
    ****************************************************************************//**
    *
    *  Clears INTR_SPI_EC.WAKE_UP and enables it. This interrupt
    *  source triggers when the master assigns the SS line and wakes up the device.
    *
    *******************************************************************************/
    void TMC6100_SpiSaveConfig(void)
    {
        /* Clear and enable SPI wakeup interrupt source */
        TMC6100_ClearSpiExtClkInterruptSource(TMC6100_INTR_SPI_EC_WAKE_UP);
        TMC6100_SetSpiExtClkInterruptMode(TMC6100_INTR_SPI_EC_WAKE_UP);
    }


    /*******************************************************************************
    * Function Name: TMC6100_SpiRestoreConfig
    ****************************************************************************//**
    *
    *  Disables the INTR_SPI_EC.WAKE_UP interrupt source. After wakeup
    *  slave does not drive the MISO line and the master receives 0xFF.
    *
    *******************************************************************************/
    void TMC6100_SpiRestoreConfig(void)
    {
        /* Disable SPI wakeup interrupt source */
        TMC6100_SetSpiExtClkInterruptMode(TMC6100_NO_INTR_SOURCES);
    }
#endif /* (TMC6100_SPI_WAKE_ENABLE_CONST) */


/* [] END OF FILE */
