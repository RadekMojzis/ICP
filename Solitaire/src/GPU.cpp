#include"gcard.h"
#include <QDir>
#include <QApplication>
#include <iostream>
#include "action.hpp"
#include <QMouseEvent>
int kocka = 0;
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
    for(int i = 0; i < 4; i++)
    game_slot_ocupied.push_back(0);
      foundations.resize(4);
    piles.resize(4);
    flip.resize(4);
    stock.resize(4);
    load.resize(4);
    undo.resize(4);
    exit.resize(4);
    game.resize(4);
    save.resize(4);
    new_game_btn = new QPushButton("New Game", &window);
    new_game_btn->resize(200, 50);
    new_game_btn->move(0, 750);
    connect(new_game_btn, SIGNAL(clicked()), this, SLOT(new_game_clicked()));
    cout << "kocka: " << kocka++<<endl;
    window.resize(1200, 800);
    window.setWindowTitle("Solitere");

    load_images();

    new_game();

    window.show();
    qApp->exec();
}

void GPU::draw_game(int gameid){
  for(int i = STOCK; i <= F_SPADES; i++)
      draw_deck(i, gameid);
}

void GPU::draw_deck(DeckID deck, int id){
    if(deck == STOCK || deck == FLIP || deck == F_HEARTS || deck == F_DIAMONDS|| deck == F_CLUBS|| deck == F_SPADES){
        draw_card(game[id]->get_top(deck), deck, id);
        return;
    }
    vector<Card> cards = game[id]->get_deck(deck);
    for(int i = 0; cards.size() > i; i++) {
        draw_card(&cards[i], deck, id);
    }
}

void GPU::draw_card(Card *card, DeckID deck, int gameid){

    gcard* ncard;
    if(deck <= F_SPADES && deck >= F_CLUBS){
        int F_index = deck - F_CLUBS;
        ncard = new gcard(card->get_id(), FOUNDATION_X, 10 + F_index * 190, cards, true,&window,this, scaling, gameid);
        foundations[gameid][F_index] = ncard;
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
    int active = 0;
    for(int i = 0; i < 4; i++)
        active += game_slot_ocupied[i];
    if(active > 4)
        return;
    for(int i = 0; i < 4; i++){
        if(!game_slot_ocupied[i]){
          foundations[i].resize(0);
          foundations[i].resize(4);
          piles[i].resize(0);
          piles[i].resize(7);
          game_slot_ocupied[i] = 1;
          game[i] = new Game();
          if(active == 1 && scaling == false)
              rescale(true, 0);
          if(active >= 1)
              scaling = true;
          load[i] = (new button("Load", &window, i, scaling, 0, 625, this));
          save[i] = (new button("Save", &window, i, scaling, 75, 625, this));
          undo[i] = (new button("Undo", &window, i, scaling, 0, 550, this));
          exit[i] = (new button("Exit", &window, i, scaling, 75, 550, this));
          connect(exit[i], SIGNAL(clicked(int)), this, SLOT(exit_game(int)));
          connect(load[i], SIGNAL(clicked(int)), this, SLOT(load_game(int)));
          connect(save[i], SIGNAL(clicked(int)), this, SLOT(save_game(int)));
          connect(undo[i], SIGNAL(clicked(int)), this, SLOT(undo_turn(int)));
          draw_game(i);
          return;
        }
    }
    return;
}

void GPU::exit_game(int id){
    clear(id);
    delete game[id];
    delete load[id];
    delete save[id];
    delete undo[id];
    delete exit[id];
    game_slot_ocupied[id] = 0;
    int active = 0;
    for(int i = 0; i < 4; i++){
        active += game_slot_ocupied[id];
    }
    if(active < 2){
        scaling = false;
        for(int i = 0; i < 4; i++){
           if(game_slot_ocupied[i]){
               rescale(false, i);
           }
        }
    }
    window.show();
}

void GPU::rescale(bool scaling, int gameidx){
    for(auto f = foundations[gameidx].begin(); f < foundations[gameidx].end(); f++){
         (*f)->rescale(scaling, gameidx);
    }
    for(auto f = piles[gameidx].begin(); f < piles[gameidx].end(); f++){
        for(auto g = (*f).begin(); g < (*f).end(); g++){
             (*g)->rescale(scaling, gameidx);
        }
    }
    flip[gameidx]->rescale(scaling, gameidx);
    stock[gameidx]->rescale(scaling, gameidx);
    load[gameidx]->rescale(scaling, gameidx);
    save[gameidx]->rescale(scaling, gameidx);
    undo[gameidx]->rescale(scaling, gameidx);
    exit[gameidx]->rescale(scaling, gameidx);
}

void GPU::execute_action(int src, int dst, int card,int g_id){
    if(src == STOCK)
        game[g_id]->execute_action(Action(STOCK, FLIP, 666));
    else{
        game[g_id]->execute_action(Action(src, dst, card));
    }
    redraw(g_id);
}
void GPU::redraw(int g_id){
    clear(g_id);
    cout << "No idea whats going on" << endl;
    draw_game(g_id);
    cout << "drawing is fine" << endl;
}

void GPU::clear(int id){
    for(int i = 0; i < 4; i++){
        delete foundations[id][i];
    }
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < piles[id][i].size(); j++){
            delete piles[id][i][j];
        }
        piles[id][i].resize(0);
    }
    delete flip[id];
    delete stock[id];
}

int abs(int a){
    return a > 0 ? a:-a;
}

int GPU::get_dst_deck(int base_x,int base_y, int g_index){
    for(auto i = foundations[g_index].begin(); i < foundations[g_index].end(); i++){
        if(abs((*i)->base_x - base_x) < 50
        && abs((*i)->base_y - base_y) < 90       ){
            return (*i)->src;
        }
    }
    for(auto i = piles[g_index].begin(); i < piles[g_index].end(); i++){
        if(abs((*((*i).end()-1))->base_x - base_x) < 50
        && abs((*((*i).end()-1))->base_y - base_y) < 90       ){
            return (*((*i).end()-1))->src;
        }
    }
    return -1;
}
