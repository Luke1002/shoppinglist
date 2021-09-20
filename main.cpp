#include <iostream>
#include <string>
#include <memory>
#include <vector>


#include "ShoppingList.h"
#include "commands.h"

int main() {
    std::string cmd;
    std::string currentShoppingList;
    std::vector<std::string> objectCategories;
    categorylistinit(objectCategories);
    std::map<std::string, ShoppingList> savedlists;
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
        } else if (cmd == "newlist") {
            newlist(savedlists, currentShoppingList, std::cin);
            std::cout << std::endl;
        } else if (cmd == "addobject") {
            addobject(savedlists, currentShoppingList, objectCategories, std::cin);
            std::cout << std::endl;
        } else if (cmd == "selectlist") {
            selectlist(savedlists, currentShoppingList, std::cin);
            std::cout << std::endl;
        } else if (cmd == "printlist") {
            printshoppinglist(savedlists, currentShoppingList);
        } else if (cmd == "printobject") {
            printobject(savedlists, currentShoppingList, std::cin);
            std::cout << std::endl;
        } else if (cmd == "checkobject") {
            checkobject(savedlists, currentShoppingList, std::cin);
            std::cout << std::endl;
        } else if (cmd == "uncheckobject") {
            uncheckobject(savedlists, currentShoppingList, std::cin);
            std::cout << std::endl;
        } else if (cmd == "shoppingprogress") {
            shoppingprogress(savedlists, currentShoppingList);
            std::cout << std::endl;
        } else if (cmd == "deletelist") {
            deleteshoppinglist(savedlists, currentShoppingList);
            std::cout << std::endl;
        } else if (cmd == "removeobject") {
            removeobject(savedlists, currentShoppingList, std::cin);
            std::cout << std::endl;
        } else {
            std::cout << "Command not found. Type \"help\" for a list of possible commands" << std::endl;
        }
    } while (cmd != "exit" || cmd != "Exit");

    std::cout << "Closing the program..." << std::endl;
    return 0;
}
