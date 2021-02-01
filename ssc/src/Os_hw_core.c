/**
*   @file    Os_hw_core.c
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





#if !defined(OSGCCARM) && !defined(OSGHSARM) && !defined(OSDS5ARM) && !defined(OSIARARM)
#error "Compiler is not defined"
#endif



#ifndef _lint

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"

#define OSEXCEPTIONTOS  (OsExceptionStack+(OSEXCEPTIONSTACKSIZE-OSSTKADDS)*4)     /* TOS for exception handlers */

extern char _f_ostext[];
extern char _e_ostext[];



extern void OSExceptionError (OSDWORD exception_address, OSDWORD ea_valid);

#if defined(OSIARARM)
extern void OSInterruptDispatcher (void);
#endif /* OSIARARM */

extern void OSInterruptDispatcher1 (OSDWORD saved_xpsr, OSDWORD saved_lr); /**< called from OSInterruptDispatcher, Located in Os_isr.c */


/*
 * Specifics for ARM CM4
 */

/******************************************************************************
* Function: OSInterruptDispatcher
* Description: wrapper for OSInterruptDispatcher1
* Returns:
* Notes:
******************************************************************************/

#if defined(OSGCCARM) || defined(OSGHSARM)
void OSInterruptDispatcher (void)
{
    OSASM (
    " cpsid i \n\r"
    " push {r14} \n\r"

    " ldr r0, [ r13 ,#0x20] \n\r"
    " mov r1, r14           \n\r"
#if defined(OSISRFPU)
    " vstmdb sp!, {S16-S31} \n\r"
#endif

    " bl OSInterruptDispatcher1 \n\r"

#if defined(OSISRFPU)
    " vldmia sp!, {S16-S31} \n\r"
#endif

#if defined(OSGCCARM)
".equiv REG_ICSR,   0xE000ED04 \n\r"
".equiv SET_PENDSV, 0x10000000 \n\r"
#else
"REG_ICSR   .equ 0xE000ED04 \n\r"
"SET_PENDSV .equ 0x10000000 \n\r"
#endif
    " ldr r0, =REG_ICSR \n\r"
    " ldr r1, =SET_PENDSV \n\r"
    " str r1,[r0] \n\r"
    " dsb \n\r"

    " nop \n\r"
    " cpsie i \n\r"

    " nop \n\r"
    " pop {pc} \n\r"
    " nop \n\r"
    " nop \n\r"
    );

}
#endif /* defined(OSGCCARM) || defined(OSGHSARM) */

#if defined(OSIARARM)
void OSInterruptDispatcher (void)
{
   OSASM (
    "cpsid i                      \n");

   OSASM (
    "mov r2, %0                   \n"
    "push {r14}                   \n"
    "ldr r0, [ r13 ,#0x20]        \n"
    "mov r1, r14                  \n"
#if defined(OSISRFPU)
    "vstmdb sp!, {S16-S31}        \n"
#endif
    "blx r2                       \n"
#if defined(OSISRFPU)
    "vldmia sp!, {S16-S31}        \n"
#endif
    ::"r" (OSInterruptDispatcher1));

   OSASM (
    "mov r0, %0                   \n"
    "mov r1, %1                   \n"
    "str r1,[r0]                  \n"
    "dsb                          \n"
    "nop                          \n"
    "cpsie i                      \n"
    "nop                          \n"
    "pop {pc}                     \n"
    "nop                          \n"
    "nop \n"
    ::"r" (0xE000ED04), "r" (0x10000000));
}

#endif /* OSIARARM */

