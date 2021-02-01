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
*   Description:  "Body" benchmark for BCC1
*
**************************************************************************************/

/*  Include-files   */

#include <Os_prop_autosar.h>             /* This API shall NOT be used in the AUTOSAR applications */ 
#include <Os.h>
#include <Os_internal_config.h>          /* This API shall NOT be used in the AUTOSAR applications */
#include <Os_internal_api.h>             /* This API shall NOT be used in the AUTOSAR applications */
/******************** variables for calculating overhead *********************/

#define TrustedApplication_START_SEC_VAR_FAST_UNSPECIFIED
#include "MemMap.h"

OSDWORD APPNEAR volatile sysCnt;    /* counter for "useful" work */
OSDWORD APPNEAR volatile nosys;     /* counter for "useful" work w/o system overhead */
OSWORD  APPNEAR volatile procent;   /* result goes here */
#define TrustedApplication_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "MemMap.h"

#define TrustedApplication_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#if defined(__CLASS_SC1)
#define ARLEN 1
#else
#define ARLEN 2
#endif

unsigned int  stackUsage[ARLEN];   /* measured stack usage */
#if defined(__CLASS_SC1)
volatile unsigned char *tmpSP;     /* temporary Stack Pointer  */
#endif

unsigned char *tmpPtr;             /* temporary Pointer  */
int iterator;

#define TrustedApplication_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define APP_START_SEC_CODE
#include "MemMap.h"

extern void SetBenchmarkPLL( void );

/***************************************************************************
 * Function:   GetUsedBytes
 *
 * Description: Calculates number of used bytes
 *
 * inp:  stack bottom pointer, size in bytes
 *
 * Returns: number of bytes
 *
 **************************************************************************/

OSDWORD GetUsedBytes( OSBYTE* start, OSDWORD num )
{
    OSBYTE c;
    
    for( ; num > 0; num-- )
    {
        c = *start;
        if ( c != (OSBYTE)STACKPATTERN )
            break;
        start++;
    }
    return num;
}

/***************************************************************************
 * Function:   IniStack
 *
 * Description: fills stack area with pattern
 *
 * inp:  stack bottom pointer, size in bytes
 *
 **************************************************************************/
#define IniStack(start, len)  { tmpPtr = (unsigned char*)(start); \
              for( iterator=0; iterator<len; iterator++ ) { tmpPtr[iterator] = (OSBYTE)STACKPATTERN; } }





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
#if defined(OSGCCARM) || defined(OSIARARM)
OSINLINE OSDWORD OSGetStackPointer (void)
{
    register OSDWORD result_reg;

    OSASM ( " mov %0, r13" : "=r" (result_reg) ); /* mr r3, r1 */

    return result_reg;
}
#endif 

#ifdef OSGHSARM
OSASM OSDWORD OSGetStackPointer (void)
{
    mov r0, r13
}
#endif

#ifdef OSDS5ARM
/* Get the SP register value */
#pragma diag_suppress 667
OSINLINE OSASM OSDWORD OSGetStackPointer (void)
{
   mov r0, r13
   bx lr
}
#pragma diag_default 667
#endif /* OSDS5ARM */







/***************************************************************************
 * Function :   main
 *
 * Description: performs HW initialization and starts OS
 *
 * Notes:       this function never returns
 **************************************************************************/

void main( void )
{

        FLASH2WS( );
        EnableBTB( );
#ifdef OSIARARM
        extern void SystemInit(void);
        SystemInit();
#endif /* OSIARARM */
        SetBenchmarkPLL( );
        EnableCache();
        IniPort();

        #if !defined(__CLASS_SC1)

        IniStack( SP_BOTTOM, SP_TOP - SP_BOTTOM );

        #if defined(__CLASS_SC2)
        IniStack( (OSBYTE*)OsISRStack, OSISRSTACKSIZE*4 );
        #else
        IniStack( (OSBYTE*)(OS_SysTimer_STKBOS), OSIPL2STKSIZE );
        #endif

        #else
        tmpSP  = (unsigned char*)OSGetStackPointer();
        IniStack( SP_BOTTOM, tmpSP - SP_BOTTOM - 16 );
        #endif        

        StartOS( 0 );
}



#if defined(OSDS5ARM) || defined(OSGCCARM)
extern void EndMeasurement(void) __attribute__((noinline));
#else
extern void EndMeasurement(void);
#endif

extern OSDWORD Count(void);


/* Application Tasks: */

/***************************************************************************
 * Function :   TASKBGND
 *
 * Description: performs initializations, measures timings.
 *
 * Notes:       this task has the lowest priority
 **************************************************************************/

