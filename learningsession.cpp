#include "learningsession.h"

LearningSession::LearningSession(Deck& deck, LearningStrategy* strategy)
    : deck(deck), strategy(strategy)
{
    currentIndex = 0;
    currentCard = nullptr;
    score = 0;
}

Card* LearningSession::nextCard()
{
    if(hasNextCard()){
        Card* next = strategy->determineNextCardinDeck(deck, currentIndex);
        currentIndex++;
        return next;
    }
    return nullptr;
}

bool LearningSession::hasNextCard()
{
    if(currentIndex >= deck.getSize()){
        return false;
    }
    return true;
}

bool LearningSession::checkAnswer(std::string input)
{
    if(deck.getCard(currentIndex-1)->checkAnswer(input)){
        score++;
        return true;
    }
    else{
        score--;
        return false;
    }
}

Deck& LearningSession::getDeck() const
{
    return deck;
}
