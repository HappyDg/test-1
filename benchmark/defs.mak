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
# Description:  common variable definitions makefile for AUTOSAR benchmarks
#
#################################################################
# PROJECT_ROOT - path to the project root given by the project makefile
# SSC_ROOT     - path to the ssc root given by the base_makefile
#

SSC_ROOT        := ..\..\..\..
PROJECT_ROOT    := $(SSC_ROOT)\benchmark

#################################################################
# Output paths (relative to PROJECT_ROOT)

OUTPUT_PATH := bin
BIN_OUTPUT_PATH := $(OUTPUT_PATH)
OBJ_OUTPUT_PATH := obj

#################################################################
# Specific (need in freescale os_rules.mak)

HWSPEC          := $(SSC_ROOT)\ssc\hwspec
OTHER_INCLUDES  := $(subst \,\\,$(SSC_ROOT)\ssc\other_includes)
COMMON_INCLUDES := $(subst \,\\,$(PROJECT_ROOT)\$(category)\common)
CATEGORY_COMMON_INCLUDES := $(subst \,\\,$(PROJECT_ROOT)\common)

OS_OIL_NAME     := sources\$(projname).oil

PROJECT_SRC     := $(PROJECT_ROOT)\$(category)\common

ifeq ($(linker_script),)
linker_script   := memory
endif
LINKER_CMD_NAME := $(PROJECT_ROOT)\common\$(linker_script)
LINKER_CMD_OUTNAME := $(OBJ_OUTPUT_PATH)\$(linker_script)


