//
// Created by luke1002 on 5/23/21.
//

#ifndef SHOPPINGLIST_SHOPPINGOBJECT_H
#define SHOPPINGLIST_SHOPPINGOBJECT_H

#include <iostream>
#include <string>

class ShoppingObject {
public:
    ShoppingObject(std::string name, int number);

    virtual ~ShoppingObject();

protected:

private:
    std::string objectName;
    int objectNumber;
    bool inCart;
};


#endif //SHOPPINGLIST_SHOPPINGOBJECT_H
