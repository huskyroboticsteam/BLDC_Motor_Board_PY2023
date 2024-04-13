/*******************************************************************************
* File Name: IDRV1.h  
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

#if !defined(CY_PINS_IDRV1_H) /* Pins IDRV1_H */
#define CY_PINS_IDRV1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "IDRV1_aliases.h"


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
} IDRV1_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   IDRV1_Read(void);
void    IDRV1_Write(uint8 value);
uint8   IDRV1_ReadDataReg(void);
#if defined(IDRV1__PC) || (CY_PSOC4_4200L) 
    void    IDRV1_SetDriveMode(uint8 mode);
#endif
void    IDRV1_SetInterruptMode(uint16 position, uint16 mode);
uint8   IDRV1_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void IDRV1_Sleep(void); 
void IDRV1_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(IDRV1__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define IDRV1_DRIVE_MODE_BITS        (3)
    #define IDRV1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - IDRV1_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the IDRV1_SetDriveMode() function.
         *  @{
         */
        #define IDRV1_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define IDRV1_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define IDRV1_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define IDRV1_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define IDRV1_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define IDRV1_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define IDRV1_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define IDRV1_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define IDRV1_MASK               IDRV1__MASK
#define IDRV1_SHIFT              IDRV1__SHIFT
#define IDRV1_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IDRV1_SetInterruptMode() function.
     *  @{
     */
        #define IDRV1_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define IDRV1_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define IDRV1_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define IDRV1_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(IDRV1__SIO)
    #define IDRV1_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(IDRV1__PC) && (CY_PSOC4_4200L)
    #define IDRV1_USBIO_ENABLE               ((uint32)0x80000000u)
    #define IDRV1_USBIO_DISABLE              ((uint32)(~IDRV1_USBIO_ENABLE))
    #define IDRV1_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define IDRV1_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define IDRV1_USBIO_ENTER_SLEEP          ((uint32)((1u << IDRV1_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << IDRV1_USBIO_SUSPEND_DEL_SHIFT)))
    #define IDRV1_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << IDRV1_USBIO_SUSPEND_SHIFT)))
    #define IDRV1_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << IDRV1_USBIO_SUSPEND_DEL_SHIFT)))
    #define IDRV1_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(IDRV1__PC)
    /* Port Configuration */
    #define IDRV1_PC                 (* (reg32 *) IDRV1__PC)
#endif
/* Pin State */
#define IDRV1_PS                     (* (reg32 *) IDRV1__PS)
/* Data Register */
#define IDRV1_DR                     (* (reg32 *) IDRV1__DR)
/* Input Buffer Disable Override */
#define IDRV1_INP_DIS                (* (reg32 *) IDRV1__PC2)

/* Interrupt configuration Registers */
#define IDRV1_INTCFG                 (* (reg32 *) IDRV1__INTCFG)
#define IDRV1_INTSTAT                (* (reg32 *) IDRV1__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define IDRV1_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(IDRV1__SIO)
    #define IDRV1_SIO_REG            (* (reg32 *) IDRV1__SIO)
#endif /* (IDRV1__SIO_CFG) */

/* USBIO registers */
#if !defined(IDRV1__PC) && (CY_PSOC4_4200L)
    #define IDRV1_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define IDRV1_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define IDRV1_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define IDRV1_DRIVE_MODE_SHIFT       (0x00u)
#define IDRV1_DRIVE_MODE_MASK        (0x07u << IDRV1_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins IDRV1_H */


/* [] END OF FILE */
