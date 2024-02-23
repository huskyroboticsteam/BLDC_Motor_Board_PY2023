/*******************************************************************************
* File Name: Current_Sensor_I2C_SCBCLK.h
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

#if !defined(CY_CLOCK_Current_Sensor_I2C_SCBCLK_H)
#define CY_CLOCK_Current_Sensor_I2C_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Current_Sensor_I2C_SCBCLK_StartEx(uint32 alignClkDiv);
#define Current_Sensor_I2C_SCBCLK_Start() \
    Current_Sensor_I2C_SCBCLK_StartEx(Current_Sensor_I2C_SCBCLK__PA_DIV_ID)

#else

void Current_Sensor_I2C_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Current_Sensor_I2C_SCBCLK_Stop(void);

void Current_Sensor_I2C_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Current_Sensor_I2C_SCBCLK_GetDividerRegister(void);
uint8  Current_Sensor_I2C_SCBCLK_GetFractionalDividerRegister(void);

#define Current_Sensor_I2C_SCBCLK_Enable()                         Current_Sensor_I2C_SCBCLK_Start()
#define Current_Sensor_I2C_SCBCLK_Disable()                        Current_Sensor_I2C_SCBCLK_Stop()
#define Current_Sensor_I2C_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    Current_Sensor_I2C_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define Current_Sensor_I2C_SCBCLK_SetDivider(clkDivider)           Current_Sensor_I2C_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define Current_Sensor_I2C_SCBCLK_SetDividerValue(clkDivider)      Current_Sensor_I2C_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Current_Sensor_I2C_SCBCLK_DIV_ID     Current_Sensor_I2C_SCBCLK__DIV_ID

#define Current_Sensor_I2C_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Current_Sensor_I2C_SCBCLK_CTRL_REG   (*(reg32 *)Current_Sensor_I2C_SCBCLK__CTRL_REGISTER)
#define Current_Sensor_I2C_SCBCLK_DIV_REG    (*(reg32 *)Current_Sensor_I2C_SCBCLK__DIV_REGISTER)

#define Current_Sensor_I2C_SCBCLK_CMD_DIV_SHIFT          (0u)
#define Current_Sensor_I2C_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define Current_Sensor_I2C_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define Current_Sensor_I2C_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define Current_Sensor_I2C_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Current_Sensor_I2C_SCBCLK_CMD_DISABLE_SHIFT))
#define Current_Sensor_I2C_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Current_Sensor_I2C_SCBCLK_CMD_ENABLE_SHIFT))

#define Current_Sensor_I2C_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define Current_Sensor_I2C_SCBCLK_DIV_FRAC_SHIFT (3u)
#define Current_Sensor_I2C_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define Current_Sensor_I2C_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define Current_Sensor_I2C_SCBCLK_DIV_REG        (*(reg32 *)Current_Sensor_I2C_SCBCLK__REGISTER)
#define Current_Sensor_I2C_SCBCLK_ENABLE_REG     Current_Sensor_I2C_SCBCLK_DIV_REG
#define Current_Sensor_I2C_SCBCLK_DIV_FRAC_MASK  Current_Sensor_I2C_SCBCLK__FRAC_MASK
#define Current_Sensor_I2C_SCBCLK_DIV_FRAC_SHIFT (16u)
#define Current_Sensor_I2C_SCBCLK_DIV_INT_MASK   Current_Sensor_I2C_SCBCLK__DIVIDER_MASK
#define Current_Sensor_I2C_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Current_Sensor_I2C_SCBCLK_H) */

/* [] END OF FILE */
