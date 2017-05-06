

#pragma once
#include "card.hpp"
#include <vector>


enum DeckID{
    STOCK,
    FLIP,
    PILE1, PILE2, PILE3, PILE4, PILE5, PILE6, PILE7,
    F_HEARTS, F_DIAMONDS,F_CLUBS, F_SPADES
};

class Foundation{
    private:
        std::vector<Card> cards;
    public:
        Foundation();
        ~Foundation();
        Card* get_top();
        //const std::vector<Card> & get_cards(){};
};

class Flip{
    private:
        std::vector<Card> cards;
    public:
//        push(Card& card);
//        pop();
//        Card& top();
        Card* get_top();
        Flip();
        ~Flip();
        //const std::vector<Card> & get_cards();
};

class Pile{
    private:
        std::vector<Card> cards;
    public:

        Pile();
        ~Pile();
        std::vector<Card> & get_cards();
};


class Stock{
    private:
        std::vector<Card> cards;
    public:
        Stock();
        ~Stock();
        Card* get_top();
        //const std::vector<Card> & get_cards();
};
