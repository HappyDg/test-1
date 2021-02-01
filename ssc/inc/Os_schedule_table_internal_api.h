/**
*   @file    Os_schedule_table_internal_api.h
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

#ifndef OS_SCHEDULE_TABLE_INTERNAL_API_H_
#define OS_SCHEDULE_TABLE_INTERNAL_API_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <Os_prop_autosar.h>

#include <Os_schedule_table_internal_types.h>

#if defined(OSSCHEDULETABLES)


#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if (OSNALMS > 0U)
#if (OSNSCTALMS > 0U) && (OSNUSERALMS == 0U)
extern OSSCTALMCB OsSCTAlarms[OSNSCTALMS];
#endif
#endif    /* (OSNALMS > 0U) */

extern OSSCTCB OsScheduleTables[OSNSCTS];

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_sections.h"

#if (OSNUSERALMS == 0U)
#define OSALMSCTARRAY OsSCTAlarms
#else
#define OSALMSCTARRAY OsAllAlarms.OsSCTAlarms
#endif

/* Bits in schedule table status (field in TagOSSCTCB structure ) */
#define OSSCTCBDIRSIGN  ((OSWORD)0x10)  /* Schedule table correct.direction flag */
#define OSSCTCBSYNCUP   ((OSWORD)0x20)  /* Schedule table sync.correction flag */
#define OSSCTCBEND      ((OSWORD)0x80)  /* flag of Schedule table end */
#define OSSCTCBSTATUS   ((OSWORD)0x0F)  /* mask for Schedule table status bits */

/* Masks for Schedule Table configuration 'state' field */
#define OSSCTCFGPERIODICMASK    ((OSWORD)0x100) /* Schedule table is periodic */

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

/*  Private OS Services */
extern void OSInitScheduleTables (void);
extern OSAlmType OSProcessScheduleTable (OSSCTALMCB * almId);

#if defined(OSNAUTOSCTS)
#if (OSNAPPMODES > 1U)
extern void OSInitAutoScheduleTables (AppModeType mode);
#else
extern void OSInitAutoScheduleTables (void);
#endif
#endif /* defined(OSNAUTOSCTS) */

#if defined(OSAPPLICATION)
extern void OSKillAppScheduleTables (OSAPPLICATIONTYPE appId);
#endif


#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#endif /* defined(OSSCHEDULETABLES) */


#ifdef __cplusplus
}
#endif


#endif /*OS_SCHEDULE_TABLE_INTERNAL_API_H_ */

/** @} */
