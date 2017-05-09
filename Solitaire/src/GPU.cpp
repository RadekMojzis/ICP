#include"gcard.h"
#include <QDir>
#include <QApplication>
#include <iostream>
#include "action.hpp"
#include <QMouseEvent>

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

    new_game_btn = new QPushButton("New Game", &window);
    new_game_btn->resize(200, 50);
    new_game_btn->move(0, 750);
    connect(new_game_btn, SIGNAL(clicked()), this, SLOT(new_game_clicked()));
    window.resize(1200, 800);
    window.setWindowTitle("Solitere");

    load_images();
    new_game();

    window.show();
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
    int active = 0;
    for(int i = 0; i < 4; i++)
        active += game_slot_ocupied[i];

    if(game.size() > 3){
        for(int i = 0; i < 4; i++){
            if(!game_slot_ocupied[i]){
                active = i;
                game_slot_ocupied[active] = 1;
                game[active] = new Game();

                if(active >= 1)
                    scaling = true;
                load[active] = (new button("Load", &window, active, scaling, 0, 625, this));
                save[active] = (new button("Save", &window, active, scaling, 75, 625, this));
                undo[active] = (new button("Undo", &window, active, scaling, 0, 550, this));
                exit[active] = (new button("Exit", &window, active, scaling, 75, 550, this));
                connect(exit[active], SIGNAL(clicked(int)), this, SLOT(exit_game(int)));
                connect(load[active], SIGNAL(clicked(int)), this, SLOT(load_game(int)));
                connect(save[active], SIGNAL(clicked(int)), this, SLOT(save_game(int)));
                connect(undo[active], SIGNAL(clicked(int)), this, SLOT(undo_turn(int)));

                draw_game(active);
                return;
            }
        }
        return;
    }
    game_slot_ocupied[active] = 1;
    foundations.push_back(vector<vector<gcard*>>());
    piles.push_back(vector<vector<gcard*>>());
    stock.resize(stock.size()+1);
    flip.resize(flip.size()+1);

    game.push_back(new Game());

    if(active == 1)
       rescale(true, 0);
    if(active >= 1)
        scaling = true;
    cout << "Ahoj!" << endl;

    load.push_back(new button("Load", &window, active, scaling, 0, 625, this));
    save.push_back(new button("Save", &window, active, scaling, 75, 625, this));
    undo.push_back(new button("Undo", &window, active, scaling, 0, 550, this));
    exit.push_back(new button("Exit", &window, active, scaling, 75, 550, this));
    connect(exit[active], SIGNAL(clicked(int)), this, SLOT(exit_game(int)));
    connect(load[active], SIGNAL(clicked(int)), this, SLOT(load_game(int)));
    connect(save[active], SIGNAL(clicked(int)), this, SLOT(save_game(int)));
    connect(undo[active], SIGNAL(clicked(int)), this, SLOT(undo_turn(int)));

    for(int i = 0; i < 4; i++)
        foundations[active].push_back(vector<gcard*>());

    for(int i = 0; i < 7; i++)
        piles[active].push_back(vector<gcard*>());

    draw_game(active);
}

void GPU::exit_game(int id){
    clear(id);
    delete game[id];
    delete load[id];
    delete save[id];
    delete undo[id];
    delete exit[id];


    game_slot_ocupied[id] = 0;
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
}

void GPU::clear(int id){
    for(auto f = foundations[id].begin(); f < foundations[id].end(); f++){
        for(auto g = (*f).begin(); g < (*f).end(); g++){
            delete *g;
        }
        (*f).resize(0);
    }
    for(auto f = piles[id].begin(); f < piles[id].end(); f++){
        for(auto g = (*f).begin(); g < (*f).end(); g++){
            delete *g;
        }
        (*f).resize(0);
    }

    delete flip[id];
    delete stock[id];
}

int abs(int a){
    return a > 0 ? a:-a;
}

int GPU::get_dst_deck(int base_x,int base_y, int g_index){
    for(auto i = foundations[g_index].begin(); i < foundations[g_index].end(); i++){
        if(abs((*((*i).end()-1))->base_x - base_x) < 50
        && abs((*((*i).end()-1))->base_y - base_y) < 90       ){
            return (*((*i).end()-1))->src;
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
