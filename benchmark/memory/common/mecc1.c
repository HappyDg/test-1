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
*   Description:  "Body" benchmark for ECC1
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

int  stackUsage[12];            /* measured stack usage */
volatile unsigned char *tmpSP;  /* temporary Stack Pointer  */
unsigned char *tmpPtr;          /* temporary Pointer  */
int iterator;


#define TrustedApplication_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#define APP_START_SEC_CODE
#include "MemMap.h"
extern void SetBenchmarkPLL( void );


#define GetTOS(tskNum) ((OSBYTE*)(OsTaskCfgTable[OSNTSKS - tskNum - 1].tos))
#define GetBOS(tskNum,tskStkSize) (GetTOS(tskNum) - tskStkSize)
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
#define IniStack(start, len)  for( iterator=0; iterator<len; iterator++ ) { (start)[iterator] = (OSBYTE)STACKPATTERN; }



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
        #else
        tmpSP = (unsigned char*)OSGetStackPointer();
        tmpPtr = (unsigned char*)SP_BOTTOM;
        IniStack( tmpPtr, tmpSP - tmpPtr - 16 );
        #endif
        IniStack( GetBOS(1,  OSTASK1STKSIZE),  OSTASK1STKSIZE    );
        IniStack( GetBOS(2,  OSTASK2STKSIZE),  OSTASK2STKSIZE    );
        IniStack( GetBOS(3,  OSTASK3STKSIZE),  OSTASK3STKSIZE    );
        IniStack( GetBOS(4,  OSTASK4STKSIZE),  OSTASK4STKSIZE    );
        IniStack( GetBOS(5,  OSTASK5STKSIZE),  OSTASK5STKSIZE    );
        IniStack( GetBOS(6,  OSTASK6STKSIZE),  OSTASK6STKSIZE    );
        IniStack( GetBOS(7,  OSTASK7STKSIZE),  OSTASK7STKSIZE    );
        IniStack( GetBOS(8,  OSTASK8STKSIZE),  OSTASK8STKSIZE    );
        IniStack( GetBOS(9,  OSTASK9STKSIZE),  OSTASK9STKSIZE    );
        IniStack( GetBOS(10, OSTASK10STKSIZE), OSTASK10STKSIZE   );    
        #if defined(__CLASS_SC1) || defined(__CLASS_SC2)
        IniStack( (OSBYTE*)OsISRStack,  OSISRSTACKSIZE*4 );
        #else
        IniStack( (OSBYTE*)(OS_SysTimer_STKBOS), OSIPL2STKSIZE );
        #endif
        StartOS( 0 );
}

/************************ User's functions: **********************************/

#if defined(OSDS5ARM) || defined(OSGCCARM)
extern void EndMeasurement(void) __attribute__((noinline));
#else
extern void EndMeasurement(void);
#endif


extern OSDWORD Count(void);

/*****************************************************************************
 * Function :   TASKBGND
 *
 * Description: performs initializations, measures timings.
 *
 * Notes:       this task has the lowest priority
 *****************************************************************************/

