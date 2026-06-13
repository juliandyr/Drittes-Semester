#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <learningsession.h>


class Controller
{
public:
    Controller(LearningSession &learningSession, CardView &view);
    virtual ~Controller() = default;
    virtual void start() = 0;
    virtual void end() =0;

protected:
    LearningSession& learningSession;
    CardView& view;
};

#endif // CONTROLLER_H
