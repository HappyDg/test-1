/******************************************************************************
*
*       NXP(TM) and the NXP logo are trademarks of NXP.
*       All other product or service names are the property of their respective owners.
*       (C) Freescale Semiconductor, Inc. 2013-2016
*       Copyright 2020 NXP
*
*       THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
*       BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF NXP.
*
*       Description: Configuration Header file
*
*       Note: The implementation that was used is: AUTOSAR_S32K
*       System Generator for AUTOSAR OS/S32K - Version: 4.0 Build 4.0.98
*
********************************************************************************/
#ifndef OSCFG_H
#define OSCFG_H
#define APP_START_SEC_CODE
#include    "Os_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"


/* Applications */
#define SND_APP ((ApplicationType)OS_MKOBJID(OBJECT_APPLICATION, 0U)) /* Application ID */
void ErrorHook_SND_APP(StatusType error);
#define RCV_APP ((ApplicationType)OS_MKOBJID(OBJECT_APPLICATION, 1U)) /* Application ID */
void ErrorHook_RCV_APP(StatusType error);
#define TRUSTED_APP ((ApplicationType)OS_MKOBJID(OBJECT_APPLICATION, 2U)) /* Application ID */
void ErrorHook_TRUSTED_APP(StatusType error);

/* Spinlock */

/* Application modes */
#define Mode01 ((AppModeType)0U)           /* AppMode ID */

/* Common stack */
#define OSTASKRCV1STKSIZE 416U             /* stack size of TASKRCV1 */
#define OSTASKRCV1STKBOS OSRUNNABLESTKBEG  /* TASKRCV1 bos */
#define OSTASKRCV1STKTOS (OSTASKRCV1STKBOS + OSTASKRCV1STKSIZE/4U) /* TASKRCV1 tos */

/* Task definitions */
#define TASKRCV1 ((TaskType)OS_MKOBJID(OBJECT_TASK, 0U)) /* Task ID */
extern void FuncTASKRCV1(void); /* Task entry point */
#define TASKRCV2 ((TaskType)OS_MKOBJID(OBJECT_TASK, 1U)) /* Task ID */
extern void FuncTASKRCV2(void); /* Task entry point */
#define TASKSND1 ((TaskType)OS_MKOBJID(OBJECT_TASK, 2U)) /* Task ID */
extern void FuncTASKSND1(void); /* Task entry point */
#define TASKSND2 ((TaskType)OS_MKOBJID(OBJECT_TASK, 3U)) /* Task ID */
extern void FuncTASKSND2(void); /* Task entry point */
#define TASKCNT ((TaskType)OS_MKOBJID(OBJECT_TASK, 4U)) /* Task ID */
extern void FuncTASKCNT(void); /* Task entry point */
#define TASKSTOP ((TaskType)OS_MKOBJID(OBJECT_TASK, 5U)) /* Task ID */
extern void FuncTASKSTOP(void); /* Task entry point */

/* ISR functions */

/* ISRs definition */
#define OSISRISR1() OSISR2DISP(ISR1)       /* IrqChannel is EXTERNAL */
extern void OS_isr_ISR1(void); /* irq: ISR1; channel: EXTERNAL; category: 2 */
#define ISR1LEVEL 5U                       /* interrupt level of ISR1 */
#define ISR1PRIORITY 5U                    /* priority of ISR1 */
#define ISR1 ((ISRType)OS_MKOBJID(OBJECT_ISR, 0U)) /* ISR ID */

/* ISR1 id */

/* Resources definitions */
#define MSGAACCESS ((ResourceType)OS_MKOBJID(OBJECT_RESOURCE, 0U)) /* Resource ID */
#define MSGBACCESS ((ResourceType)OS_MKOBJID(OBJECT_RESOURCE, 1U)) /* Resource ID */
#define RES_SCHEDULER ((ResourceType)OS_MKOBJID(OBJECT_RESOURCE, 2U)) /* Resource ID */

