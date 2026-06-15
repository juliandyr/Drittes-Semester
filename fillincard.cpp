#include "fillincard.h"
#include <algorithm>


FillInCard::FillInCard(const std::string question,const std::vector<std::string> &answers, char delimiter) : answers(answers),
    delimiter(delimiter)
{
    this->question = question;
}

bool FillInCard::checkAnswer(const std::string &input)
{
    std::string normalizedString = normalize(input);
    auto parsedInputVector = parseInput(normalizedString,',');
    size_t counter = 0;
    if(parsedInputVector.size() != answers.size()){
        score--;
        return false;
    }
    for(size_t i = 0; i<answers.size(); ++i){
        //if i = i:
        //counter++;
        // answers:           |3| |4| |5|
        // parsedInputvector: |3| |2| |5|
        // erst wenn counter == answer.size() == dann return true;
        //sonst 2 != 3, false;
        if(normalize(parsedInputVector.at(i)) == normalize(answers.at(i))){
            counter++;
        }
    }
    if(counter == answers.size() && counter == parsedInputVector.size()){
        score++;
        return true;
    }
    else{
        score--;
        return false;
    }
}

void FillInCard::render(CardView &view)
{
    view.showText(question);
    //view.showOptions(answers);
}

std::string FillInCard::normalize(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c)
                                                                            ; });
    s.erase( std::remove_if(s.begin(), s.end(), [](unsigned char c){ return std::isspace(c);
            }), s.end());
    return s;
}




std::vector<std::string> FillInCard::parseInput(const std::string& input, const char delim) {
    std::vector<std::string> result;
    std::string current;
    for (char c : input) {
        if (c == delim) {
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else {
            current += c;
        }
    }
    if (!current.empty()) {
        result.push_back(current);
    }
    return result;
}

nlohmann::json FillInCard::createjsonObject()
{
    nlohmann::json FillInCardjson;

    FillInCardjson["Question"] = question;
    FillInCardjson["Score"] = score;
    for(auto& answer : answers){
        FillInCardjson["Antworten"].push_back({"Antwortmöglichkeit: ", answer}); //FillInCardjson["Antworten"] = answers wäre auch gegangen!
    }
    FillInCardjson["Delimiter"] = delimiter;
    FillInCardjson["type"] = "fillin";
    return FillInCardjson;

}

Card* FillInCard::clone() const
{
    FillInCard* cloned = new FillInCard(question, answers, delimiter);
    cloned->setScore(this->score);
    return cloned;
}
