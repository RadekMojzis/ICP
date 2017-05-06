

#pragma once
#include <iostream>
#include "card.hpp"
#include "game.hpp"
#include <QApplication>

#include "mainwindow.h"

class PPU{
    // you put cards from deck here
    private:
        Game game;
    public:
        void draw_game();
        void draw_deck(DeckID id);
        void draw_card(Card *card);
        void init();
        PPU(){};
        ~PPU(){};
};


class GPU{
    // you put cards from deck here
    private:
        MainWindow w;
    public:
        void draw_game();
        void draw_deck(DeckID id);
        void draw_card(Card *card);
        int run();
        GPU(){};
        ~GPU(){};
};
