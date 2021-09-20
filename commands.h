//
// Created by luke1002 on 5/25/21.
//

#ifndef SHOPPINGLISTMANAGER_COMMANDS_H
#define SHOPPINGLISTMANAGER_COMMANDS_H

#include "ShoppingList.h"
#include <memory>

void help();

void newlist(std::map<std::string, ShoppingList>& listsdb, std::string &currentList, std::istream &input);

void addobject(std::map<std::string, ShoppingList> &listsdb, std::string &currentList, std::vector<std::string> &categoryDb, std::istream &input);

void selectlist(std::map<std::string, ShoppingList> &listsdb, std::string &currentList, std::istream &input);

void checkobject(std::map<std::string, ShoppingList> &listsdb, std::string &currentList, std::istream &input);

void uncheckobject(std::map<std::string, ShoppingList> &listsdb, std::string &currentList, std::istream &input);

void printshoppinglist(std::map<std::string, ShoppingList> &listsdb, std::string &currentList);

void printobject(std::map<std::string, ShoppingList> &listsdb, std::string &currentList, std::istream &input);

void shoppingprogress(std::map<std::string, ShoppingList> &listsdb, std::string &currentList);

void deleteshoppinglist(std::map<std::string, ShoppingList>& listsdb, std::string &currentList);

void removeobject(std::map<std::string, ShoppingList> &listsdb, std::string &currentList, std::istream &input);

void categorylistinit(std::vector<std::string> &categoryDb);


#endif //SHOPPINGLISTMANAGER_COMMANDS_H
