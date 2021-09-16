//
// Created by luke1002 on 5/23/21.
//

#include <iostream>
#include <string>
#include <vector>

#include "ShoppingList.h"


ShoppingList::ShoppingList(std::string name) : listName(std::move(name)) {
}

ShoppingList::~ShoppingList() {
    shoppingList.clear();
}

std::string ShoppingList::getListName() const {
    return listName;
}

void ShoppingList::setListName(std::string name) {
    ShoppingList::listName = name;
}

void ShoppingList::addObject(ShoppingObject &object) {
    shoppingList.push_back(object);
}

void ShoppingList::printList() {
    std::cout << listName << std::endl << std::endl;
    for (auto& element : shoppingList) {
        element.printObjectInfo();
    }
}

std::vector<ShoppingObject> &ShoppingList::getShoppingList() {
    return shoppingList;
}
