#ifndef BCC1_M_H
#define BCC1_M_H
/**************************************************************************************
* 
*   NXP(TM) and the NXP logo are trademarks of NXP.
*   All other product or service names are the property of their respective owners.
*   (c) Copyright 2012 - 2016 Freescale Semiconductor Inc.
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
*   Description:  hardware specific definitions for benchmark
*
**************************************************************************************/

#define APPNEAR

/* Branch Unit Control and Status Register (BUCSR) */
    
#if defined(OSGCCARM) || defined(OSGHSARM) || defined(OSDS5ARM)
    #define SetBUCSR()
#endif


#define EnableBTB()



#define OSREG32( address )      ( *(volatile OSDWORD*)(address) ) /**<  32-bit register */
#define OSREG16( address )      ( *(volatile OSWORD *)(address) ) /**<  16-bit register */
#define OSREG8( address )       ( *(volatile OSBYTE *)(address) ) /**<  8-bit  register */


#define FLASH2WS()
/* uncomment it to enable pin manipulations */
/* #define USEPORT */

#if defined(USEPORT) /* Below configuration is for S32K148 using the daughter board S32K14xCVD-Q144, SCH-29559 */

/* Port Control and Interrupts (PORT) */
#define PORTA_MUX_BASE_ADDR 0x40049000
#define PORTE_MUX_BASE_ADDR 0x4004D000

#define PORTA_MUX_BASE_ADDR 0x40049000 /* Port Data Direction Register PDDR */
#define PORTE_MUX_BASE_ADDR 0x4004D000

#define PCR        0x00000140                          /* MUX = 001, DSE = 1  */
#define GPIOPCR0  OSREG32(PORTA_MUX_BASE_ADDR + 0x38) /* PTA14, 0x38, P24_3,  R386 */
#define GPIOPCR1  OSREG32(PORTE_MUX_BASE_ADDR + 0x00) /* PTE0,  0x00, P24_5,  R387 */
#define GPIOPCR2  OSREG32(PORTE_MUX_BASE_ADDR + 0x04) /* PTE1,  0x04, P24_7,  R388 */
#define GPIOPCR3  OSREG32(PORTA_MUX_BASE_ADDR + 0x34) /* PTA13, 0x34, P24_9,  R389 */
#define GPIOPCR4  OSREG32(PORTA_MUX_BASE_ADDR + 0x30) /* PTA12, 0x30, P24_11, R390 */
#define GPIOPCR5  OSREG32(PORTA_MUX_BASE_ADDR + 0x2C) /* PTA11, 0x2C, P24_13, R391 */
#define GPIOPCR6  OSREG32(PORTE_MUX_BASE_ADDR + 0x28) /* PTE10, 0x28, P24_43, R402 */
#define GPIOPCR7  OSREG32(PORTE_MUX_BASE_ADDR + 0x2C) /* PTE11, 0x2C, P24_45, R401 */

/* General-Purpose Input/Output (GPIO) */
#define GPIOA_BASE_ADDR 0x400FF000
#define GPIOE_BASE_ADDR 0x400FF100

#define GPIOA_PDOR (GPIOA_BASE_ADDR + 0x0)
#define GPIOE_PDOR (GPIOE_BASE_ADDR + 0x0)

#define GPIOA_PDDR (GPIOA_BASE_ADDR + 0x14)
#define GPIOE_PDDR (GPIOE_BASE_ADDR + 0x14)

/* Set GPIO output direction */
#define SetPDDR(gpio_pddr,channel)        (OSREG32(gpio_pddr) |= (1 << channel))       /* PTA14 -> channel = 14, PTE0 -> channel = 0  */

#define SetGPIO_PDDR0 SetPDDR(GPIOA_PDDR,14) /* PTA14, 0x38, P24_3,  R386 */
#define SetGPIO_PDDR1 SetPDDR(GPIOE_PDDR,0)  /* PTE0,  0x00, P24_5,  R387 */
#define SetGPIO_PDDR2 SetPDDR(GPIOE_PDDR,1)  /* PTE1,  0x04, P24_7,  R388 */
#define SetGPIO_PDDR3 SetPDDR(GPIOA_PDDR,13) /* PTA13, 0x34, P24_9,  R389 */
#define SetGPIO_PDDR4 SetPDDR(GPIOA_PDDR,12) /* PTA12, 0x30, P24_11, R390 */
#define SetGPIO_PDDR5 SetPDDR(GPIOA_PDDR,11) /* PTA11, 0x2C, P24_13, R391 */
#define SetGPIO_PDDR6 SetPDDR(GPIOE_PDDR,10) /* PTE10, 0x28, P24_43, R402 */
#define SetGPIO_PDDR7 SetPDDR(GPIOE_PDDR,11) /* PTE11, 0x2C, P24_45, R401 */

