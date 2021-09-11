//
// Created by luke1002 on 5/25/21.
//

#ifndef SHOPPINGLISTMANAGER_COMMANDS_H
#define SHOPPINGLISTMANAGER_COMMANDS_H

#include "ShoppingList.h"

void help();

void newlist(std::list<ShoppingList>& listsdb, std::shared_ptr<ShoppingList> &currentList);

void addobject(std::shared_ptr<ShoppingList> &currentList, std::shared_ptr<ShoppingObject> &currentObject, std::list<std::string> &categoryDb);

void selectlist(std::list<ShoppingList>& listsdb, std::shared_ptr<ShoppingList> &currentList, std::shared_ptr<ShoppingObject> &currentObject);

void selectobject(const std::shared_ptr<ShoppingList>& currentList, std::shared_ptr<ShoppingObject> &currentObject);

void checkobject(const std::shared_ptr<ShoppingObject>& currentObject);

void uncheckobject(const std::shared_ptr<ShoppingObject>& currentObject);

void printshoppinglist(const std::shared_ptr<ShoppingList>& currentList);

void printobject(const std::shared_ptr<ShoppingObject>& currentObject);

void shoppingprogress(const std::shared_ptr<ShoppingList>& currentList);

void deleteshoppinglist(std::list<ShoppingList>& listsdb, std::shared_ptr<ShoppingList> &currentList, std::shared_ptr<ShoppingObject> &currentObject);

void removeobject(const std::shared_ptr<ShoppingList>& currentList, std::shared_ptr<ShoppingObject> &currentObject);

void categorylistinit(std::list<std::string> &categoryDb);


#endif //SHOPPINGLISTMANAGER_COMMANDS_H
