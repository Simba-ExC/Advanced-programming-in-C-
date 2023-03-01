cmake_minimum_required(VERSION 3.5)

find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
# add_executable(tests test.cpp)
# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# These tests need their own main
add_executable(testOfList list.cpp)
target_link_libraries(testOfList PRIVATE Catch2::Catch2)