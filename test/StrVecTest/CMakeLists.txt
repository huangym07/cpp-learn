add_executable(StrVecTest
    StrVecTest.cpp 
)

target_include_directories(StrVecTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../googletest/googletest/include)

target_link_libraries(StrVecTest PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../../googletest/build/lib/libgtest.a
    ${CMAKE_CURRENT_SOURCE_DIR}/../../googletest/build/lib/libgtest_main.a
)

target_link_libraries(StrVecTest PRIVATE StrVecLib)

set_target_properties(StrVecTest PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_test(NAME StrVecTest COMMAND ${CMAKE_BINARY_DIR}/StrVecTest)