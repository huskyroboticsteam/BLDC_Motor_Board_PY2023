/*******************************************************************************
* File Name: TMC6100_SPI_mosi_s.c  
* Version 2.20
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "TMC6100_SPI_mosi_s.h"


#if defined(TMC6100_SPI_mosi_s__PC)
    #define TMC6100_SPI_mosi_s_SetP4PinDriveMode(shift, mode)  \
    do { \
        TMC6100_SPI_mosi_s_PC =   (TMC6100_SPI_mosi_s_PC & \
                                (uint32)(~(uint32)(TMC6100_SPI_mosi_s_DRIVE_MODE_IND_MASK << \
                                (TMC6100_SPI_mosi_s_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << \
                                (TMC6100_SPI_mosi_s_DRIVE_MODE_BITS * (shift))); \
    } while (0)
#else
    #if (CY_PSOC4_4200L)
        #define TMC6100_SPI_mosi_s_SetP4PinDriveMode(shift, mode)  \
        do { \
            TMC6100_SPI_mosi_s_USBIO_CTRL_REG = (TMC6100_SPI_mosi_s_USBIO_CTRL_REG & \
                                    (uint32)(~(uint32)(TMC6100_SPI_mosi_s_DRIVE_MODE_IND_MASK << \
                                    (TMC6100_SPI_mosi_s_DRIVE_MODE_BITS * (shift))))) | \
                                    (uint32)((uint32)(mode) << \
                                    (TMC6100_SPI_mosi_s_DRIVE_MODE_BITS * (shift))); \
        } while (0)
    #endif
#endif
  

#if defined(TMC6100_SPI_mosi_s__PC) || (CY_PSOC4_4200L) 
    /*******************************************************************************
    * Function Name: TMC6100_SPI_mosi_s_SetDriveMode
    ****************************************************************************//**
    *
    * \brief Sets the drive mode for each of the Pins component's pins.
    * 
    * <b>Note</b> This affects all pins in the Pins component instance. Use the
    * Per-Pin APIs if you wish to control individual pin's drive modes.
    *
    * <b>Note</b> USBIOs have limited drive functionality. Refer to the Drive Mode
    * parameter for more information.
    *
    * \param mode
    *  Mode for the selected signals. Valid options are documented in 
    *  \ref driveMode.
    *
    * \return
    *  None
    *
    * \sideeffect
    *  If you use read-modify-write operations that are not atomic, the ISR can
    *  cause corruption of this function. An ISR that interrupts this function 
    *  and performs writes to the Pins component Drive Mode registers can cause 
    *  corrupted port data. To avoid this issue, you should either use the Per-Pin
    *  APIs (primary method) or disable interrupts around this function.
    *
    * \funcusage
    *  \snippet TMC6100_SPI_mosi_s_SUT.c usage_TMC6100_SPI_mosi_s_SetDriveMode
    *******************************************************************************/
    void TMC6100_SPI_mosi_s_SetDriveMode(uint8 mode)
    {
		TMC6100_SPI_mosi_s_SetP4PinDriveMode(TMC6100_SPI_mosi_s__0__SHIFT, mode);
    }
#endif


