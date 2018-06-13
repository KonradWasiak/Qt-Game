#include "wyswietlaniezycia.h"
#include "glowneokno.h"
#include <QFont>

extern Gracz *ObecnyGracz;
extern GlowneOkno *w;

WyswietlanieZycia::WyswietlanieZycia(QGraphicsItem *parent): QGraphicsTextItem(parent){

    if(w->wyborPojazdu == 1)
    {
    zycieWyswietlane = ObecnyGracz->pierwszy->getZycie();
    }
    if(w->wyborPojazdu == 2)
    {
    zycieWyswietlane = ObecnyGracz->drugi->getZycie();
    }
    if(w->wyborPojazdu == 3)
    {
    zycieWyswietlane = ObecnyGracz->trzeci->getZycie();
    }

    setPlainText(QString("ZYCIE: ") + QString::number(zycieWyswietlane));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void WyswietlanieZycia::zmniejszenieZycia(){
    zycieWyswietlane--;
    setPlainText(QString("ZYCIE: ") + QString::number(zycieWyswietlane));
}
