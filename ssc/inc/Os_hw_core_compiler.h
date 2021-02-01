/**
*   @file    Os_hw_core_compiler.h
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

#ifndef OS_HW_CORE_COMPILER_H_
#define OS_HW_CORE_COMPILER_H_


#ifdef __cplusplus
extern "C"
{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Os_hw_core_compiler_h_REF_19_4_1
* Violates MISRA 2004 Required Rule 19.4, Expression-like macro not parenthesized
* The macro cannot be parenthesized because of assembler limitation, in all instances of
* this macro usage the macro is in brackets.
*/

#include <Os_hw_core_compiler_api.h>   /* get the defines in the private space too */

#define OSTEXT_START_SEC_CODE
#include "Os_sections.h"






#if !defined(OSGCCARM) && !defined(OSGHSARM) && !defined(OSDS5ARM) && !defined(OSIARARM)
#error "Compiler is not defined"
#endif



#if defined(OSGCCARM) || defined(OSIARARM)


OSINLINE OSDWORD OSCNTLZW (register OSDWORD regx)
{
    register OSDWORD result_reg;

    OSASM ( "clz %0, %1" : "=r" (result_reg) : "r" (regx));

    return (result_reg);
}



/* Disable/Enable Hardware Interrupts */
#define OSDHI()        OSASM ("cpsid i")
#define OSEHI()        OSASM ("dsb\n cpsie i\n")

#define OS_SHUTDOWN_INTERRUPTS()   OSASM ("cpsid i")


/* Set the SP register new value */

OSINLINE void OSLOADSP (OSDWORD * loadsp)
{
    #if defined(OSGHSARM)
    OSMSYNC();
    #endif
    OSASM ( " mov r13, %0" : : "r" (loadsp));

}




extern void OSArmDeactivateIsr(OSDWORD saved_xpsr, OSDWORD saved_lr);



/* not yet used on ARM */
/* Set the PID0 register value - not yet used on ARM */
#if defined(OSGCCARM)
OSINLINE void OSSetPID0 (__attribute__ ((unused)) register OSDWORD x)
{
}
#else
OSINLINE void OSSetPID0 (OSDWORD x)
{
}
#endif



#if defined(OSUSEWAIT)
    OSINLINE void OSWAIT (void)
    {
        OSASM ("wfi");
    }
#else
    /* 'wait' can stop some clk(depends on derivative) */
    #define OSWAIT()
#endif /* defined(OSUSEWAIT) */






#if defined(OSUSEISRSTACK)      || defined(OSSYSTIMER) || defined(OS2SYSTIMER) || \
    defined(OSTIMINGPROTECTION) || defined(OSMEMPROTECTION)


    OSINLINE void OSLoadISRSP (register OSDWORD * isrsp)
    {
        register OSDWORD tmp_reg;
        #if defined(OSGHSARM)
        OSMSYNC();
        #endif
        /*
         * MEM[isrsp-4] = r1; save current stack pointer (R1) on new stack pointed by ISRSP
         */
        OSASM ( "str r13, [ %0 ,#-4]" : : "r" (isrsp) );

        /*
         * r1 = isrsp - 8 ; new stack pointer points to new stack
         */
        OSASM ( "add %0, %1, #-8" :  "=r" (tmp_reg) : "r" (isrsp));
        OSASM ( "mov r13, %0    " : : "r" (tmp_reg));
    }


    OSINLINE void OSRestoreSP (void)
    {
        /*
         * r1 = MEM[r1 + 8] ; r1 (new stack pointer)  = r1 (current stack) + 8;
         * restore old stack pointer from location where it was saved on current stack
         */
        #if defined(OSGHSARM)
        OSMSYNC();
        #endif
        OSASM ( "ldr r13, [ r13 ,#4]"::);
    }


#else

    #define OSRestoreSP()

#endif  /* defined(OSUSEISRSTACK) || defined(OSSYSTIMER) || defined(OS2SYSTIMER) || \
defined(OSTIMINGPROTECTION) || defined(OSMEMPROTECTION) */


#endif /* defined(OSGCCARM) || defined(OSIARARM) */



#if defined(OSGHSARM)


OSINLINE OSDWORD OSCNTLZW (OSDWORD value)
{

    return __CLZ32(value);

}



/* Disable/Enable Hardware Interrupts */
#define OSDHI()        OSASM ("cpsid i")
#define OSEHI()        OSASM ("dsb\n cpsie i\n")

#define OS_SHUTDOWN_INTERRUPTS()   OSASM ("cpsid i")


