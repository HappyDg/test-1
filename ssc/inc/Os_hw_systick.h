/**
*   @file    Os_hw_systick.h
*   @version 4.0.98
*
*   @brief   AUTOSAR OS - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup [OS]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR OS 4.0
*   Platform             : Arm Architecture
*   Peripheral           : CortexM4
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 4.0.98
*   Build Version        : ARMS32KV4_OS_4.0.98_ASR_REL_4_0_REV_0003
*
*   (c) Copyright 2013 - 2016 Freescale Semiconductor Inc.
*   Copyright 2017 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef OS_HW_SYSTICK_H
#define OS_HW_SYSTICK_H


#ifdef __cplusplus
extern "C"
{
#endif

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"


/************************************************  SYSTICK registers  *****/

#define OSSYSTICK_TENBIT        (0x1UL)                        /* SYSTICK timer enable bit */
#define OSSYSTICK_INT_ENBIT     (0x1UL<<1)                     /* SYSTICK interrupt enable bit */
#define OSSYSTICK_CLKSRC_CORE   (0x1UL<<2)                     /* SYSTICK source CLK is cpu CLK */
#define OSSYSTICK_FLGBIT        (0x1UL<<16)                    /* SYSTICK channel interrupt flag */

#define OSSYSTICK_CSR         OSREG32(OSSYSTICKBASE)           /* SYSTICK Control and Status Register */
#define OSSYSTICK_RVR         OSREG32(OSSYSTICKBASE + 0x4U)    /* SYSTICK Reload Value Register */
#define OSSYSTICK_CVR         OSREG32(OSSYSTICKBASE + 0x8U)    /* SYSTICK Counter Value */

/**************************************************************************/

#define OSSYSTICK_STARTVAL  ((OSDWORD)0x0)                     /* start value for SYSTICK counter */


#if defined(OSSYSTIMER)


/*********************************************************  System SYSTICK timer  *****/
#if defined(OSTIMSYSTICK)

    #define OSSTREG         OSSYSTICK_CSR                   /* status register */
    #define OSINTFLAG       OSSYSTICK_FLGBIT                /* timer interrupt flag for external usage */
    #define OSTIMTCNT       OSSYSTICK_CVR                   /* counter value */
    #define OSTIMCHOC       OSSYSTICK_RVR                   /* timer compare value - reload value in this case */


    #define OSTimHWprepare()     /* do nothing */

    #define OSSysTimRun()        OSSYSTICK_CSR |=  OSSYSTICK_TENBIT          /* enable  timer ENABLE = 1 */
    #define OSSysTimStop()       OSSYSTICK_CSR &= ~OSSYSTICK_TENBIT          /* disable timer ENABLE = 0 */
    #define OSSysTimClearFlag()  OSSYSTICK_CSR &= ~OSSYSTICK_FLGBIT          /* clear interrupt flag TBD: check if we can write 0, we actually need a read to clear */
    #define OSSysTimEnableInt()  OSSYSTICK_CSR |=  OSSYSTICK_INT_ENBIT       /* enable  timer interrupts TICKINT = 1 */
    #define OSSysTimDisableInt() OSSYSTICK_CSR &= ~OSSYSTICK_INT_ENBIT       /* disable timer interrupts TICKINT = 0 */


/***************************************************************************
* Macro:       OSSysTimSetHW
*
* Description: System timer's HW initialization;
*              mode,control bits and prescaler are set here;
*
*          for SYSTICK:
*              MODULO value;
*              clear counter register;
*
**************************************************************************/

OSINLINE void
OSSysTimSetHW (void)
{

    #if defined(OSTIMMODULO)
    OSTIMCHOC = OSTIMMODULO;  /* reload value */
    #endif

    OSTIMTCNT = OSSYSTICK_STARTVAL; /* reset counter value */

    OSSYSTICK_CSR |= OSSYSTICK_CLKSRC_CORE;

    OSSysTimRun ();          /* start system timer  */
}

#endif     /* defined(OSTIMSYSTICK) */

#endif /* #if defined(OSSYSTIMER) */





#if defined(OSSECONDTIMER)

/*********************************************************  System SYSTICK timer  *****/
#if defined(OSTIM2SYSTICK)

    #define OSSTREG2        OSSYSTICK_CSR                    /* status register */
    #define OSINTFLAG2      OSSYSTICK_FLGBIT                 /* timer interrupt flag for external usage */
    #define OSTIM2TCNT      OSSYSTICK_CVR                    /* counter value */
    #define OSTIM2CHOC      OSSYSTICK_RVR                    /* timer compare value - reload value in this case */


    #define OSTim2HWprepare()    /* do nothing */

    #define OSSecondRun()        OSSYSTICK_CSR |=  OSSYSTICK_TENBIT          /* enable  timer ENABLE = 1 */
    #define OSSecondStop()       OSSYSTICK_CSR &= ~OSSYSTICK_TENBIT          /* disable timer ENABLE = 0 */
    #define OSSecondClearFlag()  OSSYSTICK_CSR &= ~OSSYSTICK_FLGBIT          /* clear interrupt flag TBD: check if we can write 0, we actually need a read to clear */
    #define OSSecondEnableInt()  OSSYSTICK_CSR |=  OSSYSTICK_INT_ENBIT       /* enable  timer interrupts TICKINT = 1 */
    #define OSSecondDisableInt() OSSYSTICK_CSR &= ~OSSYSTICK_INT_ENBIT       /* disable timer interrupts TICKINT = 0 */


/***************************************************************************
* Macro:       OSSecondTimSetHW
*
* Description: Second timer's HW initialization;
*              mode,control bits and prescaler are set here;
*
*          for SYSTICK:
*              MODULO value;
*              clear counter register;
*
**************************************************************************/

OSINLINE void
OSSecondSetHW (void)
{

    #if defined(OSTIM2MODULO)
    OSTIM2CHOC = OSTIM2MODULO; /* reload value */
    #endif

    OSTIM2TCNT = OSSYSTICK_STARTVAL; /* reset counter value */

    OSSYSTICK_CSR |= OSSYSTICK_CLKSRC_CORE;

    OSSecondRun ();        /* start second timer  */
}

#endif /* defined(OSTIM2SYSTICK) */

#endif /* #if defined(OSSECONDTIMER) */




#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif


#endif /* OS_HW_SYSTICK_H */

/** @} */

