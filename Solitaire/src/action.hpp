#pragma once
#include "deck.hpp"
#include "card.hpp"

class Action{
	private:
        DeckID from;
        DeckID to;
        CardIndex what;
	public:
        Action();
		bool execute();
		void reverse();
		DeckID getFrom();
        DeckID getTo();
        CardIndex getCard();
};
