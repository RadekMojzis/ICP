#ifndef GCARD_INCLUDED
#define GCARD_INCLUDED
#include <QWidget>
#include <QLabel>
#include <vector>
#include "deck.hpp"
#include "game.hpp"
#include <QPushButton>
typedef int CardID;

extern std::vector <QPixmap*> cards;
const int FOUNDATION_X = 1050;
class GPU;

class gcard : public QLabel{
    Q_OBJECT
private:
    bool disabled;
    int number;

    int base_drag_x;
    int base_drag_y;

    bool drag_action = false;
    void releasestack();
    void dragstack(int x, int y);
    int game_id;
    GPU *gpu;
public:

    int base_x;
    int base_y;

    void rescale(bool scaling= false,int inxeg = 0);
    DeckID src;
    gcard* next = nullptr;
    gcard(CardID card,
          int x,
          int y,
          std::vector<QPixmap*>& cards,
          bool disabledrag,
          QWidget * parent,
          GPU* main_gpu,
          bool scaling = false,
          int index =0
          );
    ~gcard(){}

signals:
    void clicked(QMouseEvent * event);
    void released(QMouseEvent * event);
    void doubleclick(QMouseEvent * event);
    void movement(QMouseEvent * event);

public slots:
    void slotClicked(QMouseEvent * event);
    void slotReleased(QMouseEvent * event);
    void slotDoubleclick(QMouseEvent * event);
    void slotmovement(QMouseEvent * event);

protected:
    void mousePressEvent ( QMouseEvent * event ) ;
    void mouseReleaseEvent ( QMouseEvent * event ) ;
    void mouseDoubleClickEvent( QMouseEvent * event ) ;
    void mouseMoveEvent( QMouseEvent * event ) ;
};


class GPU: public QWidget{
    Q_OBJECT
    // you put cards from deck here
    private:
        QWidget window;
        vector <QPixmap*> cards;
        void load_images();
        QPushButton *new_game_btn;
        vector<QPushButton*> load;
        vector<QPushButton*> save;
        vector<QPushButton*> undo;
        vector<QPushButton*> exit;

        vector<int> game_slot_ocupied;
        vector<vector<vector<gcard*>>> foundations;
        vector<vector<vector<gcard*>>> piles;
        vector<gcard*> flip;
        vector<gcard*> stock;
        void rescale( bool scaling, int gameidx);

    public:
        int get_dst_deck(int base_x,int base_y, int g_index);
        void exit_game(int id);
        vector<Game*> game;
        bool scaling = false;
        void execute_action(int src, int dst, int card,int g_id);
        void new_game();
        void draw_game(int gameid);
        void draw_deck(DeckID deck, int i);
        void draw_card(Card *card, DeckID decks, int gameid);
        int run();
        void clear(int id);
        GPU();
        ~GPU(){};
public slots:
    void new_game_clicked(){new_game();};
};


class button: public QPushButton{
    Q_OBJECT
    private:
        int g_id;
        GPU *gpu;
        int pos_x;
        int pos_y;
public:
        button(QString name, QWidget * parent, int gid,bool scaling,int x, int y, GPU*main_gpu);
        void rescale(bool scaling, int gameindex);
};

#endif
