/*******************************************************************************
* File Name: PIN_2.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PIN_2_H) /* Pins PIN_2_H */
#define CY_PINS_PIN_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PIN_2_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} PIN_2_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PIN_2_Read(void);
void    PIN_2_Write(uint8 value);
uint8   PIN_2_ReadDataReg(void);
#if defined(PIN_2__PC) || (CY_PSOC4_4200L) 
    void    PIN_2_SetDriveMode(uint8 mode);
#endif
void    PIN_2_SetInterruptMode(uint16 position, uint16 mode);
uint8   PIN_2_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PIN_2_Sleep(void); 
void PIN_2_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PIN_2__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PIN_2_DRIVE_MODE_BITS        (3)
    #define PIN_2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PIN_2_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PIN_2_SetDriveMode() function.
         *  @{
         */
        #define PIN_2_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PIN_2_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PIN_2_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PIN_2_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PIN_2_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PIN_2_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PIN_2_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PIN_2_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PIN_2_MASK               PIN_2__MASK
#define PIN_2_SHIFT              PIN_2__SHIFT
#define PIN_2_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PIN_2_SetInterruptMode() function.
     *  @{
     */
        #define PIN_2_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PIN_2_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PIN_2_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PIN_2_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PIN_2__SIO)
    #define PIN_2_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PIN_2__PC) && (CY_PSOC4_4200L)
    #define PIN_2_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PIN_2_USBIO_DISABLE              ((uint32)(~PIN_2_USBIO_ENABLE))
    #define PIN_2_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PIN_2_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PIN_2_USBIO_ENTER_SLEEP          ((uint32)((1u << PIN_2_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PIN_2_USBIO_SUSPEND_DEL_SHIFT)))
    #define PIN_2_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PIN_2_USBIO_SUSPEND_SHIFT)))
    #define PIN_2_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PIN_2_USBIO_SUSPEND_DEL_SHIFT)))
    #define PIN_2_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PIN_2__PC)
    /* Port Configuration */
    #define PIN_2_PC                 (* (reg32 *) PIN_2__PC)
#endif
/* Pin State */
#define PIN_2_PS                     (* (reg32 *) PIN_2__PS)
/* Data Register */
#define PIN_2_DR                     (* (reg32 *) PIN_2__DR)
/* Input Buffer Disable Override */
#define PIN_2_INP_DIS                (* (reg32 *) PIN_2__PC2)

/* Interrupt configuration Registers */
#define PIN_2_INTCFG                 (* (reg32 *) PIN_2__INTCFG)
#define PIN_2_INTSTAT                (* (reg32 *) PIN_2__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PIN_2_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PIN_2__SIO)
    #define PIN_2_SIO_REG            (* (reg32 *) PIN_2__SIO)
#endif /* (PIN_2__SIO_CFG) */

/* USBIO registers */
#if !defined(PIN_2__PC) && (CY_PSOC4_4200L)
    #define PIN_2_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PIN_2_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PIN_2_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PIN_2_DRIVE_MODE_SHIFT       (0x00u)
#define PIN_2_DRIVE_MODE_MASK        (0x07u << PIN_2_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PIN_2_H */


/* [] END OF FILE */
