/**
*   @file    Os_hw_core_compiler_api.h
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

#ifndef OS_HW_CORE_COMPILER_API_H_
#define OS_HW_CORE_COMPILER_API_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"








#if !defined(OSGCCARM) && !defined(OSGHSARM) && !defined(OSDS5ARM) && !defined(OSIARARM)
#error "Compiler is not defined"
#endif

#if defined(OSGHSARM)
#include <arm_ghs.h>            /* for intrinsic functions only */
#endif


#if defined(OSGCCARM) || defined(OSIARARM)


/*
* Get the MSR register value
*/
OSINLINE OSDWORD OSGETMSR (void)
{
    register OSDWORD primask_reg;

    OSASM ( " mrs %0, primask " : "=r" (primask_reg) );

    return primask_reg;
}


/*
* Set the MSR register new value
*/
OSINLINE void OSSETMSR (register OSDWORD primask_val)
{
    OSASM ( " msr primask, %0 " : : "r" (primask_val) );
}



/* msync and isynch core instruction macros */
#define OSMSYNC() OSASM("dsb")
#define OSISYNC() OSASM("isb")

#endif /* defined(OSGCCARM) */



#if defined(OSGHSARM)

/*
* Get the MSR register value
*/
OSINLINE OSDWORD OSGETMSR (void)
{
    return __MRS( __PRIMASK );
}

/*
* Set the MSR register new value
*/
OSINLINE void OSSETMSR (OSDWORD primask_val)
{
    __MSR( __PRIMASK, primask_val);
}



/* msync and isynch core instruction macros */
#define OSMSYNC() OSASM("dsb")
#define OSISYNC() OSASM("isb")

#endif /* defined(OSGHSARM) */



#if defined(OSDS5ARM)

/*
* Get the MSR register value
*/
OSINLINE OSDWORD OSGETMSR (void)
{
    register OSDWORD __regPriMask  OSASM("primask");
    return (__regPriMask);
}

/*
* Set the MSR register new value
*/
OSINLINE void OSSETMSR (OSDWORD primask_val)
{
    register OSDWORD __regPriMask  OSASM("primask");
    __regPriMask = (primask_val);
}



/* msync and isynch core instruction macros */
#define OSMSYNC()      __dsb(0xF)
#define OSISYNC()      __isb(0xF)

#endif /* defined(OSDS5ARM) */



#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif


#endif /*OS_HW_CORE_COMPILER_API_H_*/

/** @} */

