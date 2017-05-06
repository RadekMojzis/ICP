#include"deck.hpp"


Card* Stock::get_top(){
    return &(*cards.end());
}

DeckSize Stock::DeckSize() {
    return cards.size();
}

DeckID Stock::getID() {
    return id;
}

bool Stock::ActionValidity() {

}

void Stock::addCards(vector <Card> &cards) {

}

void Stock::removeCards(vector <Card> &cards) {

}