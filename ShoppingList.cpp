//
// Created by luke1002 on 5/23/21.
//

#include <iostream>
#include <string>
#include <list>

#include "ShoppingList.h"


ShoppingList::ShoppingList(std::string name) : listName(name) {
}

ShoppingList::~ShoppingList() {
    shoppingList.clear();
}