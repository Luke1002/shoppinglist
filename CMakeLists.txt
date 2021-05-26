cmake_minimum_required(VERSION 3.19)
project(shoppinglistmanager)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(shoppinglistmanager main.cpp ShoppingObject.cpp ShoppingObject.h ShoppingList.cpp ShoppingList.h commands.cpp commands.h)
