#ifndef TERMINALCONTROLLER_H
#define TERMINALCONTROLLER_H


#include "controller.h"
#include "terminalcardview.h"

class TerminalController : public Controller
{
public:
    TerminalController(LearningSession &learningSesssion, CardView &view);
    void start() override;
    void end() override;

};

#endif // TERMINALCONTROLLER_H
