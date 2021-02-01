/**
*   @file    Os_memory_types.h
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

#ifndef OS_MEMORY_TYPES_H_
#define OS_MEMORY_TYPES_H_


#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar_api.h>
#include <Os_types_common_public.h>

/*
* needed in the API
*/
typedef void  *TrustedFunctionParameterRefType;
typedef OSWORD TrustedFunctionIndexType;

typedef void   *MemoryStartAddressType;
typedef OSDWORD MemorySizeType;

/*
* AccessType holds information how a
* specific memory region can be accessed
*/
typedef OSBYTE   AccessType;
#define OSMP_R ((AccessType)1)
#define OSMP_W ((AccessType)2)
#define OSMP_E ((AccessType)4)
#define OSMP_S ((AccessType)8)


#ifdef __cplusplus
}
#endif

#endif /*OS_MEMORY_TYPES_H_*/

/** @} */

