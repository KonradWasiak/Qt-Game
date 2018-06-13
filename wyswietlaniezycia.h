#ifndef WYSWIETLANIEZYCIA_H
#define WYSWIETLANIEZYCIA_H


#include <QGraphicsTextItem>

class WyswietlanieZycia: public QGraphicsTextItem{
public:
    WyswietlanieZycia(QGraphicsItem * parent=0);
    void zmniejszenieZycia();
private:
    int zycieWyswietlane;
};
#endif // WYSWIETLANIEZYCIA_H
