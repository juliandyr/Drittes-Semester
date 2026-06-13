#ifndef LEARNINGSESSION_H
#define LEARNINGSESSION_H


#include "deck.h"
class LearningSession
{
public:
    LearningSession(Deck& deck);
    Card* nextCard();
    bool hasNextCard();
    bool checkAnswer(std::string input);



    Deck &getDeck() const;

private:
    //speichert deck als datenstruktur,
    Deck& deck;
    size_t currentIndex;
    Card* currentCard;
    int score;
};

#endif // LEARNINGSESSION_H
