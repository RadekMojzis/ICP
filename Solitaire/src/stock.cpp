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

vector<Card> Stock::getStack(CardPosition pos, DeckSize size){
    std::vector<Card> ret;
    for (int i = pos; pos < size; pos++) {
        ret.push_back (cards[pos]);
    }
    return ret;
}
/**
 *
 * \param action type of action
 * \return returns whether or not is the action valid
 */
bool Stock::ActionValidity(ActionID action) {
    switch(action) {
        case POP : {
            return true;
        }
        case GET : {
            return false;
        }
        case PUT : {
            return false;
        }
    }
}

void Stock::addCards(Card c){
    cards.push_back(c);
}

void Stock::removeCards() {
    if (cards.size() >= 1)
        cards.pop_back();
    else {
        //will be driven by game????
    }
}