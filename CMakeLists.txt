cmake_minimum_required(VERSION 3.31)
project(atrust_SWPU)

set(CMAKE_CXX_STANDARD 20)

add_executable(atrust_SWPU main.cpp)

# 优先使用静态库
set(CMAKE_FIND_LIBRARY_SUFFIXES .a .lib)

# 对于 C 项目
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

# 对于 C++ 项目
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++ -static-libgcc")
