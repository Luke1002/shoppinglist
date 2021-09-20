//
// Created by luke1002 on 5/23/21.
//

#ifndef SHOPPINGLIST_SHOPPINGOBJECT_H
#define SHOPPINGLIST_SHOPPINGOBJECT_H

#include <iostream>
#include <string>

class ShoppingObject {
public:
    ShoppingObject(std::string name, int number, std::string category);

    virtual ~ShoppingObject();

    std::string getObjectName();

    void setObjectName(std::string name);

    int getObjectQuantity();

    void setObjectQuantity(int number);

    bool isInCart() const;

    void setInCart(bool inCart);

    std::string &getObjectCategory();

    void setObjectCategory(std::string objectTag);

    std::stringstream toString();

private:
    std::string objectName;
    int objectQuantity;
    bool inCart;
    std::string objectCategory;
};


#endif //SHOPPINGLIST_SHOPPINGOBJECT_H
