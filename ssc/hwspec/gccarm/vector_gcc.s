
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
* Description:    Vector table for OS/S32K
*
* Notes:
*
******************************************************************************/

/*
extern void OSInterruptDispatcher( void );

extern void OSNmiException (void);
extern void OSHardFaultException (void);
extern void OSBusFaultException (void);
extern void OSUsageFaultException (void);
extern void OSSVCallException (void);
extern void OSDebugMonitorException (void);
extern void OSPendSVException (void);

extern void OSReservedException (void);

*/

.section  .vector,"a",%progbits
.align 2
.thumb
.globl VTABLE
VTABLE:

/* 0 - 15 */
.long _Stack_start             /* Top of Stack for Initial Stack Pointer */
.long Reset_Handler            /* Reset Handler */
.long OSNmiException           /* NMI Handler */
.long OSHardFaultException     /* Hard Fault Handler */
.long OSReservedException      /* Reserved */
.long OSBusFaultException      /* Bus Fault Handler */
.long OSUsageFaultException    /* Usage Fault Handler */
.long OSReservedException      /* Reserved */
.long OSReservedException      /* Reserved */
.long OSReservedException      /* Reserved */
.long OSReservedException      /* Reserved */
.long OSSVCallException        /* SVCall Handler */
.long OSDebugMonitorException  /* Debug Monitor Handler */
.long OSReservedException      /* Reserved */
.long OSPendSVException        /* PendSV Handler */
.long OSInterruptDispatcher    /* SysTick Handler */

/* External interrupts 16 - 31 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 32 - 47 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 48 - 63 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 64 - 79 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 80 - 95 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 96 - 111 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 112 - 127 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 128 - 143 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 144 - 159 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 160 - 175 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher




.size VTABLE, . - VTABLE

