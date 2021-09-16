//
// Created by luke1002 on 5/25/21.
//

#include <iostream>
#include <string>
#include <cmath>
#include<memory>
#include<vector>

#include "commands.h"

void help()
{
    std::cout << "Command list" << std::endl
              << "newlist : create a new shopping list" << std::endl
              << "addobject : add a new object in the current shopping list" << std::endl
              << "selectlist : change current shopping list" << std::endl
              << "selectobject : change current object" << std::endl
              << "checkobject : set current object to \"Bought\"" << std::endl
              << "uncheckobject : set current object to \"To Buy\"" << std::endl
              << "printlist : print current shopping list" << std::endl
              << "printobject : print current object" << std::endl
              << "shoppingprogress : shows selected list progress as percentage" << std::endl
              << "deletelist : delete selected shopping list" << std::endl
              << "removeobject : remove selected object from selected shopping list" << std::endl
              << "help : visualize this help screen" << std::endl
              << "exit : exit the program" << std::endl;
}

void newlist(std::vector<ShoppingList>& listsdb, std::shared_ptr<ShoppingList> &currentList, std::shared_ptr<ShoppingObject> &currentObject, std::istream &input)
{
    std::string name;
    bool nameFound;
    do {
        nameFound = false;
        std::cout << "Insert list name" << std::endl
                  << "Name: ";
        std::getline(input, name);

        for (auto &element : listsdb) {
            if (element.getListName() == name) {
                nameFound = true;
                std::cout << "Name already used for another list." << std::endl
                          << "Please choose a different name" << std::endl;
            }
        }
        if (!nameFound) {
            currentList = std::make_shared<ShoppingList>(name);
            (listsdb).push_back(*currentList);
            currentObject.reset();
        }

    } while (nameFound);
}

