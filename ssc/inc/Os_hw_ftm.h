/**
*   @file    Os_hw_ftm.h
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
*   (c) Copyright 2013 - 2016 Freescale Semiconductor Inc.
*   Copyright 2017 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef OS_HW_FTM_H
#define OS_HW_FTM_H

#ifdef __cplusplus
extern "C"
{
#endif

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"



/************************************************  FTM registers  *****/

#define OSFTM_MODE_WPDIS_MASK                      (0x4UL)
#define OSFTM_CnSC_CHIE_MASK                       (0x40UL)
#define OSFTM_CnSC_MSA_MASK                        (0x10UL)
#define OSFTM_CnSC_MSB_MASK                        (0x00UL)
#define OSFTM_CnSC_ELSA_MASK                       (0x4UL)
#define OSFTM_CnSC_ELSB_MASK                       (0x8UL)


/* CnV Bit Fields */
#define OSFTM_CnV_VAL_MASK                         (0xFFFFUL)
#define OSFTM_CnV_VAL_SHIFT                        0
#define OSFTM_CnV_VAL(x)                           (((OSDWORD)(((OSDWORD)(x))<<OSFTM_CnV_VAL_SHIFT))&OSFTM_CnV_VAL_MASK)
/* MOD Bit Fields */
#define OSFTM_MOD_MOD_MASK                         (0xFFFFUL)
#define OSFTM_MOD_MOD_SHIFT                        0
#define OSFTM_MOD_MOD(x)                           (((OSDWORD)(((OSDWORD)(x))<<OSFTM_MOD_MOD_SHIFT))&OSFTM_MOD_MOD_MASK)
/* SC Bit Fields */
#define OSFTM_SC_PS_MASK                           (0x7UL)
#define OSFTM_SC_PS_SHIFT                          0
#define OSFTM_SC_PS(x)                             (((OSDWORD)(((OSDWORD)(x))<<OSFTM_SC_PS_SHIFT))&OSFTM_SC_PS_MASK)
#define OSFTM_SC_CLKS_MASK                         (0x18UL)
#define OSFTM_SC_CLKS_SHIFT                        3
#define OSFTM_SC_CLKS(x)                           (((OSDWORD)(((OSDWORD)(x))<<OSFTM_SC_CLKS_SHIFT))&OSFTM_SC_CLKS_MASK)

#define OSFTM_SC_TOF_MASK                          (0x80UL)
#define OSFTM_CnSC_CHF_MASK                        (0x80UL)

#if defined(OSTIMFTM0) || defined(OSTIM2FTM0)

#define OSFTM0_SC                                  OSREG32(OSFTM0BASE)
#define OSFTM0_CNT                                 OSREG32(OSFTM0BASE + 0x4U)
#define OSFTM0_MOD                                 OSREG32(OSFTM0BASE + 0x8U)
#define OSFTM0_CnSC(n)                             OSREG32(OSFTM0BASE + ((OSDWORD)8*(n)) + (OSDWORD)0xCU)
#define OSFTM0_CnV(n)                              OSREG32(OSFTM0BASE + ((OSDWORD)8*(n)) + (OSDWORD)0x10U)
#define OSFTM0_CNTIN                               OSREG32(OSFTM0BASE + 0x4CU)
#define OSFTM0_MODE                                OSREG32(OSFTM0BASE + 0x54U)
#define OSFTM0_CONF                                OSREG32(OSFTM0BASE + 0x84U)

#endif

#if defined(OSTIMFTM1) || defined(OSTIM2FTM1)

#define OSFTM1_SC                                  OSREG32(OSFTM1BASE)
#define OSFTM1_CNT                                 OSREG32(OSFTM1BASE + 0x4U)
#define OSFTM1_MOD                                 OSREG32(OSFTM1BASE + 0x8U)
#define OSFTM1_CnSC(n)                             OSREG32(OSFTM1BASE + ((OSDWORD)8*(n)) + (OSDWORD)0xCU)
#define OSFTM1_CnV(n)                              OSREG32(OSFTM1BASE + ((OSDWORD)8*(n)) + (OSDWORD)0x10U)
#define OSFTM1_CNTIN                               OSREG32(OSFTM1BASE + 0x4CU)
#define OSFTM1_MODE                                OSREG32(OSFTM1BASE + 0x54U)
#define OSFTM1_CONF                                OSREG32(OSFTM1BASE + 0x84U)

