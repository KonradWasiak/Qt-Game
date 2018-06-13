#ifndef GRAGAMEPLAYGRACZ_H
#define GRAGAMEPLAYGRACZ_H
#include "gracz.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class GraGameplayGracz: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    GraGameplayGracz(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

    bool czyGraczZywy = 1;
    int iloscZabitychPrzeciwnikow;
    int tempZycieGracza;
    int tempZlotoGracza;
    int tempSzybkoscPodstawowaGracza;
    int tempDoswiadczenieGracza;
    int tempOgienPodstawowyGracza;
    int tempOgienDodatkowyGracza;
    int tempPancerzGracza;
    int tempSzybkoscDodatkowaGracza;
    int tempZlotoDodatkoweGracza;
    int tempPancerzDodatkowyGracza;
    int wybranyPojazd;
    QString sciezkaDoGrafiki;
};

#endif // GRAGAMEPLAYGRACZ_H
