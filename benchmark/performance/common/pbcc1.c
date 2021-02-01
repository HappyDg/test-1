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
*   Description:  "Body" performance benchmark for BCC1
*
**************************************************************************************/
/* "#include"-s as in Os_counter.c */
#include <Os_prop_autosar.h>
#include <Os_types_basic.h>
#include <Os_types_public.h>
#include <Os_types_common_public.h>
#include <Os_types_common_internal.h>
#include <Os_internal_api.h>
#include <Os_internal_types.h>
#include <Os_internal_config.h>
#include <Os_platform.h>
#include <Os_counter_api.h>
#include <Os_counter_types.h>
#include <Os_counter_internal_api.h>
#include <Os_counter_internal_types.h>
#include <Os_counter_config.h>

#include <Os.h>                          /* AUTOSAR API */

#define APP_START_SEC_CODE
#include "MemMap.h"


#ifdef USETIMER

#define TrustedApplication_START_SEC_VAR_FAST_UNSPECIFIED
#include "MemMap.h"

OSDWORD APPNEAR volatile inTime;    /* temp: start time     */
OSDWORD APPNEAR volatile pfm1;                 /* time loosed on measurement                */

OSDWORD APPNEAR volatile systemTimerIsrTime;   /* time from int-t arises to LeaveISR       */
OSDWORD APPNEAR volatile secondTimerIsrTime;   /* time from int-t arises to LeaveISR       */

OSDWORD APPNEAR volatile interruptLatency;     /* time from int-t arises to end of EnterISR*/
OSDWORD APPNEAR volatile activateTask1FromIsr; /* ActivateTask inside ISR time             */
OSDWORD APPNEAR volatile fromIsrToTask1;
OSDWORD APPNEAR volatile fromActivateToTask2;
OSDWORD APPNEAR volatile returnToBackGroundTask;
OSDWORD APPNEAR volatile activateTaskA1ViaAlarm;
OSDWORD APPNEAR volatile fromSecondTimerIsrToTaskA1;
OSDWORD APPNEAR volatile activated1Task;
OSDWORD APPNEAR volatile activated4Tasks;
OSDWORD APPNEAR volatile fromIsrToTaskT1;
OSDWORD APPNEAR volatile fromIsrToTaskT2;
OSDWORD APPNEAR volatile fromIsrToTaskT3;
OSDWORD APPNEAR volatile fromIsrToTaskT7;
OSDWORD APPNEAR volatile expired1Alarm;
OSDWORD APPNEAR volatile expired4Alarms;
OSDWORD APPNEAR volatile expired8Alarms;
OSDWORD APPNEAR volatile fromLeaveIsrToTaskH1;

OSDWORD APPNEAR volatile fromTeriminateToTask1;
OSDWORD APPNEAR volatile fromTaskT7ToTaskT4;
OSDWORD APPNEAR volatile fromTaskH1ToTaskH4;
OSDWORD APPNEAR volatile fromTaskH4ToTaskH8;

#define TrustedApplication_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "MemMap.h"

#define flag inTime
#define SetFlag( )

#else  /* USETIMER */

#define TrustedApplication_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
OSBYTE volatile flag;                       /* synchronization flag for TASK_BGND */
#define TrustedApplication_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#define SetFlag() flag =  1

#endif /* USETIMER */

extern void SetBenchmarkPLL( void );

void IniSecondTimer( void );
void SystemTimerISR( void );



/***************************************************************************
 * inline function  : EnableCache
 *
 * Description: enables cache
 *
 * Returns: none
 *
 * Notes: none
 **************************************************************************/
void EnableCache( void );
void EnableCache( void )
{

}

void main( void )
{
#if defined(OSIARARM)
    extern void SystemInit(void);
    SystemInit();
#endif  /* OSIARARM */	
    SetBenchmarkPLL( );
    DeinitFTM1();
    OSFTM2_STOP_CLK(); 
    IniPort( );
    EnableLPIT(); 
    ClearTimeFTM1( );
    /* ClearTime( );*/
    ClearTime2();
    EnableCache();
    StartOS( 0 );
}

