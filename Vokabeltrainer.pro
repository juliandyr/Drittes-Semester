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
        fillincard.cpp \
        learningsession.cpp \
        main.cpp \
        singlechoicecard.cpp \
        terminalcardview.cpp \
        terminalcontroller.cpp \
        textcard.cpp

HEADERS += \
    card.h \
    cardview.h \
    controller.h \
    deck.h \
    deckexception.h \
    deckmanager.h \
    fillincard.h \
    learningsession.h \
    singlechoicecard.h \
    terminalcardview.h \
    terminalcontroller.h \
    textcard.h \
    json.hpp

