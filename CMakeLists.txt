cmake_minimum_required(VERSION 3.15)  # 降低版本要求以提高兼容性
project(atrust_SWPU)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(atrust_SWPU main.cpp)

# 根据不同操作系统设置链接选项
if(WIN32)
    # Windows 平台静态链接
    set(CMAKE_FIND_LIBRARY_SUFFIXES .lib .a)
    # 静态链接 MSVC 运行时库
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    # 对于 MinGW 编译器
    if(MINGW)
        target_link_options(atrust_SWPU PRIVATE -static)
    endif()
elseif(APPLE)
    # macOS 平台 (不支持完全静态链接系统库)
    set(CMAKE_FIND_LIBRARY_SUFFIXES .a .dylib .framework)
    # 仅静态链接非系统库，系统库使用动态链接
else()
    # Linux 平台
    set(CMAKE_FIND_LIBRARY_SUFFIXES .a .so)
    target_link_options(atrust_SWPU PRIVATE
            -static
            -static-libstdc++
            -static-libgcc
    )
endif()