/*****************************************************************************
 * Function :   IniSecondTimer
 *
 * Description: Initialize HW and start timer as system Second Timer
 *
 * Notes:       This code shall NOT be used in the AUTOSAR applications -
 *              it uses OS internal macros.
 *
 *****************************************************************************/
void IniSecondTimer( void )
{
    SetCMP(0);
    ClearCMP(0);
    OSSecondSWClearFlag ();
    EnableCMP(0);
}

/************************ User's functions: **********************************/
/*****************************************************************************
 * Function :   TASK_BGND
 *
 * Description: performs initializations, measures timings.
 *
 * Notes:       this task has the lowest priority
 *****************************************************************************/
TASK( TASK_BGND )
{
    StartTimeFTM1();
    StartTime();
    CMPSetHW(0);
    SetPort( PIN1 );  /* calculate time from start */

    SetStartTime( );
    #ifdef USETIMER
    pfm1 = GetTime();
    pfm1 -= inTime;    /* time spent for measurements, to be substracted */
    #endif
    ClrPort( );
    /* Use FTM2 channel 0 for task activation */
    SetCMP2(0);
    ClearCMP2(0);
    EnableCMP2(0);




    flag = 0;
    while( flag == 0 ){}                /* wait to task 1 activated */
    ClrPort( );
    CalcTime( returnToBackGroundTask ); /* return to background after ISR */
    DisableCMP2(0);


    flag = 0;
    IniSecondTimer( );
    SetRelAlarm( ALARM_ONE, 1, 0 );     /* one-shot alarm ( 2ms ) */
    while( flag == 0 ){}                /* wait to task 3 activated */
    ClrPort( );
    #ifdef USETIMER
    activateTaskA1ViaAlarm = secondTimerIsrTime; /* fix one-shot alarm interrupt timing */
    #endif
    /* NB! setting alarms in order of attached tasks priorities (from low to high)
       gives a better (~1.5 times) performance in case of many activations at one point */
    SetRelAlarm( ALARM_8, 4, 4 );       /* period 1000 us */
    SetRelAlarm( ALARM_7, 4, 4 );       /* period 1000 us */
    SetRelAlarm( ALARM_6, 4, 4 );       /* period 1000 us */
    SetRelAlarm( ALARM_5, 4, 4 );       /* period 1000 us */
    SetRelAlarm( ALARM_4, 4, 2 );       /* period 500 us  */
    SetRelAlarm( ALARM_3, 4, 2 );       /* period 500 us  */
    SetRelAlarm( ALARM_2, 4, 2 );       /* period 500 us  */
    SetRelAlarm( ALARM_1, 4, 1 );       /* period 250 us  */
    OsIsrTable[OsIsr[115]].userISR = SystemTimerISR; /* replace with OSISRSystemTimer, FTM0, channel 0 */
    /* wait when second timer will be near 1/2 of period before start schedule table to ensure that
       there will not be any interference between schedule table and harmonic alarms  */
    #define MAX_LPIT_VALUE()     0xFFFFFFFFU

    while( (MAX_LPIT_VALUE() - GetTime()) < ST_DELAY ){}
    
    StartScheduleTableRel( ScheduleTable1, 1 );

    for(;;)
    {
        SetPort( PIN7 );    /* toggle pin7 to check MCU speed  */
        ClrPort( );
    }
}

/***************************************************************************
 * Function :   OneTaskISR/OneIsr
 *
 * Description: ISR for timer
 *
 * Notes:
 **************************************************************************/
ISR( OneTaskISR )
{
DisableCMP2(0);
  



    SetPort( PIN4 );

#ifdef USETIMER
	    interruptLatency = (OSWORD)(OSFTM2_CNT - ISR2DELAY - pfm1);
#endif /* USETIMER */

    SetStartTime( );
        ActivateTask( TASK_1 );
    ClrPort( );
        CalcTime( activateTask1FromIsr );
    SetStartTime( );


}
/***************************************************************************
 * Functions:   TASK_1
 *
 * Description: only pin setting and/or timer capture for measurements
 *              done in all tasks
 *
 * Notes:       task 1 is activated from ISR
 **************************************************************************/

