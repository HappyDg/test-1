*******************************************************************************
NXP AUTOSAR OS/S32K v.4.0 RTM RELEASE
Build 4.0.98  29 Sep. 2017
readme.txt
NXP(TM) and the NXP logo are trademarks of NXP
All other product or service names are the property of their respective owners.
Copyright 2017 NXP
*******************************************************************************

This package contains NXP AUTOSAR OS/S32K v.4.0 RTM Release, build 4.0.98.

The product is developed according to the documents:
- AUTOSAR Specification of Operating System V5.0.0 R4.0 Rev 3
- Specification of ECU Configuration V3.2.0 R4.0 Rev 3
- Specification of Standard Types V1.3.0 R4.0 Rev 1
- OSEK/VDX Operating System, Version 2.2.3, 17 Feb 2005
- OSEK/VDX System Generation, OIL: OSEK Implementation
  Language, Version 2.5, 1 July 2004


The product implements OSEK Run Time Interface (ORTI)
according to the documents:
- OSEK/VDX OSEK Run Time Interface (ORTI) Part A:
  Language Specification Version: 2.2, 14 November 2005
- OSEK/VDX OSEK Run Time Interface (ORTI) Part B:
  OSEK Objects and Attributes Version 2.2, 25 November 2005

Release Specifics:
==================

This build includes direct support of the following derivatives:
- S32K148 (Maskset 0N20V)
- S32K146 (Maskset 0N73V)
- S32K144 (Maskset 0N57U)
- S32K142 (Maskset 0N33V)

AUTOSAR OS Functional test suites were executed on Windows 7 with:
- SCH 28767 REV B board with SCH-29559 REV C1 daughter card (S32K148 and S32K146).
- SCH 28767 REV B board with SCH-28768 REV B1 daughter card (S32K144 and S32K142).

This build targets SC1.

It is strongly recommended that the following compiler/versions are used:

- GNU Tools for ARM Embedded Processors: Gcc Compiler 4.9.3 20150529 (release) [ARM/embedded-4_9-branch revision 224288]
- GHS Compiler for ARM 2015.1.4
- IAR Compiler V7.50.3

Compiler Options:
==================
The compiler, assembler, linker options supported in this release are listed
in the technical reference manual in the installation directory at
doc\AUTOSAR_OSS32K_TR.pdf

About this document
==================
This document contains additional information about the product.
The notes presented are the latest available.

The following topics are covered:

1. Installation
2. Support Information
3. Development hardware and software recommendations
4. Tresos plugin
5. What's new?
6. Known problems
7. Additional Information
8. Release History


1. Installation

1.1 Installation and license file

Please check the NXP Support website for new versions and updates (see
section 2 for customer support information).

Installation of Standard Software Core and System Generator are protected with
FLEXlm.

To get the installation decryption key please contact NXP support.

1.2. Installation instructions

To setup NXP AUTOSAR OS/S32K 4.0 RTM Release, Build 4.0.98 on your hard
disk follow the steps below.

1.2.1. Installer execution

Run the S32K_AUTOSAR_OS_4_0_98_RTM_1_0_0.exe program.

1.2.2. Preparing for installation

It is strongly recommended to close all other programs and login as
Administrator before installation. It helps to avoid an access error during
system icons installation and updating Windows Registry.

NOTES: 1. The full NXP AUTOSAR OS/S32K file set takes about 30 MB of
          disk space.
       2. About 60 MB of disk space is required for the temporary files during
          installation.
       3. It is required to install NXP AUTOSAR OS/S32K into the
          directory without spaces. (Do not install AUTOSAR OS in a directory
          like "Program Files").

1.2.3. Select directories

Target Directory is a directory for AUTOSAR OS source files, user documentation
and platform specific system generator files. It is mandatory to select
directory names without spaces as it is specified by AUTOSAR.

1.2.4. Select components which you want to install

You can choose Custom installation and select NXP AUTOSAR OS components
which have to be installed in Custom Installation dialog box. By default all
components are selected.

1.2.5. Choose the tools (compilers and Tresos) to be used with the OS

It is recommended to enter the paths to the installation directories of the
tools which the installer requires. Otherwise, after the installation, manual
setup of the tools will be necessary for the tools to work correctly with the
installed AUTOSAR OS project.

