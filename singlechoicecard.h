#ifndef SINGLECHOICECARD_H
#define SINGLECHOICECARD_H

#include "card.h"
#include <vector>
#include <json.hpp>

class SingleChoiceCard : public Card
{
public:
    SingleChoiceCard(const std::string question, const std::vector<std::string> &options, int correctIndex);

    bool checkAnswer (const std::string& input) override;
    void render(CardView& view) override;
    std::string normalize(std::string input);

    nlohmann::json createjsonObject() override;

private:
    std::vector<std::string>options;
    int correctIndex;
};

#endif // SINGLECHOICECARD_H
