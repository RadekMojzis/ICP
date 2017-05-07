#include"interface.hpp"
#include<iostream>
using namespace std;



PPU::PPU(){
    cout << "PPU is being initialised..." << endl;
};

void PPU::draw_game(){
    cout << "Stock" << endl;
    draw_deck(STOCK);
    cout << "flip" << endl;
    draw_deck(FLIP);
    cout << "piles" << endl;
    cout << "1 |";
    draw_deck(PILE1);
    cout << "2 |";
    draw_deck(PILE2);
    cout << "3 |";
    draw_deck(PILE3);
    cout << "4 |";
    draw_deck(PILE4);
    cout << "5 |";
    draw_deck(PILE5);
    cout << "6 |";
    draw_deck(PILE6);
    cout << "7 |";
    draw_deck(PILE7);
    cout << "CLUBS:";
    draw_deck(F_CLUBS);
    cout << "DIAMONDS:";
    draw_deck(F_DIAMONDS);
    cout << "HEARTS:";
    draw_deck(F_HEARTS);
    cout << "SPADES:";
    draw_deck(F_SPADES);
    cout << "-------------------------------------------------------";
}


void PPU::draw_deck(DeckID deck){
    if(deck == STOCK || deck == FLIP || deck == F_HEARTS || deck == F_DIAMONDS|| deck == F_CLUBS|| deck == F_SPADES){
        draw_card(game.get_top(deck));
        cout << endl;
        return;
    }
    vector<Card> & cards = game.get_deck(deck);
    for(vector<Card>::iterator card = cards.begin(); card < cards.end(); card++) {
        draw_card(&(*card));
    }
    cout << endl;
}

void PPU::draw_card(Card *card){
    if(!card->is_up()){
        cout << "[XX]";
        return;
    }
    vector<string> color = {"C", "D", "H", "S"};
    vector<string> number = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    cout <<"[" << color[card->get_id()/13] << number[card->get_id()%13] << "]";
}

void PPU::new_game(){

}
