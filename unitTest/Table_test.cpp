#include "gtest/gtest.h"
#include <stdint.h>
#include "../src/Table.h"


class TableTest : public ::testing::Test
{};



//very small test
TEST(Table_Test, TableConstructor)
{
    Table table;
    std::deque<int32_t> cards = { 4, 3, 2, 1 }; //4 is on top
    Deck deck(cards);

    for(uint32_t i = 1; i < 5; ++i)
    {
        table.placeCard(i);
    }
    //the list of cards should be in the same order
    EXPECT_EQ(deck.getCards(), table.getDeck().getCards());

    cards = { 3, 2, 4, 1};
    deck = Deck(cards);
    EXPECT_NE(deck.getCards(), table.getDeck().getCards());

    table.clear();
    EXPECT_TRUE(table.isEmpty());
}
