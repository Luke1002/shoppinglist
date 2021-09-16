//
// Created by luke1002 on 9/12/21.
//

#include "../ShoppingObject.h"
#include "gtest/gtest.h"


TEST(ShoppingObject, GetterSetter)
{
    ShoppingObject object("Banana", 7, "Produce");
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
}

TEST(ShoppingObject, Functions)
{
    ShoppingObject object("Banana", 7, "Produce");
    EXPECT_EQ(object.isBought(), false);
    object.checkTrue();
    EXPECT_EQ(object.isBought(), true);
    object.checkFalse();
    EXPECT_EQ(object.isBought(), false);
}