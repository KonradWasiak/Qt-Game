#include "pociskprzeciwpancerny.h"
#include "przeciwnik.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "qdebug.h"
#include "gragameplay.h"
extern GraGameplay *Gameplay;

PociskPrzeciwpancerny::PociskPrzeciwpancerny(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    if(Gameplay->gracz->wybranyPojazd == 2)
    {
    setPixmap(QPixmap(":/img/RAKIETAA.png"));
    }
    else if(Gameplay->gracz->wybranyPojazd == 3)
    {
        setPixmap(QPixmap(":/img/BOMBAA.png"));

    }
    QTimer *zegar = new QTimer(this);
    connect(zegar,SIGNAL(timeout()),this,SLOT(ruchPociskuPrzeciwpancernego()));
    zegar->start(50);
}

void PociskPrzeciwpancerny::ruchPociskuPrzeciwpancernego()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
       for (int i = 0, n = colliding_items.size(); i < n; ++i)
       {
           if (typeid(*(colliding_items[i])) == typeid(Przeciwnik2))
           {
               if(((Przeciwnik2&)*colliding_items[i]).tempZyciePrzeciwnika2 <= 0)
               {
                    Gameplay->gracz->iloscZabitychPrzeciwnikow += 1;
                    Gameplay->gracz->tempZlotoGracza += (((Przeciwnik2&)*colliding_items[i]).tempZlotoZPrzeciwnika2 + Gameplay->gracz->tempZlotoDodatkoweGracza);
                    Gameplay->gracz->tempDoswiadczenieGracza += 2;
                    Gameplay->wyswietlanieZlota->zwiekszenieZlota(((Przeciwnik&)*colliding_items[i]).tempZlotoZPrzeciwnika);
                    scene()->removeItem(colliding_items[i]);
                    scene()->removeItem(this);
                    delete colliding_items[i];
                    delete this;
                    return;
               }
               else if(((Przeciwnik2&)*colliding_items[i]).tempZyciePrzeciwnika2 > 0)
               {
                   (((Przeciwnik2&)*colliding_items[i]).tempZyciePrzeciwnika2) -= Gameplay->gracz->tempOgienDodatkowyGracza;
                   scene()->removeItem(this);
                   delete this;
                   return;
               }

           }

       }
       setPos(x(),y()-5);
       if(pos().y() + 27 < 0)
       {
           scene()->removeItem(this);
           delete this;
       }
}