TASK( TASK_1 ) /* priority = 21 */
{
    SetPort( PIN4 ); /* the same pin used in ISR */
    CalcTime( fromIsrToTask1 );
    SetStartTime( );
    ActivateTask( TASK_2 );
    SetPort( PIN4 );
    CalcTime( fromTeriminateToTask1 );
    SetStartTime( );
    TerminateTask( );
}

TASK( TASK_2 ) /* priority = 22 */
{
    SetPort( PIN5 );
    CalcTime( fromActivateToTask2 );
    SetFlag( );
    SetStartTime( );
    TerminateTask( );
}

/***************************************************************************
 *
 * Function :   SecondTimerISR
 *
 * Description: stripped copy of AUTOSAR Second Timer ISR
 *
 * Notes:   This code shall NOT be used in the AUTOSAR applications, it is
 *          the part of OS code modified for measurements.
 *
 **************************************************************************/

ISR( SecondTimerISR )
{
    SetPort( PIN4 );

    if (OSSecondSWFlagIsSet() != 0U)    /* if interrupt is not spurious */
    {
        OSSecondSWClearFlag ();

        OSDI ();

        OSCounterTrigger(OS_GETOBJIND(Counter2));

        ClrPort();
        #ifdef USETIMER
		/* secondTimerIsrTime = PIT_LDVALn(0) - PIT_CVALn(0); */ /* time from the point when interrupt raised */
        if (OSFTM1_CNT > OSFTM1_CnV(0))
            secondTimerIsrTime = (OSWORD)(OSFTM1_CNT - OSFTM1_CnV(0));  /* time from the point when interrupt raised */
        else
            secondTimerIsrTime = (OSWORD)(SECOND_TIMER_VALUE_MODULO - OSFTM1_CnV(0) + OSFTM1_CNT);
        OSFTM1_CnV(0) += (OSWORD)(T2_CH0_MODULO);   /* update OSFTM1_CnV(0) each call to ISR */
        #endif
        SetStartTime( );
    }
}

/***************************************************************************
 * Functions:   TaskA
 *
 * Description: only pin setting and/or timer capture for measurements
 *              done in all tasks
 *
 * Notes:       this task are activated by one-shot alarm
 **************************************************************************/

TASK( TASK_ALM ) /* priority = 23 */
{
    SetPort( PIN5 );
    CalcTime( fromSecondTimerIsrToTaskA1 );
    SetFlag( );
    SetStartTime( );
    TerminateTask( );
}

/***************************************************************************
 * Functions:   TASK_h[1...8]
 *
 * Description: only pin setting and/or timer capture for measurements
 *              done in the tasks
 *
 * Notes:       this 8 tasks are activated by Alarm[1...8]
 **************************************************************************/

TASK( TASK_h1 ) /* priority = 8 */
{
    SetPort( PIN4 );  /* the same pin used in SecondTimer ISR */
    CalcTime( fromLeaveIsrToTaskH1 );
    SetStartTime( );
    TerminateTask( );
}

TASK( TASK_h2 ) /* priority = 7 */
{
    TerminateTask( );
}

TASK( TASK_h3 ) /* priority = 6 */
{
    TerminateTask( );
}

TASK( TASK_h4 ) /* priority = 5 */
{
    SetPort( PIN5 );
    CalcTime( fromTaskH1ToTaskH4 );
    SetStartTime( );
    TerminateTask( );
}

TASK( TASK_h5 ) /* priority = 4 */
{
    TerminateTask( );
}

TASK( TASK_h6 ) /* priority = 3 */
{
    TerminateTask( );
}

TASK( TASK_h7 ) /* priority = 2 */
{
    TerminateTask( );
}

TASK( TASK_h8 ) /* priority = 1 */
{
    SetPort( PIN6 );
    CalcTime( fromTaskH4ToTaskH8 );
    SetStartTime( );
    TerminateTask( );
}

