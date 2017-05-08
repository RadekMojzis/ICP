

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

const int FOUNDATION_X = 1050;

class GPU{
    // you put cards from deck here
    private:
        QWidget window;
        vector <QPixmap*> cards;
        void load_images();

        vector<vector<gcard*>> foundations;
        vector<vector<gcard*>> piles;
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
