/**
*   @file    Os_platform_interrupt.h
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
*   (c) Copyright 2011 - 2016 Freescale Semiconductor Inc.
*   Copyright 2017 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef OS_PLATFORM_INTERRUPT_H_
#define OS_PLATFORM_INTERRUPT_H_


#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_platform.h>   /**< user provided platform configuration */

#include <Os_platform_config.h> /**< select IPs available on platform     */
#include <Os_platform_base.h>   /**< provides base addresses for each IP  */

#include <Os_hw_core.h>         /**< provides register access macros      */
#include <Os_hw_intc.h>



#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

typedef struct {

    OSDWORD xpsr;
    OSDWORD lr;

} Os_ArmSavedIRQCtxType;

OSDECLAREVAR(extern volatile Os_ArmSavedIRQCtxType, Os_ArmSavedIRQCtx_[ OSINTC_NVIC_PRIO_LEVELS ]);
#define Os_ArmSavedIRQCtx OSUSEVAR(Os_ArmSavedIRQCtx_)

OSDECLAREVAR(extern volatile OSDWORD, Os_ArmNvicNestingLevel_);
#define Os_ArmNvicNestingLevel OSUSEVAR(Os_ArmNvicNestingLevel_)

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"




#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern void OSPlatformIntcInit(void); /**< Platform specific interrupt controller initialization */


extern void OSPlatformIntcShutdown(void); /**< Platform specific interrupt controller de-initialization */

OSINLINE void OSArmDeactivateNIsr(OSDWORD xpsr, OSDWORD lr)
{
    OSGETCOREIND
    OSArmDeactivateIsr(xpsr, lr);
    Os_ArmNvicNestingLevel--;
}

OSINLINE void OSArmPushIrq(OSDWORD xpsr, OSDWORD lr)
{
    OSGETCOREIND
    Os_ArmSavedIRQCtx[ Os_ArmNvicNestingLevel ].xpsr=xpsr;
    Os_ArmSavedIRQCtx[ Os_ArmNvicNestingLevel ].lr=lr;

    Os_ArmNvicNestingLevel++;
}


OSINLINE OSDWORD OSGetMsrDI (void)
{
    register OSDWORD msr;
    msr = OSGETMSR ();
    OSSETMSR (msr | OSMSR_PRIMASKBIT0 ); /**< disable interrupts */
    return msr;
}





#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"






/*
 * Functions for NVIC IPL manipulations, to be called with all interrupts disabled
 */

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSGCCARM) || defined(OSIARARM)

    OSINLINE OSDWORD OSISRGetIntVector( void ) /**< Get the interrupt vector */
    {
        register OSDWORD result;

        OSASM ("MRS %0, ipsr" : "=r" (result) );

        return (result);
    }

    OSINLINE void OSISRSetPrio(OSDWORD prio) /**< Set current ISR prio to the highest OS ISR prio */
    {
      register OSDWORD converted_prio = OSINTC_NVIC_CONVERT_PRIO_SET(prio);

      OSASM ("MSR basepri, %0" : : "r" (converted_prio) );
    }

    OSINLINE OSDWORD OSISRGetPrio(void) /**< Get current ISR prio */
    {
      register OSDWORD result;

      OSASM ("MRS %0, basepri_max" : "=r" (result) );

      result = OSINTC_NVIC_CONVERT_PRIO_GET( result );

      return (result);
    }

#endif /* defined(OSGCCARM) || defined(OSIARARM) */


#if defined(OSGHSARM)

    OSINLINE OSDWORD OSISRGetIntVector( void ) /**< Get the interrupt vector */
    {
        return __MRS( __IPSR );
    }


    OSINLINE void OSISRSetPrio(OSDWORD prio) /**< Set current ISR prio to the highest OS ISR prio */
    {
      register OSDWORD converted_prio = OSINTC_NVIC_CONVERT_PRIO_SET(prio);

      __MSR( __BASEPRI, converted_prio);
    }



    OSINLINE OSDWORD OSISRGetPrio(void) /**< Get current ISR prio */
    {
      OSDWORD result;

      result = __MRS( __BASEPRI_MAX );

      result = OSINTC_NVIC_CONVERT_PRIO_GET( result );

      return (result);
    }

#endif /* defined(OSGHSARM) */


#if defined(OSDS5ARM)

    OSINLINE OSDWORD OSISRGetIntVector( void ) /**< Get the interrupt vector */
    {
        register OSDWORD __regIpsr  OSASM("ipsr");
        return (__regIpsr);
    }


    OSINLINE void OSISRSetPrio(OSDWORD prio) /**< Set current ISR prio to the highest OS ISR prio */
    {
      OSDWORD converted_prio = OSINTC_NVIC_CONVERT_PRIO_SET(prio);
      register OSDWORD __regBasePri         OSASM("basepri");

      __regBasePri = converted_prio;
    }


    OSINLINE OSDWORD OSISRGetPrio(void) /**< Get current ISR prio */
    {
      register OSDWORD __regBasePriMax  OSASM("basepri_max");

      OSDWORD result;

      result = __regBasePriMax;

      result = OSINTC_NVIC_CONVERT_PRIO_GET( result );

      return (result);
    }

#endif /* defined(OSDS5ARM) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

    #define OSISRALLON()          OSMSYNC(); OSISRSetPrio(0)     /**< Unmasks all interrupts */

    #if !defined(OSNOISR)
       #define OSEOIR()           OSISRSetPrio(oldPri)   /**< End Of Interrupt, restore IPL */
    #endif


    #if (OSNISR > 0U)


    #define  OSDisableISRSource(isrPtr) OSINTC_NVIC_DISABLE_INTX((isrPtr)->index) /* OSINTC_NVIC_CLEAR_PENDING_INTX((isrPtr)->index) */
    #define  OSEnableISRSource(isrPtr)  OSINTC_SET_PRIO_INTX((isrPtr)->index, OSINTC_NVIC_CONVERT_PRIO_SET((isrPtr)->isrPrio)); OSINTC_NVIC_ENABLE_INTX((isrPtr)->index)

    #endif /* OSNISR > 0 */






#if (OSNIOCCALLBACKS > 0U)

/*
 * Software interrupt for IOC callback
 */





    #define OSIOCSOFTINTCORE0     (16U)
    #define OSIOCCore0Invoke()    OSINTC_NVIC_SET_PENDING_INTX(OSIOCSOFTINTCORE0)
    #define OSIOCCore0ClearFlag() OSINTC_NVIC_CLEAR_PENDING_INTX(OSIOCSOFTINTCORE0)
    #define OSIOCCore0GetFlag()   OSINTC_NVIC_PEND_OR_ACTIVE_STATUS_INTX(OSIOCSOFTINTCORE0)





#endif /* OSNIOCCALLBACKS > 0U */












#ifdef __cplusplus
}
#endif


#endif /*OS_PLATFORM_INTERRUPT_H_ */

/** @} */
