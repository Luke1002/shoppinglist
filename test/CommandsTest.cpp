//
// Created by luke1002 on 9/12/21.
//

#include "gtest/gtest.h"
#include "../commands.h"
#include "../commands.cpp"


TEST(Commands, newlist) {
    std::cout << std::endl << std::endl;
    std::cout << "Testing: Commands" << std::endl << std::endl;
    std::cout << "----- Starting Test N.1 -----" << std::endl;
    std::cout << "Test Name: newlist" << std::endl;
    std::map<std::string, ShoppingList> listDatabase;
    std::string currentList;
    std::stringstream fakeInput("lista\n");
    newlist(listDatabase, currentList, fakeInput);
    printshoppinglist(listDatabase, currentList);
    std::cout << std::endl << std::endl;
    EXPECT_EQ(listDatabase.begin()->second.getListName(), "lista");
    EXPECT_EQ(currentList, "lista");
    std::stringstream fakeInput2("elenco\n");
    newlist(listDatabase, currentList, fakeInput2);
    EXPECT_EQ(listDatabase.find("lista")->second.getListName(), "lista");
    EXPECT_EQ(listDatabase.find("elenco")->second.getListName(), "elenco");
    EXPECT_EQ(currentList, "elenco");
    std::cout << std::endl;
    std::cout << "----- Ending Test N.1 -----" << std::endl << std::endl;
    std::cout << std::endl << std::endl;
}

TEST(Commands, addobject) {
    std::cout << std::endl << std::endl;
    std::cout << "----- Starting Test N.2 -----" << std::endl;
    std::cout << "Test Name: addobject" << std::endl;
    std::map<std::string, ShoppingList> listDatabase;
    std::vector<std::string> categoryList;
    categorylistinit(categoryList);
    std::string currentList;
    std::stringstream fakeInput("lista\n");
    newlist(listDatabase, currentList, fakeInput);
    ShoppingList &list = listDatabase.find(currentList)->second;
    fakeInput = std::stringstream("Banana\n7\nProduce\n");
    addobject(listDatabase, currentList, categoryList, fakeInput);
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.getObjectName(), "Banana");
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.getObjectQuantity(), 7);
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.getObjectCategory(), "Produce");
    fakeInput = std::stringstream("Milk\n2\nNotACategory\nDairy products\n");
    addobject(listDatabase, currentList, categoryList, fakeInput);
    EXPECT_EQ(list.getShoppingList().find("Milk")->second.getObjectName(), "Milk");
    EXPECT_EQ(list.getShoppingList().find("Milk")->second.getObjectQuantity(), 2);
    EXPECT_NE(list.getShoppingList().find("Milk")->second.getObjectCategory(), "NotACategory");
    EXPECT_EQ(list.getShoppingList().find("Milk")->second.getObjectCategory(), "Dairy products");
    std::cout << std::endl;
    std::cout << "----- Ending Test N.2 -----" << std::endl << std::endl;
    std::cout << std::endl << std::endl;
}

TEST(Commands, selectlist) {
    std::cout << std::endl << std::endl;
    std::cout << "----- Starting Test N.3 -----" << std::endl;
    std::cout << "Test Name: selectlist" << std::endl;
    std::map<std::string, ShoppingList> listDatabase;
    std::string currentList;
    std::stringstream fakeInput("lista\n");
    selectlist(listDatabase, currentList, fakeInput);
    EXPECT_TRUE(currentList.empty());
    fakeInput = std::stringstream("lista\n");
    newlist(listDatabase, currentList, fakeInput);
    ShoppingList &list = listDatabase.find(currentList)->second;
    fakeInput = std::stringstream("lista\n");
    selectlist(listDatabase, currentList, fakeInput);
    EXPECT_EQ(list.getListName(), "lista");
    std::cout << "----- Ending Test N.3 -----" << std::endl << std::endl;
    std::cout << std::endl << std::endl;
}

TEST(Commands, checkobject) {
    std::cout << std::endl << std::endl;
    std::cout << "----- Starting Test N.4 -----" << std::endl;
    std::cout << "Test Name: checkobject" << std::endl;
    std::vector<std::string> categoryList;
    categorylistinit(categoryList);
    std::map<std::string, ShoppingList> listDatabase;
    std::string currentList;
    std::stringstream fakeInput("lista\n");
    newlist(listDatabase, currentList, fakeInput);
    ShoppingList &list = listDatabase.find(currentList)->second;
    fakeInput = std::stringstream("Banana\n7\nProduce\n");
    addobject(listDatabase, currentList, categoryList, fakeInput);
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.isInCart(), false);
    fakeInput = std::stringstream("Banana\n");
    checkobject(listDatabase, currentList, fakeInput);
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.isInCart(), true);
    fakeInput = std::stringstream("Banana\n");
    checkobject(listDatabase, currentList, fakeInput);
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.isInCart(), true);
    std::cout << "----- Ending Test N.4 -----" << std::endl << std::endl;
    std::cout << std::endl << std::endl;
}

