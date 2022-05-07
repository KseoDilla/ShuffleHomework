#ifndef _TABLE_H_
#define _TABLE_H_

#include <deque>
#include "Deck.h"
#include <stdint.h>

//Class reprsenting the table which holds a deck
class Table
{
    public:
        //@brief default constructor
        //A table is never constructed with a deck of cards
        Table();

        //@brief a destructor
        ~Table();

        //@brief Method to place cards onto the table's deck
        //@param card represents the card to insert onto the table's deck
        void placeCard(int32_t card);
        
        //@brief method to grab the deck from the table
        Deck getDeck();

        //@brief method to clear the table
        void clear();

        //@brief public method to check if the table is empty
        bool isEmpty();

    private:
        //@brief member variable to keep track of the cards on the table
        Deck m_deck;
};

#endif
