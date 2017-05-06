#include"deck.hpp"


Card* Stock::get_top(){
    return &(*cards.end());
}

Stock::Stock(){}

Stock::Stock(std::vector<Card> & initCards, DeckID ident):
    cards{initCards}, id{ident} {};

Stock::~Stock(){}

DeckSize Stock::getSize() {
    return cards.size();
}

DeckID Stock::getID() {
    return id;
}

bool Stock::ActionValidity(ActionID action, std::vector<Card> cards) {

}

void Stock::addCards(std::vector<Card> & cards) {

}

void Stock::removeCards(std::vector <Card> & cards) {

}
