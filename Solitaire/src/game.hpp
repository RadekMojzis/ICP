
#pragma once


#include "action.hpp"
#include <vector>
#include "deck.hpp"


class Game{
	private:
		Stock stock;
		Flip flip;
		
		std::vector<Pile> piles;
		std::vector<Foundation> foundations;

		std::vector<Action> history;
		
	public:
        Game();
        ~Game();
		void execute_action(DeckID src, DeckID dst, CardIndex card);	
        // interface has to be able to create actions but it doesnt have
        //	 access into Game object...
		
		const std::vector<Card> & get_stock();
		//?redo();
		void undo();
		void save();
		void load();
		void quit();
};
