//
// Created by luke1002 on 5/23/21.
//

#ifndef SHOPPINGLIST_SHOPPINGLIST_H
#define SHOPPINGLIST_SHOPPINGLIST_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "ShoppingObject.h"

class ShoppingList {
public:

    explicit ShoppingList(std::string name);

    virtual ~ShoppingList();

    std::string getListName() const;

    void setListName(std::string name);

    std::map<std::string, ShoppingObject> getShoppingList();

    void setShoppingList(const std::map<std::string, ShoppingObject> &shoppingList);

    void addObject(std::string objectName, int objectQuantity, std::string objectCategory);

    bool removeObject(std::string objectName);

    bool setBought(std::string objectName, bool inCart);

private:
    std::string listName;
    std::map<std::string, ShoppingObject> shoppingList;
};


#endif //SHOPPINGLIST_SHOPPINGLIST_H