/* Set the SP register new value */

OSASM void OSLOADSP (OSDWORD * loadsp)
{

%reg loadsp
   dsb
   mov r13, loadsp

%error
}




extern void OSArmDeactivateIsr(OSDWORD saved_xpsr, OSDWORD saved_lr);



/* not yet used on ARM */
/* Set the PID0 register value - not yet used on ARM */
OSINLINE void OSSetPID0 (__attribute__ ((unused)) register OSDWORD x)
{

}



#if defined(OSUSEWAIT)
    OSINLINE void OSWAIT (void)
    {
        OSASM ("wfi");
    }
#else
    /* 'wait' can stop some clk(depends on derivative) */
    #define OSWAIT()
#endif /* defined(OSUSEWAIT) */






#if defined(OSUSEISRSTACK)      || defined(OSSYSTIMER) || defined(OS2SYSTIMER) || \
    defined(OSTIMINGPROTECTION) || defined(OSMEMPROTECTION)


extern void OSLoadISRSP (OSDWORD * isrsp);

OSASM void OSRestoreSP (void)
{
    /*
     * r1 = MEM[r1 + 8] ; r1 (new stack pointer)  = r1 (current stack) + 8;
     * restore old stack pointer from location where it was saved on current stack
     */
    dsb
    ldr r13, [ r13 ,#4]
}


#else

    #define OSRestoreSP()

#endif  /* defined(OSUSEISRSTACK) || defined(OSSYSTIMER) || defined(OS2SYSTIMER) || \
defined(OSTIMINGPROTECTION) || defined(OSMEMPROTECTION) */


#endif /* defined(OSGHSARM) */



#if defined(OSDS5ARM)


OSINLINE OSDWORD OSCNTLZW (OSDWORD value)
{
    return __clz(value); /* use intrinsic */
}



/* Disable/Enable Hardware Interrupts */
#define OSDHI()        OSASM ("cpsid i")
#define OSEHI()        OSASM volatile ("dsb\n cpsie i\n")

#define OS_SHUTDOWN_INTERRUPTS()   OSASM ("cpsid i")


/* Set the SP register new value */
#pragma diag_suppress 667
OSINLINE OSASM void OSLOADSP (OSDWORD * loadsp)
{
   dsb
   mov r13, r0

   bx lr
}
#pragma diag_default 667



extern void OSArmDeactivateIsr(OSDWORD saved_xpsr, OSDWORD saved_lr);



/* not yet used on ARM */
/* Set the PID0 register value - not yet used on ARM */
OSINLINE void OSSetPID0 (register OSDWORD x)
{

}



#if defined(OSUSEWAIT)
    OSINLINE void OSWAIT (void)
    {
        OSASM ("wfi");
    }
#else
    /* 'wait' can stop some clk(depends on derivative) */
    #define OSWAIT()
#endif /* defined(OSUSEWAIT) */






#if defined(OSUSEISRSTACK)      || defined(OSSYSTIMER) || defined(OS2SYSTIMER) || \
    defined(OSTIMINGPROTECTION) || defined(OSMEMPROTECTION)

#pragma diag_suppress 667
OSINLINE OSASM void OSLoadISRSP (OSDWORD * isrsp)
{
    dsb
    /*
     * MEM[isrsp-4] = r1; save current stack pointer (R1) on new stack pointed by ISRSP
     */
    str r13, [ r0, #-4 ]

    /*
     * r1 = isrsp - 8; new stack pointer points to new stack
     */
    add  r0, r0, #-8
    mov r13, r0

    bx lr

}
#pragma diag_default 667

#pragma diag_suppress 667
OSINLINE OSASM void OSRestoreSP (void)
{
    /*
     * r1 = MEM[r1 + 8] ; r1 (new stack pointer)  = r1 (current stack) + 8;
     * restore old stack pointer from location where it was saved on current stack
     */
    dsb
    ldr r13, [ r13 ,#4]

    bx lr
}
#pragma diag_default 667

#else

    #define OSRestoreSP()

#endif  /* defined(OSUSEISRSTACK) || defined(OSSYSTIMER) || defined(OS2SYSTIMER) || \
defined(OSTIMINGPROTECTION) || defined(OSMEMPROTECTION) */


#endif /* defined(OSDS5ARM) */



#define OSTEXT_STOP_SEC_CODE
#include "Os_sections.h"

#ifdef __cplusplus
}
#endif

#endif /*OS_HW_CORE_COMPILER_H_*/

/** @} */

