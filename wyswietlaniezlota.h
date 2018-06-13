#ifndef WYSWIETLANIEZLOTA_H
#define WYSWIETLANIEZLOTA_H


#include <QGraphicsTextItem>

class WyswietlanieZlota: public QGraphicsTextItem{
public:
    WyswietlanieZlota(QGraphicsItem * parent=0);
    void zwiekszenieZlota(int x);
private:
    int zlotoWyswietlane;
};
#endif // WYSWIETLANIEZLOTA_H
