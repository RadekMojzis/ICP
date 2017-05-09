
#pragma once


#include "action.hpp"
#include <vector>
#include <iterator>
#include "deck.hpp"
#include <ctime>

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
        bool ActionValidity(Action act);
		void execute_action(Action act);
        std::vector<Card> & get_deck(DeckID deck);
        Card *get_top(DeckID deck);
        const std::vector<Card> & get_stock();

        void print();
        void undo(){};
        void save(string file);
        void load(string file);
        void quit(){};
};

