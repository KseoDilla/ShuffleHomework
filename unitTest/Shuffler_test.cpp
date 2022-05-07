#include "gtest/gtest.h"
#include "../src/Shuffler.h"
#include <stdint.h>


class ShufflerTest : public ::testing::Test
{
    protected:
    std::unique_ptr<Shuffler> pShuffler;

    ShufflerTest()
    {
    }

    //For test fixtures
    virtual void SetUp()
    {
        pShuffler = std::make_unique<Shuffler>(8);
    }

    virtual void TearDown()
    {
    }
};



// Test the constructor
TEST(ShufflerStandAlone_Test, ShufflerConstructor)
{
    std::deque<int32_t> deckOfCards = { 1, 2, 3, 4, 5, 6, 7, 8 };
    Shuffler sd(8);
    //ensure the deque was copied and the class has a copy - they should be equal
    EXPECT_EQ(deckOfCards, sd.getDeck());
    
    deckOfCards.pop_front();
    //ensure the deque was copied and the class has its own copy
    //in this instance, they should no longer equal if the input has removed a card from its deck
    //but has updated the class
    EXPECT_NE(deckOfCards, sd.getDeck());
}



// There's some sort of discrete math here that I do not quite understand
// but there's a pattern here when it comes to powers of 2 (this is a head scratcher)
// it was easier to validate these sets of cards
TEST(ShufflerStandAlone_Test, ShufflerPowersOf2)
{
    //4 cards take 2 rounds
    std::deque<int32_t> deckOfCards = { 1, 2, 3, 4 };
    Shuffler sd(4);
    //ensure the deque was copied and the class has a copy - they should be equal
    EXPECT_EQ(2, sd.start());


   sd = Shuffler(8);
   EXPECT_EQ(4, sd.start());
    
   sd = Shuffler(16);
   EXPECT_EQ(4, sd.start());

   sd = Shuffler(32);
   EXPECT_EQ(12, sd.start());
}



//Test edge case - no cards are provided
TEST(ShufflerStandAlone_Test, ShufflerEdgeCaseNoInput)
{
    Shuffler sd;
    EXPECT_EQ(0, sd.start());
}



//Test the number of rounds it takes to sort
TEST_F(ShufflerTest, ShufflerSortSuccess)
{
    //In a set of 8 cards, there should be 4 rounds
    //to sort this deck back to its original order
    EXPECT_EQ(4, pShuffler->start());
}
    


//Just a generic failure case
TEST_F(ShufflerTest, ShufflerSortFail)
{
    EXPECT_NE(5, pShuffler->start());
}
