/*******************************************************************************
* File Name: DRV_EN.h  
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

#if !defined(CY_PINS_DRV_EN_H) /* Pins DRV_EN_H */
#define CY_PINS_DRV_EN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "DRV_EN_aliases.h"


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
} DRV_EN_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   DRV_EN_Read(void);
void    DRV_EN_Write(uint8 value);
uint8   DRV_EN_ReadDataReg(void);
#if defined(DRV_EN__PC) || (CY_PSOC4_4200L) 
    void    DRV_EN_SetDriveMode(uint8 mode);
#endif
void    DRV_EN_SetInterruptMode(uint16 position, uint16 mode);
uint8   DRV_EN_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void DRV_EN_Sleep(void); 
void DRV_EN_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(DRV_EN__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define DRV_EN_DRIVE_MODE_BITS        (3)
    #define DRV_EN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - DRV_EN_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the DRV_EN_SetDriveMode() function.
         *  @{
         */
        #define DRV_EN_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define DRV_EN_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define DRV_EN_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define DRV_EN_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define DRV_EN_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define DRV_EN_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define DRV_EN_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define DRV_EN_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define DRV_EN_MASK               DRV_EN__MASK
#define DRV_EN_SHIFT              DRV_EN__SHIFT
#define DRV_EN_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DRV_EN_SetInterruptMode() function.
     *  @{
     */
        #define DRV_EN_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define DRV_EN_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define DRV_EN_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define DRV_EN_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(DRV_EN__SIO)
    #define DRV_EN_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(DRV_EN__PC) && (CY_PSOC4_4200L)
    #define DRV_EN_USBIO_ENABLE               ((uint32)0x80000000u)
    #define DRV_EN_USBIO_DISABLE              ((uint32)(~DRV_EN_USBIO_ENABLE))
    #define DRV_EN_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define DRV_EN_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define DRV_EN_USBIO_ENTER_SLEEP          ((uint32)((1u << DRV_EN_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << DRV_EN_USBIO_SUSPEND_DEL_SHIFT)))
    #define DRV_EN_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << DRV_EN_USBIO_SUSPEND_SHIFT)))
    #define DRV_EN_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << DRV_EN_USBIO_SUSPEND_DEL_SHIFT)))
    #define DRV_EN_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(DRV_EN__PC)
    /* Port Configuration */
    #define DRV_EN_PC                 (* (reg32 *) DRV_EN__PC)
#endif
/* Pin State */
#define DRV_EN_PS                     (* (reg32 *) DRV_EN__PS)
/* Data Register */
#define DRV_EN_DR                     (* (reg32 *) DRV_EN__DR)
/* Input Buffer Disable Override */
#define DRV_EN_INP_DIS                (* (reg32 *) DRV_EN__PC2)

/* Interrupt configuration Registers */
#define DRV_EN_INTCFG                 (* (reg32 *) DRV_EN__INTCFG)
#define DRV_EN_INTSTAT                (* (reg32 *) DRV_EN__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define DRV_EN_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(DRV_EN__SIO)
    #define DRV_EN_SIO_REG            (* (reg32 *) DRV_EN__SIO)
#endif /* (DRV_EN__SIO_CFG) */

/* USBIO registers */
#if !defined(DRV_EN__PC) && (CY_PSOC4_4200L)
    #define DRV_EN_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define DRV_EN_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define DRV_EN_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define DRV_EN_DRIVE_MODE_SHIFT       (0x00u)
#define DRV_EN_DRIVE_MODE_MASK        (0x07u << DRV_EN_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins DRV_EN_H */


/* [] END OF FILE */
