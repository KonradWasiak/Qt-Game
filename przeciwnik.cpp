#include "przeciwnik.h"
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

Przeciwnik::Przeciwnik(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    samolotPrzeciwnika = new PrzeciwnikSamolot();
    samolotPrzeciwnika->setZycie(((Gameplay->gracz->iloscZabitychPrzeciwnikow) / 10) + 3);
    samolotPrzeciwnika->setUnik(((Gameplay->gracz->iloscZabitychPrzeciwnikow) / 10) + 1);

    int losowanaWspolrzednaPrzeciwnika = rand() % 700;

        tempZyciePrzeciwnika = samolotPrzeciwnika->getZycie();
        tempUnikPrzeciwnika = samolotPrzeciwnika->getUnik();
        tempZlotoZPrzeciwnika = ((Gameplay->gracz->iloscZabitychPrzeciwnikow) / 10) + 5;

        setPos(losowanaWspolrzednaPrzeciwnika, 0);

        QTimer *zegar = new QTimer(this);
        connect(zegar,SIGNAL(timeout()),this,SLOT(ruchPrzeciwnika()));
        zegar->start(20);
}

void Przeciwnik::ruchPrzeciwnika()
{
    setPos(x(),y()+ ((Gameplay->gracz->iloscZabitychPrzeciwnikow) / 10) + 3);
      if (pos().y() + 40 > 600)
      {
          scene()->removeItem(this);
          delete samolotPrzeciwnika;
          delete this;


          if(Gameplay->gracz->tempPancerzDodatkowyGracza > 0)
          {
              Gameplay->gracz->tempPancerzDodatkowyGracza -= 1;
          }
          else
          {
              Gameplay->gracz->tempZycieGracza -= 1;
              Gameplay->wyswietlanieZycia->zmniejszenieZycia();
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



