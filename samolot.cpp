#include "samolot.h"

Samolot::Samolot(): PojazdGracza()
{
    ogienDodatkowy = 0;
    bonusZlota = 0;
}

Samolot::Samolot(int od, int dz, int z, int op, int p, int u, int s): PojazdGracza("SAMOLOT",z , op, p, u, s)
{
    ogienDodatkowy = od;
    bonusZlota = dz;
}

void Samolot::setUzbrojenieDodatkowe(int x){
    ogienDodatkowy = x;
}

int Samolot::getBonus()
{
    return bonusZlota;
}

void Samolot::setBonus(int x)
{
    bonusZlota = x;
}

int Samolot::getUzbrojenieDodatkowe()
{
    return ogienDodatkowy;
}




