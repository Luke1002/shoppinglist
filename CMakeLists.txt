cmake_minimum_required(VERSION 3.19)
project(shoppinglistmanager)

set(CMAKE_CXX_STANDARD 11)

add_executable(shoppinglistmanager main.cpp ShoppingObject.cpp ShoppingObject.h ShoppingList.cpp ShoppingList.h)
