/**
*   @file    Os_tp_v3.c
*   @version 4.0.98
*
*   @brief   AUTOSAR OS - Brief file description (one line).
*   @details timing protection for Autosar V3 and V4
*    Notes: Configuration macros:
*    OSNTPBGTS           - number of tasks and ISRs with execution budget
*    OSNTPTSKBGTS        - number of tasks with execution budget
*    OSNTPISRBGTS        - number of ISR2s with execution budget
*    OSNTPTSKARRIV       - number of tasks with ISR arrival rate
*    OSNTPISRARRIV       - number of ISR2s with ISR arrival rate
*    OSNTPTSKINTLOCKTIME - number of tasks with OS interrupt locking Time
*    OSNTPISRINTLOCKTIME - number of ISR2s with OS interrupt locking Time
*    OSNTPTSKRESLOCKTIME - number of tasks with at least one resource locking Time
*    OSNTPISRRESLOCKTIME - number of ISR2s with at least one resource locking Time
*    OSNTPTSKRESLOCKS    - number of all resource locking time configurations for tasks
*    OSNTPISRRESLOCKS    - number of all resource locking time configurations for ISRs
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

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Os_tp_v3_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters.
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character.
* Compilers are checked for support this length of identifiers.
*
* @section Os_tp_v3_c_REF_14_7_1
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function
* A function shall have a sigle point of exit at the end of finction.
* The returned statement is result of error hanling.
*
* @section Os_tp_v3_c_REF_17_4_1
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* Array indexing shall be the only allowed form of pointer arithmetic
* The pointers are used to increase of OS performance.
*
* @section Os_tp_v3_c_REF_19_1_1
* Violates MISRA 2004 Advisory Rule 19.1, declaration before #include
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* MemMap is required by AutoSAR to be included in the middle of the source file(s).
*/



/****************** generic includes START ***********************/
#include <Os_prop_autosar.h>

#include <Os_types_basic.h>

#include <Os_types_public.h>
#include <Os_types_common_public.h>
#include <Os_types_common_internal.h>

#include <Os_internal_api.h>
#include <Os_internal_types.h>
#include <Os_internal_config.h>

#include <Os_platform.h>
/****************** generic includes END ***********************/


#include <Os_application_api.h> /* for INVALID_OSAPPLICATION */
#include <Os_task_api.h> /* for INVALID_TASK */
#include <Os_isr_api.h> /* for INVALID_ISR */

#include <string.h>




#ifdef __cplusplus
}
#endif



/** @} */
