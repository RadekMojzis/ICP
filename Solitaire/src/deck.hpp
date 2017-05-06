

#pragma once
#include "card.hpp"
#include <vector>


enum DeckID{
    STOCK,
    FLIP,
    PILE1, PILE2, PILE3, PILE4, PILE5, PILE6, PILE7,
    FOUNDATION1, FOUNDATION2,FOUNDATION3, FOUNDATION4
};

class Foundation{
    // you put cards from deck here
    private:
        std::vector<Card> cards;
    public:
        ~Foundation();
        Foundation();
        //const std::vector<Card> & get_cards(){};
};

class Flip{
    private:
        std::vector<Card> cards;
    public:
//        push(Card& card);
//        pop();
//        Card& top();

        ~Flip();
        Flip();
        //const std::vector<Card> & get_cards();
};

class Pile{
    // you put cards from deck here
    private:
        std::vector<Card> cards;
    public:

        Pile();
        ~Pile();
        //const std::vector<Card> & get_cards();
};


class Stock{
    private:
        std::vector<Card> cards;
    public:
        ~Stock();
        Stock();
        //const std::vector<Card> & get_cards();
};
