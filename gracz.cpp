#include "gracz.h"
#include "pojazd.h"
#include "samolot.h"
#include "helikopter.h"
#include "bombowiec.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

Gracz::Gracz()
{
    zloto = 200;
    doswiadczenie = 0;
    poziom = 1;
    pierwszy = new Samolot();
    drugi = new Helikopter();
    trzeci = new Bombowiec();
}

Gracz::Gracz(QString nazwaG)
{
    QFile plikzDanymiGracza(nazwaG + ".txt");
    if (plikzDanymiGracza.open(QIODevice::ReadOnly))
    {
       QTextStream in(&plikzDanymiGracza);
       while (!in.atEnd())
       {
           zloto = (in.readLine()).toInt();
           doswiadczenie= (in.readLine()).toInt();
           poziom = (in.readLine()).toInt();
       }

       plikzDanymiGracza.close();
    }

    int z, op, p, u, s, od, sd, r, b, pd, dz;

    QFile plikZsamolotem(nazwaG + "Samolot.txt");
    if (plikZsamolotem.open(QIODevice::ReadOnly))
    {
       QTextStream in(&plikZsamolotem);
       while (!in.atEnd())
       {
            z = (in.readLine()).toInt();
            op = (in.readLine()).toInt();
            p = (in.readLine()).toInt();
            u = (in.readLine()).toInt();
            s= (in.readLine()).toInt();
            dz = (in.readLine()).toInt();
            od = (in.readLine()).toInt();
       }

       plikzDanymiGracza.close();
    }
    pierwszy = new Samolot(od, dz, z, op, p, u, s);

    QFile plikZhelikopterem(nazwaG + "Helikopter.txt");
    if (plikZhelikopterem.open(QIODevice::ReadOnly))
    {
       QTextStream in(&plikZhelikopterem);
       while (!in.atEnd())
       {
            z = (in.readLine()).toInt();
            op = (in.readLine()).toInt();
            p = (in.readLine()).toInt();
            u = (in.readLine()).toInt();
            s= (in.readLine()).toInt();
            sd = (in.readLine()).toInt();
            r = (in.readLine()).toInt();
       }

       plikzDanymiGracza.close();
    }

    drugi = new Helikopter(sd,  r,  z,  op,  p,  u,  s);


    QFile plikZbombowcem(nazwaG + "Bombowiec.txt");
    if (plikZbombowcem.open(QIODevice::ReadOnly))
    {
       QTextStream in(&plikZbombowcem);
       while (!in.atEnd())
       {
            z = (in.readLine()).toInt();
            op = (in.readLine()).toInt();
            p = (in.readLine()).toInt();
            u = (in.readLine()).toInt();
            s= (in.readLine()).toInt();
            b = (in.readLine()).toInt();
            pd = (in.readLine()).toInt();
       }

       plikzDanymiGracza.close();
    }
    trzeci = new Bombowiec(pd, b, z, op, p, u, s);
}

void Gracz::setZloto(int z)
{
    zloto = z;
}

void Gracz::setDoswiadczenie(int d)
{
    doswiadczenie = d;
}

int Gracz::getZloto()
{
    return zloto;
}

int Gracz::getPoziom()
{
    return poziom;
}

int Gracz::getDoswiadczenie()
{
    return doswiadczenie;
}

void Gracz::zapiszStanGracza(QString nazwaGracza)
{
    poziom = (doswiadczenie / 100)+1;

    QFile plikDaneGracza(nazwaGracza + ".txt");
    if(plikDaneGracza.open(QFile::WriteOnly | QFile::Text))
    {
    QTextStream out(&plikDaneGracza);
    out << getZloto() << endl;
    out << getDoswiadczenie() << endl;
    out << getPoziom();
    plikDaneGracza.flush();
    plikDaneGracza.close();
    }


    QFile plikDaneSamolotuGracza(nazwaGracza + "Samolot.txt");

    if(plikDaneSamolotuGracza.open(QFile::WriteOnly | QFile::Text))

    {
    QTextStream out(&plikDaneSamolotuGracza);

    out << pierwszy->getZycie() << endl;
    out << pierwszy->getOgienPodstawowy() << endl;
    out << pierwszy->getPancerz() << endl;
    out << pierwszy->getUszkodzenia() << endl;
    out << pierwszy->getSzybkosc()<< endl;
    out << pierwszy->getBonus()<< endl;
    out << pierwszy->getUzbrojenieDodatkowe();
    }

    QFile plikDaneHelikopteruGracza(nazwaGracza + "Helikopter.txt");
    if(plikDaneHelikopteruGracza.open(QFile::WriteOnly | QFile::Text))
    {
    QTextStream out(&plikDaneHelikopteruGracza);
    out << drugi->getZycie() << endl;
    out << drugi->getOgienPodstawowy() << endl;
    out << drugi->getPancerz() << endl;
    out << drugi->getUszkodzenia()<< endl;
    out << drugi->getSzybkosc()<< endl;
    out << drugi->getBonus() << endl;
    out << drugi->getUzbrojenieDodatkowe();
    }

    QFile plikDaneBombowcaGracza(nazwaGracza + "Bombowiec.txt");
    if(plikDaneBombowcaGracza.open(QFile::WriteOnly | QFile::Text))
    {
    QTextStream out(&plikDaneBombowcaGracza);
    out << trzeci->getZycie()<< endl;
    out << trzeci->getOgienPodstawowy()<< endl;
    out << trzeci->getPancerz() << endl;
    out << trzeci->getUszkodzenia() << endl;
    out << trzeci->getSzybkosc()<< endl;
    out << trzeci->getUzbrojenieDodatkowe() << endl;
    out << trzeci->getBonus();
    }

}



void Gracz::dodajGracza(QString nazwaNowegoGracza)
{
    Gracz *nowyGracz = new Gracz();
    QFile plikListaGraczy("ListaGraczy.txt");
    if(plikListaGraczy.open(QFile::Append | QFile::Text))
    {
    QTextStream out(&plikListaGraczy);
    out << nazwaNowegoGracza << endl;
    plikListaGraczy.flush();
    plikListaGraczy.close();
    }
    nowyGracz->zapiszStanGracza(nazwaNowegoGracza);
    delete nowyGracz;
}

Gracz &Gracz::operator=(const Gracz &zrodlowy)
{
    zloto = zrodlowy.zloto;
    doswiadczenie = zrodlowy.doswiadczenie;
    poziom = zrodlowy.poziom;
    pierwszy = zrodlowy.pierwszy;
    drugi = zrodlowy.drugi;
    trzeci = zrodlowy.trzeci;

    return (*this);
}
