#include "gtest/gtest.h"
#include <stdint.h>
#include "../src/Table.h"


class TableTest : public ::testing::Test {};


//unit test for table constructor
//also tests placeCard(), getDeck(), isEmpty()
TEST(Table_Test, TableConstructor)
{
    Table table;
    Deck deck(4);

    //the cards are placed down onto the table as a stack
    //place the cards 
    for(uint32_t i = 4; i > 0; --i)
    {
        table.placeCard(i);
    }
    EXPECT_EQ(deck.getCards(), table.getDeck().getCards());

    table.clear();
    EXPECT_TRUE(table.isEmpty());
}
