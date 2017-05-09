

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
        Foundation(DeckID ident);
        ~Foundation();
        DeckID getID();
        DeckSize getSize();
        bool ActionValidity();
        void addCards(Card c);
        void push_back(int c);
        void removeCards();
        Card* get_top();
        std::vector<Card>::iterator get_iterator_begin();
        std::vector<Card>::iterator get_iterator_end();
};

class Flip{
        Card blank;
        DeckID id;
        std::vector<Card> cards;
    public:
//        push(Card& card);
//        pop();
//        Card& top();

        Flip(){id = FLIP; blank = Card(57);};
        ~Flip();
        DeckID getID();
        DeckSize getSize();
        bool ActionValidity();
        void addCards(Card c);
        void removeCards();
        void push_back(int c);
        Card* get_top();
        std::vector<Card>::iterator get_iterator_begin();
        std::vector<Card>::iterator get_iterator_end();
        void clrVec();
};

class Pile{
        Card blank;
        DeckID id;
        vector<Card> cards;
    public:
        Pile(DeckID ident){id = ident; blank = Card(57);};
        ~Pile();
        void push_back(int card);
        void push_back(int card, bool revealed);
        DeckID getID();
        DeckSize getSize();
        bool ActionValidity();
        void addCards(Card c);
        void removeCards();
        vector<Card> & get_cards();
        Card* get_top();
        std::vector<Card>::iterator get_iterator_begin();
        std::vector<Card>::iterator get_iterator_end();
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
        Stock(){blank = Card(57);};
        Stock(vector<Card> & initCards, DeckID ident): cards{initCards}, id{ident} {};
        ~Stock();
        DeckID getID();
        DeckSize getSize();

        vector<Card> getStack(CardPosition pos);
        bool ActionValidity(ActionID action);
        //bool ActionValidity(ActionID action, vector<Card> cards);

        void push_back(int c);
        void removeCards();
        Card* get_top();
        std::vector<Card>::iterator get_iterator_begin();
        std::vector<Card>::iterator get_iterator_end();
    //const std::vector<Card> & get_cards();
};
