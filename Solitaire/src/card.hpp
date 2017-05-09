#pragma once


typedef int CardIndex;
typedef unsigned int CardPosition;

/**
 * \class Card represents a real card in the game.
 * \var id is unique for every card. Represents the value and color of the card.
 * \var faceUp flag which controls whether the card is flipped face-up or face-down.
 */

class Card{
		int id;
        bool faceUP = false;
		CardPosition position;
		
  public:
        Card(){id = 53; faceUP = true;}
        Card(int ident);
        Card(int ident, bool b): id{ident}, faceUP{b} {};
        int get_id(){return faceUP ? id : 52;};
        int get_true_id(){return id;};

        bool is_up(){return faceUP;};
        void flip();
        Card(Card*copy);
		void setPosition(CardPosition pos);
		CardPosition getPosition();
};
