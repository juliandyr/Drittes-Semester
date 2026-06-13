#ifndef DECKMANAGER_H
#define DECKMANAGER_H

#include "deck.h"
class DeckManager
{
public:
    DeckManager();
    static Deck createDefaultDeck();
    static Deck loadDeck(std::string path);
    static void saveDeck(Deck& deck, std::string path);


};

#endif // DECKMANAGER_H
