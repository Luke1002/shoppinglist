//
// Created by luke1002 on 9/12/21.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"



TEST(ShoppingList, GetterSetter)
{
    ShoppingList list("lista");
    EXPECT_EQ(list.getListName(), "lista");
    list.setListName("elenco");
    EXPECT_EQ(list.getListName(), "elenco");

}

TEST(ShoppingList, Functions)
{
    ShoppingList list("lista");
    list.addObject(*new ShoppingObject("Banana", 7, "Produce"));
    EXPECT_EQ(list.getShoppingList().back().getObjectName(), "Banana");
    EXPECT_EQ(list.getShoppingList().back().getObjectQuantity(), 7);
    EXPECT_EQ(list.getShoppingList().back().getObjectCategory(), "Produce");
    list.addObject(*new ShoppingObject("Milk", 3, "Dairy products"));
    EXPECT_EQ(list.getShoppingList().front().getObjectName(), "Banana");
    EXPECT_EQ(list.getShoppingList().front().getObjectQuantity(), 7);
    EXPECT_EQ(list.getShoppingList().front().getObjectCategory(), "Produce");

    EXPECT_EQ(list.getShoppingList().back().getObjectName(), "Milk");
    EXPECT_EQ(list.getShoppingList().back().getObjectQuantity(), 3);
    EXPECT_EQ(list.getShoppingList().back().getObjectCategory(), "Dairy products");
    list.addObject(*new ShoppingObject("Biscuits", 2, "Snacks"));
    int listMember = 0;
    for(auto itr : list.getShoppingList())
    {
        listMember++;
        switch (listMember)
        {
            case 1:
                EXPECT_EQ(itr.getObjectName(), "Banana");
                EXPECT_EQ(itr.getObjectQuantity(), 7);
                EXPECT_EQ(itr.getObjectCategory(), "Produce");
                break;

            case 2:
                EXPECT_EQ(itr.getObjectName(), "Milk");
                EXPECT_EQ(itr.getObjectQuantity(), 3);
                EXPECT_EQ(itr.getObjectCategory(), "Dairy products");
                break;
            case 3:
                EXPECT_EQ(itr.getObjectName(), "Biscuits");
                EXPECT_EQ(itr.getObjectQuantity(), 2);
                EXPECT_EQ(itr.getObjectCategory(), "Snacks");
                break;
            default:
                break;
        }
    }
}