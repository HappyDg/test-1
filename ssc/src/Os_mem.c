/**
*   @file    Os_mem.c
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
* @section Os_mem_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters.
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character.
* Compilers are checked for support this length of identifiers.
*
* @section Os_mem_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_mem_c_REF_16_10_1
* Violates MISRA 2004 Required Rule 16.10, Ignoring return value of function
* If a function returns error information, then that error information shall be tested.
* Function OSLongJmp is used for switching context and it is not supposed
* to return to the place where it is called.
*
* @section Os_mem_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used to increase of OS performance.
*
* @section Os_mem_c_REF_19_1_1
* Violates MISRA 2004 Advisory Rule 19.1, declaration before #include
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* MemMap is required by AutoSAR to be included in the middle of the source file(s).
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

#include <Os_task_api.h> /* for INVALID_TASK */
#include <Os_isr_api.h> /* for INVALID_ISR */
#include <Os_resource_internal_api.h>

#include <Os_memory_api.h>
#include <Os_memory_types.h>
#include <Os_memory_internal_api.h>
#include <Os_memory_internal_types.h>




#define OS_START_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#define OS_STOP_SEC_VAR_UNSPECIFIED
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"

#define OSTEXT_START_SEC_CODE
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


/**** linker defined symbols for ProtectionHandler ****/
extern char OS_BEGIN_DSADDR (ostext)[];    /* beginning of OS code section */
extern char OS_END_DSADDR (ostext)[];      /* end of OS code section */


/* local functions prototypes */
#if defined(OSHOOKPROTECTION)
static void OSProtectionHandler (StatusType ecode);
#endif







/***************************************************************************
 * inline function:    OSExceptionExit
 *
 * Description: calls ProtectionHandler or ShutdownOS
 *
 * Returns:     never
 *
 **************************************************************************/
OSINLINE void
OSExceptionExit (StatusType ecode, OSDWORD exception_address, OSDWORD ea_valid)
{


    OSPUTERROR (ecode);

    #if defined( OSHOOKPROTECTION )

        if (
            /* if exception occurs in OS code itself */
            ( ea_valid && (exception_address >= (OSDWORD) OS_BEGIN_DSADDR (ostext)) && (exception_address < (OSDWORD) OS_END_DSADDR (ostext)) )
            || (OsIsrLevel & OSISRLEVELHOOKANYSYSTEM) /* if exception occurs in any system-wide hooks */
            #if (OSNISR > 0)
            || (OSISRGetPrio () > OSHIGHISRPRIO) /* if exception occurs not in TASK or ISR cat.2  */
            #endif
            || (OSTRUE != OsStarted) /* if exception occurs before OsStarted variable initialization */
          )
        {
            OSShutdownOS (ecode);
        }

        OSProtectionHandler (ecode);

    #else

        OSShutdownOS (ecode);

    #endif /* defined( OSHOOKPROTECTION ) */
}

/***************************************************************************
 * Function:    OSExceptionError
 *
 * Description: it is called when critical or noncritical core exception occurs
 *
 * Returns:     never
 *
 **************************************************************************/
void
OSExceptionError (OSDWORD exception_address, OSDWORD ea_valid)
{
    StatusType ecode;

    ecode = E_OS_PROTECTION_EXCEPTION;

    OSExceptionExit (ecode, exception_address, ea_valid);
}




#if defined(OSHOOKPROTECTION)
/****************************************************************************************
 * Function:    OSProtectionHandler
 *
 * Description: called from Memory and CPU exception handlers
 *
 * Returns:     never
 *
 ****************************************************************************************/
