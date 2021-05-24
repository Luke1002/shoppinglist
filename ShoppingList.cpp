//
// Created by luke1002 on 5/23/21.
//

#include <iostream>
#include <string>
#include <list>

#include "ShoppingList.h"


ShoppingList::ShoppingList(std::string name) : listName(name) {
}

ShoppingList::~ShoppingList() {
    shoppingList.clear();
}

const std::string &ShoppingList::getListName() const {
    return listName;
}

void ShoppingList::setListName(const std::string &name) {
    ShoppingList::listName = name;
}

void ShoppingList::addObject()
{
    int number;
    std::string name;
    std::cin >> name;
    std::cin >> number;
    shoppingList.emplace_back(name, number);
}

void ShoppingList::printList()
{
    for(auto itr = shoppingList.begin(); itr != shoppingList.end(); ++itr)
    {
        std::cout << "Oggetto: " << (*itr).getObjectName() << std::endl
                  << "Quantità: " << (*itr).getObjectNumber() << std::endl
                  << "Acquistato: ";
        if((*itr).isBought())
        {
            std::cout << "Sì" << std::endl;
        }else
        {
            std::cout << "No" << std::endl;
        }
        std::cout << std::endl;
    }
}
