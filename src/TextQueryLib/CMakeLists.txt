add_library(TextQueryLib SHARED 
    TextQueryLib.cpp
)
target_include_directories(TextQueryLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/TextQueryLib
)

set_target_properties(TextQueryLib PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)