/*******************************************************************************
* Function Name: TMC6100_SPI_mosi_s_Write
****************************************************************************//**
*
* \brief Writes the value to the physical port (data output register), masking
*  and shifting the bits appropriately. 
*
* The data output register controls the signal applied to the physical pin in 
* conjunction with the drive mode parameter. This function avoids changing 
* other bits in the port by using the appropriate method (read-modify-write or
* bit banding).
*
* <b>Note</b> This function should not be used on a hardware digital output pin 
* as it is driven by the hardware signal attached to it.
*
* \param value
*  Value to write to the component instance.
*
* \return 
*  None 
*
* \sideeffect
*  If you use read-modify-write operations that are not atomic; the Interrupt 
*  Service Routines (ISR) can cause corruption of this function. An ISR that 
*  interrupts this function and performs writes to the Pins component data 
*  register can cause corrupted port data. To avoid this issue, you should 
*  either use the Per-Pin APIs (primary method) or disable interrupts around 
*  this function.
*
* \funcusage
*  \snippet TMC6100_SPI_mosi_s_SUT.c usage_TMC6100_SPI_mosi_s_Write
*******************************************************************************/
void TMC6100_SPI_mosi_s_Write(uint8 value)
{
    uint8 drVal = (uint8)(TMC6100_SPI_mosi_s_DR & (uint8)(~TMC6100_SPI_mosi_s_MASK));
    drVal = (drVal | ((uint8)(value << TMC6100_SPI_mosi_s_SHIFT) & TMC6100_SPI_mosi_s_MASK));
    TMC6100_SPI_mosi_s_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: TMC6100_SPI_mosi_s_Read
****************************************************************************//**
*
* \brief Reads the associated physical port (pin status register) and masks 
*  the required bits according to the width and bit position of the component
*  instance. 
*
* The pin's status register returns the current logic level present on the 
* physical pin.
*
* \return 
*  The current value for the pins in the component as a right justified number.
*
* \funcusage
*  \snippet TMC6100_SPI_mosi_s_SUT.c usage_TMC6100_SPI_mosi_s_Read  
*******************************************************************************/
uint8 TMC6100_SPI_mosi_s_Read(void)
{
    return (uint8)((TMC6100_SPI_mosi_s_PS & TMC6100_SPI_mosi_s_MASK) >> TMC6100_SPI_mosi_s_SHIFT);
}


/*******************************************************************************
* Function Name: TMC6100_SPI_mosi_s_ReadDataReg
****************************************************************************//**
*
* \brief Reads the associated physical port's data output register and masks 
*  the correct bits according to the width and bit position of the component 
*  instance. 
*
* The data output register controls the signal applied to the physical pin in 
* conjunction with the drive mode parameter. This is not the same as the 
* preferred TMC6100_SPI_mosi_s_Read() API because the 
* TMC6100_SPI_mosi_s_ReadDataReg() reads the data register instead of the status 
* register. For output pins this is a useful function to determine the value 
* just written to the pin.
*
* \return 
*  The current value of the data register masked and shifted into a right 
*  justified number for the component instance.
*
* \funcusage
*  \snippet TMC6100_SPI_mosi_s_SUT.c usage_TMC6100_SPI_mosi_s_ReadDataReg 
*******************************************************************************/
uint8 TMC6100_SPI_mosi_s_ReadDataReg(void)
{
    return (uint8)((TMC6100_SPI_mosi_s_DR & TMC6100_SPI_mosi_s_MASK) >> TMC6100_SPI_mosi_s_SHIFT);
}


/*******************************************************************************
* Function Name: TMC6100_SPI_mosi_s_SetInterruptMode
****************************************************************************//**
*
* \brief Configures the interrupt mode for each of the Pins component's
*  pins. Alternatively you may set the interrupt mode for all the pins
*  specified in the Pins component.
*
*  <b>Note</b> The interrupt is port-wide and therefore any enabled pin
*  interrupt may trigger it.
*
* \param position
*  The pin position as listed in the Pins component. You may OR these to be 
*  able to configure the interrupt mode of multiple pins within a Pins 
*  component. Or you may use TMC6100_SPI_mosi_s_INTR_ALL to configure the
*  interrupt mode of all the pins in the Pins component.       
*  - TMC6100_SPI_mosi_s_0_INTR       (First pin in the list)
*  - TMC6100_SPI_mosi_s_1_INTR       (Second pin in the list)
*  - ...
*  - TMC6100_SPI_mosi_s_INTR_ALL     (All pins in Pins component)
*
* \param mode
*  Interrupt mode for the selected pins. Valid options are documented in
*  \ref intrMode.
*
* \return 
*  None
*  
* \sideeffect
*  It is recommended that the interrupt be disabled before calling this 
*  function to avoid unintended interrupt requests. Note that the interrupt
*  type is port wide, and therefore will trigger for any enabled pin on the 
*  port.
*
* \funcusage
*  \snippet TMC6100_SPI_mosi_s_SUT.c usage_TMC6100_SPI_mosi_s_SetInterruptMode
*******************************************************************************/
void TMC6100_SPI_mosi_s_SetInterruptMode(uint16 position, uint16 mode)
{
    uint32 intrCfg;
    
    intrCfg =  TMC6100_SPI_mosi_s_INTCFG & (uint32)(~(uint32)position);
    TMC6100_SPI_mosi_s_INTCFG = intrCfg | ((uint32)position & (uint32)mode);
}


/*******************************************************************************
* Function Name: TMC6100_SPI_mosi_s_ClearInterrupt
****************************************************************************//**
*
* \brief Clears any active interrupts attached with the component and returns 
*  the value of the interrupt status register allowing determination of which
*  pins generated an interrupt event.
*
* \return 
*  The right-shifted current value of the interrupt status register. Each pin 
*  has one bit set if it generated an interrupt event. For example, bit 0 is 
*  for pin 0 and bit 1 is for pin 1 of the Pins component.
*  
* \sideeffect
*  Clears all bits of the physical port's interrupt status register, not just
*  those associated with the Pins component.
*
* \funcusage
*  \snippet TMC6100_SPI_mosi_s_SUT.c usage_TMC6100_SPI_mosi_s_ClearInterrupt
*******************************************************************************/
uint8 TMC6100_SPI_mosi_s_ClearInterrupt(void)
{
	uint8 maskedStatus = (uint8)(TMC6100_SPI_mosi_s_INTSTAT & TMC6100_SPI_mosi_s_MASK);
	TMC6100_SPI_mosi_s_INTSTAT = maskedStatus;
    return maskedStatus >> TMC6100_SPI_mosi_s_SHIFT;
}


/* [] END OF FILE */
