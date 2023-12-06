/*******************************************************************************
* File Name: LEDReg_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "LEDReg.h"

/* Check for removal by optimization */
#if !defined(LEDReg_Sync_ctrl_reg__REMOVED)

static LEDReg_BACKUP_STRUCT  LEDReg_backup = {0u};

    
/*******************************************************************************
* Function Name: LEDReg_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LEDReg_SaveConfig(void) 
{
    LEDReg_backup.controlState = LEDReg_Control;
}


/*******************************************************************************
* Function Name: LEDReg_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void LEDReg_RestoreConfig(void) 
{
     LEDReg_Control = LEDReg_backup.controlState;
}


/*******************************************************************************
* Function Name: LEDReg_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LEDReg_Sleep(void) 
{
    LEDReg_SaveConfig();
}


/*******************************************************************************
* Function Name: LEDReg_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LEDReg_Wakeup(void)  
{
    LEDReg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
