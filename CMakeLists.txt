cmake_minimum_required(VERSION 3.22.1)


# CPP standard
set(CMAKE_CXX_STANDARD 17)
# 不管是 Debug 还是 Release 都是用同一个 ABI
add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=1)
# Build type
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -O3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall")
# clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(StrVecTest)

enable_testing()

add_subdirectory(src/StrVecLib)
add_subdirectory(test/StrVecTest)