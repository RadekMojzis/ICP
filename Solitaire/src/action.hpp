#pragma once
#include "deck.hpp"
#include "card.hpp"

class Action{
	private:
        DeckID from;
        DeckID to;
        CardIndex what;
        CardIndex toFlip = -1;
         // chce to nejakou konstantu ktera bude rikat nic se neflipuje
	public:
        void flips(CardIndex card);
        Action(DeckID src, DeckID dst, CardIndex card);
        //bool execute();
		void reverse();
		DeckID getFrom();
        DeckID getTo();
        CardIndex getCard();
};
