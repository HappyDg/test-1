/**
*   @file    Os_platform_timers.h
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

#ifndef OS_PLATFORM_TIMERS_H_
#define OS_PLATFORM_TIMERS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_prop_platform.h> /**< user provided platform configuration */

#include <Os_platform_config.h> /**< select IPs available on platform */
#include <Os_platform_base.h>   /**< provides base addresses for each IP */

#include <Os_hw_core.h>          /**< provides register access macros  */








#include <Os_hw_pit.h>



#include <Os_hw_systick.h>

#include <Os_hw_ftm.h>


#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

/*********************** platform specific definitions for timers ***********************/

#if defined(OSHWCOUNTER)





















    #if defined(OSTIMFTM0)  || defined(OSTIMFTM1)  || defined(OSTIMFTM2)  || defined(OSTIMFTM3) || \
        defined(OSTIMFTM4)  || defined(OSTIMFTM5)  || defined(OSTIMFTM6)  || defined(OSTIMFTM7) || \
        defined(OSTIM2FTM0) || defined(OSTIM2FTM1) || defined(OSTIM2FTM2) || defined(OSTIM2FTM3) || \
        defined(OSTIM2FTM4) || defined(OSTIM2FTM5) || defined(OSTIM2FTM6) || defined(OSTIM2FTM7)
    typedef OSWORD OSHWTickType; /**< FTM 16bits */
    #endif

#endif /* defined(OSHWCOUNTER) */
































#if defined(OSTIMFTM0)  || defined(OSTIMFTM1)  || defined(OSTIMFTM2)  || defined(OSTIMFTM3) || \
    defined(OSTIMFTM4)  || defined(OSTIMFTM5)  || defined(OSTIMFTM6)  || defined(OSTIMFTM7) || \
    defined(OSTIM2FTM0) || defined(OSTIM2FTM1) || defined(OSTIM2FTM2) || defined(OSTIM2FTM3) || \
    defined(OSTIM2FTM4) || defined(OSTIM2FTM5) || defined(OSTIM2FTM6) || defined(OSTIM2FTM7)
#define OSCTRBITS(num) ((OSWORD)(num))  /**< 16 bit FTM counter */
#endif



#if defined(OSSYSTIMER)

#if defined(OSTIMDEC) || defined(OSTIMFIT)
#define OSSTREG             (OSINTC_SSCIR4_7)
#define OSSysTimClearFlag() (OSSTREG = OSSYSSOFTCLEAR)
#define OSSysTimFlagIsSet() (OSSTREG & OSSYSSOFTCLEAR)


#else /* below for other timers */

#define OSSysTimFlagIsSet() (OSSTREG & OSINTFLAG)

#if defined(OSHWCOUNTER)
#if defined(OSTIMeMIOS)
#define OSTIMSetCNTVal( value ) \
                    OSMTSCREG &= ~OSeMIOSHWMODE;   /* enter to GPIO mode for CNT change */ \
                    OSTIMTCNT = value; \
                    OSMTSCREG |= OSeMIOSHWMODE;    /* restore SAOC mode */ \
                    OSSysTimClearFlag()
#else
#define OSTIMSetCNTVal( value ) \
                        OSTIMTCNT = value; \
                        OSSysTimClearFlag()
#endif
#endif /* defined(OSHWCOUNTER) */

#endif /* defined(OSTIMDEC) || defined(OSTIMFIT) */
#endif /* defined(OSSYSTIMER) */


#if defined(OSSECONDTIMER)
#if defined(OSTIM2DEC) || defined(OSTIM2FIT)
#define OSSTREG2            (OSINTC_SSCIR4_7)
#define OSSecondClearFlag() (OSSTREG2 = OSSECSOFTCLEAR)
#define OSSecondFlagIsSet() (OSSTREG2 & OSSECSOFTCLEAR)


#else  /* below for other timers */

#define OSSecondFlagIsSet() (OSSTREG2 & OSINTFLAG2)

#if defined(OSHWCOUNTER)
#if defined(OSTIM2eMIOS)
#define OSTIM2SetCNTVal( value )                                        \
    OSMTSCREG2 &= ~OSeMIOSHWMODE;   /* enter to GPIO mode for CNT change */ \
    OSTIM2TCNT = value;                                                 \
    OSMTSCREG2 |= OSeMIOSHWMODE;    /* restore SAOC mode */             \
    OSSecondClearFlag()
#else
#define OSTIM2SetCNTVal( value )                \
    OSTIM2TCNT = value;                         \
    OSSecondClearFlag()
#endif
#endif /* defined(OSHWCOUNTER) */
#endif /* defined(OSTIM2DEC) || defined(OSTIM2FIT) */
#endif /* defined(OSSECONDTIMER) */





#if defined(OSHWCOUNTER)


/* Single core implementation */
#if (OSNHWCTRS == 1U)

#define OSHWCtrInterruptRaised( ctrId )  OSSysTimFlagIsSet()
#define OSHWCtrValue( ctrId )            (OSTIMTCNT)
#define OSHWCtrGetOC( ctrId )            (OSTIMCHOC)
#define OSHWCtrInit( ctrId, value )      OSTIMSetCNTVal( value )

#else /* OSNHWCTRS == 1U */

#define OSHWCtrInterruptRaised( ctrId )  ( ( (ctrId) != 0U ) ? OSSecondFlagIsSet() : OSSysTimFlagIsSet() )
#define OSHWCtrValue( ctrId )            ( ( (ctrId) != 0U ) ? (OSTIM2TCNT) : (OSTIMTCNT) )
#define OSHWCtrGetOC( ctrId )            ( ( (ctrId) != 0U ) ? (OSTIM2CHOC) : (OSTIMCHOC) )
#define OSHWCtrInit( ctrId, value )             \
    if( ctrId == 1U)                            \
    {                                           \
        OSTIM2SetCNTVal( value );               \
    }                                           \
    else                                        \
    {                                           \
        OSTIMSetCNTVal( value );                \
    }
#endif /* OSNHWCTRS == 1U */


#endif /* defined(OSHWCOUNTER) */



#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif


#endif /* OS_PLATFORM_TIMERS_H_ */

/** @} */
