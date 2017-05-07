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

bool Action::execute(){

}
