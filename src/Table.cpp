#include "Table.h"
#include <deque> //already included in the header file but it's nice to be explicit
#include <stdint.h>

Table::Table()
:m_deck()
{
}



Table::~Table()
{
}



void Table::placeCard(int32_t card)
{
    m_deck.pushFront(card);
}



Deck Table::getDeck()
{
    return m_deck;
}



void Table::clear()
{
    m_deck = Deck();
}



bool Table::isEmpty()
{
    return m_deck.isEmpty();
}
