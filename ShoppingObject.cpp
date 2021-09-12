//
// Created by luke1002 on 5/23/21.
//

#include <iostream>
#include <string>

#include "ShoppingObject.h"

ShoppingObject::ShoppingObject(std::string  name, int number, std::string category) : objectName(std::move(name)), objectQuantity(number), objectCategory(std::move(category)), inCart(false) {

}

ShoppingObject::~ShoppingObject() = default;

std::string ShoppingObject::getObjectName() const {
    return objectName;
}

void ShoppingObject::setObjectName( std::string name) {
    ShoppingObject::objectName = name;
}

unsigned int ShoppingObject::getObjectQuantity()  {
    return objectQuantity;
}

void ShoppingObject::setObjectQuantity(int number) {
    if(number>0)
    {
        objectQuantity = number;
    }
    else if(number == 0)
    {
        objectQuantity = 1;
    }
    else
    {
        objectQuantity = -(number);
    }
}

void ShoppingObject::printObjectInfo() {
    std::cout << "Object: " << getObjectName() << std::endl
              << "Quantity: " << getObjectQuantity() << std::endl
              << "Category: " << getObjectCategory() << std::endl
              << "Bought: ";
    if (inCart) {
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

bool ShoppingObject::isBought()  {
    return inCart;
}

const std::string &ShoppingObject::getObjectCategory() const {
    return objectCategory;
}

void ShoppingObject::setObjectCategory(const std::string &objectTag) {
    ShoppingObject::objectCategory = objectTag;
}