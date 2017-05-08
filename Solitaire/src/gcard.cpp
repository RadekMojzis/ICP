#include <iostream>

#include <QMouseEvent>
#include "gcard.h"
#include <iostream>
using namespace std;

gcard::gcard(CardID card, int x, int y, vector <QPixmap*>& cards,bool disabledrag, QWidget * parent):QLabel(parent){
    cout << "creating card [" << card << "]- on[" << x << ", " << y << "]" <<endl;
    connect( this, SIGNAL( clicked(QMouseEvent * )), this, SLOT( slotClicked(QMouseEvent * ) ) );
    connect( this, SIGNAL( released(QMouseEvent * ) ), this, SLOT( slotReleased(QMouseEvent * ) ) );
    connect( this, SIGNAL( doubleclick(QMouseEvent * ) ), this, SLOT( slotDoubleclick(QMouseEvent * ) ) );
    connect( this, SIGNAL( movement(QMouseEvent * ) ), this, SLOT( slotmovement(QMouseEvent * ) ) );
    disabled = disabledrag;
    base_x = x;
    base_y = y;
    setPixmap(*cards[card]);
    resize(130,180);
    move(x, y);
    //setStyleSheet("border: 1px solid grey");
    number = card;
    setAcceptDrops(true);
    show();
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
    cout << number << endl;
    if(disabled)
        return;
    base_drag_x = event->globalX();
    base_drag_y = event->globalY();
}

void gcard::slotReleased(QMouseEvent * event){
    move(base_x, base_y);
    if(next != nullptr)
         releasestack();
    if(drag_action){
        (void) event;
        //generate drop
    }

    drag_action = false;
}

void gcard::slotDoubleclick(QMouseEvent * event){
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
