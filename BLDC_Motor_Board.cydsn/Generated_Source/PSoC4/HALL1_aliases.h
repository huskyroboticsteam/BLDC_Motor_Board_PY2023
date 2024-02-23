/*******************************************************************************
* File Name: HALL1.h  
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

#if !defined(CY_PINS_HALL1_ALIASES_H) /* Pins HALL1_ALIASES_H */
#define CY_PINS_HALL1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define HALL1_0			(HALL1__0__PC)
#define HALL1_0_PS		(HALL1__0__PS)
#define HALL1_0_PC		(HALL1__0__PC)
#define HALL1_0_DR		(HALL1__0__DR)
#define HALL1_0_SHIFT	(HALL1__0__SHIFT)
#define HALL1_0_INTR	((uint16)((uint16)0x0003u << (HALL1__0__SHIFT*2u)))

#define HALL1_INTR_ALL	 ((uint16)(HALL1_0_INTR))


#endif /* End Pins HALL1_ALIASES_H */


/* [] END OF FILE */
