/**
*   @file    Os_isr_internal_types.h
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

#ifndef OS_ISR_INTERNAL_TYPES_H_
#define OS_ISR_INTERNAL_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>

#include <Os_types_basic.h>     /* for OSDWORD ...   */
#include <Os_types_common_internal.h>   /* for OSAPPLICATIONTYPE */

#include <Os_resource_internal_types.h> /* for OSResType */

#include <Os_tp_internal_types.h>       /* for OSTPRESLOCK */

/* ISR control structure */
struct tagISRTYPE
{


    #if defined(OSTERMINATION)
    OSBYTE isKilled;            /* set when the ISR is killed via ProtectionHook or via TerminateApplication() */
    #endif

    #if defined(OSUSERESLINK)
    OSRefResType resources;     /* pointer to the resources */
    #endif

    OSVOIDFUNCVOID userISR;     /* actual ISR function */
    OSISRTYPE type;             /* type of the ISR */
    OSWORD index;               /* Index of interrupt in the external interrupts table */
    OSBYTE isrPrio;             /* Interrupt priority */



    #if defined(OSAPPLICATION)
    OSAPPLICATIONTYPE appId;    /* application identification value */
    #endif

};


#ifdef __cplusplus
}
#endif

#endif /*OS_ISR_INTERNAL_TYPES_H_ */

/** @} */
