cmake_minimum_required(VERSION 3.5.0)
project(leetcode_cpp VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

foreach(name
    0026_Remove_Duplicates_from_Sorted_Array
    0189_Rotate_Array
    0344_Reverse_String
    0007_Reverse_Integer
    0387_First_Unique_Character_in_a_String
    0237_Delete_Node_in_a_Linked_List
    0019_Remove_Nth_Node_From_End_of_List
    0104_Maximum_Depth_of_Binary_Tree
    0088_Merge_Sorted_Array
    0278_First_Bad_Version
    0070_Climbing_Stairs
    0217_Contains_Duplicate
    0190_Reverse_Bits
    0136_Single_Number
    0242_Valid_Anagram
    0206_Reverse_Linked_List
    0101_Symmetric_Tree
    0053_Maximum_Subarray
    0326_Power_of_Three
    0118_Pascals_Triangle
    0350_Intersection_of_Two_Arrays_II
    0125_Valid_Palindrome
    0066_Plus_One
)
  add_executable(${name} ${name}.cpp)
  target_link_libraries(${name} PRIVATE)
  set_target_properties(${name}
    PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS off
    )
  add_test(
    NAME ${name}
    COMMAND $<TARGET_FILE:${name}>)
endforeach()

include(CPack)
