#include "weightedstrategy.h"

Card* WeightedStrategy::determineNextCardinDeck(Deck& deck, size_t currentIndex)
{
    std::vector<Card*> vectorCopy = deck.getCards();
    std::sort(vectorCopy.begin(), vectorCopy.end(), [](const Card* lhs, const Card* rhs){
        return *lhs < *rhs;
    });
    return vectorCopy.at(0);
}
