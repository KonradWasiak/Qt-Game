#ifndef HELIKOPTER_H
#define HELIKOPTER_H
#include "pojazdgracza.h"

class Helikopter: public PojazdGracza
{
public:
    Helikopter();
    Helikopter(int sd, int r,int z, int op, int p, int u, int s);

    int getUzbrojenieDodatkowe();
    void setUzbrojenieDodatkowe(int x);

    int getBonus();
    void setBonus(int x);
private:
    int szybkoscDodatkowa;
    int rakiety;
};

#endif // HELIKOPTER_H
