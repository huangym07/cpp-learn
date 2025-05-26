add_library(TextQueryLib SHARED 
    TextQueryLib.cpp
)
target_include_directories(TextQueryLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/TextQueryLib
)