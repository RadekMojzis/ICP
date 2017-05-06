#include"deck.hpp"


Card* Stock::get_top(){
    return &(*cards.end());
}
Stock::Stock(){}

Stock::~Stock(){}
