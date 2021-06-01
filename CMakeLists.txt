cmake_minimum_required(VERSION 3.19)
project(shoppinglistmanager)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp commands.cpp commands.h ShoppingObject.cpp ShoppingObject.h ShoppingList.cpp ShoppingList.h)

add_executable(shoppinglistmanager ${SOURCE_FILES})
