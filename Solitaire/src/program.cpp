#include"program.hpp"


program::program(IF_TYPE IF){
    cosi = IF;
    if(cosi == GUI){
        gpu = new GPU();
    }
    if(cosi == TEXT){
        ppu = new PPU();
    }
};


void program::new_game(){
    if(cosi == GUI){
        gpu->new_game();
    }
    if(cosi == TEXT){
        ppu->new_game();
    }
}
