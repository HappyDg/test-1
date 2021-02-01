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
*  Description:  S32K system initialization code
*
**************************************************************************************/

#include "arm_cortex_m4.h"
#include <Os.h>

void SetPLL(void);
void SystemInit(void);
void SetBenchmarkPLL(void);
static void NVIC_SetPriorityGrouping(unsigned int PriorityGroup);


volatile scb_t * SCB = (volatile scb_t *)0xE000ED00;

#if !defined(OSIARARM)
    #define SYSINITSECTION __attribute__ ((section (".systeminit")))
#else
    #define SYSINITSECTION
#endif


SYSINITSECTION
static void NVIC_SetPriorityGrouping(unsigned int PriorityGroup)
{
  /* Set the PRIGROUP[10:8] bits according to NVIC_PriorityGroup value */
  SCB->AIRCR = (unsigned int)0x05FA0000 | PriorityGroup;
}


/*
 * system initialization : system clock, interrupt router ...
 */
SYSINITSECTION
void SystemInit(void)
{

    NVIC_SetPriorityGrouping(0); /* 0 means 7 bits for prio, 1 for sub-prio */

    /*SCB->CCR   |= (1<<3); */ /**< Enables unaligned access traps : Disabled because of IOC */
    SCB->CCR     |=  1;        /**< NonBaseThrdEna */
    SCB->SHP[10]  =  0x00;     /**< PendSV priority 0 */
    /*Enable floating point unit  */
    #if defined (OSISRFPU) || defined (OSTSKFPU) 
    SCB->CPACR   |= (0xF << 20); /**< Enables FPU */
    #endif

    /* system clock initialization */

    /* enable peripheral clocks - write directly to PCC registers */

    (*(volatile unsigned int*)(0x40065000 + 0x80  ))=0x00;   /* FTFC   */
    (*(volatile unsigned int*)(0x40065000 + 0x84  ))=0x00;   /* DMAMUX   */
    (*(volatile unsigned int*)(0x40065000 + 0x90  ))=0x00;   /* FlexCAN0   */
    (*(volatile unsigned int*)(0x40065000 + 0x94  ))=0x00;   /* FlexCAN1   */
    (*(volatile unsigned int*)(0x40065000 + 0x98  ))=0x00;   /* FTM3   */
    (*(volatile unsigned int*)(0x40065000 + 0x9C  ))=0x00;   /* ADC1   */
    #if !defined(S32K142)
    (*(volatile unsigned int*)(0x40065000 + 0xAC  ))=0x00;   /* FlexCAN2   */
    #endif /* !defined(S32K142) */
    (*(volatile unsigned int*)(0x40065000 + 0xB0  ))=0x00;   /* LPSPI0   */
    (*(volatile unsigned int*)(0x40065000 + 0xB4  ))=0x00;   /* LPSPI1   */
    #if !defined(S32K142)
    (*(volatile unsigned int*)(0x40065000 + 0xB8  ))=0x00;   /* LPSPI2   */
    #endif /* !defined(S32K142) */
    (*(volatile unsigned int*)(0x40065000 + 0xC4  ))=0x00;   /* PDB1   */
    (*(volatile unsigned int*)(0x40065000 + 0xC8  ))=0x00;   /* CRC   */
    (*(volatile unsigned int*)(0x40065000 + 0xD8  ))=0x00;   /* PDB0   */
    (*(volatile unsigned int*)(0x40065000 + 0xDC  ))=0x00;   /* LPIT   */
    (*(volatile unsigned int*)(0x40065000 + 0xE0  ))=0x00;   /* FTM0   */
    (*(volatile unsigned int*)(0x40065000 + 0xE4  ))=0x00;   /* FTM1   */
    (*(volatile unsigned int*)(0x40065000 + 0xE8  ))=0x00;   /* FTM2   */
    (*(volatile unsigned int*)(0x40065000 + 0xEC  ))=0x00;   /* ADC0   */
    (*(volatile unsigned int*)(0x40065000 + 0xF4  ))=0x00;   /* RTC   */
    (*(volatile unsigned int*)(0x40065000 + 0x100 ))=0x00;   /* LPTMR0   */
    (*(volatile unsigned int*)(0x40065000 + 0x124 ))=0x00;   /* PORTA   */
    (*(volatile unsigned int*)(0x40065000 + 0x128 ))=0x00;   /* PORTB   */
    (*(volatile unsigned int*)(0x40065000 + 0x12C ))=0x00;   /* PORTC   */
    (*(volatile unsigned int*)(0x40065000 + 0x130 ))=0x00;   /* PORTD   */
    (*(volatile unsigned int*)(0x40065000 + 0x134 ))=0x00;   /* PORTE   */
    #if defined(S32K148)
    (*(volatile unsigned int*)(0x40065000 + 0x150 ))=0x00;   /* SAI0   */
    (*(volatile unsigned int*)(0x40065000 + 0x154 ))=0x00;   /* SAI1   */
    #endif /* defined(S32K148) */
    (*(volatile unsigned int*)(0x40065000 + 0x168 ))=0x00;   /* FlexIO   */
    (*(volatile unsigned int*)(0x40065000 + 0x184 ))=0x00;   /* EWM   */
    (*(volatile unsigned int*)(0x40065000 + 0x198 ))=0x00;   /* LPI2C0   */
    (*(volatile unsigned int*)(0x40065000 + 0x1A8 ))=0x00;   /* LPUART0   */
    (*(volatile unsigned int*)(0x40065000 + 0x1AC ))=0x00;   /* LPUART1   */
    #if !defined(S32K142)
    (*(volatile unsigned int*)(0x40065000 + 0x1B0 ))=0x00;   /* LPUART2   */
    #endif /* !defined(S32K142) */
    #if defined(S32K148)
    (*(volatile unsigned int*)(0x40065000 + 0x1B8 ))=0x00;   /* FTM4   */
    (*(volatile unsigned int*)(0x40065000 + 0x1BC ))=0x00;   /* FTM5   */
    (*(volatile unsigned int*)(0x40065000 + 0x1C0 ))=0x00;   /* FTM6   */
    (*(volatile unsigned int*)(0x40065000 + 0x1C4 ))=0x00;   /* FTM7   */
    #endif /* defined(S32K148) */
    (*(volatile unsigned int*)(0x40065000 + 0x1CC ))=0x00;   /* CMP0   */
    #if defined(S32K148)
    (*(volatile unsigned int*)(0x40065000 + 0x1D8 ))=0x00;   /* QSPI   */
    (*(volatile unsigned int*)(0x40065000 + 0x1E4 ))=0x00;   /* ENET   */
    #endif /* defined(S32K148) */


    (*(volatile unsigned int*)(0x40065000 + 0x80  ))=0xC3000000;   /* FTFC   */
    (*(volatile unsigned int*)(0x40065000 + 0x84  ))=0xC3000000;   /* DMAMUX   */
    (*(volatile unsigned int*)(0x40065000 + 0x90  ))=0xC3000000;   /* FlexCAN0   */
    (*(volatile unsigned int*)(0x40065000 + 0x94  ))=0xC3000000;   /* FlexCAN1   */
    (*(volatile unsigned int*)(0x40065000 + 0x98  ))=0xC3000000;   /* FTM3   */
    (*(volatile unsigned int*)(0x40065000 + 0x9C  ))=0xC3000000;   /* ADC1   */
    #if !defined(S32K142)
    (*(volatile unsigned int*)(0x40065000 + 0xAC  ))=0xC3000000;   /* FlexCAN2   */
    #endif /* !defined(S32K142) */
    (*(volatile unsigned int*)(0x40065000 + 0xB0  ))=0xC3000000;   /* LPSPI0   */
    (*(volatile unsigned int*)(0x40065000 + 0xB4  ))=0xC3000000;   /* LPSPI1   */
    #if !defined(S32K142)
    (*(volatile unsigned int*)(0x40065000 + 0xB8  ))=0xC3000000;   /* LPSPI2   */
    #endif /* !defined(S32K142) */
    (*(volatile unsigned int*)(0x40065000 + 0xC4  ))=0xC3000000;   /* PDB1   */
    (*(volatile unsigned int*)(0x40065000 + 0xC8  ))=0xC3000000;   /* CRC   */
    (*(volatile unsigned int*)(0x40065000 + 0xD8  ))=0xC3000000;   /* PDB0   */
    (*(volatile unsigned int*)(0x40065000 + 0xDC  ))=0xC3000000;   /* LPIT   */
    (*(volatile unsigned int*)(0x40065000 + 0xE0  ))=0xC3000000;   /* FTM0   */
    (*(volatile unsigned int*)(0x40065000 + 0xE4  ))=0xC3000000;   /* FTM1   */
    (*(volatile unsigned int*)(0x40065000 + 0xE8  ))=0xC3000000;   /* FTM2   */
    (*(volatile unsigned int*)(0x40065000 + 0xEC  ))=0xC3000000;   /* ADC0   */
    (*(volatile unsigned int*)(0x40065000 + 0xF4  ))=0xC3000000;   /* RTC   */
    (*(volatile unsigned int*)(0x40065000 + 0x100 ))=0xC3000000;   /* LPTMR0   */
    (*(volatile unsigned int*)(0x40065000 + 0x124 ))=0xC3000000;   /* PORTA   */
    (*(volatile unsigned int*)(0x40065000 + 0x128 ))=0xC3000000;   /* PORTB   */
    (*(volatile unsigned int*)(0x40065000 + 0x12C ))=0xC3000000;   /* PORTC   */
    (*(volatile unsigned int*)(0x40065000 + 0x130 ))=0xC3000000;   /* PORTD   */
    (*(volatile unsigned int*)(0x40065000 + 0x134 ))=0xC3000000;   /* PORTE   */
    #if defined(S32K148)
    (*(volatile unsigned int*)(0x40065000 + 0x150 ))=0xC3000000;   /* SAI0   */
    (*(volatile unsigned int*)(0x40065000 + 0x154 ))=0xC3000000;   /* SAI1   */
    #endif /* defined(S32K148) */
    (*(volatile unsigned int*)(0x40065000 + 0x168 ))=0xC3000000;   /* FlexIO   */
    (*(volatile unsigned int*)(0x40065000 + 0x184 ))=0xC3000000;   /* EWM   */
    (*(volatile unsigned int*)(0x40065000 + 0x198 ))=0xC3000000;   /* LPI2C0   */
    (*(volatile unsigned int*)(0x40065000 + 0x1A8 ))=0xC3000000;   /* LPUART0   */
    (*(volatile unsigned int*)(0x40065000 + 0x1AC ))=0xC3000000;   /* LPUART1   */
    #if !defined(S32K142)
    (*(volatile unsigned int*)(0x40065000 + 0x1B0 ))=0xC3000000;   /* LPUART2   */
    #endif /* !defined(S32K142) */
    #if defined(S32K148)
    (*(volatile unsigned int*)(0x40065000 + 0x1B8 ))=0xC3000000;   /* FTM4   */
    (*(volatile unsigned int*)(0x40065000 + 0x1BC ))=0xC3000000;   /* FTM5   */
    (*(volatile unsigned int*)(0x40065000 + 0x1C0 ))=0xC3000000;   /* FTM6   */
    (*(volatile unsigned int*)(0x40065000 + 0x1C4 ))=0xC3000000;   /* FTM7   */
    #endif /* defined(S32K148) */
    (*(volatile unsigned int*)(0x40065000 + 0x1CC ))=0xC3000000;   /* CMP0   */
    #if defined(S32K148)
    (*(volatile unsigned int*)(0x40065000 + 0x1D8 ))=0xC3000000;   /* QSPI   */
    (*(volatile unsigned int*)(0x40065000 + 0x1E4 ))=0xC3000000;   /* ENET   */
    #endif /* defined(S32K148) */

}

