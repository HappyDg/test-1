/**
*   @file    Os_isr_config.h
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

#ifndef OS_ISR_CONFIG_H_
#define OS_ISR_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar.h>

#include <Os_types_basic.h>     /* for OSSHORT ... */
#include <Os_types_common_internal.h>

#include <Os_platform_config.h>

#include <Os_tp_internal_types.h>       /* for OSTPRESLOCK */

#if (OSNISR > 0U)

struct tagISRCFGTYPE
{

    OSVOIDFUNCVOID userISR;     /* actual ISR function */
    OSISRTYPE type;             /* type of the ISR */
    OSWORD index;               /* Index of interrupt in the external interrupts table */
    OSBYTE isrPrio;             /* Interrupt priority */


    #if defined(OSAPPLICATION)
    OSAPPLICATIONTYPE appId;    /* application identification value */
    #endif
};

typedef struct tagISRCFGTYPE OSISRCFGTYPE;

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

        /* Interrupts configuration table */
extern const OSISRCFGTYPE OsIsrCfg[OSNISR + 1U];

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#endif



#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"


extern const OSSHORT OsIsr[OSNINTC];             /**< one interrupt controller in single core */

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#define OSISREXCEPTIONIDX  OSNINTC      /* reserved vector number of INTC  */
#define OSISREXCEPTIONPRIO 1


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

extern void OSISRException (void);

#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif

#endif /*OS_ISR_CONFIG_H_ */

/** @} */