#endif

#if defined(OSTIMFTM2) || defined(OSTIM2FTM2)

#define OSFTM2_SC                                  OSREG32(OSFTM2BASE)
#define OSFTM2_CNT                                 OSREG32(OSFTM2BASE + 0x4U)
#define OSFTM2_MOD                                 OSREG32(OSFTM2BASE + 0x8U)
#define OSFTM2_CnSC(n)                             OSREG32(OSFTM2BASE + ((OSDWORD)8*(n)) + (OSDWORD)0xCU)
#define OSFTM2_CnV(n)                              OSREG32(OSFTM2BASE + ((OSDWORD)8*(n)) + (OSDWORD)0x10U)
#define OSFTM2_CNTIN                               OSREG32(OSFTM2BASE + 0x4CU)
#define OSFTM2_MODE                                OSREG32(OSFTM2BASE + 0x54U)
#define OSFTM2_CONF                                OSREG32(OSFTM2BASE + 0x84U)

#endif

#if defined(OSTIMFTM3) || defined(OSTIM2FTM3)

#define OSFTM3_SC                                  OSREG32(OSFTM3BASE)
#define OSFTM3_CNT                                 OSREG32(OSFTM3BASE + 0x4U)
#define OSFTM3_MOD                                 OSREG32(OSFTM3BASE + 0x8U)
#define OSFTM3_CnSC(n)                             OSREG32(OSFTM3BASE + ((OSDWORD)8*(n)) + (OSDWORD)0xCU)
#define OSFTM3_CnV(n)                              OSREG32(OSFTM3BASE + ((OSDWORD)8*(n)) + (OSDWORD)0x10U)
#define OSFTM3_CNTIN                               OSREG32(OSFTM3BASE + 0x4CU)
#define OSFTM3_MODE                                OSREG32(OSFTM3BASE + 0x54U)
#define OSFTM3_CONF                                OSREG32(OSFTM3BASE + 0x84U)

#endif

#if defined(OSTIMFTM4) || defined(OSTIM2FTM4)

#define OSFTM4_SC                                  OSREG32(OSFTM4BASE)
#define OSFTM4_CNT                                 OSREG32(OSFTM4BASE + 0x4U)
#define OSFTM4_MOD                                 OSREG32(OSFTM4BASE + 0x8U)
#define OSFTM4_CnSC(n)                             OSREG32(OSFTM4BASE + ((OSDWORD)8*(n)) + (OSDWORD)0xCU)
#define OSFTM4_CnV(n)                              OSREG32(OSFTM4BASE + ((OSDWORD)8*(n)) + (OSDWORD)0x10U)
#define OSFTM4_CNTIN                               OSREG32(OSFTM4BASE + 0x4CU)
#define OSFTM4_MODE                                OSREG32(OSFTM4BASE + 0x54U)
#define OSFTM4_CONF                                OSREG32(OSFTM4BASE + 0x84U)

#endif

#if defined(OSTIMFTM5) || defined(OSTIM2FTM5)

#define OSFTM5_SC                                  OSREG32(OSFTM5BASE)
#define OSFTM5_CNT                                 OSREG32(OSFTM5BASE + 0x4U)
#define OSFTM5_MOD                                 OSREG32(OSFTM5BASE + 0x8U)
#define OSFTM5_CnSC(n)                             OSREG32(OSFTM5BASE + ((OSDWORD)8*(n)) + (OSDWORD)0xCU)
#define OSFTM5_CnV(n)                              OSREG32(OSFTM5BASE + ((OSDWORD)8*(n)) + (OSDWORD)0x10U)
#define OSFTM5_CNTIN                               OSREG32(OSFTM5BASE + 0x4CU)
#define OSFTM5_MODE                                OSREG32(OSFTM5BASE + 0x54U)
#define OSFTM5_CONF                                OSREG32(OSFTM5BASE + 0x84U)

#endif

#if defined(OSTIMFTM6) || defined(OSTIM2FTM6)

