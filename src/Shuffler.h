#ifndef _SHUFFLER_H_
#define _SHUFFLER_H_

#include <deque>
#include "Deck.h"
#include <stdint.h>
#include "Table.h"

//Class for shuffling
class Shuffler
{
    public:
        //@brief default constructor
        Shuffler();

        //@brief parameterized constructor
        Shuffler(std::deque<int32_t>& cards);


        //@brief destructor
        ~Shuffler();

        //@brief method to start shuffling
        //return the number of rounds it took to shuffle the deck back to its original order
        /*
           1) take first card off the deck in our hands and place it on the table
           2) take the next card off the deck and put it at the bottom of the deck in our hands
           3) when no cards are available pick up the deck from the table
           4) rinse and repease until the cards are in the original order they were picked up in
        */
        int32_t start();

        //@brief method to grab the m_deck member variable
        const std::deque<int32_t>& getDeck() const;

    private:
        //@brief private method to help shuffle the deck - does most of the heavy lifting for the start method 
        void shuffle();

        //@brief member variable to help keep track of the cards in our hands
        Deck m_deck;

        //@brief member variable to help keep track of the cards placed on the table
        Table m_table;
};

#endif
