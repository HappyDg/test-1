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
# Description:  common makefile for AUTOSAR samples
#
#################################################################

# Default compiler
compiler := ghsarm

# Make debug=yes default in order to generate the corresponding cmm files
debug := no

# List of supported compilers
compilers_list := gccarm iararm ghsarm

include ../utils.mak

# Cygwin path
CYGWINDIR := C:\cygwin64\bin
USED_TOOLS_LIST  := CYGWINDIR

# Tresos path
ifeq ($(cfg),xdm)
TRESOS_BASE := C:\EB\tresos
USED_TOOLS_LIST  += TRESOS_BASE
endif # ifeq ($(cfg),xdm)

# Path to compiler directory
ifeq ($(compiler),ghsarm)
GHSDIR := path_to_GreenHills_compiler_not_set
USED_TOOLS_LIST += GHSDIR
endif
ifeq ($(compiler),gccarm)
GCCDIR := C:\NXP\GNU_Tools_ARM_Embedded\10_2020-q4-major
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

include ../compiler_options.mak

ifeq ($(debug),yes)
# Please edit path to Lauterbach Trace32 software if necessary
EXPECT_DBG := LAUTERBACH_PATH
DBGDIR := $(subst /,\,$($(EXPECT_DBG)))
USED_TOOLS_LIST += DBGDIR
endif
# Current debug rule uses Lauterbach tool as debugger.
# In case of other debugger usage please update this rule or
# if you want obtain only the executable files set debug=no.
ifeq ($(debug),yes)
cmm_file := $(call remove_slashes,$(BIN_OUTPUT_PATH)\$(projname).cmm)
bat_file := $(call remove_slashes,$(BIN_OUTPUT_PATH)\$(projname).bat)

DBG_FILES := $(cmm_file) $(bat_file)

# T32 binary path related variables
T32_HOSTOS  := windows64
T32EXE      := t32marm

# t32m* relative path in the $(LAUTERBACH_PATH) tree
DBGEXE_RELPATH := bin/$(T32_HOSTOS)/$(T32EXE)

define debug_rule
$(cmm_file):
	@$(ECHO) Make CMM file $$@
	@$(ECHO) DO ../../../$(platform).cmm $(projname) $(flash)                                                                   > $$@
	@$(ECHO) DATA.LIST                                                                                                         >> $$@
	@$(ECHO) SYMBOL.BROWSE.FUNCTION                                                                                            >> $$@
ifeq ($(cfg),xdm)
	@$(ECHO) TASK.ORTI OS.ort                                                                                                  >> $$@
else
ifeq ($(fpu),yes)
	@$(ECHO) TASK.ORTI $(projname)_fpu.ort                                                                                     >> $$@
else
	@$(ECHO) TASK.ORTI $(projname).ort                                                                                         >> $$@
endif
endif
$(bat_file):
	@$(ECHO) Make BAT file $$@
	@$(ECHO) 'if not defined $(EXPECT_DBG) goto defaultDBG'                                                                     > $$@
	@$(ECHO) 'set DBG_PATH=%$(EXPECT_DBG)%'                                                                                    >> $$@
	@$(ECHO) 'goto startDBG'                                                                                                   >> $$@
	@$(ECHO) ':defaultDBG'                                                                                                     >> $$@
	@$(ECHO) 'set DBG_PATH=$(DBGDIR)'                                                                                          >> $$@
	@$(ECHO) ':startDBG'                                                                                                       >> $$@
	@$(ECHO) 'start %DBG_PATH%/$(DBGEXE_RELPATH) -c %DBG_PATH%/config.t32,$(projname).cmm %DBG_PATH% ../tmp 20001 CORE_0 USB CORE=1'    >> $$@
	@$(CHMOD) +rwx $$@
endef

endif

all:

include ../common_rules.mak