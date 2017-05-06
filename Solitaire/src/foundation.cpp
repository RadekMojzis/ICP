#include"deck.hpp"

Card* Foundation::get_top(){
    return &(*cards.end());
}

Foundation::Foundation(){}

Foundation::~Foundation(){}
