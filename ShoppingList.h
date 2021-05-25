//
// Created by luke1002 on 5/23/21.
//

#ifndef SHOPPINGLIST_SHOPPINGLIST_H
#define SHOPPINGLIST_SHOPPINGLIST_H

#include <iostream>
#include <string>
#include <list>

#include "ShoppingObject.h"

class ShoppingList {
public:

    explicit ShoppingList(std::string name);

    virtual ~ShoppingList();

    const std::string &getListName() const;

    void setListName(const std::string &name);

    void addObject(const std::string& name, unsigned int number);

    void printList();

    std::list<ShoppingObject> &getShoppingList();

protected:

private:
    std::string listName;
    std::list<ShoppingObject> shoppingList;
};


#endif //SHOPPINGLIST_SHOPPINGLIST_H
