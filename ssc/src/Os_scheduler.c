/**
*   @file    Os_scheduler.c
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

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Os_scheduler_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters.
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character.
* Compilers are checked for support this length of identifiers.
*
* @section Os_scheduler_c_REF_14_4_1
* Violates MISRA 2004 Required Rule 14.4, Use of goto is deprecated
* The goto statement shall not be used.
* The goto statement is used to implement the OS scheduler internal logic.
*
* @section Os_scheduler_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_scheduler_c_REF_16_10_1
* Violates MISRA 2004 Required Rule 16.10, Ignoring return value of function
* If a function returns error information, then that error information shall be tested.
* Function OSLongJmp is used for switching context and it is not supposed
* to return to the place where it is called.
* Function OS2SystemMode is used for switching to system mode and it is not supposed
* to analyze the return value where it is called.
*
* @section Os_scheduler_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used to increase of OS performance.
*
* @section Os_scheduler_c_REF_19_1_1
* Violates MISRA 2004 Advisory Rule 19.1, declaration before #include
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* MemMap is required by AutoSAR to be included in the middle of the source file(s).
*
* @section Os_scheduler_c_REF_19_4_1
* Violates MISRA 2004 Required Rule 19.4, Expression-like macro not parenthesized
* The macro cannot be parenthesized because of assembler limitation, in all instances of
* this macro usage the macro is in brackets.
*
* @section Os_scheduler_c_REF_19_7_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* A function should be used in preference to a funcion-ike macro.
* Function like macros are used to reduce code complexity and for performance reasons.
*/


/****************** generic includes START ***********************/
#include <Os_prop_autosar.h>

#include <Os_types_basic.h>

#include <Os_types_public.h>
#include <Os_types_common_public.h>
#include <Os_types_common_internal.h>

#include <Os_internal_api.h>
#include <Os_internal_types.h>
#include <Os_internal_config.h>

#include <Os_platform.h>
/****************** generic includes END ***********************/

#include <Os_scheduler_api.h>
#include <Os_scheduler_internal_api.h>

/*
* @violates @ref Os_scheduler_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

OSDECLAREVAR (OSNEAR OSDWORD, OsSchedulerVector1_);     /* Mask of activated tasks(priorities) */

#if defined(OSEXTPRIORS)
OSDECLAREVAR (OSNEAR OSDWORD, OsSchedulerVector2_);     /* Mask of activated tasks(priorities) Extended vector */
#endif /* defined(OSEXTPRIORS) */

#if (OSNTRUSTEDFUNCTIONS > 0U)
OSDECLAREVAR (OSNEAR OSDWORD, OsSchedulerVectorMask1_); /* Mask on mask of activated tasks(priorities) */

#if defined(OSEXTPRIORS)
OSDECLAREVAR (OSNEAR OSDWORD, OsSchedulerVectorMask2_); /* Mask on mask of activated tasks(priorities) Extended vector */
#endif
#endif /* (OSNTRUSTEDFUNCTIONS > 0U) */

#if defined(OSNOFASTTERMINATE)
OSDECLAREVAR (OSNEAR OSTSKCBPTR, OS_TaskListHead_); /**< The head of the task list */
#endif /* defined(OSNOFASTTERMINATE) */

/*
* @violates @ref Os_scheduler_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_scheduler_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

/*
 * scheduler variables
 */

#if defined(OSUSETCB)

#if defined(OSRESOURCE) || defined(OSINRES)

#define OS_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_scheduler_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

OSTSKCBPTR OsPrioLink[OSNPRIORS];       /* Priority Link table */

#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_scheduler_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#endif /* defined(OSRESOURCE) || defined(OSINRES) */

#endif /* defined(OSUSETCB) */

#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_scheduler_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

/* Prototypes */

/* Macros */
/*
 * @violates @ref Os_scheduler_c_REF_19_4_1 MISRA 2004 Required Rule 19.4, Expression-like macro not parenthesized
 */
/*
 * @violates @ref Os_scheduler_c_REF_19_7_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define OSTaskEnterLabel()

/*  Scheduler services  */

/*  Private OS Services */


#if defined(OSSC1)
#if !defined(OSNOFASTTERMINATE)
/******************************************************************************
 * Function :   OSTaskForceDispatch
 *
 * Description: Task dispatcher for BCC1 with FastTerminate
 *
 * Returns:     none
 *
 * Notes:
 *
 ******************************************************************************/
