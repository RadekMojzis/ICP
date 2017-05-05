#pragma once
#include "deck.hpp"
#include "card.hpp"

class Action{
	private:
		Deck &from;
		Deck &to;
		Card &what;
	public:
		bool execute();
		void reverse();
};