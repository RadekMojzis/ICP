#include "gcard.h"
button::button(QString name,
               QWidget * parent,
               int gid, bool scaling,
               int x, int y,
               GPU*main_gpu):QPushButton(name, parent){
    g_id = gid;
    pos_x = x;
    pos_y = y;
    resize(150, 75);
    gpu = main_gpu;
    rescale(scaling, gid);
    move(pos_x, pos_y);
}

void button::rescale(bool scaling, int gameindex){
    if(scaling){
        pos_x = pos_x/2;
        pos_y = pos_y/2;
    }
    if(gameindex > 1){
        pos_y += 400;
        //600*400
    }
    if((gameindex % 2) == 1){
        pos_x += 600;
    }
    if(scaling){
        resize(75,36);
    }
    move(pos_x, pos_y);
}
