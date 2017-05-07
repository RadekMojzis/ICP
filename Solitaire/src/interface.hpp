

#pragma once

#include <iostream>
#include <vector>

#include "card.hpp"
#include "game.hpp"
#include "gcard.h"

#include <QApplication>
#include <QtWidgets>
#include <QLabel>

using namespace std;

class PPU{
    // you put cards from deck here
    private:
        Game game;
    public:
        void new_game();
        void draw_game();
        void draw_deck(DeckID id);
        void draw_card(Card *card);
        PPU();
        ~PPU();
};

class GPU{
    // you put cards from deck here
    private:
        QWidget window;
        vector <QPixmap*> cards;
        void load_images();

        vector<gcard*> hearts;
        vector<gcard*> spades;
        vector<gcard*> clubs;
        vector<gcard*> diamonds;
        vector<gcard*> pile0;
        vector<gcard*> pile1;
        vector<gcard*> pile2;
        vector<gcard*> pile3;
        vector<gcard*> pile4;
        vector<gcard*> pile5;
        vector<gcard*> pile6;
        vector<gcard*> flip;
        vector<gcard*> stock;

    public:
        Game game;
        void new_game();
        void draw_game();
        void draw_deck(DeckID deck);
        void draw_card(Card *card, DeckID decks);
        int run();
        void clear();
        GPU();
        ~GPU();
};