#define OSFTM6_SC                                  OSREG32(OSFTM6BASE)
#define OSFTM6_CNT                                 OSREG32(OSFTM6BASE + 0x4U)
#define OSFTM6_MOD                                 OSREG32(OSFTM6BASE + 0x8U)
#define OSFTM6_CnSC(n)                             OSREG32(OSFTM6BASE + ((OSDWORD)8*(n)) + (OSDWORD)0xCU)
#define OSFTM6_CnV(n)                              OSREG32(OSFTM6BASE + ((OSDWORD)8*(n)) + (OSDWORD)0x10U)
#define OSFTM6_CNTIN                               OSREG32(OSFTM6BASE + 0x4CU)
#define OSFTM6_MODE                                OSREG32(OSFTM6BASE + 0x54U)
#define OSFTM6_CONF                                OSREG32(OSFTM6BASE + 0x84U)

#endif

#if defined(OSTIMFTM7) || defined(OSTIM2FTM7)

#define OSFTM7_SC                                  OSREG32(OSFTM7BASE)
#define OSFTM7_CNT                                 OSREG32(OSFTM7BASE + 0x4U)
#define OSFTM7_MOD                                 OSREG32(OSFTM7BASE + 0x8U)
#define OSFTM7_CnSC(n)                             OSREG32(OSFTM7BASE + ((OSDWORD)8*(n)) + (OSDWORD)0xCU)
#define OSFTM7_CnV(n)                              OSREG32(OSFTM7BASE + ((OSDWORD)8*(n)) + (OSDWORD)0x10U)
#define OSFTM7_CNTIN                               OSREG32(OSFTM7BASE + 0x4CU)
#define OSFTM7_MODE                                OSREG32(OSFTM7BASE + 0x54U)
#define OSFTM7_CONF                                OSREG32(OSFTM7BASE + 0x84U)

#endif



/**************************************************************************/

#define OSFTM_STARTVAL                             ((OSDWORD)0x0)                     /* start value for FTM counter */


#if defined(OSSYSTIMER)

/*********************************************************  System timer: FTM  *****/

#if defined(OSTIMFTM0) || defined(OSTIMFTM1) || defined(OSTIMFTM2) || defined(OSTIMFTM3) || \
    defined(OSTIMFTM4) || defined(OSTIMFTM5) || defined(OSTIMFTM6) || defined(OSTIMFTM7)

#define OSINTFLAG                                  OSFTM_CnSC_CHF_MASK                /* timer interrupt flag for external usage */

#if defined(OSSYSTIMFREEZE)
    #define OSCHFREEZE                             (0x00U<<6)
#else
    #define OSCHFREEZE                             (0x03U<<6)
#endif

#if defined(OSTIMMODULO)
    #define OSMODULO_MASK                          (OSTIMMODULO)
#else
    #define OSMODULO_MASK                          (0xFFFFUL)
#endif

#endif /* OSTIMFTM0/1/2/3/4/5/6/7 */


#if defined(OSTIMFTM0)

    #define OSSTREG                                OSFTM0_CnSC(OSTIMCHAN)                   /* status register */
    #define OSTIMTCNT                              OSFTM0_CNT                   /* counter value */
    #define OSTIMCHOC                              OSFTM0_CnV(OSTIMCHAN)                   /* timer compare value  */

