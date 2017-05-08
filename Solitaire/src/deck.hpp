

#pragma once
#include "card.hpp"
#include <vector>

using namespace std;

enum DeckID{
    STOCK,
    FLIP,
    PILE1, PILE2, PILE3, PILE4, PILE5, PILE6, PILE7,
    F_CLUBS, F_DIAMONDS,F_HEARTS, F_SPADES
};
typedef unsigned int DeckSize;

class Foundation{
        DeckID id;
        std::vector<Card> cards;
    public:
        Foundation();
        ~Foundation();
        DeckID getID();
        DeckSize getSize();
        bool ActionValidity();
        void addCards(Card c);
        void removeCards();
        Card* get_top();
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
        DeckSize getSize();
        bool ActionValidity();
        void addCards(Card c);
        void removeCards();
        Card* get_top();
        std::vector<Card>::iterator get_iterator_begin();
        std::vector<Card>::iterator get_iterator_end();
};

class Pile{
        DeckID id;
        vector<Card> cards;
    public:

        Pile();
        ~Pile();
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
        DeckID id = STOCK;
        vector<Card> cards;
    public:

        Stock();
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
