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

#if defined(OSGCCARM)
#define APPNEAR
#endif
#if defined(OSGHSARM)
#define APPNEAR
#endif
#if defined(OSDS5ARM)
#define APPNEAR
#endif
#if defined(OSIARARM)
#define APPNEAR
#endif

/* ST_DELAY tuning */
#define ST_DELAY 140000
#define ST_DELAY1 130000
/* Branch Unit Control and Status Register (BUCSR) */

#if defined(OSGCCARM) || defined(OSGHSARM) || defined(OSDS5ARM) || defined(OSIARARM)
#define SetBUCSR()
#endif



#define EnableBTB()

#define OSREG32( address )      ( *(volatile OSDWORD*)(address) ) /**<  32-bit register */
#define OSREG16( address )      ( *(volatile OSWORD *)(address) ) /**<  16-bit register */
#define OSREG8( address )       ( *(volatile OSBYTE *)(address) ) /**<  8-bit  register */



#define FLASH2WS()



/*  Conditional compilation for this application  */

/* uncomment it to enable pin manipulations */
/* #define USEPORT */

/* comment it to disable timer capture      */
#define USETIMER
#if defined(USEPORT) /* Below configuration is for S32K148 using the daughter board S32K14xCVD-Q144, SCH-29559 */

/* Port Control and Interrupts (PORT) */
#define PORTA_MUX_BASE_ADDR 0x40049000
#define PORTE_MUX_BASE_ADDR 0x4004D000

#define PORTA_MUX_BASE_ADDR 0x40049000 /* Port Data Direction Register PDDR */
#define PORTE_MUX_BASE_ADDR 0x4004D000

#define PCR        0x00000140                         /* MUX = 001, DSE = 1  */
#define GPIOPCR0  OSREG32(PORTA_MUX_BASE_ADDR + 0x38) /* PTA14, 0x38, P24_3,  R386 */
#define GPIOPCR1  OSREG32(PORTE_MUX_BASE_ADDR + 0x00) /* PTE0,  0x00, P24_5,  R387 */
#define GPIOPCR2  OSREG32(PORTE_MUX_BASE_ADDR + 0x04) /* PTE1,  0x04, P24_7,  R388 */
#define GPIOPCR3  OSREG32(PORTA_MUX_BASE_ADDR + 0x34) /* PTA13, 0x34, P24_9,  R389 */
#define GPIOPCR4  OSREG32(PORTA_MUX_BASE_ADDR + 0x30) /* PTA12, 0x30, P24_11, R390 */
#define GPIOPCR5  OSREG32(PORTA_MUX_BASE_ADDR + 0x2C) /* PTA11, 0x2C, P24_13, R391 */
#define GPIOPCR6  OSREG32(PORTE_MUX_BASE_ADDR + 0x24) /* PTE9,  0x24, P24_47, R345 */
#define GPIOPCR7  OSREG32(PORTE_MUX_BASE_ADDR + 0x2C) /* PTE11, 0x2C, P24_43, R401 */

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
#define SetGPIO_PDDR6 SetPDDR(GPIOE_PDDR,9) /* PTE9, 0x24, P24_47, R345 */
#define SetGPIO_PDDR7 SetPDDR(GPIOE_PDDR,11) /* PTE11, 0x2C, P24_43, R401 */

/* Set/clear GPIO output data*/
#define SetPDOR(gpio_pdor,channel)        (OSREG32(gpio_pdor) |= (1 << channel))       /* PTA14 -> channel = 14, PTE0 -> channel = 0  */
#define ClrPDOR(gpio_pdor,channel)        (OSREG32(gpio_pdor) &= ~(1 << channel))       /* PTA14 -> channel = 14, PTE0 -> channel = 0  */

