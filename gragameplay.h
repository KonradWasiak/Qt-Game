#ifndef GRAGAMEPLAY_H
#define GRAGAMEPLAY_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "gragameplaygracz.h"
#include "przeciwnik.h"
#include "przeciwnik2.h"
#include "wyswietlaniezycia.h"
#include "wyswietlaniezlota.h"

class GraGameplay: public QGraphicsView
{
    Q_OBJECT
public:
    GraGameplay(QWidget *parent = 0);
    QGraphicsScene *scena;
    GraGameplayGracz *gracz;
    Przeciwnik *przeciwnik;
    Przeciwnik2 *przeciwnik2;
    WyswietlanieZycia *wyswietlanieZycia;
    WyswietlanieZlota *wyswietlanieZlota;

public slots:
    void generowaniePrzeciwnika();
    void generowaniePrzeciwnika2();

private:
};

#endif // GRAGAMEPLAY_H
