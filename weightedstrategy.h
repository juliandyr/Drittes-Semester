#ifndef WEIGHTEDSTRATEGY_H
#define WEIGHTEDSTRATEGY_H

#include "learningstrategy.h"
#include <algorithm>
#include <vector>

class WeightedStrategy : public LearningStrategy
{
public:
    Card* determineNextCardinDeck(Deck& deck, size_t currentIndex) override;
};

#endif // WEIGHTEDSTRATEGY_H
