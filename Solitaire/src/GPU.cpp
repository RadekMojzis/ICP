#include"interface.hpp"


void GPU::load_images(){
    QString path = "D:/testground/QT/cards/";
    QString cardname;
    for(int i = 0; i < 52; i++){
        if(i < 52)
            cardname = "S";
        if(i < 39)
            cardname = "H";
        if(i < 26)
            cardname = "D";
        if(i < 13)
            cardname = "C";

        cardname += QString::number(i%13);
        cardname += ".png";

        cards.push_back(new QPixmap(path + cardname));
    }
}


GPU::GPU(){
    window.resize(800, 450);
    window.show();
    window.setWindowTitle("Solitere");

    load_images();

    window.show();
    cout << "Ahoj!" << endl;
    draw_game();
    qApp->exec();
}

void GPU::draw_game(){
    vector <QPixmap*> & images = cards;
    gcard *karta = new gcard(27, 10, 10, images, &window);
    gcard *karta2 = new gcard(50, 140, 10, images, &window);
    gcard *karta3 = new gcard(35, 10, 50, images, &window);

}

void GPU::draw_deck(DeckID id){
    (void) id;
}

void GPU::draw_card(Card *card){
    (void) card;
}

void GPU::new_game(){

}
