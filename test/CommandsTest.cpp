//
// Created by luke1002 on 9/12/21.
//

#include "gtest/gtest.h"
#include "../commands.h"
#include "../commands.cpp"


TEST(Commands, newlist)
{
    std::vector<ShoppingList> listDatabase;
    std::shared_ptr<ShoppingList> shoppingList;
    std::stringstream fakeInput("lista\n");
    std::shared_ptr<ShoppingObject> objectPtr;
    newlist(listDatabase, shoppingList, objectPtr, fakeInput);
    listDatabase.back().printList();
    std::cout << std::endl << std::endl;
    EXPECT_EQ(listDatabase.back().getListName(), "lista");
    EXPECT_EQ(shoppingList->getListName(), "lista");
    std::stringstream fakeInput2("elenco\n");
    newlist(listDatabase, shoppingList, objectPtr, fakeInput2);
    EXPECT_EQ(listDatabase.front().getListName(), "lista");
    EXPECT_EQ(listDatabase.back().getListName(), "elenco");
    EXPECT_EQ(shoppingList->getListName(), "elenco");
}
TEST(Commands, addobject)
{
    std::vector<std::string> categoryList;
    std::vector<ShoppingList> listDb;
    categorylistinit(categoryList);
    std::shared_ptr<ShoppingList> listPtr = (std::make_shared<ShoppingList>("lista"));
    listDb.push_back(*(listPtr));
    std::shared_ptr<ShoppingObject> objectPtr;
    std::stringstream fakeInput("Banana\n7\nProduce\n");
    addobject(listPtr, objectPtr, categoryList, fakeInput);
    EXPECT_EQ(objectPtr->getObjectName(), "Banana");
    EXPECT_EQ(objectPtr->getObjectQuantity(), 7);
    EXPECT_EQ(objectPtr->getObjectCategory(), "Produce");
    std::stringstream fakeInput2("Milk\n2\nNotACategory\nDairy products\n");
    addobject(listPtr, objectPtr, categoryList, fakeInput2);
    EXPECT_EQ(objectPtr->getObjectName(), "Milk");
    EXPECT_EQ(objectPtr->getObjectQuantity(), 2);
    EXPECT_NE(objectPtr->getObjectCategory(), "NotACategory");
    EXPECT_EQ(objectPtr->getObjectCategory(), "Dairy products");
}

TEST(Commands, selectlist)
{
    std::vector<ShoppingList> listDatabase;
    std::shared_ptr<ShoppingList> shoppingList;
    std::shared_ptr<ShoppingObject> objectPtr;
    std::stringstream fakeInput("lista\n");
    selectlist(listDatabase, shoppingList, objectPtr, fakeInput);
    EXPECT_EQ(objectPtr, nullptr);
    EXPECT_EQ(shoppingList, nullptr);
    std::stringstream fakeInput2("lista\n");
    newlist(listDatabase, shoppingList, objectPtr, fakeInput2);
    std::stringstream fakeInput3("lista\n");
    selectlist(listDatabase, shoppingList, objectPtr, fakeInput3);
    EXPECT_EQ(objectPtr, nullptr);
    EXPECT_EQ(shoppingList->getListName(), "lista");

}

TEST(Commands, selectobject)
{
    std::vector<std::string> categoryList;
    categorylistinit(categoryList);
    std::vector<ShoppingList> listDatabase;
    std::stringstream fakeInput("lista\n");
    std::shared_ptr<ShoppingList> shoppingList;
    std::shared_ptr<ShoppingObject> objectPtr;
    newlist(listDatabase, shoppingList, objectPtr, fakeInput);
    std::stringstream fakeInput2("Banana\n");
    selectobject(shoppingList, objectPtr, fakeInput2);
    EXPECT_EQ(objectPtr, nullptr);
    EXPECT_EQ(shoppingList->getListName(), "lista");
    std::stringstream fakeInput3("Banana\n7\nProduce\n");
    addobject(shoppingList, objectPtr, categoryList, fakeInput3);
    EXPECT_EQ(objectPtr->getObjectName(), "Banana");
    std::stringstream fakeInput4("Milk\n2\nDairy products\n");
    addobject(shoppingList, objectPtr, categoryList, fakeInput4);
    EXPECT_EQ(objectPtr->getObjectName(), "Milk");
    std::stringstream fakeInput5("Banana\n");
    selectobject(shoppingList, objectPtr, fakeInput5);
    EXPECT_EQ(objectPtr->getObjectName(), "Banana");
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
    listPtr->addObject(*new ShoppingObject("Banana", 7, "Produce"));
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
    listPtr->addObject(*new ShoppingObject("Banana", 7, "Produce"));
    listPtr->addObject(*new ShoppingObject("Milk", 3, "Dairy products"));
    listPtr->addObject(*new ShoppingObject("Biscuits", 2, "Snacks"));

    std::cout << std::endl << "Expected Result" << std::endl
              << "Shopping Progress: 0%" << std::endl << std::endl
              << "Actual Result" << std::endl;
    shoppingprogress(listPtr);

}

TEST(Commands, deletelist)
{
    std::vector<std::string> categoryList;
    categorylistinit(categoryList);
    std::vector<ShoppingList> listDb;
    std::shared_ptr<ShoppingList> listPtr(new ShoppingList("lista"));
    listDb.push_back(*(listPtr));
    std::shared_ptr<ShoppingObject> objectPtr;
    std::stringstream fakeInput("Banana\n7\nProduce\n");
    addobject(listPtr, objectPtr, categoryList, fakeInput);
    EXPECT_EQ(listPtr->getListName(), "lista");
    EXPECT_EQ(objectPtr->getObjectName(), "Banana");
    deleteshoppinglist(listDb, listPtr, objectPtr);
    EXPECT_EQ(listPtr, nullptr);
    EXPECT_EQ(objectPtr, nullptr);
    deleteshoppinglist(listDb, listPtr, objectPtr);
    EXPECT_EQ(listPtr, nullptr);
    EXPECT_EQ(objectPtr, nullptr);
}

TEST(Commands, removeobject) {
    std::vector<std::string> categoryList;
    categorylistinit(categoryList);
    std::shared_ptr<ShoppingList> listPtr(new ShoppingList("lista"));
    std::shared_ptr<ShoppingObject> objectPtr;
    std::stringstream fakeInput("Banana\n7\nProduce\nMilk\n2\nDairy products\nMilk\nBanana\nMilk\nBanana\n");
    addobject(listPtr, objectPtr, categoryList, fakeInput);
    EXPECT_EQ(listPtr->getListName(), "lista");
    EXPECT_EQ(objectPtr->getObjectName(), "Banana");
    addobject(listPtr, objectPtr, categoryList, fakeInput);
    EXPECT_EQ(objectPtr->getObjectName(), "Milk");
    removeobject(listPtr, objectPtr);
    EXPECT_EQ(listPtr->getListName(), "lista");
    EXPECT_EQ(objectPtr, nullptr);
    selectobject(listPtr, objectPtr, fakeInput);
    EXPECT_EQ(objectPtr, nullptr);
    selectobject(listPtr, objectPtr, fakeInput);
    EXPECT_EQ(objectPtr->getObjectName(), "Banana");
    removeobject(listPtr, objectPtr);
    EXPECT_EQ(listPtr->getListName(), "lista");
    EXPECT_EQ(objectPtr, nullptr);
    selectobject(listPtr, objectPtr, fakeInput);
    EXPECT_EQ(objectPtr, nullptr);
    selectobject(listPtr, objectPtr, fakeInput);
    EXPECT_EQ(objectPtr, nullptr);
}