void
OSTaskForceDispatch (void)
{
    #if defined(OSRESOURCE)
    OSTSKCBPTR osOldRunning;    /* pointer to currently running task CB */
    #else
    OSTASKTYPE osOldRunning;    /* currently running task   */
    #endif

    OSTASKTYPE osChainTask;     /* task to be chain (if any)    */

    OSCheckStack ();            /* check main stack overflow */

    osOldRunning = OsRunning;   /* save running task (if any)   */

    #if defined(OSHOOKPOSTTASK)
    if (OSTSKIND (OsRunning) != OSNULLTASK)
    {
        OSPostTaskHook ();      /* user hook or empty macro */
    }
    #endif

    while ((OsRunning = OSGETMAXPRIOTASK) != osOldRunning)      /* cycle to launch all preempting tasks */
    {
        OSOrtiSetRunningId ();
        OSSETRUNPRIO ();        /* set internal resource priotity, if any       */

        #if defined(OSRESOURCE) || defined(OSINRES)
        OSRUNNINGSTATUS |= OSTCBNOSUSPENDED;    /* set "nonsuspended" flag */
        #endif /* defined(OSRESOURCE) || defined(OSINRES) */

        OSOrtiResetIdOnExit (); /* set that the caller service is finished  */
        OSCallPreTaskHook ();
        OSEI ();
        osChainTask = OSCallTask ();    /* execute the task, and get the ID of chained task */
        OSDI ();
        OSCheckStack ();        /* check main stack overflow */

        #if defined(OSORTICURRENTSERVICEID)
        /* in case of FastTerminate all work of Chain/TerminateTask services    */
        /* is done in the dispatcher, so ORTI trace setting is done here too    */
        if (osChainTask != OSINVALID_TASK)
        {
            OSOrtiSetServiceWatch (OSServiceId_ChainTask);
            OSOrtiSetOldServiceID (OSServiceId_ChainTask);
        }
        else
        {
            OSOrtiSetServiceWatch (OSServiceId_TerminateTask);
            OSOrtiSetOldServiceID (OSServiceId_TerminateTask);
        }
        #endif

        #if defined(OSRESOURCE) || defined(OSINRES)
        OSRUNNINGSTATUS &= (~OSTCBNOSUSPENDED); /* clear "nonsuspended" flag */
        #endif

        OSResetInternalPrio2 ();

        OSREMOVETASK (OsRunning);

        if (osChainTask != OSINVALID_TASK)      /* if some task needs to be chained */
        {
            OSTask2Ready (osChainTask); /* then readies chained task */
        }
        OSPostTaskHook ();      /* user hook or empty macro */

    }

    OSOrtiSetRunningId ();
    OSSETBITRUNPRIO ();         /* restore internal resource priotity */
    OSOrtiResetIdOnExit ();     /* set that the caller service is finished  */
    OSPreTaskHook ();           /* call user hook           */

    /*
     * @violates @ref Os_scheduler_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function
     */
    return;
    /*
     * @violates @ref Os_scheduler_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function
     */
    OSWARNSUPPRESS              /* For extra CW warning suppress */
}

#else /* below w/o FastTerminate */

/******************************************************************************
 * Function :   OSTaskInternalDispatch
 *
 * Description: Main part of Task dispatcher (SC1, w/o FastTerminate)
 *
 * Returns:     never
 *
 * Notes:       called from OS*Dispatch and OSLeaveISR with new OsRunning set
 *
 ******************************************************************************/
OSUSE_FRAME void OSTaskInternalDispatch (void)
{
  RescheduleOnError:           /* old Task is killed before "goto" this label */
    OSOrtiSetRunningId ();

    if ((OsRunning->status & OSTCBFIRST) != 0U)  /* if task not running yet */
    {
        /* start-up the task    */
        OsRunning->status &= (OSBYTE) (~OSTCBFIRST);    /* task is running      */

        #if (OSNXTSKS > 0U)
        if ((OsRunning->status & OSTSKEXTENDED) != 0U)
        {
            OSLOADSP (OsRunning->tos);
        }
        else
        #endif
        {
            OSLOADBASICSP ();
        }

        OSSETRUNPRIO ();        /* set internal resource priority, if any */

        OSTaskEnterLabel ();

        OSSetCurApp (OsRunning->appId);
        OSOrtiResetIdOnExit (); /* set that the caller service is finished  */
        OSCallPreTaskHook ();
        OSEI ();
        OSCallTask ();          /* start task via conventional call */

        /* Task returned w/o TerminateTask  */
        OSDispatchOnError ();   /* shutdown OS in STANDARD status */
        /*
         * @violates @ref Os_scheduler_c_REF_14_4_1 MISRA 2004 Required Rule 14.4, Use of goto is deprecated
         */
        goto RescheduleOnError;
    }

    OSSetCurApp (OsRunning->appId);

    #if (OSNXTSKS > 0U)
    if ((OsRunning->status & OSTSKEXTENDED) == 0U)
    #endif
    {
        /* Restore previous value of the SPRG1 from the preempted task */
        OSLOADCONTEXTADDR (OsRunning);
    }
    /*
     * @violates @ref Os_scheduler_c_REF_16_10_1 MISRA 2004 Required Rule 16.10, Ignoring return value of function
     */
    #if defined(OSTSKFPU)
    OSLongJmp (OsRunning->pcontext, (OsRunning->status & OSTSKFLOATINGPOINT));    /* restore context of preempted task   */
    #else
    OSLongJmp (OsRunning->pcontext);    /* restore context of preempted task   */
    #endif

    /* never return to this point */
    OSWARNSUPPRESS              /* For extra CW warning suppress */
}

