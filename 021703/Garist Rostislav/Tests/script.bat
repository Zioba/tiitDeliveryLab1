@echo off
TIIT1.exe add 2 2 add 3 3 add 4 4 add 1 1 view > output1.txt
fc output1.txt answer1.txt > nul
if ERRORLEVEL 1 (echo Wrong answer 1) else (echo OK 1)

TIIT1.exe 1 2 3 4 5 > output2.txt
fc output2.txt answer2.txt > nul
if ERRORLEVEL 1 (echo Wrong answer 2) else (echo OK 2)

TIIT1.exe add add remove add > output3.txt
fc output3.txt answer3.txt > nul
if ERRORLEVEL 1 (echo Wrong answer 3) else (echo OK 3)

TIIT1.exe adddd 2 2 view > output4.txt
fc output4.txt answer4.txt > nul
if ERRORLEVEL 1 (echo Wrong answer 4) else (echo OK 4)

TIIT1.exe add 2 2 add 3 3 add 1 1 add 9 9 add 5 5 view remove 2 remove 3 view > output5.txt
fc output5.txt answer5.txt > nul
if ERRORLEVEL 1 (echo Wrong answer 5) else (echo OK 5)

TIIT1.exe remove 2 add 2 2 add 9 9 view remove 2 remove 9 view > output6.txt
fc output6.txt answer6.txt > nul
if ERRORLEVEL 1 (echo Wrong answer 6) else (echo OK 6)

TIIT1.exe add 2 2 add 3 3 viewer > output7.txt
fc output7.txt answer7.txt > nul
if ERRORLEVEL 1 (echo Wrong answer 7) else (echo OK 7)

TIIT1.exe view remove 5 remove 6 add 5 5 add 8 9 view > output8.txt
fc output8.txt answer8.txt > nul
if ERRORLEVEL 1 (echo Wrong answer 8) else (echo OK 8)

TIMEOUT /t -1