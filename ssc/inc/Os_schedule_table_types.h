/**
*   @file    Os_schedule_table_types.h
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

#ifndef OS_SCHEDULE_TABLE_TYPES_H_
#define OS_SCHEDULE_TABLE_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_autosar_api.h>
#include <Os_types_common_public.h>     /* for OSObjectType, TickType ... */

#if defined(OSSCHEDULETABLES)
typedef OSObjectType ScheduleTableType; /* the index in 'the Schedule Table' array */
typedef TickType GlobalTimeTickType;    /* the global time source type */
typedef unsigned char ScheduleTableStatusType;  /* the status of a Schedule Table */
typedef ScheduleTableStatusType *ScheduleTableStatusRefType;    /* points to a variable of the data type ScheduleTableStatusType */
#endif

#ifdef __cplusplus
}
#endif


#endif /*OS_SCHEDULE_TABLE_TYPES_H_ */

/** @} */
