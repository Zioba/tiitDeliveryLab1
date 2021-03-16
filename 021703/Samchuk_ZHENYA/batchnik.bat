@echo off
cd C:\tests\
touch test_push_back.txt
touch test_push_front.txt
touch test_pop_front.txt
touch test_pop_back.txt
echo INITIAL DEQUE - 3 2 2 4
echo push front 4
C:\Users\ASUS\source\repos\DQ\Debug\DQ.exe push_front 4 > test_push_front.txt | type test_push_front.txt
fc test_push_front.txt test_push_front_RES.txt
if not ERRORLEVEL 1 echo PUSH FRONT FUNCTION TEST PASSED
if ERRORLEVEL 1 echo FAIL
echo.
echo push_back 5
C:\Users\ASUS\source\repos\DQ\Debug\DQ.exe push_back 5 > test_push_back.txt | type test_push_back.txt
fc test_push_back.txt test_push_back_RES.txt
if not ERRORLEVEL 1 echo PUSH BACK FUNCTION TEST PASSED SUCCESSFULLY
if ERRORLEVEL 1 echo FAIL
echo.
echo pop_front 
C:\Users\ASUS\source\repos\DQ\Debug\DQ.exe pop_front > test_pop_front.txt | type test_pop_front.txt
fc test_pop_front.txt test_pop_front_RES.txt
if not ERRORLEVEL 1 echo POP FRONT FUNCTION TEST PASSED SUCCESSFULLY
if ERRORLEVEL 1 echo FAIL
echo.
echo pop_back 
C:\Users\ASUS\source\repos\DQ\Debug\DQ.exe pop_back > test_pop_back.txt | type test_pop_back.txt
fc test_pop_back.txt test_pop_back_RES.txt
if not ERRORLEVEL 1 echo POP BACK FUNCTION TEST PASSED SUCCESSFULLY
if ERRORLEVEL 1 echo FAIL
echo.
pause





