/*******************************************************************************
* File Name: IDRV1.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_IDRV1_ALIASES_H) /* Pins IDRV1_ALIASES_H */
#define CY_PINS_IDRV1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define IDRV1_0			(IDRV1__0__PC)
#define IDRV1_0_PS		(IDRV1__0__PS)
#define IDRV1_0_PC		(IDRV1__0__PC)
#define IDRV1_0_DR		(IDRV1__0__DR)
#define IDRV1_0_SHIFT	(IDRV1__0__SHIFT)
#define IDRV1_0_INTR	((uint16)((uint16)0x0003u << (IDRV1__0__SHIFT*2u)))

#define IDRV1_INTR_ALL	 ((uint16)(IDRV1_0_INTR))


#endif /* End Pins IDRV1_ALIASES_H */


/* [] END OF FILE */
