#ifndef _ARM_CORTEX_M4_H_
#define _ARM_CORTEX_M4_H_
/**************************************************************************************
*
*   NXP(TM) and the NXP logo are trademarks of NXP
*   All other product or service names are the property of their respective owners.
*   (c) Copyright 2014 Freescale Semiconductor Inc.
*   Copyright 2017 NXP
*   All Rights Reserved.
*
*   You can use this example for any purpose on any computer system with the
*   following restrictions:
*
*   1. This example is provided "as is", without warranty.
*
*   2. You don't remove this copyright notice from this example or any direct derivation
*      thereof.
*
*  Description:  _ARM_CORTEX_M4_H_ specifics
*
**************************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif


/*
 * Arm Cortex-M4 System Control Block structure
 */
typedef struct
{
  unsigned int CPUID;                   /* 0x000 RO CPUID Base Register                                   */
  unsigned int ICSR;                    /* 0x004 RW Interrupt Control and State Register                  */
  unsigned int VTOR;                    /* 0x008 RW Vector Table Offset Register                          */
  unsigned int AIRCR;                   /* 0x00C RW Application Interrupt and Reset Control Register      */
  unsigned int SCR;                     /* 0x010 RW System Control Register                               */
  unsigned int CCR;                     /* 0x014 RW Configuration Control Register                        */
  unsigned char SHP[12];                /* 0x018 RW System Handlers Priority Registers (4-7, 8-11, 12-15) */
  unsigned int SHCSR;                   /* 0x024 RW System Handler Control and State Register             */
  unsigned int CFSR;                    /* 0x028 RW Configurable Fault Status Register                    */
  unsigned int HFSR;                    /* 0x02C RW HardFault Status Register                             */
  unsigned int DFSR;                    /* 0x030 RW Debug Fault Status Register                           */
  unsigned int MMFAR;                   /* 0x034 RW MemManage Fault Address Register                      */
  unsigned int BFAR;                    /* 0x038 RW BusFault Address Register                             */
  unsigned int AFSR;                    /* 0x03C RW Auxiliary Fault Status Register                       */
  unsigned int PFR[2];                  /* 0x040 RO Processor Feature Register                            */
  unsigned int DFR;                     /* 0x048 RO Debug Feature Register                                */
  unsigned int ADR;                     /* 0x04C RO Auxiliary Feature Register                            */
  unsigned int MMFR[4];                 /* 0x050 RO Memory Model Feature Register                         */
  unsigned int ISAR[5];                 /* 0x060 RO Instruction Set Attributes Register                   */
  unsigned int RESERVED0[5];
  unsigned int CPACR;                   /* 0x088 RW Coprocessor Access Control Register                   */
} scb_t;


extern volatile scb_t * SCB;

#ifdef __cplusplus
}
#endif

#endif /* _ARM_CORTEX_M4_H_ */

