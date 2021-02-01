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
#  Description:  makefile for SC1 sample
#
#  Notes:  1. Usage
#             make [-s] <target> ... [<variable>=<value>] ...
#
#          2. Targets:
#             all  - build all samples (target by default)
#             sc1  - build sample for scalability class 1
#
#             clean - clear files for all samples
#             clean_sc1 - clear files for SC1 sample

#          3. Variables:
#             compiler - type of compiler: gccarm

#
#
#             debug    - Generate Lauterbach command file:
#                        no (by default)
#                        yes
#
#             cfg      - config file source: oil, epc or xdm  configuration file
#                        (value by oil)
#
#             flash    - load sample image into flash memory
#                        no (by default)
#                        yes
#
#             mcu      - select derivative silicon
#                        s32k144 (by default)
#                        s32k148
#
#          4. Some useful options:
#             -s       - silent mode (don't echo commands)
#
#          5. Examples:
#             make                         - build all samples
#             make compiler=gccarm         - build all samples with GCC compiler
#             make sc1                     - build sample for scalability class 1
#             make sc1   compiler=gccarm   - build sample for scalability classes 1

#             make sc1 debug=yes           - build sample for scalability class 1
#                                            with generation of Lauterbach command file
#             make clean                   - clear files for all samples
#             make clean_sc1               - clear files for SC1 sample
#
#################################################################

#default values
samples := sc1
compiler := ghsarm
debug := yes
cfg := oil
flash := no
mcu := s32k142

clean_samples = $(addprefix clean_,$(samples))

.PHONY: all clean $(samples) $(clean_samples)

define generate_build_rule
$(1):
	@$(MAKE) -C ./$(1) compiler=$(2) mcu=$(3) debug=$(4) cfg=$(5) flash=$(6)
endef

define generate_clean_rule
clean_$(1):
	@$(MAKE) -C ./$(1) clean
endef

all: $(samples)
clean: $(clean_samples)

$(foreach sample,$(samples),$(eval $(call generate_build_rule,$(sample),$(compiler),$(mcu),$(debug),$(cfg),$(flash))))
$(foreach sample,$(samples),$(eval $(call generate_clean_rule,$(sample))))