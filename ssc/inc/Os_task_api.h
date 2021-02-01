/**
*   @file    Os_task_api.h
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

#ifndef OS_TASK_API_H
#define OS_TASK_API_H


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <Os_prop_autosar_api.h>

#include <Os_task_types.h>  /* for TaskType, TaskStateRefType ... */
#include <Os_memory_api.h>  /* for OSServiceCallX defines */

#define INVALID_TASK  OS_MKOBJID(OBJECT_TASK, OSNTSKS)         /* Invalid task (no active task) */

    /*  OSEK naming conventions */
#if defined(OSBCC)

#if defined(OSNOFASTTERMINATE)
#define TASK( TaskName ) void       Func##TaskName( void )
#else
#define TASK( TaskName ) OSTASKTYPE Func##TaskName( void )
#endif

#endif /* defined(OSBCC)  */

#if defined(OSECC)
#define TASK( TaskName ) void         Func##TaskName( void )
#endif /* defined(OSECC)  */


#define DeclareTask(TaskID) extern OSBYTE osdummy

    /*
     *  part of public API, returned by GetTaskState through TaskStateRefType parameter
     */
#define RUNNING         ((TaskStateType)0)      /* Constant of data type TaskStateType for task state running.  */
#define WAITING         ((TaskStateType)1)      /* Constant of data type TaskStateType for task state waiting.  */
#define READY           ((TaskStateType)2)      /* Constant of data type TaskStateType for task state ready.    */
#define SUSPENDED       ((TaskStateType)3)      /* Constant of data type TaskStateType for task state suspended. */


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

/* Public OS Services */
extern StatusType OS_ActivateTask (TaskType taskId);

#if defined(OSBCC)
    #if defined(OSNOFASTTERMINATE)
        extern StatusType OS_TerminateTask (void);
        extern StatusType OS_ChainTask (TaskType taskId);
    #else
        #define TerminateTask()      return( OSINVALID_TASK )
        #define ChainTask( taskId )  return( (taskId) )
    #endif
#endif /* defined(OSBCC)  */

#if defined(OSECC)
extern StatusType OS_TerminateTask (void);
extern StatusType OS_ChainTask (TaskType taskId);
#endif

extern StatusType OS_GetTaskID (TaskRefType taskIdRef);
extern StatusType OS_GetTaskState (TaskType taskId, TaskStateRefType stateRef);



#define ActivateTask(taskId)           OS_ActivateTask(taskId)

#if defined(OSNOFASTTERMINATE)
#define TerminateTask()             OS_TerminateTask()
#define ChainTask(taskId)           OS_ChainTask(taskId)
#endif

#define GetTaskID(taskIdRef)           OS_GetTaskID(taskIdRef)
#define GetTaskState(taskId, stateRef) OS_GetTaskState(taskId, stateRef)


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_TASK_API_H */

/** @} */
