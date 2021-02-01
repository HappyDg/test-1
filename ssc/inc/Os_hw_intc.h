/**
*   @file    Os_hw_intc.h
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

#ifndef OS_HW_INTC_H
#define OS_HW_INTC_H



#ifdef __cplusplus
extern "C"
{
#endif





    /*
     * NVIC
     */

    #define OSINTC_NVIC_PRIO_BITS  (4u)
    #define OSINTC_NVIC_PRIO_LEVELS (1UL << OSINTC_NVIC_PRIO_BITS)
    #define OSINTC_NVIC_PRIO_SHIFT (8u - OSINTC_NVIC_PRIO_BITS)

    #define OSINTC_NVIC_ICTR       (0xE000E004ul)               /**< RO: Interrupt Controller Type Register  */
    #define OSINTC_NVIC_ISER0      (0xE000E100ul)               /**< RW: Interrupt Set-Enable    Register 0-15  : 0xE000E100 -> 0xE000E13C */
    #define OSINTC_NVIC_ICER0      (0xE000E180ul)               /**< RW: Interrupt Clear-Enable  Register 0-15  : 0xE000E180 -> 0xE000E1BC */
    #define OSINTC_NVIC_ISPR0      (0xE000E200ul)               /**< RW: Interrupt Set-Pending   Register 0-15  : 0xE000E200 -> 0xE000E23C */
    #define OSINTC_NVIC_ICPR0      (0xE000E280ul)               /**< RW: Interrupt Clear-Pending Register 0-15  : 0xE000E280 -> 0xE000E2BC */
    #define OSINTC_NVIC_IABR0      (0xE000E300ul)               /**< RO: Active Bit Register     Register 0-15  : 0xE000E300 -> 0xE000E37C */
    #define OSINTC_NVIC_IPR0       (0xE000E400ul)               /**< RW: Interrupt Priority      Register 0-123 : 0xE000E400 -> 0xE000E7EC */
    #define OSINTC_NVIC_STIR       (0xE000EF00ul)               /**< WO: Software Trigger Interrupt Register */

    /*
     * System control block registers related to priority control
     */
    #define OSINTC_SYS_SHPR1       (0xE000ED18ul)               /**< RW: System Handler Priority Register 1 */
    #define OSINTC_SYS_SHPR2       (0xE000ED1Cul)               /**< RW: System Handler Priority Register 2 */
    #define OSINTC_SYS_SHPR3       (0xE000ED20ul)               /**< RW: System Handler Priority Register 3 */

    /*
     * OS interface to NVIC
     */

    /*
     * Convert from low number value means low prio to
     * low number value means high prio - the way NVIC works
     *
     * 0x00 means 0xFF in hw - this level will never generate an interrupt (>= in basepri)
     */

    /* these values to be used only through conversion macros */
    #define OSINTC_NVIC_MIN_PRIO                0x00u
    #define OSINTC_NVIC_MAX_PRIO                0xFFu

    #define OSINTC_NVIC_CONVERT_PRIO_SET(prio)  (OSBYTE)(((prio) ^ 0xFFu) << OSINTC_NVIC_PRIO_SHIFT)
    #define OSINTC_NVIC_CONVERT_PRIO_GET(prio)  (OSBYTE)(((prio) ^ 0xFFu) >> OSINTC_NVIC_PRIO_SHIFT)

    /* enable  interrupt X */
    #define OSINTC_NVIC_ENABLE_INTX(id)         \
            if ((id) >= 16) OSREG32(OSINTC_NVIC_ISER0 + ((((id)-16)>>5)<<2)) = (OSDWORD)1ul<<((OSDWORD)((id)-16) & 0x1Fu)

    /* disable interrupt X */
    #define OSINTC_NVIC_DISABLE_INTX(id)        \
            if ((id) >= 16) OSREG32(OSINTC_NVIC_ICER0 + ((((id)-16)>>5)<<2)) = (OSDWORD)1ul<<((OSDWORD)((id)-16) & 0x1Fu)

        /* fast version */
        /* set   interrupt pending X */
        #define OSINTC_NVIC_SET_PENDING_INTX(id)    \
                if ((id) >= 16) OSREG32(OSINTC_NVIC_STIR) = ((id)-16) & 0x1FFUL

    /* clear interrupt pending X */
    #define OSINTC_NVIC_CLEAR_PENDING_INTX(id)      \
            if ((id) >= 16)     OSREG32(OSINTC_NVIC_ICPR0 + ((((id)-16)>>5)<<2)) = (OSDWORD)1ul<<((OSDWORD)((id)-16) & 0x1Fu)

    /* interrupt X PENDING status  */
    #define OSINTC_NVIC_PENDING_STATUS_INTX(id)      \
            (((id) >= 16) ?  ((OSREG32(OSINTC_NVIC_ICPR0 + ((((id)-16)>>5)<<2)) >>  (((id)-16) & 0x1Fu) ) & 0x01UL) : 0)

    /* interrupt X ACTIVE status  */
    #define OSINTC_NVIC_ACTIVE_STATUS_INTX(id)      \
            (((id) >= 16) ?  ((OSREG32(OSINTC_NVIC_IABR0 + ((((id)-16)>>5)<<2)) >>  (((id)-16) & 0x1Fu) ) & 0x01UL) : 0)

    /* interrupt X PENDING or ACTIVE status  */
    #define OSINTC_NVIC_PEND_OR_ACTIVE_STATUS_INTX(id)  \
            (((id) >= 16) ?  (((OSREG32(OSINTC_NVIC_IABR0 + ((((id)-16)>>5)<<2)) >>  (((id)-16) & 0x1Fu) ) & 0x01UL) || \
                              ((OSREG32(OSINTC_NVIC_ICPR0 + ((((id)-16)>>5)<<2)) >>  (((id)-16) & 0x1Fu) ) & 0x01UL)) : 0)


    #define OSINTC_SYS_PRIO_INTX(id)            OSREG8( OSINTC_SYS_SHPR1 + ((id)-4) )  /**< interrupt priority */
    #define OSINTC_NVIC_PRIO_INTX(id)           OSREG8( OSINTC_NVIC_IPR0 +  (id)    )  /**< interrupt priority */

    /* set interrupt priority */
    #define OSINTC_SET_PRIO_INTX(id, val)                                \
            if (id>=16) OSINTC_NVIC_PRIO_INTX((id)-16) = (OSBYTE)(val);  \
                 else   OSINTC_SYS_PRIO_INTX(id)       = (OSBYTE)(val)





#ifdef __cplusplus
}
#endif

#endif /*OS_HW_INTC_H*/

/** @} */