1.2.6. Follow the prompts and instructions of the installation program.

1.2.7. The installation program copies to the target directory all needed
       files. The directory tree is described in the file filelist.txt.

NOTE: Installation of Adobe Acrobat Reader 5.0 or later is required to view
      the NXP AUTOSAR OS/S32K User's Manual and Technical Reference.

1.2.8. Properly locate the license file

NXP AUTOSAR OS and System Generator license file "license.dat"
shall be located on your hard disk in the following folder:

    <Target Directory>\S32K_AUTOSAR_OS_4_0_98_RTM_1_0_0.exe\ssc\bin\generator

Note: Installation program copies license file given for source code feature
into the above folders during the product installation. It is recommended to
use a single license file containing source code and all other features used by
System Generator.

1.3. NXP AUTOSAR OS/S32K Uninstallation

To uninstall NXP AUTOSAR OS/S32K use the 'NXP AUTOSAR OS/S32K
v.4.0, build 4.0.98' item of the Add/Remove Programs module of the Windows
Control Panel.


2. Support Information

To order NXP products or literature, consult your local sales
representative.

For technical support please use the following Web address:
    http://www.nxp.com/support

To see the list of current support phone numbers under the section labelled
"Support" click on the link labelled "Contact Us".


3. Development hardware and software recommendations

3.1. Software requirements

The PC has to work under Windows XP/7 during NXP AUTOSAR OS installation.

The makefiles provided with OS are written for GNU make v.3.81. Higher versions
of GNU make are not supported.

The CygWin package with make utility shall be properly installed and path to
CygWin binaries shall be in the PATH variable.

NXP AUTOSAR OS SysGen requires Java Runtime Environment JRE 6.0 installed
on your computer. The JRE can be downloaded from the following URL:

http://www.oracle.com/technetwork/java/javasebusiness/downloads/java-archive-downloads-javase6-419409.html


3.2. Target hardware requirements

The sample applications can be executed on the following boards:
- 700-28767 REV A board with 700-28768 REV A daughter card.
- 700-28767 REV A board with 700-29559 RevX2 daughter card.

4. Tresos plugin

The os_ts folder contains EB tresos Studio EB tresos Studio 21.0.0 b160607-0933
configuration plugins for OS/S32K and configuration project samples for OS
module. The plugins and samples have their own "readme.txt" files describing
some aspects of their installation.

For any questions about Tresos usage, details about Tresos installation and
configuration please refer to EB tresos Studio documentation.


5. What's new?

  NXP AUTOSAR OS/S32K v.4.0 RTM, build 4.0.98
  - This is the RTM release of NXP AUTOSAR OS v.4.0 for S32K family.
  - This release incorporates all the work done in the previous 4.0.93 BETA release.

  The following CRs have been implemented:

    ASROS-1779    [OS] Extract code for S32K RTM 98
    ASROS-1739    [OSCODE] Add floating point support for platforms with ARM Cortex M cores
    ASROS-1458    [OSCODE] Check mem.sh and fix if needed
    ASROS-1510    [OSCODE] fix IAR compiler specific code for ARM
    ASROS-1784    [SG] Add floating point support for ARM platforms
    ASROS-1802    [SG] Fix floating point support for ARM platforms option per task/isr
    ASROS-1778    [SG] SG creates multiple definitions for mem area in linker file of IAR on S32K platform
    ASROS-1384    [SG] Sysgen expects Prescaler and Modulo for SYSTICK timer module
    ASROS-1776    [SG] update for S32Kv4_4.0.98_RTM
    ASROS-1834    [SG] Update stacksize for ISR and TASK when Floating point enabled
    ASROS-1785    [PLUGIN] Add floating point support for platforms with ARM Cortex M cores
    ASROS-1808    [PLUGIN] Fix plugin support floating point for s32k
    ASROS-1777    [PLUGIN] update for S32Kv4_4.0.98_RTM
    ASROS-1854    [PLUGIN] Update tresos sample by import sample1.epc and sample1_fpu.epc
    ASROS-1689    [SAMPLE] Improve sample for s32k
    ASROS-1685    [SAMPLE] The sample should run from flash
    ASROS-1672    [BENCHMARK] Draft version of S32K's benchmark
    ASROS-1789    [SYSTEST] Create test case for testing floating point unit
    ASROS-1795    [SYSTEST] Support systest run on flash in S32K
    ASROS-1837    [GHS] [S32K]Possible incorrect stack restoration when task exits without TerminateTask or ChainTask
                  - GHS compiler tries to optimize speed by reordering instructions,
                  but the OS explicit stack switching might lead to incorrect results.


