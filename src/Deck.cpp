#include <algorithm>
#include <deque>
#include <iostream>
#include <stdint.h>

#include "Deck.h"

Deck::Deck()
: m_cards()
{
}

Deck::Deck(int32_t numOfCards)
: m_cards()
{
    for(int32_t i = 1; i <= numOfCards; ++i)
    {
        m_cards.push_back(i);
    }
}


Deck::Deck(Deck& incomingDeck)
: m_cards(incomingDeck.getCards())
{
}

Deck::~Deck()
{
}


int32_t Deck::popFront(const bool shuffleMode)
{
    int32_t card = m_cards.front();
    shuffleMode ? m_cards.pop_front() : putBelowDeck();
    return card;
}


void Deck::pushFront(int32_t card)
{
    m_cards.push_front(card);
}


void Deck::putBelowDeck()
{
    m_cards.push_back(m_cards.front());
    m_cards.pop_front();
}

void Deck::print() const
{
    //print the deck in order
    std::for_each(
            m_cards.begin(),
            m_cards.end(),
            [](int32_t const &i) {
            std::cout << i << ' ';
            });
    std::cout << std::endl;
}


const std::deque<int32_t>& Deck::getCards() const
{
    return m_cards;
}


const bool Deck::isEmpty() const
{
    return m_cards.empty();
}


bool Deck::operator==(const Deck& rhs) const
{
    return getCards() == rhs.getCards();
}

bool Deck::operator!=(const Deck& rhs) const
{
    return !(getCards() == rhs.getCards());
}
