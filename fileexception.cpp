#include "fileexception.h"

FileException::FileException(const std::string &nameOfFile, const std::string &errorMessage)
    : DeckException(errorMessage), nameOfFile(nameOfFile)
{}

std::string FileException::getNameOfFile() const
{
    return nameOfFile;
}
