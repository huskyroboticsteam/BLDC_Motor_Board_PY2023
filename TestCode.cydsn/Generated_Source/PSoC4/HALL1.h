/*******************************************************************************
* File Name: HALL1.h  
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

#if !defined(CY_PINS_HALL1_H) /* Pins HALL1_H */
#define CY_PINS_HALL1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "HALL1_aliases.h"


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
} HALL1_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   HALL1_Read(void);
void    HALL1_Write(uint8 value);
uint8   HALL1_ReadDataReg(void);
#if defined(HALL1__PC) || (CY_PSOC4_4200L) 
    void    HALL1_SetDriveMode(uint8 mode);
#endif
void    HALL1_SetInterruptMode(uint16 position, uint16 mode);
uint8   HALL1_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void HALL1_Sleep(void); 
void HALL1_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(HALL1__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define HALL1_DRIVE_MODE_BITS        (3)
    #define HALL1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - HALL1_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the HALL1_SetDriveMode() function.
         *  @{
         */
        #define HALL1_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define HALL1_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define HALL1_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define HALL1_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define HALL1_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define HALL1_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define HALL1_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define HALL1_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define HALL1_MASK               HALL1__MASK
#define HALL1_SHIFT              HALL1__SHIFT
#define HALL1_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HALL1_SetInterruptMode() function.
     *  @{
     */
        #define HALL1_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define HALL1_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define HALL1_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define HALL1_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(HALL1__SIO)
    #define HALL1_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(HALL1__PC) && (CY_PSOC4_4200L)
    #define HALL1_USBIO_ENABLE               ((uint32)0x80000000u)
    #define HALL1_USBIO_DISABLE              ((uint32)(~HALL1_USBIO_ENABLE))
    #define HALL1_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define HALL1_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define HALL1_USBIO_ENTER_SLEEP          ((uint32)((1u << HALL1_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << HALL1_USBIO_SUSPEND_DEL_SHIFT)))
    #define HALL1_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << HALL1_USBIO_SUSPEND_SHIFT)))
    #define HALL1_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << HALL1_USBIO_SUSPEND_DEL_SHIFT)))
    #define HALL1_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(HALL1__PC)
    /* Port Configuration */
    #define HALL1_PC                 (* (reg32 *) HALL1__PC)
#endif
/* Pin State */
#define HALL1_PS                     (* (reg32 *) HALL1__PS)
/* Data Register */
#define HALL1_DR                     (* (reg32 *) HALL1__DR)
/* Input Buffer Disable Override */
#define HALL1_INP_DIS                (* (reg32 *) HALL1__PC2)

/* Interrupt configuration Registers */
#define HALL1_INTCFG                 (* (reg32 *) HALL1__INTCFG)
#define HALL1_INTSTAT                (* (reg32 *) HALL1__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define HALL1_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(HALL1__SIO)
    #define HALL1_SIO_REG            (* (reg32 *) HALL1__SIO)
#endif /* (HALL1__SIO_CFG) */

/* USBIO registers */
#if !defined(HALL1__PC) && (CY_PSOC4_4200L)
    #define HALL1_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define HALL1_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define HALL1_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define HALL1_DRIVE_MODE_SHIFT       (0x00u)
#define HALL1_DRIVE_MODE_MASK        (0x07u << HALL1_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins HALL1_H */


/* [] END OF FILE */
