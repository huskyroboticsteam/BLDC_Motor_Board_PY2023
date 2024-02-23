/*******************************************************************************
* File Name: WH.h  
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

#if !defined(CY_PINS_WH_ALIASES_H) /* Pins WH_ALIASES_H */
#define CY_PINS_WH_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define WH_0			(WH__0__PC)
#define WH_0_PS		(WH__0__PS)
#define WH_0_PC		(WH__0__PC)
#define WH_0_DR		(WH__0__DR)
#define WH_0_SHIFT	(WH__0__SHIFT)
#define WH_0_INTR	((uint16)((uint16)0x0003u << (WH__0__SHIFT*2u)))

#define WH_INTR_ALL	 ((uint16)(WH_0_INTR))


#endif /* End Pins WH_ALIASES_H */


/* [] END OF FILE */
