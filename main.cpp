#include "mainwindow.h"
#include <QApplication>
#include "src/interface.hpp"
#include <iostream>
#include <unistd.h>
#include "src/GPU.hpp"
#include "src/PPU.hpp"
#include "src/program.hpp"
#include "src/interface.hpp"

using namespace std;

IF_TYPE get_if(int argc, char *argv[]){
    int opt;
    while ((opt = getopt(argc, argv, "tg")) != -1) {
           switch (opt) {
           case 't':
               return TEXT;
               break;
           case 'g':
               return GUI;
               break;
           default:
               cerr << "Usage: solitaire [-i|-g]" << std::endl;
               exit(EXIT_FAILURE);
           }
    }
    return TEXT;
}


int main(int argc, char *argv[]){
    IF_TYPE type;
    type = TEXT;
    if(argc != 1)
        type = get_if();
    if(type == GUI){
        GPU gpu();
        GPU &gpu_ref = gpu;
        program(gpu_ref);
    }
    else{
        PPU ppu();
        PPU &ppu_ref = ppu;
        program(ppu_ref);
    }

    return 0;
}
