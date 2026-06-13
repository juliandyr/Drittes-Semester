#include "terminalcontroller.h"
#include "terminalcardview.h"
#include <iostream>


TerminalController::TerminalController(LearningSession &learningSesssion, CardView &view)
    : Controller(learningSesssion, view)
{}

void TerminalController::start()
{
    //Deck deck = Deck();
    //View view = View();

    Deck& deck = learningSession.getDeck();

    for (size_t i = 0; i < deck.getSize(); ++i){ ////while schleife bis stop?

        auto deckCard = deck.getCard(i);

        deckCard->render(view);

        view.showInputField();

        std::string input;
        std::getline(std::cin, input);

        bool correct = deckCard->checkAnswer(input);

        view.showFeedback(correct);
        //std::cout << "start() aufgerufen, Deck hat " << deck.getSize() << " Karten" << std::endl;
        //int score = deckCard->getScore();
        //view.showScore(score);

    }
}

void TerminalController::end()
{

    std::cout << "Vokabeltrainer beendet" << std::endl;
    return;
}
