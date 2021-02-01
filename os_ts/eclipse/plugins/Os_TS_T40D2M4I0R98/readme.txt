************************************************************
AUTOSAR OS/S32K v.4.0 RTM
build 4.0.98
TresosECU plugin readme.txt

NXP(TM) and the NXP logo are trademarks of NXP.
All other product or service names are the property of their respective owners.
(C) Freescale Semiconductor, Inc. 2008-2016
Copyright 2017 NXP

************************************************************


The Os_TS_T40D2M4I0R98 directory contains the configuration plugin for S32K14X.

The Os_TS_T40D2M4I0R98 directory contains the following subdirectories and files:

autosar\                       ; OS configuration directory
autosar\Os.epd                 ; OS configuration file

config                         ; TresosECU OS plugin configuration directory
config\Os.xdm                  ; TresosECU OS plugin configuration file

make
make\os_defs.mak               ; AUTOSAR OS defines makefile
make\os_rules.mak              ; AUTOSAR OS rules makefile

META-INF                       ; TresosECU OS plugin manifest directory
META-INF\MANIFEST.MF           ; TresosECU OS plugin manifest file
META-INF\cryptomanifest.mf     ; TresosECU OS plugin cryptomanifest (for signed plugin)
META-INFf\cryptomanifestsig.mf ; TresosECU OS plugin cryptosignature (for signed plugin)

anchors.xml                    ; TresosECU OS plugin help definition file
plugin.xml                     ; TresosECU OS plugin declaration file
readme.txt                     ; this file


        INSTALLATION

For using this directory with TresosECU, please follow the steps below:

1) Create a text file with the extension ".link" into the TresosECU 
installation in a folder called "links" 
(e.g. <MyTresosIntallation>\links\Os.link)

2) Put the following text in the "Os.link" file:
"path=<MyDirectoryPath>/<MyDirectoryName>", please make sure the path is
described with forward slashes.

 3) If you change the installation path, please don't forget that it
 should be
 "<NewDirectoryPath>/<NewDirectoryName>/eclipse/plugins/Os_TS_T40D2M4I0R98"

 For more detail information about plugins installation please refer to
 original eclipse documentation:  
 http://www.ibm.com/developerworks/opensource/library/os-ecfeat/
 
       FUNCTIONALITY RESTRICTIONS

This plugin has been tested with Tresos 21.0.0 b160607-0933.

       KNOWN PROBLEMS

Os_TS_T40D2M4I0R98\plugin.xml is prepared in such a way,
that Tresos 21.0.0 b160607-0933 can run SysGen (Tresos External Generator applicable to Os) for created EPC-file.
The command line in Os_TS_T40D2M4I0R98\plugin.xml contains SysGen call applicable
for SC1 and SC2.
To apply SysGen for SC3 and SC4, the user has to modify in Os_TS_T40D2M4I0R98\plugin.xml line:
     value="${pluginPath}\..\..\..\..\ssc\bin\generator\sg.exe  ${outputDir}\epc\project.epc"/>
into
     value="${pluginPath}\..\..\..\..\ssc\bin\generator\sg.exe  -L <your-path-to-LCF-input> -M <your-path-to-LCF-output> ${outputDir}\epc\project.epc"/>


There is a number of inconsistencies between AUTOSAR SWS and XML specifications,
which have been fixed in Os.bmd(epd) file:

-   The SysGen follows the AUTOSAR_SWS_OS specification in part of OIL, which
    requires that some parameters have to be set to AUTO if don't specify them.
    But XML does not allow "AUTO" for integer parameters. In such situation
    you may need to "switch of" this parameter, if multiplicity tag allows.
    The Sysgen will interpret this parameter as "AUTO".
