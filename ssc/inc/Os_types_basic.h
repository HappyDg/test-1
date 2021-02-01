/**
*   @file    Os_types_basic.h
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

#ifndef OS_TYPES_BASIC_H
#define OS_TYPES_BASIC_H


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include    <Std_Types.h>        /**< Standard type header - from MCAL  */

/*
 * only the basic types
 */

typedef unsigned char OSBYTE;
typedef unsigned char *OSBYTEPTR;

typedef unsigned short OSWORD;
typedef signed short OSSHORT;

typedef unsigned short *OSWORDPTR;
typedef unsigned int OSDWORD;

#if defined(OSDS5ARM)
#pragma diag_suppress 450
#endif
    typedef unsigned long long OSQWORD;
#if defined(OSDS5ARM)
#pragma diag_default 450
#endif

typedef unsigned int OSCARDINAL;

typedef signed int OSSIGNEDDWORD;

#if defined(OSDS5ARM)
#pragma diag_suppress 450
#endif
    typedef signed long long OSSIGNEDQWORD;
#if defined(OSDS5ARM)
#pragma diag_default 450
#endif


#include <Os_compiler_api.h>     /**< for OSNEAR, OSASM, OSINLINE */

#include <Os_hw_core_compiler_api.h>





#define OSDECLAREVAR(var_type, var) var_type var
#define OSUSEVAR(var) var
#define OSGETCOREIND



#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /*OS_TYPES_BASIC_H */

/** @} */
