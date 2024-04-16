cmake_minimum_required(VERSION 3.5.0)
project(leetcode_cpp VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

add_executable(leetcode_cpp 0026_Remove_Duplicates_from_Sorted_Array.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set_target_properties(leetcode_cpp
    PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS off
    )
    
include(CPack)

enable_testing()

add_test(
    NAME 0026_Remove_Duplicates_from_Sorted_Array
    COMMAND $<TARGET_FILE:leetcode_cpp>)