void addobject(std::shared_ptr<ShoppingList> &currentList, std::shared_ptr<ShoppingObject> &currentObject, std::vector<std::string> &categoryDb, std::istream &input)
{
    std::string name;
    if (currentList != nullptr) {
        bool nameFound;
        std::cout << "Please enter object name" << std::endl;
        do {
            nameFound = false;
            std::cout << "Name: ";
            std::getline(input, name);
            for (auto element : currentList->getShoppingList()) {
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
            input >> quantity;
            if (!input) {
                std::cout << "Invalid input. Please enter an integer" << std::endl;
                input.clear();
                input.ignore();
            }
            else
            {
                correctValue = true;
            }
        } while (!correctValue);
        input.ignore();
        std::cout << "Please enter object category. Type \"list\" for a list of available categories or \"new\" to create a new category" << std::endl;
        std::string categoryName;
        bool categoryChosen;
        bool categoryFound;
        do {
            categoryChosen = false;
            std::cout << "Category: ";
            std::getline(input, categoryName);
            if(categoryName == "list")
            {
                std::cout << "Available categories: " << std::endl << std::endl;
                for(auto itr : categoryDb)
                {
                    std::cout << itr << std::endl;
                }
            }
            else if(categoryName == "new")
            {
                do {
                    std::cout << "Enter new category name: ";
                    categoryFound = false;
                    std::cout << "Name: ";
                    std::getline(input, name);
                    for (auto element : categoryDb) {
                        if (categoryName == element) {
                            categoryFound = true;
                        }
                    }
                    if(categoryFound)
                    {
                        std::cout << "Name already used for another category." << std::endl
                                  << "Please choose a different name" << std::endl;
                    }
                    else
                    {
                        categoryDb.emplace_back(categoryName);
                        std::cout << "New category successfully added" << std::endl;
                    }
                } while (categoryFound);
            }
            else
            {
                for(auto itr : categoryDb)
                {
                    if(itr == categoryName)
                    {
                        categoryChosen = true;
                    }
                }
                if(!categoryChosen)
                {
                    std::cout << "Category not found. Type \"list\" for a list of available categories or \"new\" to create a new category" << std::endl;
                }
            }
        } while (!categoryChosen);
        currentObject = (std::make_shared<ShoppingObject>(name, static_cast<int>(quantity), categoryName));
        currentList->addObject(*(currentObject));
    } else {
        std::cout << "No shopping list selected: Please select a shopping list first" << std::endl;
    }
}

void selectlist(std::vector<ShoppingList>& listsdb, std::shared_ptr<ShoppingList> &currentList, std::shared_ptr<ShoppingObject> &currentObject, std::istream &input)
{
    int position;
    int x = 0;
    std::string name;
    bool nameFound = false;
    std::cout << "insert name of list to change to" << std::endl;
    std::getline(input, name);
    for (auto itr = listsdb.begin(); itr != listsdb.end() && !nameFound; ++itr) {
        if (name == itr->getListName()) {
            nameFound = true;
            position = x;
        }
        x++;
    }

    if (nameFound) {
        std::shared_ptr<ShoppingList> tempPtr = std::make_shared<ShoppingList>(listsdb.at(position));
        currentList.swap(tempPtr);
        currentObject.reset();
        std::cout << "Selected list successfully changed " << std::endl;
    } else {
        std::cout << "Shopping list not found. Please check the list name spelling" << std::endl;
    }
}

void selectobject(const std::shared_ptr<ShoppingList>& currentList, std::shared_ptr<ShoppingObject> &currentObject, std::istream &input)
{
    int position;
    int x = 0;
    std::string name;

    if(currentList != nullptr)
    {
        std::cout << "insert name of object to change to" << std::endl;
        std::getline(input, name);
        bool nameFound = false;
        for (auto itr = currentList->getShoppingList().begin(); itr != currentList->getShoppingList().end() && !nameFound; ++itr) {
            if (name == itr->getObjectName()) {
                nameFound = true;
                position = x;
            }
            x++;
        }
        if (nameFound) {
            std::shared_ptr<ShoppingObject> tempPtr = std::make_shared<ShoppingObject>(currentList->getShoppingList().at(position));
            currentObject.swap(tempPtr);
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

void checkobject(const std::shared_ptr<ShoppingObject>& currentObject)
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

void uncheckobject(const std::shared_ptr<ShoppingObject>& currentObject)
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

void printshoppinglist(const std::shared_ptr<ShoppingList>& currentList)
{
    if(currentList!= nullptr)
    {
        currentList->printList();
    }
    else
    {
        std::cout << "No shopping list selected: Please select a shopping list first" << std::endl;
    }
}

void printobject(const std::shared_ptr<ShoppingObject>& currentObject)
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

void shoppingprogress(const std::shared_ptr<ShoppingList>& currentList)
{
    if(currentList != nullptr)
    {
        int totalElements = 0;
        int boughtElements = 0;
        for(auto& element : currentList->getShoppingList())
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

void deleteshoppinglist(std::vector<ShoppingList>& listsdb, std::shared_ptr<ShoppingList> &currentList, std::shared_ptr<ShoppingObject> &currentObject)
{
    if(currentList != nullptr)
    {
        bool foundList = false;
        std::vector<ShoppingList>::const_iterator itr;
        for(itr = listsdb.begin(); itr != listsdb.end() && !foundList; ++itr)
        {
            if(currentList->getListName() == itr->getListName())
            {
                foundList = true;
                itr = listsdb.erase(itr);
            }
        }
        if(foundList)
        {
            currentList.reset();
            currentObject.reset();
        }
    }
    else
    {
        std::cout << "No shopping list selected: Please select a shopping list first" << std::endl;
    }
}

void removeobject(const std::shared_ptr<ShoppingList>& currentList, std::shared_ptr<ShoppingObject> &currentObject)
{
    if(currentObject != nullptr)
    {
        bool foundObject = false;
        std::vector<ShoppingObject>& list = currentList->getShoppingList();
        std::vector<ShoppingObject>::const_iterator itr;
        for(itr = list.begin(); itr != list.end() && !foundObject; ++itr)
        {
            if((currentObject)->getObjectName() == (*itr).getObjectName())
            {
                foundObject = true;
                itr = list.erase(itr);
            }
        }
        if(foundObject)
        {
            currentObject.reset();
        }
    }
    else
    {
        std::cout << "No object selected: Please select an object first" << std::endl;
    }
}

void categorylistinit(std::vector<std::string> &categoryDb) {
    categoryDb.emplace_back("Alcoholic drinks");
    categoryDb.emplace_back("Baby products");
    categoryDb.emplace_back("Bakery");
    categoryDb.emplace_back("Beverages");
    categoryDb.emplace_back("Canned foods");
    categoryDb.emplace_back("Clothes");
    categoryDb.emplace_back("Coffee, tea & hot chocolate");
    categoryDb.emplace_back("Cosmetics");
    categoryDb.emplace_back("Dairy products");
    categoryDb.emplace_back("Electrical products");
    categoryDb.emplace_back("Fish & seawood");
    categoryDb.emplace_back("Frozen");
    categoryDb.emplace_back("Grains & pasta");
    categoryDb.emplace_back("Home & kitchen");
    categoryDb.emplace_back("Home baking");
    categoryDb.emplace_back("House-cleaning products");
    categoryDb.emplace_back("Meat, poultry & sausages");
    categoryDb.emplace_back("Newspapers");
    categoryDb.emplace_back("Office supplies");
    categoryDb.emplace_back("Oils");
    categoryDb.emplace_back("Other");
    categoryDb.emplace_back("Personal hygiene");
    categoryDb.emplace_back("Pet supplies");
    categoryDb.emplace_back("Pharmacy");
    categoryDb.emplace_back("Preserves");
    categoryDb.emplace_back("Produce");
    categoryDb.emplace_back("Ready meals");
    categoryDb.emplace_back("Snacks");
    categoryDb.emplace_back("Spices, sauces & condiments");
}
