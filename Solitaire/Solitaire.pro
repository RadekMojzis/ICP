#-------------------------------------------------
#
# Project created by QtCreator 2017-05-05T20:54:27
#
#-------------------------------------------------

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Solitaire
TEMPLATE = app
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

SOURCES += main.cpp
SOURCES += src/PPU.cpp
SOURCES += src/GPU.cpp
SOURCES += src/action.cpp
SOURCES += src/card.cpp
SOURCES += src/deck.cpp
SOURCES += src/flip.cpp
SOURCES += src/foundation.cpp
SOURCES += src/game.cpp
SOURCES += src/pile.cpp
SOURCES += src/stock.cpp
SOURCES += src/program.cpp
SOURCES += src/gcard.cpp

HEADERS += src/interface.hpp
HEADERS += src/action.hpp
HEADERS += src/card.hpp
HEADERS += src/deck.hpp
HEADERS += src/game.hpp
HEADERS += src/program.hpp
HEADERS += src/gcard.h
