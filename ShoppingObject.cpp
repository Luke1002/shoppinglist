//
// Created by luke1002 on 5/23/21.
//

#include <iostream>
#include <string>
#include <sstream>

#include "ShoppingObject.h"

ShoppingObject::ShoppingObject(std::string name, int number, std::string category) : objectName(std::move(name)), objectCategory(std::move(category)), inCart(false) {
    if (number >= 0) {
        objectQuantity = abs(number);
    } else {
        objectQuantity = abs(number);
    }
}

ShoppingObject::~ShoppingObject() = default;

std::string ShoppingObject::getObjectName() {
    return objectName;
}

void ShoppingObject::setObjectName(std::string name) {
    ShoppingObject::objectName = name;
}

int ShoppingObject::getObjectQuantity() {
    return objectQuantity;
}

void ShoppingObject::setObjectQuantity(int number) {
    if (number >= 0) {
        objectQuantity = number;
    } else {
        objectQuantity = -(number);
    }
}

std::stringstream ShoppingObject::toString() {
    return std::stringstream(
            objectName + "\n" + std::to_string(objectQuantity) + "\n" + objectCategory + "\n");
}

std::string &ShoppingObject::getObjectCategory() {
    return objectCategory;
}

void ShoppingObject::setObjectCategory(std::string objectTag) {
    ShoppingObject::objectCategory = objectTag;
}

bool ShoppingObject::isInCart() const {
    return inCart;
}

void ShoppingObject::setInCart(bool inCart) {
    ShoppingObject::inCart = inCart;
}
