/*******************************************************************************
* File Name: UL.h  
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

#if !defined(CY_PINS_UL_ALIASES_H) /* Pins UL_ALIASES_H */
#define CY_PINS_UL_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define UL_0			(UL__0__PC)
#define UL_0_PS		(UL__0__PS)
#define UL_0_PC		(UL__0__PC)
#define UL_0_DR		(UL__0__DR)
#define UL_0_SHIFT	(UL__0__SHIFT)
#define UL_0_INTR	((uint16)((uint16)0x0003u << (UL__0__SHIFT*2u)))

#define UL_INTR_ALL	 ((uint16)(UL_0_INTR))


#endif /* End Pins UL_ALIASES_H */


/* [] END OF FILE */
