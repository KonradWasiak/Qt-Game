#include "helikopter.h"

Helikopter::Helikopter():PojazdGracza()
{
    szybkoscDodatkowa = 0;
    rakiety = 0;
}

Helikopter::Helikopter(int sd, int r, int z, int op, int p, int u, int s): PojazdGracza("HELIKOPTER", z, op, p, u, s)
{
    szybkoscDodatkowa = sd;
    rakiety = r;
}

void Helikopter::setBonus(int sd)
{
    szybkoscDodatkowa = sd;
}

int Helikopter::getBonus()
{
    return szybkoscDodatkowa;
}


int Helikopter::getUzbrojenieDodatkowe()
{
    return rakiety;
}
void Helikopter::setUzbrojenieDodatkowe(int x)
{
    rakiety += x;
}



