cmake_minimum_required(VERSION 3.19)
project(shoppinglistmanager)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)

set(SOURCE_FILES commands.cpp commands.h ShoppingObject.cpp ShoppingObject.h ShoppingList.cpp ShoppingList.h main.cpp)

add_executable(shoppinglistmanager main.cpp ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
target_link_libraries(shoppinglistmanager core)
