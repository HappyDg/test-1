/**
*   @file    Os_orti_internal_api.h
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

#ifndef OS_ORTI_INTERNAL_API_H_
#define OS_ORTI_INTERNAL_API_H_


#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>

#ifdef OS_ORTI_USE_PROBE
#include "Os_orti_probe.h"
#else
#define OS_ORTI_PROBE_POINT()
#endif /* OS_ORTI_PROBE_POINT  */

#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#if defined(OSORTICURRENTSERVICEID)
OSDECLAREVAR (extern OSNEAR volatile OSBYTE, OsOrtiRunningServiceId_);
#define OsOrtiRunningServiceId OSUSEVAR(OsOrtiRunningServiceId_)

OSDECLAREVAR (extern OSNEAR volatile OSBYTE, OsOrtiOldServiceId_);
#define OsOrtiOldServiceId OSUSEVAR(OsOrtiOldServiceId_)
#endif /* defined(OSORTICURRENTSERVICEID) */

#if(OSORTIDEBUGLEVEL > 0U)
OSDECLAREVAR (extern OSNEAR OSBYTE, OsOrtiRunning_);
#define OsOrtiRunning OSUSEVAR(OsOrtiRunning_)
OSDECLAREVAR (extern OSNEAR StatusType, OsLastError_);
#define OsLastError OSUSEVAR(OsLastError_)
#endif

#if defined(OSISRENTRYEXIT) && defined(OSORTIRUNNINGISRID)
/* ORTI support for tracing ISR */
OSDECLAREVAR (extern OSNEAR volatile OSWORD, OSISRId_); /* the id of currently running ISR */
#define OSISRId OSUSEVAR(OSISRId_)
#endif

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSORTICURRENTSERVICEID)

/* Declaration of service watch: */
/*   run-time variable containing the identifier of */
/*   currently running OSEK OS service */

/***  Macros to handle service watch  ***/

    /* Set specified service identifier     */
    #define OSOrtiSetServiceWatch( ServiceId )           \
    {                                                    \
        OsOrtiRunningServiceId = (ServiceId) | 1U;       \
        OS_ORTI_PROBE_POINT();                           \
    }

    /* Set service watch on leaving service */
    #define OSOrtiServiceWatchOnExit( ServiceId )        \
    {                                                    \
        OsOrtiRunningServiceId = ServiceId;              \
        OS_ORTI_PROBE_POINT();                           \
    }


        /* Remember current service ID          */
#define OSOrtiSetOldServiceID( ServiceId )    (OsOrtiOldServiceId = ServiceId)

    /* Restore ID on exit (after dispatch)  */
    #define OSOrtiResetIdOnExit()                           \
        if( OsOrtiOldServiceId )                            \
        {                                                   \
            OsOrtiRunningServiceId = OsOrtiOldServiceId;    \
            OS_ORTI_PROBE_POINT();                          \
            OsOrtiOldServiceId = 0U;                        \
        }

#else /* defined(OSORTICURRENTSERVICEID) */

    #define OSOrtiSetServiceWatch( ServiceId )
    #define OSOrtiServiceWatchOnExit( ServiceId )

    #define OSOrtiSetOldServiceID( ServiceID )
    #define OSOrtiResetIdOnExit()

#endif /* defined(OSORTICURRENTSERVICEID) */


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#if(OSORTIDEBUGLEVEL > 0U)
#define OSPUTERROR( error ) OsLastError = (error);
#else /* (OSORTIDEBUGLEVEL > 0U) */
#define OSPUTERROR( error )
#endif /* (OSORTIDEBUGLEVEL > 0U) */


#if (OSORTIDEBUGLEVEL != 0U)


/* set Task Id in special variable and generate OTM for SC1,2 */
#if defined(OSUSETCB)

#if (OSORTIDEBUGLEVEL == OSORTIDEBUGLEVELSTATIC)
#define OSOrtiSetRunningId() (OsOrtiRunning = (OSBYTE)OsRunning->taskId)
#else
#define OSOrtiSetRunningId() OsOrtiRunning = (OSBYTE)OsRunning->taskId; OSSetPID0(OsOrtiRunning)
#endif

#else /* defined(OSUSETCB) */

#if (OSORTIDEBUGLEVEL == OSORTIDEBUGLEVELSTATIC)
#define OSOrtiSetRunningId() OsOrtiRunning = (OSBYTE)OsRunning
#else
#define OSOrtiSetRunningId() OsOrtiRunning = (OSBYTE)OsRunning; OSSetPID0(OsOrtiRunning)
#endif /* (OSORTIDEBUGLEVEL == OSORTIDEBUGLEVELSTATIC) */

#endif /* defined(OSUSETCB) */

#else /* (OSORTIDEBUGLEVEL != 0U) */
#define OSOrtiSetRunningId()
#endif /* (OSORTIDEBUGLEVEL != 0U) */


#ifdef __cplusplus
}
#endif



#endif /*OS_ORTI_INTERNAL_API_H_ */

/** @} */
