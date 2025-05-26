cmake_minimum_required(VERSION 3.22.1)


# CPP standard
set(CMAKE_CXX_STANDARD 11)
# Build type
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -O3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall")
# clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


project(TextQueryTest)

add_executable(prog src/main.cpp)

add_subdirectory(src/TextQueryLib)
target_link_libraries(prog PRIVATE TextQueryLib)

# 确保可执行文件运行时，操作系统可以找到并加载可执行文件依赖的动态库
if(NOT WIN32)
    # Linux 下可以使用 RPATH
    # 将动态库搜索路径嵌入到可执行文件中，使程序在运行时能够自动找到依赖的共享库
    set_target_properties(prog PROPERTIES
        INSTALL_RPATH "$ORIGIN/src/TextQueryLib"
    )
endif()

if(WIN32)
    # WINDOWS 不支持 INSTALL_RPATH
    # 程序运行时，WINDOWS 按照以下路径搜索动态库
    # 1. 程序所在目录（最推荐）
    # 2. 系统目录（如 C:\Windows\System32）
    # 3. PATH 环境变量 包含的路径
    # 4. 应用程序清单文件（*.manifest）指定的路径

    # 使用 CMake 自定义命令（构建时复制）
    add_custom_command(TARGET prog POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:TextQueryLib>  # DLL 源路径
            $<TARGET_FILE_DIR:prog>      # 可执行文件目录
    )
endif()