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

std::map<std::string, ShoppingObject> ShoppingList::getShoppingList() {
    return shoppingList;
}

void ShoppingList::setShoppingList(const std::map<std::string, ShoppingObject> &shoppingList) {
    ShoppingList::shoppingList = shoppingList;
}

void ShoppingList::addObject(std::string objectName, int objectQuantity, std::string objectCategory) {
    shoppingList.emplace(objectName, ShoppingObject(objectName, objectQuantity, objectCategory));
}

bool ShoppingList::removeObject(std::string objectName) {
    if (shoppingList.find(objectName) != shoppingList.end()) {
        shoppingList.erase(objectName);
        return true;
    } else {
        return false;
    }
}

bool ShoppingList::setBought(std::string objectName, bool inCart) {
    if (shoppingList.find(objectName) != shoppingList.end()) {
        shoppingList.find(objectName)->second.setInCart(inCart);
        return true;
    } else {
        return false;
    }
}