
#include <QWidget>
#include <QLabel>
#include <vector>
typedef int CardID;

extern std::vector <QPixmap*> cards;

class gcard : public QLabel{
    Q_OBJECT
private:
    int number;
    int deck;

    int base_x;
    int base_y;

    int base_drag_x;
    int base_drag_y;

    bool drag_action = false;
public:
    gcard(CardID card, int x, int y, std::vector<QPixmap*>& cards, QWidget * parent);
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
