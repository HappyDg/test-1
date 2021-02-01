/**
*   @file    Os_platform_config.h
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

#ifndef OS_PLATFORM_CONFIG_H
#define OS_PLATFORM_CONFIG_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_platform.h>

/*
 * platform specific file
 * placed on platform branch
 * because of this we have only defines for specific platforms and derivatives
 */

/*
 *  core configuration *********************************************************
 */














/*
 * INTC configuration - interrupt table length *********************************
 */


























#define OSNINTC (163U)

/*
 *  Timers available on configuration ******************************************
 */























#define OSTIMPIT_TYPE4



#ifdef __cplusplus
}
#endif

#endif /*OS_PLATFORM_CONFIG_H */

/** @} */