6. Known problems/limitations

    ASROS-1845                   [BENCHMARK] Add benchmark for S32K without Floating point support
    ASROS-1761                   [GHS] Possible undesirable interraction between stack switching at task
                                 switch and the compiler optimizations
                                 - GHS compiler tries to optimize speed by reordering instructions,
                                 but the OS explicit stack switching might lead to incorrect results.
    ASROS-1492/ENGR00382032      [ALL] Add support for LPIT 32 bit timer in S32K
    ASROS-1051/ENGR00325705      [SG] Fails to correctly detect license if the path to
                                 license.dat contains '@'
    ASROS-1193/ENGR00346396      [ALL] Source files do not contain the trademark related
                                 and disclaimer lines in the copyright header

7. Additional Information

7.1 NXP AUTOSAR OS Samples

The Sample applications delivered with the NXP AUTOSAR OS should help users to
learn how to use the OS. There is one sample application for SC1.

The following environment variables must be set in order to compile the sample application:

GCCARM_TOOLCHAIN_PATH   - points to the GCC compiler root directory, eg. "c:/tools/GCC_4.9_2015q3"
GCCARM_TOOLCHAIN_PREFIX - contains the tool chain prefix,            eg. "arm-none-eabi"

COMP_201514_PATH        - points to the GHS compiler root directory  eg. "c:/tools/ghs_arm_201514/comp_201514"

IARARM_7503_PATH        - points to the IAR compiler root directory  eg. "c:/tools/IAR_7503/arm"

8. Release History

NXP AUTOSAR OS/S32K v.4.0 RTM RELEASE, build 4.0.98
- This release, see "What's new" section

NXP AUTOSAR OS/S32K v.4.0 BETA RELEASE, build 4.0.93
- The following CRs have been implemented:
    ENGR00388888    [OSCODE] Support new hardware FTM 4 5 6 7
    ENGR00388905    [OSCODE] Update the vector table and startup code according the S32K reference manual Rev. 3
    ENGR00388973    [OSCODE] Wrong value for OSSTACKBOTTOM and OSSTACKTOP on the IAR compiler
    ENGR00380089    [OSCODE] Add support for IAR stack placement
    ENGR00387915    [SG] max IrqNumber should be 162 instead of 127
    ENGR00388879    [SG] Introduce support for FTM 4,5,6,7
    ENGR00388915    [SG] Sysgen generates wrong memory region (GHS syntax) in IAR linker script
    ENGR00389000    [SG] Fixed code generation for OsSecondsPerTick
    ENGR00387918    [PLUGIN] max IrqNumber should be 162 instead of 127
    ENGR00388883    [PLUGIN] Introduce support for FTM4,5,6,7 and tresos 21

Freescale AUTOSAR OS/S32K v.4.0 CODE_DROP3, build 4.0.82
- The following CRs have been implemented:
    [OSCODE]    Updated in order to fix the reported issue to IAR : CALL 576889s_IAR
                The OS can now be compiled with optimizations turned on.
    [PLUGIN]    The Tresos plugin was updated to support both "ARM" and "Cortex-M"
                architectures.

Freescale AUTOSAR OS/S32K v.4.0 CODE_DROP2, build 4.0.82
- The second code drop adding support for S32K CUT2.0.

Freescale AUTOSAR OS/S32K v.4.0 CODE_DROP1, build 4.0.82
- This is the first code drop of Freescale AUTOSAR OS v.4.0 for S32K family.

Freescale AUTOSAR OS/S32K v.4.0 EARLY ACCESS RELEASE, build 4.0.82
- The first EAR of Freescale AUTOSAR OS v.4.0 for S32K family.
- The following CRs have been implemented:
    ENGR369550 | [Plugin] Wrong Architecture for S32K in the Tresos plugin
    ENGR371123 | [INSTALLER] Create installer for S32K 4.0.82
    ENGR371138 | [DOC] Create documentation for S32K 4.0.82 EAR release
