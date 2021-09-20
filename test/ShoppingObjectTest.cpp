//
// Created by luke1002 on 9/12/21.
//

#include "../ShoppingObject.h"
#include "gtest/gtest.h"


TEST(ShoppingObject, Getter_Setter) {
    std::cout << std::endl << std::endl;
    std::cout << "Testing: ShoppingObject" << std::endl << std::endl;
    std::cout << "----- Starting Test N.1 -----" << std::endl;
    std::cout << "Test Name: Getter_Setter" << std::endl;
    ShoppingObject object((std::string &)"Banana",7,(std::string &)"Produce");
    EXPECT_EQ(object.getObjectName(), "Banana");
    EXPECT_EQ(object.getObjectQuantity(), 7);
    EXPECT_EQ(object.getObjectCategory(), "Produce");

    object.setObjectName("Apple");
    object.setObjectQuantity(-5);
    object.setObjectCategory("Dairy products");

    EXPECT_EQ(object.getObjectName(), "Apple");
    EXPECT_EQ(object.getObjectQuantity(), 5);
    EXPECT_EQ(object.getObjectCategory(), "Dairy products");

    EXPECT_NE(object.getObjectName(), "Banana");
    EXPECT_NE(object.getObjectQuantity(), 7);
    EXPECT_NE(object.getObjectCategory(), "Produce");
    EXPECT_EQ(object.isInCart(), false);
    object.setInCart(true);
    EXPECT_EQ(object.isInCart(), true);
    object.setInCart(false);
    EXPECT_EQ(object.isInCart(), false);
    std::cout << "----- Ending Test N.1 -----" << std::endl;
    std::cout << std::endl << std::endl;
}

TEST(ShoppingObject, Functions) {
    std::cout << std::endl << std::endl;
    std::cout << "----- Starting Test N.2 -----" << std::endl;
    std::cout << "Testing: ShoppingObject" << std::endl;
    std::cout << "Test Name: Functions" << std::endl;
    ShoppingObject object((std::string &)"Banana", 7, (std::string &)"Produce");
    EXPECT_EQ(object.toString().str(), "Banana\n7\nProduce\n");
    object.setObjectName("Roast Beef");
    EXPECT_EQ(object.toString().str(), "Roast Beef\n7\nProduce\n");
    object.setObjectQuantity(-5);
    EXPECT_EQ(object.toString().str(), "Roast Beef\n5\nProduce\n");
    object.setObjectCategory("Meat Products");
    EXPECT_EQ(object.toString().str(), "Roast Beef\n5\nMeat Products\n");
    std::cout << "----- Ending Test N.2 -----" << std::endl << std::endl;
    std::cout << "Ending testing of: ShoppingObject" << std::endl;
    std::cout << std::endl << std::endl;
}