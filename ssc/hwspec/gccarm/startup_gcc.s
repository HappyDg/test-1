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

.syntax unified
.cpu cortex-m4

.globl VTABLE
.globl _Stack_start

.section .startup

.thumb
.thumb_func

.equiv VTOR_REG, 0xE000ED08


.align 2
.globl Reset_Handler
.type Reset_Handler, %function
Reset_Handler:


    /* set SP reg */
    ldr     r0, =_Stack_start
    mov     sp,r0

	/* Initialize the GPRs */
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
	ldr  r0, =VTOR_REG
	ldr  r1, =VTABLE
	/*ldr  r2, =(1 << 29)
	orr  r1, r2 */ /* r1 = r1 | r2 */
	str  r1,[r0]


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


	/* Zero fill the bss segment */
	ldr  r2, =_bss_start
	ldr  r4, =_bss_end

	mov   r3, #0
FillZerobss:

	str   r3, [r2], #4
	cmp   r2, r4
	bcc   FillZerobss

	/* call system initialization first */
	bl SystemInit

	/* call application entry point */
	bl main

	b . /* in case main returns */

.pool
.size Reset_Handler, . - Reset_Handler





.section .stack_main
.align 3

#ifdef __STACK_SIZE
.equ Stack_Size, __STACK_SIZE
#else
.equ Stack_Size, 0x1000
#endif

.space Stack_Size

