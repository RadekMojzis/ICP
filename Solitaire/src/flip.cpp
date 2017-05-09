#include"deck.hpp"

Card* Flip::get_top(){

    if(cards.empty()){
        return &blank;
    }
    return &(*(cards.end()-1));
}

Flip::~Flip(){}

DeckID Flip::getID() {
    return id;
}

DeckSize Flip::getSize() {
    return cards.size();
}

void Flip::push_back(int c) {
    cards.push_back(Card(c, true));
}

void Flip::addCards(Card c) {
    cards.push_back(c);
}

void Flip::removeCards() {
    cards.pop_back();
}

std::vector<Card>::iterator Flip::get_iterator_begin(){
    return cards.begin();
}

std::vector<Card>::iterator Flip::get_iterator_end() {
    return cards.end();
}

void Flip::clrVec() {
    cards.clear();
    //todo might need to use this instead
    //vector<Cards>()/swap(cards);
    return;
}
