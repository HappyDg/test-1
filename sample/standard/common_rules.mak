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
# Description:  common rules makefile for AUTOSAR samples
#
#################################################################

# Cygwin utilities
CYGWIN_DIR  := $(strip $(call remove_slashes,$(CYGWINDIR)))
RM          := $(CYGWIN_DIR)/rm.exe
MKDIR       := $(CYGWIN_DIR)/mkdir.exe
CAT         := $(CYGWIN_DIR)/cat.exe
ECHO        := $(CYGWIN_DIR)/echo.exe
COPY        := $(CYGWIN_DIR)/cp.exe
TOUCH       := $(CYGWIN_DIR)/touch.exe
CHMOD       := $(CYGWIN_DIR)/chmod.exe
MV          := $(CYGWIN_DIR)/mv.exe

# Tresos path
ifeq ($(cfg),xdm)
TRESOSBASE  := $(strip $(call remove_slashes,$(TRESOS_BASE)))
endif # ifeq ($(cfg),xdm)

obj_output_path := $(call remove_slashes,$(OBJ_OUTPUT_PATH))
bin_output_path := $(call remove_slashes,$(BIN_OUTPUT_PATH))

# set final target
.PHONY: all
all: tools_validation $(BIN_OUTPUT_PATH)\$(projname).elf

mak_path := ssc\mak
include $(SSC_ROOT)\$(os_dir)\$(mak_path)\os_defs.mak
include $(SSC_ROOT)\$(os_dir)\$(mak_path)\os_rules.mak

OBJ_FILE_SUFFIX := o
LIB_FILE_SUFFIX := lib

.SUFFIXES: # Delete the default suffixes
.SUFFIXES: .c .h .$(OBJ_FILE_SUFFIX) .$(LIB_FILE_SUFFIX)

#/\----------------------------------------------------- check paths start -----------------------------------------------------/\

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),clean_keep_elf)
ifneq ($(MAKECMDGOALS),showflags)

tools_validation: $(foreach var,$(USED_TOOLS_LIST),$($(var)))
	$(foreach var,$(USED_TOOLS_LIST),$(shell test '$($(var))' || echo " Variable $(var) must be set"))

endif
endif
endif

#/\----------------------------------------------------- check paths stop -----------------------------------------------------/\

ifeq ($(CC_I),)
CC_I := -I
endif

ifeq ($(CC_D),)
CC_D := -D
endif

cpopt      += $(addprefix $(CC_I),$(call remove_slashes,$(CC_INCLUDE_PATH)))
cpopt      += $(foreach define,$(PREPROCESSOR_DEFINES), $(CC_D)$($(define)_KEY)=$($(define)_VALUE))

OBJ_OUTPUT_PATH1 = $(OBJ_OUTPUT_PATH)

$(eval $(call targetcheck_rule))

# C rule
ifndef generate_c_rule
define generate_c_rule
$(addprefix $(OBJ_OUTPUT_PATH1)\,$(addsuffix .$(OBJ_FILE_SUFFIX),$(basename $(notdir $(1))))): $(1)
	@$(ECHO) Processing $$<
	$(CC) $(ccopt) $(cpopt) $$(subst \,\\,$$<) -o $$(subst \,\\,$$@)
endef
endif # ifndef generate_c_rule

# Asm rule
ifndef generate_asm_rule
define generate_asm_rule
$(addprefix $(OBJ_OUTPUT_PATH)\,$(addsuffix .$(OBJ_FILE_SUFFIX),$(basename $(notdir $(1))))): $(1)
	@$(ECHO) Processing $$<
	$(AS) $(asopt) -o $$(subst \,\\,$$@) $$(subst \,\\,$$<)
endef
endif # ifndef generate_asm_rule

XX_FILES_TO_BUILD := $(CC_FILES_TO_BUILD) $(ASM_FILES_TO_BUILD)
XX_OBJ_FILES := $(addprefix $(OBJ_OUTPUT_PATH1)\,$(addsuffix .$(OBJ_FILE_SUFFIX),$(basename $(notdir $(XX_FILES_TO_BUILD)))))
FILES_TO_LINK := $(XX_OBJ_FILES) $(LIBRARIES_LINK_ONLY) $(OBJECTS_LINK_ONLY)

# Dependencies
-include $(XX_OBJ_FILES:.o=.d)

# Generation of C and assembler rules
$(foreach file,$(CC_FILES_TO_BUILD),$(eval $(call generate_c_rule,$(file))))
$(foreach file,$(ASM_FILES_TO_BUILD),$(eval $(call generate_asm_rule,$(file))))


# Rule for linking
$(BIN_OUTPUT_PATH)\$(projname).elf: $(FILES_TO_LINK) $(DBG_FILES) $(LINKER_CMD_OUTFILE)
	@$(ECHO) Linking $@
	@$(MKDIR) -p $(bin_output_path)
ifndef linking_rule
	$(LI) $(ldopt)  -o $(subst \,\\,$@)
else
	$(call linking_rule)
endif

# Debug rule is optional offering the possibility to be implemented in common.mak
ifeq ($(debug),yes)
$(eval $(call debug_rule))
endif

# Target for show internal options
showflags:
	@$(ECHO) showflags...
	@$(ECHO) COMPILEROPTIONS = $(ccopt) $(cpopt)
	@$(ECHO) LINKEROPTIONS = $(ldopt)
	@$(ECHO) PREPROCESSOR_DEFINES = $(PREPROCESSOR_DEFINES)
	@$(ECHO) CC_FILES_TO_BUILD = $(CC_FILES_TO_BUILD)
	@$(ECHO) ASM_FILES_TO_BUILD = $(ASM_FILES_TO_BUILD)
	@$(ECHO) CC_INCLUDE_PATH = $(CC_INCLUDE_PATH)
	@$(ECHO) FILES_TO_LINK = $(FILES_TO_LINK)

clean:
	@$(ECHO) Clean...
	$(call cleanup_specific_files)
	@$(RM) -fR $(OUTPUT_PATH)

clean_keep_elf:
	@$(ECHO) Clean with keep elf ...
	$(call cleanup_specific_files)
	@$(RM) -fR $(OBJ_OUTPUT_PATH)
