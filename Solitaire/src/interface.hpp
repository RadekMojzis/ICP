

#pragma once
#include <iostream>
#include "card.hpp"
#include "game.hpp"


class PPU{
    // you put cards from deck here
    private:
        Game game;
    public:
        void draw_game(){};
        void draw_deck(){};
        void draw_card(Card &card);
        void init();
        PPU(){};
        ~PPU();
};


class GPU{
    // you put cards from deck here
    private:
    public:
        void init(){};
        void draw_game(){};
        void draw_deck(){};
        void draw_card(Card &card);
        GPU(){};
        ~GPU(){};
};
