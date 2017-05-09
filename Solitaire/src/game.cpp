#include "game.hpp"
#include<iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int chaos (int i) {
    static int a = 0;
    a += 17;
    return (std::rand()+a)%i;
}

void Game::print(){
    stock.get_top()->flip();
    cout << "stock:" << stock.get_top()->get_true_id() << endl;
    cout << "flip:" << flip.get_top()->get_true_id() << endl;
    cout << "piles:" << endl;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < piles[i].getSize(); j++){
            cout << piles[i].get_cards()[j].get_true_id() << ", ";
        }
        cout << endl;
    }
    cout << "foundations:" << endl;

    cout << "C" <<foundations[0].get_top()->get_true_id() << endl;
    cout << "D" <<foundations[1].get_top()->get_true_id() << endl;
    cout << "H" <<foundations[2].get_top()->get_true_id() << endl;
    cout << "S" <<foundations[3].get_top()->get_true_id() << endl;
}

Game::Game(){
    cout << "game is being initialised" << endl;
    for(int i = 2; i < 9; i++){
        piles.push_back(Pile(i));
    }

    vector <int> shuffle;
    for(int i = 0; i < 52; i++){
        shuffle.push_back(i);
    }
    std::srand ( unsigned ( std::time(0) ) );
    random_shuffle(shuffle.begin(),shuffle.end(), chaos);
    for(int i = 0; i < 7; i++){
        for(int j = 0; j <= i; j++){
            piles[i].push_back(shuffle.back());
            shuffle.pop_back();
        }
    }
    while(shuffle.size()){
        stock.push_back(shuffle.back());
        shuffle.pop_back();
    }

    for(int i = 9; i < 13; i++)
        foundations.push_back(Foundation(i));
    for(int i = 0; i < 7; i++){
        for(int j = 0; j <= i; j++){
            if(i == j){
                piles[i].get_cards()[j].flip();
            }
        }
    }

    for(int i = 0; i < 7; i++){
        for(int j = 0; j <= i; j++){
            //cout << piles[i].get_cards()[j].is_up() << ", ";
        }
        //cout << endl;
    }
    for(int i = 0; i < 7; i++){
        for(int j = 0; j <= i; j++){
            //cout << piles[i].get_cards()[j].get_id() << ", ";
        }
        // << endl;
    }
}

Game::~Game(){
    cout << "game is being terminated" << endl;
    //init stuff
}

std::vector<Card> & Game::get_deck(DeckID deck){
    switch (deck) {
    case PILE1:
        return piles[0].get_cards(); break;
    case PILE2:
        return piles[1].get_cards(); break;
    case PILE3:
        return piles[2].get_cards(); break;
    case PILE4:
        return piles[3].get_cards(); break;
    case PILE5:
        return piles[4].get_cards(); break;
    case PILE6:
        return piles[5].get_cards(); break;
    case PILE7:
        return piles[6].get_cards(); break;
    default:
        break;
    }
    // this can never happen but i hate warnings...
    return piles[0].get_cards();
}

Card *Game::get_top(DeckID deck){
    switch (deck) {
    case STOCK:
        return stock.get_top(); break;
    case FLIP:
        return flip.get_top(); break;
    case F_CLUBS:
        return foundations[0].get_top(); break;
    case F_DIAMONDS:
        return foundations[1].get_top(); break;
    case F_HEARTS:
        return foundations[2].get_top(); break;
    case F_SPADES:
        return foundations[3].get_top(); break;
    default:
        break;
    }
    // this can never happen but i hate warnings...
    return stock.get_top();
}
//TODO test na flipnute karty?
bool Game::ActionValidity(Action act){
    DeckID src = act.getFrom();
    DeckID dst = act.getTo();
    CardIndex val = act.getCard();
    CardIndex topSrc;
    if (src == STOCK) topSrc = stock.get_top()->get_id();
    else if (src == FLIP) topSrc = flip.get_top()->get_id();
    else if (src >= PILE1 && src <= PILE7) piles[src - PILE1].get_top()->get_id();
    else foundations[src - F_CLUBS].get_top()->get_id();
    if (dst == STOCK) {
        return false;
    }
    if (dst == FLIP) {
        if (src != STOCK) return false;
        return true;
    }
    if (dst >= F_CLUBS && dst <= F_SPADES) {
        //cannot drag from another foundation
        if (src >= F_CLUBS && src <= F_SPADES)  return false;
        //the first card must be ace of clubs
        if (foundations[dst - F_CLUBS].getSize() == 0 && val != 0) return false;
        //all the cards must be the right color
        if (val >= (dst - F_CLUBS)*13 && val <= (dst - F_CLUBS)*13 + 12) return false;
        //is not complete
        if (foundations[dst - F_CLUBS].get_top()->get_id() == (dst - F_CLUBS)*13) return false;
        //must be ascending
        if (val - 1 != foundations[dst - F_CLUBS].get_top()->get_id()) return false;
        //not top card moving (more cards drag)
        if (val != topSrc)  return false;
        return true;
    }
    if (dst >= PILE1 && dst <= PILE7) {
        //if empty, only kings are allowed
        if (piles[dst - PILE1].getSize() == 0) {
            if (val != 12 && val != 25 && val != 38 && val != 51) return false;
            return true;
        }
        // if there is an ace in the pile (end of pile)
        if (!(piles[dst - PILE1].get_top()->get_id() % 13)) return false;
        CardIndex top = piles[dst - PILE1].get_top()->get_id();
        if (val >= 13 && val < 26) {
            if (val != top - 14 && val != top + 25) return false;
        }
        else if (val >= 26 && val < 39) {
            if (val != top - 27 && val != top + 12) return false;
        }
        else if (val != top + 12 && val != top + 25 && val != top - 14 && val != top - 27) return false;
        return true;
    }
}

