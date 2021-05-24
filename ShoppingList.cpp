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

const std::string &ShoppingList::getListName() const {
    return listName;
}

void ShoppingList::setListName(const std::string &name) {
    ShoppingList::listName = name;
}

void ShoppingList::addObject(std::string name, int number) {
    shoppingList.emplace_back(name, number);
}

void ShoppingList::printList() {
    std::cout << listName << std::endl << std::endl;
    for (auto element : shoppingList) {
        std::cout << "Object: " << element.getObjectName() << std::endl
                  << "Quantity: " << element.getObjectNumber() << std::endl
                  << "Bought: ";
        if (element.isBought()) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
        std::cout << std::endl;
    }
}

std::list<ShoppingObject> &ShoppingList::getShoppingList() {
    return shoppingList;
}