#define SetPIN0 SetPDOR(GPIOA_PDOR,14) /* PTA14, 0x38, P24_3,  R386 */
#define SetPIN1 SetPDOR(GPIOE_PDOR,0)  /* PTE0,  0x00, P24_5,  R387 */
#define SetPIN2 SetPDOR(GPIOE_PDOR,1)  /* PTE1,  0x04, P24_7,  R388 */
#define SetPIN3 SetPDOR(GPIOA_PDOR,13) /* PTA13, 0x34, P24_9,  R389 */
#define SetPIN4 SetPDOR(GPIOA_PDOR,12) /* PTA12, 0x30, P24_11, R390 */
#define SetPIN5 SetPDOR(GPIOA_PDOR,11) /* PTA11, 0x2C, P24_13, R391 */
#define SetPIN6 SetPDOR(GPIOE_PDOR,9) /* PTE9, 0x24, P24_47, R345 */
#define SetPIN7 SetPDOR(GPIOE_PDOR,11) /* PTE11, 0x2C, P24_43, R401 */

#define ClrPIN0 ClrPDOR(GPIOA_PDOR,14) /* PTA14, 0x38, P24_3,  R386 */
#define ClrPIN1 ClrPDOR(GPIOE_PDOR,0)  /* PTE0,  0x00, P24_5,  R387 */
#define ClrPIN2 ClrPDOR(GPIOE_PDOR,1)  /* PTE1,  0x04, P24_7,  R388 */
#define ClrPIN3 ClrPDOR(GPIOA_PDOR,13) /* PTA13, 0x34, P24_9,  R389 */
#define ClrPIN4 ClrPDOR(GPIOA_PDOR,12) /* PTA12, 0x30, P24_11, R390 */
#define ClrPIN5 ClrPDOR(GPIOA_PDOR,11) /* PTA11, 0x2C, P24_13, R391 */
#define ClrPIN6 ClrPDOR(GPIOE_PDOR,9) /* PTE9,  0x24, P24_47, R345 */
#define ClrPIN7 ClrPDOR(GPIOE_PDOR,11) /* PTE11, 0x2C, P24_43, R401 */

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
#define ClrPIN0
#define ClrPIN1
#define ClrPIN2
#define ClrPIN3
#define ClrPIN4
#define ClrPIN5
#define ClrPIN6
#define ClrPIN7
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

    /*********************************** FTM *********************************/
    #define BENCHMARK_OSFTM_SC_TOF_MASK         0x00000200U
    #define SECOND_TIMER_VALUE_MODULO           0xFFFFU
    #define T2_CH0_MODULO                       9999U   /* (250 us / (1/40MHz)) - 1 */

    /************************ FTM 1 - Channel 0 ******************************/
    #define OSFTM1_SC                                  OSREG32(OSFTM1BASE)
    #define OSFTM1_CNT                                 OSREG32(OSFTM1BASE + 0x4U)
    #define OSFTM1_MOD                                 OSREG32(OSFTM1BASE + 0x8U)
    #define OSFTM1_CnSC(n)                             OSREG32(OSFTM1BASE + ((OSDWORD)8*(n)) + (OSDWORD)0xCU)
    #define OSFTM1_CnV(n)                              OSREG32(OSFTM1BASE + ((OSDWORD)8*(n)) + (OSDWORD)0x10U)
    #define OSFTM1_CNTIN                               OSREG32(OSFTM1BASE + 0x4CU)
    #define OSFTM1_STATUS                              OSREG32(OSFTM1BASE + 0x50U)
    #define OSFTM1_MODE                                OSREG32(OSFTM1BASE + 0x54U)
    #define OSFTM1_CONF                                OSREG32(OSFTM1BASE + 0x84U)

    #define SetCMP(Channel)     OSFTM1_CnV(Channel)=T2_CH0_MODULO
    #define ClearCMP(Channel)   OSFTM1_CnSC(Channel) &= ~OSFTM_CnSC_CHF_MASK  /* Clear Interrupt Request Flag */
    #define EnableCMP(Channel)  OSFTM1_CnSC(Channel) |=  OSFTM_CnSC_CHIE_MASK /* Enable Interrupts */
    #define DisableCMP(Channel) OSFTM1_CnSC(Channel) &= ~OSFTM_CnSC_CHIE_MASK /* Disable Interrupts */

    #define DeinitFTM1()        { \
                                OSFTM1_MODE = OSFTM_MODE_WPDIS_MASK; \
                                OSFTM1_CNT = 0x00U;   \
                                OSFTM1_MOD = 0x00U;     \
                                OSFTM1_CONF = 0x00U;    \
                                OSFTM1_SC &= 0x00U;      \
                                OSFTM1_MODE = 0x00U;    \
                                ClearCMP(0);            \
                                DisableCMP(0);          \
                            }

    #define StopTimeFTM1()      OSFTM1_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define GetTimeFTM1()       OSFTM1_CNT & 0x0000FFFF
    #define ClearTimeFTM1()     OSFTM1_CNT = 0

    /* CLKS = 0x01 -> FTM input clock/ CPWMS = 0 -> FTM counter operates in Up Counting mode */
    #define StartTimeFTM1()     { \
                                StopTimeFTM1();  \
                                OSFTM1_MODE = OSFTM_MODE_WPDIS_MASK; \
                                OSFTM1_SC = 0x00U;                   \
                                ClearTimeFTM1();                          \
                                OSFTM1_CNTIN = 0x00U;                \
                                OSFTM1_CnSC(0) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
                                OSFTM1_MOD = SECOND_TIMER_VALUE_MODULO;      \
                                OSFTM1_SC = 0x8U; \
                                OSFTM1_CONF = 0x00000000;            \
                            }
    #define CheckOverflow()     ((OSFTM1_SC & BENCHMARK_OSFTM_SC_TOF_MASK) == BENCHMARK_OSFTM_SC_TOF_MASK)  /* true: have overflow */
    #define ClearOverflow()     OSFTM1_SC &= ~BENCHMARK_OSFTM_SC_TOF_MASK       /* clear overflow */

   /************************ FTM 2 - Channel 0 ******************************/
    #define OSFTM2_SC                                  OSREG32(OSFTM2BASE)
    #define OSFTM2_CNT                                 OSREG32(OSFTM2BASE + 0x4U)
    #define OSFTM2_MOD                                 OSREG32(OSFTM2BASE + 0x8U)
    #define OSFTM2_CnSC(n)                             OSREG32(OSFTM2BASE + ((OSDWORD)8*(n)) + (OSDWORD)0xCU)
    #define OSFTM2_CnV(n)                              OSREG32(OSFTM2BASE + ((OSDWORD)8*(n)) + (OSDWORD)0x10U)
    #define OSFTM2_CNTIN                               OSREG32(OSFTM2BASE + 0x4CU)
    #define OSFTM2_MODE                                OSREG32(OSFTM2BASE + 0x54U)
    #define OSFTM2_CONF                                OSREG32(OSFTM2BASE + 0x84U)

    #define OSCHFREEZE1                                 (0x03U<<6)  
   /* #define OSCHFREEZE1                                 (0x00U<<6) */    /* prevent timer from running in debug mode */

    #define CMPSetHW(Channel)            \
    {                                    \
            OSFTM2_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM2_SC = 0x00U;                   \
            OSFTM2_CNTIN = 0x00U;                \
            OSFTM2_CnSC(Channel) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM2_MOD = OSFTM_MOD_MOD(OSMODULO_MASK);      \
            OSFTM2_SC = OSFTM_SC_PS(0);          \
            OSFTM2_CONF = OSCHFREEZE1;            \
            OSFTM2_SC |=  OSFTM_SC_CLKS(0x01U);  \
    }

    #define OSFTM2_START_CLK()               OSFTM2_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSFTM2_STOP_CLK()                OSFTM2_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */

    #define SetCMP2(Channel)     OSFTM2_STOP_CLK(); OSFTM2_CnV(Channel)=ISR2DELAY; OSFTM2_START_CLK()
    #define ClearCMP2(Channel)   OSFTM2_CnSC(Channel) &= ~OSFTM_CnSC_CHF_MASK        /* clear interrupt flag  */
    #define EnableCMP2(Channel)  OSFTM2_CnSC(Channel) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define DisableCMP2(Channel) OSFTM2_CnSC(Channel) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */
    #define ClearTime2()     OSFTM2_CNT = 0

        /*********************************** FTM3 ********************************/
    #define OSFTM3_SC           OSREG32(OSFTM3BASE)
    #define OSFTM3_CNT          OSREG32(OSFTM3BASE + 0x4U)
    #define OSFTM3_MOD          OSREG32(OSFTM3BASE + 0x8U)
    #define OSFTM3_CnSC(n)      OSREG32(OSFTM3BASE + ((OSDWORD)8*(n)) + (OSDWORD)0xCU)
    #define OSFTM3_CnV(n)       OSREG32(OSFTM3BASE + ((OSDWORD)8*(n)) + (OSDWORD)0x10U)
    #define OSFTM3_CNTIN        OSREG32(OSFTM3BASE + 0x4CU)
    #define OSFTM3_STATUS       OSREG32(OSFTM3BASE + 0x50U)
    #define OSFTM3_MODE         OSREG32(OSFTM3BASE + 0x54U)
    #define OSFTM3_CONF         OSREG32(OSFTM3BASE + 0x84U)

    #define CMPSetHWFTM3(Channel)            \
    {                                    \
            OSFTM3_MODE = OSFTM_MODE_WPDIS_MASK; \
            OSFTM3_SC = 0x00U;                   \
            OSFTM3_CNTIN = 0x00U;                \
            OSFTM3_CnSC(Channel) = OSFTM_CnSC_MSA_MASK | OSFTM_CnSC_MSB_MASK | OSFTM_CnSC_ELSB_MASK | OSFTM_CnSC_ELSA_MASK; \
            OSFTM3_MOD = OSFTM_MOD_MOD(OSMODULO_MASK); \
            OSFTM3_SC = OSFTM_SC_PS(0);           \
            OSFTM3_CONF = OSCHFREEZE1;             \
            OSFTM3_SC |=  OSFTM_SC_CLKS(0x01U);   \
    }

    #define OSFTM3_START_CLK()               OSFTM3_SC |=  OSFTM_SC_CLKS(0x01U)          /* enable  clock */
    #define OSFTM3_STOP_CLK()                OSFTM3_SC &= ~OSFTM_SC_CLKS(0x01U)          /* disable  clock */
    #define SetCMPFTM3(Channel)     OSFTM3_STOP_CLK(); OSFTM3_CnV(Channel)=ISR2DELAY * 2; OSFTM3_START_CLK()
    #define ClearCMPFTM3(Channel)   OSFTM3_CnSC(Channel) &= ~OSFTM_CnSC_CHF_MASK        /* clear interrupt flag  */
    #define EnableCMPFTM3(Channel)  OSFTM3_CnSC(Channel) |=  OSFTM_CnSC_CHIE_MASK       /* enable  channel interrupts */
    #define DisableCMPFTM3(Channel) OSFTM3_CnSC(Channel) &= ~OSFTM_CnSC_CHIE_MASK       /* disable channel interrupts */
    #define ClearINTFTM3(Channel)   (OSFTM3_STATUS &= ~(1 << Channel))        /* clear interrupt flag  */
    #define ClearTimeFTM3()         OSFTM3_CNT = 0
    
#define T2MODULO   0xffff

#define ISR2DELAY  (T2_CH0_MODULO)    /* 0.25 ms delay for OneTimeISR */

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
#define StartTime() LPIT_TVAL(0) = 0xFFFFFFFF; EnableLPIT_CH(0)
#define GetTime() LPIT_CVAL(0) & 0xFFFFFFFF
#define ClearTime()         /* LPIT_CVAL(0) = 0xFFFFFFFF */
/***** end LPIT ******/



#ifdef USETIMER
#define SetStartTime( )      inTime = GetTime( )
#define CalcTime( VarName )  VarName = GetTime( ); VarName = (OSWORD) ( ( inTime + pfm1 ) - VarName )
#else
#define SetStartTime( )
#define CalcTime( VarName )
#endif /* USETIMER */






#define OSSecondFlagIsSet()    (OSFTM1_STATUS & 1) /* Check status flag INT channel 0 of FTM1 */
#define OSSecondClearFlag()    (OSFTM1_STATUS &= ~1)  /* Clear status flag INT channel 0 of FTM1 */
#define OSSecondSWFlagIsSet()  OSSecondFlagIsSet()
#define OSSecondSWClearFlag()  OSSecondClearFlag()


#endif /* BCC1_M_H */
