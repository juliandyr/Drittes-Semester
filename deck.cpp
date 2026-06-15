#include "deck.h"

Deck::Deck() {}

Deck::Deck(const std::string title)
{
    this->title = title;
}

Deck::~Deck()
{
    for(auto& card: cards){
        delete card;
    }
}

Deck::Deck(Deck&& other) : title(std::move(other.title)), cards(std::move(other.cards))
{
    other.cards.clear();
}

Deck::Deck(const Deck& other) : title(other.title)
{
    for(auto card : other.cards){
        this->cards.push_back(card->clone());
    }
}

Deck& Deck::operator=(Deck rhs)
{
    swap(*this, rhs);
    return *this;
}

void Deck::addCard(Card* card)
{
    cards.push_back(card);
}

std::vector<Card*> Deck::getCards() const
{
    return cards;
}

Card* Deck::getCard(int index)
{
    return cards.at(index);
}

size_t Deck::getSize()
{
    return cards.size();
}
