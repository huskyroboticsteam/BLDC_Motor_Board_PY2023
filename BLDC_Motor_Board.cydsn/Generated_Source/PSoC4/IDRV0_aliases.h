/*******************************************************************************
* File Name: IDRV0.h  
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

#if !defined(CY_PINS_IDRV0_ALIASES_H) /* Pins IDRV0_ALIASES_H */
#define CY_PINS_IDRV0_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define IDRV0_0			(IDRV0__0__PC)
#define IDRV0_0_PS		(IDRV0__0__PS)
#define IDRV0_0_PC		(IDRV0__0__PC)
#define IDRV0_0_DR		(IDRV0__0__DR)
#define IDRV0_0_SHIFT	(IDRV0__0__SHIFT)
#define IDRV0_0_INTR	((uint16)((uint16)0x0003u << (IDRV0__0__SHIFT*2u)))

#define IDRV0_INTR_ALL	 ((uint16)(IDRV0_0_INTR))


#endif /* End Pins IDRV0_ALIASES_H */


/* [] END OF FILE */
