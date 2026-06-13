#ifndef CARDVIEW_H
#define CARDVIEW_H



#include <string>
#include <vector>
class CardView
{
public:
    CardView();
    virtual ~CardView() = default;
    virtual void showText(std::string text) = 0;
    virtual void showOptions(std::vector<std::string>options) = 0;
    virtual void showInputField()= 0;
    virtual void showFeedback(bool correct)= 0;
    virtual void clear()= 0;
};

#endif // CARDVIEW_H
