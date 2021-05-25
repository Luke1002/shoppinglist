//
// Created by luke1002 on 5/23/21.
//

#include <iostream>
#include <string>
#include <utility>

#include "ShoppingObject.h"

ShoppingObject::ShoppingObject(std::string  name, int number) : objectName(std::move(name)), objectQuantity(number), inCart(false) {

}

ShoppingObject::~ShoppingObject() = default;

const std::string &ShoppingObject::getObjectName() const {
    return objectName;
}

void ShoppingObject::setObjectName(const std::string& name) {
    ShoppingObject::objectName = name;
}

unsigned int ShoppingObject::getObjectQuantity() const {
    return objectQuantity;
}

void ShoppingObject::setObjectQuantity(int number) {
    ShoppingObject::objectQuantity = number;
}

void ShoppingObject::printObjectInfo() const {
    std::cout << "Object: " << getObjectName() << std::endl
              << "Quantity: " << getObjectQuantity() << std::endl
              << "Bought: ";
    if (isBought()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    std::cout << std::endl;
}

void ShoppingObject::checkTrue() {
    inCart = true;
}

void ShoppingObject::checkFalse() {
    inCart = false;
}

bool ShoppingObject::isBought() const {
    return inCart;
}