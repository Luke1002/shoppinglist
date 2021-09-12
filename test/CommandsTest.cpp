//
// Created by luke1002 on 9/12/21.
//

#include "gtest/gtest.h"
#include "../commands.h"



TEST(Commands, newlist)
{

    std::list<ShoppingList> listDatabase;
    std::shared_ptr<ShoppingList> shoppingList;
    std::stringstream fakeInput("lista\n");
    newlist(listDatabase, shoppingList, fakeInput);
    listDatabase.back().printList();
    std::cout << std::endl << std::endl;
    EXPECT_EQ(listDatabase.back().getListName(), "lista");
}

TEST(Commands, addobject)
{

}

TEST(Commands, selectlist)
{

}

TEST(Commands, selectobject)
{

}

TEST(Commands, checkobject)
{
    std::shared_ptr<ShoppingObject> objectPtr(new ShoppingObject("Banana", 7, "Produce"));
    EXPECT_EQ(objectPtr->isBought(), false);
    checkobject(objectPtr);
    EXPECT_EQ(objectPtr->isBought(), true);

}

TEST(Commands, uncheckobject)
{
    std::shared_ptr<ShoppingObject> objectPtr(new ShoppingObject("Banana", 7, "Produce"));
    EXPECT_EQ(objectPtr->isBought(), false);
    uncheckobject(objectPtr);
    EXPECT_EQ(objectPtr->isBought(), false);
}

TEST(Commands, printlist)
{
    std::shared_ptr<ShoppingList> listPtr(new ShoppingList("lista"));
    listPtr->addObject("Banana", 7, "Produce");
    std::cout << std::endl << "Expected Result" << std::endl << std::endl
              << "lista" << std::endl << std::endl
              << "Object: Banana" << std::endl
              << "Quantity: 7" << std::endl
              << "Category: Produce" << std::endl
              << "Bought: No" << std::endl << std::endl
              << "Actual Result" << std::endl << std::endl;
    printshoppinglist(listPtr);
}

TEST(Commands, printobject)
{
    std::shared_ptr<ShoppingObject> objectPtr(new ShoppingObject("Banana", 7, "Produce"));
    std::cout << std::endl << std::endl << "Expected Result" << std::endl << std::endl
    << "Object: Banana" << std::endl
    << "Quantity: 7" << std::endl
    << "Category: Produce" << std::endl
    << "Bought: No" << std::endl << std::endl
    << "Actual Result" << std::endl << std::endl;
    printobject(objectPtr);
}

TEST(Commands, shoppingprogress)
{
    std::shared_ptr<ShoppingList> listPtr(new ShoppingList("lista"));
    listPtr->addObject("Banana", 7, "Produce");
    listPtr->addObject("Milk", 3, "Dairy products");
    listPtr->addObject("Biscuits", 2, "Snacks");

    std::cout << std::endl << "Expected Result" << std::endl
              << "Shopping Progress: 0%" << std::endl << std::endl
              << "Actual Result" << std::endl;
    shoppingprogress(listPtr);

}

TEST(Commands, deletelist)
{

}

TEST(Commands, removeobject)
{

}