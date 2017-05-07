#include <iostream>
#include <unistd.h>
#include "src/program.hpp"
#include "src/interface.hpp"
#include <QApplication>

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
    QApplication a(argc, argv);

    IF_TYPE type;
    type = TEXT;
    if(argc != 1)
        type = get_if(argc, argv);

    program hra(type);

    return 0;
}
