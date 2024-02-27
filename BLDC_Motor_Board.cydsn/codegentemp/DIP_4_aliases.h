/*******************************************************************************
* File Name: DIP_4.h  
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

#if !defined(CY_PINS_DIP_4_ALIASES_H) /* Pins DIP_4_ALIASES_H */
#define CY_PINS_DIP_4_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DIP_4_0			(DIP_4__0__PC)
#define DIP_4_0_PS		(DIP_4__0__PS)
#define DIP_4_0_PC		(DIP_4__0__PC)
#define DIP_4_0_DR		(DIP_4__0__DR)
#define DIP_4_0_SHIFT	(DIP_4__0__SHIFT)
#define DIP_4_0_INTR	((uint16)((uint16)0x0003u << (DIP_4__0__SHIFT*2u)))

#define DIP_4_INTR_ALL	 ((uint16)(DIP_4_0_INTR))


#endif /* End Pins DIP_4_ALIASES_H */


/* [] END OF FILE */
