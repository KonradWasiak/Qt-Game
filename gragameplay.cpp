#include "gragameplay.h"
#include "gragameplaygracz.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "glowneokno.h"
#include "qdebug.h"
#include "QGraphicsPixmapItem"

extern Gracz *ObecnyGracz;
extern GlowneOkno *w;
GraGameplay::GraGameplay(QWidget *parent)
{

        this->setFixedSize(800,600);
        setBackgroundBrush(QBrush(QImage(":/img/TLOGRY.png")));

        scena = new QGraphicsScene();
        scena->setSceneRect(0,0,800,600);
        setScene(scena);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(800,600);
        gracz = new GraGameplayGracz();
        gracz->setPixmap(QPixmap(gracz->sciezkaDoGrafiki));
        gracz->setPos(400, 500);
        gracz->setFlag(QGraphicsItem::ItemIsFocusable);
        gracz->setFocus();
        scena->addItem(gracz);
        gracz->grabKeyboard();


        wyswietlanieZycia = new WyswietlanieZycia();
        wyswietlanieZycia->setPos(wyswietlanieZycia->x() + 10,wyswietlanieZycia->y()+25);
        scena->addItem(wyswietlanieZycia);

        wyswietlanieZlota = new WyswietlanieZlota();
        wyswietlanieZlota->setPos(wyswietlanieZlota->x() + 10,wyswietlanieZlota->y()+50);
        scena->addItem(wyswietlanieZlota);

        QTimer * timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(generowaniePrzeciwnika()));
        timer->start((2000-(gracz->iloscZabitychPrzeciwnikow * 1000)));
        timer->stop();
        QTimer * timer2 = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(generowaniePrzeciwnika2()));
        timer->start((5000-(gracz->iloscZabitychPrzeciwnikow * 1000)));
        timer2->stop();
        show();

}

void GraGameplay::generowaniePrzeciwnika()
{
    przeciwnik = new Przeciwnik();
    przeciwnik->setPixmap(QPixmap(":/img/PRZECIWNIKSAMOLOT.png"));
    scene()->addItem(przeciwnik);
}
void GraGameplay::generowaniePrzeciwnika2()
{
    przeciwnik2 = new Przeciwnik2();
    przeciwnik2->setPixmap(QPixmap(":/img/PRZECIWNIKCZOLG.png"));
    scene()->addItem(przeciwnik2);
}
