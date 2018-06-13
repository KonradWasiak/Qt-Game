#ifndef POJAZDGRACZA_H
#define POJAZDGRACZA_H
#include <QString>
#include "pojazd.h"

class PojazdGracza: public Pojazd
{
public:
    PojazdGracza();
    PojazdGracza(QString n, int z, int op, int p, int u, int s);
    //GETTERY:
    int getOgienPodstawowy();
    int getPancerz();
    int getUszkodzenia();
    int getSzybkosc();

    //SETTERY:
    void setOgienPodstawowy(int op);
    void setPancerz(int p);
    void setUszkodzenia(int u);
    void setSzybkosc(int s);

    virtual int getUzbrojenieDodatkowe()=0;
    virtual void setUzbrojenieDodatkowe(int x)=0;

protected:
    int ogienPodstawowy;
    int pancerz;
    int uszkodzenia;
    int szybkosc;
};

#endif // POJAZDGRACZA_H
