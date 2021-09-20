//
// Created by luke1002 on 5/25/21.
//

#include <iostream>
#include <string>
#include <cmath>
#include<memory>
#include<vector>
#include <sstream>

#include "commands.h"

void help() {
    std::cout << "Command list" << std::endl
              << "newlist : create a new shopping list" << std::endl
              << "addobject : add a new object in the selected shopping list" << std::endl
              << "selectlist : change current shopping list" << std::endl
              << "checkobject : set an object to \"Bought\"" << std::endl
              << "uncheckobject : set an object to \"To Buy\"" << std::endl
              << "printlist : print current shopping list" << std::endl
              << "printobject : print an object of selected list" << std::endl
              << "shoppingprogress : shows selected list progress as percentage" << std::endl
              << "deletelist : delete selected shopping list" << std::endl
              << "removeobject : remove an object from selected shopping list" << std::endl
              << "help : visualize this help screen" << std::endl
              << "exit : exit the program" << std::endl;
}

void
newlist(std::map<std::string, ShoppingList> &listsdb, std::string &currentList, std::istream &input) {
    std::string name;
    std::cout << "Insert list name" << std::endl
              << "Name: ";
    std::getline(input, name);
    if (listsdb.find(name) == listsdb.end()) {
        listsdb.insert(std::make_pair(name, ShoppingList(name)));
        currentList = name;
    } else {
        std::cout << "Name already used for another list. Please choose a different name" << std::endl;
    }
}

void
addobject(std::map<std::string, ShoppingList> &listsdb, std::string &currentList, std::vector<std::string> &categoryDb,
          std::istream &input) {
    std::string name;
    ShoppingList &listPtr = listsdb.find(currentList)->second;
    if (!currentList.empty()) {
        bool nameFound;
        std::cout << "Please enter object name" << std::endl;
        do {
            nameFound = false;
            std::cout << "Name: ";
            std::getline(input, name);
            std::unique_ptr<std::map<std::string, ShoppingObject>> list = std::make_unique<std::map<std::string, ShoppingObject>>(
                    listPtr.getShoppingList());
            auto itr = list->find(name);
            if (itr != list->end()) {
                nameFound = true;
                std::cout << "Name already used for another object in the same list." << std::endl
                          << "Please choose itr different name" << std::endl;
            }
        } while (nameFound);
        std::cout << "Please enter quantity. Enter \"0\" to not select a quantity" << std::endl;
        bool correctValue = false;
        int quantity;
        do {
            std::cout << "Quantity: ";
            input >> quantity;
            if (!input) {
                std::cout << "Invalid input. Please enter an integer" << std::endl;
                input.clear();
                input.ignore();
            } else {
                correctValue = true;
            }
        } while (!correctValue);
        input.ignore();
        std::cout
                << "Please enter object category. Type \"list\" for a list of available categories or \"new\" to create a new category"
                << std::endl;
        std::string categoryName;
        bool categoryChosen;
        bool categoryFound;
        do {
            categoryChosen = false;
            std::cout << "Category: ";
            std::getline(input, categoryName);
            if (categoryName == "list") {
                std::cout << "Available categories: " << std::endl << std::endl;
                for (auto itr: categoryDb) {
                    std::cout << itr << std::endl;
                }
            } else if (categoryName == "new") {
                do {
                    std::cout << "Enter new category name: ";
                    categoryFound = false;
                    std::cout << "Name: ";
                    std::getline(input, name);
                    for (auto itr: categoryDb) {
                        if (categoryName == itr) {
                            categoryFound = true;
                        }
                    }
                    if (categoryFound) {
                        std::cout << "Name already used for another category." << std::endl
                                  << "Please choose a different name" << std::endl;
                    } else {
                        categoryDb.emplace_back(categoryName);
                        std::cout << "New category successfully added" << std::endl;
                    }
                } while (categoryFound);
            } else {
                for (auto itr: categoryDb) {
                    if (itr == categoryName) {
                        categoryChosen = true;
                    }
                }
                if (!categoryChosen) {
                    std::cout
                            << "Category not found. Type \"list\" for a list of available categories or \"new\" to create a new category"
                            << std::endl;
                }
            }
        } while (!categoryChosen);
        listPtr.addObject(name, quantity, categoryName);
    } else {
        std::cout << "No shopping list selected: Please select a shopping list first" << std::endl;
    }
}

void selectlist(std::map<std::string, ShoppingList> &listsdb, std::string &currentList,
                std::istream &input) {
    std::string name;
    std::cout << "insert name of list to change to" << std::endl;
    std::getline(input, name);
    if (listsdb.find(name) != listsdb.end()) {
        currentList = listsdb.find(name)->first;
    } else {
        std::cout << "Shopping list not found. Please check the list name spelling" << std::endl;
    }
}

void checkobject(std::map<std::string, ShoppingList> &listsdb, std::string &currentList, std::istream &input) {
    ShoppingList &listPtr = listsdb.find(currentList)->second;
    if (!currentList.empty()) {
        if (!(listPtr.getShoppingList().empty())) {
            std::string name;
            std::cout << "insert name of object to check" << std::endl;
            std::getline(input, name);
            bool success = listPtr.setBought(name, true);
            if (success) {
                std::cout << "Object successfully checked" << std::endl;
            } else {
                std::cout << "Object not found. Please check the object name spelling" << std::endl;
            }
        } else {
            std::cout << "Selected list is empty" << std::endl;
        }

    } else {
        std::cout << "No list has been selected." << std::endl;
    }
}