static void
OSProtectionHandler (StatusType ecode)
{
    ProtectionReturnType action;
    #if defined(OSAPPHOOKSTARTUP) || defined(OSAPPHOOKSHUTDOWN)
    OSISRLEVELTYPE apphook;
    #endif

    #if defined(OSAPPLICATION)
    RestartType restart = NO_RESTART;

    OsViolatorAppId = OS_MKOBJID (OBJECT_APPLICATION, (ApplicationType)OSGetCurApp ());
    #endif

    OsViolatorTaskId = INVALID_TASK;
    OsViolatorISRId = INVALID_ISR;

    #if defined(OSAPPHOOKSTARTUP) || defined(OSAPPHOOKSHUTDOWN)
    apphook = OsIsrLevel & (OSISRLEVELHOOKAPPSTARTUP | OSISRLEVELHOOKAPPSHUTDOWN);
    #endif

    #if !defined(OSNOISR2)
    if (OSISRLEVELMASKED != 0U)
    {
        OSWORD handlerId;
        /*
        * @violates @ref Os_mem_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        handlerId = OsIsrArray[OSISRLEVELMASKED - 1U] - &OsIsrTable[0];
        OsViolatorISRId = OS_MKOBJID (OBJECT_ISR, handlerId);
    }
    else
    #endif
    #if defined(OSAPPHOOKSTARTUP) || defined(OSAPPHOOKSHUTDOWN)
    if (apphook == 0U)
    #endif
    {   /* if it's not context of app. spec. Startup/Shutdown hooks */
        if (OSTSKIND (OsRunning) != OSNULLTASK)
        {
            OsViolatorTaskId = OS_MKOBJID (OBJECT_TASK, OSTSKIND (OsRunning));
        }
    }
    #if defined(OSAPPHOOKSTARTUP) || defined(OSAPPHOOKSHUTDOWN)
    else
    {
        /* to satisfy MISRA Violates MISRA 2004 Required Rule 14.10, no 'else' at end of 'if ... else if' chain */
    }
    #endif

    OSOrtiSetServiceWatch (OSServiceId_ProtectionHook); /* set watch to this service */
    OSSETPROTCNXT ();
    OSCLEARSUSPENDLEVELS ();    /* [OS093] */
    action = ProtectionHook (ecode);
    OSCLRPROTCNTX ();
    OSOrtiServiceWatchOnExit (OSServiceId_ProtectionHook);      /* clear service watch on hook leaving */

    #if defined(OSAPPHOOKSTARTUP) || defined(OSAPPHOOKSHUTDOWN)
    if (apphook != 0U)
    {                           /* if an exception occurred in Startup/Shutdown app. spec. hooks */
        OSShutdownOS (ecode);
    }
    #endif

    switch (action)
    {
        case PRO_KILLTASKISR:
            #if (OSNUSERISR > 0U)
            if (OSISRLEVELMASKED != 0U)
            {
                OSKillRunningISR ();
            }
            else
            #endif /* OSNUSERISR > 0 */
            {
                if (OSTSKIND (OsRunning) != OSNULLTASK)
                {
                    OSKillTask (OsRunning);
                }
                #if defined(OSAPPLICATION)
                else if (OSTerminateApplication ((OSAPPLICATIONTYPE)(OS_GETOBJIND (OsViolatorAppId)), NO_RESTART))
                {   /* if no running Task or ISR found */
                    break;
                }
                #endif
                else
                {
                    OSShutdownOS (ecode);
                }
            }
            break;

        case PRO_KILLAPPL_RESTART:
            #if defined(OSAPPLICATION)
            #if defined(OSHAS_RESTARTTASK)
            if (OsAppTable[OS_GETOBJIND (OsViolatorAppId)].restartTask == OSINVALID_TASK)
            #endif
            {
                /* no restart task was configured for the faulty OS-Application (OS557) */
                OSShutdownOS (ecode);
            }
            restart = RESTART;  /* no break */
            #endif /* defined(OSAPPLICATION) */

        case PRO_KILLAPPL:
            #if defined(OSAPPLICATION)
            if (OSTerminateApplication ((OSAPPLICATIONTYPE)(OS_GETOBJIND (OsViolatorAppId)), restart))
            {
                break;
            }
            /* no break. OSShutdownOS() shall be called */
            #endif
        case PRO_SHUTDOWN:
        default:
            OSShutdownOS (ecode);
    }
    OSDI ();

    if (((OsKilled & OSRUNTSKKILLED) != 0U)
        #if defined(OSISRENTRYEXIT)
        && (OSISRLEVELMASKED == 0U)
        #endif
        )
    {
        OSSETTASKMSR ();        /* set MSR for Task, EE = 1 */
        /*
        * @violates @ref Os_mem_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
        */
        OsRunning = OSGETMAXPRIOTASK;
        OsKilled &= ~OSRUNTSKKILLED;
        OSTaskInternalDispatch ();
        /* no return here */
    }
    #if (OSNIPLS > 0U)

    /* otherwise running ISR is killed - no other option */

    OsIsrLevel--;
    /*
     * @violates @ref Os_mem_c_REF_16_10_1 MISRA 2004 Required Rule 16.10, Ignoring return value of function
     * @violates @ref Os_mem_c_REF_17_4_1 MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
     */
    #if defined(OSTSKFPU)
    OSLongJmp (OsISRbufs[OSISRLEVELMASKED], OsRunning->status & OSTSKFLOATINGPOINT);    /* back to OSInterruptDispatcher */
    #else
    OSLongJmp (OsISRbufs[OSISRLEVELMASKED]);    /* back to OSInterruptDispatcher */
    #endif /* OSTSKFPU */
    #endif
}
#endif /* defined(OSHOOKPROTECTION) */

#define OSTEXT_STOP_SEC_CODE
/*
* @violates @ref Os_mem_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif


/** @} */
