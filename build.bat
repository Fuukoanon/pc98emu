@echo off

set CXX=g++
set SRC_DIR=Source
set BUILD_DIR=BUILD_DIR
set TARGT=pc98emu.exe

set SDL3_ROOT=C:\Programs for Coding And RE\SDL3\x86_64-w64-mingw32
set SDL3_INCLUDE=%SDL3_ROOT%\include
set SDL3_LIB=%SDL3_ROOT%\lib

%CXX% %SRC_DIR%\*.cc -o %BUILD_DIR%\%TARGET_NAME% ^
    -I"%SDL3_INCLUDE%" ^
    -L"%SDL3_LIB%" ^
    -lmingw32 -lSDL3main -lSDL3

if %errorlevel% neq 0 (
    echo Build failed.
    exit /b %errorlevel%
)

copy /Y "%SDL3_ROOT%\bin\SDL3.dll" "%BIN_DIR%\" >nul

echo "Done Building"
endlocal