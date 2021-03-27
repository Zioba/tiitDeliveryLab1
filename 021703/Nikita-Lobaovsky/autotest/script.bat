@echo off
MainProject.exe build 4 1 2 3 4 view > output1.txt
fc output1.txt input1.txt > nul
if ERRORLEVEL 1 (echo Error Build - 1) ELSE (echo Ok Build - 1)  
MainProject.exe build 5 4 2 3 5 6 view > output2.txt
fc output2.txt input2.txt > nul
if ERRORLEVEL 1 (echo Error Build - 1) ELSE (echo Ok Build - 1)  
MainProject.exe build 5 4 2 3 5 6 add 0 4 5 view > output3.txt
fc output3.txt input3.txt > nul
if ERRORLEVEL 1 (echo Error Add - 3) ELSE (echo Ok Add - 3)
MainProject.exe build 7 4 2 3 5 6 8 9 add 2 5 2 view > output4.txt
fc output4.txt input4.txt > nul
if ERRORLEVEL 1 (echo Error Add - 3) ELSE (echo Ok Add - 3)
MainProject.exe build 5 8 1 2 5 3 sum 1 4 > output5.txt
fc output5.txt input5.txt > nul
if ERRORLEVEL 1 (echo Error Sum - 5) ELSE (echo Ok Sum - 5)
MainProject.exe build 10 4 1 8 5 3 7 2 9 10 6 sum 2 7 > output6.txt
fc output6.txt input6.txt > nul
if ERRORLEVEL 1 (echo Error Sum - 5) ELSE (echo Ok Sum - 5)
TIMEOUT /t -1