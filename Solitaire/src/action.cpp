#include"action.hpp"


DeckID Action::getFrom() {
    return from;
}

DeckID Action::getTo() {
    return to;
}

CardIndex Action::getCard() {
    return what;
}

Action::Action(DeckID src, DeckID dst, CardIndex card){
    from = src;
    to = dst;
    what = card;
}

void Action::flips(CardIndex card){
    toFlip = card;
}

void Action::reverse(){
    DeckID tmp = from;
    from = to;
    to = tmp;
}
