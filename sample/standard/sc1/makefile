#################################################################
#
#   NXP(TM) and the NXP logo are trademarks of NXP
#   All other product or service names are the property of their respective owners.
#   (c) Copyright 2013 - 2016 Freescale Semiconductor Inc.
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
#  Description:  makefile for SC1 sample
#
#  Notes:  1. Usage
#             make [-s] <target> ... [<variable>=<value>] ...
#
#          2. Targets:
#             all  - build SC1 sample (target by default)
#             clean - clear object and binary files for SC1 sample
#             clean_keep_elf - clear only object files for SC1 sample
#             showflags - show options, list of source files etc.
#
#          3. Variables:
#             compiler - type of compiler:
#                        ghsarm - GreenHills compiler
#                        gccarm - GCC compiler
#                        iararm - IAR compiler
#                        (value by default see below)
#
#             debug    - debugging support: yes or no
#                        debug=yes - generate a script for Lauterbach debugger
#                                    in the directory output/bin
#                        (value by default: no)
#             cfg      - config file source: oil, epc or xdm  configuration file
#                        (value by default: oil)
#
#             flash    - load sample image into flash memory
#                        no (by default)
#                        yes
#
#             fpu      - select whether using FPU feature or not
#                        no (by default)
#                        yes
#
#
#          4. Some useful options:
#             -s    - silent mode (don't echo commands)
#
#          5. Examples:
#             make                        - build SC1 sample
#             make cfg=xdm                - build SC1 sample with XDM
#                                           configuration file
#             make compiler=ghsarm        - build SC1 sample using GreenHills compiler
#             make debug=yes              - build sample with default (GreenHills) compiler
#                                           with generation of Lauterbach command file
#             make clean                  - clear files for SC1 sample
#
#################################################################

# Select platform (only s32k)
platform := s32k

# Select derivative silicon (to keep configuration files generic for all derivatives)
mcu := s32k142

# Select default compiler
compiler := ghsarm

# Config source file
cfg := oil

# FPU feature configuration
fpu := no

# Project name
projname := sample1

# Explicitly set Scalability Class (variable is used in common.mak file)
sc := 1

#Select MCU core
core := master

#Select memory (flash/ram)
flash := no

#################################################################
# define the directory where the module is located in

os_dir          := S32K_AUTOSAR_OS_4_0_98_RTM_1_0_0

#################################################################
# PROJECT_ROOT - path to the project root given by the project makefile
# SSC_ROOT     - path to the ssc root given by the base_makefile
# XDM_SAMPLE_PATH - path to the xdm sample
# XDM_SAMPLE_PATH_MC - path to the multicore xdm sample

SSC_ROOT        := C:\NXP\AUTOSAR

# Definitions of makefile variables
include ../defs.mak

ifeq ($(cfg),oil)
ifeq ($(core),master)
ifeq ($(fpu),yes)
OS_OIL_NAME     := $(PROJECT_SRC)\$(projname)_fpu.oil
else
OS_OIL_NAME     := $(PROJECT_SRC)\$(projname).oil
endif
endif
endif

ifeq ($(cfg),epc)
ifeq ($(core),master)
ifeq ($(fpu),yes)
OS_OIL_NAME     := $(PROJECT_SRC)\$(projname)_fpu.epc
else
OS_OIL_NAME     := $(PROJECT_SRC)\$(projname).epc
endif
endif
endif

ifeq ($(cfg),xdm)
ifeq ($(core),master)
OS_OIL_NAME     := $(XDM_SAMPLE_PATH)\OS.xdm
endif
endif

ifeq ($(flash),yes)
SUFFIX_LD   := _fls
else
SUFFIX_LD   :=
endif

LINKER_CMD_NAME := $(PROJECT_ROOT)lcf\$(projname)$(SUFFIX_LD)
LINKER_CMD_OUTNAME := $(OUTPUT_PATH)\obj\$(projname)$(SUFFIX_LD)

CC_INCLUDE_PATH += $(PROJECT_SRC) $(HWSPEC) $(OBJ_OUTPUT_PATH)

# Files to build

# OS configuration
ifeq ($(core),master)
CC_FILES_TO_BUILD += \
	$(OBJ_OUTPUT_PATH)\$(projname)_cfg.c
endif

# User application
CC_FILES_TO_BUILD += \
	$(HWSPEC)\SystemInit.c \
	$(PROJECT_SRC)\samplets1.c \
	$(PROJECT_SRC)\samplerv1.c


PREPROCESSOR_DEFINES += apptypesh oscfgname ospropname
apptypesh_KEY        :=APPTYPESH
apptypesh_VALUE      :="<sample.h>"
oscfgname_KEY        :=OSCFGH
oscfgname_VALUE      :="<$(projname)_cfg.h>"
ospropname_KEY       :=OSPROPH
ospropname_VALUE      ="\"$(call remove_slashes,$(OS_PROPHEADER))\""

#################################################################
include ../common.mak  # base makefile

