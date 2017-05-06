#include"deck.hpp"

Card* Foundation::get_top(){
    return &(*cards.end());
}
