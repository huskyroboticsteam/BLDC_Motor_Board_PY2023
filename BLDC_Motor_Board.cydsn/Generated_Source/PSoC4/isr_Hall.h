/*******************************************************************************
* File Name: isr_Hall.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_isr_Hall_H)
#define CY_ISR_isr_Hall_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_Hall_Start(void);
void isr_Hall_StartEx(cyisraddress address);
void isr_Hall_Stop(void);

CY_ISR_PROTO(isr_Hall_Interrupt);

void isr_Hall_SetVector(cyisraddress address);
cyisraddress isr_Hall_GetVector(void);

void isr_Hall_SetPriority(uint8 priority);
uint8 isr_Hall_GetPriority(void);

void isr_Hall_Enable(void);
uint8 isr_Hall_GetState(void);
void isr_Hall_Disable(void);

void isr_Hall_SetPending(void);
void isr_Hall_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_Hall ISR. */
#define isr_Hall_INTC_VECTOR            ((reg32 *) isr_Hall__INTC_VECT)

/* Address of the isr_Hall ISR priority. */
#define isr_Hall_INTC_PRIOR             ((reg32 *) isr_Hall__INTC_PRIOR_REG)

/* Priority of the isr_Hall interrupt. */
#define isr_Hall_INTC_PRIOR_NUMBER      isr_Hall__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_Hall interrupt. */
#define isr_Hall_INTC_SET_EN            ((reg32 *) isr_Hall__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_Hall interrupt. */
#define isr_Hall_INTC_CLR_EN            ((reg32 *) isr_Hall__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_Hall interrupt state to pending. */
#define isr_Hall_INTC_SET_PD            ((reg32 *) isr_Hall__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_Hall interrupt. */
#define isr_Hall_INTC_CLR_PD            ((reg32 *) isr_Hall__INTC_CLR_PD_REG)



#endif /* CY_ISR_isr_Hall_H */


/* [] END OF FILE */
