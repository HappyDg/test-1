/**
*   @file    Os_memory_internal_api.h
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

#ifndef OS_MEMORY_INTERNAL_API_H_
#define OS_MEMORY_INTERNAL_API_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <Os_prop_autosar.h>

#include <Os_types_basic.h>     /* for OSDWORD */
#include <Os_types_common_internal.h>   /* for OSAPPLICATIONTYPE */

#include <Os_memory_types.h>    /* for RestartType */
#include <Os_memory_internal_types.h>








#if defined(OSEXTSTATUS)

#define OSCHECKWRITEACCESS( address, size, ID, param )   \
    if( 0 == (address) )                                 \
    {                                                    \
        OSRETERROR( E_OS_PARAM_POINTER, (ID), (param) ); \
    }

#if defined(OSIOC)

#define OSIOCCHECKWRITEACCESS( address, size ) \
    if( 0 == (address) )                       \
    {                                          \
        return IOC_E_NOK;                      \
    }

#define OSIOCCHECKREADACCESS( address, size ) \
    if( 0 == (address) )                      \
    {                                         \
        return IOC_E_NOK;                     \
    }

#endif /* defined(OSIOC) */

#else /* defined(OSEXTSTATUS) */

#define OSCHECKWRITEACCESS( address, size, ID, param )

#if defined(OSIOC)

#define OSIOCCHECKWRITEACCESS( address, size )
#define OSIOCCHECKREADACCESS( address, size )

#endif

#endif /* defined(OSEXTSTATUS) */




#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"


/* Prototypes of core exception handlers */
extern void OSExceptionError (OSDWORD exception_address, OSDWORD ea_valid);

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_MEMORY_INTERNAL_API_H_ */

/** @} */
