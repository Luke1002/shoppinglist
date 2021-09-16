# 'Google_test' is the subproject name
project(Tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp ShoppingObjectTest.cpp ShoppingListTest.cpp CommandsTest.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core)