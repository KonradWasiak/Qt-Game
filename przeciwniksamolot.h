#ifndef PRZECIWNIKSAMOLOT_H
#define PRZECIWNIKSAMOLOT_H
#include "pojazdprzeciwnika.h"

class PrzeciwnikSamolot: public PojazdPrzeciwnika
{
public:
    PrzeciwnikSamolot();
    PrzeciwnikSamolot(QString n, int z, int zl, int un);
    void setUnik(int x);
    int getUnik();
private:
    int unik;

};

#endif // PRZECIWNIKSAMOLOT_H
