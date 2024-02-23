/*******************************************************************************
* File Name: ADC_Pot_PM.c
* Version 2.50
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_Pot.h"


/***************************************
* Local data allocation
***************************************/

static ADC_Pot_BACKUP_STRUCT  ADC_Pot_backup =
{
    ADC_Pot_DISABLED,
    0u    
};


/*******************************************************************************
* Function Name: ADC_Pot_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_Pot_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_Pot_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_Pot_RestoreConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_Pot_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_Pot_backup - modified.
*
*******************************************************************************/
void ADC_Pot_Sleep(void)
{
    /* During deepsleep/ hibernate mode keep SARMUX active, i.e. do not open
    *   all switches (disconnect), to be used for ADFT
    */
    ADC_Pot_backup.dftRegVal = ADC_Pot_SAR_DFT_CTRL_REG & (uint32)~ADC_Pot_ADFT_OVERRIDE;
    ADC_Pot_SAR_DFT_CTRL_REG |= ADC_Pot_ADFT_OVERRIDE;
    if((ADC_Pot_SAR_CTRL_REG  & ADC_Pot_ENABLE) != 0u)
    {
        if((ADC_Pot_SAR_SAMPLE_CTRL_REG & ADC_Pot_CONTINUOUS_EN) != 0u)
        {
            ADC_Pot_backup.enableState = ADC_Pot_ENABLED | ADC_Pot_STARTED;
        }
        else
        {
            ADC_Pot_backup.enableState = ADC_Pot_ENABLED;
        }
        ADC_Pot_StopConvert();
        ADC_Pot_Stop();
        
        /* Disable the SAR internal pump before entering the chip low power mode */
        if((ADC_Pot_SAR_CTRL_REG & ADC_Pot_BOOSTPUMP_EN) != 0u)
        {
            ADC_Pot_SAR_CTRL_REG &= (uint32)~ADC_Pot_BOOSTPUMP_EN;
            ADC_Pot_backup.enableState |= ADC_Pot_BOOSTPUMP_ENABLED;
        }
    }
    else
    {
        ADC_Pot_backup.enableState = ADC_Pot_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_Pot_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers.
*  This should be called just after awaking from sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_Pot_backup - used.
*
*******************************************************************************/
void ADC_Pot_Wakeup(void)
{
    ADC_Pot_SAR_DFT_CTRL_REG = ADC_Pot_backup.dftRegVal;
    if(ADC_Pot_backup.enableState != ADC_Pot_DISABLED)
    {
        /* Enable the SAR internal pump  */
        if((ADC_Pot_backup.enableState & ADC_Pot_BOOSTPUMP_ENABLED) != 0u)
        {
            ADC_Pot_SAR_CTRL_REG |= ADC_Pot_BOOSTPUMP_EN;
        }
        ADC_Pot_Enable();
        if((ADC_Pot_backup.enableState & ADC_Pot_STARTED) != 0u)
        {
            ADC_Pot_StartConvert();
        }
    }
}
/* [] END OF FILE */
