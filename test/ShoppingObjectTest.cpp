//
// Created by lucal on 12/09/2021.
//

#include "gtest/gtest.h"
#include "../ShoppingObject.h"

TEST(ShoppingObject, GetterSetter)
{
    ShoppingObject l("Banana", 7, "Produce");
    EXPECT_EQ(l.getObjectName(), "Banana");
    l.setObjectName("Apple");
    EXPECT_NE(l.getObjectName(), "Banana");
    EXPECT_EQ(l.getObjectName(), "Apple");

    EXPECT_EQ(l.getObjectQuantity(), 7);
    l.setObjectQuantity(-1);
    EXPECT_NE(l.getObjectQuantity(), 7);
    EXPECT_EQ(l.getObjectQuantity(), 1);
}