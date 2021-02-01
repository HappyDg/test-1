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

#include <Os.h>                              /* OS API */

#include <Ioc.h>

/* Global 'receive' application data */
#define RCV_APP_START_SEC_VAR_FAST_16
#include "MemMap.h"
#if defined(OSTSKFPU)
APP_NEAR_16 volatile unsigned short repeatCnt;
#else
APP_NEAR_16 volatile unsigned short taskRcv1, taskRcv2, repeatCnt;
#endif
#define RCV_APP_STOP_SEC_VAR_FAST_16
#include "MemMap.h"

#if defined(OSTSKFPU)
#define RCV_APP_START_SEC_VAR_FAST_32
#include "MemMap.h"
APP_NEAR_32 volatile float taskRcv1, taskRcv2;
#define RCV_APP_STOP_SEC_VAR_FAST_32
#include "MemMap.h"
#endif

/* Global 'trusted' application data */
#define TRUSTED_APP_START_SEC_VAR_FAST_16
#include "MemMap.h"
APP_NEAR_16 volatile unsigned short taskStop;
#define TRUSTED_APP_STOP_SEC_VAR_FAST_16
#include "MemMap.h"

#define APP_START_SEC_CODE
#include "MemMap.h"

/***************************************************************************
 * Function:    main
 *
 * Description: inits variables and starts OS
 *
 **************************************************************************/
void main( void )
{
#if defined(OSIARARM)
    extern void SystemInit(void);
    SystemInit();
#endif

    ind = 0;
    repeatCnt = 0;
    repeatCnt1 = 0;
#if defined(OSTSKFPU)
    taskRcv1 = 0.5;
    taskRcv2 = 0.5;
#else
    taskRcv1 = 0;
    taskRcv2 = 0;
#endif
    taskStop = 0;
#if defined(OSTSKFPU)
    taskSnd1 = 0.5;
    taskSnd2 = 0.5;
#else
    taskSnd1 = 0;
    taskSnd2 = 0;
#endif
    taskCnt  = 0;


    StartOS( Mode01 );                            /* jump to OS startup */

}


/* Application Tasks: */

/***************************************************************************
 * Function:    TASKRCV1
 *
 * Description: Task receiver - is activated by start-up and delays itself
 *
 * PROPERTIES:  priority = 5, Extended, preemptive, activated at start-up
 *
 **************************************************************************/

TASK( TASKRCV1 )
{
    volatile StatusType status;                 /* variable to check system status */
    EventMaskType event;                        /* variable for event masks */
    MSGATYPE Msg_A;                             /* object to receive message MsgA */

    InitGPIO(LED3);
    Msg_A.value = 0;

    for( ; ; )                                  /* main endless loop */
    {
        DisableAllInterrupts();  /* to allow to use a breakpoint on next line */
        hookNmb = 0;
        EnableAllInterrupts();

        status = SetRelAlarm( STOPALARM, 20, 0 );
        StartScheduleTableRel(SCHEDTAB, 1);

        for( ; ; )
        {
            taskRcv1++;
            status = ClearEvent( MSGAEVENT | TIMLIMITEVENT );
            status = SetRelAlarm( TIMLIMITALARM, 125, 0 );

            status = WaitEvent( MSGAEVENT | TIMLIMITEVENT );

            status = GetEvent( TASKRCV1, &event );

            if ( event == MSGAEVENT )
            {
                CancelAlarm( TIMLIMITALARM );
                status = GetResource( MSGAACCESS );
                status = IocRead_MsgA ( &Msg_A );    /* get message data */
                status = ReleaseResource( MSGAACCESS );
            }
            else
            {
                if( ++repeatCnt >= (REPEAT_CNT_MAX_VAL * 2) )
                {
                    repeatCnt = 0;
                    SetGPIO(LED3);
                }
                break;
            }
        }

    }

}


/***************************************************************************
 * Function:    TASKRCV2
 *
 * Description: Task receiver - is activated by message B
 *
 * PROPERTIES:   priority = 4, basic, preemptive
 *
 **************************************************************************/

TASK( TASKRCV2 )
{
    volatile StatusType status;
    MSGBTYPE Msg_B;

    taskRcv2++;
                                                /* GetResource to have exclusive access to the message */
    status = GetResource( MSGBACCESS );
                                                /* receive message */
    status = IocRead_MsgB ( &Msg_B );

    status = ReleaseResource( MSGBACCESS );
    status = TerminateTask( );
}

/***************************************************************************
 * Function:    TASKSTOP
 *
 * Description: Task  - terminate Time Scale processing
 *
 * PROPERTIES:   priority = 0, basic, preemptive
 *
 **************************************************************************/

TASK( TASKSTOP )
{
    volatile StatusType status;
    DisableAllInterrupts();
    taskStop++;
    EnableAllInterrupts();
    status = StopScheduleTable(SCHEDTAB);
    status = TerminateTask();
}


/***************************************************************************
 * Function:    ISR1
 *
 * Description: User's ISR
 *
 * PROPERTIES:
 *
 **************************************************************************/
ISR( ISR1 )
{
}

#define APP_STOP_SEC_CODE
#include "MemMap.h"

