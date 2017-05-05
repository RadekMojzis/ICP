

#pragma once
#include "deck.hpp"

class Pile: public Deck{
	// you put cards from deck here
	private:
	public:
		const std::vector<Card> & get_cards();
};
