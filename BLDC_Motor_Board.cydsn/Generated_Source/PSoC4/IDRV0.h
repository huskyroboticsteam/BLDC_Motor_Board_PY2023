/*******************************************************************************
* File Name: IDRV0.h  
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

#if !defined(CY_PINS_IDRV0_H) /* Pins IDRV0_H */
#define CY_PINS_IDRV0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "IDRV0_aliases.h"


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
} IDRV0_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   IDRV0_Read(void);
void    IDRV0_Write(uint8 value);
uint8   IDRV0_ReadDataReg(void);
#if defined(IDRV0__PC) || (CY_PSOC4_4200L) 
    void    IDRV0_SetDriveMode(uint8 mode);
#endif
void    IDRV0_SetInterruptMode(uint16 position, uint16 mode);
uint8   IDRV0_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void IDRV0_Sleep(void); 
void IDRV0_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(IDRV0__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define IDRV0_DRIVE_MODE_BITS        (3)
    #define IDRV0_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - IDRV0_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the IDRV0_SetDriveMode() function.
         *  @{
         */
        #define IDRV0_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define IDRV0_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define IDRV0_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define IDRV0_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define IDRV0_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define IDRV0_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define IDRV0_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define IDRV0_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define IDRV0_MASK               IDRV0__MASK
#define IDRV0_SHIFT              IDRV0__SHIFT
#define IDRV0_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IDRV0_SetInterruptMode() function.
     *  @{
     */
        #define IDRV0_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define IDRV0_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define IDRV0_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define IDRV0_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(IDRV0__SIO)
    #define IDRV0_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(IDRV0__PC) && (CY_PSOC4_4200L)
    #define IDRV0_USBIO_ENABLE               ((uint32)0x80000000u)
    #define IDRV0_USBIO_DISABLE              ((uint32)(~IDRV0_USBIO_ENABLE))
    #define IDRV0_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define IDRV0_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define IDRV0_USBIO_ENTER_SLEEP          ((uint32)((1u << IDRV0_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << IDRV0_USBIO_SUSPEND_DEL_SHIFT)))
    #define IDRV0_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << IDRV0_USBIO_SUSPEND_SHIFT)))
    #define IDRV0_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << IDRV0_USBIO_SUSPEND_DEL_SHIFT)))
    #define IDRV0_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(IDRV0__PC)
    /* Port Configuration */
    #define IDRV0_PC                 (* (reg32 *) IDRV0__PC)
#endif
/* Pin State */
#define IDRV0_PS                     (* (reg32 *) IDRV0__PS)
/* Data Register */
#define IDRV0_DR                     (* (reg32 *) IDRV0__DR)
/* Input Buffer Disable Override */
#define IDRV0_INP_DIS                (* (reg32 *) IDRV0__PC2)

/* Interrupt configuration Registers */
#define IDRV0_INTCFG                 (* (reg32 *) IDRV0__INTCFG)
#define IDRV0_INTSTAT                (* (reg32 *) IDRV0__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define IDRV0_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(IDRV0__SIO)
    #define IDRV0_SIO_REG            (* (reg32 *) IDRV0__SIO)
#endif /* (IDRV0__SIO_CFG) */

/* USBIO registers */
#if !defined(IDRV0__PC) && (CY_PSOC4_4200L)
    #define IDRV0_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define IDRV0_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define IDRV0_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define IDRV0_DRIVE_MODE_SHIFT       (0x00u)
#define IDRV0_DRIVE_MODE_MASK        (0x07u << IDRV0_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins IDRV0_H */


/* [] END OF FILE */
