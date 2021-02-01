/******************************************************************************
*
*       NXP(TM) and the NXP logo are trademarks of NXP.
*       All other product or service names are the property of their respective owners.
*       (C) Freescale Semiconductor, Inc. 2013-2016
*       Copyright 2019 NXP
*
*       THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
*       BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF NXP.
*
*       Description: IOC header file
*
*       Note: The implementation that was used is: AUTOSAR_S32K
*       System Generator for AUTOSAR OS/S32K - Version: 4.0 Build 4.0.98
*
********************************************************************************/
#ifndef IOC_H
#define IOC_H

/* 'LastIsBest' */

/* MsgA */
#define IocRead_MsgA(DataRef) OSIocRead(0U, (OSBYTEPTR) DataRef)
#define IocWrite_MsgA(DataRef) OSIocWriteRef( 0U, (OSBYTEPTR) DataRef)

/* MsgB */
#define IocRead_MsgB(DataRef) OSIocRead(1U, (OSBYTEPTR) DataRef)
#define IocWrite_MsgB(DataRef) OSIocWriteRef( 1U, (OSBYTEPTR) DataRef)

/* Queued */

#endif /* IOC_H */

