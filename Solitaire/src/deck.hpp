

#pragma once
#include "card.hpp"
#include <vector>


enum DeckID{
    STOCK,
    FLIP,
    PILE1, PILE2, PILE3, PILE4, PILE5, PILE6, PILE7,
    F_HEARTS, F_DIAMONDS,F_CLUBS, F_SPADES
};
typedef unsigned int DeckSize;
typedef unsigned int ActionID;

class Foundation{
        DeckID id;
        std::vector<Card> cards;
    public:
        Foundation();
        ~Foundation();
<<<<<<< HEAD
        Card* get_top();
=======
        DeckID getID();
        bool ActionValidity();
>>>>>>> origin/master
        //const std::vector<Card> & get_cards(){};
};

class Flip{
        DeckID id;
        std::vector<Card> cards;
    public:
//        push(Card& card);
//        pop();
//        Card& top();
        Card* get_top();
        Flip();
        ~Flip();
        DeckID getID();
        bool ActionValidity();
    //const std::vector<Card> & get_cards();
};

class Pile{
        DeckID id;
        std::vector<Card> cards;
    public:

        Pile();
        ~Pile();
<<<<<<< HEAD
        std::vector<Card> & get_cards();
=======
        DeckID getID();
        bool ActionValidity();
    //const std::vector<Card> & get_cards();
>>>>>>> origin/master
};


class Stock{
        DeckID id = 0;
        std::vector<Card> cards;
    public:
<<<<<<< HEAD
        Stock();
        ~Stock();
        Card* get_top();
        //const std::vector<Card> & get_cards();
=======

        Stock() {};
        Stock(vector<Card> & initCards, int ident): cards{initCards}, id{ident} {};
        ~Stock();
        DeckID getID();
        bool ActionValidity(ActionID action, vector<Card> cards);
        DeckSize getSize();
        void addCards(vector<Card> & cards);
        void removeCards(vector<Card> & cards);

    //const std::vector<Card> & get_cards();
>>>>>>> origin/master
};
