/******************************************************************************
*
*       NXP(TM) and the NXP logo are trademarks of NXP.
*       All other product or service names are the property of their respective owners.
*       (C) Freescale Semiconductor, Inc. 2013-2016
*       Copyright 2021 NXP
*
*       THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
*       BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF NXP.
*
*       Description: Configuration Data file
*
*       Note: The implementation that was used is: AUTOSAR_S32K
*       System Generator for AUTOSAR OS/S32K - Version: 4.0 Build 4.0.98
*
********************************************************************************/
#include    <Os.h>
#include    <Os_internal_config.h>
#define OSTEXT_START_SEC_CODE
#include    "Os_sections.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

const    OSAPP   OsAppCfgTable[OSNAPPS] = 
{
    {
        ErrorHook_SND_APP, /* pointer to error hook */
        0x38000000U, /* all tasks of the application, priority-wise */
        OSINVALID_TASK, /* index in OsTaskTable */
    }, /* SND_APP */
    {
        ErrorHook_RCV_APP, /* pointer to error hook */
        0xc0000000U, /* all tasks of the application, priority-wise */
        0U, /* index in OsTaskTable */
    }, /* RCV_APP */
    {
        ErrorHook_TRUSTED_APP, /* pointer to error hook */
        0x4000000U, /* all tasks of the application, priority-wise */
        OSINVALID_TASK, /* index in OsTaskTable */
    }, /* TRUSTED_APP */
};

/* Task Configuration table */
const    OSTSK   OsTaskCfgTable[OSNTSKS] = 
{
    {
        3U, /* Application identification mask value */
        (OSTASKENTRY) &FuncTASKRCV1, /* entry point of task */
        OSTASKRCV1STKTOS, /* top of task stack */
        OSTASKRCV1STKBOS, /* bottom of task stack */
        0U | OSTSKEXTENDED | OSTSKACTIVATE, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT, OSTSKFLOATINGPOINT */
        0U, /* task id (task number in the task table) */
        1U, /* application identification value */
    }, /* TASKRCV1 */
    {
        3U, /* Application identification mask value */
        (OSTASKENTRY) &FuncTASKRCV2, /* entry point of task */
        0U, /* top of task stack */
        0U, /* bottom of task stack */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT, OSTSKFLOATINGPOINT */
        1U, /* task id (task number in the task table) */
        1U, /* application identification value */
    }, /* TASKRCV2 */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncTASKSND1, /* entry point of task */
        0U, /* top of task stack */
        0U, /* bottom of task stack */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT, OSTSKFLOATINGPOINT */
        2U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* TASKSND1 */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncTASKSND2, /* entry point of task */
        0U, /* top of task stack */
        0U, /* bottom of task stack */
        0U, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT, OSTSKFLOATINGPOINT */
        3U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* TASKSND2 */
    {
        1U, /* Application identification mask value */
        (OSTASKENTRY) &FuncTASKCNT, /* entry point of task */
        0U, /* top of task stack */
        0U, /* bottom of task stack */
        0U | OSTSKNONPREEMPT, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT, OSTSKFLOATINGPOINT */
        4U, /* task id (task number in the task table) */
        0U, /* application identification value */
    }, /* TASKCNT */
    {
        4U, /* Application identification mask value */
        (OSTASKENTRY) &FuncTASKSTOP, /* entry point of task */
        0U, /* top of task stack */
        0U, /* bottom of task stack */
        0U | OSTSKNONPREEMPT, /* properties of task OSTSKACTIVATE, OSTSKEXTENDED, OSTSKNONPREMPT, OSTSKFLOATINGPOINT */
        5U, /* task id (task number in the task table) */
        2U, /* application identification value */
    }, /* TASKSTOP */
};
const    OSISRCFGTYPE   OsIsrCfg[OSNISR + 1] =  /*Interrupts config table*/
{
    {
        OS_isr_ISR1, /* actual ISR function */
        OSTRUSTEDISR2, /* ISR type */
        114U,  
        5U, /* ISR PRIORITY */
        2U, /* application identification value */
    }, /* ISR1 */
    {
        OSISRSystemTimer, /* actual ISR function */
        OSSYSINTERRUPT, /* ISR type */
        115U, /* index in OsIsr */
        2U, /* Interrupt priority */
        OSINVALID_OSAPPLICATION, /* appId */
    }, /* SysTimer */
    {
        OSISRSecondTimer, /* actual ISR function */
        OSSYSINTERRUPT, /* ISR type */
        15U, /* index in OsIsr */
        4U, /* Interrupt priority */
        OSINVALID_OSAPPLICATION, /* appId */
    }, /* SecondTimer */
    {
        OSISRException, /* actual ISR function */
        OSSYSINTERRUPT, /* ISR type */
        OSISREXCEPTIONIDX, /* Index of interrupt */
        OSISREXCEPTIONPRIO, /* Interrupt priority */
        OSINVALID_OSAPPLICATION, /* appId */
    }, /* Exception */
};
const    OSSHORT   OsIsr[OSNINTC] =  /* OSNINTERRUPTS external interrupt handlers table */
{
   /*  0*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 10*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,     2U, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 20*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 30*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 40*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 50*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 60*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 70*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 80*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /* 90*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*100*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*110*/ OSNISR, OSNISR, OSNISR, OSNISR,     0U,     1U, OSNISR, OSNISR, OSNISR, OSNISR,
   /*120*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*130*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*140*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*150*/ OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR, OSNISR,
   /*160*/ OSNISR, OSNISR, OSNISR,
};

