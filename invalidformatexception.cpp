#include "invalidformatexception.h"

InvalidFormatException::InvalidFormatException(int indexOfCardWithInvalidFormat, const std::string &errorText, const std::string &errorMessage)
    : DeckException(errorMessage),
    indexOfCardWithInvalidFormat(indexOfCardWithInvalidFormat),
    errorText(errorText)
{}

int InvalidFormatException::getIndexOfCardWithInvalidFormat() const
{
    return indexOfCardWithInvalidFormat;
}

std::string InvalidFormatException::getErrorText() const
{
    return errorText;
}
