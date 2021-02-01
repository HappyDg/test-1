/**
*   @file    Os_multicore_internal_types.h
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

#ifndef OS_MULTICORE_INTERNAL_TYPES_H
#define OS_MULTICORE_INTERNAL_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif


#if (OSNSPINLOCKS > 0U)

#define OSINVALID_SPINLOCK  ((SpinlockIdType)OSNSPINLOCKS)


/* Spinlock CB */
#if defined(OSEXTSTATUS) || defined(OSUSERESLINK)

typedef struct TagOSSPINLOCKCB OSSPINLOCKCB;
typedef OSSPINLOCKCB *OSSpinlockType;

struct TagOSSPINLOCKCB
{
    #if defined(OSUSERESLINK)
    OSRefResType nextRes;    /* Link to next item in the spinlock list */

    #if defined(OSRESOURCE)
    OSObjectType type;    /* resource type:  OBJECT_SPINLOCK */
    #endif
    #endif        /* defined(OSUSERESLINK) */

    #if defined(OSEXTSTATUS)
    OSObjectType owner;        /* spinlock owner (type and id of runable) */
    #endif

};
#endif            /* defined(OSEXTSTATUS) || defined(OSUSERESLINK) */

#endif            /* (OSNSPINLOCKS > 0U) */


#ifdef __cplusplus
}
#endif


#endif /*OS_MULTICORE_INTERNAL_TYPES_H */

/** @} */
