#ifndef CARD_H
#define CARD_H




#include "cardview.h"
#include "json.hpp"
#include <string>
class Card
{
public:
    Card();
    virtual ~Card() = default;
    virtual bool checkAnswer(const std::string& input) = 0;
    virtual void render(CardView& view) = 0;
    virtual nlohmann::json createjsonObject() = 0;


    int getScore() const;

protected:
    std::string question;
    int score;
};

#endif // CARD_H
