#include"interface.hpp"
#include<iostream>
#include<string>
using namespace std;

void help(){

}

void bad(){

}

int get_src(string src){
    if(src == "d")
        return F_DIAMONDS;
    if(src == "h")
        return F_HEARTS;
    if(src == "c")
        return F_CLUBS;
    if(src == "s")
        return F_SPADES;
    if(src == "flip")
        return FLIP;

    int pile = stoi(src);
    if(pile > 7 || pile < 1)
        return -1;
    else
        return pile + 1;
}


int get_card(string src){

}

bool PPU::execute(string command){
    if(command == "stock"){
        //game.flip();
        return true;
    }
    else if(command == "flip"){
        //game.flip();
        return true;
    }
    else if(command == "undo"){
        game[active].undo();
        return true;
    }
    else if(command == "save"){
        string name;
        cin >> name;
        game[active].save(name);
        cout << "Saved" << endl;
        return true;
    }
    else if(command == "load"){
        string name;
        cin >> name;
        game[active].load(name);
        cout << "Loading" << endl;
        return true;
    }
    else if(command == "act"){
        string src;
        string dst;
        string target;
        cin >> src;
        int isrc = get_src(src);
        if(isrc < 0){bad(); return true;}
        cin >> dst;
        int idst = get_src(src);
        if(idst < 0){bad(); return true;}
        cin >> target;
        int itarget = get_card(src);
        if(itarget < 0){bad();return true;}


    }
    else if(command == "help"){
        return true;
    }
    else if(command == "new"){
        new_game();
        return true;
    }
    else if(command == "quit"){
        return true;
    }
    else{
        cout << "Unrecognised." << endl;
    }

    return true;
}

PPU::PPU(){
    game.push_back(Game());
    draw_game();
    string command;
    cin >> command;
    while(execute(command)){
        cin >> command;
        draw_game();
    }
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
        draw_card(game[active].get_top(deck));
        cout << endl;
        return;
    }
    vector<Card> & cards = game[active].get_deck(deck);
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
    if(card->get_id() > 52){
        cout << "[__]";
        return;
    }
    vector<string> color = {"C", "D", "H", "S"};
    vector<string> number = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    cout <<"[" << color[card->get_id()/13] << number[card->get_id()%13] << "]";
}

void PPU::new_game(){
    game.push_back(Game());
    active +=1;
}

void PPU::change_focus(int i){
    if(i > game.size()){
        cout << "No souch game!" << endl;
        return;
    }
    else{
        active = i;
        cout << "Success!" << endl;
    }
}
