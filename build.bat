@echo off
echo ========================================================
echo   Building C Intermediate Education Suite
echo ========================================================

gcc --version >nul 2>&1
if %errorlevel% equ 0 (
    echo [INFO] Found GCC. Compiling...
    gcc -Wall -Wextra -std=c99 -O2 src\main.c src\utils.c src\pointers_memory.c src\data_structures.c src\structs_unions.c src\function_pointers.c src\bitwise_ops.c src\file_io.c src\quiz.c -o c_education_intermediate.exe
    if %errorlevel% equ 0 (
        echo [SUCCESS] Compilation successful!
        echo Running C Intermediate Course Hub...
        c_education_intermediate.exe
    ) else (
        echo [ERROR] Compilation failed!
    )
    goto end
)

clang --version >nul 2>&1
if %errorlevel% equ 0 (
    echo [INFO] Found Clang. Compiling...
    clang -Wall -Wextra -std=c99 -O2 src\main.c src\utils.c src\pointers_memory.c src\data_structures.c src\structs_unions.c src\function_pointers.c src\bitwise_ops.c src\file_io.c src\quiz.c -o c_education_intermediate.exe
    if %errorlevel% equ 0 (
        echo [SUCCESS] Compilation successful!
        echo Running C Intermediate Course Hub...
        c_education_intermediate.exe
    ) else (
        echo [ERROR] Compilation failed!
    )
    goto end
)

echo [WARNING] No GCC or Clang compiler found in PATH.
echo Please install MinGW or LLVM Clang.

:end
pause
