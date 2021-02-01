#################################################################
#
#   NXP(TM) and the NXP logo are trademarks of NXP
#   All other product or service names are the property of their respective owners.
#   (c) Copyright 2014 - 2016 Freescale Semiconductor Inc.
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
# Description:  common variable definitions makefile for AUTOSAR samples
#
#################################################################

PROJECT_ROOT    := $(dir $(shell cygpath -a -w makefile))
XDM_SAMPLE_PATH := $(SSC_ROOT)\$(os_dir)\os_ts\eclipse\workspace\os_sample_sc$(sc)\config
XDM_SAMPLE_PATH_MC := $(SSC_ROOT)\$(os_dir)\os_ts\eclipse\workspace\os_sample_sc$(sc)_mc\config

#################################################################
# Output paths (relative to PROJECT_ROOT)

OUTPUT_PATH     := $(PROJECT_ROOT)output_$(compiler)_$(cfg)
OBJ_OUTPUT_PATH := $(OUTPUT_PATH)\obj
BIN_OUTPUT_PATH := $(OUTPUT_PATH)\bin

#################################################################
# Specific (need in freescale os_rules.mak)

HWSPEC          := $(SSC_ROOT)\$(os_dir)\ssc\hwspec
OTHER_INCLUDES  := $(subst \,\\,$(SSC_ROOT)\$(os_dir)\ssc\other_includes)
PROJECT_SRC     := $(PROJECT_ROOT)src
SAMPLE_INCLUDES := $(subst \,\\,$(SSC_ROOT)\$(os_dir)\sample\standard\includes)
SAMPLE_SRC      := $(subst \,\\,$(SSC_ROOT)\$(os_dir)\sample\standard\src)