/******************************************************************************
 * Function :   OSTaskForceDispatch
 *
 * Description: Task dispatcher (SC1, w/o FastTerminate)
 *
 * Returns:     none
 *
 * Notes:       interrupts are disabled before call
 *
 ******************************************************************************/
void
OSTaskForceDispatch (void)
{
    OSTSKCBPTR osOldRunning;        /* pointer to currently running task CB */
    OSJMP_BUF context;

    #if defined(OSTSKFPU) /* if enable FPU */
    OSBYTE osFPU;
    #endif

    OSCheckStack ();            /* check stack overflow              */

    osOldRunning = OsRunning;

    #if defined(OSHOOKPOSTTASK)
    if (OSTSKIND (osOldRunning) != OSNULLTASK)
    {
        OSPostTaskHook ();      /* call user hook                    */
    }
    #endif /* defined(OSHOOKPOSTTASK) */

    OsRunning = OSGETMAXPRIOTASK;

    osOldRunning->pcontext = context;

    #if defined(OSTSKFPU)
    osFPU = osOldRunning->status & OSTSKFLOATINGPOINT;
    if (OSSetJmp (context, osFPU))     /* save context of preempted task    */
    #else
    if (OSSetJmp (context))     /* save context of preempted task     */
    #endif
    {                           /* return point from dispatched tasks */

        OSSETBITRUNPRIO ();     /* restore internal resource priotity */
        OSOrtiResetIdOnExit (); /* set that the caller service is finished */
        OSPreTaskHook ();
        /*
         * @violates @ref Os_scheduler_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function
         */
        return;
    }

    #if (OSNXTSKS > 0U)
    if ((osOldRunning->status & OSTSKEXTENDED) == 0U)
    #endif
    {
        /* Save previous value of the SPRG1 into preempted basic task context and */
        /* set new SPRG1 value as address of the preempted task context */
        OSSAVECONTEXTADDR (osOldRunning);
    }

    OSTaskInternalDispatch ();
}


/******************************************************************************
 * Function :   OSTaskTerminateDispatch
 *
 * Description: Reduced analog of OSTaskForceDispatch() (SC1, w/o FastTerminate) for
 *              Terminate/ChainTask services; changes Task state to SUSPENDED.
 *
 * Returns:     never
 *
 * Notes:       interrupts are disabled before call
 *
 ******************************************************************************/
void
OSTaskTerminateDispatch (void)
{
    OSCheckStack ();        /* check stack overflow */

    OSPostTaskHook ();          /* call user hook */

    OSResetInternalPrio2 ();

    if ((OSRUNNINGSTATUS & OSTCBFIRST) == 0U)
    {                           /* if ChainTask was not called */
        OSRUNNINGSTATUS &= (~OSTCBNOSUSPENDED); /* clear "nonsuspended" flag */
        OSRUNNINGSTATUS |= OSTCBFIRST;  /* set flag that task has no valid context  yet */
        OSREMOVETASK (OsRunning);
    }

    OsRunning = OSGETMAXPRIOTASK;

    OSTaskInternalDispatch ();
}
#endif /* !defined(OSNOFASTTERMINATE) */

#else /* defined(OSSC1) */



/******************************************************************************
 * Function :   OSTaskInternalDispatch
 *
 * Description: Main part of Task dispatcher for protected environment (SC2..4)
 *
 * Returns:     never
 *
 * Notes:       called from OS*Dispatch and OSLeaveISR with new OsRunning set
 *
 ******************************************************************************/

