//
// Created by luke1002 on 5/23/21.
//

#include <string>
#include <sstream>

#include "ShoppingObject.h"

ShoppingObject::ShoppingObject(std::string &name, int number, std::string &category) : objectName(std::move(name)), objectCategory(std::move(category)), inCart(false) {
        objectQuantity = abs(number);
}

ShoppingObject::~ShoppingObject() = default;


const std::string &ShoppingObject::getObjectName() const {
    return objectName;
}

void ShoppingObject::setObjectName(const std::string &name) {
    ShoppingObject::objectName = name;
}

const std::string &ShoppingObject::getObjectCategory() const {
    return objectCategory;
}

void ShoppingObject::setObjectCategory(const std::string &categoryName) {
    ShoppingObject::objectCategory = categoryName;
}


int ShoppingObject::getObjectQuantity() const{
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

bool ShoppingObject::isInCart() const {
    return inCart;
}

void ShoppingObject::setInCart(bool inCart) {
    ShoppingObject::inCart = inCart;
}