/***************************************************************************
 *
 * Function :   ISRSystemTimer
 *
 * Description: stripped copy of AUTOSAR System Timer ISR
 *
 * Notes:   This code shall NOT be used in the AUTOSAR applications, it is
 *          the part of OS code modified for measurements.
 *
 **************************************************************************/
void SystemTimerISR( void )
{
    SetPort( PIN0 );

    OSTPStopBudget();                         /* stop timing protection for preempted runnable */

    if( OSSysTimFlagIsSet() )                 /* if interrupt is not spurious */
    {
        OSSetCurApp(OSINVALID_OSAPPLICATION); /* OS ISR does not belongs to any OS-Application */
        OSSystemEnterISR2();
        OSDI();

        #if (OSNALMS > 0U)
        /* An ISR2 can interrupt this system timer ISR between
           OSSystemEnterISR2() and OSDI(). If that ISR2 calls an alarm
           service (like SetAlarmAbs() or CancelAlarm()), the alarm queue
           may became empty here.
           Secondly, an alarm set by SetAlarmAbs() called from that ISR2
           (for example) may trigger here. So two checks are necessary.
           ENGR00217477 */

        if ((OsCounters[OSTIMER1].alarm != OSALM0) && (OSSysTimFlagIsSet () != 0U))
        {
            OSSysTimClearFlag();                  /* clear output compare interrupt flag */
            /*** NB!: functions beginning with "OS" shall NOT be used in AUTOSAR applications! ***/
            #ifdef USETIMER
            inTime = OSHWCtrGetOC( 0 );
            #endif
            OSCounterNotify( OSTIMER1 );
        }
        #endif

        ClrPort( );
        #ifdef USETIMER
        systemTimerIsrTime = (OSWORD)(OSTIMTCNT - inTime - pfm1);
        #endif
        SetStartTime( );
        OSSystemLeaveISR2();

    }
    OSWARNSUPPRESS
}

/***************************************************************************
 * Functions:   TASK_t[1...7]
 *
 * Description: only pin setting and/or timer capture for measurements
 *              done in the tasks
 *
 * Notes:       this 7 tasks are activated from ScheduleTable
 **************************************************************************/

TASK( TASK_t1 )
{
    SetPort( PIN0 );    /* the same pin used in TimeScale ISR */
    CalcTime( fromIsrToTaskT1 );
    #ifdef USETIMER
    expired4Alarms = secondTimerIsrTime;
    #endif
    TerminateTask( );
}

TASK( TASK_t2 ) /* priority = 12 */
{
    SetPort( PIN1 );
    CalcTime( fromIsrToTaskT2 );
    #ifdef USETIMER
    expired1Alarm = secondTimerIsrTime;
    activated1Task = systemTimerIsrTime;
    #endif
    TerminateTask( );
}

TASK( TASK_t3 ) /* priority = 13 */
{
    SetPort( PIN2 );
    CalcTime( fromIsrToTaskT3 );
    #ifdef USETIMER
    expired8Alarms = secondTimerIsrTime;
    #endif
    TerminateTask( );
}

TASK( TASK_t4 )   /* priority = 14 */
{
    SetPort( PIN0 );
    CalcTime( fromTaskT7ToTaskT4 );
#ifdef USETIMER
    activated4Tasks = systemTimerIsrTime;
#endif
    TerminateTask( );
}

TASK( TASK_t5 ) /* priority = 15 */
{
    SetPort( PIN1 );
    TerminateTask( );
}

TASK( TASK_t6 ) /* priority = 16 */
{
    SetPort( PIN2 );
    TerminateTask( );
}

TASK( TASK_t7 ) /* priority = 17 */
{
    SetPort( PIN3 );
    CalcTime( fromIsrToTaskT7 );
    SetStartTime( );    /* TASK_t4 starts after  TASK_t7, TASK_t6 and TASK_t5 */
    TerminateTask( );
}

#define APP_STOP_SEC_CODE
#include "MemMap.h"
