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
# Description:  compiler options for AUTOSAR samples
#
#################################################################

ifeq ($(compiler),ghsarm)

#\/----------------------------------------------------- GREEN HILLS START -----------------------------------------------------\/

# GREEN HILLS compiler root directory
GHS_DIR     := $(strip $(call remove_spaces,$(call remove_slashes,$(GHSDIR))))

proc        := cortexm4f

# Compiler paths
cbin        := $(GHS_DIR)
cinc        := $(GHS_DIR)/include/arm
clib        := $(GHS_DIR)/lib/thumb2
clibinc     := .
ceabinc     := .
ceablib     := .


# Executables
CC          := $(cbin)/ccthumb.exe
CP          := $(cbin)/ccthumb.exe
AS          := $(cbin)/ccthumb.exe
LI          := $(cbin)/elxr.exe

# Compilers' options
ccopt       := -cpu=$(proc) -c -Osize -Wall -ansi -G -preprocess_assembly_files --no_exceptions \
               -dual_debug --prototype_errors -Wundef -noslashcomment -Wimplicit-int -Wshadow \
               -Wtrigraphs -nostartfile --no_commons --incorrect_pragma_warnings -keeptempfiles \
               -list --short_enum -fhard -fpu=vfpv4_d16

# Preprocessor options
cpopt       := -DOSGHSARM -I$(cinc) -I$(clib) -I$(clibinc) -I$(ceabinc) -I$(OTHER_INCLUDES) -I$(SAMPLE_INCLUDES)

# Assembler options
asopt       := -cpu=$(proc) -c -preprocess_assembly_files -asm=-list -D__STACK_SIZE=0x800 -fhard -fpu=vfpv4_d16

ldopt        = -Mn -delete -v -ignore_debug_references -map -keepmap -T $(LINKER_CMD_OUTFILE) \
               -L $(clib) -lstartup -lsys -larch -lansi  -L $(ceablib) $(FILES_TO_LINK)

#/\----------------------------------------------------- GREEN HILLS END -----------------------------------------------------/\

endif # $(compiler) == ghsarm

ifeq ($(compiler),gccarm)

#\/----------------------------------------------------- GCC ARM START -----------------------------------------------------\/

# GCC compiler root directory
GCC_DIR     := $(strip $(call remove_spaces,$(call remove_slashes,$(GCCDIR))))

proc        := cortex-m4

# Compiler paths
cbin        := $(GCC_DIR)/bin
cinc        := .
clib        := .
clibinc     := .
ceabinc     := .
ceablib     := .


# Executables
GCCARM_TOOLCHAIN_PREFIX := arm-none-eabi

CC          := $(cbin)/$(GCCARM_TOOLCHAIN_PREFIX)-gcc.exe
CP          := $(cbin)/$(GCCARM_TOOLCHAIN_PREFIX)-gcc.exe
AS          := $(cbin)/$(GCCARM_TOOLCHAIN_PREFIX)-gcc.exe
LI          := $(cbin)/$(GCCARM_TOOLCHAIN_PREFIX)-ld.exe

# Compilers' options - use "-O1"
ccopt := -c -O1 -ggdb3 -mcpu=$(proc) -mthumb -mlittle-endian -fomit-frame-pointer -mhard-float -fno-common \
         -Wall -Wextra -Wstrict-prototypes -Wno-sign-compare -Werror=implicit-function-declaration \
         -mfloat-abi=hard -mfpu=fpv4-sp-d16

# Preprocessor options
cpopt := -DOSGCCARM -I$(cinc) -I$(clib) -I$(clibinc) -I$(ceabinc) -I$(OTHER_INCLUDES) -I$(SAMPLE_INCLUDES)

# Assembler options
asopt := -mcpu=$(proc) -c -mthumb -x assembler-with-cpp -D__STACK_SIZE=0x800 -mfloat-abi=hard -mfpu=fpv4-sp-d16
#-DOSPROPH="\"$(OS_PROPHEADER)\""

# Linker options
ldopt  = -T $(LINKER_CMD_OUTFILE) -Map $(bin_output_path)/$(projname).map -L $(clib) -L $(ceablib) $(FILES_TO_LINK)

#/\----------------------------------------------------- GCC ARM END -----------------------------------------------------/\

endif # $(compiler) == gccarm


ifeq ($(compiler),ds5arm)

#\/----------------------------------------------------- DS5 ARM START -----------------------------------------------------\/

# DS5 compiler root directory
DS5_DIR     := $(strip $(call remove_spaces,$(call remove_slashes,$(DS5DIR))))

proc        := Cortex-M4

# Compiler paths
cbin        := $(DS5_DIR)/bin
cinc        := .
clib        := .
clibinc     := .
ceabinc     := .
ceablib     := .


# Executables
CC          := $(cbin)/armcc.exe
CP          := $(cbin)/not_found.exe
AS          := $(cbin)/armasm.exe
LI          := $(cbin)/armlink.exe

# Compilers' options
ccopt := -c -O3 -Otime --strict --strict_warnings --c90 --dollar -g --cpu=$(proc) --library_type=microlib

# Preprocessor options
cpopt := -DOSDS5ARM -I$(cinc) -I$(clib) -I$(clibinc) -I$(ceabinc) -I$(OTHER_INCLUDES) -I$(SAMPLE_INCLUDES)

# Assembler options
asopt := --cpu=$(proc) --library_type=microlib --cpreproc --cpreproc_opts=-D,__STACK_SIZE=0x800

# Linker options
# $(clib) $(ceablib)
ldopt  = --cpu=$(proc) --library_type=microlib --info unused --symbols --entry Reset_Handler --scatter $(LINKER_CMD_OUTFILE) --map --list=$(bin_output_path)/$(projname).map $(FILES_TO_LINK)

#/\----------------------------------------------------- DS5 ARM END -----------------------------------------------------/\

endif # $(compiler) == ds5arm



ifeq ($(compiler),iararm)

#\/----------------------------------------------------- IAR ARM START -----------------------------------------------------\/

# IAR compiler root directory
IAR_DIR     := $(strip $(call remove_spaces,$(call remove_slashes,$(IARDIR))))

proc        := Cortex-M4F

# Compiler paths
cbin        := $(IAR_DIR)/bin
cinc        := $(IAR_DIR)/inc/c/
clib        := .
clibinc     := .
ceabinc     := .
ceablib     := $(IAR_DIR)/lib

# Executables
CC          := $(cbin)/iccarm.exe
CP          := $(cbin)/not_found.exe
AS          := $(cbin)/iasmarm.exe
LI          := $(cbin)/ilinkarm.exe

# Compilers' options
ccopt := -Ohs --debug --cpu=$(proc) --thumb --endian=little --require_prototypes --no_wrap_diagnostics --no_system_include -c --fpu=VFPv4_sp

# Preprocessor options
cpopt := -DOSIARARM -I$(cinc) -I$(clib) -I$(clibinc) -I$(ceabinc) -I$(OTHER_INCLUDES) -I$(SAMPLE_INCLUDES)

# Assembler options
asopt := --cpu $(proc) --cpu_mode thumb -g --fpu VFPv4_sp

# Linker options
# $(clib)
ldopt  = --cpu=$(proc) --no_wrap_diagnostics --skip_dynamic_initialization -L $(ceablib) --config $(LINKER_CMD_OUTFILE) --map $(bin_output_path)/$(projname).map $(FILES_TO_LINK)


#/\----------------------------------------------------- IAR ARM END -----------------------------------------------------/\

endif # $(compiler) == iararm

# Use s32k142 definition to make the configuration file generic for all derivatives
cpopt += -DS32K142

