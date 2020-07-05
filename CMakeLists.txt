cmake_minimum_required(VERSION 3.5)

project(codecov)

add_executable(matrix matrix.h main.cpp)

set_target_properties(matrix PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wall;-Wpedantic;-Wextra"
)