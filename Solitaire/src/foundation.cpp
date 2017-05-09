#include"deck.hpp"

Card* Foundation::get_top(){
    if(cards.empty())
        return & blank;
    return &(*cards.end());
}
Foundation::Foundation(DeckID ident){
    id = ident;
    if(id == F_HEARTS)
        blank = Card(56);
    if(id == F_SPADES)
        blank = Card(55);
    if(id == F_DIAMONDS)
        blank = Card(54);
    if(id == F_CLUBS)
        blank = Card(53);

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

std::vector<Card>::iterator Foundation::get_iterator_begin(){
    return cards.begin();
}

std::vector<Card>::iterator Foundation::get_iterator_end() {
    return cards.end();
}