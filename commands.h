//
// Created by luke1002 on 5/25/21.
//

#ifndef SHOPPINGLISTMANAGER_COMMANDS_H
#define SHOPPINGLISTMANAGER_COMMANDS_H

#include "ShoppingList.h"

void help();

void newlist(std::list<ShoppingList>& listsdb, ShoppingList **currentlist);

void addobject(ShoppingList *currentlist, ShoppingObject **currentobject);

void selectlist(std::list<ShoppingList>& listsdb, ShoppingList** currentlist);

void selectobject(ShoppingList *currentlist, ShoppingObject **currentObject);

void printshoppinglist(ShoppingList *currentlist);

void printobject(ShoppingObject *currentObject);

void checkobject(ShoppingObject *currentObject);

void uncheckobject(ShoppingObject *currentObject);

void shoppingprogress(ShoppingList *currentlist);

void deleteshoppinglist(std::list<ShoppingList>& listsdb, ShoppingList **currentlist);

void removeobject(ShoppingList *currentlist, ShoppingObject **currentobject);


#endif //SHOPPINGLISTMANAGER_COMMANDS_H