#if defined(OSDS5ARM)
extern void $Super$$main(void);
void $Sub$$main(void)
{
    SystemInit();
    $Super$$main();    /* calls original main() */
}
#endif /* defined(OSDS5ARM) */


/*
 * M4 at X MHz
 */
SYSINITSECTION
void SetPLL(void)
{
  /* TBD */
}
#ifdef SCGINIT

/* System Clock Generator */
#define SCG_BASEADDR    0x40064000U
#define SCG_VERID       (*(volatile unsigned int*)(SCG_BASEADDR + 0x0U   ))
#define SCG_PARAM       (*(volatile unsigned int*)(SCG_BASEADDR + 0x4U   ))
#define SCG_CSR         (*(volatile unsigned int*)(SCG_BASEADDR + 0x10U  ))
#define SCG_RCCR        (*(volatile unsigned int*)(SCG_BASEADDR + 0x14U  ))
#define SCG_VCCR        (*(volatile unsigned int*)(SCG_BASEADDR + 0x18U  ))
#define SCG_HCCR        (*(volatile unsigned int*)(SCG_BASEADDR + 0x1cU  ))
#define SCG_CLKOUTCNFG  (*(volatile unsigned int*)(SCG_BASEADDR + 0x20U  ))
#define SCG_SOSCCSR     (*(volatile unsigned int*)(SCG_BASEADDR + 0x100U ))
#define SCG_SOSCDIV     (*(volatile unsigned int*)(SCG_BASEADDR + 0x104U ))
#define SCG_SOSCCFG     (*(volatile unsigned int*)(SCG_BASEADDR + 0x108U ))
#define SCG_SIRCCSR     (*(volatile unsigned int*)(SCG_BASEADDR + 0x200U ))
#define SCG_SIRCDIV     (*(volatile unsigned int*)(SCG_BASEADDR + 0x204U ))
#define SCG_SIRCCFG     (*(volatile unsigned int*)(SCG_BASEADDR + 0x208U ))
#define SCG_FIRCCSR     (*(volatile unsigned int*)(SCG_BASEADDR + 0x300U ))
#define SCG_FIRCDIV     (*(volatile unsigned int*)(SCG_BASEADDR + 0x304U ))
#define SCG_FIRCCFG     (*(volatile unsigned int*)(SCG_BASEADDR + 0x308U ))
#define SCG_SPLLCSR     (*(volatile unsigned int*)(SCG_BASEADDR + 0x600U ))
#define SCG_SPLLDIV     (*(volatile unsigned int*)(SCG_BASEADDR + 0x604U ))
#define SCG_SPLLCFG     (*(volatile unsigned int*)(SCG_BASEADDR + 0x608U ))

