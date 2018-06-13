#include "pojazdgracza.h"
#include <QString>

PojazdGracza::PojazdGracza():Pojazd()
{
    ogienPodstawowy = 1;
    pancerz = 1;
    uszkodzenia = 0;
    szybkosc = 25;
}

PojazdGracza::PojazdGracza(QString n, int z, int op, int p, int u, int s): Pojazd(n, z)
{
    ogienPodstawowy = op;
    pancerz = p;
    uszkodzenia = u;
    szybkosc = s;
}

void PojazdGracza::setOgienPodstawowy(int op)
{
    ogienPodstawowy = op;
}

void PojazdGracza::setPancerz(int p)
{
    pancerz = p;
}

void PojazdGracza::setUszkodzenia(int u)
{
    uszkodzenia = u;
}

void PojazdGracza::setSzybkosc(int s)
{
    szybkosc = s;
}

int PojazdGracza::getOgienPodstawowy()
{
    return ogienPodstawowy;
}
int PojazdGracza::getPancerz()
{
    return pancerz;
}
int PojazdGracza::getUszkodzenia()
{
    return uszkodzenia;
}
int PojazdGracza::getSzybkosc()
{
    return szybkosc;
}
