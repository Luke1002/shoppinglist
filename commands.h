//
// Created by luke1002 on 5/25/21.
//

#ifndef SHOPPINGLISTMANAGER_COMMANDS_H
#define SHOPPINGLISTMANAGER_COMMANDS_H

#include "ShoppingList.h"
#include <memory>

void help();

void newlist(std::vector<ShoppingList>& listsdb, std::shared_ptr<ShoppingList> &currentList, std::shared_ptr<ShoppingObject> &currentObject, std::istream &input);

void addobject(std::shared_ptr<ShoppingList> &currentList, std::shared_ptr<ShoppingObject> &currentObject, std::vector<std::string> &categoryDb, std::istream &input);

void selectlist(std::vector<ShoppingList>& listsdb, std::shared_ptr<ShoppingList> &currentList, std::shared_ptr<ShoppingObject> &currentObject, std::istream &input);

void selectobject(const std::shared_ptr<ShoppingList>& currentList, std::shared_ptr<ShoppingObject> &currentObject, std::istream &input);

void checkobject(const std::shared_ptr<ShoppingObject>& currentObject);

void uncheckobject(const std::shared_ptr<ShoppingObject>& currentObject);

void printshoppinglist(const std::shared_ptr<ShoppingList>& currentList);

void printobject(const std::shared_ptr<ShoppingObject>& currentObject);

void shoppingprogress(const std::shared_ptr<ShoppingList>& currentList);

void deleteshoppinglist(std::vector<ShoppingList>& listsdb, std::shared_ptr<ShoppingList> &currentList, std::shared_ptr<ShoppingObject> &currentObject);

void removeobject(const std::shared_ptr<ShoppingList>& currentList, std::shared_ptr<ShoppingObject> &currentObject);

void categorylistinit(std::vector<std::string> &categoryDb);


#endif //SHOPPINGLISTMANAGER_COMMANDS_H
