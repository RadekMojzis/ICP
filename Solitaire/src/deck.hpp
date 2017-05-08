

#pragma once
#include "card.hpp"
#include <vector>

using namespace std;

typedef int DeckID;

const int STOCK = 0;
const int FLIP = 1;
const int PILE1 = 2;
const int PILE2 = 3;
const int PILE3 = 4;
const int PILE4 = 5;
const int PILE5 = 6;
const int PILE6 = 7;
const int PILE7 = 8;
const int F_CLUBS = 9;
const int F_DIAMONDS = 10;
const int F_HEARTS = 11;
const int F_SPADES = 12;

typedef unsigned int DeckSize;

class Foundation{
        DeckID id;
        std::vector<Card> cards;
        Card blank;
    public:
        Foundation(DeckID ident){id = ident;};
        ~Foundation();
        DeckID getID();
        DeckSize getSize();
        bool ActionValidity();
        void addCards(Card c);
        void removeCards();
        Card* get_top();
};

class Flip{
        Card blank;
        DeckID id;
        std::vector<Card> cards;
    public:
//        push(Card& card);
//        pop();
//        Card& top();

        Flip(){id = FLIP;};
        ~Flip();
        DeckID getID();
        DeckSize getSize();
        bool ActionValidity();
        void addCards(Card c);
        void removeCards();
        Card* get_top();
        std::vector<Card>::iterator get_iterator_begin();
        std::vector<Card>::iterator get_iterator_end();
};

class Pile{
        Card blank;
        DeckID id;
        vector<Card> cards;
    public:
        Pile(DeckID ident){id = ident;};
        ~Pile();
        void push_back(int card);
        DeckID getID();
        DeckSize getSize();
        bool ActionValidity();
        void addCards(Card c);
        void removeCards();
        vector<Card> & get_cards();
        Card* get_top();
};

/**
 * \brief Deck from which cards are being drawn into the "flip" deck.
 */
typedef int ActionID;

class Stock{
        Card blank;
        DeckID id = STOCK;
        vector<Card> cards;
    public:
        Stock(){};
        Stock(vector<Card> & initCards, DeckID ident): cards{initCards}, id{ident} {};
        ~Stock();
        DeckID getID();
        DeckSize getSize();

        vector<Card> getStack(CardPosition pos);
        bool ActionValidity(ActionID action);
        //bool ActionValidity(ActionID action, vector<Card> cards);

        void addCards(Card c);
        void removeCards();
        Card* get_top();
    //const std::vector<Card> & get_cards();
};
