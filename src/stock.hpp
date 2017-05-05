
#pragma once
#include "deck.hpp"

class Stock:Deck{
	private:
	public:
		const std::vector<Card> & get_cards();
};