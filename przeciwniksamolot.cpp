#include "przeciwniksamolot.h"

PrzeciwnikSamolot::PrzeciwnikSamolot(): PojazdPrzeciwnika()
{
    unik = 0;

}

PrzeciwnikSamolot::PrzeciwnikSamolot(QString n, int z, int zl, int un): PojazdPrzeciwnika(n, z, zl)
{
    unik = un;
    zlotoZprzeciwnika = z;
}

void PrzeciwnikSamolot::setUnik(int x)
{
    unik = x;
}

int PrzeciwnikSamolot::getUnik()
{
    return unik;
}