void Game::execute_action(Action act) {
    print(); // action je dobre
    //if (!(ActionValidity(act))) return;
    DeckID src = act.getFrom();
    DeckID dst = act.getTo();
    CardIndex c = act.getCard();
    if (src == STOCK) {
        if (stock.getSize()) {
            flip.push_back(stock.get_top()->get_true_id());
            stock.removeCards();
            return;
        } // now it works
        else if (flip.getSize() > 0) {
            //flipping the stack uppside down
            for (auto it = flip.get_iterator_end() - 1; it >= flip.get_iterator_begin(); --it) {
                stock.push_back((*it).get_true_id());
            }
            flip.clrVec();
            return; //TODO might wanna change...
        }
        return; //both flip and stock are empty
    }
    if (src == FLIP) {
        if (flip.getSize() == 0) return;
        if (dst >= PILE1 && dst <= PILE7){
            piles[dst-PILE1].push_back(flip.get_top()->get_true_id());
            piles[dst-PILE1].get_top()->flip();
        }
        if (dst >= F_CLUBS && dst <= F_SPADES){
            foundations[dst-F_CLUBS].push_back(flip.get_top()->get_true_id());
        }
        flip.removeCards();
        //from flip you can put into foundation or piles
    }
    if (src >= F_CLUBS && src <= F_SPADES) {
        piles[dst-PILE1].push_back(foundations[src-F_CLUBS].get_top()->get_true_id(), true);
        foundations[src - F_CLUBS].removeCards();
        //from foundation you only can move cards to piles

    }
    if (src >= PILE1 && src <= PILE7) {
        if (dst > PILE7) {
            foundations[dst-F_CLUBS].push_back(piles[src-PILE1].get_top()->get_true_id());
            piles[src - PILE1].removeCards();
        }
        // pile to pile
        else if (piles[src-PILE1].get_top()->get_true_id() == act.getCard()) {
            piles[dst - PILE1].push_back(piles[src-PILE1].get_top()->get_true_id(), true);
            piles[src-PILE1].removeCards();
        }
        else{
            auto it = piles[src-PILE1].get_cards();
            int remove = 0;
            int flag = 0;
            for(int i = 0; i < it.size(); i++){
                if(it[i].get_true_id() == act.getCard())
                    flag = 1;
                if(flag){
                    piles[dst-PILE1].push_back(it[i].get_true_id(), true);
                    remove++;
                }
            }
            for(int i = 0; i < remove; i++){
                piles[src-PILE1].removeCards();
            }
        }
    }
    return;
}

void Game::save(string file) {
    ofstream outfile;
    outfile.open(file);

    for (std::vector<Card>::iterator it = stock.get_iterator_begin(); it != stock.get_iterator_end(); ++it) {
        //outfile << "S|" << to_string(*it.get_id()) << "-" << *it.is_up() << "|";
        outfile << to_string((*it).get_id()) << "S" << (*it).is_up() << "\n";
    }
    for (std::vector<Card>::iterator it = flip.get_iterator_begin(); it != flip.get_iterator_end(); ++it) {
        outfile << to_string((*it).get_id()) << "F" << (*it).is_up() << "\n";
    }
    outfile << "\n";
    for (int i = 0; i < 7; i++) {
        for (std::vector<Card>::iterator it = piles[i].get_iterator_begin(); it != piles[i].get_iterator_end(); ++it) {
            outfile << to_string((*it).get_id()) << "P" << to_string(i) << (*it).is_up() << "\n";
        }
    }
    for (int i = 0; i < 4; i++) {
        for (std::vector<Card>::iterator it = foundations[i].get_iterator_begin(); it != foundations[i].get_iterator_end(); ++it) {
            outfile << to_string((*it).get_id()) << "E" << to_string(i) << (*it).is_up() << "\n";
        }
    }
    outfile.close();
}

void Game::load(string file) {
    ifstream infile;
    string line;
    infile.open(file);
    while (getline (infile, line) ) {
        if(line.find('S') != string::npos) {
            size_t  faceUpPos = line.find('S') + 1;
            int val  = stoi(line, nullptr);
            bool fUp = line[faceUpPos] - 48;    //todo hope so
            stock.push_back(val);
        }
        if(line.find('F') != string::npos) {
            size_t  faceUpPos = line.find('F') + 1;
            int val  = stoi(line, nullptr);
            bool fUp = line[faceUpPos] - 48;
            Card c(val, fUp);
            flip.addCards(c);
        }
        if(line.find('P') != string::npos) {
            size_t faceUpPos = line.find('P') + 2;
            int a = line[faceUpPos - 1] - 48;
            int val = stoi(line, nullptr);
            bool fUp = line[faceUpPos] - 48;
            Card c(val, fUp);
            piles[a].addCards(c);
        }
        if(line.find('E') != string::npos) {
            size_t faceUpPos = line.find('E') + 2;
            int a = line[faceUpPos - 1] - 48;
            int val = stoi(line, nullptr);
            bool fUp = line[faceUpPos] - 48;
            Card c(val, fUp);
            foundations[a].addCards(c);
        }
    }
    infile.close();
}
