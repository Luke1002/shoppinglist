#include <iostream>
#include <string>


#include "ShoppingList.h"
#include "ShoppingObject.h"
#include "commands.h"

int main() {
    std::string cmd;
    ShoppingList *currentShoppingList;
    ShoppingObject *currentShoppingObject;
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
            selectlist(savedlists,&currentShoppingList);
        }
        else if (cmd == "selectobject") {
            selectobject(currentShoppingList, &currentShoppingObject);
        }
        else if (cmd == "printshoppinglist") {
            //TODO ADD "printshoppinglist" COMMAND
        }
        else if (cmd == "printobject") {
            //TODO ADD "printobject" COMMAND
        }
        else if (cmd == "checkobject") {
            //TODO ADD "checkobject" COMMAND
        }
        else if (cmd == "uncheckobject") {
            //TODO ADD "uncheckobject" COMMAND
        }
        else if (cmd == "shoppingprogress") {
            //TODO ADD "shoppingprogress" COMMAND
        }
    } while (cmd != "exit" || cmd != "Exit");

    std::cout << "Closing the program..." << std::endl;
    return 0;
}
