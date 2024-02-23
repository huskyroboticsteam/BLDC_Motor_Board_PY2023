/*******************************************************************************
* File Name: HALL3.h  
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

#if !defined(CY_PINS_HALL3_ALIASES_H) /* Pins HALL3_ALIASES_H */
#define CY_PINS_HALL3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define HALL3_0			(HALL3__0__PC)
#define HALL3_0_PS		(HALL3__0__PS)
#define HALL3_0_PC		(HALL3__0__PC)
#define HALL3_0_DR		(HALL3__0__DR)
#define HALL3_0_SHIFT	(HALL3__0__SHIFT)
#define HALL3_0_INTR	((uint16)((uint16)0x0003u << (HALL3__0__SHIFT*2u)))

#define HALL3_INTR_ALL	 ((uint16)(HALL3_0_INTR))


#endif /* End Pins HALL3_ALIASES_H */


/* [] END OF FILE */
