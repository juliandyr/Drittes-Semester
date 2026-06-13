#include "textcard.h"

TextCard::TextCard(const std::string question, const std::vector<std::string> options) {
    this->question = question;
    this->options = options;
}

bool TextCard::checkAnswer(const std::string &input)
{
    if(input == "yes"|| input == "1"){
        score++;
        return true;}///////////////Abfangen ungültiger Antworten!
    else if(input == "no" || input == "2"){
        score--;
        return false;}
    else return false;
}

void TextCard::render(CardView &view)
{
    view.showText(question);
    view.showOptions(options);
}

nlohmann::json TextCard::createjsonObject()
{
    nlohmann::json TextCardjson;

    TextCardjson["Question"] = question;
    TextCardjson["Score"] = score;
    TextCardjson["type"] = "text";
    for(auto& option : options){
        TextCardjson["Options"].push_back({"Option: ", option});
    }

    return TextCardjson;

}
