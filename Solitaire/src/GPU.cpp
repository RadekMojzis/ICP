#include"interface.hpp"



int GPU::run(){
    w.show();
    return qApp->exec();
}

void GPU::draw_game(){

}

void GPU::draw_deck(DeckID id){
    (void) id;
}

void GPU::draw_card(Card *card){
    (void) card;
}