TEST(Commands, uncheckobject) {
    std::cout << std::endl << std::endl;
    std::cout << "----- Starting Test N.5 -----" << std::endl;
    std::cout << "Test Name: uncheckobject" << std::endl;
    std::vector<std::string> categoryList;
    categorylistinit(categoryList);
    std::map<std::string, ShoppingList> listDatabase;
    std::string currentList;
    std::stringstream fakeInput("lista\n");
    newlist(listDatabase, currentList, fakeInput);
    ShoppingList &list = listDatabase.find(currentList)->second;
    fakeInput = std::stringstream("Banana\n7\nProduce\n");
    addobject(listDatabase, currentList, categoryList, fakeInput);
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.isInCart(), false);
    fakeInput = std::stringstream("Banana\n");
    checkobject(listDatabase, currentList, fakeInput);
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.isInCart(), true);
    fakeInput = std::stringstream("Banana\n");
    uncheckobject(listDatabase, currentList, fakeInput);
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.isInCart(), false);
    std::cout << "----- Ending Test N.5 -----" << std::endl << std::endl;
    std::cout << std::endl << std::endl;
}

TEST(Commands, printlist) {
    std::cout << std::endl << std::endl;
    std::cout << "----- Starting Test N.6 -----" << std::endl;
    std::cout << "Test Name: printlist" << std::endl;
    std::map<std::string, ShoppingList> listDatabase;
    std::string currentList;
    std::stringstream fakeInput("lista\n");
    newlist(listDatabase, currentList, fakeInput);
    ShoppingList &list = listDatabase.find(currentList)->second;
    list.addObject("Banana", 7, "Produce");
    std::cout << std::endl << "Expected Result" << std::endl << std::endl
              << "lista" << std::endl << std::endl
              << "Object: Banana" << std::endl
              << "Quantity: 7" << std::endl
              << "Category: Produce" << std::endl
              << "Bought: No" << std::endl << std::endl
              << "Actual Result" << std::endl << std::endl;
    printshoppinglist(listDatabase, currentList);
    std::cout << "----- Ending Test N.6 -----" << std::endl << std::endl;
    std::cout << std::endl << std::endl;
}

TEST(Commands, printobject) {
    std::cout << std::endl << std::endl;
    std::cout << "----- Starting Test N.7 -----" << std::endl;
    std::cout << "Test Name: printobject" << std::endl;
    std::vector<std::string> categoryList;
    categorylistinit(categoryList);
    std::map<std::string, ShoppingList> listDatabase;
    std::string currentList;
    std::stringstream fakeInput("lista\n");
    newlist(listDatabase, currentList, fakeInput);
    ShoppingList &list = listDatabase.find(currentList)->second;
    fakeInput = std::stringstream("Banana\n7\nProduce\nBanana\n");
    addobject(listDatabase, currentList, categoryList, fakeInput);
    std::cout << std::endl << std::endl << "Expected Result" << std::endl << std::endl
              << "Object: Banana" << std::endl
              << "Quantity: 7" << std::endl
              << "Category: Produce" << std::endl
              << "Bought: No" << std::endl << std::endl
              << "Actual Result" << std::endl << std::endl;
    printobject(listDatabase, currentList, fakeInput);
    fakeInput = std::stringstream("Apple\n0\nProduce\nApple\n");
    addobject(listDatabase, currentList, categoryList, fakeInput);
    std::cout << std::endl << std::endl << "Expected Result" << std::endl << std::endl
              << "Object: Apple" << std::endl
              << "Category: Produce" << std::endl
              << "Bought: No" << std::endl << std::endl
              << "Actual Result" << std::endl << std::endl;
    printobject(listDatabase, currentList, fakeInput);
    std::cout << "----- Ending Test N.7 -----" << std::endl << std::endl;
    std::cout << std::endl << std::endl;
}

