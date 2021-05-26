#include <iostream>
#include <string>


#include "ShoppingList.h"
#include "ShoppingObject.h"
#include "commands.h"

int main() {
    std::string cmd;
    ShoppingList *currentShoppingList = nullptr;
    ShoppingObject *currentShoppingObject = nullptr;
    std::list<ShoppingList> savedlists;
    std::cout << "Shopping List Manager" << std::endl
              << "by Luca Lascialfari" << std::endl
              << std::endl
              << "Type \"help\" to view the list of commands available" << std::endl;
    do {
        std::cout << ">> ";
        std::getline(std::cin, cmd);
        if (cmd == "help") {
            help();
        }
        else if (cmd == "newshoppinglist") {
            newlist(savedlists,&currentShoppingList);
        }
        else if (cmd == "addobject") {
            addobject(currentShoppingList, &currentShoppingObject);
        }
        else if (cmd == "selectshoppinglist") {
            selectlist(savedlists, &currentShoppingList, &currentShoppingObject);
        }
        else if (cmd == "selectobject") {
            selectobject(currentShoppingList, &currentShoppingObject);
        }
        else if (cmd == "printshoppinglist") {
            printshoppinglist(currentShoppingList);
        }
        else if (cmd == "printobject") {
            printobject(currentShoppingObject);
        }
        else if (cmd == "checkobject") {
            checkobject(currentShoppingObject);
        }
        else if (cmd == "uncheckobject") {
            uncheckobject(currentShoppingObject);
        }
        else if (cmd == "shoppingprogress") {
            shoppingprogress(currentShoppingList);
        }
        else if(cmd == "deleteshoppinglist")
        {
            deleteshoppinglist(savedlists, &currentShoppingList, &currentShoppingObject);
        }
        else if(cmd == "removeobject")
        {
            removeobject(currentShoppingList, &currentShoppingObject);
        }
        else
        {
            std::cout << "Command not found. Type \"help\" for a list of possible commands" << std::endl;
        }
    } while (cmd != "exit" || cmd != "Exit");

    std::cout << "Closing the program..." << std::endl;
    return 0;
}