/* Set/clear GPIO output data*/
#define SetPDOR(gpio_pdor,channel)        (OSREG32(gpio_pdor) |= (1 << channel))       /* PTA14 -> channel = 14, PTE0 -> channel = 0  */
#define ClrPDOR(gpio_pdor,channel)        (OSREG32(gpio_pdor) &= ~(1 << channel))       /* PTA14 -> channel = 14, PTE0 -> channel = 0  */

#define SetPIN0 SetPDOR(GPIOA_PDOR,14) /* PTA14, 0x38, P24_3,  R386 */
#define SetPIN1 SetPDOR(GPIOE_PDOR,0)  /* PTE0,  0x00, P24_5,  R387 */
#define SetPIN2 SetPDOR(GPIOE_PDOR,1)  /* PTE1,  0x04, P24_7,  R388 */
#define SetPIN3 SetPDOR(GPIOA_PDOR,13) /* PTA13, 0x34, P24_9,  R389 */
#define SetPIN4 SetPDOR(GPIOA_PDOR,12) /* PTA12, 0x30, P24_11, R390 */
#define SetPIN5 SetPDOR(GPIOA_PDOR,11) /* PTA11, 0x2C, P24_13, R391 */
#define SetPIN6 SetPDOR(GPIOE_PDOR,10) /* PTE10, 0x28, P24_43, R402 */
#define SetPIN7 SetPDOR(GPIOE_PDOR,11) /* PTE11, 0x2C, P24_45, R401 */

#define ClrPIN0 ClrPDOR(GPIOA_PDOR,14) /* PTA14, 0x38, P24_3,  R386 */
#define ClrPIN1 ClrPDOR(GPIOE_PDOR,0)  /* PTE0,  0x00, P24_5,  R387 */
#define ClrPIN2 ClrPDOR(GPIOE_PDOR,1)  /* PTE1,  0x04, P24_7,  R388 */
#define ClrPIN3 ClrPDOR(GPIOA_PDOR,13) /* PTA13, 0x34, P24_9,  R389 */
#define ClrPIN4 ClrPDOR(GPIOA_PDOR,12) /* PTA12, 0x30, P24_11, R390 */
#define ClrPIN5 ClrPDOR(GPIOA_PDOR,11) /* PTA11, 0x2C, P24_13, R391 */
#define ClrPIN6 ClrPDOR(GPIOE_PDOR,10) /* PTE10, 0x28, P24_43, R402 */
#define ClrPIN7 ClrPDOR(GPIOE_PDOR,11) /* PTE11, 0x2C, P24_45, R401 */

#define IniPort()   \
        GPIOPCR0 = PCR; \
        GPIOPCR1 = PCR; \
        GPIOPCR2 = PCR; \
        GPIOPCR3 = PCR; \
        GPIOPCR4 = PCR; \
        GPIOPCR5 = PCR; \
        GPIOPCR6 = PCR; \
        GPIOPCR7 = PCR; \
        SetGPIO_PDDR0; \
        SetGPIO_PDDR1; \
        SetGPIO_PDDR2; \
        SetGPIO_PDDR3; \
        SetGPIO_PDDR4; \
        SetGPIO_PDDR5; \
        SetGPIO_PDDR6; \
        SetGPIO_PDDR7; \
        ClrPort()

#define SetPort(nn)   \
        ClrPort();\
        Set##nn       /* set pin */
		
#define ClrPort()   \
        ClrPIN0;\
        ClrPIN1;\
        ClrPIN2;\
        ClrPIN3;\
        ClrPIN4;\
        ClrPIN5;\
        ClrPIN6;\
        ClrPIN7    /* reset pin */

#else /* defined(USEPORT) */

#define ClrPort()
#define SetPIN0
#define SetPIN1
#define SetPIN2
#define SetPIN3
#define SetPIN4
#define SetPIN5
#define SetPIN6
#define SetPIN7
#define IniPort()
#define SetPort(nn)

#endif /* defined(USEPORT) */

#define absdiff(t_ini, t_final)  ((t_ini) - (t_final)) /* (t_ini) - (t_final) for count down counter; (t_final) - (t_ini) for count up counter  */

#define CMPSetHW(Channel)
#define ClearCMP(Channel)   OSFTM0_CnSC(Channel) &= ~OSFTM_CnSC_CHF_MASK  /* Clear Interrupt Request Flag */
#define EnableCMP(Channel)  OSFTM0_CnSC(Channel) |=  OSFTM_CnSC_CHIE_MASK /* Enable Interrupts */
#define DisableCMP(Channel) OSFTM0_CnSC(Channel) &= ~OSFTM_CnSC_CHIE_MASK /* Disable Interrupts */

