/**
*   @file    Os_stack_internal_api.h
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

#ifndef OS_STACK_INTERNAL_API_H_
#define OS_STACK_INTERNAL_API_H_


#ifdef __cplusplus
extern "C"
{
#endif


#include <Os_prop_autosar.h>






#if defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U) || defined(OSMEMPROTECTION)
#define OSSTKNOASSIGNED     0xFFFFU
#endif


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#if defined(OSSYSSTKCHECK)
extern void OSCheckStack (void);
#endif

#if defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U)
extern void OSFillStacks (void);
#else
#define OSFillStacks( )
#endif

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#if defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U)


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern OSWORD OSGetUsedBytes (const OSDWORD * start, OSWORD num);

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"


#if !defined(OSSTKCHECKPATTERN)
#define OSSTKCHECKPATTERN  0x55555555U  /* Pattern to used to fill the stack area */
#endif

#if !defined(OSORTISTACKPATTERN)
#define OSORTISTACKPATTERN  OSSTKCHECKPATTERN
#endif /* !defined(OSORTISTACKPATTERN) */


/***************************************************************************
* Macro:       OSSTKSETGUARD, OSSTKINVALID
*
* Description: initialize, check stack patterns
*
* Notes:       pattern size may be 1 or 2 or 4 long words
*
**************************************************************************/
#if OSSTKCHECKPATTERNSIZE == 1U
#define OSSTKINVALID(ptr)   (*(ptr) != OSSTKCHECKPATTERN)
#define OSSTKSETGUARD(ptr)   *(ptr) = OSSTKCHECKPATTERN

#elif OSSTKCHECKPATTERNSIZE == 2U
#define OSSTKINVALID(ptr)   (((ptr)[0] != OSSTKCHECKPATTERN) || ((ptr)[1] != OSSTKCHECKPATTERN))
#define OSSTKSETGUARD(ptr)   (ptr)[0] = OSSTKCHECKPATTERN; (ptr)[1] = OSSTKCHECKPATTERN

#elif OSSTKCHECKPATTERNSIZE == 4U

#define OSSTKINVALID(ptr)                                               \
    ((((ptr)[0] != OSSTKCHECKPATTERN) || ((ptr)[1] != OSSTKCHECKPATTERN)) || \
     (((ptr)[2] != OSSTKCHECKPATTERN) || ((ptr)[3] != OSSTKCHECKPATTERN)))

#define OSSTKSETGUARD(ptr)                                      \
    (ptr)[0] = OSSTKCHECKPATTERN; (ptr)[1] = OSSTKCHECKPATTERN; \
    (ptr)[2] = OSSTKCHECKPATTERN; (ptr)[3] = OSSTKCHECKPATTERN
#endif


#endif /* defined(OSSTKCHECK) || (OSORTIDEBUGLEVEL > 0U) */


#ifdef __cplusplus
}
#endif


#endif /*OS_STACK_INTERNAL_API_H_ */

/** @} */