TASK( TASKBGND )
{
    volatile OSDWORD tvalue, temp;             /* temp - for timer value   */

    DisableCMP( 0 ); /* DisableTimerInt( );    disable SystemCounter and alarms */
                                            /* thus removing system overhead    */
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

    tvalue = GetTime();
    ClrPort();
    do{
        temp = GetTime();
    }while( absdiff(tvalue, temp) < 2*CUR100MS );

    nosys = Count();    /* make some work and calculate it */

    EnableCMP( 0 );     /* EnableTimerInt(); thus enabling alarms */

    sysCnt = Count();   /* make some work and calculate it */

    DisableCMP( 0 );    /* DisableTimerInt(); disable SystemCounter and alarms */

    procent = (OSWORD)((nosys - sysCnt) * 1000 / (nosys / 10));
                        /* at this point "percent" helds system overhead in (% * 100) */
    stackUsage[0]  = GetUsedBytes( (OSBYTE*)SP_BOTTOM, SP_TOP - SP_BOTTOM );
    stackUsage[1]  = GetUsedBytes( GetBOS(1, OSTASK1STKSIZE ),    OSTASK1STKSIZE );
    stackUsage[2]  = GetUsedBytes( GetBOS(2, OSTASK2STKSIZE ),    OSTASK2STKSIZE );
    stackUsage[3]  = GetUsedBytes( GetBOS(3, OSTASK3STKSIZE ),    OSTASK3STKSIZE );
    stackUsage[4]  = GetUsedBytes( GetBOS(4, OSTASK4STKSIZE ),    OSTASK4STKSIZE );
    stackUsage[5]  = GetUsedBytes( GetBOS(5, OSTASK5STKSIZE ),    OSTASK5STKSIZE );
    stackUsage[6]  = GetUsedBytes( GetBOS(6, OSTASK6STKSIZE ),    OSTASK6STKSIZE );
    stackUsage[7]  = GetUsedBytes( GetBOS(7, OSTASK7STKSIZE ),    OSTASK7STKSIZE );
    stackUsage[8]  = GetUsedBytes( GetBOS(8, OSTASK8STKSIZE ),    OSTASK8STKSIZE );
    stackUsage[9]  = GetUsedBytes( GetBOS(9, OSTASK9STKSIZE ),    OSTASK9STKSIZE );
    stackUsage[10] = GetUsedBytes( GetBOS(10,OSTASK10STKSIZE ),   OSTASK10STKSIZE );
    #if defined(__CLASS_SC1) || defined(__CLASS_SC2)
    stackUsage[11] = GetUsedBytes( (OSBYTE*)(OsISRStack),  OSISRSTACKSIZE*4 );
    #else
    stackUsage[11] = GetUsedBytes( (OSBYTE*)(OS_SysTimer_STKBOS), OSIPL2STKSIZE );
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
    do{                                     /* measure during 10 ticks */
        counter++;                          /* make some work and calculate it  */
        temp = GetTime();
    }while( absdiff(tvalue, temp) < 10*CUR100MS );
    ClrPort();
    return counter;
}


/*****************************************************************************
 * Functions:   TASK[1...10]
 *
 * Description: this tasks do nothing, used for measuring system overhead
 *
 *****************************************************************************/

TASK( TASK1 )
{
    for( ; ; )
    {
        WaitEvent( EVENT1 );
        ClearEvent( EVENT1 );
    }
}

TASK( TASK2 )
{
    for( ; ; )
    {
        WaitEvent( EVENT2 );
        ClearEvent( EVENT2 );
    }
}

TASK( TASK3 )
{
    for( ; ; )
    {
        WaitEvent( EVENT3 );
        ClearEvent( EVENT3 );
    }
}

TASK( TASK4 )
{
    for( ; ; )
    {
        WaitEvent( EVENT4 );
        ClearEvent( EVENT4 );
    }
}

TASK( TASK5 )
{
    for( ; ; )
    {
        WaitEvent( EVENT5 );
        ClearEvent( EVENT5 );
    }
}

TASK( TASK6 )
{
    for( ; ; )
    {
        WaitEvent( EVENT6 );
        ClearEvent( EVENT6 );
    }
}

TASK( TASK7 )
{
    for( ; ; )
    {
        WaitEvent( EVENT7 );
        ClearEvent( EVENT7 );
    }
}

TASK( TASK8 )
{
    for( ; ; )
    {
        WaitEvent( EVENT8 );
        ClearEvent( EVENT8 );
    }
}

TASK( TASK9 )
{
    for( ; ; )
    {
        WaitEvent( EVENT9 );
        ClearEvent( EVENT9 );
    }
}

TASK( TASK10 )
{
    for( ; ; )
    {
        WaitEvent( EVENT10 );
        ClearEvent( EVENT10 );
    }
}
#define APP_STOP_SEC_CODE
#include "MemMap.h"
