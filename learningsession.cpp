#include "learningsession.h"


LearningSession::LearningSession(Deck &deck) : deck(deck)
{
    currentIndex = 0; //muss der bei 0 anfangen?
    currentCard = nullptr;
    score = 0;
}

Card *LearningSession::nextCard()
{
    if(hasNextCard()){
    Card* nextCard = deck.getCard(currentIndex+1);
        currentIndex++;
        return nextCard;
    }
}

bool LearningSession::hasNextCard()
{
    //deck.getCards() gibt mir vektor;
    if(currentIndex+1 >= deck.getSize()){
        return false;
    }
    else{
        return true;
    }

}

bool LearningSession::checkAnswer(std::string input)
{
    if(deck.getCard(currentIndex)->checkAnswer(input)){
        score++;
        return true;
    }
    else{
        score--;
        return false;
    }
}

Deck &LearningSession::getDeck() const
{
    return deck;
}
