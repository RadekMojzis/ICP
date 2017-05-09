#include"deck.hpp"

Card* Pile::get_top(){
    //if(getSize())
        return &(*(cards.end()-1));
    //return &blank;
}

std::vector<Card> & Pile::get_cards(){
    std::vector<Card> & ref = cards;
    return ref;
}


Pile::~Pile(){}

DeckID Pile::getID() {
    return id;
}

DeckSize Pile::getSize() {
    return cards.size();
}

void Pile::addCards(Card c) {
    cards.push_back(c);
}

void Pile::removeCards() {
    cards.pop_back();
    if(cards.size())
        get_top()->flip();
}

void Pile::push_back(int card){
    cards.push_back(Card(card));
}

void Pile::push_back(int card, bool revealed){
    cards.push_back(Card(card, revealed));
}

std::vector<Card>::iterator Pile::get_iterator_begin(){
    return cards.begin();
}

std::vector<Card>::iterator Pile::get_iterator_end() {
    return cards.end();
}
