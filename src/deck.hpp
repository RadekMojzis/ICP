

#pragma once
#include "card.hpp"
#include <vector>

class Deck{
	// you put cards from deck here
	private:
		std::vector<Card> cards;
	public:
		Deck(){};
		const std::vector<Card> & get_cards();
};