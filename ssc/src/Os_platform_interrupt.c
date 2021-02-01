/**
*   @file    Os_platform_interrupt.c
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

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Os_platform_interrupt_c_REF_5_1_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters.
* The section identification define's naming convention is defined by AutoSar and identifiers are longer than 31 character.
* Compilers are checked for support this length of identifiers.
*
* @section Os_platform_interrupt_c_REF_19_1_1
* Violates MISRA 2004 Advisory Rule 19.1, declaration before #include
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* MemMap is required by AutoSAR to be included in the middle of the source file(s).
*/

/****************** generic includes START ***********************/
#include <Os_prop_platform.h>

#include <Os_types_basic.h>

#include <Os_types_public.h>
#include <Os_types_common_public.h>
#include <Os_types_common_internal.h>

#include <Os_internal_api.h>
#include <Os_internal_types.h>
#include <Os_internal_config.h>

#include <Os_platform.h>   /**< for platform specific details */
/****************** generic includes END ***********************/

/*
* @violates @ref Os_platform_interrupt_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_START_SEC_VAR_FAST_UNSPECIFIED
#include "Os_sections.h"


OSDECLAREVAR(volatile Os_ArmSavedIRQCtxType, Os_ArmSavedIRQCtx_[ OSINTC_NVIC_PRIO_LEVELS ]);
OSDECLAREVAR(volatile OSDWORD, Os_ArmNvicNestingLevel_);

/*
* @violates @ref Os_platform_interrupt_c_REF_5_1_1 MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*/
#define OS_STOP_SEC_VAR_FAST_UNSPECIFIED
/*
* @violates @ref Os_platform_interrupt_c_REF_19_1_1 MISRA 2004 Advisory Rule 19.1, declaration before #include
*/
#include "Os_sections.h"






#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"


/******************************************************************************
 * Function:    OSPlatformIntcInit
 *
 * Description: Platform specific interrupt controller initialization code
 *
 * Returns:     none
 *
 * Notes:
 ******************************************************************************/
void OSPlatformIntcInit(void)
{
    OSGETCOREIND
    OSDWORD i;

    Os_ArmNvicNestingLevel = 0;

    for (i = 0; i < OSINTC_NVIC_PRIO_LEVELS; i++)
    {
        Os_ArmSavedIRQCtx[i].xpsr=0;
        Os_ArmSavedIRQCtx[i].lr=0;
    }


    /* disable all interrupts and enable configured */
    for (i = 0; i < OSNINTC; i++)
    {

        if (i>=16) {

            OSINTC_NVIC_DISABLE_INTX(i);        /**< disable interrupt       */
            OSINTC_NVIC_CLEAR_PENDING_INTX(i);  /**< clear pending interrupt */
            OSINTC_SET_PRIO_INTX(i, OSINTC_NVIC_CONVERT_PRIO_SET( OSINTC_NVIC_MIN_PRIO ));     /**< set priority to MIN */
        }

        #if (OSNISR > 0)

            /* enable if configured */
            if (OsIsr[i] != OSNISR)
            {


                OSINTC_SET_PRIO_INTX(i, OSINTC_NVIC_CONVERT_PRIO_SET( OsIsrCfg[OsIsr[i]].isrPrio )); /**<  set priority */

                OSINTC_NVIC_ENABLE_INTX(i); /**< enable interrupt       */
            }

        #endif /* (OSNISR > 0) */
    }

}


/******************************************************************************
 * Function:    OSPlatformIntcShutdown
 *
 * Description: Platform specific interrupt controller initialization code
 *
 * Returns:     none
 *
 * Notes:
 ******************************************************************************/
void OSPlatformIntcShutdown(void)
{
    OSGETCOREIND
    OSDWORD i;

    for (i = 16; i < OSNINTC; i++)
    {
        OSINTC_NVIC_DISABLE_INTX(i);        /**< disable interrupt       */
        OSINTC_NVIC_CLEAR_PENDING_INTX(i);  /**< clear pending interrupt */
        OSINTC_SET_PRIO_INTX(i, OSINTC_NVIC_CONVERT_PRIO_SET( OSINTC_NVIC_MIN_PRIO ));     /**< set priority to MIN */
    }

    for (i = Os_ArmNvicNestingLevel; i > 0; i--)
    {
        OSDWORD idx = i-1;
        OSDWORD xpsr, lr;

        xpsr = Os_ArmSavedIRQCtx[ idx ].xpsr;
        lr   = Os_ArmSavedIRQCtx[ idx ].lr;

        OSArmDeactivateIsr(xpsr, lr);
    }

}




#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"




#ifdef __cplusplus
}
#endif



/** @} */
