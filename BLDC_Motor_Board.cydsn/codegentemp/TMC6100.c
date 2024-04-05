/***************************************************************************//**
* \file TMC6100.c
* \version 4.0
*
* \brief
*  This file provides the source code to the API for the SCB Component.
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

#if (TMC6100_SCB_MODE_I2C_INC)
    #include "TMC6100_I2C_PVT.h"
#endif /* (TMC6100_SCB_MODE_I2C_INC) */

#if (TMC6100_SCB_MODE_EZI2C_INC)
    #include "TMC6100_EZI2C_PVT.h"
#endif /* (TMC6100_SCB_MODE_EZI2C_INC) */

#if (TMC6100_SCB_MODE_SPI_INC || TMC6100_SCB_MODE_UART_INC)
    #include "TMC6100_SPI_UART_PVT.h"
#endif /* (TMC6100_SCB_MODE_SPI_INC || TMC6100_SCB_MODE_UART_INC) */


/***************************************
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for Unconfigured mode */
#if (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    uint8 TMC6100_scbMode = TMC6100_SCB_MODE_UNCONFIG;
    uint8 TMC6100_scbEnableWake;
    uint8 TMC6100_scbEnableIntr;

    /* I2C configuration variables */
    uint8 TMC6100_mode;
    uint8 TMC6100_acceptAddr;

    /* SPI/UART configuration variables */
    volatile uint8 * TMC6100_rxBuffer;
    uint8  TMC6100_rxDataBits;
    uint32 TMC6100_rxBufferSize;

    volatile uint8 * TMC6100_txBuffer;
    uint8  TMC6100_txDataBits;
    uint32 TMC6100_txBufferSize;

    /* EZI2C configuration variables */
    uint8 TMC6100_numberOfAddr;
    uint8 TMC6100_subAddrSize;
#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/
/**
* \addtogroup group_general
* \{
*/

/** TMC6100_initVar indicates whether the TMC6100 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time SCB_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the TMC6100_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  TMC6100_Init() function can be called before the 
*  TMC6100_Start() or TMC6100_Enable() function.
*/
uint8 TMC6100_initVar = 0u;


#if (! (TMC6100_SCB_MODE_I2C_CONST_CFG || \
        TMC6100_SCB_MODE_EZI2C_CONST_CFG))
    /** This global variable stores TX interrupt sources after 
    * TMC6100_Stop() is called. Only these TX interrupt sources 
    * will be restored on a subsequent TMC6100_Enable() call.
    */
    uint16 TMC6100_IntrTxMask = 0u;
#endif /* (! (TMC6100_SCB_MODE_I2C_CONST_CFG || \
              TMC6100_SCB_MODE_EZI2C_CONST_CFG)) */
/** \} globals */

#if (TMC6100_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_TMC6100_CUSTOM_INTR_HANDLER)
    void (*TMC6100_customIntrHandler)(void) = NULL;
#endif /* !defined (CY_REMOVE_TMC6100_CUSTOM_INTR_HANDLER) */
#endif /* (TMC6100_SCB_IRQ_INTERNAL) */


/***************************************
*    Private Function Prototypes
***************************************/

static void TMC6100_ScbEnableIntr(void);
static void TMC6100_ScbModeStop(void);
static void TMC6100_ScbModePostEnable(void);


