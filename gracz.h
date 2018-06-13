#ifndef GRACZ_H
#define GRACZ_H
#include "pojazd.h"
#include "samolot.h"
#include "helikopter.h"
#include "bombowiec.h"
#include <QString>

class Gracz
{
public:
    Gracz();
    Gracz(QString nazwaG);
    void setZloto(int z);
    void setDoswiadczenie(int d);
    void setPoziom(int p);
    int getZloto();
    int getPoziom();
    int getDoswiadczenie();
    void zapiszStanGracza(QString nazwaGracza);
    void zaladujStanGracza(QString nazwaGracza);
    static void dodajGracza(QString nazwaNowegoGracza);
    PojazdGracza *pierwszy;
    PojazdGracza  *drugi;
    PojazdGracza  *trzeci;

    Gracz & operator=(const Gracz& zrodlowy);

private:
    int zloto;
    int doswiadczenie;
    int poziom;

};

#endif // GRACZ_H
