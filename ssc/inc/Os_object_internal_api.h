/**
*   @file    Os_object_internal_api.h
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

#ifndef OS_OBJECT_INTERNAL_API_H
#define OS_OBJECT_INTERNAL_API_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>
#include <Os_object_api.h>      /* get the missing defines back to the original files */



#if defined(OSEXTSTATUS) || defined(OSCOMEXTSTATUS)
#define OSCALCULATEOBJIND
#define OS_GETOBJTYP(ObjId) ((ObjectTypeType)((ObjId) >> OSOBJSHIFT)) /* macro to get Object Type, assuming bits[14,15] == 0 */
#endif





#if defined(OSEXTSTATUS)
#define OSIDISINVALID(id, type, limit) ((OS_GETOBJTYP(id) != ((ObjectTypeType)(type))) || (id >= OS_MKOBJID((type),(limit))))
#endif


#if defined(OSEXTSTATUS)
#define OSAPPIDISINVALID(id)  (OSIDISINVALID((id), OBJECT_APPLICATION, OSNAPPS))
#else /* defined(OSEXTSTATUS) */
#define OSAPPIDISINVALID(id)  ((id) >= OSNAPPS)
#endif /* defined(OSEXTSTATUS) */


#if defined(OSEXTSTATUS)

#define OSTASKIDISINVALID(id) (OSIDISINVALID((id), OBJECT_TASK, OSNTSKS))

#if (OSNISR > 0U)
#define OSISRIDISINVALID(id)  (OSIDISINVALID((id), OBJECT_ISR, OSNISR))
#endif

#if defined(OSRESOURCE)
#define OSRESIDISINVALID(id)  (OSIDISINVALID((id), OBJECT_RESOURCE, OSNALLRES_))
#endif

#define OSCTRIDISINVALID(id)  (OSIDISINVALID((id), OBJECT_COUNTER, OSNCTRS))

#if (OSNUSERALMS > 0U)
#define OSALMIDISINVALID(id)  (OSIDISINVALID((id), OBJECT_ALARM, OSNUSERALMS))
#endif

#if defined(OSSCHEDULETABLES)
#define OSSCTIDISINVALID(id)  (OSIDISINVALID((id), OBJECT_SCHEDULETABLE, OSNSCTS))
#endif

#endif /* defined(OSEXTSTATUS) */


#if defined(OSUSETCB) || defined(OSINRES)
#define OSISTASKNOSUSPEND(taskId)   (OSTASKSTATUS(taskId) & OSTCBNOSUSPENDED)
#else
#define OSISTASKNOSUSPEND(taskId)   (OSCHECKTASKSTATUS(taskId))
#endif

#define OSTASKACTEXHAUSTED(taskId)  (OSISTASKNOSUSPEND(taskId))

#ifdef __cplusplus
}
#endif

#endif /*OS_OBJECT_INTERNAL_API_H */

/** @} */
