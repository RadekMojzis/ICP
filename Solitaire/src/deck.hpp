

#pragma once
#include "card.hpp"
#include <vector>


enum DeckID{
    STOCK,
    FLIP,
    PILE1, PILE2, PILE3, PILE4, PILE5, PILE6, PILE7,
    F_HEARTS, F_DIAMONDS, F_CLUBS, F_SPADES
};

class Foundation{
    // you put cards from deck here
    private:
        std::vector<Card> cards;
    public:
        Card* get_top();
        ~Foundation(){};
        Foundation(){};
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
        ~Flip(){};
        Flip(){};
        //const std::vector<Card> & get_cards();
};

class Pile{
    // you put cards from deck here
    private:
        std::vector<Card> cards;
    public:
        std::vector<Card> & get_cards();
        Pile(){};
        ~Pile(){};
        //const std::vector<Card> & get_cards();
};


class Stock{
    private:
        std::vector<Card> cards;
    public:
        Card* get_top();
        ~Stock(){};
        Stock(){};
        //const std::vector<Card> & get_cards();
};
