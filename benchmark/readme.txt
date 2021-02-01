************************************************************
AUTOSAR OS/S32K v.4 benchmark
readme.txt

NXP(TM) and the NXP logo are trademarks of NXP
All other product or service names are the property of their respective owners.
Copyright 2017 NXP
All Rights Reserved.

************************************************************
The benchmark for the following derivatives are provided:
- S32K142
- S32K144
- S32K146
- S32K148

The benchmark for S32K is currently set to run with FPU support.

1. Build the executable files:
- Navigate the path to release_oss32kv4/benchmark
- Select the target need to build by setting CHIPS (ex. CHIPS := S32K142) in the compiler_options.mak file
- From Cysgwin Terminal, run command: make compiler=gccarm (or iararm, ghsarm). It is better to run make clean before each build.
Note: we can build separate executable file by navigate to deeper path (ex. benchmark/memory/bcc1/sc1) 

2. Run the tests:
Run all the tests:
   - select the compiler want to test from file all.cmm in benchmark folder (ex. GOSUB execAllTests "ia")
   - check the s32k.cmm in benchmark/common if the option for correct compiler is set (Register.Set R13 CSTACK$$Limit
   or Register.Set R13 _Stack_start)   
   - run all.cmm file in T32
Note: We can run separate test by navigate to deeper path (ex. benchmark/memory/bcc1 and run mbcc1.cmm). 
      In this case we may need to select compiler by setting suff param (ex. &suff="_gh" in benchmark\memory\common\test.cmm)   

3. Test with existing executable files in bin/$target folder (ex. benchmark/memory/bcc1/sc1/bin/S32K142)   
- Copy the executable files from ../bin/$target folder to ../bin folder
- Run test like in step #2 above
