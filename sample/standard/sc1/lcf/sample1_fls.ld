/**************************************************************************************
*
*   NXP(TM) and the NXP logo are trademarks of NXP
*   All other product or service names are the property of their respective owners.
*   (c) Copyright 2013 - 2016 Freescale Semiconductor Inc.
*   Copyright 2017 NXP
*   All Rights Reserved.
*
*   You can use this example for any purpose on any computer system with the
*   following restrictions:
*
*   1. This example is provided "as is", without warranty.
*
*   2. You don't remove this copyright notice from this example or any direct derivation
*      thereof.
*
*  Description:  GHS linker command file for AUTOSAR OS sample application
*
**************************************************************************************/
MEMORY
{
    OsInternalROM   : org = 0x00000800, len = 0x0003F7FF /* 253 Kbytes */
    OsInternalRAM   : org = 0x1FFFC000, len = 0x00006FFF /* 28 Kbytes */
}

SECTIONS
{

     /* Interrupt vectors table */
    .vector                         : > OsInternalROM



    .startup                        : > . /* reset code */
    .systeminit                     : > . /* SystemInit */
    .text.startup                   : > .

    /* Code and constant area (all code and constant sections shall be placed between .osbegincode and .osendcode sections). */
    .osbegincode  ALIGN(0x20)       : > .
    .ostext                         : > .
    .oshook                         : > .
    .osrodata                       : > .
    .syscall                        : > .
    .secinfo                        : > .
    .rodata                         : > .



    .ossrodata                      : > .
    .sapp_c32                       : > .
    .sapp_c16                       : > .
    .sapp_cU                        : > .
    .sapp_c8                        : > .


    .text                           : > .
    .appcode                        : > .
    .ROM.data                       : > .
    .osendcode                      : > . /* for mem protection only */

    /* ------------------------------------ OS stack area ------------------------------------ */
    .osstack      ALIGN(0x20)       : > OsInternalRAM

    /* ------------------------------------ OS application data ------------------------------------ */
/* Begin of the RAM area for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */
/* End of the RAM area for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */

/* Begin of the RAM area #1 for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */
/* End of the RAM area #1 for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */

/* Begin of the RAM area #2 for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */
/* End of the RAM area #2 for applications. Do not edit or delete this comment: it is used by the SysGen for GHS */

    /* -------------------------------------- Default data/bss --------------------------------- */
    .data                           : > .
    .osdata                         : > . /* it is empty */
    .ossdata                        : > .

    . = ALIGN(0x20);
    .sapp_v32_data                  : > .
    .sapp_v16_data                  : > .
    .sapp_vU_data                   : > .
    .sapp_v8_data                   : > .

    /* ------------------------------------ BSS sections ------------------------------------ */
    _bss_start = .;

    .osbss  ALIGN(1K)   CLEAR         : > .
    .ossbss                           : > .

    .bss    ALIGN(0x20) CLEAR         : > .
    .sbss                             : > .

    .sapp_v32_bss ALIGN(0x20) CLEAR   : > .
    .sapp_v16_bss       CLEAR       : > .
    .sapp_vU_bss        CLEAR       : > .
    .sapp_v8_bss        CLEAR       : > .


    _bss_end = .;

    /* ------------------------------------ main stacks section ------------------------------------ */

    .stack_main  ALIGN(16)          : > .


    _Stack_end    = addr(.stack_main);
    _Stack_start  = addr(.stack_main)+sizeof(.stack_main);

    OS_MAIN_STACK_MIN   = _Stack_end;
    OS_MAIN_STACK_MAX   = _Stack_start;

}

