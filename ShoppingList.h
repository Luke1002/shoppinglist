//
// Created by luke1002 on 5/23/21.
//

#ifndef SHOPPINGLIST_SHOPPINGLIST_H
#define SHOPPINGLIST_SHOPPINGLIST_H

#include <iostream>
#include <string>
#include <vector>

#include "ShoppingObject.h"

class ShoppingList {
public:

    explicit ShoppingList(std::string name);

    virtual ~ShoppingList();

    std::string getListName() const;

    void setListName(std::string name);

    void addObject(ShoppingObject &object);

    void printList();

    std::vector<ShoppingObject> &getShoppingList();

protected:

private:
    std::string listName;
    std::vector<ShoppingObject> shoppingList;
};


#endif //SHOPPINGLIST_SHOPPINGLIST_H
