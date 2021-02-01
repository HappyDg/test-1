/**
*   @file    Os_sections.h
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

#ifdef __cplusplus
extern "C"
{
#endif




#if !defined(OSGCCARM)  && !defined(OSGHSARM) && !defined(OSDS5ARM) && !defined(OSIARARM)
#error Unknown compiler
#endif




#define OSMEMMAP_ERROR


/*
 * OSCODE start
 */

#if defined(OSTEXT_START_SEC_CODE)
#undef OSTEXT_START_SEC_CODE
#undef OSMEMMAP_ERROR



#if defined(OSGHSARM)
#pragma ghs section text=".ostext"
#endif
#if defined(OSDS5ARM)
#pragma arm section code=".ostext"
#endif
#if defined(OSIARARM)
#pragma default_function_attributes = @ ".ostext"
#endif

/*
 * OSCODE stop
 */
#elif defined(OSTEXT_STOP_SEC_CODE)
#undef OSTEXT_STOP_SEC_CODE
#undef OSMEMMAP_ERROR


#if defined(OSGHSARM)
#pragma ghs section text=default
#endif
#if defined(OSDS5ARM)
#pragma arm section code
#endif
#if defined(OSIARARM)
#pragma default_function_attributes =
#endif

/*
 * VAR sections start
 */
#elif defined(OS_START_SEC_VAR_UNSPECIFIED)
#undef OS_START_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSGHSARM)
#pragma ghs section bss=".osbss"
#pragma ghs startdata
#endif
#if defined(OSDS5ARM)
#pragma arm section rwdata=".osdata", zidata=".osbss"
#endif

/*
 * VAR sections stop
 */
#elif defined(OS_STOP_SEC_VAR_UNSPECIFIED)
#undef OS_STOP_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSGHSARM)
#pragma ghs enddata
#pragma ghs section bss=default
#endif
#if defined(OSDS5ARM)
#pragma arm section rwdata, zidata
#endif


/*
 * VAR FAST sections start
 */
#elif defined(OS_START_SEC_VAR_FAST_UNSPECIFIED)
#undef OS_START_SEC_VAR_FAST_UNSPECIFIED
#undef OSMEMMAP_ERROR



#if defined(OSGHSARM)
#pragma ghs section bss=".ossbss"
#pragma ghs startdata
#endif
#if defined(OSDS5ARM)
#pragma arm section rwdata=".ossdata", zidata=".ossbss"
#endif


/*
 * VAR FAST sections stop
 */
#elif defined(OS_STOP_SEC_VAR_FAST_UNSPECIFIED)
#undef OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#undef OSMEMMAP_ERROR


#if defined(OSGHSARM)
#pragma ghs enddata
#pragma ghs section bss=default
#endif
#if defined(OSDS5ARM)
#pragma arm section rwdata, zidata
#endif

/*
 * NON CACHEABLE VAR sections start
 */

#elif defined(OS_NONCACHEABLE_START_SEC_VAR_UNSPECIFIED)
#undef OS_NONCACHEABLE_START_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR



#if defined(OSGHSARM)
#pragma ghs section bss=".osnoncacheablebss"
#pragma ghs startdata
#endif
#if defined(OSDS5ARM)
#pragma arm section rwdata=".osnoncacheabledata", zidata=".osnoncacheablebss"
#endif

/*
 * NON CACHEABLE VAR sections stop
 */
#elif defined(OS_NONCACHEABLE_STOP_SEC_VAR_UNSPECIFIED)
#undef OS_NONCACHEABLE_STOP_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR



#if defined(OSGHSARM)
#pragma ghs enddata
#pragma ghs section bss=default
#endif
#if defined(OSDS5ARM)
#pragma arm section rwdata, zidata
#endif


/*
 * STACK sections start
 */
#elif defined(OSSTACK_START_SEC_VAR_UNSPECIFIED)
#undef OSSTACK_START_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR



#if defined(OSGHSARM)
#pragma ghs startdata
#pragma ghs section bss=".osstack"
#endif
#if defined(OSDS5ARM)
#pragma arm section zidata=".osstack"
#endif
#if defined(OSIARARM)
#pragma default_variable_attributes = @ ".osstack"
#endif

/*
 * STACK sections stop
 */
#elif defined(OSSTACK_STOP_SEC_VAR_UNSPECIFIED)
#undef OSSTACK_STOP_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR




#if defined(OSGHSARM)
#pragma ghs enddata
#pragma ghs section bss=default
#endif
#if defined(OSDS5ARM)
#pragma arm section zidata
#endif
#if defined(OSIARARM)
#pragma default_variable_attributes =
#endif

/*
 * STACK second core start
 */

#elif defined(OSSTACK2_START_SEC_VAR_UNSPECIFIED)
#undef OSSTACK2_START_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR



/*
 * STACK second core stop
 */
#elif defined(OSSTACK2_STOP_SEC_VAR_UNSPECIFIED)
#undef OSSTACK2_STOP_SEC_VAR_UNSPECIFIED
#undef OSMEMMAP_ERROR






/*
 * CONST sections start
 */
#elif defined(OS_START_SEC_CONST_UNSPECIFIED)
#undef OS_START_SEC_CONST_UNSPECIFIED
#undef OSMEMMAP_ERROR



#if defined(OSGHSARM)
#pragma ghs section rodata=".osrodata"
#pragma ghs startdata
#endif
#if defined(OSDS5ARM)
#pragma arm section rodata=".osrodata"
#endif


/*
 * CONST sections stop
 */
#elif defined(OS_STOP_SEC_CONST_UNSPECIFIED)
#undef OS_STOP_SEC_CONST_UNSPECIFIED
#undef OSMEMMAP_ERROR



#if defined(OSGHSARM)
#pragma ghs enddata
#pragma ghs section rodata=default
#endif
#if defined(OSDS5ARM)
#pragma arm section rodata
#endif


/*
 * CONST FAST section start
 */
#elif defined(OS_START_SEC_CONST_FAST_UNSPECIFIED)
#undef OS_START_SEC_CONST_FAST_UNSPECIFIED
#undef OSMEMMAP_ERROR



#if defined(OSGHSARM)
#pragma ghs section rodata=".ossrodata"
#endif
#if defined(OSDS5ARM)
#pragma arm section rodata=".ossrodata"
#endif

/*
 * CONST FAST section stop
 */
#elif defined(OS_STOP_SEC_CONST_FAST_UNSPECIFIED)
#undef OS_STOP_SEC_CONST_FAST_UNSPECIFIED
#undef OSMEMMAP_ERROR



#if defined(OSGHSARM)
#pragma ghs section rodata=default
#endif
#if defined(OSDS5ARM)
#pragma arm section rodata
#endif

#endif


#if defined(OSMEMMAP_ERROR)
#error "Os_sections.h: OSMEMMAP_ERROR is defined"
#endif


#ifdef __cplusplus
}
#endif



/** @} */
