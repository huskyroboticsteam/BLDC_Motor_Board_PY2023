/*******************************************************************************
* File Name: DRV_EN.h  
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

#if !defined(CY_PINS_DRV_EN_ALIASES_H) /* Pins DRV_EN_ALIASES_H */
#define CY_PINS_DRV_EN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DRV_EN_0			(DRV_EN__0__PC)
#define DRV_EN_0_PS		(DRV_EN__0__PS)
#define DRV_EN_0_PC		(DRV_EN__0__PC)
#define DRV_EN_0_DR		(DRV_EN__0__DR)
#define DRV_EN_0_SHIFT	(DRV_EN__0__SHIFT)
#define DRV_EN_0_INTR	((uint16)((uint16)0x0003u << (DRV_EN__0__SHIFT*2u)))

#define DRV_EN_INTR_ALL	 ((uint16)(DRV_EN_0_INTR))


#endif /* End Pins DRV_EN_ALIASES_H */


/* [] END OF FILE */
