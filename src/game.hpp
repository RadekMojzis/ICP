
#pragma once

#include "stock.hpp"
#include "flip.hpp"
#include "foundation.hpp"
#include "pile.hpp"
#include "action.hpp"
#include <vector>


typedef int CardIndex;

enum DeckID{
	STOCK,
	FLIP, 
	PILE1, PILE2, PILE3, PILE4, PILE5, PILE6, PILE7,
	FOUNDATION1, FOUNDATION2,FOUNDATION3, FOUNDATION4
};

class Game{
	private:
		Stock stock;
		Flip flip;
		
		std::vector<Pile> piles;
		std::vector<Foundation> foundations;

		std::vector<Action> history;
		
	public:
		void execute_action(DeckID src, DeckID dst, CardIndex card);	
		// interface has to be able to create actions but it doesnt have \
			 access into Game object... 
		
		const std::vector<Card> & get_stock();
		//?redo();
		void undo();
		void save();
		void load();
		void quit();
};
