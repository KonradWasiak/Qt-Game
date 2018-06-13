#include "pocisk.h"
#include "przeciwnik.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "qdebug.h"
#include "gragameplay.h"
extern GraGameplay *Gameplay;

Pocisk::Pocisk(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/img/POCISKK.png"));
    QTimer *zegar = new QTimer(this);
    connect(zegar,SIGNAL(timeout()),this,SLOT(ruchPocisku()));
    zegar->start(50);

}

void Pocisk::ruchPocisku()
{


    QList<QGraphicsItem *> colliding_items = collidingItems();
       for (int i = 0, n = colliding_items.size(); i < n; ++i)
       {
           if (typeid(*(colliding_items[i])) == typeid(Przeciwnik) && ((Przeciwnik&)*colliding_items[i]).tempZyciePrzeciwnika <= 0)
           {
               int szansaUniku = (rand() % 10) + 1;
               if(Gameplay->przeciwnik->tempUnikPrzeciwnika >= szansaUniku)
               {
                    Gameplay->gracz->iloscZabitychPrzeciwnikow += 1;
                    Gameplay->gracz->tempZlotoGracza += ((Przeciwnik&)*colliding_items[i]).tempZlotoZPrzeciwnika;
                    Gameplay->gracz->tempDoswiadczenieGracza += 5;
                    Gameplay->wyswietlanieZlota->zwiekszenieZlota(((Przeciwnik&)*colliding_items[i]).tempZlotoZPrzeciwnika  + Gameplay->gracz->tempZlotoDodatkoweGracza);
                    scene()->removeItem(colliding_items[i]);
                    scene()->removeItem(this);
                    delete colliding_items[i];
                    delete this;
                    return;
               }
           }
           else if(typeid(*(colliding_items[i])) == typeid(Przeciwnik) && ((Przeciwnik&)*colliding_items[i]).tempZyciePrzeciwnika > 0)
           {
               int szansaUniku = (rand() % 10) + 1;
               if(Gameplay->przeciwnik->tempUnikPrzeciwnika >= szansaUniku)
               {
               ((Przeciwnik&)*colliding_items[i]).tempZyciePrzeciwnika -= Gameplay->gracz->tempOgienPodstawowyGracza;
               scene()->removeItem(this);
               delete this;
               }
           }

           if (typeid(*(colliding_items[i])) == typeid(Przeciwnik2) && ((Przeciwnik2&)*colliding_items[i]).tempPancerzPrzeciwnika2 <= 0)
           {
                    ((Przeciwnik2&)*colliding_items[i]).tempZyciePrzeciwnika2 = 0;
                    Gameplay->gracz->iloscZabitychPrzeciwnikow += 1;
                    Gameplay->gracz->tempDoswiadczenieGracza += 2;
                    Gameplay->gracz->tempZlotoGracza += (((Przeciwnik&)*colliding_items[i]).tempZlotoZPrzeciwnika + Gameplay->gracz->tempZlotoDodatkoweGracza);
                    Gameplay->wyswietlanieZlota->zwiekszenieZlota(((Przeciwnik&)*colliding_items[i]).tempZlotoZPrzeciwnika);
                    scene()->removeItem(colliding_items[i]);
                    scene()->removeItem(this);
                    delete colliding_items[i];
                    delete this;
                    return;
           }
           else if(typeid(*(colliding_items[i])) == typeid(Przeciwnik2) && ((Przeciwnik2&)*colliding_items[i]).tempZyciePrzeciwnika2 > 0)
           {
               ((Przeciwnik2&)*colliding_items[i]).tempPancerzPrzeciwnika2 -= Gameplay->gracz->tempOgienPodstawowyGracza;
               scene()->removeItem(this);
               delete this;
           }

       }

       setPos(x(),y()-10);
       if (pos().y() + 20 < 0)
       {
           scene()->removeItem(this);
           delete this;
       }
}