void uncheckobject(std::map<std::string, ShoppingList> &listsdb, std::string &currentList, std::istream &input) {
    ShoppingList &listPtr = listsdb.find(currentList)->second;
    if (!currentList.empty()) {
        if (!(listPtr.getShoppingList().empty())) {
            std::string name;
            std::cout << "insert name of object to uncheck" << std::endl;
            std::getline(input, name);
            bool success = listPtr.setBought(name, false);
            if (success) {
                std::cout << "Object successfully unchecked" << std::endl;
            } else {
                std::cout << "Object not found. Please check the object name spelling" << std::endl;
            }
        } else {
            std::cout << "Selected list is empty" << std::endl;
        }

    } else {
        std::cout << "No list has been selected." << std::endl;
    }
}

void printshoppinglist(std::map<std::string, ShoppingList> &listsdb, std::string &currentList) {
    ShoppingList &listPtr = listsdb.find(currentList)->second;
    if (!currentList.empty()) {
        std::cout << listPtr.getListName() << std::endl << std::endl;
        std::stringstream objectOutput;
        std::string tmp;
        for (auto itr: listPtr.getShoppingList()) {
            objectOutput = itr.second.toString();
            std::getline(objectOutput, tmp);
            std::cout << "Object: " << tmp << std::endl;
            std::getline(objectOutput, tmp);
            if (tmp != "0") {
                std::cout << "Quantity: " << tmp << std::endl;
            }
            std::getline(objectOutput, tmp);
            std::cout << "Category: " << tmp << std::endl;
            std::getline(objectOutput, tmp);
            std::cout << "Bought: ";
            if (itr.second.isInCart()) {
                std::cout << "Yes";
            } else {
                std::cout << "No";
            }
            std::cout << std::endl << std::endl;
        }
    } else {
        std::cout << "No shopping list selected: Please select a shopping list first" << std::endl;
    }
}

void printobject(std::map<std::string, ShoppingList> &listsdb, std::string &currentList, std::istream &input) {
    ShoppingList &listPtr = listsdb.find(currentList)->second;
    if (!currentList.empty()) {
        if (!(listPtr.getShoppingList().empty())) {
            std::string name;
            std::cout << "insert name of object to print" << std::endl;
            std::getline(input, name);
            std::unique_ptr<std::map<std::string, ShoppingObject>> list = std::make_unique<std::map<std::string, ShoppingObject>>(
                    listPtr.getShoppingList());
            auto itr = list->find(name);
            if (itr != list->end()) {
                std::stringstream objectOutput = listPtr.getShoppingList().find(name)->second.toString();
                std::string tmp;
                std::getline(objectOutput, tmp);
                std::cout << std::endl << "Object: " << tmp << std::endl;
                std::getline(objectOutput, tmp);
                if (tmp != "0") {
                    std::cout << "Quantity: " << tmp << std::endl;
                }
                std::getline(objectOutput, tmp);
                std::cout << "Category: " << tmp << std::endl;
                std::getline(objectOutput, tmp);
                std::cout << "Bought: ";
                if (listPtr.getShoppingList().find(name)->second.isInCart()) {
                    std::cout << "Yes";
                } else {
                    std::cout << "No";
                }
                std::cout << std::endl << std::endl;
            } else {
                std::cout << "Object not found. Please check the object name spelling" << std::endl;
            }
        } else {
            std::cout << "Selected list is empty" << std::endl;
        }

    } else {
        std::cout << "No list has been selected." << std::endl;
    }
}

void shoppingprogress(std::map<std::string, ShoppingList> &listsdb, std::string &currentList) {
    ShoppingList &listPtr = listsdb.find(currentList)->second;
    if (!currentList.empty()) {
        if (!(listPtr.getShoppingList().empty())) {
            int totalElements = 0;
            int boughtElements = 0;
            for (auto &element: listPtr.getShoppingList()) {
                totalElements++;
                if (element.second.isInCart()) {
                    boughtElements++;
                }
            }
            float percentage =
                    (static_cast<float>(boughtElements) * static_cast<float>(100)) / static_cast<float>(totalElements);
            percentage *= 100.00;
            percentage = roundf(percentage);
            percentage /= 100.00;
            std::cout << "Shopping progress: " << percentage << "%" << std::endl;
        } else {
            std::cout << "Selected list is empty" << std::endl;
        }
    } else {
        std::cout << "No shopping list selected: Please select a shopping list first" << std::endl;
    }
}

void deleteshoppinglist(std::map<std::string, ShoppingList> &listsdb, std::string &currentList) {
    ShoppingList &listPtr = listsdb.find(currentList)->second;
    if (!currentList.empty()) {
        listsdb.erase(listPtr.getListName());
        currentList = "";
    } else {
        std::cout << "No shopping list selected: Please select a shopping list first" << std::endl;
    }
}

void removeobject(std::map<std::string, ShoppingList> &listsdb, std::string &currentList, std::istream &input) {
    ShoppingList &listPtr = listsdb.find(currentList)->second;
    if (!currentList.empty()) {
        if (listPtr.getShoppingList().empty()) {
            std::cout << "Selected list is empty" << std::endl;
        } else {
            std::string name;
            std::cout << "insert name of object to delete" << std::endl;
            std::getline(input, name);
            bool success = listPtr.removeObject(name);
            if (success) {
                std::cout << "Object successfully removed" << std::endl;
            } else {
                std::cout << "Object not found. Please check the object name spelling" << std::endl;
            }
        }
    } else {
        std::cout << "No shopping list selected: Please select a shopping list first" << std::endl;
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