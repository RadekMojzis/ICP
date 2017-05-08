#include"deck.hpp"

Card* Pile::get_top(){
    return &(*cards.end());
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
}

void Pile::push_back(int card){
    cards.push_back(Card(card));
}
