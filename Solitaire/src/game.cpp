#include "game.hpp"
#include<iostream>

using namespace std;

Game::Game(){
    cout << "game is being initialised" << endl;
    //init stuff
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
        case PILE1 : {}
        case PILE2 : {}
        case PILE3 : {}
        case PILE4 : {}
        case PILE5 : {}
        case PILE6 : {}
        case PILE7 : {
            //starts with king
            //ends with ace
            //racism
            //descending
        }
        default: return false;
    }
<<<<<<< HEAD

=======
    return true;
>>>>>>> c16e2c9e1e1eb0580fdf201cb53f27fcffe3e810
}

void Game::execute_action(Action act) {
    if (ActionValidity(act))
        //act.execute();
    return;
}
