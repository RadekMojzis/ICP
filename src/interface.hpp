

#pragma once
#include <iostream>
#include "card.hpp"
#include "game.hpp"

enum IF_TYPE{
    GUI,
    TEXT
};

class interface{
	// you put cards from deck here
    protected:
		Game game;
		DeckID drawing_deck;
		
        virtual void draw_game() = 0;
        virtual void draw_card(Card &card) = 0;
        virtual void change_drawing_deck(DeckID dst) = 0;

	public:
        interface();
};
