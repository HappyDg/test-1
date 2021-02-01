/**
*   @file    Os_memory_api.h
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

#ifndef OS_MEMORY_API_H_
#define OS_MEMORY_API_H_

#ifdef __cplusplus
extern "C"
{
#endif            /* __cplusplus */

#include <Os_prop_autosar_api.h>
#include <Os_memory_types.h>
#include <Os_types_basic.h>
#include <Os_hw_core_compiler_api.h>


#if defined(OSMEMPROTECTION) || defined(OSHOOKPROTECTION) || defined(OSSBSSCOPY)


#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"
extern OSNEAR OSBYTE OsStarted;    /* Boolean variable, it shall be OSFALSE (0) before StartOS() call  */
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


#endif /* defined(OSMEMPROTECTION) || defined(OSHOOKPROTECTION) || defined(OSSBSSCOPY) */



#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"



/*
* API in this file
*
* OSMEMORY_IS_READABLE(x)
* OSMEMORY_IS_WRITEABLE(x)
* OSMEMORY_IS_EXECUTABLE(x)
* OSMEMORY_IS_STACKSPACE(x)
*
* only available if OSMEMPROTECTION is on
* CallTrustedFunction
* CheckISRMemoryAccess
* CheckTaskMemoryAccess
*
*/


/*  part of Autosar OS public API
 *
 * These macros return a value not equal to zero if the memory is
 * readable / writable / executable or stack space
*/
#define OSMEMORY_IS_READABLE(x)   ( ((x) & OSMP_R) != 0U )
#define OSMEMORY_IS_WRITEABLE(x)  ( ((x) & OSMP_W) != 0U )
#define OSMEMORY_IS_EXECUTABLE(x) ( ((x) & OSMP_E) != 0U )
#define OSMEMORY_IS_STACKSPACE(x) ( ((x) & OSMP_S) != 0U )


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif



#endif /*OS_MEMORY_API_H_*/

/** @} */

