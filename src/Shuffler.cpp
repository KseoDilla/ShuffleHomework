#include <deque> //already included in the header file but it's nice to be explicit
#include <iostream> //for print32_ting std::cout
#include "Shuffler.h"
#include <stdint.h>

Shuffler::Shuffler()
:m_deck(0), m_table()
{
}



Shuffler::Shuffler(int32_t numOfCards)
: m_deck(numOfCards), m_table()
{
}


Shuffler::~Shuffler()
{
}


int32_t Shuffler::start()
{
    int32_t numOfRounds = 0;
    Deck originalDeck;

    std::cout << "Beginning shuffle..." << std::endl;
    while(originalDeck != m_deck)
    {
        //if it's the first round than originalDeck has not been populated
        //int32_tialize it to remember what our deck looked like
        if(numOfRounds == 0)
        {
            originalDeck = m_deck;
        }

        //Let's shuffle!
        shuffle();

        //print iteration to provide feedback
        std::cout << "Round " <<  ++numOfRounds << ": ";
        m_deck.print();
        std::cout << std::endl; 
    }
    std::cout << "...Done!" << std::endl;
    return numOfRounds;
}



const std::deque<int32_t>& Shuffler::getDeck() const
{
    return m_deck.getCards();
}



void Shuffler::shuffle()
{
    bool dealingMode = true;
    while(!m_deck.isEmpty())
    {
        //grab the card off the top of the deck
        //if dealingMode is false put it at the bottom of the deck in our hand
        //if dealingMode is true put it on top of the table (like a stack)
        //a ternary operator would make this a lot cleaner to read
        int32_t card = m_deck.popFront(dealingMode);
        if(dealingMode)
        {
            m_table.placeCard(card);
        }
        dealingMode = !dealingMode;
    }
    m_deck = m_table.getDeck();
    m_table.clear();
}
