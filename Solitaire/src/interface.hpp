

#pragma once
#include <iostream>
#include "card.hpp"
#include "game.hpp"
#include <iostream>

class PPU{
    // you put cards from deck here
    private:
    public:
        void draw_game(){};
        void draw_deck(){};
        void draw_card(Card &card);
        PPU(){};
        ~PPU(){};
};


class GPU{
    // you put cards from deck here
    private:
    public:
        void draw_game(){};
        void draw_deck(){};
        void draw_card(Card &card);
        GPU(){};
        ~GPU(){};
};