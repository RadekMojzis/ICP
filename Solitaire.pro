#-------------------------------------------------
#
# Project created by QtCreator 2017-05-05T20:54:27
#
#-------------------------------------------------

QT       += core gui

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


SOURCES += main.cpp\
        mainwindow.cpp\
				src\PPU.cpp\
				src\GPU.cpp\
				src\action.cpp\
				src\card.cpp\
				src\deck.cpp\
				src\flip.cpp\
				src\foundation.cpp\
				src\game.cpp\
				src\pile.cpp\
				src\program.cpp
				
				
HEADERS  += mainwindow.h\
					src\interface.hpp\
					src\PPU.hpp\
					src\GPU.hpp\
					src\action.hpp\
					src\card.hpp\
					src\deck.hpp\
					src\flip.hpp\
					src\foundation.hpp\
					src\game.hpp\
					src\pile.hpp\
					src\program.hpp\
					src\interface.hpp
					
FORMS    += mainwindow.ui
