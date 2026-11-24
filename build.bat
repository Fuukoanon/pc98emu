@echo off

set CXX=g++
set SRC_DIR=Source
set BUILD_DIR=Build
set TARGET=pc98emu.exe

set SDL3_ROOT=C:\Programs for Coding And RE\SDL3\x86_64-w64-mingw32
set SDL3_INCLUDE=%SDL3_ROOT%\include
set SDL3_LIB=%SDL3_ROOT%\lib

if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

%CXX% %SRC_DIR%\*.cc -o "%BUILD_DIR%\%TARGET%" -I"%SDL3_INCLUDE%" -L"%SDL3_LIB%" -lmingw32 -lSDL3

if %errorlevel% neq 0 (
    echo Build failed.
    exit /b %errorlevel%
)

copy /Y "%SDL3_ROOT%\bin\SDL3.dll" "%BUILD_DIR%\"

echo "Done Building"
endlocal