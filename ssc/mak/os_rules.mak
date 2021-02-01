################################################################
#
#  NXP(TM) and the NXP logo are trademarks of NXP
#  All other product or service names are the property of their respective owners.
#  (C) Freescale Semiconductor, Inc. 2013-2014
#  Copyright 2017 NXP
#  All Rights Reserved.
#
#  1. This example is provided "as is", without warranty.
#
#  2. You don't remove this copyright notice from this example or any direct derivation
#     thereof.
#
#  Description:  AUTOSAR OS rules makefile
#
#  Notes:
#
#################################################################

#################################################################
# REQUIRE:
#
# PROJECT_ROOT - path to the project root given by the project makefile (in base_make)
# SSC_ROOT     - path to the ssc root given by the base_makefile (in base_make)
#
# OS_SRC_PATH, OS_INC_PATH, OS_HWSPEC_PATH (in os_defs.mak)
# OS_OIL_NAME  - full name of project specific configuration file with '.oil' extension  (in makefile of project)
#

#################################################################
# Specific

OS_PROPHEADER := $(OBJ_OUTPUT_PATH)\Os_prop.h
OS_ORTI_NAME := $(BIN_OUTPUT_PATH)\$(basename $(notdir $(OS_OIL_NAME))).ort


#################################################################
# REGISTRY
# LIBRARIES_TO_BUILD +=
# freescale_oslib_FILES =

CC_FILES_TO_BUILD += $(wildcard $(OS_SRC_PATH)/*.c)

CC_FILES_FOR_COMPILER := $(wildcard $(HWSPEC)/$(compiler)/*.c)

ASM_FILES_FOR_COMPILER := $(wildcard $(HWSPEC)/$(compiler)/*.s)
ASM_FILES_FOR_COMPILER += $(wildcard $(HWSPEC)/$(compiler)/*.asm)

CC_FILES_TO_BUILD  += $(CC_FILES_FOR_COMPILER)
ASM_FILES_TO_BUILD += $(ASM_FILES_FOR_COMPILER)

ifeq ($(compiler),ghsarm)
LINKER_CMD_FILE    := $(LINKER_CMD_NAME).ld
LINKER_CMD_OUTFILE := $(LINKER_CMD_OUTNAME).ld
endif

ifeq ($(compiler),gccarm)
LINKER_CMD_FILE    := $(LINKER_CMD_NAME).gld
LINKER_CMD_OUTFILE := $(LINKER_CMD_OUTNAME).gld
endif

ifeq ($(compiler),ds5arm)
LINKER_CMD_FILE    := $(LINKER_CMD_NAME).scat
LINKER_CMD_OUTFILE := $(LINKER_CMD_OUTNAME).scat
endif

ifeq ($(compiler),iararm)
LINKER_CMD_FILE    := $(LINKER_CMD_NAME).icf
LINKER_CMD_OUTFILE := $(LINKER_CMD_OUTNAME).icf
ASM_FILES_FOR_COMPILER += $(wildcard $(OS_SRC_PATH)/*.s)
endif



# CPP_FILES_TO_BUILD +=
# ASM_FILES_TO_BUILD +=
#LIBRARIES_LINK_ONLY +=
# OBJECTS_LINK_ONLY +=
# DIRECTORIES_TO_CREATE +=

#MAKE_CLEAN_RULES +=
#MAKE_COMPILE_RULES +=
#MAKE_DEBUG_RULES +=
#MAKE_CONFIG_RULES +=
#MAKE_ADD_RULES +=

.PHONY: os_sysgen_rules
MAKE_GENERATE_RULES += os_sysgen_rules

ifeq ($(cfg),oil)
cfg_file := $(OS_OIL_NAME)
endif

ifeq ($(cfg),epc)
cfg_file := $(OS_OIL_NAME)
endif

ifeq ($(cfg),xdm)
cfg_file := $(OBJ_OUTPUT_PATH)\$(notdir $(basename $(OS_OIL_NAME))).epc
endif

$(OBJ_OUTPUT_PATH)\$(projname)_cfg.c: $(OS_OIL_NAME) $(LINKER_CMD_FILE)
	@echo Processing $<
	@$(MKDIR) -p $(obj_output_path) $(bin_output_path)

ifeq ($(cfg),xdm)
	$(TRESOSBASE)/bin/tresos_cmd.bat legacy convert "$(OS_OIL_NAME)@xdm" "$(cfg_file)@asc:4.0.3"
endif


ifeq ($(sc),1)
	$(OS_SG_PATH)\sg.exe -c$@ -h$*.h -o$(OS_ORTI_NAME) -i$(OS_SG_PATH) -p$(OS_PROPHEADER) -L$(LINKER_CMD_FILE) -M$(LINKER_CMD_OUTFILE) $(cfg_file)
endif

#ifeq ($(sc),2)
#	$(OS_SG_PATH)\sg.exe -c$@ -h$*.h -o$(OS_ORTI_NAME) -i$(OS_SG_PATH) -p$(OS_PROPHEADER) -L$(LINKER_CMD_FILE) -M$(LINKER_CMD_OUTFILE) $(cfg_file)
#endif

#ifeq ($(sc),3)
#	$(OS_SG_PATH)\sg.exe -c$@ -h$*.h -o$(OS_ORTI_NAME) -i$(OS_SG_PATH) -p$(OS_PROPHEADER) -L$(LINKER_CMD_FILE) -M$(LINKER_CMD_OUTFILE)  $(cfg_file)
#endif

#ifeq ($(sc),4)
#	$(OS_SG_PATH)\sg.exe -c$@ -h$*.h -o$(OS_ORTI_NAME) -i$(OS_SG_PATH) -p$(OS_PROPHEADER) -L$(LINKER_CMD_FILE) -M$(LINKER_CMD_OUTFILE) $(cfg_file)
#endif
	@$(TOUCH) $@


os_sysgen_rules: $(OS_OIL_CFG_NAME).c
