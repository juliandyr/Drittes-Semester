#ifndef TERMINALCARDVIEW_H
#define TERMINALCARDVIEW_H

/*Anmerkungen:
 * showInputField()???!!!
*/


#include "cardview.h"

class TerminalCardView : public CardView
{
public:
    TerminalCardView();
     void showText(std::string text) override;
     void showOptions(std::vector<std::string>options)override ;
     void showInputField()override;
     void showFeedback(bool correct)override;
     void clear()override;
     void showScore(int score);
};

#endif // TERMINALCARDVIEW_H