TASK( TASKBGND )
{
    volatile OSDWORD tvalue, temp;            /* temp - for current timer value */

    DisableCMP( 0 );  /* DisableTimerInt();    disable SystemCounter and alarms */
                                              /* thus removing system overhead */
    SetAbsAlarm( ALARM1,   20*CUR1MS, 200*CUR1MS );       /* start ALARM1  after  20 ms with cycle 200 ms*/
    SetAbsAlarm( ALARM2,   40*CUR1MS, 200*CUR1MS );       /* start ALARM2  after  40 ms with cycle 200 ms*/
    SetAbsAlarm( ALARM3,   60*CUR1MS, 200*CUR1MS );       /* start ALARM3  after  60 ms with cycle 200 ms*/
    SetAbsAlarm( ALARM4,   80*CUR1MS, 200*CUR1MS );       /* start ALARM4  after  80 ms with cycle 200 ms*/
    SetAbsAlarm( ALARM5,  100*CUR1MS, 200*CUR1MS );       /* start ALARM5  after 100 ms with cycle 200 ms*/
    SetAbsAlarm( ALARM6,  120*CUR1MS, 200*CUR1MS );       /* start ALARM6  after 120 ms with cycle 200 ms*/
    SetAbsAlarm( ALARM7,  140*CUR1MS, 200*CUR1MS );       /* start ALARM7  after 140 ms with cycle 200 ms*/
    SetAbsAlarm( ALARM8,  160*CUR1MS, 200*CUR1MS );       /* start ALARM8  after 160 ms with cycle 200 ms*/
    SetAbsAlarm( ALARM9,  180*CUR1MS, 200*CUR1MS );       /* start ALARM9  after 180 ms with cycle 200 ms*/
    SetAbsAlarm( ALARM10, 200*CUR1MS, 200*CUR1MS );       /* start ALARM10 after 200 ms with cycle 200 ms*/
    sysCnt = 0L;
    nosys  = 0L;

    InitTime();

    ClearTime();
    StartTime();
    SetPort( PIN0 ); 
    tvalue = GetTime();
    ClrPort();
    do{                                     /* synchronize */
        temp = GetTime();
    }while( absdiff(tvalue, temp) < 2*CUR100MS );
    SetPort( PIN0 ); 
    nosys = Count();
   
    EnableCMP( 0 );  /* EnableTimerInt(); thus enabling alarms */

    sysCnt = Count();
    DisableCMP( 0 ); /* DisableTimerInt(); disable SystemCounter and alarms */
    
    procent = (OSWORD)((nosys - sysCnt) * 1000 / (nosys / 10));
                        /* at this point "percent" helds system overhead in (% * 100) */
    stackUsage[0] = GetUsedBytes( (OSBYTE*)SP_BOTTOM, SP_TOP - SP_BOTTOM );

    #if !defined(__CLASS_SC1)
    #if defined(__CLASS_SC2)
    stackUsage[1] = GetUsedBytes( (OSBYTE*)OsISRStack, OSISRSTACKSIZE*4 );
    #else
    stackUsage[1] = GetUsedBytes( (OSBYTE*)(OS_SysTimer_STKBOS), OSIPL2STKSIZE );
    #endif
    #endif

    EndMeasurement();       
}


void EndMeasurement(void)
{
    OSDHI();
    for( ; ; )
    {
    }
}


OSDWORD Count( void )
{
    volatile OSDWORD tvalue, temp, counter=0L;

    tvalue = GetTime();
    SetPort( PIN4 ); 
    do{                                     /* measure during 10ticks */
        counter++;                          /* make some work and calculate it */
        temp = GetTime();
    }while( absdiff(tvalue, temp) < 10*CUR100MS );
    ClrPort();
    return counter;
}


/***************************************************************************
 * Functions:   TASK[1...10]
 *
 * Description: this tasks do nothing, used for measuring system overhead
 *
 **************************************************************************/

TASK( TASK1 )
{
    TerminateTask();
}

TASK( TASK2 )
{
    TerminateTask();
}

TASK( TASK3 )
{
    TerminateTask();
}

TASK( TASK4 )
{
    TerminateTask();
}

TASK( TASK5 )
{
    TerminateTask();
}

TASK( TASK6 )
{
    TerminateTask();
}

TASK( TASK7 )
{
    TerminateTask();
}

TASK( TASK8 )
{
    TerminateTask();
}

TASK( TASK9 )
{
    TerminateTask();
}

TASK( TASK10 )
{
    TerminateTask();
}
#define APP_STOP_SEC_CODE
#include "MemMap.h"
