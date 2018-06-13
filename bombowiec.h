#ifndef BOMBOWIEC_H
#define BOMBOWIEC_H
#include "pojazdgracza.h"

class Bombowiec: public PojazdGracza
{
public:
    Bombowiec();
    Bombowiec(int pd, int b, int z, int op, int p, int u, int s);

public:

    int getUzbrojenieDodatkowe();
    void setUzbrojenieDodatkowe(int x);

    int getBonus();
    void setBonus(int x);
private:
    int pancerzDodatkowy;
    int bomby;
};

#endif // BOMBOWIEC_H
