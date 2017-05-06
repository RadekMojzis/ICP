#include"deck.hpp"

std::vector<Card> & Pile::get_cards(){
    std::vector<Card> & ref = cards;
    return ref;
}
Pile::Pile(){}

Pile::~Pile(){}
