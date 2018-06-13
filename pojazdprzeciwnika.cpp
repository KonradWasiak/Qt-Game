#include "pojazdprzeciwnika.h"
#include <QString>

PojazdPrzeciwnika::PojazdPrzeciwnika(): Pojazd()
{
    szybkoscPrzeciwnika = 10;
    zlotoZprzeciwnika = 1;
}

PojazdPrzeciwnika::PojazdPrzeciwnika(QString n, int z, int zl)
{
    nazwaPojazdu = n;
    zycie = z;
    zlotoZprzeciwnika = zl;
}

void PojazdPrzeciwnika::setZlotoZprzeciwnika(int x)
{
    zlotoZprzeciwnika = x;
}

int PojazdPrzeciwnika::getZlotoZprzeciwnika()
{
    return zlotoZprzeciwnika;
}

void PojazdPrzeciwnika::setSzybkoscPrzeciwnika(int s)
{
    szybkoscPrzeciwnika = s;
}

int PojazdPrzeciwnika::getSzybkoscPrzeciwnika()
{
    return szybkoscPrzeciwnika;
}

void PojazdPrzeciwnika::setBonus(int x)
{/*PRZECIWNIK NIE POSIADA BONUSÓW*/}

int PojazdPrzeciwnika::getBonus()
{/*PRZECIWNIK NIE POSIADA BONUSÓW*/ return 0;}
