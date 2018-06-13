#include "wyswietlaniezlota.h"
#include <QFont>

WyswietlanieZlota::WyswietlanieZlota(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    zlotoWyswietlane = 0;
    setPlainText(QString("ZŁOTO: ") + QString::number(zlotoWyswietlane));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",16));
}

void WyswietlanieZlota::zwiekszenieZlota(int x){
    zlotoWyswietlane += x;
    setPlainText(QString("ZŁOTO: ") + QString::number(zlotoWyswietlane));
}
