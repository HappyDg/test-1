/**
*   @file    Os_stack_api.h
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
*   (c) Copyright 2012 - 2016 Freescale Semiconductor Inc.
*   Copyright 2017 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef OS_STACK_API_H_
#define OS_STACK_API_H_


#ifdef __cplusplus
extern "C"
{
#endif


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U)

extern OSWORD OS_GetRunningStackUsage (void);
#if defined(OSMEMPROTECTION) && (OSNXTSKS > 0U)
OSINLINE OSWORD GetRunningStackUsage (void)
{
    OSServiceCall0 (OSWORD, GetRunningStackUsage);
}
#else
#define GetRunningStackUsage() OS_GetRunningStackUsage()
#endif

extern OSWORD GetStackUsage (TaskType taskId);

#endif /* defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U) */

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif


#endif /*OS_STACK_API_H_ */

/** @} */
