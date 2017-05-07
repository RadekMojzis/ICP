#include <iostream>
#include <vector>
#include <QMouseEvent>
#include "gcard.h"

std::vector <QPixmap*> cards;

gcard::gcard(CardID card, int x, int y, QWidget * parent):QLabel(parent){
    connect( this, SIGNAL( clicked(QMouseEvent * )), this, SLOT( slotClicked(QMouseEvent * ) ) );
    connect( this, SIGNAL( released(QMouseEvent * ) ), this, SLOT( slotReleased(QMouseEvent * ) ) );
    connect( this, SIGNAL( doubleclick(QMouseEvent * ) ), this, SLOT( slotDoubleclick(QMouseEvent * ) ) );
    connect( this, SIGNAL( movement(QMouseEvent * ) ), this, SLOT( slotmovement(QMouseEvent * ) ) );

    base_x = x;
    base_y = y;

    setPixmap(*cards[card]);
    resize(122,174);
    move(x, y);
    setStyleSheet("border: 1px solid grey");
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
    base_drag_x = event->globalX();
    base_drag_y = event->globalY();

    std::cout << "He clicked on me [" << number <<"]!" <<  std::endl;
}

void gcard::slotReleased(QMouseEvent * event){
    move(base_x, base_y);
    if(drag_action){
        (void) event;
        //generate drop
    }

    std::cout << "released! [" << number <<"]!" <<  std::endl;
    drag_action = false;
}

void gcard::slotDoubleclick(QMouseEvent * event){
    std::cout << "doubleclick [" << number <<"]!" <<  std::endl;
}

void gcard::slotmovement(QMouseEvent * event){
    int x = base_x + event->globalX() - base_drag_x;
    int y = base_y + event->globalY() - base_drag_y;
    drag_action = true;
    move(x, y);

    std::cout << "movement over [" << number <<"]!" <<  std::endl;
}

