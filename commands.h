//
// Created by luke1002 on 5/25/21.
//

#ifndef SHOPPINGLISTMANAGER_COMMANDS_H
#define SHOPPINGLISTMANAGER_COMMANDS_H

#include "ShoppingList.h"

void help();

void newlist(std::list<ShoppingList>& listsdb, ShoppingList **currentlist);

void addobject(ShoppingList *currentlist, ShoppingObject **currentobject);

void selectlist(std::list<ShoppingList> listsdb, ShoppingList** currentlist);

void selectobject(ShoppingList *currentlist, ShoppingObject **currentObject);

void printshoppinglist();

void printobject();

void checkobject();

void uncheckobject();

void shoppingprogress();


#endif //SHOPPINGLISTMANAGER_COMMANDS_H
