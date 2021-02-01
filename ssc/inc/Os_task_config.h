/**
*   @file    Os_task_config.h
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

#ifndef OS_TASK_CONFIG_H_
#define OS_TASK_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>

#include <Os_types_basic.h>     /* for OSDWORD ... */
#include <Os_types_common_internal.h>   /* for OSTASKENTRY ... */

#include <Os_tp_internal_types.h>       /* for OSTPRESLOCK */

   /* Task properties  - used by the property field */
#define OSTSKACTIVATE           ( (OSBYTE)0x08 )        /* Activate task during system start-up */
#if defined(OSTSKFPU)
#define OSTSKFLOATINGPOINT   ( (OSBYTE)0x20 )        /* Use floating point in task */
#endif
#define OSTSKNONPREEMPT         ( (OSBYTE)0x40 )        /* Non-preemptive task  */
#define OSTSKEXTENDED           ( (OSBYTE)0x80 )        /* Extended task    */



#if defined(OSUSETCB)

/* Task configuration table */
struct TagOSTSK
{
    #if defined(OSAPPLICATION)
    OSAPPLICATIONMASKTYPE appMask; /* Application identification mask value */
    #endif

    OSTASKENTRY entry;          /* entry point of task */

    #if (OSNAPPMODES > 1U)
    OSDWORD autostart;
    #endif                          /* (OSNAPPMODES > 1U) */

    #if (OSNXTSKS > 0U)
    OSDWORD *tos;               /* top of task stack */
    #if defined(OSUSEBOS)
    OSDWORD *bos;               /* bottom of task stack */
    #endif
    #endif                          /* (OSNXTSKS > 0U) */


    #if defined(OSINRES)
    OSBYTE runprio;             /* running prio (internal resource) */
    #endif                          /* defined(OSINRES) */

    OSBYTE property;            /* properties of task OSTSKACTIVATE, OSTSKFLOATINGPOINT, OSTSKEXTENDED, OSTSKNONPREMPT */
    TaskType taskId;            /* task id (task number in the task table) */


    #if defined(OSAPPLICATION)
    OSAPPLICATIONTYPE appId;    /* application identification value */
    #endif
};


typedef struct TagOSTSK OSTSK;  /* Task configuration table */
typedef OSTSK *OSTSKPTR;        /* Pointer to the task configuration table */

#define OSTSKPTR0   ( (OSTSKPTR)0 )     /* Null-pointer */

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

extern const OSTSK OsTaskCfgTable[OSNTSKS];     /* TaskConfiguration table  */

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#else /* defined(OSUSETCB) */

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

extern const OSTASKENTRY OsTaskEntry[OSNTSKS];  /* Tasks' entries */
extern const OSBYTE OsTaskProperty[OSNTSKS];    /* Tasks' properties */
extern const OSBYTE OsTaskRunPrio[OSNTSKS];     /* Tasks' runprio */

#if (OSNAPPMODES > 1U)
extern const OSBYTE OsTaskAutostart[OSNTSKS];
#endif

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"


#endif /* defined(OSUSETCB) */


/* OSNULLTASK - real index of null task */
/* OSINVALID_TASK - invalid task index */
#define OSINVALID_TASK  OSNTSKS                /* Invalid task index */

#if defined(OSUSETCB)

#define OSNULLTASKPTR ((OSTSKCBPTR)0)

#define OSNULLTASK  OSINVALID_TASK

#else            /* defined(OSUSETCB) */

#define OSNULLTASK     OSINVALID_TASK    /* Task Id when no activated tasks */

#endif           /* defined(OSUSETCB) */


#ifdef __cplusplus
}
#endif


#endif /*OS_TASK_CONFIG_H_ */

/** @} */
