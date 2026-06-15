#include "singlechoicecard.h"
#include <algorithm>

//SingleChoiceCard::SingleChoiceCard() {}

SingleChoiceCard::SingleChoiceCard(const std::string question, const std::vector<std::string> &options, int correctIndex) : options(options),
    correctIndex(correctIndex)
{
    this->question = question;
}

bool SingleChoiceCard::checkAnswer(const std::string &input)
{
    std::string normalizedString = normalize(input);
    if(normalizedString == normalize(options.at(correctIndex)) || normalizedString == std::to_string(correctIndex+1)){
        score++;
        return true;
    }
        score--;
        return false;
}

void SingleChoiceCard::render(CardView &view)
{
    view.showText(question);
    view.showOptions(options);
}

std::string SingleChoiceCard::normalize(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c)
                                                                            ; });
    s.erase( std::remove_if(s.begin(), s.end(), [](unsigned char c){ return std::isspace(c);
            }), s.end());
    return s;
}

nlohmann::json SingleChoiceCard::createjsonObject()
{
    nlohmann::json singleChoiceCardjson;

    singleChoiceCardjson["Question"] = question;
    singleChoiceCardjson["Score"] = score;
    for(auto& option : options){
        singleChoiceCardjson["Options"].push_back({"Option: ", option});
    }
    singleChoiceCardjson["CorrectIndex"] = correctIndex;
    singleChoiceCardjson["type"] = "single";
    return singleChoiceCardjson;

}

Card* SingleChoiceCard::clone() const
{
    SingleChoiceCard* cloned = new SingleChoiceCard(question, options, correctIndex);
    cloned->setScore(this->score);
    return cloned;
}
