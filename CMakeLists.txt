cmake_minimum_required(VERSION 3.22.1)

project(codeforces)

set(CMAKE_GENERATOR "Unix Makefiles")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER "D:\\Mrming\\DevelopTools\\MSYS2\\ucrt64\\bin\\clang++")

set(CMAKE_BUILD_TYPE "Release")

file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})