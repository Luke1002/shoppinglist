project(Test)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
# adding the Google_Tests_run target
add_executable(Test_run runAllTests.cpp ShoppingObjectTest.cpp)

# linking Google_Tests_run with DateConverter_lib which will be tested
target_link_libraries(Test_run core)

target_link_libraries(Test_run gtest gtest_main)