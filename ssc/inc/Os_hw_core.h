/**
*   @file    Os_hw_core.h
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

#ifndef OS_HW_CORE_H_
#define OS_HW_CORE_H_

#ifdef __cplusplus
extern "C"
{
#endif


#include <Os_hw_core_compiler.h>

#define OSREG32( address ) /*lint -save -e923 -e960 */ ( *(volatile OSDWORD*)(address) ) /*lint -restore */ /* 32-bit register */
#define OSREG16( address ) /*lint -save -e923 -e960 */ ( *(volatile OSWORD *)(address) ) /*lint -restore */ /* 16-bit register */
#define OSREG8( address )  /*lint -save -e923 -e960 */ ( *(volatile OSBYTE *)(address) ) /*lint -restore */ /*  8-bit register */




#define OSMSR_PRIMASKBIT0   (0x00000001ul) /**< primask register bit0 */

#define OSARMCM4_BFSR       (0xE000ED29ul)
#define OSARMCM4_BFAR       (0xE000ED38ul)

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern void OSNmiException (void);
extern void OSHardFaultException (void);
extern void OSBusFaultException (void);
extern void OSUsageFaultException (void);
extern void OSSVCallException (void);
extern void OSDebugMonitorException (void);
extern void OSPendSVException (void);

extern void OSReservedException (void);

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"




#ifdef __cplusplus
}
#endif


#endif /*OS_HW_CORE_H_*/

/** @} */

