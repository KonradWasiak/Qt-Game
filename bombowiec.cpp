#include "bombowiec.h"

Bombowiec::Bombowiec()
{
    pancerzDodatkowy = 0;
    bomby = 3;
}

Bombowiec::Bombowiec(int pd, int b, int z, int op, int p, int u, int s): PojazdGracza("BOMBOWIEC", z, op, p, u, s)
{
    pancerzDodatkowy = pd;
    bomby = b;
}

void Bombowiec::setBonus(int pd)
{
    pancerzDodatkowy = pd;
}

int Bombowiec::getBonus()
{
    return pancerzDodatkowy;
}

void Bombowiec::setUzbrojenieDodatkowe(int b)
{
    bomby = b;
}

int Bombowiec::getUzbrojenieDodatkowe()
{
    return bomby;
}

