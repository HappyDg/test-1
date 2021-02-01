if not defined LAUTERBACH_PATH goto defaultDBG
set DBG_PATH=%LAUTERBACH_PATH%
goto startDBG
:defaultDBG
set DBG_PATH=D:\t32
:startDBG
start %DBG_PATH%/bin/windows64/t32marm -c %DBG_PATH%/config.t32,sample1.cmm %DBG_PATH% ../tmp 20001 CORE_0 USB CORE=1
