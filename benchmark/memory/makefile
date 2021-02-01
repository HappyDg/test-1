##################################################################
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
#  Description:  makefile for memory benchmarks
#
#  Notes:  1. Usage
#             make [-s] <target> ... [<variable>=<value>] ...
#
#          2. Targets:
#             all  - build all benchmarks (target by default)
#             clean - clear files for all benchmarks
#
#          3. Variables:
#             compiler - type of compiler: ds5arm, ghsarm or gccarm
#                        (value by default see in common.mak)
#
#          4. Examples:
#             make                        - build all memory benchmarks
#             make compiler=ds5arm        - build all memory benchmarks
#                                           using DS5 ARM compiler
#             make clean                  - clear files for all memory benchmarks
#
#################################################################

bmarks := bcc1 ecc1

clean_bmarks = $(addprefix clean_,$(bmarks))
clean_keep_elf_bmarks = $(addprefix clean_keep_elf_,$(bmarks))

.PHONY: all clean $(bmarks) $(clean_bmarks)

define generate_build_rule
$(1):
	@$(MAKE) -C ./$(1) c=$(2)
endef

define generate_clean_rule
clean_$(1):
	@$(MAKE) -C ./$(1) clean
endef

define generate_clean_keep_elf_rule
clean_keep_elf_$(1):
	@$(MAKE) -C ./$(1) clean_keep_elf
endef

all: $(bmarks)
clean: $(clean_bmarks)
clean_keep_elf: $(clean_keep_elf_bmarks)

$(foreach bmark,$(bmarks),$(eval $(call generate_build_rule,$(bmark),$(c))))

$(foreach bmark,$(bmarks),$(eval $(call generate_clean_rule,$(bmark))))

$(foreach bmark,$(bmarks),$(eval $(call generate_clean_keep_elf_rule,$(bmark))))