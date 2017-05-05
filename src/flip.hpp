
#pragma once
#include "deck.hpp"

class Flip: public Deck{
	private:
	public:
		const std::vector<Card> & get_cards();
};
