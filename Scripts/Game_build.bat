echo ====== Build Engine LIB
SET EXE_NAME=Game.exe

REM ==== BUILD ====
SET SOURCE=^
Game\src\main.cpp

SET CFLAGS=^
-std=c++14 ^
-w 

SET LFLAGS=^
-Isrc ^
-IEngine\includes ^
-Lbuild ^
-lEngineLib

echo on
g++ %CFLAGS% %SOURCE% -o build\%EXE_NAME% %LFLAGS%
@echo off
if NOT %errorlevel%==0 (
    SET ERROR_CODE=%errorlevel%
    echo ==== CREATING GAME - FAILD ==== 
    goto :end
)

:end