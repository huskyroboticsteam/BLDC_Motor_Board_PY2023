/*******************************************************************************
* File Name: WL.h  
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

#if !defined(CY_PINS_WL_ALIASES_H) /* Pins WL_ALIASES_H */
#define CY_PINS_WL_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define WL_0			(WL__0__PC)
#define WL_0_PS		(WL__0__PS)
#define WL_0_PC		(WL__0__PC)
#define WL_0_DR		(WL__0__DR)
#define WL_0_SHIFT	(WL__0__SHIFT)
#define WL_0_INTR	((uint16)((uint16)0x0003u << (WL__0__SHIFT*2u)))

#define WL_INTR_ALL	 ((uint16)(WL_0_INTR))


#endif /* End Pins WL_ALIASES_H */


/* [] END OF FILE */
