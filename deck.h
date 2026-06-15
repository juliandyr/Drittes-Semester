#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>

class Deck
{
public:
    Deck();
    Deck(const std::string title);
    ~Deck();
    Deck(Deck&& other);
    Deck(const Deck& other);
    Deck& operator=(Deck rhs);

    void addCard(Card* card);
    std::vector<Card*> getCards() const;
    Card* getCard(int index);
    size_t getSize();

    friend void swap(Deck& a, Deck& b){
        std::swap(a.title, b.title);
        std::swap(a.cards, b.cards);
    }

private:
    std::string title;
    std::vector<Card*> cards;
};

#endif // DECK_H
