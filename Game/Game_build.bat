@echo off
@color 7
@echo ====== Build Game

REM ============== Variables ==============
@SET GCC=g++
@SET EXE_NAME=Game.exe
@SET GAME_BUILD_DIR=Build
@SET ENGINE_INCLUDE_PATH=..\Engine\Core\Include
@SET EXTERNAL_INCLUDE_PATH=..\External
@SET SOURCE=^
Src\Core\src\main.cpp ^
Src\Core\src\Game.cpp ^
Src\Core\src\GameCfg.cpp 
SET CFLAGS=^
-std=c++14 ^
-w ^
-ISrc\Core\Include ^
-I..\Engine\Engine\Core ^
-I..\Engine\Engine\Managers ^
-I..\Engine\Engine\Assets ^
-I%EXTERNAL_INCLUDE_PATH% ^
-LLibs 

SET LFLAGS=^
-lopengl32 ^
-lglfw3dll ^
-lEngineLib 

REM ========== Pre build secion ==========
@call mkdir %GAME_BUILD_DIR%
REM /Y - Suppress prompt to confirm overwriting a file.
REM /E - Copy whole Directory.
@call xcopy /Y Libs %GAME_BUILD_DIR%
@call xcopy /Y /E Assets %GAME_BUILD_DIR%\Assets

REM ============ Build secion ============
@echo on
g++ %CFLAGS% %SOURCE% -o %GAME_BUILD_DIR%\%EXE_NAME% %LFLAGS%
@echo.
@echo off
if NOT %errorlevel%==0 (
    SET ERROR_CODE=%errorlevel%
    echo ==== Building GAME - FAILD ==== 
    goto :end
)

:end