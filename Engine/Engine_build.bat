@echo off
@color 7
@echo ====== Build Engine LIB

REM ============== Variables ==============
@SET GCC=g++
@SET LIB_NAME=EngineLib.dll
@SET SOURCE=^
Engine\Core\Src\Engine.cpp ^
Engine\Managers\Src\ResourceMgr.cpp
@SET CFLAGS=^
-std=c++14 ^
-w ^
-shared ^
-fPIC
@SET LFLAGS=^
-IEngine\Core\Include ^
-IEngine\Managers\Include

REM ============ Build secion ============
@echo on
%GCC% %CFLAGS% %SOURCE% -o Build\%LIB_NAME% %LFLAGS%
@echo.
@echo off

if NOT %errorlevel%==0 (
    color 4 
    SET ERROR_CODE=%errorlevel%
    echo ==== CREATING DYNAMIC LIB - FAILD ==== 
    goto :end
)

:end