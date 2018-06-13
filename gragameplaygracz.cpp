#include "gragameplaygracz.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "pocisk.h"
#include "przeciwnik.h"
#include "glowneokno.h"
#include "qdebug.h"
#include "pociskprzeciwpancerny.h"
#include "pociskdodatkowy.h"

extern Gracz *ObecnyGracz;
extern GraGameplay *Gameplay;
extern GlowneOkno *w;

GraGameplayGracz::GraGameplayGracz(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    if(w->wyborPojazdu == 1)
    {
        iloscZabitychPrzeciwnikow = 0;
        tempDoswiadczenieGracza = ObecnyGracz->getDoswiadczenie();
        tempZycieGracza = ObecnyGracz->pierwszy->getZycie();
        tempOgienPodstawowyGracza = ObecnyGracz->pierwszy->getOgienPodstawowy();
        tempOgienDodatkowyGracza = ObecnyGracz->pierwszy->getUzbrojenieDodatkowe();
        tempZlotoGracza = ObecnyGracz->getZloto();
        tempDoswiadczenieGracza = ObecnyGracz->getDoswiadczenie();
        tempZlotoDodatkoweGracza = ObecnyGracz->pierwszy->getBonus();
        tempSzybkoscPodstawowaGracza = ObecnyGracz->pierwszy->getSzybkosc();
        tempPancerzGracza = ObecnyGracz->pierwszy->getPancerz();
        tempPancerzDodatkowyGracza = 0;

        sciezkaDoGrafiki = ":/img/MYSLIWIECC.png" ;

        wybranyPojazd = 1;
    }
    if(w->wyborPojazdu == 2)
    {
        iloscZabitychPrzeciwnikow = 0;
        tempDoswiadczenieGracza = ObecnyGracz->getDoswiadczenie();
        tempZycieGracza = ObecnyGracz->drugi->getZycie();
        tempOgienPodstawowyGracza = ObecnyGracz->drugi->getOgienPodstawowy();
        tempOgienDodatkowyGracza = ObecnyGracz->drugi->getUzbrojenieDodatkowe();
        tempZlotoGracza = ObecnyGracz->getZloto();
        tempDoswiadczenieGracza = ObecnyGracz->getDoswiadczenie();
        tempSzybkoscDodatkowaGracza = ObecnyGracz->drugi->getBonus();
        tempSzybkoscPodstawowaGracza = ObecnyGracz->drugi->getSzybkosc();
        tempPancerzDodatkowyGracza = 0;
        tempZlotoDodatkoweGracza = 0;
        tempPancerzGracza = ObecnyGracz->pierwszy->getPancerz();

        sciezkaDoGrafiki = ":/img/HELI.png" ;


        wybranyPojazd = 2;

    }
    if(w->wyborPojazdu == 3)
    {
        iloscZabitychPrzeciwnikow = 0;
        tempDoswiadczenieGracza = ObecnyGracz->getDoswiadczenie();
        tempZycieGracza = ObecnyGracz->trzeci->getZycie();
        tempOgienPodstawowyGracza = ObecnyGracz->trzeci->getOgienPodstawowy();
        tempOgienDodatkowyGracza = ObecnyGracz->trzeci->getUzbrojenieDodatkowe();
        tempZlotoGracza = ObecnyGracz->getZloto();
        tempDoswiadczenieGracza = ObecnyGracz->getDoswiadczenie();
        tempPancerzDodatkowyGracza = ObecnyGracz->trzeci->getBonus();
        tempSzybkoscPodstawowaGracza = ObecnyGracz->trzeci->getSzybkosc();
        tempZlotoDodatkoweGracza = 0;
        tempPancerzGracza = ObecnyGracz->pierwszy->getPancerz();

        sciezkaDoGrafiki = ":/img/BOMBOWIECC.png" ;

        wybranyPojazd = 3;

    }
}

void GraGameplayGracz::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A)
    {
        if (pos().x() > 0)
        setPos((x()-tempSzybkoscPodstawowaGracza),y());
    }
     if (event->key() == Qt::Key_D)
    {
       if (pos().x() + 100 < 800)
        setPos((x()+tempSzybkoscPodstawowaGracza),y());
    }
     if(event->key() == Qt::Key_Space && wybranyPojazd == 1)
    {
        Pocisk * pocisk = new Pocisk();
        pocisk->setPos(x()-5,y());
        scene()->addItem(pocisk);
        Pocisk * pocisk2 = new Pocisk();
        pocisk2->setPos(x()+30,y());
        scene()->addItem(pocisk2);
        PociskDodatkowy * pocisk3 = new PociskDodatkowy();
        pocisk3->setPos(x()+12,y());
        scene()->addItem(pocisk3);
    }
     if(event->key() == Qt::Key_Space && (wybranyPojazd == 2 || wybranyPojazd == 3))
     {
         Pocisk * pocisk = new Pocisk();
         pocisk->setPos(x()+15,y());
         scene()->addItem(pocisk);
     }
     if(event->key() == Qt::Key_Backspace && (wybranyPojazd == 2 || wybranyPojazd == 3))
    {
        PociskPrzeciwpancerny * pociskPrzeciwpancerny = new PociskPrzeciwpancerny();
        pociskPrzeciwpancerny->setPos(x()+16,y());
        scene()->addItem(pociskPrzeciwpancerny);
    }

     if (event->key() == Qt::Key_O  && wybranyPojazd == 2)
     {
         if (pos().x() > 0)
         setPos(x()-((tempSzybkoscDodatkowaGracza * 10)+tempSzybkoscPodstawowaGracza),y());
     }
      if (event->key() == Qt::Key_P && wybranyPojazd == 2)
     {
        if (pos().x() + 100 < 800)
         setPos(x()+((tempSzybkoscDodatkowaGracza * 10)+tempSzybkoscPodstawowaGracza),y());
     }
}


