//
// Created by luke1002 on 5/23/21.
//

#include <iostream>
#include <string>
#include <list>
#include <utility>

#include "ShoppingList.h"


ShoppingList::ShoppingList(std::string name) : listName(std::move(name)) {
}

ShoppingList::~ShoppingList() {
    shoppingList.clear();
}

std::string ShoppingList::getListName() const {
    return listName;
}

void ShoppingList::setListName(std::string &name) {
    ShoppingList::listName = name;
}

void ShoppingList::addObject(std::string& name, unsigned int number) {
    shoppingList.emplace_back(name, number);
}

void ShoppingList::printList() {
    std::cout << listName << std::endl << std::endl;
    for (auto& element : shoppingList) {
        element.printObjectInfo();
    }
}

std::list<ShoppingObject> &ShoppingList::getShoppingList() {
    return shoppingList;
}
