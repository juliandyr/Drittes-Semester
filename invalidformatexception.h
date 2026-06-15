#ifndef INVALIDFORMATEXCEPTION_H
#define INVALIDFORMATEXCEPTION_H

#include "deckexception.h"
#include <string>

class InvalidFormatException : public DeckException
{
public:
    InvalidFormatException(int indexOfCardWithInvalidFormat, const std::string& errorText, const std::string& errorMessage);
    int getIndexOfCardWithInvalidFormat() const;
    std::string getErrorText() const;

private:
    int indexOfCardWithInvalidFormat;
    std::string errorText;
};

#endif // INVALIDFORMATEXCEPTION_H