TEST(Commands, shoppingprogress) {
    std::cout << std::endl << std::endl;
    std::cout << "----- Starting Test N.8 -----" << std::endl;
    std::cout << "Test Name: shoppingprogress" << std::endl;
    std::map<std::string, ShoppingList> listDatabase;
    std::string currentList;
    std::stringstream fakeInput("lista\n");
    newlist(listDatabase, currentList, fakeInput);
    ShoppingList &list = listDatabase.find(currentList)->second;
    list.addObject("Banana", 7, "Produce");
    list.addObject("Milk", 3, "Dairy products");
    list.addObject("Biscuits", 2, "Snacks");
    std::cout << std::endl << "Expected Result" << std::endl
              << "Shopping Progress: 0%" << std::endl << std::endl
              << "Actual Result" << std::endl;
    shoppingprogress(listDatabase, currentList);
    list.setBought("Milk", true);
    std::cout << std::endl << "Expected Result" << std::endl
              << "Shopping Progress: 33.33%" << std::endl << std::endl
              << "Actual Result" << std::endl;
    shoppingprogress(listDatabase, currentList);
    list.setBought("Biscuits", true);
    std::cout << std::endl << "Expected Result" << std::endl
              << "Shopping Progress: 66.67%" << std::endl << std::endl
              << "Actual Result" << std::endl;
    shoppingprogress(listDatabase, currentList);
    list.setBought("Milk", false);
    std::cout << std::endl << "Expected Result" << std::endl
              << "Shopping Progress: 33.33%" << std::endl << std::endl
              << "Actual Result" << std::endl;
    shoppingprogress(listDatabase, currentList);
    std::cout << "----- Ending Test N.8 -----" << std::endl << std::endl;
    std::cout << std::endl << std::endl;
}

TEST(Commands, deletelist) {
    std::cout << std::endl << std::endl;
    std::cout << "----- Starting Test N.9 -----" << std::endl;
    std::cout << "Test Name: deletelist" << std::endl;
    std::vector<std::string> categoryList;
    categorylistinit(categoryList);
    std::map<std::string, ShoppingList> listDatabase;
    std::string currentList;
    std::stringstream fakeInput("lista\n");
    newlist(listDatabase, currentList, fakeInput);
    ShoppingList &list = listDatabase.find(currentList)->second;
    fakeInput = std::stringstream("Banana\n7\nProduce\n");
    addobject(listDatabase, currentList, categoryList, fakeInput);
    EXPECT_EQ(list.getListName(), "lista");
    deleteshoppinglist(listDatabase, currentList);
    EXPECT_TRUE(currentList.empty());
    deleteshoppinglist(listDatabase, currentList);
    EXPECT_TRUE(currentList.empty());
    std::cout << "----- Ending Test N.9 -----" << std::endl << std::endl;
    std::cout << std::endl << std::endl;
}

TEST(Commands, removeobject) {
    std::cout << std::endl << std::endl;
    std::cout << "----- Starting Test N.10 -----" << std::endl;
    std::cout << "Test Name: removeobject" << std::endl;
    std::vector<std::string> categoryList;
    categorylistinit(categoryList);
    std::map<std::string, ShoppingList> listDatabase;
    std::string currentList;
    std::stringstream fakeInput("lista\n");
    newlist(listDatabase, currentList, fakeInput);
    ShoppingList &list = listDatabase.find(currentList)->second;
    fakeInput = std::stringstream("Banana\n7\nProduce\nMilk\n2\nDairy products\n");
    addobject(listDatabase, currentList, categoryList, fakeInput);
    EXPECT_EQ(currentList, "lista");
    addobject(listDatabase, currentList, categoryList, fakeInput);
    fakeInput = std::stringstream("Milk\n");
    removeobject(listDatabase, currentList, fakeInput);
    fakeInput = std::stringstream("Milk\n");
    printobject(listDatabase, currentList, fakeInput);
    std::unique_ptr<std::map<std::string, ShoppingObject>> objectlist = std::make_unique<std::map<std::string, ShoppingObject>>(
            list.getShoppingList());
    EXPECT_TRUE(objectlist->find("Milk") == objectlist->end());
    EXPECT_TRUE(objectlist->find("Banana") != objectlist->end());
    fakeInput = std::stringstream("Banana\n");
    removeobject(listDatabase, currentList, fakeInput);
    fakeInput = std::stringstream("Banana\n");
    printobject(listDatabase, currentList, fakeInput);
    EXPECT_TRUE(objectlist->find("Milk") == objectlist->end());
    std::cout << "----- Ending Test N.10 -----" << std::endl << std::endl;
    std::cout << "Ending testing of: Commands" << std::endl;
    std::cout << std::endl << std::endl;
}