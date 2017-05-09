#include <iostream>

#include <QMouseEvent>
#include "gcard.h"

using namespace std;

void gcard::rescale(bool scaling ,int index ){
    if(scaling){
        base_x = base_x/2;
        base_y = base_y/2;
    }
    if(index > 1){
        base_y += 400;
        //600*400
    }
    if((index % 2) == 1){
        base_x += 600;
    }
    if(scaling){
        setPixmap(pixmap()->scaled(65, 90));
    }
    if(scaling){
        resize(65,90);
    }
    move(base_x, base_y);
}

gcard::gcard(CardID card, int x, int y, vector <QPixmap*>& cards,bool disabledrag, QWidget * parent,GPU *main_gpu, bool scaling, int index):QLabel(parent){
    //cout << "creating card [" << card << "]- on[" << x << ", " << y << "]" <<endl;
    connect( this, SIGNAL( clicked(QMouseEvent * )), this, SLOT( slotClicked(QMouseEvent * ) ) );
    connect( this, SIGNAL( released(QMouseEvent * ) ), this, SLOT( slotReleased(QMouseEvent * ) ) );
    connect( this, SIGNAL( doubleclick(QMouseEvent * ) ), this, SLOT( slotDoubleclick(QMouseEvent * ) ) );
    connect( this, SIGNAL( movement(QMouseEvent * ) ), this, SLOT( slotmovement(QMouseEvent * ) ) );
    disabled = disabledrag;
    gpu = main_gpu;
    base_x = x;
    base_y = y;
    game_id = index;

    setPixmap(*cards[card]);
    resize(130,180);
    rescale(scaling, index);
    move(base_x, base_y);
    //setStyleSheet("border: 1px solid grey");
    number = card;
    setAcceptDrops(true);
    show();
    //cout << "done!" << endl;
}

void gcard::mousePressEvent ( QMouseEvent * event ){
    emit clicked(event);
}

void gcard::mouseReleaseEvent ( QMouseEvent * event ){
    emit released(event);
}

void gcard::mouseDoubleClickEvent ( QMouseEvent * event ){
    emit doubleclick(event);
}

void gcard::mouseMoveEvent ( QMouseEvent * event ){

    emit movement(event);
}

void gcard::slotClicked(QMouseEvent * event){
    //cout << number << endl;
    if(src == STOCK)
        gpu->execute_action(src, src, -1, game_id);

    if(disabled)
        return;
    base_drag_x = event->globalX();
    base_drag_y = event->globalY();
}

void gcard::slotReleased(QMouseEvent * event){
    if(next != nullptr)
         releasestack();
    if(drag_action){

        int dst_deck = gpu->get_dst_deck(this->pos().x(), this->pos().y(), game_id);
        if(dst_deck != src && dst_deck > 0){
            cout << "generating action src: " << src << ", dst: "<< dst_deck <<", Card: " << number << ", Game: " << game_id << endl;
            gpu->execute_action(src, dst_deck, number, game_id);
            return;
        }
    }
    move(base_x, base_y);
    drag_action = false;
}

void gcard::slotDoubleclick(QMouseEvent * event){
    (void) event;
}

void gcard::slotmovement(QMouseEvent * event){
    if(disabled)
        return;
    int x = base_x + event->globalX() - base_drag_x;
    int y = base_y + event->globalY() - base_drag_y;
    drag_action = true;
    move(x, y);
    raise();
    if(next != nullptr)
        next->dragstack(event->globalX() - base_drag_x, event->globalY() - base_drag_y);
}

void gcard::dragstack(int x, int y){
    move(base_x + x, base_y + y);
    raise();
    if(next != nullptr)
        next->dragstack(x, y);
}

void gcard::releasestack(){
    move(base_x, base_y);
    if(next != nullptr)
        next->releasestack();
}
