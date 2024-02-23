/*******************************************************************************
* File Name: Timer_general_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_general.h"

static Timer_general_backupStruct Timer_general_backup;


/*******************************************************************************
* Function Name: Timer_general_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_general_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_general_SaveConfig(void) 
{
    #if (!Timer_general_UsingFixedFunction)
        Timer_general_backup.TimerUdb = Timer_general_ReadCounter();
        Timer_general_backup.InterruptMaskValue = Timer_general_STATUS_MASK;
        #if (Timer_general_UsingHWCaptureCounter)
            Timer_general_backup.TimerCaptureCounter = Timer_general_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_general_UDB_CONTROL_REG_REMOVED)
            Timer_general_backup.TimerControlRegister = Timer_general_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_general_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_general_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_general_RestoreConfig(void) 
{   
    #if (!Timer_general_UsingFixedFunction)

        Timer_general_WriteCounter(Timer_general_backup.TimerUdb);
        Timer_general_STATUS_MASK =Timer_general_backup.InterruptMaskValue;
        #if (Timer_general_UsingHWCaptureCounter)
            Timer_general_SetCaptureCount(Timer_general_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_general_UDB_CONTROL_REG_REMOVED)
            Timer_general_WriteControlRegister(Timer_general_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_general_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_general_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_general_Sleep(void) 
{
    #if(!Timer_general_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_general_CTRL_ENABLE == (Timer_general_CONTROL & Timer_general_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_general_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_general_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_general_Stop();
    Timer_general_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_general_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_general_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_general_Wakeup(void) 
{
    Timer_general_RestoreConfig();
    #if(!Timer_general_UDB_CONTROL_REG_REMOVED)
        if(Timer_general_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_general_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
