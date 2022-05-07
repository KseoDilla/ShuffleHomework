#include "gtest/gtest.h"
#include "../src/Deck.h"
#include <deque>
#include <stdint.h>


class DeckTest : public ::testing::Test
{};

//test default constructor
//test isEmpty
TEST(Deck_Test, DeckConstructor)
{
    Deck deck;
    EXPECT_TRUE(deck.isEmpty());
}

//test parameterized constructor
//test getCards
TEST(Deck_Test, DeckParameterConstructor)
{
    std::deque<int32_t> cards = { 1, 2, 3, 4, 5, 6, 7, 8};
    Deck deck(cards);

    EXPECT_EQ(cards, deck.getCards());
}


//test copy constructor
TEST(Deck_Test, DeckCopyConstructor)
{
    std::deque<int32_t> cards = { 1, 2, 3, 4, 5 };
    Deck deck1(cards);
    Deck deck2;

    EXPECT_NE(deck1, deck2);

    deck2 = deck1;

    EXPECT_EQ(deck1, deck2);
}


//test shuffleMode - test the two modes
TEST(Deck_TEST, DeckPopFront)
{
    std::deque<int32_t> cards = { 1, 2, 3, 4, 5 };
    Deck deck1(cards);

    deck1.popFront(false); //put the card at the bottom of the deck
    EXPECT_NE(cards, deck1.getCards());
    cards.push_back(cards.front());
    cards.pop_front();
    EXPECT_EQ(cards, deck1.getCards());

    deck1.popFront(true); //put the card on the table
    EXPECT_NE(cards, deck1.getCards());
    cards.pop_front();
    EXPECT_EQ(cards, deck1.getCards());
}

//test pushFront - really should be a table unit test but I've ran out of time
TEST(Deck_TEST, DeckPushFront)
{
    std::deque<int32_t> cards = { 1, 2, 3, 4, 5 };
    Deck deck1(cards);

    deck1.pushFront(1);
    cards.push_front(1);

    EXPECT_EQ(cards, deck1.getCards());
}
