#include "pociskdodatkowy.h"
#include "przeciwnik.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "qdebug.h"
#include "gragameplay.h"
extern GraGameplay *Gameplay;

PociskDodatkowy::PociskDodatkowy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/img/POCISKK.png"));
    QTimer *zegar = new QTimer(this);
    connect(zegar,SIGNAL(timeout()),this,SLOT(ruchPociskuDodatkowego()));
    zegar->start(50);

}

void PociskDodatkowy::ruchPociskuDodatkowego()
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
                    Gameplay->wyswietlanieZlota->zwiekszenieZlota(((Przeciwnik&)*colliding_items[i]).tempZlotoZPrzeciwnika + Gameplay->gracz->tempZlotoDodatkoweGracza);
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

       }

       setPos(x(),y()-8);
       if (pos().y() + 20 < 0)
       {
           scene()->removeItem(this);
           delete this;
       }
}

