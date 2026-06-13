#include "terminalcardview.h"
#include <iostream>

TerminalCardView::TerminalCardView() {}

void TerminalCardView::showText(std::string text)
{
    std::cout << "Aufgabenstellung: " << text << std::endl;
}

void TerminalCardView::showOptions(std::vector<std::string> options)
{
    int i = 0;
    for(auto& option : options){
        i++;
        std::cout << "Antwortmöglichkeit " << i << ": " << option << std::endl;
    }
}

void TerminalCardView::showInputField()
{   //std::string option = " ";
    std::cout << "Sie dürfen ihre Antwort nun eingeben: " << std::endl;
    //std::cin >> option;
}

void TerminalCardView::showFeedback(bool correct)
{
    if(correct){
        std::cout << "Antwort war korrekt! " << std::endl;
    }
    else{
        std::cout << "Antwort leider falsch" << std::endl;
    }
}

void TerminalCardView::clear()
{
    std::cout << std::endl << std::endl;
}

void TerminalCardView::showScore(int score)
{
    std::cout << "Score: " << score << std::endl;
}
