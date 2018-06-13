#ifndef SAMOLOT_H
#define SAMOLOT_H
#include "pojazdgracza.h"

class Samolot: public PojazdGracza
{
public:
     Samolot();
     Samolot(int od, int dz, int z, int op, int p, int u, int s);

     int getUzbrojenieDodatkowe();
     void setUzbrojenieDodatkowe(int x);
     int getBonus();
     void setBonus(int x);
private:
    int ogienDodatkowy;
    int bonusZlota;

};

#endif // SAMOLOT_H
