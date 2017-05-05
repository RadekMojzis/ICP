

#pragma once
#include <iostream>
#include "card.hpp"
#include "game.hpp"

class PPU{
	// you put cards from deck here
	private:
		Game game;
		DeckID drawing_deck;
		CardIndex drawing_card;
		
		void draw_game();
		void draw_card(Card &card);
		void change_drawing_deck(DeckID dst);

	public:
		PPU();

};