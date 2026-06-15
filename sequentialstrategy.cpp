#include "sequentialstrategy.h"

Card* SequentialStrategy::determineNextCardinDeck(Deck& deck, size_t currentIndex)
{
    return deck.getCard(currentIndex);
}