/* ********************* LPIT ************************/
#define LPITBASE             0x40037000
#define LPIT_VERID           OSREG32(LPITBASE)
#define LPIT_PARAM           OSREG32(LPITBASE + 0x4U)
#define LPIT_MCR             OSREG32(LPITBASE + 0x8U)
#define LPIT_MSR             OSREG32(LPITBASE + 0xCU)
#define LPIT_MIER            OSREG32(LPITBASE + 0x10U)
#define LPIT_SETTEN          OSREG32(LPITBASE + 0x14U)
#define LPIT_CLRTEN          OSREG32(LPITBASE + 0x18U)
#define LPIT_TVAL(n)         OSREG32(LPITBASE + ((OSDWORD)10*(n)) + (OSDWORD)0x20U)
#define LPIT_CVAL(n)         OSREG32(LPITBASE + ((OSDWORD)10*(n)) + (OSDWORD)0x24U)
#define LPIT_TCTRL(n)        OSREG32(LPITBASE + ((OSDWORD)10*(n)) + (OSDWORD)0x28U)

#define LPIT_M_CEN_MASK      (1 << 0)  /* Module Clock Enable */
#define LPIT_SW_RST_MASK     (1 << 1)
#define LPIT_DOZE_EN_MASK    (1 << 2)  /* DOZE Mode Enable Bit, timer channels run on DOZE mode */
#define LPIT_DBG_EN_MASK     (1 << 3)

#define LPIT_SET_T_EN_MASK(n)     (1 << n) /* n = 0..3 */
#define LPIT_CLR_T_EN_MASK(n)     (1 << n) /* n = 0..3 */
#define LPIT_MODE_MASK      (3 << 2) /* 00b - 32-bit Periodic Counter */
#define LPIT_T_EN           (1 << 0) /* Timer Enable  */

#define EnableLPIT()        LPIT_MCR = LPIT_M_CEN_MASK | LPIT_DOZE_EN_MASK; LPIT_MCR |= LPIT_SW_RST_MASK; LPIT_MCR &= ~LPIT_SW_RST_MASK
#define EnableLPIT_CH(n)    LPIT_TCTRL(n) &= ~LPIT_MODE_MASK;  LPIT_TCTRL(n) |= LPIT_T_EN; /*LPIT_SETTEN |= LPIT_SET_T_EN_MASK(n); */ /*; LPIT_CVAL(n) = 0xFFFFFFFF*/
#define DisableLPIT_CH(n)   LPIT_CLRTEN |= LPIT_CLR_T_EN_MASK(n); LPIT_TCTRL(n) &= ~LPIT_T_EN
#define InitTime() EnableLPIT()
#define StartTime() LPIT_TVAL(0) = 0xFFFFFFFF; EnableLPIT_CH(0)
#define GetTime() LPIT_CVAL(0) & 0xFFFFFFFF
#define ClearTime()         /* LPIT_CVAL(0) = 0xFFFFFFFF */
/***** end LPIT ******/



#define TrustedApplication_START_SEC_VAR_FAST_UNSPECIFIED
#include "MemMap.h"
extern OSDWORD APPNEAR volatile sysCnt;         /* counter for "useful" work */
extern OSDWORD APPNEAR volatile nosys;          /* counter for "useful" work w/o system overhead */
extern OSWORD  APPNEAR volatile procent;        /* result goes here */
#define TrustedApplication_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "MemMap.h"

#define SYNCHRON 0x02000000             /* time for synchronization     */
#define MEASURE  0x04000000             /* time of measurement = 98 ms  */
#define MEASURE1 SYNCHRON + MEASURE
#define MEASURE2 SYNCHRON + 2*MEASURE


/*
 * CUR100MS is calculated for FTM as hardware counter
 * 1 tick = 1/timer_input_frequency (s).
 * ==> 1s = timer_input_frequency (ticks)
 * ==> 1ms = timer_input_frequency/1000 (ticks)
 * ==> CUR100MS = timer_input_frequency/10 (ticks)
*/
/*
 * CUR1MS is calculated for FTM0 as software system timer.
 * 1 tick = duration/TimerModuloValue = 1/timer_input_frequency_Hz.
 * duration = TimerModuloValue/timer_input_frequency_Hz (s
 * = TimerModuloValue/timer_input_frequency_Hz * 1000 (ms)
 * 1 tick .... duration
 * CUR1MS .... 1ms
 * ==> CUR1MS = 1/duration ticks
 * 40000000/(65535*1000) = 0.61036
*/
#define CUR100MS    4000000
#define CUR1MS      0.61036



/*** definitions for measuring stack usage ***/

/*** stack symbols ***/
#define SP_TOP    ((OSBYTE *)OSSTACKTOP)
#define SP_BOTTOM ((OSBYTE *)OSSTACKBOTTOM)

#define STACKPATTERN 0xA5A5A5A5                 /* pattern to fill stack */

/*** stack functions prototypes   ***/
OSDWORD GetUsedBytes( OSBYTE* start, OSDWORD num );
void IniStack( OSBYTE* start, OSDWORD num  );

#endif /* BCC1_M_H */

