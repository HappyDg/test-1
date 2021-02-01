/**
*   @file    Os_compiler_internal_api.h
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
#ifndef OS_COMPILER_INTERNAL_API_H_
#define OS_COMPILER_INTERNAL_API_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <Os_compiler_api.h>




#if defined(OSGHSARM)
#include <arm_ghs.h>            /* for intrinsic functions only */
#endif




#if !defined(OSGCCARM)  && !defined(OSGHSARM)  && !defined(OSDS5ARM) && !defined(OSIARARM)
#error "Compiler is not defined"
#endif



/* Data section addresses for various compilers */



#if defined(OSGCCARM)
#define OS_BEGIN_DSADDR(DSNAME) _f_##DSNAME
#define OS_END_DSADDR(DSNAME)   _e_##DSNAME
#endif

#if defined(OSGHSARM)
#define OS_BEGIN_DSADDR(DSNAME) _f_##DSNAME
#define OS_END_DSADDR(DSNAME)   _e_##DSNAME
#endif

#if defined(OSDS5ARM)
/* TBD find equivalent */
#define OS_BEGIN_DSADDR(DSNAME) _f_##DSNAME
#define OS_END_DSADDR(DSNAME)   _e_##DSNAME
#endif

#if defined(OSIARARM)
/* TBD find equivalent */
#define OS_BEGIN_DSADDR(DSNAME) _f_##DSNAME
#define OS_END_DSADDR(DSNAME)   _e_##DSNAME
#endif









/* definitions for assembler functions */
#if defined(OSGCCARM) || defined(OSGHSARM) || defined(OSDS5ARM) || defined(OSIARARM)
#define OSSTRING(x) #x
#define OSASMF(x) OSASM (" "OSSTRING(x)" ")
#define OSASMF2(x,x1) OSASM (" "OSSTRING(x)","OSSTRING(x1)" ")
#define OSASMF3(x,x1,x2) OSASM (" "OSSTRING(x)","OSSTRING(x1)","OSSTRING(x2)" ")
#define OSASMF4(x,x1,x2,x3) OSASM (" "OSSTRING(x)","OSSTRING(x1)","OSSTRING(x2)","OSSTRING(x3)" ")
#define OSASMF5(x,x1,x2,x3,x4) OSASM (" "OSSTRING(x)","OSSTRING(x1)","OSSTRING(x2)","OSSTRING(x3)","OSSTRING(x4)" ")
#endif /* OSGCCARM || OSGHSARM || OSDS5ARM || OSIARARM */








#if defined(OSGCCARM)
#define OSWARNSUPPRESS
#endif /* defined(OSGCCARM) */

#if defined(OSGHSARM)
#define OSWARNSUPPRESS
#endif /* defined(OSGHSARM) */

#if defined(OSDS5ARM)
#define OSWARNSUPPRESS
#endif /* defined(OSDS5ARM) */

#if defined(OSIARARM)
#define OSWARNSUPPRESS
#endif /* defined(OSIARARM) */








#if defined(OSDS5ARM)
    extern OSDWORD Image$$MAIN_STACK$$ZI$$Limit;
    extern OSDWORD Image$$MAIN_STACK$$ZI$$Base;
#elif defined(OSIARARM)
    extern OSDWORD CSTACK$$Base;
    extern OSDWORD CSTACK$$Limit;
#else
    extern OSDWORD OS_MAIN_STACK_MAX[];
    extern OSDWORD OS_MAIN_STACK_MIN[];
#endif /* defined(OSDS5ARM) */





#if defined(OSDS5ARM)
    #define OSSTACKTOP          (OSDWORD*)(&Image$$MAIN_STACK$$ZI$$Limit)
    #define OSSTACKBOTTOM       (OSDWORD*)(&Image$$MAIN_STACK$$ZI$$Base)
#elif defined(OSIARARM)
    #define OSSTACKTOP          (OSDWORD*)(&CSTACK$$Limit)
    #define OSSTACKBOTTOM       (OSDWORD*)(&CSTACK$$Base)
#else
    #define OSSTACKTOP          OS_MAIN_STACK_MAX
    #define OSSTACKBOTTOM       OS_MAIN_STACK_MIN
#endif /* defined(OSDS5ARM) */









#if defined(OSGCCARM)
#define OSUSE_FRAME
#endif

#if defined(OSGHSARM)
#define OSUSE_FRAME
#endif

#if defined(OSDS5ARM)
#define OSUSE_FRAME
#endif

#if defined(OSIARARM)
#define OSUSE_FRAME
#endif


#ifdef __cplusplus
}
#endif


#endif /*OS_COMPILER_INTERNAL_API_H_ */

/** @} */