/* Events definition */
#define MSGAEVENT ((EventMaskType)1U)      /* Event mask */
#define TIMLIMITEVENT ((EventMaskType)2U)  /* Event mask */

/* Alarms identification */
#define STOPALARM ((AlarmType)OS_MKOBJID(OBJECT_ALARM, 0U)) /* Alarm ID */
#define TIMLIMITALARM ((AlarmType)OS_MKOBJID(OBJECT_ALARM, 1U)) /* Alarm ID */

/* Counters identification */
#define SYSTEMTIMER ((CounterType)OS_MKOBJID(OBJECT_COUNTER, 0U)) /* Counter ID */
#define OSMINCYCLE_SYSTEMTIMER ((TickType)0x1U) /* SYSTEMTIMER */
#define OSMAXALLOWEDVALUE_SYSTEMTIMER ((TickType)0xffffU) /* SYSTEMTIMER */
#define OSTICKSPERBASE_SYSTEMTIMER 10UL    /* SYSTEMTIMER */
#define OS_TICKS2NS_SYSTEMTIMER(ticks) (PhysicalTimeType)(ticks*333U) /*  */
#define OS_TICKS2US_SYSTEMTIMER(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*333ULL/1000UL) /*  */
#define OS_TICKS2MS_SYSTEMTIMER(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*333ULL/1000000UL) /*  */
#define OS_TICKS2SEC_SYSTEMTIMER(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*333ULL/1000000000UL) /*  */
#define SECONDTIMER ((CounterType)OS_MKOBJID(OBJECT_COUNTER, 1U)) /* Counter ID */
#define OSMINCYCLE_SECONDTIMER ((TickType)0x1U) /* SECONDTIMER */
#define OSMAXALLOWEDVALUE_SECONDTIMER ((TickType)0x7530U) /* SECONDTIMER */
#define OSTICKSPERBASE_SECONDTIMER 10UL    /* SECONDTIMER */
#define OS_TICKS2NS_SECONDTIMER(ticks) (PhysicalTimeType)(ticks*2500000U) /*  */
#define OS_TICKS2US_SECONDTIMER(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*2500000ULL/1000UL) /*  */
#define OS_TICKS2MS_SECONDTIMER(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*2500000ULL/1000000UL) /*  */
#define OS_TICKS2SEC_SECONDTIMER(ticks) (PhysicalTimeType)((OSQWORD)(ticks)*2500000ULL/1000000000UL) /*  */
#define STCOUNTER ((CounterType)OS_MKOBJID(OBJECT_COUNTER, 2U)) /* Counter ID */
#define OSMINCYCLE_STCOUNTER ((TickType)0x1U) /* STCOUNTER */
#define OSMAXALLOWEDVALUE_STCOUNTER ((TickType)0x14U) /* STCOUNTER */
#define OSTICKSPERBASE_STCOUNTER 1UL       /* STCOUNTER */
#define OSMINCYCLE ((TickType)0x1U)        /* SysTimer */
#define OSMAXALLOWEDVALUE ((TickType)0xffffU) /* SysTimer */
#define OSTICKSPERBASE 10UL                /* SysTimer */
#define OSTICKDURATION 333UL               /* SysTimer */
#define OSMINCYCLE2 ((TickType)0x1U)       /* SecondTimer */
#define OSMAXALLOWEDVALUE2 ((TickType)0x7530U) /* SecondTimer */
#define OSTICKSPERBASE2 10UL               /* SecondTimer */
#define OSTICKDURATION2 2500000UL          /* SecondTimer */

/* Messages identification */

/* Flags identification */

/* Message callback prototypes */

/* scheduletable */
#define SCHEDTAB ((ScheduleTableType)OS_MKOBJID(OBJECT_SCHEDULETABLE, 0U)) /* ScheduleTable ID */

/* IOC */
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include    "Os_sections.h"

#define APP_STOP_SEC_CODE
#include    "Os_memmap.h"

#endif /* OSCFG_H */

