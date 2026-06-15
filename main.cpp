#include "deck.h"
#include "fileexception.h"
#include "fillincard.h"
#include "invalidformatexception.h"
#include "sequentialstrategy.h"
#include "singlechoicecard.h"
#include "terminalcardview.h"
#include "terminalcontroller.h"
#include "textcard.h"
#include <iostream>
#include <card.h>
#include "deckmanager.h"
#include "weightedstrategy.h"


int main()
{
    //Deck deck = DeckManager::createDefaultDeck();
    // Alternativ:
    try{
        //SequentialStrategy strategy;
        WeightedStrategy strategy;
        Deck deck = DeckManager::loadDeck("../myDeck.json");
        LearningSession session(deck, &strategy);
        TerminalCardView view;
        TerminalController controller(session, view);
        controller.start();
        DeckManager::saveDeck(deck, "../myDeck.json");
        controller.end();
    }
    catch(const FileException& e){
        std::cerr << e.what() << std::endl;
        std::cerr << "Datei: " << e.getNameOfFile() << std::endl;
        std::cerr << "Zeitpunkt: " << e.getTimeOfErrorOccurring() << std::endl;
    }
    catch(const InvalidFormatException& e){
        std::cerr << e.what() << std::endl;
        std::cerr << "Kartenindex: " << e.getIndexOfCardWithInvalidFormat() << std::endl;
        std::cerr << "Fehlerfeld: " << e.getErrorText() << std::endl;
        std::cerr << "Zeitpunkt: " << e.getTimeOfErrorOccurring() << std::endl;
    }
    return 0;
}
