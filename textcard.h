#ifndef TEXTCARD_H
#define TEXTCARD_H

#include "card.h"
#include "json.hpp"

class TextCard : public Card
{
public:
    TextCard(const std::string question, const std::vector<std::string> options);
    bool checkAnswer(const std::string& input) override;
    void render(CardView& view) override;
    nlohmann::json createjsonObject() override;
    Card* clone() const override;

private:
    std::vector<std::string> options;
};

#endif // TEXTCARD_H
