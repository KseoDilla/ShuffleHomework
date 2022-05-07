#ifndef _DECK_H_
#define _DECK_H_

#include <deque>
#include <stdint.h>

class Deck
{
    public:
        //@brief default constructor
        Deck();

        //@brief parameterized constructor
        Deck(int32_t numOfCards);

        //@brief copy constructor
        Deck(Deck& incomingDeck);


        //@brief destructor
        ~Deck();

        //@brief method to determine if the deck is empty
        const bool isEmpty() const;

        //@brief a public method to return the list of cards as a deque
        const std::deque<int32_t>& getCards() const;

        //@brief pops the top card off the deck
        //param shuffleMode boolean dictates if the card gets discarded to the table or placed at the bottom of the deck
        /*
          if true pop the card and do nothing else and return the card - it's going to the table
          if false pop the card and put it at the bottom of the deck - call putBelowDeck
        */
        int32_t popFront(const bool shuffleMode);

        //@brief place it on top of the deck - this is used by the table class when the card is discarded to the table
        //@param card - an integer representing the card's value
        void pushFront(int32_t card);

        //@brief this printt method will print FIFO
        void print() const;

        //@brief overloaded equal operator to help determine if the decks are equal
        bool operator==(const Deck& rhs) const;

        //@brief overloaded not equal operator to help determine if the decks are equal
        bool operator!=(const Deck& rhs) const;

    private:
        //@brief method to help put the card at the bottom of the deck - it's a push back in this case
        void putBelowDeck();

        //@brief data structure to hold the list of cards
        std::deque<int32_t> m_cards;
};

#endif
