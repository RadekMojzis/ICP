#include"gcard.h"
#include <QDir>
#include <QApplication>

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

        cardname += QString::number((i%13)+1);
        cardname += ".png";
        cards.push_back(new QPixmap(path + cardname));
    }
    cards.push_back(new QPixmap(path + "0.png"));
    cards.push_back(new QPixmap(path + "CF.png"));
    cards.push_back(new QPixmap(path + "DF.png"));
    cards.push_back(new QPixmap(path + "HF.png"));
    cards.push_back(new QPixmap(path + "SF.png"));
    cards.push_back(new QPixmap(path + "B.png"));
}


GPU::GPU(){
    window.resize(1200, 800);
    window.show();
    window.setWindowTitle("Solitere");

    load_images();

    window.show();

    new_game();
    qApp->exec();
    for(auto g = game.begin(); g < game.end(); g++)
        delete *g;
}

void GPU::draw_game(int gameid){
  for(int i = STOCK; i <= F_SPADES; i++)
      draw_deck(i, gameid);
}

void GPU::draw_deck(DeckID deck, int i){
    if(deck == STOCK || deck == FLIP || deck == F_HEARTS || deck == F_DIAMONDS|| deck == F_CLUBS|| deck == F_SPADES){
        draw_card(game[i]->get_top(deck), deck, i);

        return;
    }
    vector<Card> & cards = game[i]->get_deck(deck);
    for(auto card = cards.begin(); card < cards.end(); card++) {
        draw_card(&(*card), deck, i);
    }
}

void GPU::draw_card(Card *card, DeckID deck, int gameid){
    gcard* ncard;
    //cout << "trying to put: [" << card->get_id() <<"] into deck: " <<  deck << endl;
    if(deck <= F_SPADES && deck >= F_CLUBS){
        int F_index = deck - F_CLUBS;
        ncard = new gcard(card->get_id(), FOUNDATION_X, 10 + F_index * 190, cards, true,&window,this, scaling, gameid);
        foundations[gameid][F_index].push_back(ncard);
        ncard->src = deck;
    }
    if(deck >= PILE1 && deck <= PILE7){
        int P_index = deck - PILE1;
        ncard = new gcard(card->get_id(), 140 + 130 * P_index , 10 + piles[gameid][P_index].size() * 30 , cards, false,&window,this, scaling, gameid);
        if(piles[gameid][P_index].size())
            (*(piles[gameid][P_index].end()-1))->next = ncard;
        piles[gameid][P_index].push_back(ncard);
        ncard->src = deck;
        }
    if(deck == STOCK){
        ncard = new gcard(card->get_id(), 10, 10, cards, true,&window,this, scaling, gameid);
        ncard->src = STOCK;
        stock[gameid] = ncard;
    }
    if(deck == FLIP){
        bool disabled = card->get_id() != 57 ? false : true;
        ncard = new gcard(card->get_id(), 10, 190 , cards, disabled, &window,this, scaling, gameid);
        ncard->src = FLIP;
        flip[gameid] = ncard;
    }
}

void GPU::new_game(){
    foundations.push_back(vector<vector<gcard*>>());
    piles.push_back(vector<vector<gcard*>>());
    stock.resize(active+2);
    flip.resize(active+2);

    if(game.size() > 3)
        return;
    game.push_back(new Game());

    active += 1;

   if(active == 1)
       rescale(true, 0);
   if(active >= 1)
        scaling = true;
    for(int i = 0; i < 4; i++)
        foundations[active].push_back(vector<gcard*>());

    for(int i = 0; i < 7; i++)
        piles[active].push_back(vector<gcard*>());

    draw_game(active);
}

void GPU::rescale(bool scaling, int gameidx){
    for(auto f = foundations[gameidx].begin(); f < foundations[gameidx].end(); f++){
        for(auto g = (*f).begin(); g < (*f).end(); g++){
             (*g)->rescale(scaling, gameidx);
        }
    }
    for(auto f = piles[gameidx].begin(); f < piles[gameidx].end(); f++){
        for(auto g = (*f).begin(); g < (*f).end(); g++){
             (*g)->rescale(scaling, gameidx);
        }
    }
    flip[gameidx]->rescale(scaling, gameidx);
    stock[gameidx]->rescale(scaling, gameidx);
}

void GPU::execute_action(int src, int dst, int card,int g_id){

}


void GPU::clear(){
    for(auto f = foundations[active].begin(); f < foundations[active].end(); f++){
        for(auto g = (*f).begin(); g < (*f).end(); g++){
            delete *g;
        }
    }
    for(auto f = piles[active].begin(); f < piles[active].end(); f++){
        for(auto g = (*f).begin(); g < (*f).end(); g++){
            delete *g;
        }
    }

    delete flip[active];
    delete stock[active];

}

int GPU::get_dst_deck(int base_x,int base_y, int g_index){
    for(auto i = foundations[g_index].begin(); i < foundations[g_index].end(); i++){

    }
    for(auto i = piles[g_index].begin(); i < piles[g_index].end(); i++){

    }
    return -1;
    //flip and stock make no sence...
}
