#ifndef POCISKDODATKOWY_H
#define POCISKDODATKOWY_H
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class PociskDodatkowy: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PociskDodatkowy(QGraphicsItem * parent=0);
public slots:
    void ruchPociskuDodatkowego();
};
#endif // POCISKDODATKOWY_H
