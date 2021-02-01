/**
*   @file    Os_compiler_api.h
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

#ifndef OS_COMPILER_API_H
#define OS_COMPILER_API_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef _lint
#define OSLINT                _lint
#endif




#if defined(OSGHSARM)
#include <arm_ghs.h>            /* for intrinsic functions only */
#endif



#if !defined(OSGCCARM) && !defined(OSGHSARM) && !defined(OSDS5ARM) && !defined(OSIARARM)
#error "Compiler is not defined"
#endif






#if defined(OSGCCARM)
#define OSASM                 asm volatile
#endif /* defined(OSGCCARM) */

#if defined(OSGHSARM)
#define OSASM                 asm
#endif /* defined(OSGHSARM) */

#if defined(OSDS5ARM)
#define OSASM                 __asm
#endif /* defined(OSDS5ARM) */

#if defined(OSIARARM)
#define OSASM                 __asm volatile
#endif /* defined(OSIARARM) */







#if defined(OSGCCARM)
/* small data,const sections not available for ARM */
#define OSNEAR
#define OSNEARCONST
#endif

#if defined(OSGHSARM)
/* small data,const sections not available for ARM */
#define OSNEAR
#define OSNEARCONST
#endif

#if defined(OSDS5ARM)
/* small data,const sections not available for ARM */
#define OSNEAR
#define OSNEARCONST
#endif

#if defined(OSIARARM)
/* small data,const sections not available for ARM */
#define OSNEAR
#define OSNEARCONST
#endif






#define OSNONCACHE



/*
 * definitions for INLINE functions
 * these are needed in the public API
 */




#if defined(OSGCCARM)
#define OSINLINE                static inline __attribute__((always_inline))
#endif /* defined(OSGCCARM) */

#if defined(OSGHSARM)
#ifdef __cplusplus
#define OSINLINE                inline
#else
#define OSINLINE              __inline
#endif
#endif /* defined(OSGHSARM) */

#if defined(OSDS5ARM)
#define OSINLINE                static __inline
#endif /* defined(OSDS5ARM) */

#if defined(OSIARARM)
#define OSINLINE                static inline
#endif /* defined(OSIARARM) */




#ifdef OSLINT
#define OSINLINE_
#else
#define OSINLINE_ OSINLINE
#endif


#ifdef __cplusplus
}
#endif

#endif /*OS_COMPILER_API_H */

/** @} */
