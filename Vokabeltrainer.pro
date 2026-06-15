TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        card.cpp \
        cardview.cpp \
        controller.cpp \
        deck.cpp \
        deckexception.cpp \
        deckmanager.cpp \
        fileexception.cpp \
        fillincard.cpp \
        invalidformatexception.cpp \
        learningsession.cpp \
        learningstrategy.cpp \
        main.cpp \
        sequentialstrategy.cpp \
        singlechoicecard.cpp \
        terminalcardview.cpp \
        terminalcontroller.cpp \
        textcard.cpp \
        weightedstrategy.cpp

HEADERS += \
    card.h \
    cardview.h \
    controller.h \
    deck.h \
    deckexception.h \
    deckmanager.h \
    fileexception.h \
    fillincard.h \
    invalidformatexception.h \
    learningsession.h \
    learningstrategy.h \
    sequentialstrategy.h \
    singlechoicecard.h \
    terminalcardview.h \
    terminalcontroller.h \
    textcard.h \
    json.hpp \
    weightedstrategy.h

