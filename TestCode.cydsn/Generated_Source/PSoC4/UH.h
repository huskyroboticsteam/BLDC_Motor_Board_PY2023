/*******************************************************************************
* File Name: UH.h  
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

#if !defined(CY_PINS_UH_H) /* Pins UH_H */
#define CY_PINS_UH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "UH_aliases.h"


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
} UH_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   UH_Read(void);
void    UH_Write(uint8 value);
uint8   UH_ReadDataReg(void);
#if defined(UH__PC) || (CY_PSOC4_4200L) 
    void    UH_SetDriveMode(uint8 mode);
#endif
void    UH_SetInterruptMode(uint16 position, uint16 mode);
uint8   UH_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void UH_Sleep(void); 
void UH_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(UH__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define UH_DRIVE_MODE_BITS        (3)
    #define UH_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - UH_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the UH_SetDriveMode() function.
         *  @{
         */
        #define UH_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define UH_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define UH_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define UH_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define UH_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define UH_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define UH_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define UH_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define UH_MASK               UH__MASK
#define UH_SHIFT              UH__SHIFT
#define UH_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in UH_SetInterruptMode() function.
     *  @{
     */
        #define UH_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define UH_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define UH_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define UH_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(UH__SIO)
    #define UH_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(UH__PC) && (CY_PSOC4_4200L)
    #define UH_USBIO_ENABLE               ((uint32)0x80000000u)
    #define UH_USBIO_DISABLE              ((uint32)(~UH_USBIO_ENABLE))
    #define UH_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define UH_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define UH_USBIO_ENTER_SLEEP          ((uint32)((1u << UH_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << UH_USBIO_SUSPEND_DEL_SHIFT)))
    #define UH_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << UH_USBIO_SUSPEND_SHIFT)))
    #define UH_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << UH_USBIO_SUSPEND_DEL_SHIFT)))
    #define UH_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(UH__PC)
    /* Port Configuration */
    #define UH_PC                 (* (reg32 *) UH__PC)
#endif
/* Pin State */
#define UH_PS                     (* (reg32 *) UH__PS)
/* Data Register */
#define UH_DR                     (* (reg32 *) UH__DR)
/* Input Buffer Disable Override */
#define UH_INP_DIS                (* (reg32 *) UH__PC2)

/* Interrupt configuration Registers */
#define UH_INTCFG                 (* (reg32 *) UH__INTCFG)
#define UH_INTSTAT                (* (reg32 *) UH__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define UH_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(UH__SIO)
    #define UH_SIO_REG            (* (reg32 *) UH__SIO)
#endif /* (UH__SIO_CFG) */

/* USBIO registers */
#if !defined(UH__PC) && (CY_PSOC4_4200L)
    #define UH_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define UH_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define UH_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define UH_DRIVE_MODE_SHIFT       (0x00u)
#define UH_DRIVE_MODE_MASK        (0x07u << UH_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins UH_H */


/* [] END OF FILE */
