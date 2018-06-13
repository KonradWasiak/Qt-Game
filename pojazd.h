#ifndef POJAZD_H
#define POJAZD_H
#include <QString>

class Pojazd
{
public:
    Pojazd();
    Pojazd(QString n,int z);

    virtual int getBonus()=0;
    virtual void setBonus(int x)=0;
    void setZycie(int z);
    int getZycie();
protected:
    QString nazwaPojazdu;
    int zycie;

};

#endif // POJAZD_H
