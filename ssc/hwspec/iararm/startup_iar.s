/******************************************************************************
*
*   NXP(TM) and the NXP logo are trademarks of NXP
*   All other product or service names are the property of their respective owners.
*   (c) Copyright 2016 Freescale Semiconductor Inc.
*   Copyright 2017 NXP
*   All Rights Reserved.
*
*   You can use this example for any purpose on any computer system with the
*   following restrictions:
*
*   1. This example is provided  as is , without warranty.
*
*   2. You don't remove this copyright notice from this example or any direct
*      derivation thereof.
*
* Description:    Startup code for OS/S32K
*
* Notes:
*
******************************************************************************/


    SECTION .startup : CODE

    EXPORT  Reset_Handler

    EXTERN  ?main
    EXTERN  VTABLE
    EXTERN  CSTACK$$Limit

VTOR_REG EQU 0xE000ED08

Reset_Handler

    ; set SP reg
    ldr     r0,=CSTACK$$Limit
    mov     sp,r0

    ; Initialize the GPRs
    MOV     r0,#0
    MOV     r1,#0
    MOV     r2,#0
    MOV     r3,#0
    MOV     r4,#0
    MOV     r5,#0
    MOV     r6,#0
    MOV     r7,#0
    MOV     r8,#0
    MOV     r9,#0
    MOV     r10,#0
    MOV     r11,#0
    MOV     r12,#0

    /* relocate vector table to RAM */
    LDR  r0, =VTOR_REG
    LDR  r1, =VTABLE
    STR  r1,[r0]


    /* disable WDG */
    ldr  r0, =0x40052004
    ldr  r1, =0xD928C520
    ldr  r2, =0x40052008
    ldr  r3, =0x0000FFFF
    ldr  r4, =0x40052000
    ldr  r5, =0x00002120
    str  r1, [r0]  /* SD:0x40052004 = 0xD928C520   Unlock */
    str  r3, [r2]  /* SD:0x40052008 = 0xD928       maximum timeout value*/
    str  r5, [r4]  /* SD:0x40052000 = 0x2120       disable Wdg */

    import main
    import SystemInit

    /* Branch to main() */
    LDR     r0, =?main
    BLX     r0

    B       .                     ; in case main returns


    END
