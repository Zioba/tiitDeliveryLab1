@echo off

(echo.
echo.110000010010010110110100010101111011011111)>Out.txt

(echo.
echo.String is empty)>Out0.txt

@echo off
(echo.
echo.0)>Out1.txt


betaTreeOfHuffman.exe TreeOfHuffman
fc /a Out.txt Text.txt > nul
(echo. -------------------)
if ERRORLEVEL 1 (echo Wrong - 1) ELSE (echo OK - 1)
(echo. -------------------)

betaTreeOfHuffman.exe " "
fc /a Out0.txt Text0.txt > nul
(echo. -------------------)
if ERRORLEVEL 1 (echo Wrong - 2) ELSE (echo OK - 2)
(echo. -------------------)

betaTreeOfHuffman.exe t
fc /a Out1.txt Text1.txt > nul
(echo. -------------------)
if ERRORLEVEL 1 (echo Wrong - 3) ELSE (echo OK - 3)
(echo. -------------------)

cmd /k