#include "deckexception.h"

DeckException::DeckException(const std::string &errorMessage)
    : std::runtime_error(errorMessage)
{
    timeOfErrorOccurring = std::time(nullptr);
}

int DeckException::getTimeOfErrorOccurring() const
{
    return timeOfErrorOccurring;
}
