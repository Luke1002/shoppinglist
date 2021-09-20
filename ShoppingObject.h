//
// Created by luke1002 on 5/23/21.
//

#ifndef SHOPPINGLIST_SHOPPINGOBJECT_H
#define SHOPPINGLIST_SHOPPINGOBJECT_H

#include <iostream>
#include <string>

class ShoppingObject {
public:
    ShoppingObject(std::string &name, int number, std::string &category);

    virtual ~ShoppingObject();

    const std::string &getObjectName() const;

    void setObjectName(const std::string &objectName);

    const std::string &getObjectCategory() const;

    void setObjectCategory(const std::string &objectCategory);

    int getObjectQuantity() const;

    void setObjectQuantity(int number);

    bool isInCart() const;

    void setInCart(bool inCart);

    std::stringstream toString();

private:
    std::string objectName;
    int objectQuantity;
    bool inCart;
    std::string objectCategory;
};


#endif //SHOPPINGLIST_SHOPPINGOBJECT_H
