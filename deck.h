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
    void addCard(Card* card);
    std::vector<Card *> getCards() const;
    Card* getCard(int index);
    size_t getSize();

private:
    std::string title;
    std::vector<Card*>cards;
};

#endif // DECK_H
