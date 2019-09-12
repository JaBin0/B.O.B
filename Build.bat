@echo off
@cls
@color 7

REM ============== Variables ==============
@SET ENGINE_DIR=Engine
@SET ENGINE_BUILD=Engine_build.bat
@SET GAME_DIR=Game
@SET GAME_BUILD=Game_build.bat
@SET ERROR_CODE=0
@SET EXE_NAME=
@SET GAME_BUILD_DIR=


@echo === Build Begin:
call cd %ENGINE_DIR%
call %ENGINE_BUILD%
call cd ..

if NOT %ERROR_CODE%==0 (
    color 4 
    echo ==== BUILD FAILD ==== 
    goto :end
)

REM COPY Libs
xcopy /Y %ENGINE_DIR%\Build %GAME_DIR%\Libs

call cd %GAME_DIR%
call %GAME_BUILD%
call cd ..

if NOT %ERROR_CODE%==0 (
    color 4 
    echo ==== BUILD FAILD ==== 
    goto :end
)

:run
@color 2
@echo === BUILD SUCCESS
@echo === RUN ===
@echo.
@call %GAME_DIR%\%GAME_BUILD_DIR%\%EXE_NAME%
@echo. 
@echo === END ===

:end