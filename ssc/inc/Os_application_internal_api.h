/**
*   @file    Os_application_internal_api.h
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
#ifndef OS_APPLICATION_INTERNAL_API_H_
#define OS_APPLICATION_INTERNAL_API_H_


#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_types_common_internal.h>
#include <Os_application_internal_types.h>
#include <Os_application_config.h> /**< for OSAPP */

#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


#if defined(OSAPPLICATION)
#if defined(OSAPPIDRAM)
OSDECLAREVAR (extern OSNEAR OSAPPLICATIONTYPE, OsAppID_);       /* Current application Id */
#define OsAppID OSUSEVAR(OsAppID_)
#endif
#endif /* defined(OSAPPLICATION) */

#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSAPPLICATION)

extern void OSInitApplications (void);  /* making OsAppTable of OsCfgAppTable */
extern OSWORD OSTerminateApplication (OSAPPLICATIONTYPE appId, RestartType RestartOption);


#endif /* defined(OSAPPLICATION) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#if defined(OSAPPLICATION)

#define OSCURRENTAPPMASK         ((OSAPPLICATIONMASKTYPE)(1U << (OSGetCurApp())))
#define OSGIVENAPPMASK(appInd)   ((OSAPPLICATIONMASKTYPE)(1U << (appInd)))
#endif


#if defined(OSAPPLICATION)

#if defined(OSAPPIDRAM)         /* Current AppID is stored in RAM */
             /* Current AppID is stored in RAM */
             /* Get current application Id */
    #define OSGetCurApp() (OsAppID)

             /* Set current application Id */
    #define OSSetCurAppId(appId) (OsAppID = (OSAPPLICATIONTYPE)(appId))

#else /* OSAPPIDRAM */


    #error "HW support for OSGetCurApp(),OSSetCurAppId() is not available on this platform"


#endif /* defined(OSAPPIDRAM) */


#define OSSetCurApp(appId) (OSSetCurAppId(appId))

#else

#define OSSetCurApp(arg)

#endif /* defined(OSAPPLICATION) */

#if defined(OSAPPLICATION)



#define OSSETAPPSTATE(index, value) \
    OsAppTable[index].state = value

#define OSGETAPPSTATE(index) OsAppTable[index].state





#define OSCHECKACCESSRIGHTS( mask, ID, param ) \
    if( ( OSCURRENTAPPMASK & (mask)) == 0U ) \
    { \
        OSRETERROR( E_OS_ACCESS, (ID), (param) ); \
    }

#define OS2CHECKACCESSRIGHTS( mask, appId ) \
    if( ( OSGIVENAPPMASK( appId ) & (mask)) == 0U ) \
    { \
       return E_OS_ACCESS; \
    }

#define OSCHECKACCESSRIGHTSRI( mask, ID, param ) \
    if( ( OSCURRENTAPPMASK & (mask)) == 0U ) \
    { \
        OSRI( save ); \
        OSRETERROR( E_OS_ACCESS, (ID), (param) ); \
    }

#define OSCHECKACCESSRIGHTSEI( mask, ID, param ) \
    if( ( OSCURRENTAPPMASK & (mask)) == 0U ) \
    { \
        OSEI( ); \
        OSRETERROR( E_OS_ACCESS, (ID), (param) ); \
    }

#define OSIOCCHECKACCESSRIGHTS( mask )    \
    if( ( OSCURRENTAPPMASK & (mask)) == 0U ) \
    { \
        return IOC_E_NOK; \
    }

#else /* defined(OSAPPLICATION) */

#define OSCHECKACCESSRIGHTS( mask, ID, param )

#define OS2CHECKACCESSRIGHTS( mask, appId )
#define OSCHECKACCESSRIGHTSRI( mask, ID, param )
#define OSCHECKACCESSRIGHTSEI( mask, ID, param )

#endif /* defined(OSAPPLICATION) */

#ifdef __cplusplus
}
#endif

#endif /*OS_APPLICATION_INTERNAL_API_H_ */

/** @} */
