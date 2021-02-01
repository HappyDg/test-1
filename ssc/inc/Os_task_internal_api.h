/**
*   @file    Os_task_internal_api.h
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

#ifndef OS_TASK_INTERNAL_API_H_
#define OS_TASK_INTERNAL_API_H_


#ifdef __cplusplus
extern "C"
{
#endif


#include <Os_types_common_internal.h>   /* for OSTSKCBPTR */

#include <Os_task_internal_types.h>

#include <Os_application_internal_types.h>      /* for OSAPPCB */

#include <Os_scheduler_internal_api.h>  /* for OSTask2Suspend, OSTASKRUNPRIO and friends */


/* Task status      */
                                                /*#define OSTCBSCHEDULER  ( (OSBYTE)0x01 ) *//* (0x01) Task has allocated (locked) the scheduler */
#define OSTCBFIRST       ( (OSBYTE)0x02 )       /* (0x02) First run of task (context must be built) */
#define OSTCBWAIT        ( (OSBYTE)0x04 )       /* (0x04) Task is waiting for an event              */
#define OSTCBNOSUSPENDED ( (OSBYTE)0x10 )       /* Task is not in suspended state, for Ext. Status  */

#define OSTCBSTART      ((OSBYTE)(OSTCBFIRST | OSTCBNOSUSPENDED))


#if defined(OSBCC)

#if defined(OSEXTPRIORS)
#define OSCHECKTASKSTATUS(taskId)  \
    ( (taskId < OSSCHMAXBITNUM) ? \
    ((OsSchedulerVector1 &  ( OSDWORDMSB >> taskId )) ? 1U : 0U) : \
    ((OsSchedulerVector2 &  ( OSDWORDMSB >> ((OSTASKTYPE)taskId - OSSCHMAXBITNUM))) ? 1U : 0U ))
#else /* defined(OSEXTPRIORS) */
#define OSCHECKTASKSTATUS(taskId) \
    (( OsSchedulerVector1 & ( OSDWORDMSB >> (taskId) )) ? 1U : 0U )
#endif /* defined(OSEXTPRIORS) */

#endif /* defined(OSBCC)  */


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSSYSSTKCHECK)

extern void OSCheckStack (void);

#if defined(OSUSETOS)           /* note that OSSYSSTKCHECK is defined ==> field 'bos' is used */
                                          /* Restore stack pad for running task  */
#define OSSTKRESTOREPAD() OSSTKSETGUARD( OsRunning->bos )
#else
#define OSSTKRESTOREPAD() OSSTKSETGUARD( OSSTACKBOTTOM )
#endif

#else
#define OSCheckStack()
#define OSSTKRESTOREPAD()
#endif /* defined(OSSYSSTKCHECK) */


#if(OSNAPPMODES > 1U)
extern void OSInitTasks (AppModeType mode);
#else
extern void OSInitTasks (void);
#endif


#if defined(OSTERMINATION)
extern void OSKillTask (OSTSKCBPTR taskPtr);
#endif

#if !defined(OSSC1) || defined(OSEXTSTATUS)
extern void OSKillRunningTask (void);
#endif

#if defined(OSAPPLICATION)
extern void OSKillAppTasks (OSAPPLICATIONTYPE appId);
#endif




       /* It is for SC3 (because OSCHECKSTACK_TP() is used only in the OS dispatchers for SC2,3,4) */
#if defined(OSSYSSTKCHECK)
    #if defined(OSHOOKPROTECTION)
        #define OSCHECKSTACK_TP(arg)   OSCheckStack();  OsKilled &= ~OSRUNTSKKILLED
    #else
        #define OSCHECKSTACK_TP(arg)   OSCheckStack()
    #endif /* defined(OSHOOKPROTECTION) */
#else
    #define OSCHECKSTACK_TP(arg)
#endif /* defined(OSSYSSTKCHECK) */




/******************************************************************************
* inline function: OSResetInternalPrio
* Description:     clears bit in scheduler vector if there is no OTHER ready
*                  task of running priority, resets Task prio to assigned
* Returns:         none
******************************************************************************/
#if defined(OSINRES)
OSINLINE void
OSResetInternalPrio (void)
{
    if (OSCLEARRUNPRIOBITISNECESSARY ())
    {                           /* if there is no ready task of this prio. */
        OSTask2Suspend (OSTASKRUNPRIO (OsRunning));     /* then clear bit in OsScheduler           */
    }
    OSRESETRUNPRIO ();
}
#else
#define OSResetInternalPrio( )
#endif

/******************************************************************************
* inline function: OSResetInternalPrio2
* Description:     clears bit in scheduler vector if there is no ready task
*                  of running priority, resets Task prio to assigned
* Returns:         none
******************************************************************************/
#if defined(OSINRES)

#if defined(OSECC)

OSINLINE void
OSResetInternalPrio2 (void)
{
    if ((OSTASKSTATUS (OSPRIO2TASKID (OSTASKRUNPRIO (OsRunning))) & (OSTCBNOSUSPENDED | OSTCBWAIT)) != OSTCBNOSUSPENDED)
    {                           /* if there is no ready task of this prio.  */
        OSTask2Suspend (OSTASKRUNPRIO (OsRunning));     /* then clear bit in OsScheduler         */
    }
    OSRESETRUNPRIO ();
}

#else /* defined(OSECC) */

OSINLINE void
OSResetInternalPrio2 (void)
{
    if ((OSTASKSTATUS (OSPRIO2TASKID (OSTASKRUNPRIO (OsRunning))) & OSTCBNOSUSPENDED) == 0U)
    {                           /* if there is no ready task of this prio.  */
        OSTask2Suspend (OSTASKRUNPRIO (OsRunning));     /* then clear bit in OsScheduler         */
    }
    OSRESETRUNPRIO ();
}

#endif /* defined(OSECC) */

#else /* defined(OSINRES) */

#define OSResetInternalPrio2( )

#endif /* defined(OSINRES) */




#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


#endif /*OS_TASK_INTERNAL_API_H_ */

/** @} */