#if defined(OSFTM0GLOBALPRESCALER)
    #define OSTimHWprepare()                     \
            {                                    \
            OSFTM0_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM0_SC = 0x00U;                   \
            OSFTM0_CNTIN = 0x00U;                \
            OSFTM0_CnSC(OSTIMCHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM0_MOD = OSFTM_MOD_MOD(OSMODULO_MASK);      \
            OSFTM0_SC = OSFTM_SC_PS(OSFTM0GLOBALPRESCALER); \
            OSFTM0_CONF = OSCHFREEZE;            \
            }
#else
    #define OSTimHWprepare()
#endif

    #define OSSysTimRun()                          OSFTM0_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSysTimStop()                         OSFTM0_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSysTimClearFlag()                    OSFTM0_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSysTimEnableInt()                    OSFTM0_CnSC(OSTIMCHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSysTimDisableInt()                   OSFTM0_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIMFTM1)

    #define OSSTREG                                OSFTM1_CnSC(OSTIMCHAN)                   /* status register */
    #define OSTIMTCNT                              OSFTM1_CNT                   /* counter value */
    #define OSTIMCHOC                              OSFTM1_CnV(OSTIMCHAN)                   /* timer compare value  */

#if defined(OSFTM1GLOBALPRESCALER)
    #define OSTimHWprepare()                     \
            {                                    \
            OSFTM1_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM1_SC = 0x00U;                   \
            OSFTM1_CNTIN = 0x00U;                \
            OSFTM1_CnSC(OSTIMCHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM1_MOD = OSFTM_MOD_MOD(OSMODULO_MASK);      \
            OSFTM1_SC = OSFTM_SC_PS(OSFTM1GLOBALPRESCALER); \
            OSFTM1_CONF = OSCHFREEZE;            \
            }
#else
    #define OSTimHWprepare()
#endif

    #define OSSysTimRun()                          OSFTM1_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSysTimStop()                         OSFTM1_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSysTimClearFlag()                    OSFTM1_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSysTimEnableInt()                    OSFTM1_CnSC(OSTIMCHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSysTimDisableInt()                   OSFTM1_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIMFTM2)

    #define OSSTREG                                OSFTM2_CnSC(OSTIMCHAN)                   /* status register */
    #define OSTIMTCNT                              OSFTM2_CNT                   /* counter value */
    #define OSTIMCHOC                              OSFTM2_CnV(OSTIMCHAN)                   /* timer compare value  */

#if defined(OSFTM2GLOBALPRESCALER)
    #define OSTimHWprepare()                     \
            {                                    \
            OSFTM2_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM2_SC = 0x00U;                   \
            OSFTM2_CNTIN = 0x00U;                \
            OSFTM2_CnSC(OSTIMCHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM2_MOD = OSFTM_MOD_MOD(OSMODULO_MASK);      \
            OSFTM2_SC = OSFTM_SC_PS(OSFTM2GLOBALPRESCALER); \
            OSFTM2_CONF = OSCHFREEZE;            \
            }
#else
    #define OSTimHWprepare()
#endif

    #define OSSysTimRun()                          OSFTM2_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSysTimStop()                         OSFTM2_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSysTimClearFlag()                    OSFTM2_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSysTimEnableInt()                    OSFTM2_CnSC(OSTIMCHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSysTimDisableInt()                   OSFTM2_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIMFTM3)

    #define OSSTREG                                OSFTM3_CnSC(OSTIMCHAN)                   /* status register */
    #define OSTIMTCNT                              OSFTM3_CNT                   /* counter value */
    #define OSTIMCHOC                              OSFTM3_CnV(OSTIMCHAN)                   /* timer compare value  */

#if defined(OSFTM3GLOBALPRESCALER)
    #define OSTimHWprepare()                     \
            {                                    \
            OSFTM3_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM3_SC = 0x00U;                   \
            OSFTM3_CNTIN = 0x00U;                \
            OSFTM3_CnSC(OSTIMCHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM3_MOD = OSFTM_MOD_MOD(OSMODULO_MASK);      \
            OSFTM3_SC = OSFTM_SC_PS(OSFTM3GLOBALPRESCALER); \
            OSFTM3_CONF = OSCHFREEZE;            \
            }
#else
    #define OSTimHWprepare()
#endif

    #define OSSysTimRun()                          OSFTM3_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSysTimStop()                         OSFTM3_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSysTimClearFlag()                    OSFTM3_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSysTimEnableInt()                    OSFTM3_CnSC(OSTIMCHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSysTimDisableInt()                   OSFTM3_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIMFTM4)

    #define OSSTREG                                OSFTM4_CnSC(OSTIMCHAN)                   /* status register */
    #define OSTIMTCNT                              OSFTM4_CNT                   /* counter value */
    #define OSTIMCHOC                              OSFTM4_CnV(OSTIMCHAN)                   /* timer compare value  */

#if defined(OSFTM4GLOBALPRESCALER)
    #define OSTimHWprepare()                     \
            {                                    \
            OSFTM4_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM4_SC = 0x00U;                   \
            OSFTM4_CNTIN = 0x00U;                \
            OSFTM4_CnSC(OSTIMCHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM4_MOD = OSFTM_MOD_MOD(OSMODULO_MASK);      \
            OSFTM4_SC = OSFTM_SC_PS(OSFTM4GLOBALPRESCALER); \
            OSFTM4_CONF = OSCHFREEZE;            \
            }
#else
    #define OSTimHWprepare()
#endif

    #define OSSysTimRun()                          OSFTM4_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSysTimStop()                         OSFTM4_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSysTimClearFlag()                    OSFTM4_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSysTimEnableInt()                    OSFTM4_CnSC(OSTIMCHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSysTimDisableInt()                   OSFTM4_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIMFTM5)

    #define OSSTREG                                OSFTM5_CnSC(OSTIMCHAN)                   /* status register */
    #define OSTIMTCNT                              OSFTM5_CNT                   /* counter value */
    #define OSTIMCHOC                              OSFTM5_CnV(OSTIMCHAN)                   /* timer compare value  */

#if defined(OSFTM5GLOBALPRESCALER)
    #define OSTimHWprepare()                     \
            {                                    \
            OSFTM5_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM5_SC = 0x00U;                   \
            OSFTM5_CNTIN = 0x00U;                \
            OSFTM5_CnSC(OSTIMCHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM5_MOD = OSFTM_MOD_MOD(OSMODULO_MASK);      \
            OSFTM5_SC = OSFTM_SC_PS(OSFTM5GLOBALPRESCALER); \
            OSFTM5_CONF = OSCHFREEZE;            \
            }
#else
    #define OSTimHWprepare()
#endif

    #define OSSysTimRun()                          OSFTM5_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSysTimStop()                         OSFTM5_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSysTimClearFlag()                    OSFTM5_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSysTimEnableInt()                    OSFTM5_CnSC(OSTIMCHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSysTimDisableInt()                   OSFTM5_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIMFTM6)

    #define OSSTREG                                OSFTM6_CnSC(OSTIMCHAN)                   /* status register */
    #define OSTIMTCNT                              OSFTM6_CNT                   /* counter value */
    #define OSTIMCHOC                              OSFTM6_CnV(OSTIMCHAN)                   /* timer compare value  */

#if defined(OSFTM6GLOBALPRESCALER)
    #define OSTimHWprepare()                     \
            {                                    \
            OSFTM6_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM6_SC = 0x00U;                   \
            OSFTM6_CNTIN = 0x00U;                \
            OSFTM6_CnSC(OSTIMCHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM6_MOD = OSFTM_MOD_MOD(OSMODULO_MASK);      \
            OSFTM6_SC = OSFTM_SC_PS(OSFTM6GLOBALPRESCALER); \
            OSFTM6_CONF = OSCHFREEZE;            \
            }
#else
    #define OSTimHWprepare()
#endif

    #define OSSysTimRun()                          OSFTM6_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSysTimStop()                         OSFTM6_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSysTimClearFlag()                    OSFTM6_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSysTimEnableInt()                    OSFTM6_CnSC(OSTIMCHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSysTimDisableInt()                   OSFTM6_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIMFTM7)

    #define OSSTREG                                OSFTM7_CnSC(OSTIMCHAN)                   /* status register */
    #define OSTIMTCNT                              OSFTM7_CNT                   /* counter value */
    #define OSTIMCHOC                              OSFTM7_CnV(OSTIMCHAN)                   /* timer compare value  */

#if defined(OSFTM7GLOBALPRESCALER)
    #define OSTimHWprepare()                     \
            {                                    \
            OSFTM7_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM7_SC = 0x00U;                   \
            OSFTM7_CNTIN = 0x00U;                \
            OSFTM7_CnSC(OSTIMCHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM7_MOD = OSFTM_MOD_MOD(OSMODULO_MASK);      \
            OSFTM7_SC = OSFTM_SC_PS(OSFTM7GLOBALPRESCALER); \
            OSFTM7_CONF = OSCHFREEZE;            \
            }
#else
    #define OSTimHWprepare()
#endif

    #define OSSysTimRun()                          OSFTM7_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSysTimStop()                         OSFTM7_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSysTimClearFlag()                    OSFTM7_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSysTimEnableInt()                    OSFTM7_CnSC(OSTIMCHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSysTimDisableInt()                   OSFTM7_CnSC(OSTIMCHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#endif     /* defined(OSTIMFTM7) */

#if defined(OSTIMFTM0) || defined(OSTIMFTM1) || defined(OSTIMFTM2) || defined(OSTIMFTM3) || \
    defined(OSTIMFTM4) || defined(OSTIMFTM5) || defined(OSTIMFTM6) || defined(OSTIMFTM7)
/***************************************************************************
* Macro:       OSSysTimSetHW
*
* Description: System timer's HW initialization;
*              mode,control bits and prescaler are set here;
*
*          for FTM:
*              MODULO value;
*              clear counter register;
*
**************************************************************************/

OSINLINE void
OSSysTimSetHW (void)
{

    #if defined(OSTIMMODULO)
    OSTIMCHOC = OSTIMMODULO;  /* reload value */
    #endif

    OSTIMTCNT = OSFTM_STARTVAL; /* reset counter value */

    OSSysTimRun ();          /* start system timer  */
}

#endif /* OSTIMFTM0/1/2/3/4/5/6/7 */

#endif /* defined(OSSYSTIMER) */



#if defined(OSSECONDTIMER)

/*********************************************************  Second timer: FTM  *****/

#if defined(OSTIM2FTM0) || defined(OSTIM2FTM1) || defined(OSTIM2FTM2) || defined(OSTIM2FTM3) || \
    defined(OSTIM2FTM4) || defined(OSTIM2FTM5) || defined(OSTIM2FTM6) || defined(OSTIM2FTM7)

#define OSINTFLAG2                                 OSFTM_CnSC_CHF_MASK                /* timer interrupt flag for external usage */

#if defined(OSSECONDFREEZE)
    #define OSCH2FREEZE                            (0x00U<<6U)
#else
    #define OSCH2FREEZE                            (0x03U<<6U)
#endif

#if defined(OSTIM2MODULO)
    #define OSMODULO2_MASK                         (OSTIM2MODULO)
#else
    #define OSMODULO2_MASK                         (0xFFFFUL)
#endif

#endif /* OSTIM2FTM0/1/2/3/4/5/6/7 */


#if defined(OSTIM2FTM0)

    #define OSSTREG2                               OSFTM0_CnSC(OSTIM2CHAN)                   /* status register */
    #define OSTIM2TCNT                             OSFTM0_CNT                   /* counter value */
    #define OSTIM2CHOC                             OSFTM0_CnV(OSTIM2CHAN)                   /* timer compare value  */

#if defined(OSFTM0GLOBALPRESCALER)
    #define OSTim2HWprepare()                    \
            {                                    \
            OSFTM0_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM0_SC = 0x00U;                   \
            OSFTM0_CNTIN = 0x00U;                \
            OSFTM0_CnSC(OSTIM2CHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM0_MOD = OSFTM_MOD_MOD(OSMODULO2_MASK);     \
            OSFTM0_SC = OSFTM_SC_PS(OSFTM0GLOBALPRESCALER); \
            OSFTM0_CONF = OSCH2FREEZE;           \
            }
#else
    #define OSTim2HWprepare()
#endif

    #define OSSecondRun()                          OSFTM0_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSecondStop()                         OSFTM0_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSecondClearFlag()                    OSFTM0_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSecondEnableInt()                    OSFTM0_CnSC(OSTIM2CHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSecondDisableInt()                   OSFTM0_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIM2FTM1)

    #define OSSTREG2                               OSFTM1_CnSC(OSTIM2CHAN)                   /* status register */
    #define OSTIM2TCNT                             OSFTM1_CNT                   /* counter value */
    #define OSTIM2CHOC                             OSFTM1_CnV(OSTIM2CHAN)                   /* timer compare value  */

#if defined(OSFTM1GLOBALPRESCALER)
    #define OSTim2HWprepare()                    \
            {                                    \
            OSFTM1_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM1_SC = 0x00U;                   \
            OSFTM1_CNTIN = 0x00U;                \
            OSFTM1_CnSC(OSTIM2CHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM1_MOD = OSFTM_MOD_MOD(OSMODULO2_MASK);     \
            OSFTM1_SC = OSFTM_SC_PS(OSFTM1GLOBALPRESCALER); \
            OSFTM1_CONF = OSCH2FREEZE;           \
            }
#else
    #define OSTim2HWprepare()
#endif

    #define OSSecondRun()                          OSFTM1_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSecondStop()                         OSFTM1_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSecondClearFlag()                    OSFTM1_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSecondEnableInt()                    OSFTM1_CnSC(OSTIM2CHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSecondDisableInt()                   OSFTM1_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIM2FTM2)

    #define OSSTREG2                               OSFTM2_CnSC(OSTIM2CHAN)                   /* status register */
    #define OSTIM2TCNT                             OSFTM2_CNT                   /* counter value */
    #define OSTIM2CHOC                             OSFTM2_CnV(OSTIM2CHAN)                   /* timer compare value  */

#if defined(OSFTM2GLOBALPRESCALER)
    #define OSTim2HWprepare()                    \
            {                                    \
            OSFTM2_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM2_SC = 0x00U;                   \
            OSFTM2_CNTIN = 0x00U;                \
            OSFTM2_CnSC(OSTIM2CHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM2_MOD = OSFTM_MOD_MOD(OSMODULO2_MASK);     \
            OSFTM2_SC = OSFTM_SC_PS(OSFTM2GLOBALPRESCALER); \
            OSFTM2_CONF = OSCH2FREEZE;           \
            }
#else
    #define OSTim2HWprepare()
#endif

    #define OSSecondRun()                          OSFTM2_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSecondStop()                         OSFTM2_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSecondClearFlag()                    OSFTM2_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSecondEnableInt()                    OSFTM2_CnSC(OSTIM2CHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSecondDisableInt()                   OSFTM2_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIM2FTM3)

    #define OSSTREG2                               OSFTM3_CnSC(OSTIM2CHAN)                   /* status register */
    #define OSTIM2TCNT                             OSFTM3_CNT                   /* counter value */
    #define OSTIM2CHOC                             OSFTM3_CnV(OSTIM2CHAN)                   /* timer compare value  */

#if defined(OSFTM3GLOBALPRESCALER)
    #define OSTim2HWprepare()                    \
            {                                    \
            OSFTM3_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM3_SC = 0x00U;                   \
            OSFTM3_CNTIN = 0x00U;                \
            OSFTM3_CnSC(OSTIM2CHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM3_MOD = OSFTM_MOD_MOD(OSMODULO2_MASK);     \
            OSFTM3_SC = OSFTM_SC_PS(OSFTM3GLOBALPRESCALER); \
            OSFTM3_CONF = OSCH2FREEZE;           \
            }
#else
    #define OSTim2HWprepare()
#endif

    #define OSSecondRun()                          OSFTM3_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSecondStop()                         OSFTM3_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSecondClearFlag()                    OSFTM3_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSecondEnableInt()                    OSFTM3_CnSC(OSTIM2CHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSecondDisableInt()                   OSFTM3_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIM2FTM4)

    #define OSSTREG2                               OSFTM4_CnSC(OSTIM2CHAN)                   /* status register */
    #define OSTIM2TCNT                             OSFTM4_CNT                   /* counter value */
    #define OSTIM2CHOC                             OSFTM4_CnV(OSTIM2CHAN)                   /* timer compare value  */

#if defined(OSFTM4GLOBALPRESCALER)
    #define OSTim2HWprepare()                    \
            {                                    \
            OSFTM4_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM4_SC = 0x00U;                   \
            OSFTM4_CNTIN = 0x00U;                \
            OSFTM4_CnSC(OSTIM2CHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM4_MOD = OSFTM_MOD_MOD(OSMODULO2_MASK);     \
            OSFTM4_SC = OSFTM_SC_PS(OSFTM4GLOBALPRESCALER); \
            OSFTM4_CONF = OSCH2FREEZE;           \
            }
#else
    #define OSTim2HWprepare()
#endif

    #define OSSecondRun()                          OSFTM4_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSecondStop()                         OSFTM4_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSecondClearFlag()                    OSFTM4_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSecondEnableInt()                    OSFTM4_CnSC(OSTIM2CHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSecondDisableInt()                   OSFTM4_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIM2FTM5)

    #define OSSTREG2                               OSFTM5_CnSC(OSTIM2CHAN)                   /* status register */
    #define OSTIM2TCNT                             OSFTM5_CNT                   /* counter value */
    #define OSTIM2CHOC                             OSFTM5_CnV(OSTIM2CHAN)                   /* timer compare value  */

#if defined(OSFTM5GLOBALPRESCALER)
    #define OSTim2HWprepare()                    \
            {                                    \
            OSFTM5_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM5_SC = 0x00U;                   \
            OSFTM5_CNTIN = 0x00U;                \
            OSFTM5_CnSC(OSTIM2CHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM5_MOD = OSFTM_MOD_MOD(OSMODULO2_MASK);     \
            OSFTM5_SC = OSFTM_SC_PS(OSFTM5GLOBALPRESCALER); \
            OSFTM5_CONF = OSCH2FREEZE;           \
            }
#else
    #define OSTim2HWprepare()
#endif

    #define OSSecondRun()                          OSFTM5_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSecondStop()                         OSFTM5_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSecondClearFlag()                    OSFTM5_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSecondEnableInt()                    OSFTM5_CnSC(OSTIM2CHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSecondDisableInt()                   OSFTM5_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIM2FTM6)

    #define OSSTREG2                               OSFTM6_CnSC(OSTIM2CHAN)                   /* status register */
    #define OSTIM2TCNT                             OSFTM6_CNT                   /* counter value */
    #define OSTIM2CHOC                             OSFTM6_CnV(OSTIM2CHAN)                   /* timer compare value  */

#if defined(OSFTM6GLOBALPRESCALER)
    #define OSTim2HWprepare()                    \
            {                                    \
            OSFTM6_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM6_SC = 0x00U;                   \
            OSFTM6_CNTIN = 0x00U;                \
            OSFTM6_CnSC(OSTIM2CHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM6_MOD = OSFTM_MOD_MOD(OSMODULO2_MASK);     \
            OSFTM6_SC = OSFTM_SC_PS(OSFTM6GLOBALPRESCALER); \
            OSFTM6_CONF = OSCH2FREEZE;           \
            }
#else
    #define OSTim2HWprepare()
#endif

    #define OSSecondRun()                          OSFTM6_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSecondStop()                         OSFTM6_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSecondClearFlag()                    OSFTM6_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSecondEnableInt()                    OSFTM6_CnSC(OSTIM2CHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSecondDisableInt()                   OSFTM6_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#elif defined(OSTIM2FTM7)

    #define OSSTREG2                               OSFTM7_CnSC(OSTIM2CHAN)                   /* status register */
    #define OSTIM2TCNT                             OSFTM7_CNT                   /* counter value */
    #define OSTIM2CHOC                             OSFTM7_CnV(OSTIM2CHAN)                   /* timer compare value  */

#if defined(OSFTM7GLOBALPRESCALER)
    #define OSTim2HWprepare()                    \
            {                                    \
            OSFTM7_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM7_SC = 0x00U;                   \
            OSFTM7_CNTIN = 0x00U;                \
            OSFTM7_CnSC(OSTIM2CHAN) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM7_MOD = OSFTM_MOD_MOD(OSMODULO2_MASK);     \
            OSFTM7_SC = OSFTM_SC_PS(OSFTM7GLOBALPRESCALER); \
            OSFTM7_CONF = OSCH2FREEZE;           \
            }
#else
    #define OSTim2HWprepare()
#endif

    #define OSSecondRun()                          OSFTM7_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSSecondStop()                         OSFTM7_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define OSSecondClearFlag()                    OSFTM7_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHF_MASK          /* clear interrupt flag  */
    #define OSSecondEnableInt()                    OSFTM7_CnSC(OSTIM2CHAN) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define OSSecondDisableInt()                   OSFTM7_CnSC(OSTIM2CHAN) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */

#endif     /* defined(OSTIM2FTM7) */

#if defined(OSTIM2FTM0) || defined(OSTIM2FTM1) || defined(OSTIM2FTM2) || defined(OSTIM2FTM3) || \
    defined(OSTIM2FTM4) || defined(OSTIM2FTM5) || defined(OSTIM2FTM6) || defined(OSTIM2FTM7)
/***************************************************************************
* Macro:       OSSecondTimSetHW
*
* Description: Second timer's HW initialization;
*              mode,control bits and prescaler are set here;
*
*          for FTM:
*              MODULO value;
*              clear counter register;
*
**************************************************************************/

OSINLINE void
OSSecondSetHW (void)
{

    #if defined(OSTIM2MODULO)
    OSTIM2CHOC = OSTIM2MODULO; /* reload value */
    #endif

    OSTIM2TCNT = OSFTM_STARTVAL; /* reset counter value */

    OSSecondRun ();        /* start second timer  */
}

#endif /* OSTIM2FTM0/1/2/3/4/5/6/7 */

#endif /* defined(OSSECONDTIMER) */



#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif



#endif /* OS_HW_FTM_H */

/** @} */

