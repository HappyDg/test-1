#################################################################
#
#   NXP(TM) and the NXP logo are trademarks of NXP. 
#   All other product or service names are the property of their respective owners.
#   (c) Copyright 2013 - 2015 Freescale Semiconductor Inc.
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
# Description:  common makefile for AUTOSAR benchmarks
#
#################################################################

# Default compiler
compiler := ghsarm

# List of supported compilers
compilers_list := gccarm iararm ghsarm

# Scalability class
sc := $(osclassname_VALUE)

include ../../../utils.mak

# Cygwin path
CYGWINDIR := \bin
USED_TOOLS_LIST  := CYGWINDIR

# Path to compiler directory
ifeq ($(compiler),ghsarm)
GHSDIR := path_to_GreenHills_compiler_not_set
USED_TOOLS_LIST += GHSDIR
endif
ifeq ($(compiler),gccarm)
GCCDIR := C:\Users\hieu
USED_TOOLS_LIST += GCCDIR
endif
ifeq ($(compiler),ds5arm)
DS5DIR := path_to_DS5_compiler_not_set
USED_TOOLS_LIST += DS5DIR
endif
ifeq ($(compiler),iararm)
IARDIR := path_to_IAR_compiler_not_set
USED_TOOLS_LIST += IARDIR
endif

include ../../../compiler_options.mak

all:

include ../../../common_rules.mak
