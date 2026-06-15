#ifndef LEARNINGSESSION_H
#define LEARNINGSESSION_H

#include "deck.h"
#include "learningstrategy.h"

class LearningSession
{
public:
    LearningSession(Deck& deck, LearningStrategy* strategy);
    Card* nextCard();
    bool hasNextCard();
    bool checkAnswer(std::string input);
    Deck& getDeck() const;

private:
    Deck& deck;
    LearningStrategy* strategy;
    size_t currentIndex;
    Card* currentCard;
    int score;
};

#endif // LEARNINGSESSION_H
