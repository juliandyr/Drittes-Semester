#include "deck.h"
#include "fillincard.h"
#include "singlechoicecard.h"
#include "terminalcardview.h"
#include "terminalcontroller.h"
#include "textcard.h"
#include <iostream>
#include <card.h>
#include "deckmanager.h"


int main()
{
    //Deck deck = DeckManager::createDefaultDeck();
    // Alternativ:
    Deck deck = DeckManager::loadDeck( "../myDeck.json");
    LearningSession session(deck);
    TerminalCardView view;
    TerminalController controller(session, view);
    controller.start();

    DeckManager::saveDeck(deck, "../myDeck.json");

    controller.end();
    return 0;
}
