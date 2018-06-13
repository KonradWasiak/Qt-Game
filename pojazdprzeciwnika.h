#ifndef POJAZDPRZECIWNIKA_H
#define POJAZDPRZECIWNIKA_H
#include "pojazd.h"
#include <QString>
class PojazdPrzeciwnika: public Pojazd
{
public:
    PojazdPrzeciwnika();
    PojazdPrzeciwnika(QString n, int z, int zl);
    void setZlotoZprzeciwnika(int x);
    int getZlotoZprzeciwnika();

    void setSzybkoscPrzeciwnika(int s);
    int getSzybkoscPrzeciwnika();

    void setBonus(int x);
    int getBonus();
protected:
    int szybkoscPrzeciwnika;
    int zlotoZprzeciwnika;
};

#endif // POJAZDPRZECIWNIKA_H
