/**
*   @file    Os_application_api.h
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

#ifndef OS_APPLICATION_API_H_
#define OS_APPLICATION_API_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar_api.h>
#include <Os_application_types.h>

#include <Os_memory_api.h>

 /*
  * API in this file
  *
  * CheckObjectAccess
  * CheckObjectOwnership
  *
  * GetApplicationID
  * TerminateApplication
  * AllowAccess
  * GetApplicationState
  *
  */

 /*
  * return value for CheckObjectOwnership and GetApplicationID
  */
#define INVALID_OSAPPLICATION   ((ApplicationType)OS_MKOBJID(OBJECT_APPLICATION, OSNAPPS))

#if defined(OSAPPLICATION)

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern ObjectAccessType OS_CheckObjectAccess (ApplicationType appId, ObjectTypeType objectType, OSObjectType objectId);
extern ApplicationType OS_CheckObjectOwnership (ObjectTypeType objectType, OSObjectType objectId);
extern ApplicationType OS_GetApplicationID (void);


extern StatusType OS_GetApplicationState (ApplicationType appId, ApplicationStateRefType stateRef);
extern StatusType OS_AllowAccess (void);

extern StatusType OS_TerminateApplication (ApplicationType appId, RestartType RestartOption);


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#endif /* defined(OSAPPLICATION) */

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"




#define CheckObjectAccess( appId, objectType, objectId )    OS_CheckObjectAccess( appId, objectType, objectId )
#define CheckObjectOwnership( objectType, objectId   )      OS_CheckObjectOwnership( objectType, objectId )

#define GetApplicationID()                                  OS_GetApplicationID()

#define AllowAccess()                                       OS_AllowAccess( )
#define GetApplicationState( appId, stateRef )              OS_GetApplicationState( appId, stateRef )

#define TerminateApplication( appId, RestartOption )        OS_TerminateApplication( appId, RestartOption )



#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif

#endif /*OS_APPLICATION_API_H_ */

/** @} */
