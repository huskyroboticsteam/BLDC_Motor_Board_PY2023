/*******************************************************************************
* File Name: WH.h  
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

#if !defined(CY_PINS_WH_H) /* Pins WH_H */
#define CY_PINS_WH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "WH_aliases.h"


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
} WH_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   WH_Read(void);
void    WH_Write(uint8 value);
uint8   WH_ReadDataReg(void);
#if defined(WH__PC) || (CY_PSOC4_4200L) 
    void    WH_SetDriveMode(uint8 mode);
#endif
void    WH_SetInterruptMode(uint16 position, uint16 mode);
uint8   WH_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void WH_Sleep(void); 
void WH_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(WH__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define WH_DRIVE_MODE_BITS        (3)
    #define WH_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - WH_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the WH_SetDriveMode() function.
         *  @{
         */
        #define WH_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define WH_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define WH_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define WH_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define WH_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define WH_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define WH_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define WH_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define WH_MASK               WH__MASK
#define WH_SHIFT              WH__SHIFT
#define WH_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in WH_SetInterruptMode() function.
     *  @{
     */
        #define WH_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define WH_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define WH_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define WH_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(WH__SIO)
    #define WH_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(WH__PC) && (CY_PSOC4_4200L)
    #define WH_USBIO_ENABLE               ((uint32)0x80000000u)
    #define WH_USBIO_DISABLE              ((uint32)(~WH_USBIO_ENABLE))
    #define WH_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define WH_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define WH_USBIO_ENTER_SLEEP          ((uint32)((1u << WH_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << WH_USBIO_SUSPEND_DEL_SHIFT)))
    #define WH_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << WH_USBIO_SUSPEND_SHIFT)))
    #define WH_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << WH_USBIO_SUSPEND_DEL_SHIFT)))
    #define WH_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(WH__PC)
    /* Port Configuration */
    #define WH_PC                 (* (reg32 *) WH__PC)
#endif
/* Pin State */
#define WH_PS                     (* (reg32 *) WH__PS)
/* Data Register */
#define WH_DR                     (* (reg32 *) WH__DR)
/* Input Buffer Disable Override */
#define WH_INP_DIS                (* (reg32 *) WH__PC2)

/* Interrupt configuration Registers */
#define WH_INTCFG                 (* (reg32 *) WH__INTCFG)
#define WH_INTSTAT                (* (reg32 *) WH__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define WH_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(WH__SIO)
    #define WH_SIO_REG            (* (reg32 *) WH__SIO)
#endif /* (WH__SIO_CFG) */

/* USBIO registers */
#if !defined(WH__PC) && (CY_PSOC4_4200L)
    #define WH_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define WH_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define WH_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define WH_DRIVE_MODE_SHIFT       (0x00u)
#define WH_DRIVE_MODE_MASK        (0x07u << WH_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins WH_H */


/* [] END OF FILE */
