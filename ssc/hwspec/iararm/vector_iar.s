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


    ; Forward declaration of sections.
    SECTION MAIN_STACK:DATA:NOROOT(3)

    SECTION  .vector:CODE

    EXPORT VTABLE

    EXTERN Reset_Handler

    EXTERN OSInterruptDispatcher

    EXTERN OSNmiException
    EXTERN OSHardFaultException
    EXTERN OSBusFaultException
    EXTERN OSUsageFaultException
    EXTERN OSSVCallException
    EXTERN OSDebugMonitorException
    EXTERN OSPendSVException

    EXTERN OSReservedException



    DATA

VTABLE

    DCD sfe(MAIN_STACK)          /* Top of Stack for Initial Stack Pointer */
    DCD Reset_Handler            /* Reset Handler */
    DCD OSNmiException           /* NMI Handler */
    DCD OSHardFaultException     /* Hard Fault Handler */
    DCD OSReservedException      /* Reserved */
    DCD OSBusFaultException      /* Bus Fault Handler */
    DCD OSUsageFaultException    /* Usage Fault Handler */
    DCD OSReservedException      /* Reserved */
    DCD OSReservedException      /* Reserved */
    DCD OSReservedException      /* Reserved */
    DCD OSReservedException      /* Reserved */
    DCD OSSVCallException        /* SVCall Handler */
    DCD OSDebugMonitorException  /* Debug Monitor Handler */
    DCD OSReservedException      /* Reserved */
    DCD OSPendSVException        /* PendSV Handler */
    DCD OSInterruptDispatcher    /* SysTick Handler */

    /* External interrupts 16 - 31 */
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher

    /* External interrupts 32 - 47  */
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher

    /* External interrupts 48 - 63 */
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher

    /* External interrupts 64 - 79  */
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher

    /* External interrupts 80 - 95 */
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher

    /* External interrupts 96 - 111 */
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher

    /* External interrupts 112 - 127 */
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher

    /* External interrupts 128 - 143 */
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher

    /* External interrupts 144 - 159 */
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher

    /* External interrupts  160 - 175 */
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher
    DCD OSInterruptDispatcher

    END