/*******************************************************************************
* Function Name: TMC6100_Init
****************************************************************************//**
*
*  Initializes the TMC6100 component to operate in one of the selected
*  configurations: I2C, SPI, UART or EZI2C.
*  When the configuration is set to "Unconfigured SCB", this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  TMC6100_I2CInit, TMC6100_SpiInit, 
*  TMC6100_UartInit or TMC6100_EzI2CInit.
*
*******************************************************************************/
void TMC6100_Init(void)
{
#if (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)
    if (TMC6100_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        TMC6100_initVar = 0u;
    }
    else
    {
        /* Initialization was done before this function call */
    }

#elif (TMC6100_SCB_MODE_I2C_CONST_CFG)
    TMC6100_I2CInit();

#elif (TMC6100_SCB_MODE_SPI_CONST_CFG)
    TMC6100_SpiInit();

#elif (TMC6100_SCB_MODE_UART_CONST_CFG)
    TMC6100_UartInit();

#elif (TMC6100_SCB_MODE_EZI2C_CONST_CFG)
    TMC6100_EzI2CInit();

#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: TMC6100_Enable
****************************************************************************//**
*
*  Enables TMC6100 component operation: activates the hardware and 
*  internal interrupt. It also restores TX interrupt sources disabled after the 
*  TMC6100_Stop() function was called (note that level-triggered TX 
*  interrupt sources remain disabled to not cause code lock-up).
*  For I2C and EZI2C modes the interrupt is internal and mandatory for 
*  operation. For SPI and UART modes the interrupt can be configured as none, 
*  internal or external.
*  The TMC6100 configuration should be not changed when the component
*  is enabled. Any configuration changes should be made after disabling the 
*  component.
*  When configuration is set to “Unconfigured TMC6100”, the component 
*  must first be initialized to operate in one of the following configurations: 
*  I2C, SPI, UART or EZ I2C, using the mode-specific initialization API. 
*  Otherwise this function does not enable the component.
*
*******************************************************************************/
void TMC6100_Enable(void)
{
#if (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if (!TMC6100_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        TMC6100_CTRL_REG |= TMC6100_CTRL_ENABLED;

        TMC6100_ScbEnableIntr();

        /* Call PostEnable function specific to current operation mode */
        TMC6100_ScbModePostEnable();
    }
#else
    TMC6100_CTRL_REG |= TMC6100_CTRL_ENABLED;

    TMC6100_ScbEnableIntr();

    /* Call PostEnable function specific to current operation mode */
    TMC6100_ScbModePostEnable();
#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: TMC6100_Start
****************************************************************************//**
*
*  Invokes TMC6100_Init() and TMC6100_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to "Unconfigured SCB", the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZI2C. Otherwise this function does not enable the component.
*
* \globalvars
*  TMC6100_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void TMC6100_Start(void)
{
    if (0u == TMC6100_initVar)
    {
        TMC6100_Init();
        TMC6100_initVar = 1u; /* Component was initialized */
    }

    TMC6100_Enable();
}


/*******************************************************************************
* Function Name: TMC6100_Stop
****************************************************************************//**
*
*  Disables the TMC6100 component: disable the hardware and internal 
*  interrupt. It also disables all TX interrupt sources so as not to cause an 
*  unexpected interrupt trigger because after the component is enabled, the 
*  TX FIFO is empty.
*  Refer to the function TMC6100_Enable() for the interrupt 
*  configuration details.
*  This function disables the SCB component without checking to see if 
*  communication is in progress. Before calling this function it may be 
*  necessary to check the status of communication to make sure communication 
*  is complete. If this is not done then communication could be stopped mid 
*  byte and corrupted data could result.
*
*******************************************************************************/
void TMC6100_Stop(void)
{
#if (TMC6100_SCB_IRQ_INTERNAL)
    TMC6100_DisableInt();
#endif /* (TMC6100_SCB_IRQ_INTERNAL) */

    /* Call Stop function specific to current operation mode */
    TMC6100_ScbModeStop();

    /* Disable SCB IP */
    TMC6100_CTRL_REG &= (uint32) ~TMC6100_CTRL_ENABLED;

    /* Disable all TX interrupt sources so as not to cause an unexpected
    * interrupt trigger after the component will be enabled because the 
    * TX FIFO is empty.
    * For SCB IP v0, it is critical as it does not mask-out interrupt
    * sources when it is disabled. This can cause a code lock-up in the
    * interrupt handler because TX FIFO cannot be loaded after the block
    * is disabled.
    */
    TMC6100_SetTxInterruptMode(TMC6100_NO_INTR_SOURCES);

#if (TMC6100_SCB_IRQ_INTERNAL)
    TMC6100_ClearPendingInt();
#endif /* (TMC6100_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: TMC6100_SetRxFifoLevel
****************************************************************************//**
*
*  Sets level in the RX FIFO to generate a RX level interrupt.
*  When the RX FIFO has more entries than the RX FIFO level an RX level
*  interrupt request is generated.
*
*  \param level: Level in the RX FIFO to generate RX level interrupt.
*   The range of valid level values is between 0 and RX FIFO depth - 1.
*
*******************************************************************************/
void TMC6100_SetRxFifoLevel(uint32 level)
{
    uint32 rxFifoCtrl;

    rxFifoCtrl = TMC6100_RX_FIFO_CTRL_REG;

    rxFifoCtrl &= ((uint32) ~TMC6100_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    rxFifoCtrl |= ((uint32) (TMC6100_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    TMC6100_RX_FIFO_CTRL_REG = rxFifoCtrl;
}


/*******************************************************************************
* Function Name: TMC6100_SetTxFifoLevel
****************************************************************************//**
*
*  Sets level in the TX FIFO to generate a TX level interrupt.
*  When the TX FIFO has less entries than the TX FIFO level an TX level
*  interrupt request is generated.
*
*  \param level: Level in the TX FIFO to generate TX level interrupt.
*   The range of valid level values is between 0 and TX FIFO depth - 1.
*
*******************************************************************************/
void TMC6100_SetTxFifoLevel(uint32 level)
{
    uint32 txFifoCtrl;

    txFifoCtrl = TMC6100_TX_FIFO_CTRL_REG;

    txFifoCtrl &= ((uint32) ~TMC6100_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    txFifoCtrl |= ((uint32) (TMC6100_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    TMC6100_TX_FIFO_CTRL_REG = txFifoCtrl;
}


#if (TMC6100_SCB_IRQ_INTERNAL)
    /*******************************************************************************
    * Function Name: TMC6100_SetCustomInterruptHandler
    ****************************************************************************//**
    *
    *  Registers a function to be called by the internal interrupt handler.
    *  First the function that is registered is called, then the internal interrupt
    *  handler performs any operation such as software buffer management functions
    *  before the interrupt returns.  It is the user's responsibility not to break
    *  the software buffer operations. Only one custom handler is supported, which
    *  is the function provided by the most recent call.
    *  At the initialization time no custom handler is registered.
    *
    *  \param func: Pointer to the function to register.
    *        The value NULL indicates to remove the current custom interrupt
    *        handler.
    *
    *******************************************************************************/
    void TMC6100_SetCustomInterruptHandler(void (*func)(void))
    {
    #if !defined (CY_REMOVE_TMC6100_CUSTOM_INTR_HANDLER)
        TMC6100_customIntrHandler = func; /* Register interrupt handler */
    #else
        if (NULL != func)
        {
            /* Suppress compiler warning */
        }
    #endif /* !defined (CY_REMOVE_TMC6100_CUSTOM_INTR_HANDLER) */
    }
#endif /* (TMC6100_SCB_IRQ_INTERNAL) */


/*******************************************************************************
* Function Name: TMC6100_ScbModeEnableIntr
****************************************************************************//**
*
*  Enables an interrupt for a specific mode.
*
*******************************************************************************/
static void TMC6100_ScbEnableIntr(void)
{
#if (TMC6100_SCB_IRQ_INTERNAL)
    /* Enable interrupt in NVIC */
    #if (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)
        if (0u != TMC6100_scbEnableIntr)
        {
            TMC6100_EnableInt();
        }

    #else
        TMC6100_EnableInt();

    #endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (TMC6100_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: TMC6100_ScbModePostEnable
****************************************************************************//**
*
*  Calls the PostEnable function for a specific operation mode.
*
*******************************************************************************/
static void TMC6100_ScbModePostEnable(void)
{
#if (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)
#if (!TMC6100_CY_SCBIP_V1)
    if (TMC6100_SCB_MODE_SPI_RUNTM_CFG)
    {
        TMC6100_SpiPostEnable();
    }
    else if (TMC6100_SCB_MODE_UART_RUNTM_CFG)
    {
        TMC6100_UartPostEnable();
    }
    else
    {
        /* Unknown mode: do nothing */
    }
#endif /* (!TMC6100_CY_SCBIP_V1) */

#elif (TMC6100_SCB_MODE_SPI_CONST_CFG)
    TMC6100_SpiPostEnable();

#elif (TMC6100_SCB_MODE_UART_CONST_CFG)
    TMC6100_UartPostEnable();

#else
    /* Unknown mode: do nothing */
#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: TMC6100_ScbModeStop
****************************************************************************//**
*
*  Calls the Stop function for a specific operation mode.
*
*******************************************************************************/
static void TMC6100_ScbModeStop(void)
{
#if (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)
    if (TMC6100_SCB_MODE_I2C_RUNTM_CFG)
    {
        TMC6100_I2CStop();
    }
    else if (TMC6100_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        TMC6100_EzI2CStop();
    }
#if (!TMC6100_CY_SCBIP_V1)
    else if (TMC6100_SCB_MODE_SPI_RUNTM_CFG)
    {
        TMC6100_SpiStop();
    }
    else if (TMC6100_SCB_MODE_UART_RUNTM_CFG)
    {
        TMC6100_UartStop();
    }
#endif /* (!TMC6100_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
#elif (TMC6100_SCB_MODE_I2C_CONST_CFG)
    TMC6100_I2CStop();

#elif (TMC6100_SCB_MODE_EZI2C_CONST_CFG)
    TMC6100_EzI2CStop();

#elif (TMC6100_SCB_MODE_SPI_CONST_CFG)
    TMC6100_SpiStop();

#elif (TMC6100_SCB_MODE_UART_CONST_CFG)
    TMC6100_UartStop();

#else
    /* Unknown mode: do nothing */
#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: TMC6100_SetPins
    ****************************************************************************//**
    *
    *  Sets the pins settings accordingly to the selected operation mode.
    *  Only available in the Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when a specific mode of operation
    *  is selected in design time.
    *
    *  \param mode:      Mode of SCB operation.
    *  \param subMode:   Sub-mode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  \param uartEnableMask: enables TX or RX direction and RTS and CTS signals.
    *
    *******************************************************************************/
    void TMC6100_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask)
    {
        uint32 pinsDm[TMC6100_SCB_PINS_NUMBER];
        uint32 i;
        
    #if (!TMC6100_CY_SCBIP_V1)
        uint32 pinsInBuf = 0u;
    #endif /* (!TMC6100_CY_SCBIP_V1) */
        
        uint32 hsiomSel[TMC6100_SCB_PINS_NUMBER] = 
        {
            TMC6100_RX_SCL_MOSI_HSIOM_SEL_GPIO,
            TMC6100_TX_SDA_MISO_HSIOM_SEL_GPIO,
            0u,
            0u,
            0u,
            0u,
            0u,
        };

    #if (TMC6100_CY_SCBIP_V1)
        /* Supress compiler warning. */
        if ((0u == subMode) || (0u == uartEnableMask))
        {
        }
    #endif /* (TMC6100_CY_SCBIP_V1) */

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for (i = 0u; i < TMC6100_SCB_PINS_NUMBER; i++)
        {
            pinsDm[i] = TMC6100_PIN_DM_ALG_HIZ;
        }

        if ((TMC6100_SCB_MODE_I2C   == mode) ||
            (TMC6100_SCB_MODE_EZI2C == mode))
        {
        #if (TMC6100_RX_SCL_MOSI_PIN)
            hsiomSel[TMC6100_RX_SCL_MOSI_PIN_INDEX] = TMC6100_RX_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [TMC6100_RX_SCL_MOSI_PIN_INDEX] = TMC6100_PIN_DM_OD_LO;
        #elif (TMC6100_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[TMC6100_RX_WAKE_SCL_MOSI_PIN_INDEX] = TMC6100_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [TMC6100_RX_WAKE_SCL_MOSI_PIN_INDEX] = TMC6100_PIN_DM_OD_LO;
        #else
        #endif /* (TMC6100_RX_SCL_MOSI_PIN) */
        
        #if (TMC6100_TX_SDA_MISO_PIN)
            hsiomSel[TMC6100_TX_SDA_MISO_PIN_INDEX] = TMC6100_TX_SDA_MISO_HSIOM_SEL_I2C;
            pinsDm  [TMC6100_TX_SDA_MISO_PIN_INDEX] = TMC6100_PIN_DM_OD_LO;
        #endif /* (TMC6100_TX_SDA_MISO_PIN) */
        }
    #if (!TMC6100_CY_SCBIP_V1)
        else if (TMC6100_SCB_MODE_SPI == mode)
        {
        #if (TMC6100_RX_SCL_MOSI_PIN)
            hsiomSel[TMC6100_RX_SCL_MOSI_PIN_INDEX] = TMC6100_RX_SCL_MOSI_HSIOM_SEL_SPI;
        #elif (TMC6100_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[TMC6100_RX_WAKE_SCL_MOSI_PIN_INDEX] = TMC6100_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI;
        #else
        #endif /* (TMC6100_RX_SCL_MOSI_PIN) */
        
        #if (TMC6100_TX_SDA_MISO_PIN)
            hsiomSel[TMC6100_TX_SDA_MISO_PIN_INDEX] = TMC6100_TX_SDA_MISO_HSIOM_SEL_SPI;
        #endif /* (TMC6100_TX_SDA_MISO_PIN) */
        
        #if (TMC6100_CTS_SCLK_PIN)
            hsiomSel[TMC6100_CTS_SCLK_PIN_INDEX] = TMC6100_CTS_SCLK_HSIOM_SEL_SPI;
        #endif /* (TMC6100_CTS_SCLK_PIN) */

            if (TMC6100_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[TMC6100_RX_SCL_MOSI_PIN_INDEX] = TMC6100_PIN_DM_DIG_HIZ;
                pinsDm[TMC6100_TX_SDA_MISO_PIN_INDEX] = TMC6100_PIN_DM_STRONG;
                pinsDm[TMC6100_CTS_SCLK_PIN_INDEX] = TMC6100_PIN_DM_DIG_HIZ;

            #if (TMC6100_RTS_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[TMC6100_RTS_SS0_PIN_INDEX] = TMC6100_RTS_SS0_HSIOM_SEL_SPI;
                pinsDm  [TMC6100_RTS_SS0_PIN_INDEX] = TMC6100_PIN_DM_DIG_HIZ;
            #endif /* (TMC6100_RTS_SS0_PIN) */

            #if (TMC6100_TX_SDA_MISO_PIN)
                /* Disable input buffer */
                 pinsInBuf |= TMC6100_TX_SDA_MISO_PIN_MASK;
            #endif /* (TMC6100_TX_SDA_MISO_PIN) */
            }
            else 
            {
                /* (Master) */
                pinsDm[TMC6100_RX_SCL_MOSI_PIN_INDEX] = TMC6100_PIN_DM_STRONG;
                pinsDm[TMC6100_TX_SDA_MISO_PIN_INDEX] = TMC6100_PIN_DM_DIG_HIZ;
                pinsDm[TMC6100_CTS_SCLK_PIN_INDEX] = TMC6100_PIN_DM_STRONG;

            #if (TMC6100_RTS_SS0_PIN)
                hsiomSel [TMC6100_RTS_SS0_PIN_INDEX] = TMC6100_RTS_SS0_HSIOM_SEL_SPI;
                pinsDm   [TMC6100_RTS_SS0_PIN_INDEX] = TMC6100_PIN_DM_STRONG;
                pinsInBuf |= TMC6100_RTS_SS0_PIN_MASK;
            #endif /* (TMC6100_RTS_SS0_PIN) */

            #if (TMC6100_SS1_PIN)
                hsiomSel [TMC6100_SS1_PIN_INDEX] = TMC6100_SS1_HSIOM_SEL_SPI;
                pinsDm   [TMC6100_SS1_PIN_INDEX] = TMC6100_PIN_DM_STRONG;
                pinsInBuf |= TMC6100_SS1_PIN_MASK;
            #endif /* (TMC6100_SS1_PIN) */

            #if (TMC6100_SS2_PIN)
                hsiomSel [TMC6100_SS2_PIN_INDEX] = TMC6100_SS2_HSIOM_SEL_SPI;
                pinsDm   [TMC6100_SS2_PIN_INDEX] = TMC6100_PIN_DM_STRONG;
                pinsInBuf |= TMC6100_SS2_PIN_MASK;
            #endif /* (TMC6100_SS2_PIN) */

            #if (TMC6100_SS3_PIN)
                hsiomSel [TMC6100_SS3_PIN_INDEX] = TMC6100_SS3_HSIOM_SEL_SPI;
                pinsDm   [TMC6100_SS3_PIN_INDEX] = TMC6100_PIN_DM_STRONG;
                pinsInBuf |= TMC6100_SS3_PIN_MASK;
            #endif /* (TMC6100_SS3_PIN) */

                /* Disable input buffers */
            #if (TMC6100_RX_SCL_MOSI_PIN)
                pinsInBuf |= TMC6100_RX_SCL_MOSI_PIN_MASK;
            #elif (TMC6100_RX_WAKE_SCL_MOSI_PIN)
                pinsInBuf |= TMC6100_RX_WAKE_SCL_MOSI_PIN_MASK;
            #else
            #endif /* (TMC6100_RX_SCL_MOSI_PIN) */

            #if (TMC6100_CTS_SCLK_PIN)
                pinsInBuf |= TMC6100_CTS_SCLK_PIN_MASK;
            #endif /* (TMC6100_CTS_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if (TMC6100_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
            #if (TMC6100_TX_SDA_MISO_PIN)
                hsiomSel[TMC6100_TX_SDA_MISO_PIN_INDEX] = TMC6100_TX_SDA_MISO_HSIOM_SEL_UART;
                pinsDm  [TMC6100_TX_SDA_MISO_PIN_INDEX] = TMC6100_PIN_DM_OD_LO;
            #endif /* (TMC6100_TX_SDA_MISO_PIN) */
            }
            else /* Standard or IrDA */
            {
                if (0u != (TMC6100_UART_RX_PIN_ENABLE & uartEnableMask))
                {
                #if (TMC6100_RX_SCL_MOSI_PIN)
                    hsiomSel[TMC6100_RX_SCL_MOSI_PIN_INDEX] = TMC6100_RX_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [TMC6100_RX_SCL_MOSI_PIN_INDEX] = TMC6100_PIN_DM_DIG_HIZ;
                #elif (TMC6100_RX_WAKE_SCL_MOSI_PIN)
                    hsiomSel[TMC6100_RX_WAKE_SCL_MOSI_PIN_INDEX] = TMC6100_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [TMC6100_RX_WAKE_SCL_MOSI_PIN_INDEX] = TMC6100_PIN_DM_DIG_HIZ;
                #else
                #endif /* (TMC6100_RX_SCL_MOSI_PIN) */
                }

                if (0u != (TMC6100_UART_TX_PIN_ENABLE & uartEnableMask))
                {
                #if (TMC6100_TX_SDA_MISO_PIN)
                    hsiomSel[TMC6100_TX_SDA_MISO_PIN_INDEX] = TMC6100_TX_SDA_MISO_HSIOM_SEL_UART;
                    pinsDm  [TMC6100_TX_SDA_MISO_PIN_INDEX] = TMC6100_PIN_DM_STRONG;
                    
                    /* Disable input buffer */
                    pinsInBuf |= TMC6100_TX_SDA_MISO_PIN_MASK;
                #endif /* (TMC6100_TX_SDA_MISO_PIN) */
                }

            #if !(TMC6100_CY_SCBIP_V0 || TMC6100_CY_SCBIP_V1)
                if (TMC6100_UART_MODE_STD == subMode)
                {
                    if (0u != (TMC6100_UART_CTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* CTS input is multiplexed with SCLK */
                    #if (TMC6100_CTS_SCLK_PIN)
                        hsiomSel[TMC6100_CTS_SCLK_PIN_INDEX] = TMC6100_CTS_SCLK_HSIOM_SEL_UART;
                        pinsDm  [TMC6100_CTS_SCLK_PIN_INDEX] = TMC6100_PIN_DM_DIG_HIZ;
                    #endif /* (TMC6100_CTS_SCLK_PIN) */
                    }

                    if (0u != (TMC6100_UART_RTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* RTS output is multiplexed with SS0 */
                    #if (TMC6100_RTS_SS0_PIN)
                        hsiomSel[TMC6100_RTS_SS0_PIN_INDEX] = TMC6100_RTS_SS0_HSIOM_SEL_UART;
                        pinsDm  [TMC6100_RTS_SS0_PIN_INDEX] = TMC6100_PIN_DM_STRONG;
                        
                        /* Disable input buffer */
                        pinsInBuf |= TMC6100_RTS_SS0_PIN_MASK;
                    #endif /* (TMC6100_RTS_SS0_PIN) */
                    }
                }
            #endif /* !(TMC6100_CY_SCBIP_V0 || TMC6100_CY_SCBIP_V1) */
            }
        }
    #endif /* (!TMC6100_CY_SCBIP_V1) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settings do not effect the pin output if HSIOM is other than GPIO */

    #if (TMC6100_RX_SCL_MOSI_PIN)
        TMC6100_SET_HSIOM_SEL(TMC6100_RX_SCL_MOSI_HSIOM_REG,
                                       TMC6100_RX_SCL_MOSI_HSIOM_MASK,
                                       TMC6100_RX_SCL_MOSI_HSIOM_POS,
                                        hsiomSel[TMC6100_RX_SCL_MOSI_PIN_INDEX]);

        TMC6100_uart_rx_i2c_scl_spi_mosi_SetDriveMode((uint8) pinsDm[TMC6100_RX_SCL_MOSI_PIN_INDEX]);

        #if (!TMC6100_CY_SCBIP_V1)
            TMC6100_SET_INP_DIS(TMC6100_uart_rx_i2c_scl_spi_mosi_INP_DIS,
                                         TMC6100_uart_rx_i2c_scl_spi_mosi_MASK,
                                         (0u != (pinsInBuf & TMC6100_RX_SCL_MOSI_PIN_MASK)));
        #endif /* (!TMC6100_CY_SCBIP_V1) */
    
    #elif (TMC6100_RX_WAKE_SCL_MOSI_PIN)
        TMC6100_SET_HSIOM_SEL(TMC6100_RX_WAKE_SCL_MOSI_HSIOM_REG,
                                       TMC6100_RX_WAKE_SCL_MOSI_HSIOM_MASK,
                                       TMC6100_RX_WAKE_SCL_MOSI_HSIOM_POS,
                                       hsiomSel[TMC6100_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        TMC6100_uart_rx_wake_i2c_scl_spi_mosi_SetDriveMode((uint8)
                                                               pinsDm[TMC6100_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        TMC6100_SET_INP_DIS(TMC6100_uart_rx_wake_i2c_scl_spi_mosi_INP_DIS,
                                     TMC6100_uart_rx_wake_i2c_scl_spi_mosi_MASK,
                                     (0u != (pinsInBuf & TMC6100_RX_WAKE_SCL_MOSI_PIN_MASK)));

         /* Set interrupt on falling edge */
        TMC6100_SET_INCFG_TYPE(TMC6100_RX_WAKE_SCL_MOSI_INTCFG_REG,
                                        TMC6100_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK,
                                        TMC6100_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS,
                                        TMC6100_INTCFG_TYPE_FALLING_EDGE);
    #else
    #endif /* (TMC6100_RX_WAKE_SCL_MOSI_PIN) */

    #if (TMC6100_TX_SDA_MISO_PIN)
        TMC6100_SET_HSIOM_SEL(TMC6100_TX_SDA_MISO_HSIOM_REG,
                                       TMC6100_TX_SDA_MISO_HSIOM_MASK,
                                       TMC6100_TX_SDA_MISO_HSIOM_POS,
                                        hsiomSel[TMC6100_TX_SDA_MISO_PIN_INDEX]);

        TMC6100_uart_tx_i2c_sda_spi_miso_SetDriveMode((uint8) pinsDm[TMC6100_TX_SDA_MISO_PIN_INDEX]);

    #if (!TMC6100_CY_SCBIP_V1)
        TMC6100_SET_INP_DIS(TMC6100_uart_tx_i2c_sda_spi_miso_INP_DIS,
                                     TMC6100_uart_tx_i2c_sda_spi_miso_MASK,
                                    (0u != (pinsInBuf & TMC6100_TX_SDA_MISO_PIN_MASK)));
    #endif /* (!TMC6100_CY_SCBIP_V1) */
    #endif /* (TMC6100_RX_SCL_MOSI_PIN) */

    #if (TMC6100_CTS_SCLK_PIN)
        TMC6100_SET_HSIOM_SEL(TMC6100_CTS_SCLK_HSIOM_REG,
                                       TMC6100_CTS_SCLK_HSIOM_MASK,
                                       TMC6100_CTS_SCLK_HSIOM_POS,
                                       hsiomSel[TMC6100_CTS_SCLK_PIN_INDEX]);

        TMC6100_uart_cts_spi_sclk_SetDriveMode((uint8) pinsDm[TMC6100_CTS_SCLK_PIN_INDEX]);

        TMC6100_SET_INP_DIS(TMC6100_uart_cts_spi_sclk_INP_DIS,
                                     TMC6100_uart_cts_spi_sclk_MASK,
                                     (0u != (pinsInBuf & TMC6100_CTS_SCLK_PIN_MASK)));
    #endif /* (TMC6100_CTS_SCLK_PIN) */

    #if (TMC6100_RTS_SS0_PIN)
        TMC6100_SET_HSIOM_SEL(TMC6100_RTS_SS0_HSIOM_REG,
                                       TMC6100_RTS_SS0_HSIOM_MASK,
                                       TMC6100_RTS_SS0_HSIOM_POS,
                                       hsiomSel[TMC6100_RTS_SS0_PIN_INDEX]);

        TMC6100_uart_rts_spi_ss0_SetDriveMode((uint8) pinsDm[TMC6100_RTS_SS0_PIN_INDEX]);

        TMC6100_SET_INP_DIS(TMC6100_uart_rts_spi_ss0_INP_DIS,
                                     TMC6100_uart_rts_spi_ss0_MASK,
                                     (0u != (pinsInBuf & TMC6100_RTS_SS0_PIN_MASK)));
    #endif /* (TMC6100_RTS_SS0_PIN) */

    #if (TMC6100_SS1_PIN)
        TMC6100_SET_HSIOM_SEL(TMC6100_SS1_HSIOM_REG,
                                       TMC6100_SS1_HSIOM_MASK,
                                       TMC6100_SS1_HSIOM_POS,
                                       hsiomSel[TMC6100_SS1_PIN_INDEX]);

        TMC6100_spi_ss1_SetDriveMode((uint8) pinsDm[TMC6100_SS1_PIN_INDEX]);

        TMC6100_SET_INP_DIS(TMC6100_spi_ss1_INP_DIS,
                                     TMC6100_spi_ss1_MASK,
                                     (0u != (pinsInBuf & TMC6100_SS1_PIN_MASK)));
    #endif /* (TMC6100_SS1_PIN) */

    #if (TMC6100_SS2_PIN)
        TMC6100_SET_HSIOM_SEL(TMC6100_SS2_HSIOM_REG,
                                       TMC6100_SS2_HSIOM_MASK,
                                       TMC6100_SS2_HSIOM_POS,
                                       hsiomSel[TMC6100_SS2_PIN_INDEX]);

        TMC6100_spi_ss2_SetDriveMode((uint8) pinsDm[TMC6100_SS2_PIN_INDEX]);

        TMC6100_SET_INP_DIS(TMC6100_spi_ss2_INP_DIS,
                                     TMC6100_spi_ss2_MASK,
                                     (0u != (pinsInBuf & TMC6100_SS2_PIN_MASK)));
    #endif /* (TMC6100_SS2_PIN) */

    #if (TMC6100_SS3_PIN)
        TMC6100_SET_HSIOM_SEL(TMC6100_SS3_HSIOM_REG,
                                       TMC6100_SS3_HSIOM_MASK,
                                       TMC6100_SS3_HSIOM_POS,
                                       hsiomSel[TMC6100_SS3_PIN_INDEX]);

        TMC6100_spi_ss3_SetDriveMode((uint8) pinsDm[TMC6100_SS3_PIN_INDEX]);

        TMC6100_SET_INP_DIS(TMC6100_spi_ss3_INP_DIS,
                                     TMC6100_spi_ss3_MASK,
                                     (0u != (pinsInBuf & TMC6100_SS3_PIN_MASK)));
    #endif /* (TMC6100_SS3_PIN) */
    }

#endif /* (TMC6100_SCB_MODE_UNCONFIG_CONST_CFG) */


#if (TMC6100_CY_SCBIP_V0 || TMC6100_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: TMC6100_I2CSlaveNackGeneration
    ****************************************************************************//**
    *
    *  Sets command to generate NACK to the address or data.
    *
    *******************************************************************************/
    void TMC6100_I2CSlaveNackGeneration(void)
    {
        /* Check for EC_AM toggle condition: EC_AM and clock stretching for address are enabled */
        if ((0u != (TMC6100_CTRL_REG & TMC6100_CTRL_EC_AM_MODE)) &&
            (0u == (TMC6100_I2C_CTRL_REG & TMC6100_I2C_CTRL_S_NOT_READY_ADDR_NACK)))
        {
            /* Toggle EC_AM before NACK generation */
            TMC6100_CTRL_REG &= ~TMC6100_CTRL_EC_AM_MODE;
            TMC6100_CTRL_REG |=  TMC6100_CTRL_EC_AM_MODE;
        }

        TMC6100_I2C_SLAVE_CMD_REG = TMC6100_I2C_SLAVE_CMD_S_NACK;
    }
#endif /* (TMC6100_CY_SCBIP_V0 || TMC6100_CY_SCBIP_V1) */


/* [] END OF FILE */
