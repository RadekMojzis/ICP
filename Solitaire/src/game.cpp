#include "game.hpp"
#include<iostream>
#include <algorithm>
using namespace std;

int chaos (int i) { return std::rand()%i;}

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
//TODO add multiple cards restriction.... from pile to foundation
bool Game::ActionValidity(Action act){
    DeckID src = act.getFrom();
    DeckID dst = act.getTo();
    CardIndex val = act.getCard();
    switch (dst) {
        case STOCK : {
            return false;
        }
        case FLIP : {
            if (src != STOCK) return false;
            return true;
        }
        case F_CLUBS : {
            //the first card must be ace of clubs
            if (foundations[0].getSize() == 0 && val != 0) return false;
            //all the cards must be clubs
            if (val > 12) return false;
            //is not complete
            if (foundations[0].get_top()->get_id() == 12) return false;
            //must be ascending
            if (val - 1 != foundations[0].get_top()->get_id()) return false;
            return true;
         }
        case F_DIAMONDS : {
            if (foundations[1].getSize() == 0 && val != 0) return false;
            if (val > 25 && val < 13) return false;
            if (foundations[1].get_top()->get_id() == 25) return false;
            if (val - 1 != foundations[1].get_top()->get_id()) return false;
            return true;
        }
        case F_HEARTS : {
            if (foundations[2].getSize() == 0 && val != 0) return false;
            if (val > 38 && val < 26) return false;
            if (foundations[2].get_top()->get_id() == 38) return false;
            if (val - 1 != foundations[2].get_top()->get_id()) return false;
            return true;
        }
        case F_SPADES : {
            if (foundations[3].getSize() == 0 && val != 0) return false;
            if (val > 51 && val < 39) return false;
            if (foundations[3].get_top()->get_id() == 51) return false;
            if (val - 1 != foundations[3].get_top()->get_id()) return false;
            return true;
        }
        case PILE1 : {
            if (piles[0].getSize() == 0 && val != 12 && val != 25 && val != 38 && val != 51) return false;
            if (!(piles[0].get_top()->get_id() % 13)) return false;
            CardIndex top = piles[0].get_top()->get_id();
            if (val != top + 13 && val != top + 26 && val != top - 13 && val != top - 26) return false;
            return true;
        }
        case PILE2 : {
            if (piles[1].getSize() == 0 && val != 12 && val != 25 && val != 38 && val != 51) return false;
            if (!(piles[1].get_top()->get_id() % 13)) return false;
            CardIndex top = piles[1].get_top()->get_id();
            if (val != top + 13 && val != top + 26 && val != top - 13 && val != top - 26) return false;
            return true;
        }
        case PILE3 : {
            if (piles[2].getSize() == 0 && val != 12 && val != 25 && val != 38 && val != 51) return false;
            if (!(piles[2].get_top()->get_id() % 13)) return false;
            CardIndex top = piles[2].get_top()->get_id();
            if (val != top + 13 && val != top + 26 && val != top - 13 && val != top - 26) return false;
            return true;
        }
        case PILE4 : {
            if (piles[3].getSize() == 0 && val != 12 && val != 25 && val != 38 && val != 51) return false;
            if (!(piles[3].get_top()->get_id() % 13)) return false;
            CardIndex top = piles[3].get_top()->get_id();
            if (val != top + 13 && val != top + 26 && val != top - 13 && val != top - 26) return false;
            return true;
        }
        case PILE5 : {
            if (piles[4].getSize() == 0 && val != 12 && val != 25 && val != 38 && val != 51) return false;
            if (!(piles[4].get_top()->get_id() % 13)) return false;
            CardIndex top = piles[4].get_top()->get_id();
            if (val != top + 13 && val != top + 26 && val != top - 13 && val != top - 26) return false;
            return true;
        }
        case PILE6 : {
            if (piles[5].getSize() == 0 && val != 12 && val != 25 && val != 38 && val != 51) return false;
            if (!(piles[5].get_top()->get_id() % 13)) return false;
            CardIndex top = piles[5].get_top()->get_id();
            if (val != top + 13 && val != top + 26 && val != top - 13 && val != top - 26) return false;
            return true;
        }
        case PILE7 : {
            if (piles[6].getSize() == 0 && val != 12 && val != 25 && val != 38 && val != 51) return false;
            if (!(piles[6].get_top()->get_id() % 13)) return false;
            CardIndex top = piles[6].get_top()->get_id();
            if (val != top + 13 && val != top + 26 && val != top - 13 && val != top - 26) return false;
            return true;
        }
        default: return false;
    }
}

void Game::execute_action(Action act) {
    if (!(ActionValidity(act))) return;
    DeckID src = act.getFrom();
    switch (src) {
        case STOCK : {
            if (stock.getSize() > 0) {
                stock.removeCards();
                break;
            }
            if (flip.getSize() > 0) {
                for (std::vector<Card>::iterator it = flip.get_iterator_begin(); it != flip.get_iterator_end(); ++it) {
                    stock.addCards(*it);
                }
                break;
            }
            return; //both flip and stock are empty
        }
        case FLIP : {
            if (flip.getSize() == 0) return;
            flip.removeCards();
            break;
        }
        case F_CLUBS : {}
        case F_DIAMONDS : {}
        case F_HEARTS : {}
        case F_SPADES : {

        }
    }
    return;
}
