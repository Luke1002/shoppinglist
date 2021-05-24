//
// Created by luke1002 on 5/23/21.
//

#include <iostream>
#include <string>

#include "ShoppingObject.h"

ShoppingObject::ShoppingObject(const std::string name, int number) : objectName(name), objectNumber(number) {

}

ShoppingObject::~ShoppingObject() {

}

const std::string &ShoppingObject::getObjectName() const {
    return objectName;
}

void ShoppingObject::setObjectName(const std::string name) {
    ShoppingObject::objectName = name;
}

int ShoppingObject::getObjectNumber() const {
    return objectNumber;
}

void ShoppingObject::setObjectNumber(int number) {
    ShoppingObject::objectNumber = number;
}

void ShoppingObject::printObjectInfo() {
    std::cout << "Object name: " << objectName << std::endl
              << "Object number: " << objectNumber << std::endl
              << "In the cart: " << inCart << std::endl;
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