/*******************************************************************************
* File Name: WL.h  
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

#if !defined(CY_PINS_WL_H) /* Pins WL_H */
#define CY_PINS_WL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "WL_aliases.h"


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
} WL_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   WL_Read(void);
void    WL_Write(uint8 value);
uint8   WL_ReadDataReg(void);
#if defined(WL__PC) || (CY_PSOC4_4200L) 
    void    WL_SetDriveMode(uint8 mode);
#endif
void    WL_SetInterruptMode(uint16 position, uint16 mode);
uint8   WL_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void WL_Sleep(void); 
void WL_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(WL__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define WL_DRIVE_MODE_BITS        (3)
    #define WL_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - WL_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the WL_SetDriveMode() function.
         *  @{
         */
        #define WL_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define WL_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define WL_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define WL_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define WL_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define WL_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define WL_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define WL_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define WL_MASK               WL__MASK
#define WL_SHIFT              WL__SHIFT
#define WL_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in WL_SetInterruptMode() function.
     *  @{
     */
        #define WL_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define WL_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define WL_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define WL_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(WL__SIO)
    #define WL_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(WL__PC) && (CY_PSOC4_4200L)
    #define WL_USBIO_ENABLE               ((uint32)0x80000000u)
    #define WL_USBIO_DISABLE              ((uint32)(~WL_USBIO_ENABLE))
    #define WL_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define WL_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define WL_USBIO_ENTER_SLEEP          ((uint32)((1u << WL_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << WL_USBIO_SUSPEND_DEL_SHIFT)))
    #define WL_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << WL_USBIO_SUSPEND_SHIFT)))
    #define WL_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << WL_USBIO_SUSPEND_DEL_SHIFT)))
    #define WL_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(WL__PC)
    /* Port Configuration */
    #define WL_PC                 (* (reg32 *) WL__PC)
#endif
/* Pin State */
#define WL_PS                     (* (reg32 *) WL__PS)
/* Data Register */
#define WL_DR                     (* (reg32 *) WL__DR)
/* Input Buffer Disable Override */
#define WL_INP_DIS                (* (reg32 *) WL__PC2)

/* Interrupt configuration Registers */
#define WL_INTCFG                 (* (reg32 *) WL__INTCFG)
#define WL_INTSTAT                (* (reg32 *) WL__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define WL_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(WL__SIO)
    #define WL_SIO_REG            (* (reg32 *) WL__SIO)
#endif /* (WL__SIO_CFG) */

/* USBIO registers */
#if !defined(WL__PC) && (CY_PSOC4_4200L)
    #define WL_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define WL_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define WL_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define WL_DRIVE_MODE_SHIFT       (0x00u)
#define WL_DRIVE_MODE_MASK        (0x07u << WL_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins WL_H */


/* [] END OF FILE */
