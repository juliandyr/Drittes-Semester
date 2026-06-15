#ifndef LEARNINGSTRATEGY_H
#define LEARNINGSTRATEGY_H

#include "card.h"
#include "deck.h"

class LearningStrategy
{
public:
    virtual ~LearningStrategy() = default;
    virtual Card* determineNextCardinDeck(Deck& deck, size_t currentIndex) = 0;
};

#endif // LEARNINGSTRATEGY_H