OSUSE_FRAME void OSTaskInternalDispatch (void)
{

RescheduleOnError:           /* old Task is killed before "goto" this label */
    OSOrtiSetRunningId ();

    if ((OsRunning->status & OSTCBFIRST) != 0U)  /* if task not running yet */
    {
        OSTPResumeTaskBudget ();
        /* start-up the task    */
        OsRunning->status &= (OSBYTE) (~OSTCBFIRST);    /* task is running      */

        /* Prepare stack */
        /* Note: the following code (before OSMP_TASK_OPEN_STACK) shall not use any stack memory */

        #if (OSNXTSKS > 0U)
        if ((OsRunning->status & OSTSKEXTENDED) != 0U)
        {
            OSLOADSP (OsRunning->tos);
        }
        else
        #endif

        {
            /*
            * @violates @ref Os_scheduler_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
            */
            OSLOADBASICSP ();
        }


        /*
        * @violates @ref Os_scheduler_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OSSETRUNPRIO ();        /* set internal resource priority, if any */

        OSTaskEnterLabel ();

        OSSetCurApp (OsRunning->appId);
        OSOrtiResetIdOnExit (); /* set that the caller service is finished  */
        OSCallPreTaskHook ();
        OSEI ();
        OSCallTask ();

        OSDI ();

        OSCHECKSTACK_TP (OSTPResetTaskBudget);

        OSErrorHook_noPar (E_OS_MISSINGEND);    /* Task returned w/o TerminateTask  */
        OSCLEARCNTXANDLEVELS ();
        OSPostTaskHook ();
        OSKillRunningTask ();   /* remove Task from list and clear Resources */

        /*
        * @violates @ref Os_scheduler_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OsRunning = OSGETMAXPRIOTASK;
        /*
         * @violates @ref Os_scheduler_c_REF_14_4_1 MISRA 2004 Required Rule 14.4, Use of goto is deprecated
         */
        goto RescheduleOnError;

    }

    OSTPResumeTaskBudget ();


    OSSetCurApp (OsRunning->appId);

    #if (OSNXTSKS > 0U)
    if ((OsRunning->status & OSTSKEXTENDED) == 0U)
    #endif
    {
        /* Restore previous value of the SPRG1 from the preempted task */
        OSLOADCONTEXTADDR (OsRunning);
    }

    /*
     * @violates @ref Os_scheduler_c_REF_16_10_1 MISRA 2004 Required Rule 16.10, Ignoring return value of function
     */
    #if defined(OSTSKFPU)
    OSLongJmp (OsRunning->pcontext, (OsRunning->status & OSTSKFLOATINGPOINT));    /* restore context of preempted task   */
    #else
    OSLongJmp (OsRunning->pcontext);    /* restore context of preempted task   */
    #endif /* OSTSKFPU */


    OSWARNSUPPRESS              /* For extra CW warning suppress */
}

/******************************************************************************
 * Function :   OSTaskForceDispatch
 *
 * Description: Task dispatcher for protected environment (SC2..4)
 *
 * Returns:     none
 *
 * Notes:       interrupts shall be disabled before call
 *
 ******************************************************************************/
void
OSTaskForceDispatch (void)
{
    OSTSKCBPTR osOldRunning;        /* pointer to currently running task CB */
    OSJMP_BUF context;

    #if defined(OSTSKFPU) /* if enable FPU */
    OSBYTE osFPU;
    #endif

    osOldRunning = OsRunning;

    #if defined(OSHOOKPOSTTASK) || defined(OSSYSSTKCHECK) || defined(OSTIMINGPROTECTION)
    if (OSTSKIND (osOldRunning) != OSNULLTASK)
    {
        OSPostTaskHook ();      /* call user hook       */
        OSCHECKSTACK_TP (OSTPStopTaskBudget);   /* check stack overflow and save TP state */
    }
    #endif

    /*
    * @violates @ref Os_scheduler_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    OsRunning = OSGETMAXPRIOTASK;

    osOldRunning->pcontext = context;

    #if defined(OSTSKFPU)
    osFPU = osOldRunning->status & OSTSKFLOATINGPOINT;
    if (OSSetJmp (context, osFPU))     /* save context of preempted task     */
    #else
    if (OSSetJmp (context))     /* save context of preempted task     */
    #endif
    {
        /* return point from dispatched tasks */

        /*
        * @violates @ref Os_scheduler_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OSSETBITRUNPRIO ();     /* restore internal resource priority */
        OSOrtiResetIdOnExit (); /* set that the caller service is finished */
        OSPreTaskHook ();
        /*
         * @violates @ref Os_scheduler_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function
         */
        return;
    }


    #if (OSNXTSKS > 0U)
    if ((osOldRunning->status & OSTSKEXTENDED) == 0U)
    #endif
    {
        /* Save previous value of the SPRG1 into preempted basic task context and */
        /* set new SPRG1 value as address of the preempted task context */
        OSSAVECONTEXTADDR (osOldRunning);
    }

    OSTaskInternalDispatch ();
    /* unreachable point */
}

