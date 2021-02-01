/**
*   @file    Os_multicore_internal_api.h
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

#ifndef OS_MULTICORE_INTERNAL_API_H_
#define OS_MULTICORE_INTERNAL_API_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <Os_prop_autosar.h>

#include <Os_multicore_internal_types.h>
#include <Os_alarm_internal_types.h>

#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"




#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*OS_MULTICORE_INTERNAL_API_H_ */

/** @} */
