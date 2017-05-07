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
		bool faceUP;
		CardPosition position;
		
  public:
        Card(int ident){id = ident; faceUP = false;};
        int get_id(){return faceUP ? id : 52;};
        bool is_up(){return faceUP;};
        void flip(){faceUP = !faceUP;}

		void setPosition(CardPosition pos);
		CardPosition getPosition();
};
