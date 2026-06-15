#ifndef FILLINCARD_H
#define FILLINCARD_H

#include "card.h"
#include "json.hpp"
#include <vector>

class FillInCard : public Card
{
public:
    FillInCard(const std::string question, const std::vector<std::string> &answers, char delimiter);

    bool checkAnswer(const std::string& input) override;
    void render(CardView& view) override;
    std::string normalize(std::string input);
    std::vector<std::string> parseInput(const std::string& input, const char delim);
    nlohmann::json createjsonObject() override;
    Card* clone() const override;

private:
    std::vector<std::string> answers;
    char delimiter;
};

#endif // FILLINCARD_H
