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
remove_slashes = $(subst \,/,$(1))

empty       :=
space       := $(empty) $(empty)

remove_spaces = $(subst $(space),\$(space),$(1))

to_dslashes = $(subst \,\\,$(1))

#compiler checking
ifneq ($(filter $(compiler),$(compilers_list)),$(compiler))
$(error Undefined compiler type: '$(compiler)', use one from: $(compilers_list))
endif