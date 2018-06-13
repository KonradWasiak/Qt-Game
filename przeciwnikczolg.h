#ifndef PRZECIWNIKCZOLG_H
#define PRZECIWNIKCZOLG_H
#include "pojazdprzeciwnika.h"

class PrzeciwnikCzolg: public PojazdPrzeciwnika
{
public:
    PrzeciwnikCzolg();
    PrzeciwnikCzolg(QString n, int z, int zl, int pa);
    void setPancerzCzolguPrzeciwnika(int pa);
    int getPancerzCzolguPrzeciwnika();
private:
    int pancerzCzolguPrzeciwnika;

};

#endif // PRZECIWNIKCZOLG_H
