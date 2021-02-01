/**************************************************************************************
*
*   NXP(TM) and the NXP logo are trademarks of NXP
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
*  Description:  AUTOSAR OS sample application
*
**************************************************************************************/

#include    <Os.h>                              /* OS API */

#include    <Ioc.h>

/* Global 'send' application data */
#define SND_APP_START_SEC_VAR_FAST_16
#include "MemMap.h"
#if defined(OSTSKFPU)
APP_NEAR_16 volatile unsigned short ind, taskCnt, repeatCnt1;
#else
APP_NEAR_16 volatile unsigned short ind, taskSnd1, taskSnd2, taskCnt, repeatCnt1;
#endif
#define SND_APP_STOP_SEC_VAR_FAST_16
#include "MemMap.h"

#if defined(OSTSKFPU)
#define SND_APP_START_SEC_VAR_FAST_32
#include "MemMap.h"
APP_NEAR_32 volatile float taskSnd1, taskSnd2;
#define SND_APP_STOP_SEC_VAR_FAST_32
#include "MemMap.h"
#endif

#define TRUSTED_APP_START_SEC_VAR_FAST_16
#include "MemMap.h"
/* User's hooks: */
APP_NEAR_16 int volatile hookNmb;               /* to prevent hooks from linker optimization */
#define TRUSTED_APP_STOP_SEC_VAR_FAST_16
#include "MemMap.h"

#define SND_APP_START_SEC_VAR_FAST_32
#include "MemMap.h"
APP_NEAR_32 static int msgAnum;
#define SND_APP_STOP_SEC_VAR_FAST_32
#include "MemMap.h"

#define SND_APP_START_SEC_VAR_FAST_UNSPECIFIED
#include "MemMap.h"
APP_NEAR_U static MSGBTYPE Msg_B;               /* declare message MsgB */
#define SND_APP_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "MemMap.h"

#define OSHOOK_START_SEC_CODE
#include "MemMap.h"

void    ErrorHook( StatusType Error )           /* Error handling routine */
{
    hookNmb = Error;                            /* to avoid compiler warning */
    hookNmb = 1;
}

void    PreTaskHook( void )                     /* Routine to call before entering task context */
{
    hookNmb = 2;
}

void    PostTaskHook( void )                    /* Routine to call after saving task context */
{
    hookNmb = 3;
}


void ErrorHook_SND_APP(StatusType error)        /* SND application error hook */
{
    hookNmb = 4;
    while(1);
}

void ErrorHook_RCV_APP(StatusType error)        /* RCV application error hook */
{
    hookNmb = 5;
    while(1);
}

void ErrorHook_TRUSTED_APP(StatusType error)    /* TRUSTED application error hook */
{
    hookNmb = 6;
    while(1);
}



#define OSHOOK_STOP_SEC_CODE
#include "MemMap.h"

#define APP_START_SEC_CODE
#include "MemMap.h"

/* User's functions: */

/***************************************************************************
 * Function:    TASKSND1
 *
 * Description: Task sender - is activated by Time Scale
 *
 * PROPERTIES:  priority = 3, Basic, preemptive
 *
 **************************************************************************/

TASK( TASKSND1 )
{
    volatile StatusType status;                 /* variable to check system status */
    MSGATYPE Msg_A;                             /* message date */

    taskSnd1++;

    /* GetResource to access to message */
    status = GetResource( MSGAACCESS );         /* get resource */
    Msg_A.value=msgAnum++;                      /* modify MsgA  */

    status = IocWrite_MsgA(&Msg_A );
                                                /* Release Resource to access to message */
    status = ReleaseResource( MSGAACCESS );     /* release resource and terminate */
    status = TerminateTask( );
}

/***************************************************************************
 * Function:    TASKSND2
 *
 * Description: Task sender - is activated by Time Scale
 *
 * PROPERTIES:   priority = 2, Basic, preemptive
 *
 **************************************************************************/

TASK( TASKSND2 )
{
    volatile StatusType status;                 /* variable to check system status */

    taskSnd2++;

    ind += 30;
    if( ind >= 50 )
    {
        ind -= 51;
        Msg_B.msg = ind+1000;                   /* just to have some data */

        status = GetCounterValue( SYSTEMTIMER, &Msg_B.ts );
        status = GetResource( MSGBACCESS );     /* get resource */
                                                /* Send state message */
        status = IocWrite_MsgB(&Msg_B );
                                                /* Release Resource to access to message */
        status = ReleaseResource( MSGBACCESS ); /* release resource and terminate */

    }
    status = TerminateTask( );
}

/***************************************************************************
 * Function:    TASKCNT
 *
 * Description: Task - increment TSCOUNTER value
 *
 * PROPERTIES:  priority = 1, Basic, nonpreemptive
 *
 **************************************************************************/

TASK( TASKCNT )
{
    volatile StatusType status;                 /* variable to check system status */

    taskCnt++;

    status = IncrementCounter( STCOUNTER );
    if( ++repeatCnt1 >= (REPEAT_CNT_MAX_VAL * 20) )
    {
        repeatCnt1 = 0;
        ClrGPIO(LED3);
        }
    status = TerminateTask( );
}

#define APP_STOP_SEC_CODE
#include "MemMap.h"
