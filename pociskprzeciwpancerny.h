#ifndef POCISKPRZECIWPANCERNY_H
#define POCISKPRZECIWPANCERNY_H
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
class PociskPrzeciwpancerny: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PociskPrzeciwpancerny(QGraphicsItem * parent=0);
public slots:
    void ruchPociskuPrzeciwpancernego();
};

#endif // POCISKPRZECIWPANCERNY_H
