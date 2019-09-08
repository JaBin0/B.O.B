echo ====== Build Engine LIB
SET LIB_NAME=EngineLib.dll

REM ==== BUILD ====
SET SOURCE=^
Engine\src\Engine.cpp

SET CFLAGS=^
-std=c++14 ^
-w ^
-shared ^
-fPIC

SET LFLAGS=^
 -IEngine\includes

@echo on
g++ %CFLAGS% %SOURCE% -o %SCRIPT_DIR%\%LIB_DIR%\%LIB_NAME% %LFLAGS%
@echo off
if NOT %errorlevel%==0 (
    color 4 
    SET ERROR_CODE=%errorlevel%
    echo ==== CREATING DYNAMIC LIB - FAILD ==== 
    goto :end
)

:end