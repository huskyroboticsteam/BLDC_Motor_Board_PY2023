/*******************************************************************************
* File Name: TMC6100_SPI_SCBCLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_TMC6100_SPI_SCBCLK_H)
#define CY_CLOCK_TMC6100_SPI_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void TMC6100_SPI_SCBCLK_StartEx(uint32 alignClkDiv);
#define TMC6100_SPI_SCBCLK_Start() \
    TMC6100_SPI_SCBCLK_StartEx(TMC6100_SPI_SCBCLK__PA_DIV_ID)

#else

void TMC6100_SPI_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void TMC6100_SPI_SCBCLK_Stop(void);

void TMC6100_SPI_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 TMC6100_SPI_SCBCLK_GetDividerRegister(void);
uint8  TMC6100_SPI_SCBCLK_GetFractionalDividerRegister(void);

#define TMC6100_SPI_SCBCLK_Enable()                         TMC6100_SPI_SCBCLK_Start()
#define TMC6100_SPI_SCBCLK_Disable()                        TMC6100_SPI_SCBCLK_Stop()
#define TMC6100_SPI_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    TMC6100_SPI_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define TMC6100_SPI_SCBCLK_SetDivider(clkDivider)           TMC6100_SPI_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define TMC6100_SPI_SCBCLK_SetDividerValue(clkDivider)      TMC6100_SPI_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define TMC6100_SPI_SCBCLK_DIV_ID     TMC6100_SPI_SCBCLK__DIV_ID

#define TMC6100_SPI_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define TMC6100_SPI_SCBCLK_CTRL_REG   (*(reg32 *)TMC6100_SPI_SCBCLK__CTRL_REGISTER)
#define TMC6100_SPI_SCBCLK_DIV_REG    (*(reg32 *)TMC6100_SPI_SCBCLK__DIV_REGISTER)

#define TMC6100_SPI_SCBCLK_CMD_DIV_SHIFT          (0u)
#define TMC6100_SPI_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define TMC6100_SPI_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define TMC6100_SPI_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define TMC6100_SPI_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << TMC6100_SPI_SCBCLK_CMD_DISABLE_SHIFT))
#define TMC6100_SPI_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << TMC6100_SPI_SCBCLK_CMD_ENABLE_SHIFT))

#define TMC6100_SPI_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define TMC6100_SPI_SCBCLK_DIV_FRAC_SHIFT (3u)
#define TMC6100_SPI_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define TMC6100_SPI_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define TMC6100_SPI_SCBCLK_DIV_REG        (*(reg32 *)TMC6100_SPI_SCBCLK__REGISTER)
#define TMC6100_SPI_SCBCLK_ENABLE_REG     TMC6100_SPI_SCBCLK_DIV_REG
#define TMC6100_SPI_SCBCLK_DIV_FRAC_MASK  TMC6100_SPI_SCBCLK__FRAC_MASK
#define TMC6100_SPI_SCBCLK_DIV_FRAC_SHIFT (16u)
#define TMC6100_SPI_SCBCLK_DIV_INT_MASK   TMC6100_SPI_SCBCLK__DIVIDER_MASK
#define TMC6100_SPI_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_TMC6100_SPI_SCBCLK_H) */

/* [] END OF FILE */
