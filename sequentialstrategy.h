#ifndef SEQUENTIALSTRATEGY_H
#define SEQUENTIALSTRATEGY_H

#include "learningstrategy.h"

class SequentialStrategy : public LearningStrategy
{
public:
    Card* determineNextCardinDeck(Deck& deck, size_t currentIndex) override;
};

#endif // SEQUENTIALSTRATEGY_H