const    OSRESCFG   OsResCfg[OSNRESS + OSNISRRESS] = 
{
    { 3U, /* Application identification mask value */0U, /* Resource priority for task resources */ }, /* MSGAACCESS */
    { 3U, /* Application identification mask value */1U, /* Resource priority for task resources */ }, /* MSGBACCESS */
    { 0xFFU, /* Application identification mask value */0U, /* Resource priority for task resources */ }, /* RES_SCHEDULER */
};

/* Alarms table */
const    OSALM   OsAlarmsCfg[OSNUSERALMS] = 
{
    {
        6U, /* appMask */
        5U, /* task to notify */
        0U, /* if event==0 then alarm activates task else it set event for this task */
        2U, /* attached Counter ID */
        2U, /* application identification value */
    }, /* STOPALARM */
    {
        2U, /* appMask */
        0U, /* task to notify */
        TIMLIMITEVENT, /* if event==0 then alarm activates task else it set event for this task */
        1U, /* attached Counter ID */
        1U, /* application identification value */
    }, /* TIMLIMITALARM */
};

/* Counter table */
const    OSCTR   OsCountersCfg[OSNCTRS] = 
{
    {
        1U, /* appMask */
        (TickType) (0xffffU), /* maximum allowed counter value */
        10U, /* conversion constant */
        (TickType) (0x1U), /* minimum period value for alarm */
        0U, /* application identification value */
    }, /* SYSTEMTIMER */
    {
        3U, /* appMask */
        (TickType) (0x7530U), /* maximum allowed counter value */
        10U, /* conversion constant */
        (TickType) (0x1U), /* minimum period value for alarm */
        0U, /* application identification value */
    }, /* SECONDTIMER */
    {
        3U, /* appMask */
        (TickType) (0x14U), /* maximum allowed counter value */
        1U, /* conversion constant */
        (TickType) (0x1U), /* minimum period value for alarm */
        0U, /* application identification value */
    }, /* STCOUNTER */
};
static const    OSSCTEP   OSSCHEDTAB_actions[] = 
{
    {
        (OSSCTEPREF) &OSSCHEDTAB_actions[1U], /* the next expiry point */
        { 2U, /* Task to start or to set Event */0U, /* if event==0 alarm activates task else it sets event for this task */ }, /* action */
        15000U, /* Delay to the next expiry point */
        30000U, /* expiry point offset */
    }, /* TASKSND1 TASKACTIVATION */
    {
        (OSSCTEPREF) &OSSCHEDTAB_actions[2U], /* the next expiry point */
        { 3U, /* Task to start or to set Event */0U, /* if event==0 alarm activates task else it sets event for this task */ }, /* action */
        7500U, /* Delay to the next expiry point */
        15000U, /* expiry point offset */
    }, /* TASKSND2 TASKACTIVATION */
    {
        (OSSCTEPREF) &OSSCHEDTAB_actions[0U], /* the next expiry point */
        { 4U, /* Task to start or to set Event */0U, /* if event==0 alarm activates task else it sets event for this task */ }, /* action */
        7500U, /* Delay to the next expiry point */
        22500U, /* expiry point offset */
    }, /* TASKCNT TASKACTIVATION */
};
const    OSSCT   OsScheduleTablesCfg[OSNSCTS] = 
{
    {
        0U, /* attached Counter ID */
        0U, /* Initial Offset of the Schedule Table */
        (OSSCTEPREF) &OSSCHEDTAB_actions[0U], /* the pointer to first expiry point in the Schedule Table */
        7U, /* Application identification mask value */
        0U, /* application identification value */
        OSSCTCFGPERIODIC, /* config byte of the Schedule Table */
    }, /* OSSCHEDTAB */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include    "Os_sections.h"

MSGATYPE OsIocBuffer_MsgA;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include    "Os_sections.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include    "Os_sections.h"

MSGBTYPE OsIocBuffer_MsgB;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include    "Os_sections.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"


/* IOC 'LastIsBest' */
const    OSIOCBUFFERINFO   OsIocBufferInfo[OSNIOCBUFFERS] =  /*'LastIsBest' buffers info structure array*/
{
    {
        (OSBYTEPTR) &OsIocBuffer_MsgA, /* dataBuf */
        sizeof(MSGATYPE), /* dataSize */
        1U, /* sndAppMask */
        1U, /* rcvAppId */
        0U, /* TASKRCV1 */
        MSGAEVENT, /* event */
    }, /* MsgA */
    {
        (OSBYTEPTR) &OsIocBuffer_MsgB, /* dataBuf */
        sizeof(MSGBTYPE), /* dataSize */
        1U, /* sndAppMask */
        1U, /* rcvAppId */
        1U, /* TASKRCV2 */
        0U, /* event */
    }, /* MsgB */
};
void OSIOC_Init(void ) /* IOC initial */
{
}
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#define OSTEXT_STOP_SEC_CODE
#include    "Os_sections.h"

