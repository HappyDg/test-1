/**
*   @file    Os_tp_internal_api_v3.h
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

#ifndef OS_TP_INTERNAL_API_V3_H
#define OS_TP_INTERNAL_API_V3_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <Os_tp_internal_types.h>       /* for OSTPRESLOCK */
#include <Os_isr_internal_api.h>

#include <Os_hook_internal_api.h>

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"


#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


    #define OSTPSetWAITEVT()
    #define OSTPClrWAITEVT()

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"


/*
 * Empty TP interface macros in the case timing protection is not enabled
 */
#define OSTPStartTaskFrame( arg )
#define OSTPStartTaskFrameInAlm( arg )
#define OSTPResetReadyTask(arg)
#define OSTPResumeTaskBudget()
#define OSTPResetTaskBudget()
#define OSTPStopTaskBudget()
#define OSTPRestartTaskBudget()
#define OSTPStartISRBudget( arg )
#define OSTPResetISRBudget()
#define OSTPKillISRBudget()
#define OSTPResumeISRBudget( arg )
#define OSTPStopBudget()
#define OSTPStartIntLockTime()
#define OSTPStopIntLockTime()
#define OSTPKillIntLockTime()
#define OSTPStartResLockTime( arg )
#define OSTPResetResLockTime( arg )
#define OSTPISRArrivalRate( arg )
#define OSTPPostTaskHook()  OSPostTaskHook()

#define OSTPGETCOREIND OSGETCOREIND



#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_TP_INTERNAL_API_V3_H */

/** @} */
