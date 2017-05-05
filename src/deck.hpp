

#pragma once
#include "card.hpp"
#include <vector>

class Deck{
	// you put cards from deck here
    protected:
		std::vector<Card> cards;
	public:
        Deck();
        virtual const std::vector<Card> & get_cards() = 0;
};
