#include <iostream>
#include <string>


#include "ShoppingList.h"
#include "ShoppingObject.h"

int main() {
    std::string cmd;
    ShoppingList* currentShoppingList;
    ShoppingObject* currentShoppingObject;
    std::list<ShoppingList> savedlists;
    std::cout << "Shopping List Manager" << std::endl
              << "by Luca Lascialfari" << std::endl
              << std::endl
              << "Type \"help\" to view the list of commands available" << std::endl;
    do
    {
        std::cout << ">> ";
        std::getline(std::cin, cmd);
        if(cmd == "help")
        {
            std::cout << "Command list" << std::endl
                      << "help : visualize this help screen" << std::endl
                      << "newshoppinglist : create a new shopping list" << std::endl
                      << "addobject : add a new object in the current shopping list" << std::endl
                      << "selectshoppinglist : change current shopping list" << std::endl
                      << "selectobject : change current object" << std::endl
                      << "printshoppinglist : print current shopping list" << std::endl
                      << "printobject : print current object" << std::endl
                      << "checkobject : set current object to \"Bought\"" << std::endl
                      << "uncheckobject : set current object to \"Not bought\"" << std::endl
                      << "shoppingprogress : " << std::endl
                      << "exit : exit the program" << std::endl;
        }
        else if(cmd == "newshoppinglist")
        {
            std::string name;
            bool isNameUsed = false;
            do
            {
                isNameUsed = false;
                std::cout << "Insert list name" << std::endl
                          << "Name: ";
                std::getline(std::cin, name);
                std::cout << name << std::endl;

                for(auto& element : savedlists)
                {
                    if (element.getListName() == name)
                    {
                        isNameUsed = true;
                    }
                }
                if(isNameUsed)
                {
                    std::cout << "Name already used for another list." << std::endl << "Please choose a different name" << std::endl;
                }
                else
                {
                    savedlists.emplace_back(name);
                    currentShoppingList = &(savedlists.back());
                }

            }while(isNameUsed);
        }
        else if(cmd == "addobject")
        {
            std::cout << "Development in progress..." << std::endl;
        }
        else if(cmd == "selectshoppinglist")
        {
            std::cout << "Development in progress..." << std::endl;
        }
        else if(cmd == "selectobject")
        {
            std::cout << "Development in progress..." << std::endl;
        }
        else if(cmd == "printshoppinglist")
        {
            std::cout << currentShoppingList->getListName() << std::endl;
            std::cout << "Development in progress..." << std::endl;
        }
        else if(cmd == "printobject")
        {
            std::cout << "Development in progress..." << std::endl;
        }
        else if(cmd == "checkobject")
        {
            std::cout << "Development in progress..." << std::endl;
        }
        else if(cmd == "shoppingprogress")
        {
            std::cout << "Development in progress..." << std::endl;
        }
    }while(cmd != "exit" || cmd != "Exit");

    std::cout << "Closing the program..." << std::endl;
    return 0;
}
