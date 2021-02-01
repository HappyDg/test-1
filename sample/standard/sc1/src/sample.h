#ifndef SAMPLE_H
#define SAMPLE_H
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

#ifdef __cplusplus
extern "C"
{
#endif

#include "sample_hw.h"

#define LED3    2




#if defined(OSGHSARM)
#define APP_NEAR_16
#define APP_NEAR_32
#define APP_NEAR_U
#endif

#if defined(OSGCCARM)
#define APP_NEAR_16
#define APP_NEAR_32
#define APP_NEAR_U
#endif

#if defined(OSDS5ARM)
#define APP_NEAR_16
#define APP_NEAR_32
#define APP_NEAR_U
#endif

#if defined(OSIARARM)
#define APP_NEAR_16
#define APP_NEAR_32
#define APP_NEAR_U
#endif

/* Global 'receive' application data */
#define RCV_APP_START_SEC_VAR_FAST_16
#include "MemMap.h"
#if defined(OSTSKFPU)
extern APP_NEAR_16 volatile unsigned short repeatCnt;
#else
extern APP_NEAR_16 volatile unsigned short taskRcv1, taskRcv2, repeatCnt;
#endif
#define RCV_APP_STOP_SEC_VAR_FAST_16
#include "MemMap.h"

#if defined(OSTSKFPU)
#define RCV_APP_START_SEC_VAR_FAST_32
#include "MemMap.h"
extern APP_NEAR_32 volatile float taskRcv1, taskRcv2;
#define RCV_APP_STOP_SEC_VAR_FAST_32
#include "MemMap.h"
#endif

#define TRUSTED_APP_START_SEC_VAR_FAST_16
#include "MemMap.h"
extern APP_NEAR_16 int volatile hookNmb;
#define TRUSTED_APP_STOP_SEC_VAR_FAST_16
#include "MemMap.h"

/* Global 'send' application data */
#define SND_APP_START_SEC_VAR_FAST_16
#include "MemMap.h"
#if defined(OSTSKFPU)
extern APP_NEAR_16 volatile unsigned short ind, taskCnt, repeatCnt1;
#else
extern APP_NEAR_16 volatile unsigned short ind, taskSnd1, taskSnd2, taskCnt, repeatCnt1;
#endif
#define SND_APP_STOP_SEC_VAR_FAST_16
#include "MemMap.h"

#if defined(OSTSKFPU)
#define SND_APP_START_SEC_VAR_FAST_32
#include "MemMap.h"
extern APP_NEAR_32 volatile float taskSnd1, taskSnd2;
#define SND_APP_STOP_SEC_VAR_FAST_32
#include "MemMap.h"
#endif

typedef struct TagMYMsgA    MSGATYPE;           /* User defined type for a message */
struct TagMYMsgA
{
    unsigned short value;
};

typedef struct TagMYMsgB    MSGBTYPE;           /* User-defined type for a message */
struct  TagMYMsgB
{
    TickType    ts;                             /* user's defined time-stamp */
    unsigned short msg;                         /* message body */
};

#define REPEAT_CNT_MAX_VAL 2


#ifdef __cplusplus
}
#endif

#endif  /* SAMPLE_H */
