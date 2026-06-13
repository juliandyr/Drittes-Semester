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
    //cards.erase();
}

Deck::Deck(Deck &&other) : title(std::move(other.title)), cards(std::move(other.cards)) //Kopierkonstruktor-> für jede Karte ein neues Objekt
//move: keine neuen Objekte werden erstellt
{
    other.cards.clear();
}



// Deck::Deck(Deck &otherDeck)
// {
//     this->title = otherDeck.title;
//     this->cards = otherDeck.getCards();
// }

void Deck::addCard(Card *card)
{
    cards.push_back(card);
}

std::vector<Card *> Deck::getCards() const
{
    return cards;
}

Card *Deck::getCard(int index)
{
    return cards.at(index);
}

size_t Deck::getSize()
{
    return cards.size();
}
