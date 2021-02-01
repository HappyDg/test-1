/**
*    @file        Std_Types.h
*    @version     4.0.98
*
*    @brief       AUTOSAR OS Standard types definition.
*    @details     AUTOSAR standard types header file. It contains all types that are used across several
*                 modules of the basic software and that are platform and compiler independent
*/

/*==================================================================================================
*    Project      : AUTOSAR OS 4.0
*    Patform      : Arm Architecture
*    Peripheral   : CortexM4
*    Dependencies : none
*
*    Autosar Version       : 4.0.3
*    Autosar Revision      : ASR_REL_4_0_REV_0003
*    Autosar Conf. Variant :
*    Software Version      : 4.0.98
*    Build Version         : ARMS32KV4_OS_4.0.98_ASR_REL_4_0_REV_0003
*

*   (c) Copyright 2011 - 2016 Freescale Semiconductor Inc.
*   Copyright 2017 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


/**
@file        Std_Types.h
@remarks Covers STD014
*/
#ifndef STD_TYPES_H
#define STD_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief Parameters that shall be published within the standard types header file and also in the
*        module's description file
* @implements DBASE12012, DBASE12013, DBASE12014, DBASE12015, DBASE12016, DBASE12017, DBASE12018
*/
#define STD_VENDOR_ID                     43
#define STD_AR_RELEASE_MAJOR_VERSION      4
#define STD_AR_RELEASE_MINOR_VERSION      0
#define STD_AR_RELEASE_REVISION_VERSION   3
#define STD_SW_MAJOR_VERSION              4
#define STD_SW_MINOR_VERSION              0
#define STD_SW_PATCH_VERSION              98



/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
@brief Because E_OK is already defined within OSEK, the symbol E_OK has to be shared. To avoid
       name clashes and redefinition problems, the symbols have to be defined in the following way
       (approved within implementation).
@remarks Covers STD006
*/
#ifndef STATUSTYPEDEFINED
    #define STATUSTYPEDEFINED
    /**
    @brief Success return code
    @remarks Covers STD006
    @remarks Implements DBASE01004
    */
    #define E_OK         ( (StatusType) 0 )
    /**
    @brief This type is defined for OSEK compliance.
    @remarks Covers STD006
    @remarks Implements DBASE01011
    */
    typedef unsigned char StatusType;
#endif

/**
@brief This type can be used as standard API return type which is shared between the RTE and the BSW modules.
@remarks Covers STD005, STD011
@remarks Implements DBASE01002
*/
typedef unsigned char Std_ReturnType;



#ifdef __cplusplus
}
#endif

#endif /* #ifndef STD_TYPES_H */
