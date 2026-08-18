cmake_minimum_required(VERSION 3.10)
project(c_education_intermediate C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.c
    src/utils.c
    src/pointers_memory.c
    src/data_structures.c
    src/structs_unions.c
    src/function_pointers.c
    src/bitwise_ops.c
    src/file_io.c
    src/quiz.c
)

add_executable(c_education_intermediate ${SOURCES})

target_include_directories(c_education_intermediate PRIVATE src)
