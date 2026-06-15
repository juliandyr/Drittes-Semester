#ifndef FILEEXCEPTION_H
#define FILEEXCEPTION_H

#include "deckexception.h"
#include <string>

class FileException : public DeckException
{
public:
    FileException(const std::string& nameOfFile, const std::string& errorMessage);
    std::string getNameOfFile() const;

private:
    std::string nameOfFile;
};

#endif // FILEEXCEPTION_H
