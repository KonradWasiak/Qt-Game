#ifndef PRZECIWNIK_H
#define PRZECIWNIK_H

#include <QGraphicsRectItem>
#include <QObject>
#include "przeciwnikczolg.h"
#include "przeciwniksamolot.h"
#include "QGraphicsPixmapItem"

class Przeciwnik: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Przeciwnik(QGraphicsItem * parent=0);
    PrzeciwnikSamolot *samolotPrzeciwnika;
    int tempZyciePrzeciwnika;
    int tempZlotoZPrzeciwnika;
    int tempUnikPrzeciwnika;
public slots:
    void ruchPrzeciwnika();
};

#endif // PRZECIWNIK_H
