//
// Created by luke1002 on 5/25/21.
//

#include <iostream>
#include <string>
#include <cmath>

#include "commands.h"

void help()
{
    std::cout << "Command list" << std::endl
              << "help : visualize this help screen" << std::endl
              << "newshoppinglist : create a new shopping list" << std::endl
              << "addobject : add a new object in the current shopping list" << std::endl
              << "selectshoppinglist : change current shopping list" << std::endl
              << "selectobject : change current object" << std::endl
              << "printshoppinglist : print current shopping list" << std::endl
              << "printobject : print current object" << std::endl
              << "checkobject : set current object to \"Bought\"" << std::endl
              << "uncheckobject : set current object to \"To Buy\"" << std::endl
              << "shoppingprogress : shows selected list progress as percentage" << std::endl
              << "deleteshoppinglists : delete selected shopping list" << std::endl
              << "removeobject : remove selected object from selected shopping list" << std::endl
              << "exit : exit the program" << std::endl;
}

void newlist(std::list<ShoppingList>& listsdb, ShoppingList** currentlist)
{
    std::string name;
    bool nameFound;
    do {
        nameFound = false;
        std::cout << "Insert list name" << std::endl
                  << "Name: ";
        std::getline(std::cin, name);

        for (auto &element : listsdb) {
            if (element.getListName() == name) {
                nameFound = true;
                std::cout << "Name already used for another list." << std::endl
                          << "Please choose a different name" << std::endl;
            }
        }
        if (!nameFound) {
            (listsdb).emplace_back(name);
            *currentlist = &(listsdb.back());
        }

    } while (nameFound);
}

void addobject(ShoppingList *currentlist, ShoppingObject **currentObject)
{
    std::string name;
    if (currentlist != nullptr) {
        bool nameFound;
        std::cout << "Please enter object name" << std::endl;
        do {
            nameFound = false;
            std::cout << "Name: ";
            std::getline(std::cin, name);
            for (auto &element : currentlist->getShoppingList()) {
                if (name == element.getObjectName()) {
                    nameFound = true;
                    std::cout << "Name already used for another object in the same list." << std::endl
                              << "Please choose a different name" << std::endl;
                }
            }
        } while (nameFound);
        std::cout << "Please enter quantity" << std::endl;
        bool correctValue = false;
        unsigned int quantity;
        do {
            std::cout << "Quantity: ";
            std::cin >> quantity;
            if (!std::cin) {
                std::cout << "Invalid input. Please enter an integer" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
            else
            {
                correctValue = true;
            }
        } while (!correctValue);
        currentlist->addObject(name, static_cast<int>(quantity));
        *currentObject = &(currentlist->getShoppingList().back());
    } else {
        std::cout << "No shopping list selected: Please select a shopping list first" << std::endl;
    }
    std::cin.ignore();
}

void selectlist(std::list<ShoppingList>& listsdb, ShoppingList** currentlist, ShoppingObject **currentObject)
{
    std::string name;
    bool nameFound = false;
    std::cout << "insert name of list to change to" << std::endl;
    std::getline(std::cin, name);
    for (auto itr = listsdb.begin(); itr != listsdb.end(); ++itr) {
        if (name == itr->getListName()) {
            nameFound = true;
            *currentlist = &(*itr);
            *currentObject = nullptr;
        }
    }
    if (nameFound) {
        std::cout << "Selected list successfully changed" << std::endl;
    } else {
        std::cout << "Shopping list not found. Please check the list name spelling" << std::endl;
    }
}

void selectobject(ShoppingList *currentlist, ShoppingObject **currentObject)
{
    std::string name;
    if(currentlist != nullptr)
    {
        std::cout << "insert name of object to change to" << std::endl;
        std::getline(std::cin, name);
        std::list<ShoppingObject> & list = currentlist->getShoppingList();
        bool nameFound = false;
        for (auto itr = list.begin(); itr != list.end(); ++itr) {
            if (name == itr->getObjectName()) {
                nameFound = true;
                *currentObject = &(*itr);
            }
        }
        if (nameFound) {
            std::cout << "Selected object successfully changed" << std::endl;
        } else {
            std::cout << "Object not found. Please check the object name spelling" << std::endl;
        }
    }
    else
    {
        std::cout << "No list has been selected." << std::endl
                  << "Please select a list before trying to select an object" << std::endl;
    }
}

void printshoppinglist(ShoppingList *currentlist)
{
    if(currentlist!= nullptr)
    {
        currentlist->printList();
    }
    else
    {
        std::cout << "No shopping list selected: Please select a shopping list first" << std::endl;
    }
}

void printobject(ShoppingObject *currentObject)
{
    if(currentObject != nullptr)
    {
        currentObject->printObjectInfo();
    }
    else
    {
        std::cout << "No object selected: Please select an object first" << std::endl;
    }
}

void checkobject(ShoppingObject *currentObject)
{
    if(currentObject != nullptr)
    {
        currentObject->checkTrue();
        std::cout << "Object checked" << std::endl;
    }
    else
    {
        std::cout << "No object selected: Please select an object first" << std::endl;
    }
}

void uncheckobject(ShoppingObject *currentObject)
{
    if(currentObject != nullptr)
    {
        currentObject->checkFalse();
        std::cout << "Object unchecked" << std::endl;
    }
    else
    {
        std::cout << "No object selected: Please select an object first" << std::endl;
    }
}

void shoppingprogress(ShoppingList *currentlist)
{
    if(currentlist != nullptr)
    {
        int totalElements = 0;
        int boughtElements = 0;
        for(auto& element : currentlist->getShoppingList())
        {
            totalElements++;
            if(element.isBought())
            {
                boughtElements++;
            }
        }
        float percentage = (static_cast<float>(boughtElements)*static_cast<float>(100))/static_cast<float>(totalElements);
        percentage*=100.00;
        percentage = roundf(percentage);
        percentage/=100.00;
        std::cout << "Shopping progress: " << percentage << "%" << std::endl;
    }
    else
    {
        std::cout << "No shopping list selected: Please select a shopping list first" << std::endl;
    }
}

void deleteshoppinglist(std::list<ShoppingList>& listsdb, ShoppingList **currentlist, ShoppingObject **currentObject)
{
    if(*currentlist != nullptr)
    {
        bool foundList = false;
        std::list<ShoppingList>::const_iterator itr;
        for(itr = listsdb.begin(); itr != listsdb.end() && !foundList; ++itr)
        {
            if((*currentlist)->getListName() == itr->getListName())
            {
                foundList = true;
                listsdb.erase(itr);
            }
        }
        if(foundList)
        {
            (*currentlist) = nullptr;
            (*currentObject) = nullptr;
        }
    }
    else
    {
        std::cout << "No shopping list selected: Please select a shopping list first" << std::endl;
    }
}

void removeobject(ShoppingList *currentlist, ShoppingObject **currentobject)
{
    if(*currentobject != nullptr)
    {
        bool foundObject = false;
        std::list<ShoppingObject>& list = currentlist->getShoppingList();
        std::list<ShoppingObject>::const_iterator itr;
        for(itr = list.begin(); itr != list.end() && !foundObject; ++itr)
        {
            if((*currentobject)->getObjectName() == (*itr).getObjectName())
            {
                foundObject = true;
                list.erase(itr);
            }
        }
        if(foundObject)
        {
            (*currentobject) = nullptr;
        }
    }
    else
    {
        std::cout << "No object selected: Please select an object first" << std::endl;
    }
}