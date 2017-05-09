#include"deck.hpp"

Stock::~Stock(){}

Card* Stock::get_top(){
    if(cards.empty())
        return & blank;
    return &(*cards.end());
}


DeckSize Stock::getSize() {
    return cards.size();
}

DeckID Stock::getID() {
    return id;
}

vector<Card> Stock::getStack(CardPosition pos){
    std::vector<Card> ret;
    for (int i = pos; pos < getSize(); pos++) {
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
        /*case POP : {
            return true;
        }
        case GET : {
            return false;
        }
        case PUT : {
            return false;
        }*/
        default:
            break;
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

std::vector<Card>::iterator Stock::get_iterator_begin(){
    return cards.begin();
}

std::vector<Card>::iterator Stock::get_iterator_end() {
    return cards.end();
}