/******************************************************************************
 * Function :   OSTaskTerminateDispatch
 *
 * Description: Reduced analog of OSTaskForceDispatch()  (SC2..4) for
 *              Terminate/ChainTask services; changes Task state to SUSPENDED.
 *
 * Returns:     never
 *
 * Notes:       interrupts shall be disabled before call
 *
 ******************************************************************************/
void
OSTaskTerminateDispatch (void)
{


    OSPostTaskHook ();          /* call user hook       */

    OSCHECKSTACK_TP (OSTPResetTaskBudget);

    OSResetInternalPrio2 ();

    if ((OSRUNNINGSTATUS & OSTCBFIRST) == 0U)
    {                           /* if ChainTask was not called */
        OSRUNNINGSTATUS &= (~OSTCBNOSUSPENDED); /* clear "nonsuspended" flag */
        OSRUNNINGSTATUS |= OSTCBFIRST;  /* set flag that task has no valid context  yet */
        OSREMOVETASK (OsRunning);
    }

    /*
    * @violates @ref Os_scheduler_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    OsRunning = OSGETMAXPRIOTASK;

    OSTaskInternalDispatch ();
    /* unreachable point */
}

#endif /* defined(OSSC1) */

/*** Public OS Services ***/

/******************************************************************************
 * Function :   Schedule
 *
 * Description: yield the processor to the task with higher priority
 *
 * Return: E_OK                       no errors
 *         E_OS_DISABLEDINT           service call while interrupts disabled
 *         E_OS_CALLEVEL (ext.status) service call from wrong context
 *         E_OS_RESOURCE              task still occupies resource
 ******************************************************************************/
StatusType
OS_Schedule (void)
{
    OSOrtiSetServiceWatch (OSServiceId_Schedule);

    #if defined(OSCHECKCONTEXT)
    if (OSIsrLevelCheck (OSISRLEVELTASK))
    {
        #if defined(OSEXTSTATUS)
        if (OsIsrLevel & OSISRLEVELDISABLEDINTERRUPTS)
        {
            /*
             * @violates @ref Os_scheduler_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function
             */
            OSRETERROR (E_OS_DISABLEDINT, OSServiceId_Schedule, 0U);
        }
        else
        #endif
        {
            /*
             * @violates @ref Os_scheduler_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function
             */
            OSRETERROR (E_OS_CALLEVEL, OSServiceId_Schedule, 0U);
        }

    }
    #endif /* defined(OSCHECKCONTEXT) */

    #if defined(OSEXTSTATUS)

    #if defined(OSUSERESLINK)
    if (OsRunning->resources != OSNULLREFRES)   /* resource is occupied */
    {
        /*
         * @violates @ref Os_scheduler_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function
         */
        OSRETERROR (E_OS_RESOURCE, OSServiceId_Schedule, 0U);

    }
    #endif /* defined(OSUSERESLINK) */



    #endif /* OSEXTSTATUS */

    OSDI ();                    /* It is not necessary to save./restore int.mask  because */
    /* this service may be called with enabled interrupts only */
    OSOrtiSetOldServiceID (OSServiceId_Schedule);

    OSResetInternalPrio ();

    /*
    * @violates @ref Os_scheduler_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
    */
    if ((OSGETMAXPRIOTASK != OsRunning)
        #if defined(OSRESOURCEISR) && (!defined(OSEXTSTATUS))
        && (OsIsrLevel == 0U)    /* Scheduler is called  only in case when */
        /* ISR resources are not occupied */
        #endif
        )
    {
        OSTaskForceDispatch ();
    }

    #if defined(OSINRES)
    else
    {
        /*
        * @violates @ref Os_scheduler_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OSSETRUNPRIO ();
    }
    #endif

    OSOrtiResetIdOnExit ();     /* set that the caller service is finished  */
    OSEI ();

    /*
     * @violates @ref Os_scheduler_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function
     */
    return (E_OK);
    /*
     * @violates @ref Os_scheduler_c_REF_14_7_1 MISRA 2004 Required Rule 14.7, Return statement before end of function
     */
    OSWARNSUPPRESS              /* For extra CW warning suppress */
}


#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_scheduler_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"



#ifdef __cplusplus
}
#endif


/** @} */
