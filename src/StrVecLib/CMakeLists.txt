add_library(StrVecLib SHARED
    StrVecLib.cpp
)

target_include_directories(StrVecLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/StrVecLib
)

set_target_properties(StrVecLib PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)