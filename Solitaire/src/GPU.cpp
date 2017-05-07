#include"interface.hpp"
#include <QDir>

void GPU::load_images(){
    QString dir = "D:/FIT/ICP/Solitaire/";

    QString path = dir + "img/";
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
    window.resize(1200, 675);
    window.show();
    window.setWindowTitle("Solitere");

    load_images();

    window.show();
    draw_game();
    qApp->exec();
}

void GPU::draw_game(){
    clear();
    vector <QPixmap*> & images = cards;
    gcard *karta = new gcard(27, 10, 10, images, false, &window);
    gcard *karta2 = new gcard(50, 140, 10, images,false, &window);
    (void) karta2;
    gcard *karta3 = new gcard(35, 10, 50, images,false, &window);
    karta->next = karta3;

}

void GPU::draw_deck(DeckID deck){
    if(deck == STOCK || deck == FLIP || deck == F_HEARTS || deck == F_DIAMONDS|| deck == F_CLUBS|| deck == F_SPADES){
        draw_card(game.get_top(deck), deck);
        return;
    }
    vector<Card> & cards = game.get_deck(deck);
    for(auto card = cards.begin(); card < cards.end(); card++) {
        draw_card(&(*card), deck);
    }
}

void GPU::draw_card(Card *card, DeckID deck){
    gcard* ncard;
    switch (deck) {
        case F_HEARTS:
            ncard = new gcard(card->get_id(), 1050, 10, cards, true, &window);
            hearts.push_back(ncard);
            ncard->src = F_HEARTS;
          break;
        case F_SPADES:
            ncard = new gcard(card->get_id(), 1050, 390, cards, true, &window);
            hearts.push_back(ncard);
            ncard->src = F_SPADES;
            break;
        case F_DIAMONDS:
            ncard = new gcard(card->get_id(), 1050, 200, cards, true, &window);
            hearts.push_back(ncard);
            ncard->src = F_DIAMONDS;
            break;
        case F_CLUBS:
            ncard = new gcard(card->get_id(), 1050, 580, cards, true, &window);
            hearts.push_back(ncard);
            ncard->src = F_CLUBS;
            break;
        case PILE1:
            ncard = new gcard(card->get_id(), 140, 10 + 30 * pile0.size(), cards, false, &window);
            if(pile0.size())
                (*pile0.end())->next = ncard;
            pile0.push_back(ncard);
            ncard->src = PILE1;
          break;
        case PILE2:
            ncard = new gcard(card->get_id(), 270, 10 + 30 * pile1.size(), cards, false, &window);
            if(pile1.size())
                (*pile1.end())->next = ncard;
            pile1.push_back(ncard);
            ncard->src = PILE2;
          break;
        case PILE3:
            ncard = new gcard(card->get_id(), 400, 10 + 30 * pile2.size(), cards, false, &window);
            if(pile2.size())
                (*pile2.end())->next = ncard;
            pile2.push_back(ncard);
            ncard->src = PILE3;
          break;
        case PILE4:
            ncard = new gcard(card->get_id(), 530, 10 + 30 * pile3.size(), cards, false, &window);
            if(pile3.size())
                (*pile3.end())->next = ncard;
            pile3.push_back(ncard);
            ncard->src = PILE4;
          break;
        case PILE5:
            ncard = new gcard(card->get_id(), 660, 10 + 30 * pile4.size(), cards, false, &window);
            if(pile4.size())
                (*pile4.end())->next = ncard;
            pile4.push_back(ncard);
            ncard->src = PILE5;
          break;
        case PILE6:
            ncard = new gcard(card->get_id(), 890, 10 + 30 * pile5.size(), cards, false, &window);
            if(pile5.size())
                (*pile5.end())->next = ncard;
            pile5.push_back(ncard);
            ncard->src = PILE6;
          break;
        case PILE7:
            ncard = new gcard(card->get_id(), 1020, 10 + 30 * pile6.size(), cards, false, &window);
            if(pile6.size())
                (*pile6.end())->next = ncard;
            pile6.push_back(ncard);
            ncard->src = PILE7;
          break;
        case STOCK:
            ncard = new gcard(card->get_id(), 10, 10, cards, true, &window);
            ncard->src = STOCK;
          break;
        case FLIP:
            ncard = new gcard(card->get_id(), 10, 390, cards, false, &window);
            ncard->src = FLIP;
          break;
        default:
            break;
    }
}

void GPU::new_game(){

}

void GPU::clear(){
    for(auto card = hearts.begin(); card < hearts.end(); card++) {
        delete *card;
    }
    for(auto card = spades.begin(); card < spades.end(); card++) {
        delete *card;
    }
    for(auto card = clubs.begin(); card < clubs.end(); card++) {
        delete *card;
    }
    for(auto card = diamonds.begin(); card < diamonds.end(); card++) {
        delete *card;
    }
    for(auto card = pile0.begin(); card < pile0.end(); card++) {
        delete *card;
    }
    for(auto card = pile1.begin(); card < pile1.end(); card++) {
        delete *card;
    }
    for(auto card = pile2.begin(); card < pile2.end(); card++) {
        delete *card;
    }
    for(auto card = pile3.begin(); card < pile3.end(); card++) {
        delete *card;
    }
    for(auto card = pile4.begin(); card < pile4.end(); card++) {
        delete *card;
    }
    for(auto card = pile5.begin(); card < pile5.end(); card++) {
        delete *card;
    }
    for(auto card = pile6.begin(); card < pile6.end(); card++) {
        delete *card;
    }
    for(auto card = flip.begin(); card < flip.end(); card++) {
        delete *card;
    }
    for(auto card = stock.begin(); card < stock.end(); card++) {
        delete *card;
    }
}
