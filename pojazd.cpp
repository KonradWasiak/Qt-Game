#include "pojazd.h"

Pojazd::Pojazd()
{
    zycie = 3;
    nazwaPojazdu = "Pojazd bez nazwy";
}

Pojazd::Pojazd(QString n, int z)
{
    zycie = z;
    nazwaPojazdu = n;

}

void Pojazd::setZycie(int z)
{
    zycie = z;
}

int Pojazd::getZycie()
{
    return zycie;
}

