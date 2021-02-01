/**
*   @file    Os_event_api.h
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

#ifndef OS_EVENT_API_H
#define OS_EVENT_API_H

#ifdef __cplusplus
extern "C"
{
#endif    /* __cplusplus */

#include <Os_prop_autosar_api.h>
#include <Os_memory_api.h>  /* for OSServiceCallX defines */

#if ( defined(OSECC) && (OSNXTSKS > 0U) ) /* events only available in extended mode && extended tasks available */


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

/*  Public OS Services  */
extern StatusType OS_SetEvent   ( TaskType taskId, EventMaskType mask );
extern StatusType OS_ClearEvent ( EventMaskType mask );
extern StatusType OS_WaitEvent  ( EventMaskType mask );
extern StatusType OS_GetEvent   ( TaskType taskId, EventMaskRefType maskRef );

#define DeclareEvent(Event)  extern OSBYTE osdummy

/*  Public OS API  */

#define SetEvent(taskId, mask)    OS_SetEvent(taskId, mask)
#define ClearEvent(mask)          OS_ClearEvent(mask)
#define WaitEvent(mask)           OS_WaitEvent(mask)
#define GetEvent(taskId, maskRef) OS_GetEvent(taskId, maskRef)


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#endif    /* defined(OSECC) && (OSNXTSKS > 0U) */


#ifdef __cplusplus
}
#endif            /* __cplusplus */

#endif /*OS_EVENT_API_H*/

/** @} */

