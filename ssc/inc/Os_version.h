/**
*   @file    Os_version.h
*   @version 4.0.98
*
*   @brief   AUTOSAR OS - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup [OS]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR OS 4.0
*   Platform             : Arm Architecture
*   Peripheral           : CortexM4
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 4.0.98
*   Build Version        : ARMS32KV4_OS_4.0.98_ASR_REL_4_0_REV_0003
*
*   (c) Copyright 2011 - 2016 Freescale Semiconductor Inc.
*   Copyright 2017 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef OS_VERSION_H
#define OS_VERSION_H


#ifdef __cplusplus
extern "C"
{
#endif

#define OS_VENDOR_ID        43u    /* Freescale AUTOSAR Vendor ID  */
#define OS_MODULE_ID        0x01   /* OS Module ID                 */

#define OS_AR_RELEASE_MAJOR_VERSION 4   /* Major version number of AUTOSAR specification       */
#define OS_AR_RELEASE_MINOR_VERSION 0   /* Minor version number of AUTOSAR specification       */
#define OS_AR_RELEASE_REVISION_VERSION 3   /* Patch level version number of AUTOSAR specification */

#define OS_SW_MAJOR_VERSION 40   /* Major version number of the implementation   */
#define OS_SW_MINOR_VERSION 98   /* Minor version number of the implementation   */
#define OS_SW_PATCH_VERSION 0    /* Patch level version number of the implementation */

#define OSBUILDNUMBER   "OS/ARMS32K v4.0 build 4.0.98"



#ifdef __cplusplus
}
#endif



#endif /*OS_VERSION_H*/

/** @} */

