#include <iostream>
#include <string>
#include <memory>
#include <vector>


#include "ShoppingList.h"
#include "commands.h"

int main() {
    std::string cmd;
    std::shared_ptr<ShoppingList> currentShoppingList(nullptr);
    std::shared_ptr<ShoppingObject> currentShoppingObject(nullptr);
    std::vector<std::string> objectCategories;
    categorylistinit(objectCategories);
    std::vector<ShoppingList> savedlists;
    std::cout << "Shopping List Manager" << std::endl
              << "by Luca Lascialfari" << std::endl
              << std::endl
              << "Type \"help\" to view the list of commands available" << std::endl;
    do {
        std::cout << ">> ";
        std::getline(std::cin, cmd);
        std::cout << std::endl;
        if (cmd == "help") {
            help();
        }
        else if (cmd == "newlist") {
            newlist(savedlists, currentShoppingList, currentShoppingObject,std::cin);
            std::cout << std::endl;
        }
        else if (cmd == "addobject") {
            addobject(currentShoppingList, currentShoppingObject, objectCategories, std::cin);
            std::cout << std::endl;
        }
        else if (cmd == "selectlist") {
            selectlist(savedlists, currentShoppingList, currentShoppingObject, std::cin);
            std::cout << std::endl;
        }
        else if (cmd == "selectobject") {
            selectobject(currentShoppingList, currentShoppingObject, std::cin);
            std::cout << std::endl;
        }
        else if (cmd == "printlist") {
            printshoppinglist(currentShoppingList);
        }
        else if (cmd == "printobject") {
            printobject(currentShoppingObject);
            std::cout << std::endl;
        }
        else if (cmd == "checkobject") {
            checkobject(currentShoppingObject);
            std::cout << std::endl;
        }
        else if (cmd == "uncheckobject") {
            uncheckobject(currentShoppingObject);
            std::cout << std::endl;
        }
        else if (cmd == "shoppingprogress") {
            shoppingprogress(currentShoppingList);
            std::cout << std::endl;
        }
        else if(cmd == "deletelist")
        {
            deleteshoppinglist(savedlists, currentShoppingList, currentShoppingObject);
            std::cout << std::endl;
        }
        else if(cmd == "removeobject")
        {
            removeobject(currentShoppingList, currentShoppingObject);
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Command not found. Type \"help\" for a list of possible commands" << std::endl;
        }
    } while (cmd != "exit" || cmd != "Exit");

    std::cout << "Closing the program..." << std::endl;
    return 0;
}
