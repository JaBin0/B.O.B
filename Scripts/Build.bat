echo off
cls
color 7

REM Due to vscode configuration scripts start from the main dirctory,
REM so as a first command script need to move the the right folder.  

SET EXE_NAME=
SET LIB_DIR=libs
SET BUILD_DIR=Build
SET SCRIPT_DIR=Scripts

SET GAME_BUILD=Game_build.bat
SET ENGINE_LIB_BUILD=Engine_build.bat

SET ERROR_CODE=0

echo === Build Begin:
call mkdir %BUILD_DIR%
call mkdir %SCRIPT_DIR%\%LIB_DIR%

call %SCRIPT_DIR%\%ENGINE_LIB_BUILD%
if NOT %ERROR_CODE%==0 (
    color 4 
    echo ==== BUILD FAILD ==== 
    goto :end
)

REM xcopy:
REM   /Y - Suppress prompt to confirm overwriting a file.
xcopy /Y %SCRIPT_DIR%\%LIB_DIR% %BUILD_DIR%

call %SCRIPT_DIR%\%GAME_BUILD%
if NOT %ERROR_CODE%==0 (
    color 4 
    echo ==== BUILD FAILD ==== 
    goto :end
)

xcopy /E /Y Assets %BUILD_DIR%\Assets

color 2
echo === BUILD SUCCESS
:run
REM ==== RUN PROGRAM ====
cd %BUILD_DIR%
echo === RUN
echo.
%EXE_NAME%
echo === END

:end