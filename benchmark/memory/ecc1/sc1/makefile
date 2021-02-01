#################################################################
#
#   NXP(TM) and the NXP logo are trademarks of NXP. 
#   All other product or service names are the property of their respective owners.
#   (c) Copyright 2012 - 2016 Freescale Semiconductor Inc.
#   Copyright 2017 NXP
#   All Rights Reserved.
#
#   You can use this example for any purpose on any computer system with the
#   following restrictions:
#
#   1. This example is provided "as is", without warranty.
#
#   2. You don't remove this copyright notice from this example or any direct derivation
#     thereof.
#
#  Description:  makefile for memory ECC1 SC1 benchmark
#
#  Notes:  1. Usage
#             make [-s] <target> ... [<variable>=<value>] ...
#
#          2. Targets:
#             all  - build benchmark
#             clean - clear object and binary files for benchmark
#
#          3. Variables:
#             compiler - type of compiler: ds5arm, ghsarm or gccarm
#                        (value by default see in common.mak)
#
#          4. Examples:
#             make                  - build benchmark
#             make compiler=ds5arm  - build benchmark
#                                     using DS5 ARM compiler
#             make clean            - clear files for benchmark
#
#################################################################

# select platform
platform := ARMS32K

# benchmark category
category := memory

# Project name
projname := mecc1sc1

# Config source file
cfg := oil

# Definitions of makefile variables
include ../../../defs.mak

CC_INCLUDE_PATH += $(PROJECT_SRC) $(OBJ_OUTPUT_PATH)

# Files to build

# OS configuration
CC_FILES_TO_BUILD += \
    $(OBJ_OUTPUT_PATH)\$(projname)_cfg.c \

# User application
CC_FILES_TO_BUILD += \
    $(PROJECT_SRC)\mecc1.c \
    $(HWSPEC)\SystemInit.c

PREPROCESSOR_DEFINES += osclassname apptypesh oscfgname ospropname
osclassname_KEY      := __CLASS_SC1
osclassname_VALUE    := 1
apptypesh_KEY        := APPTYPESH
apptypesh_VALUE      := "\".\\..\\..\\..\\common\\memory.h\""
oscfgname_KEY        := OSCFGH
oscfgname_VALUE      := "<$(projname)_cfg.h>"
ospropname_KEY       := OSPROPH
ospropname_VALUE     := "\"Os_prop.h\""

#################################################################
include ../../../common.mak # base makefile

