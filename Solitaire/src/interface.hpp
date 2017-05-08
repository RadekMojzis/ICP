

#pragma once

#include <iostream>
#include <vector>

#include "card.hpp"
#include "game.hpp"

#include <QApplication>
#include <QtWidgets>
#include <QLabel>

using namespace std;

class PPU{
    // you put cards from deck here
    private:
        vector<Game> game;
        int active = 0;
    public:
        bool execute(string command);
        void new_game();
        void draw_game();
        void draw_deck(DeckID id);
        void draw_card(Card *card);
        void change_focus(int i);
        PPU();
        ~PPU();
};
