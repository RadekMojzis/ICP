#include"card.hpp"


void Card::setPosition(CardPosition pos) {
    position = pos;
}

CardPosition Card::getPosition() {
    return position;
}

void Card::flip(){
    faceUP = true;
}

Card::Card(int ident){
    id = ident;
    if(id < 52)
        faceUP = false;
    else{
        faceUP = true;
    }
};

Card::Card(Card*copy){
    id = copy->id;
    faceUP = copy->faceUP;
}
