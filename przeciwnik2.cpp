#include "przeciwnik2.h"
#include "gracz.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QApplication>
#include "gragameplay.h"
#include "glowneokno.h"
#include "gragameplaygracz.h"

extern Gracz *ObecnyGracz;
extern GraGameplay *Gameplay;
extern GlowneOkno *w;

Przeciwnik2::Przeciwnik2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    czolgPrzeciwnika = new PrzeciwnikCzolg();
    czolgPrzeciwnika->setZycie(((Gameplay->gracz->iloscZabitychPrzeciwnikow) / 10) + 1);
    czolgPrzeciwnika->setPancerzCzolguPrzeciwnika(((Gameplay->gracz->iloscZabitychPrzeciwnikow) / 10) + 10);

    int losowanaWspolrzednaPrzeciwnika2 = rand() % 700;

        tempZyciePrzeciwnika2 = 1;
        tempPancerzPrzeciwnika2 = czolgPrzeciwnika->getPancerzCzolguPrzeciwnika();
        tempZlotoZPrzeciwnika2 = ((Gameplay->gracz->iloscZabitychPrzeciwnikow) / 10) + 2;

        setPos(losowanaWspolrzednaPrzeciwnika2, 0);
        QTimer *zegar = new QTimer(this);
        connect(zegar,SIGNAL(timeout()),this,SLOT(ruchPrzeciwnika2()));
        zegar->start(20);
}

void Przeciwnik2::ruchPrzeciwnika2()
{
    setPos(x(),y()+ 2);
      if (pos().y() + 40 > 600)
      {
          scene()->removeItem(this);
          delete czolgPrzeciwnika;
          delete this;

          if(Gameplay->gracz->tempPancerzGracza > 0)
          {
            Gameplay->gracz->tempPancerzGracza -= 1;
          }
          else
          {
              if(Gameplay->gracz->tempPancerzDodatkowyGracza > 0)
              {
                  Gameplay->gracz->tempPancerzGracza -= 1;
              }
              else
              {
              Gameplay->gracz->tempZycieGracza -= 1;
              Gameplay->wyswietlanieZycia->zmniejszenieZycia();
              }
          }

          if(Gameplay->gracz->czyGraczZywy == true)
          {
          if(Gameplay->gracz->tempZycieGracza <= 0)
          {
              Gameplay->gracz->czyGraczZywy = false;
              ObecnyGracz->setZloto(Gameplay->gracz->tempZlotoGracza);
              ObecnyGracz->setDoswiadczenie(Gameplay->gracz->tempDoswiadczenieGracza);
              Gameplay->close();
              w->show();
              w->setEnabled(true);
          }
          }
      }

}

