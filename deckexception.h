#ifndef DECKEXCEPTION_H
#define DECKEXCEPTION_H

#include <stdexcept>
#include <ctime>

class DeckException : public std::runtime_error
{
public:
    DeckException(const std::string& errorMessage);
    int getTimeOfErrorOccurring() const;

private:
    int timeOfErrorOccurring;
};

#endif // DECKEXCEPTION_H
