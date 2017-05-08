#include "game.hpp"
#include<iostream>
#include <algorithm>
using namespace std;

int chaos (int i) {
    static int a = 0;
    a += 17;
    return (std::rand()+a)%i;
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
    vector<Card> dek;
    for(auto c = shuffle.begin(); c < shuffle.end(); c++){
        dek.push_back(Card(*c));
    }

    vector<Card> &crd = dek;
    stock = Stock(crd, STOCK);
    for(int i = 9; i < 13; i++)
        foundations.push_back(Foundation(i));

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
    case F_HEARTS:
        return foundations[0].get_top(); break;
    case F_DIAMONDS:
        return foundations[1].get_top(); break;
    case F_CLUBS:
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
    if (src == 0) topSrc = stock.get_top()->get_id();
    else if (src == 1) topSrc = flip.get_top()->get_id();
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
    if (!(ActionValidity(act))) return;
    DeckID src = act.getFrom();
    DeckID dst = act.getTo();
    CardIndex c = act.getCard();
    if (src == STOCK) {
        if (stock.getSize() > 0) {
            Card *tmp = stock.get_top();
            stock.removeCards();
            flip.addCards(*tmp);
        }
        else if (flip.getSize() > 0) {
            //flipping the stack uppside down
            for (std::vector<Card>::iterator it = flip.get_iterator_end() - 1; it >= flip.get_iterator_begin(); --it) {
                stock.addCards(*it);
            }
            flip.clrVec();
            return; //TODO might wanna change...
        }
        return; //both flip and stock are empty
    }
    if (src == FLIP) {
        if (flip.getSize() == 0) return;
        Card *tmp = flip.get_top();
        flip.removeCards();
        //from flip you can put into foundation or piles
        if (dst >= F_CLUBS && dst <= F_SPADES)  foundations[dst-F_CLUBS].addCards(*tmp);
        if (dst >= PILE1 && dst <= PILE7)   piles[dst-PILE1].addCards(*tmp);
    }
    if (src >= F_CLUBS && src <= F_SPADES) {
        Card *tmp = foundations[src-F_CLUBS].get_top();
        foundations[src - F_CLUBS].removeCards();
        //from foundation you only can move cards to piles
        piles[dst-PILE1].addCards(*tmp);
    }
    if (src >= PILE1 && src <= PILE7) {
        if (dst < PILE1 || dst > PILE7) {
            Card *tmp = piles[src-PILE1].get_top();
            piles[src - PILE1].removeCards();
            foundations[dst-F_CLUBS].addCards(*tmp);
        }
        // pile to pile
        else if (act.getCard() == piles[src - PILE1].get_top()->get_id()) {
            Card *tmp = piles[src-PILE1].get_top();
            piles[src - PILE1].removeCards();
            piles[dst - PILE1].addCards(*tmp);
        }
        else {  // more cards dragged
            Card * topCard = piles[src-PILE1].get_top();
            CardIndex topId = topCard->get_id();
            std::vector<Card> tmp;
            while (topId != c) {
                tmp.push_back(*topCard);
                topCard = piles[src-PILE1].get_top();
                topId = topCard->get_id();
            }
            for (std::vector<Card>::iterator it = tmp.end() - 1; it != tmp.begin(); --it) {
                piles[dst-PILE1].addCards(*it);
            }
        }
    }
    return;
}
