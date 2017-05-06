

#pragma once
#include "card.hpp"
#include <vector>


enum DeckID{
    STOCK,
    FLIP,
    PILE1, PILE2, PILE3, PILE4, PILE5, PILE6, PILE7,
    FOUNDATION1, FOUNDATION2,FOUNDATION3, FOUNDATION4
};
typedef unsigned int DeckSize;
typedef unsigned int ActionID;

class Foundation{
        DeckID id;
        std::vector<Card> cards;
    public:
        Foundation();
        ~Foundation();
        DeckID getID();
        bool ActionValidity();
        //const std::vector<Card> & get_cards(){};
};

class Flip{
        DeckID id;
        std::vector<Card> cards;
    public:
//        push(Card& card);
//        pop();
//        Card& top();

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

        Pile() {};
        ~Pile();
        DeckID getID();
        bool ActionValidity();
    //const std::vector<Card> & get_cards();
};


class Stock{
        DeckID id = 0;
        std::vector<Card> cards;
    public:

        Stock() {};
        Stock(vector<Card> & initCards, int ident): cards{initCards}, id{ident} {};
        ~Stock();
        DeckID getID();
        DeckSize getSize();

        CardPosition

        bool ActionValidity(ActionID action, vector<Card> cards);
        void addCards(vector<Card> & cards);
        void removeCards(vector<Card> & cards);

    //const std::vector<Card> & get_cards();
};