SYSINITSECTION
void SetBenchmarkPLL(void)
{
  
    /* system clock initialization */
    /* FIRC Configuration */
    SCG_FIRCDIV=0x000201u;   /* SCG_FIRCDIV: FIRCDIV2=2, FIRCDIV1=1 */
    SCG_FIRCCFG=0x00;        /* SCG_FIRCCFG: RANGE=0 */
    while(SCG_FIRCCSR & 0x00800000u);
    SCG_FIRCCSR=0x00000001u;   /* SCG_FIRCCSR: FIRCEN=1 */
    while(!(SCG_FIRCCSR & 0x01000000));

    /* SIRC Configuration */
    SCG_SIRCDIV=0x00201u;   /* SCG_SIRCDIV: SIRCDIV2=2, SIRCDIV1=1 */
    SCG_SIRCCFG=0x01;       /* SCG_SIRCCFG: RANGE=1 */
    while(SCG_SIRCCSR & 0x00800000u);
    SCG_SIRCCSR=0x1u;       /* SCG_SIRCCSR: SIRCEN=1 */
    while(!(SCG_SIRCCSR & 0x01000000u));

    /* SOSC Configuration */
    SCG_SOSCDIV = 0x00010101u;  /* SCG_SOSCDIV: SOSCDIV3=1, SOSCDIV2=1, SOSCDIV1=1 */
    SCG_SOSCCFG = 0x00000024u;  /* SCG_SOSCCFG: RANGE=2, EREFS=1 */
    while(SCG_SOSCCSR & 0x00800000u);
    SCG_SOSCCSR= 0x1u;           /* SCG_SOSCCSR: SOSCEN=1 */
    while(!(SCG_SOSCCSR & 0x01000000u));

    /* SCG_RCCR=0x03010001U; */ /* Fast IRC (FIRC_CLK) */
    SCG_RCCR=0x03000001U; /* Fast IRC (FIRC_CLK) */
    while(SCG_SPLLCSR & 0x00800000u);
    SCG_SPLLCSR=0x0U;

    /* SPLL Configuration 80MHz =  PLLCLK= (IN_CLK * MUL)/(2*(PREDIV+1)) */
    SCG_SPLLDIV = 0x00201u;
    SCG_SPLLCFG = 0x40000u;     /* SCG_SPLLCFG: MULT=5, PREDIV=0, SOURCE=0 */
    SCG_SPLLCSR=0x01;           /* SCG_SPLLCSR: SPLLEN=1 */
    while(!(SCG_SPLLCSR & 0x01000000u));

   /* SCG_RCCR=0x06010001U; */ /* System PLL (SPLL_CLK): RUN Mode Configuration - system clock is 40Mhz*/
    SCG_RCCR=0x06010010U;  /* System PLL (SPLL_CLK): RUN Mode Configuration - system clock is 10Mhz, BUS_CLK=40M */
    /* SCG_RCCR=0x03000001U; */ /* Fast IRC (FIRC_CLK): RUN Mode Configuration - system clock is 40Mhz*/
    SCG_VCCR=0x02010003U;  /* Slow IRC (SIRC_CLK): VLPR Mode Configuration */
  /*  SCG_HCCR=0x06000003U; */  /* System PLL (SPLL_CLK): HSPR Mode Configuration */
    SCG_HCCR=0x06010010U;
    /* enable peripheral clocks - write directly to PCC registers */
    (*(volatile unsigned int*)(0x40065000 + 0x98  ))=0x00;   /* FTM3   */
    (*(volatile unsigned int*)(0x40065000 + 0xDC  ))=0x00;   /* LPIT   */
    (*(volatile unsigned int*)(0x40065000 + 0xE0  ))=0x00;   /* FTM0   */
    (*(volatile unsigned int*)(0x40065000 + 0xE4  ))=0x00;   /* FTM1   */
    (*(volatile unsigned int*)(0x40065000 + 0xE8  ))=0x00;   /* FTM2   */
    (*(volatile unsigned int*)(0x40065000 + 0x124 ))=0x00;   /* PORTA   */
    (*(volatile unsigned int*)(0x40065000 + 0x134 ))=0x00;   /* PORTE   */

    (*(volatile unsigned int*)(0x40065000 + 0x98  ))=0xC3000000;   /* FTM3   */
    (*(volatile unsigned int*)(0x40065000 + 0xDC  ))=0xC6000000;   /* LPIT, select SPLLDIV2_CLK */
    (*(volatile unsigned int*)(0x40065000 + 0xE0  ))=0xC3000000;   /* FTM0   */
    (*(volatile unsigned int*)(0x40065000 + 0xE4  ))=0xC3000000;   /* FTM1   */
    (*(volatile unsigned int*)(0x40065000 + 0xE8  ))=0xC3000000;   /* FTM2   */
    (*(volatile unsigned int*)(0x40065000 + 0x124 ))=0xC3000000;   /* PORTA   */
    (*(volatile unsigned int*)(0x40065000 + 0x134 ))=0xC3000000;   /* PORTE   */

}
#endif


