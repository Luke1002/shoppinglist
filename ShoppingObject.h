//
// Created by luke1002 on 5/23/21.
//

#ifndef SHOPPINGLIST_SHOPPINGOBJECT_H
#define SHOPPINGLIST_SHOPPINGOBJECT_H

#include <iostream>
#include <string>

class ShoppingObject {
public:
    ShoppingObject(std::string  name, int number, std::string category);

    virtual ~ShoppingObject();

    std::basic_string<char> getObjectName() const;

    void setObjectName(std::string& name);

    unsigned int getObjectQuantity();

    void setObjectQuantity(int number);

    void printObjectInfo();

    void checkTrue();

    void checkFalse();

    bool isBought();

protected:

private:
    std::string objectName;
    unsigned int objectQuantity;
    bool inCart;
    std::string objectCategory;
public:
    const std::string &getObjectCategory() const;

    void setObjectCategory(const std::string &objectTag);
};


#endif //SHOPPINGLIST_SHOPPINGOBJECT_H
