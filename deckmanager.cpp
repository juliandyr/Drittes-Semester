#include "deckmanager.h"
#include "fillincard.h"
#include "singlechoicecard.h"
#include "textcard.h"
#include <fstream>
#include <iostream>

DeckManager::DeckManager() {}

Deck DeckManager::createDefaultDeck()
{
    auto deck = Deck();

    std::vector<std::string>options1 = {"1","2","3","4"};
    Card* card1 = new SingleChoiceCard("Wie viele Bytes hat ein Float?",options1,3);
    deck.addCard(card1);

    std::vector<std::string>options2 = {"for", "do-while", "if", "while"};
    Card* card2 = new SingleChoiceCard("Was ist keine gültige Schleife?",options2,2);
    deck.addCard(card2);

    std::vector<std::string>options3 = {"extends",":","inherits","implements"};
    Card* card3 = new SingleChoiceCard("Wie wird in C++ Vererbung implementiert?",options3,1);
    deck.addCard(card3);

    std::vector<std::string>answers1 = {"int","a+b"};
    Card* card4 = new FillInCard("Vervollstaendigen Sie die Funktion:\n int add(int a, int b) {\n ___ a, b;\nreturn ___;\n }",answers1,',');
    deck.addCard(card4);

    std::vector<std::string>answers2 = {"War mir bekannt", "War mir nicht bekannt"};
    Card* card5 = new TextCard("Die Standards C++11, C++98 oder C++23 stehen fuer die Jahre,\n in denen sie veroeffentlicht wurden. \n Bitte nur mit '1' oder '2' antworten",answers2);
    deck.addCard(card5);

    return deck;
}

Deck DeckManager::loadDeck(std::string path) //Deck wird per wert kopiert->
    //beide decks zeigen auf gleichen Pointer-> Delete zweimal auf die gleiche adresse
{
    std::ifstream file(path);

    if(!file.is_open()){
        std::cerr << "Datei konnte nicht geöffnet werden" << std::endl;
        return Deck();
    }

    std::vector<Card*>cards;

    nlohmann::json Jfile;

    file >> Jfile; std::cout <<  "JSON wurde geladen" << std::endl;

    auto deck = Deck();
    double counterTextCard = 0, counterFillInCard = 0, counterSingleChoiceCard = 0;
    double sumTextcard = 0, sumSingleChoiceCard = 0, sumFillInCard = 0;

    for(const auto& card : Jfile["Karten "]){
        if(card["type"] == "text"){
            std::vector<std::string>options;
            for(const auto& option: card["Options"]){
                std::string optionAttribut;
                optionAttribut = option.at(1).get<std::string>();
                options.push_back(optionAttribut);
            }
            double score = card["Score"];
            TextCard* textCard1 = new TextCard(card["Question"], options); std::cout << "TextCard wurde aus JSON erstellt" << std::endl;
            deck.addCard(textCard1);
            counterTextCard++;
            sumTextcard += score;
        }
        else if(card["type"] == "single"){
            std::vector<std::string>options;
            for(const auto& option: card["Options"]){
                std::string optionAttribut;
                optionAttribut = option.at(1).get<std::string>();
                options.push_back(optionAttribut);
            }
            double score = card["Score"];
            SingleChoiceCard* singleChoiceCard1 = new SingleChoiceCard(card["Question"], options, card["CorrectIndex"]); std::cout << "SingleChoiceCard wurde aus JSON erstellt" << std::endl;
            deck.addCard(singleChoiceCard1);
            counterSingleChoiceCard++;
            sumSingleChoiceCard += score;
        }
        else if(card["type"] == "fillin"){
            std::string delimiter = "";
            char delimiterChar = ' ';
            std::vector<std::string>answers;
            for(const auto& answer: card["Antworten"]){
                std::string answerAttribut;
                answerAttribut = answer.at(1).get<std::string>();
                answers.push_back(answerAttribut);
            }
            double score = card["Score"];
            delimiterChar = (char)card["Delimiter"].get<int>(); //std::cout << "Delimiter hinzugefügt" << std::endl;
            FillInCard* singleChoiceCard1 = new FillInCard(card["Question"], answers, delimiterChar);std::cout << "FillinCard wurde aus JSON erstellt" << std::endl;
            deck.addCard(singleChoiceCard1);
            counterFillInCard++;
            sumFillInCard += score;
        }
    }
    if(counterTextCard > 0){
        std::cout << "Anzahl Textcards: " << counterTextCard << "\n" << "Durschnittsscore TextCards: " << sumTextcard/counterTextCard << std::endl;
    }
    else{
        std::cout << "Keine Karte dieses Typs";
    }
    if(counterFillInCard > 0){
        std::cout <<  "Anzahl FillinCards" << counterFillInCard << "\n" <<"Durschnittsscore FillinCards: " << sumFillInCard/counterFillInCard << std::endl;
    }
    else{
        std::cout << "Keine Karte dieses Typs";
    }
    if(counterSingleChoiceCard > 0){
        std::cout <<  "Anzahl SingleChoiceCards: " << counterSingleChoiceCard << "\n" <<"Durschnittsscore SingleChoiceCards: " << sumSingleChoiceCard/counterSingleChoiceCard << std::endl;
    }
    else{
        std::cout << "Keine Karte dieses Typs";
    }

    return deck;
}

void DeckManager::saveDeck(Deck &deck, std::string path)

{   nlohmann::json deckJson;
    for(auto& card : deck.getCards()){
        deckJson["Karten "].push_back(card->createjsonObject()); std::cout << "Karte in Deck in JSON" << std::endl;
    }
    std::ofstream outfile(path); //wo muss diese Zeile hin?
    outfile << deckJson.dump(2); std::cout << "JSON Datei bereit" << std::endl;
}




