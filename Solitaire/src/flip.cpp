#include"deck.hpp"

Card* Flip::get_top(){
    return &(*cards.end());
}

Flip::Flip(){
}

Flip::~Flip(){}

DeckID Flip::getID() {
    return id;
}

DeckSize Flip::getSize() {
    return cards.size();
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