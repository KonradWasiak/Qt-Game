#ifndef POCISK_H
#define POCISK_H
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Pocisk: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Pocisk(QGraphicsItem * parent=0);
public slots:
    void ruchPocisku();
};

#endif // POCISK_H
