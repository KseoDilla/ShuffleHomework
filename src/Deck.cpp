#include <algorithm>
#include <deque>
#include <iostream>
#include <stdint.h>

#include "Deck.h"

Deck::Deck()
: m_cards()
{
}

Deck::Deck(std::deque<int32_t>& cards)
: m_cards(cards)
{
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

void Deck::print32_t() const
{
    //print32_t the deque backwards like you're reading the cards face down
    std::for_each(
            m_cards.rbegin(),
            m_cards.rend(),
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
