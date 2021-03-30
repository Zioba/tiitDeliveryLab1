@echo off
lw1_2sem_tiit_Kozhemyako_Nikita.exe 1 10 1 20 1 30 1 40 4 > factoutput1.txt
fc factoutput1.txt expoutput1.txt > nul
if ERRORLEVEL 1 (echo Wrong answer for Test 1) else (echo Right answer for Test 1)

lw1_2sem_tiit_Kozhemyako_Nikita.exe 1 10 1 20 1 30 1 40 4 2 4 2 4 2 4 2 4 > factoutput2.txt
fc factoutput2.txt expoutput2.txt > nul
if ERRORLEVEL 1 (echo Wrong answer for Test 2) else (echo Right answer for Test 2)

lw1_2sem_tiit_Kozhemyako_Nikita.exe 1 abc > factoutput3.txt
fc factoutput3.txt expoutput3.txt > nul
if ERRORLEVEL 1 (echo Wrong answer for Test 3) else (echo Right answer for Test 3)

lw1_2sem_tiit_Kozhemyako_Nikita.exe abc > factoutput4.txt
fc factoutput4.txt expoutput4.txt > nul
if ERRORLEVEL 1 (echo Wrong answer for Test 4) else (echo Right answer for Test 4)

lw1_2sem_tiit_Kozhemyako_Nikita.exe 4 > factoutput5.txt
fc factoutput5.txt expoutput5.txt > nul
if ERRORLEVEL 1 (echo Wrong answer for Test 5) else (echo Right answer for Test 5)

lw1_2sem_tiit_Kozhemyako_Nikita.exe 4 3 1 10 4 3 1 20 4 3 1 30 4 3 > factoutput6.txt
fc factoutput6.txt expoutput6.txt > nul
if ERRORLEVEL 1 (echo Wrong answer for Test 6) else (echo Right answer for Test 6)

TIMEOUT /t -1
