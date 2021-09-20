//
// Created by luke1002 on 9/12/21.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"


TEST(ShoppingList, Getter_Setter) {
    std::cout << std::endl << std::endl;
    std::cout << "Testing: ShoppingList" << std::endl << std::endl;
    std::cout << "----- Starting Test N.1 -----" << std::endl;
    std::cout << "Test Name: Getter_Setter" << std::endl;
    ShoppingList list("lista");
    EXPECT_EQ(list.getListName(), "lista");
    list.setListName("elenco");
    EXPECT_EQ(list.getListName(), "elenco");
    std::cout << "----- Ending Test N.1 -----" << std::endl << std::endl;
    std::cout << std::endl << std::endl;
}

TEST(ShoppingList, Managing_Objects) {
    std::cout << std::endl << std::endl;
    std::cout << "----- Starting Test N.2 -----" << std::endl;
    std::cout << "Test Name: Managing_Objects" << std::endl;
    ShoppingList list("lista");
    list.addObject("Banana", 7, "Produce");
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.getObjectName(), "Banana");
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.getObjectQuantity(), 7);
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.getObjectCategory(), "Produce");
    list.addObject("Milk", -3, "Dairy products");
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.getObjectName(), "Banana");
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.getObjectQuantity(), 7);
    EXPECT_EQ(list.getShoppingList().find("Banana")->second.getObjectCategory(), "Produce");

    EXPECT_EQ(list.getShoppingList().find("Milk")->second.getObjectName(), "Milk");
    EXPECT_EQ(list.getShoppingList().find("Milk")->second.getObjectQuantity(), 3);
    EXPECT_EQ(list.getShoppingList().find("Milk")->second.getObjectCategory(), "Dairy products");
    list.addObject("Biscuits", 0, "Snacks");
    int listMember = 0;
    for (auto itr: list.getShoppingList()) {
        listMember++;
        switch (listMember) {
            case 1:
                EXPECT_EQ(itr.second.getObjectName(), "Banana");
                EXPECT_EQ(itr.second.getObjectQuantity(), 7);
                EXPECT_EQ(itr.second.getObjectCategory(), "Produce");
                break;

            case 2:
                EXPECT_EQ(itr.second.getObjectName(), "Biscuits");
                EXPECT_EQ(itr.second.getObjectQuantity(), 0);
                EXPECT_EQ(itr.second.getObjectCategory(), "Snacks");

                break;
            case 3:
                EXPECT_EQ(itr.second.getObjectName(), "Milk");
                EXPECT_EQ(itr.second.getObjectQuantity(), 3);
                EXPECT_EQ(itr.second.getObjectCategory(), "Dairy products");
                break;
            default:
                break;
        }
    }
    bool removalSuccess = list.removeObject("Banana");
    EXPECT_TRUE(removalSuccess);
    listMember = 0;
    for (auto itr: list.getShoppingList()) {
        listMember++;
        switch (listMember) {
            case 1:
                EXPECT_EQ(itr.second.getObjectName(), "Biscuits");
                EXPECT_EQ(itr.second.getObjectQuantity(), 0);
                EXPECT_EQ(itr.second.getObjectCategory(), "Snacks");

                break;
            case 2:
                EXPECT_EQ(itr.second.getObjectName(), "Milk");
                EXPECT_EQ(itr.second.getObjectQuantity(), 3);
                EXPECT_EQ(itr.second.getObjectCategory(), "Dairy products");
                break;
            default:
                break;
        }
    }
    removalSuccess = list.removeObject("NotAnObject");
    EXPECT_FALSE(removalSuccess);
    listMember = 0;
    for (auto itr: list.getShoppingList()) {
        listMember++;

    }
    EXPECT_EQ(listMember, 2);
    list.setBought("Biscuits", true);
    EXPECT_TRUE(list.getShoppingList().find("Biscuits")->second.isInCart());
    list.setBought("Milk", false);
    EXPECT_FALSE(list.getShoppingList().find("Milk")->second.isInCart());
    list.setBought("NotAnObject", true);
    EXPECT_TRUE(list.getShoppingList().find("Biscuits")->second.isInCart());
    EXPECT_FALSE(list.getShoppingList().find("Milk")->second.isInCart());
    list.setBought("NotAnObject", false);
    EXPECT_TRUE(list.getShoppingList().find("Biscuits")->second.isInCart());
    EXPECT_FALSE(list.getShoppingList().find("Milk")->second.isInCart());
    std::cout << "----- Ending Test N.2 -----" << std::endl << std::endl;
    std::cout << "Ending testing of: ShoppingList" << std::endl;
    std::cout << std::endl << std::endl;
}