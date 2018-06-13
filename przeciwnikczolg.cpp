#include "przeciwnikczolg.h"

PrzeciwnikCzolg::PrzeciwnikCzolg(): PojazdPrzeciwnika()
{
    pancerzCzolguPrzeciwnika = 0;
}

void PrzeciwnikCzolg::setPancerzCzolguPrzeciwnika(int pa)
{
    pancerzCzolguPrzeciwnika = pa;
}

int PrzeciwnikCzolg::getPancerzCzolguPrzeciwnika()
{
    return pancerzCzolguPrzeciwnika;
}


