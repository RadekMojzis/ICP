#include"deck.hpp"

Card* Foundation::get_top(){
    if(cards.empty())
        return & blank;
    return &(*cards.end());
}

Foundation::~Foundation(){}

DeckID Foundation::getID() {
    return id;
}

DeckSize Foundation::getSize() {
    return cards.size();
}

void Foundation::addCards(Card c) {
    cards.push_back(c);
}

void Foundation::removeCards() {
    cards.pop_back();
}
