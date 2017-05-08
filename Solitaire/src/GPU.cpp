#include"interface.hpp"
#include <QDir>

void GPU::load_images(){
    QString dir = "D:/FIT/ICP/Solitaire/";

    QString path = dir + "img/";
    QString cardname;
    for(int i = 0; i < 52; i++){
        if(i < 52)
            cardname = "S";
        if(i < 39)
            cardname = "H";
        if(i < 26)
            cardname = "D";
        if(i < 13)
            cardname = "C";

        cardname += QString::number(i%13);
        cardname += ".png";
        cards.push_back(new QPixmap(path + cardname));
    }
    cards.push_back(new QPixmap(path + "0.png"));
}


GPU::GPU(){
    window.resize(1200, 675);
    window.show();
    window.setWindowTitle("Solitere");

    load_images();

    window.show();
    for(int i = 0; i < 4; i++)
        foundations.push_back(vector<gcard*>());

    for(int i = 0; i < 7; i++)
        piles.push_back(vector<gcard*>());
    draw_game();
    qApp->exec();
}

void GPU::draw_game(){
  for(int i = STOCK; i <= F_SPADES; i++)
      draw_deck(i);
}

void GPU::draw_deck(DeckID deck){
    if(deck == STOCK || deck == FLIP || deck == F_HEARTS || deck == F_DIAMONDS|| deck == F_CLUBS|| deck == F_SPADES){
        draw_card(game.get_top(deck), deck);
        return;
    }
    vector<Card> & cards = game.get_deck(deck);
    for(auto card = cards.begin(); card < cards.end(); card++) {
        draw_card(&(*card), deck);
    }
}

void GPU::draw_card(Card *card, DeckID deck){
    gcard* ncard;
    cout << "trying to put: [" << card->get_id() <<"] into deck: " <<  deck << endl;
    if(deck <= F_SPADES && deck >= F_CLUBS){
        int F_index = deck - F_CLUBS;
        ncard = new gcard(card->get_id(), FOUNDATION_X, 10 + F_index * 190, cards, true, &window);
        foundations[F_index].push_back(ncard);
        ncard->src = deck;
    }
    if(deck >= PILE1 && deck <= PILE7){
        int P_index = deck - PILE1;
        ncard = new gcard(card->get_id(), 140 + 130 * P_index , 10 + piles[P_index].size() * 30 , cards, false, &window);
        if(piles[P_index].size())
            (*(piles[P_index].end()-1))->next = ncard;
        piles[P_index].push_back(ncard);
        ncard->src = deck;
        }
    if(deck == STOCK){
        ncard = new gcard(card->get_id(), 10, 10, cards, true, &window);
        ncard->src = STOCK;
    }
    if(deck == FLIP){
        ncard = new gcard(card->get_id(), 10, 390, cards, false, &window);
        ncard->src = FLIP;
    }
}

void GPU::new_game(){

}

void GPU::clear(){
    for(auto f = foundations.begin(); f < foundations.end(); f++){
        for(auto g = (*f).begin(); g < (*f).end(); g++){
            delete *g;
        }
    }
    for(auto f = piles.begin(); f < piles.end(); f++){
        for(auto g = (*f).begin(); g < (*f).end(); g++){
            delete *g;
        }
    }
    for(auto g = flip.begin(); g < flip.end(); g++){
        delete *g;
    }
    for(auto g = stock.begin(); g < stock.end(); g++){
        delete *g;
    }

}
