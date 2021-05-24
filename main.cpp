#include <iostream>
#include <string>
#include <limits>


#include "ShoppingList.h"
#include "ShoppingObject.h"

int main() {
    std::string cmd;
    std::string* name;
    bool nameFound;
    int quantity;
    ShoppingList* currentShoppingList;
    ShoppingObject* currentShoppingObject;
    std::list<ShoppingList> savedlists;
    std::cout << "Shopping List Manager" << std::endl
              << "by Luca Lascialfari" << std::endl
              << std::endl
              << "Type \"help\" to view the list of commands available" << std::endl;
    do
    {
        nameFound = false;
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
            name = new std::string;
            do
            {
                nameFound = false;
                std::cout << "Insert list name" << std::endl
                          << "Name: ";
                std::getline(std::cin, *name);
                std::cout << name << std::endl;

                for(auto& element : savedlists)
                {
                    if (element.getListName() == *name)
                    {
                        nameFound = true;
                        std::cout << "Name already used for another list." << std::endl << "Please choose a different name" << std::endl;
                    }
                }
                if(!nameFound)
                {
                    savedlists.emplace_back(*name);
                    currentShoppingList = &(savedlists.back());
                }

            }while(nameFound);
            delete[] name;
        }
        else if(cmd == "addobject")
        {
            name = new std::string;
            if(currentShoppingList != nullptr)
            {
                std::cout << "Please enter object name" << std::endl;
                do
                {
                    std::cout << "Name: ";
                    std::getline(std::cin, *name);
                    for(const auto& element : currentShoppingList->getShoppingList())
                    {
                        if(*name == element.getObjectName())
                        {
                            nameFound = true;
                            std::cout << "Name already used for another object in the same list." << std::endl << "Please choose a different name" << std::endl;
                        }
                    }
                }while(nameFound);
                std::cout << "Please enter quantity" << std::endl;
                do
                {
                    std::cout << "Quantity: ";
                    std::cin >> quantity;
                    if (!std::cin)
                    {
                        std::cout << "Invalid input. Please enter an integer" << std::endl;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }while(!std::cin);
                std::cin.clear();
                currentShoppingList->addObject(*name, quantity);
                currentShoppingObject = &(currentShoppingList->getShoppingList().back());
            }
            else
            {
                std::cout << "No list has been selected." << std::endl
                          << "Please select a list before trying to add an object" << std::endl;
            }
            delete[] name;
        }
        else if(cmd == "selectshoppinglist")
        {
            name = new std::string;
            std::cout << "insert name of list to change to" << std::endl;
            std::getline(std::cin, *name);
            for(auto element : savedlists)
            {
                if(*name == element.getListName())
                {
                    nameFound = true;
                    currentShoppingList = &element;
                }
            }
            if(nameFound)
            {
                std::cout << "Selected list successfully changed" << std::endl;
            }
            else
            {
                std::cout << "Shopping list not found. Please check the list name spelling" << std::endl;
            }
            delete[] name;
        }
        else if(cmd == "selectobject")
        {
            //TODO ADD "selectobject" COMMAND
        }
        else if(cmd == "printshoppinglist")
        {
            //TODO ADD "printshoppinglist" COMMAND
        }
        else if(cmd == "printobject")
        {
            //TODO ADD "printobject" COMMAND
        }
        else if(cmd == "checkobject")
        {
            //TODO ADD "checkobject" COMMAND
        }
        else if(cmd == "shoppingprogress")
        {
            //TODO ADD "shoppingprogress" COMMAND
        }
    }while(cmd != "exit" || cmd != "Exit");

    std::cout << "Closing the program..." << std::endl;
    return 0;
}
