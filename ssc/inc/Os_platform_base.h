/**
*   @file    Os_platform_base.h
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

#ifndef OS_PLATFORM_BASE_H
#define OS_PLATFORM_BASE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_platform.h>

/*
 * this file will include base addresses for the specific platform
 * will be on platform specific branch
 * now contains defines for all the platforms
 *
 */

/*
 *  Timer base addresses ***********************************************************************************************
 */






























#define OSPITBASE       (0x40037000UL)  /**< PIT base address */
#define OSFTM0BASE      (0x40038000UL)  /**< FTM0 base address */
#define OSFTM1BASE      (0x40039000UL)  /**< FTM1 base address */
#define OSFTM2BASE      (0x4003A000UL)  /**< FTM2 base address */
#define OSFTM3BASE      (0x40026000UL)  /**< FTM3 base address */
#define OSFTM4BASE      (0x4006E000UL)  /**< FTM4 base address */
#define OSFTM5BASE      (0x4006F000UL)  /**< FTM5 base address */
#define OSFTM6BASE      (0x40070000UL)  /**< FTM6 base address */
#define OSFTM7BASE      (0x40071000UL)  /**< FTM7 base address */
#define OSSYSTICKBASE   (0xE000E010UL)  /**< SYSTICK base address */



/*
 * INTC base address ***************************************************************************************************
 */







/*
 *  SEMA4 base addresses **************************************************************************************************
 */






/*
 *  CRP base addresses **************************************************************************************************
 */



/*
 *  MC_ME base addresses **************************************************************************************************
 */



/*
 *  SSCM base addresses **************************************************************************************************
 */













#ifdef __cplusplus
}
#endif

#endif /*OS_PLATFORM_BASE_H */

/** @} */
