/**
*   @file    Os_setup_internal_api.h
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

#ifndef OS_SETUP_INTERNAL_API_H_
#define OS_SETUP_INTERNAL_API_H_


#ifdef __cplusplus
extern "C"
{
#endif


#include <Os_prop_autosar.h>
#include <Os_types_common_public.h>     /* for AppModeType */

#include <Os_setup_internal_types.h>
#include <Os_application_config.h>


#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if (OSORTIDEBUGLEVEL > 0U) || (OSNAPPMODES > 1U)
extern AppModeType OsCurAppMode;
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"


#define OSMODE     0            /* application mode */


#if(OSNAPPMODES > 1U)
        #define OSCURAPPMODE OsCurAppMode
#else
    #define OSCURAPPMODE OSDEFAULTAPPMODE
#endif /* (OSNAPPMODES > 1U) */

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern void OSShutdownOS (StatusType error);

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#if defined(OSHOOKSCHEDULER)    /* not configurable by OIL */

#define OSHOOK_START_SEC_CODE
#include "Os_memmap.h"

extern void IdleLoopHook (void);

#define OSHOOK_STOP_SEC_CODE
#include "Os_memmap.h"

#endif



#ifdef __cplusplus
}
#endif


#endif /*OS_SETUP_INTERNAL_API_H_ */

/** @} */