#if defined(OSDS5ARM)
#pragma diag_suppress 667
OSASM void OSInterruptDispatcher (void)
{

    PRESERVE8
    THUMB
    IMPORT OSInterruptDispatcher1

    cpsid i
    push {r14}

    ldr r0, [ r13 ,#0x20] /* xpsr */
    mov r1, r14           /* lr */

    bl OSInterruptDispatcher1

REG_ICSR EQU   0xE000ED04
SET_PENDSV EQU 0x10000000

    ldr r0, =REG_ICSR
    ldr r1, =SET_PENDSV
    str r1,[r0]   /* set pendsv */
    dsb

    nop
    cpsie i

    nop
    pop {pc}

}
#pragma diag_default 667
#endif /* defined(OSDS5ARM) */


/******************************************************************************
* Function:    OSPendSVException
* Description:
* Returns:
* Notes:
******************************************************************************/
#if defined(OSGCCARM) || defined(OSGHSARM)

void OSPendSVException (void)
{
    /* OS not support FPU in TASK and ISR */
    #if !defined(OSISRFPU) && !defined(OSTSKFPU)
    OSASM (
            " add sp, sp, #(9*4) \n\r" \
            " pop {pc} "
          );
    /*
    OS support FPU in ISR base on Cortex-M4(F) Lazy Stacking and
    Context Switching
        - Check EXC_RETURN[31:0] (LR)
        - If exception return uses floating-point-state then load s0-s15, FPSCR of FPU to stack.
    */
    #else
    OSASM (
            " push {r2}             \n\r"\
            " ands r2, r14,#(1 << 4)\n\r"\
            " pop {r2}              \n\r"\
            " add sp, sp, #(9*4)    \n\r"\
            " BNE EXCEPWOFPU        \n\r"\
            " push {r2}             \n\r"\
            " push {r3}             \n\r"\
            " ldr.w r2, =0xE000EF34 \n\r"\
            " ldr r3, [r2]          \n\r"\
            " bfc r3, #0, #1        \n\r"\
            " str r3, [r2]          \n\r"\
            " pop {r3}              \n\r"\
            " pop {r2}              \n\r"\
            " add sp, sp, #(18*4)   \n\r"\
            " EXCEPWOFPU:           \n\r"\
            " pop {pc} "
      );

    #endif
}

#endif /* defined(OSGCCARM) || defined(OSGHSARM) */

#if defined(OSGHSARM)
void inline OSLoadISRSP (OSDWORD * isrsp)
{
    asm(
        "dsb\n str r13, [ r0,#-4]\n"
        "add r0, r0, #-8\n"
        "mov r13, r0"
       );
}
#endif /* defined(OSGHSARM) */


#if defined(OSDS5ARM)
#pragma diag_suppress 667
OSASM void OSPendSVException (void)
{
    /* OS not support FPU in TASK and ISR */
    #if !defined(OSISRFPU) && !defined(OSTSKFPU)
    OSASM (
            add sp, sp, #(9*4)
            pop {pc}
          );
    #else
    OSASM (
            push {r2}
            ands r2, r14,#(1 << 4)
            pop {r2}
            add sp, sp, #(9*4)
            BNE EXCEPWOFPU
            push {r2}
            push {r3}
            ldr.w r2, =0xE000EF34
            ldr r3, [r2]
            bfc r3, #0, #1
            str r3, [r2]
            pop {r3}
            pop {r2}
            add sp, sp, #(18*4)
            EXCEPWOFPU:
            pop {pc}

            bx lr
          );
    #endif /* (OSISRFPU) */
}
#pragma diag_default 667
#endif /* defined(OSDS5ARM) */

#if defined(OSIARARM)
void OSPendSVException (void)
{

    /* OS not support FPU in TASK and ISR */
    #if !defined(OSISRFPU) && !defined(OSTSKFPU)
    OSASM (
            "add sp, sp, #(9*4)    \n"
            "pop {pc}              \n"
          );
    #else
    OSASM (
            "push {r2}             \n"
            "ands r2, r14,#(1 << 4)\n"
            "pop {r2}              \n"
            "add sp, sp, #(9*4)    \n"
            "BNE EXCEPWOFPU        \n"
            "push {r2}             \n"
            "push {r3}             \n"
            "mov r2, %0            \n"
            "ldr r3, [r2]          \n"
            "bfc r3, #0, #1        \n"
            "str r3, [r2]          \n"
            "pop {r3}              \n"
            "pop {r2}              \n"
            "add sp, sp, #(18*4)   \n"
            "EXCEPWOFPU:           \n"
            "pop {pc} "
            ::"r" (0xE000EF34));
    #endif
}
#endif /* defined(OSIARARM) */


#if defined(OSNOFASTTERMINATE)

/******************************************************************************
* Function:    OSSetJmp
* Description: Save current execution environment into buffer
* Input:       r0  - pointer to environment buffer
* Return:      always 0
* Notes:       The following registers are saved:
*              r1 -> r14(LR)
******************************************************************************/

#if defined(OSGCCARM) || defined(OSGHSARM) || (OSIARARM)
#if defined(OSTSKFPU)
OSSIGNEDDWORD OSSetJmp (OSJMP_BUF jmp_buf, OSBYTE TSKUSEFPU)  /**** check if proper ret.type and parameter can be put in here ****/
{
    OSASM (
        "STR    R13,[R0]        \n"
        "CMP    R1,#0           \n"
        "BEQ    SETFPU          \n"
        "ADD    R0, R0, #64     \n"
        "VSTMIA R0!, {D0-D15}   \n"
        "push {R1}              \n"
        "VMRS R1, FPSCR         \n"
        "STMIA R0!, {R1}        \n"
        "pop {R1}               \n"
        "ADD   R0,R0,#-196      \n"
        "SETFPU:                \n"
        "ADD   R0,R0,#4         \n"
        "STMIA R0,{R1-R12,R14}  \n"
        );

    return 0;
}
#else
OSSIGNEDDWORD OSSetJmp (OSJMP_BUF jmp_buf)  /**** check if proper ret.type and parameter can be put in here ****/
{
    OSASM ( " STR   R13,[R0]        " );
    OSASM ( " ADD   R0,R0,#4        " );
    OSASM ( " STMIA R0,{R1-R12,R14} " );

    return 0;
}
#endif /* OSTSKFPU */
#endif /* (OSGCCARM) || defined(OSGHSARM) || (OSIARARM) */


#if defined(OSDS5ARM)
#pragma diag_suppress 667
#if defined(OSTSKFPU)
OSASM OSSIGNEDDWORD OSSetJmp (OSJMP_BUF jmp_buf, OSBYTE TSKUSEFPU)  /**** check if proper ret.type and parameter can be put in here ****/
{
    STR     R13,[R0]
    CMP     R1,#0
    BEQ     SETFPU
    ADD     R0, R0, #64
    VSTMIA  R0!, {D0-D15}
    VMRS    R1, FPSCR
    STMIA   R0!, {R1}
    ADD     R0,R0,#-196
    SETFPU
    ADD     R0,R0,#4
    STMIA   R0,{R1-R12,R14}

    MOV     R0, #0           /**< return 0; */
    BX      LR
}
#else
OSASM OSSIGNEDDWORD OSSetJmp (OSJMP_BUF jmp_buf)  /**** check if proper ret.type and parameter can be put in here ****/
{
    STR   R13,[R0]
    ADD   R0,R0,#4
    STMIA R0,{R1-R12,R14}

    MOV   R0, #0           /**< return 0; */
    BX    LR
}
#endif /* OSTSKFPU */
#pragma diag_default 667
#endif /* OSDS5ARM */




/******************************************************************************
* Function:    OSLongJmp
* Description: Restore execution environment from buffer
* Input:       r3  - pointer to environment buffer
* Return:      always 1
* Notes:       The following registers are restored:
*              r1, LR (return address),  CTR, r14 - r31
******************************************************************************/

#if defined(OSGCCARM) || defined(OSGHSARM) || (OSIARARM)
#if defined(OSTSKFPU)
OSSIGNEDDWORD OSLongJmp (OSJMP_BUF jmp_buf, OSBYTE TSKUSEFPU)
{
    OSASM (
        "LDR    R13,[R0]        \n"
        "CMP    R1,#0           \n"
        "BEQ    LONGFPU         \n"
        "ADD    R0, R0, #64     \n"
        "VLDMIA R0!, {D0-D15}   \n"
        "push {R1}              \n"
        "LDMIA  R0!, {R1}       \n"
        "VMSR   FPSCR, R1       \n"
        "pop {R1}               \n"
        "ADD    R0,R0,#-196     \n"
        "LONGFPU:               \n"
        "ADD    R0,R0,#4        \n"
        "LDMIA  R0,{R1-R12,R14} \n"
        );

    return 1;
}
#else
OSSIGNEDDWORD OSLongJmp (OSJMP_BUF jmp_buf)
{
    OSASM ( " LDR   R13,[R0]        " );
    OSASM ( " ADD   R0,R0,#4        " );
    OSASM ( " LDMIA R0,{R1-R12,R14} " );

    return 1;
}
#endif /* OSTSKFPU */
#endif /* defined(OSGCCARM) || defined(OSGHSARM) */


#if defined(OSDS5ARM)
#pragma diag_suppress 667
#if defined(OSTSKFPU)
OSASM OSSIGNEDDWORD OSLongJmp (OSJMP_BUF jmp_buf, OSBYTE TSKUSEFPU)
{
    LDR     R13,[R0]
    CMP     R1,#0
    BEQ     LONGFPU
    ADD     R0, R0, #64
    VLDMIA  R0!, {D0-D15}
    LDMIA   R0!, {R1}
    VMSR    FPSCR, R1
    ADD     R0,R0,#-196
    LONGFPU
    ADD     R0,R0,#4
    LDMIA   R0,{R1-R12,R14}

    MOV     R0, #1           /**< return 1; */
    BX      LR
}
#else
OSASM OSSIGNEDDWORD OSLongJmp (OSJMP_BUF jmp_buf)
{
    LDR   R13,[R0]
    ADD   R0,R0,#4
    LDMIA R0,{R1-R12,R14}

    MOV   R0, #1           /**< return 1; */
    BX    LR
}
#endif /* OSTSKFPU */
#pragma diag_default 667
#endif /* defined(OSDS5ARM) */


#endif /* defined(OSNOFASTTERMINATE) */



/******************************************************************************
* Function:    OSNmiException
* Description: Handles NMI exception
* Returns:
* Notes:
******************************************************************************/
void OSNmiException (void)
{
    OSExceptionError (0x00000000 /* invalid address */,
                             0x0 /* the address is invalid */ );
}


/******************************************************************************
* Function:    OSHardFaultException
* Description: Handles Hard Fault exception
* Returns:
* Notes:
******************************************************************************/
void OSHardFaultException (void)
{
    OSExceptionError (0x00000000 /* invalid address */,
                             0x0 /* the address is invalid */ );
}



/******************************************************************************
* Function:    OSBusFaultException
* Description: Handles Bus Fault exception
* Returns:
* Notes:
******************************************************************************/
void OSBusFaultException (void)
{

    if ( OSREG8(OSARMCM4_BFSR) & (OSBYTE)0x80  ) {

        OSDWORD fault_address = OSREG32(OSARMCM4_BFAR);

        OSExceptionError ( fault_address /* invalid address  */,
                                     0x1 /* address is valid */ );
    } else {

        OSExceptionError (0x00000000 /* invalid address */,
                                 0x0 /* the address is invalid */ );
    }

}



/******************************************************************************
* Function:    OSUsageFaultException
* Description: Handles Usage Fault exception
* Returns:
* Notes:
******************************************************************************/
void OSUsageFaultException (void)
{
    OSExceptionError (0x00000000 /* invalid address */,
                             0x0 /* the address is invalid */ );
}


/******************************************************************************
* Function:    OSSVCallException
* Description: Handles Usage Fault exception
* Returns:
* Notes:
******************************************************************************/
void OSSVCallException (void)
{
    OSExceptionError (0x00000000 /* invalid address */,
                             0x0 /* the address is invalid */ );
}



/******************************************************************************
* Function:    OSDebugMonitorException
* Description: Handles debug exception
* Returns:     never
******************************************************************************/
void OSDebugMonitorException (void)
{
    OSShutdownOS (E_OS_SYS_FATAL);
}






/******************************************************************************
* Function:    OSReservedException
* Description: Handles Reserved exception
* Returns:
* Notes:
******************************************************************************/
void OSReservedException (void)
{
    OSExceptionError (0x00000000 /* invalid address */,
                             0x0 /* the address is invalid */ );
}


#if defined(OSGCCARM) || defined(OSGHSARM)

void OSArmDeactivateIsr(OSDWORD saved_xpsr, OSDWORD saved_lr)
{
    #if !defined(OSISRFPU) && !defined(OSTSKFPU)
    OSASM (
            " lsl   r0, r0, #23          \n\r" \
            " lsr   r0, r0, #23          \n\r" \
            " orr   r0, r0, #0x01000000  \n\r" \
                                           \
            " push {r0}            \n\r "  \
                                           \
            " ldr   r0,=ret_PC     \n\r "  \
            " push {r0}            \n\r "  \
                                           \
            " push {lr}            \n\r "  \
            " push {r12}           \n\r "  \
                                           \
            " push {r3}            \n\r "  \
            " push {r2}            \n\r "  \
            " push {r1}            \n\r "  \
            " push {r0}            \n\r "  \

            " dsb                  \n\r "  \
                                           \
                                           \
            " mov  lr, r1          \n\r "  \
            " nop                  \n\r "  \
            " nop                  \n\r "  \
            " bx   lr              \n\r "  \
            " nop                  \n\r "  \
            " nop                  \n\r "  \
            " nop                  \n\r "  \
"ret_PC:                           \n\r "  \
            " nop                  \n\r "  \
            " nop                  \n\r "  \
            " bx lr                \n\r "  \
            " nop                  \n\r "  \
            " nop                  \n\r "  \
          );
    #else
    OSASM (
            " push {r2}                  \n\r" \
            " ands r2, r1, (1 << 4)      \n\r" \
            " pop {r2}                   \n\r" \

            " BNE    FRAMEWOFPU          \n\r" \
            " str r2, [sp, #-8]          \n\r" \
            " VMRS r2, FPSCR             \n\r" \
            " add sp,sp,#-4              \n\r" \
            " push {r2}                  \n\r" \
            " ldr r2, [sp]               \n\r" \
            " vstmdb sp!,{S0-S15}        \n\r" \
"FRAMEWOFPU :                            \n\r" \
                                               \
            " lsl   r0, r0, #23          \n\r" \
            " lsr   r0, r0, #23          \n\r" \
            " orr   r0, r0, #0x01000000  \n\r" \
                                           \
            " push {r0}            \n\r "  \
                                           \
            " ldr   r0,=ret_PC     \n\r "  \
            " push {r0}            \n\r "  \
                                           \
            " push {lr}            \n\r "  \
            " push {r12}           \n\r "  \
                                           \
            " push {r3}            \n\r "  \
            " push {r2}            \n\r "  \
            " push {r1}            \n\r "  \
            " push {r0}            \n\r "  \

            " dsb                  \n\r "  \
                                           \
                                           \
            " mov  lr, r1          \n\r "  \
            " nop                  \n\r "  \
            " nop                  \n\r "  \
            " bx   lr              \n\r "  \
            " nop                  \n\r "  \
            " nop                  \n\r "  \
            " nop                  \n\r "  \
"ret_PC:                           \n\r "  \
            " nop                  \n\r "  \
            " nop                  \n\r "  \
            " bx lr                \n\r "  \
            " nop                  \n\r "  \
            " nop                  \n\r "  \
          );
    #endif /* !defined(OSISRFPU) && !defined(OSTSKFPU) */
}
#endif /* defined(OSGCCARM) || defined(OSGHSARM) */

#if defined(OSIARARM)

void OSArmDeactivateIsr(OSDWORD saved_xpsr, OSDWORD saved_lr)
{
    OSASM (
    #if defined(OSISRFPU) || defined(OSTSKFPU)
            "push {r2}                  \n"
            "ands r2, r1, #(1<< 4)      \n"
            "pop {r2}                   \n"

            "BNE    FRAMEWOFPU          \n"
            "str r2, [sp, #-8]          \n"
            "VMRS r2, FPSCR             \n"
            "add sp,sp,#-4              \n"
            "push {r2}                  \n"
            "ldr r2, [sp]               \n"
            "vstmdb sp!,{S0-S15}        \n"
            "FRAMEWOFPU:                \n"
    #endif
            "lsl   r0, r0, #23            \n"
            "lsr   r0, r0, #23            \n"
            "orr   r0, r0, #0x01000000    \n"
            "push {r0}                    \n"
            "mov   r0, pc            \n"
            "add   r0, r0,#0x24            \n"
            "push {r0}                    \n"
            "push {lr}                    \n"
            "push {r12}                   \n"
            "push {r3}                    \n"
            "push {r2}                    \n"
            "push {r1}                    \n"
            "push {r0}                    \n"
            "dsb                          \n"
            "mov  lr, r1                  \n"
            "nop                          \n"
            "nop                          \n"
            "bx   lr                      \n"
            "nop                          \n"
            "nop                          \n"
            "nop                          \n"
            "nop                          \n"
            "bx lr                        \n"
            "nop                          \n"
            "nop                          \n"
          );
}
#endif /* defined(OSIARARM) */

#if defined(OSDS5ARM)

#pragma diag_suppress 667
#if !defined(OSISRFPU) && !defined(OSTSKFPU)
OSASM void OSArmDeactivateIsr(OSDWORD saved_xpsr, OSDWORD saved_lr)
{
        lsl   r0, r0, #23
        lsr   r0, r0, #23
        orr   r0, r0, #0x01000000

        push {r0}

        ldr   r0,=ret_PC
        push {r0}

        push {lr}
        push {r12}

        push {r3}
        push {r2}
        push {r1}
        push {r0}

        dsb

        mov  lr, r1
        nop
        nop
        bx   lr
        nop
        nop
        nop
        nop
ret_PC
        nop
        nop
        nop

        bx lr

        ALIGN

}
#else
OSASM void OSArmDeactivateIsr(OSDWORD saved_xpsr, OSDWORD saved_lr)
{
        push {r2}
        ands r2, r1, (1 << 4)
        pop {r2}

        BNE    FRAMEWOFPU
        str r2, [sp, #-8]
        VMRS r2, FPSCR
        add sp,sp,#-4
        push {r2}
        ldr r2, [sp]
        vstmdb sp!,{S0-S15}
FRAMEWOFPU

        lsl   r0, r0, #23
        lsr   r0, r0, #23
        orr   r0, r0, #0x01000000

        push {r0}

        ldr   r0,=ret_PC
        push {r0}

        push {lr}
        push {r12}

        push {r3}
        push {r2}
        push {r1}
        push {r0}

        dsb

        mov  lr, r1
        nop
        nop
        bx   lr
        nop
        nop
        nop
        nop
ret_PC
        nop
        nop
        nop

        bx lr

        ALIGN

}
#endif /* !defined(OSISRFPU) && !defined(OSTSKFPU) */
#pragma diag_default 667

#endif /* defined(OSDS5ARM) */



#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#endif /*  ifndef _lint  */






#ifdef __cplusplus
}
#endif





/** @} */
