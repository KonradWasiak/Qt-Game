#ifndef PRZECIWNIK2_H
#define PRZECIWNIK2_H

#include <QGraphicsRectItem>
#include <QObject>
#include "przeciwnikczolg.h"
#include "QGraphicsPixmapItem"

class Przeciwnik2: public QObject,public QGraphicsPixmapItem

{
    Q_OBJECT
public:
    Przeciwnik2(QGraphicsItem * parent=0);
    PrzeciwnikCzolg *czolgPrzeciwnika;
    int tempZyciePrzeciwnika2;
    int tempZlotoZPrzeciwnika2;
    int tempPancerzPrzeciwnika2;
public slots:
//    void generowaniePrzeciwnika();
    void ruchPrzeciwnika2();
};

#endif // PRZECIWNIK2_H
