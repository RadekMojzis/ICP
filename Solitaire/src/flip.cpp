#include"deck.hpp"

Card* Flip::get_top(){
    return &(*cards.end());
}


Flip::Flip(){}

Flip::~Flip(){}

