#include "glowneokno.h"
#include "ui_glowneokno.h"
#include <QApplication>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QObject>
#include <QPushButton>
#include "pojazd.h"
#include "samolot.h"
#include "bombowiec.h"
#include "gracz.h"
#include <QDebug>
#include "gragameplay.h"
#include "gragameplaygracz.h"
#include <QApplication>

Gracz *ObecnyGracz;
GraGameplay *Gameplay;

GlowneOkno::GlowneOkno(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GlowneOkno)
{
    setFixedSize(800,600);
    ui->setupUi(this);
    this->setWindowTitle("GRA KONRAD WASIAK IP21 POLSL");

    QFile plikZlistaGraczy("ListaGraczy.txt");
    if (plikZlistaGraczy.open(QIODevice::ReadOnly))
    {
       QTextStream wejscie(&plikZlistaGraczy);
       while (!wejscie.atEnd())
       {
           QString linia = wejscie.readLine();
           ui->comboBox->addItem(linia);
       }

       plikZlistaGraczy.close();
    }

    ui->stackedWidget->setCurrentIndex(0);
    ui->wybierz1->setChecked(true);

}

GlowneOkno::~GlowneOkno()
{
    delete ui;
}


void GlowneOkno::sprawdzDostepnoscUlepszen()
{
    if(ObecnyGracz->pierwszy->getUszkodzenia() == 10)
    {
        ui->wybierz1->setEnabled(false);
    }
    if(ObecnyGracz->drugi->getUszkodzenia() == 10)
    {
        ui->wybierz2->setEnabled(false);
    }
    if(ObecnyGracz->trzeci->getUszkodzenia() == 10)
    {
        ui->wybierz2->setEnabled(false);
    }

    if(ObecnyGracz->getZloto() < 25)
    {
        ui->napraw1->setText(QStringLiteral("NAPRAW") +  "(" + QString::number(25) + ")");
        ui->napraw2->setText(QStringLiteral("NAPRAW") +  "(" + QString::number(25) + ")");
        ui->napraw3->setText(QStringLiteral("NAPRAW") +  "(" + QString::number(25) + ")");
        ui->napraw1->setEnabled(false);
        ui->napraw2->setEnabled(false);
        ui->napraw3->setEnabled(false);
    }
    else
    {
    ui->napraw1->setText(QStringLiteral("NAPRAW") +  "(" + QString::number(25) + ")");
    ui->napraw2->setText(QStringLiteral("NAPRAW") +  "(" + QString::number(25) + ")");
    ui->napraw3->setText(QStringLiteral("NAPRAW") +  "(" + QString::number(25) + ")");
    }

    if(ObecnyGracz->pierwszy->getUszkodzenia() == 0)
    {
        ui->napraw1->setEnabled(false);
    }

    if(ObecnyGracz->drugi->getUszkodzenia() == 0)
    {
        ui->napraw2->setEnabled(false);
    }

    if(ObecnyGracz->trzeci->getUszkodzenia() == 0)
    {
        ui->napraw3->setEnabled(false);
    }

    //SAMOLOT:

    if(ObecnyGracz->getZloto() < (200 * ObecnyGracz->pierwszy->getZycie()-1))
    {
        ui->ulepsz11->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->pierwszy->getZycie()))) + ")");
        ui->ulepsz11->setEnabled(false);
    }
    else
    {
    ui->ulepsz11->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->pierwszy->getZycie()))) + ")");
    }

    if(ObecnyGracz->getZloto() < ((200 * (ObecnyGracz->pierwszy->getOgienPodstawowy()))))
    {
        ui->ulepsz12->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->pierwszy->getOgienPodstawowy()))) + ")");
        ui->ulepsz12->setEnabled(false);
    }
    else
    {
    ui->ulepsz12->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->pierwszy->getOgienPodstawowy()))) + ")");
    }

    if(ObecnyGracz->getZloto() < ((200 * (ObecnyGracz->pierwszy->getPancerz()))))
    {
        ui->ulepsz13->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->pierwszy->getPancerz()))) + ")");
        ui->ulepsz13->setEnabled(false);
    }
    else
    {
    ui->ulepsz13->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->pierwszy->getPancerz()))) + ")");
    }

    if(ObecnyGracz->getZloto() < (100+(200 * (ObecnyGracz->pierwszy->getUzbrojenieDodatkowe()))))
    {
        ui->ulepsz14->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(200 * (ObecnyGracz->pierwszy->getUzbrojenieDodatkowe()))) + ")");
        ui->ulepsz14->setEnabled(false);
    }
    else
    {
    ui->ulepsz14->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(200 * (ObecnyGracz->pierwszy->getUzbrojenieDodatkowe()))) + ")");
    }

    if(ObecnyGracz->getZloto() < (100+(200 * (ObecnyGracz->pierwszy->getBonus()))))
    {
        ui->ulepsz15->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(250 * (ObecnyGracz->pierwszy->getBonus()))) + ")");
        ui->ulepsz15->setEnabled(false);
    }
    else
    {
    ui->ulepsz15->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(250 * (ObecnyGracz->pierwszy->getBonus()))) + ")");
    }

    // HELIKOPTER:

    if(ObecnyGracz->getZloto() <((200 * (ObecnyGracz->drugi->getZycie()))))
    {
        ui->ulepsz21->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->drugi->getZycie()))) + ")");
        ui->ulepsz21->setEnabled(false);
    }
    else
    {
    ui->ulepsz21->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->drugi->getZycie()))) + ")");
    }

    if(ObecnyGracz->getZloto() < ((200 * (ObecnyGracz->drugi->getOgienPodstawowy()))))
    {
        ui->ulepsz22->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->drugi->getOgienPodstawowy()))) + ")");
        ui->ulepsz22->setEnabled(false);
    }
    else
    {
    ui->ulepsz22->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->drugi->getOgienPodstawowy()))) + ")");
    }

    if(ObecnyGracz->getZloto() < ((200 * (ObecnyGracz->drugi->getPancerz()))))
    {
        ui->ulepsz23->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->drugi->getPancerz()))) + ")");
        ui->ulepsz23->setEnabled(false);
    }
    else
    {
    ui->ulepsz23->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->drugi->getPancerz()))) + ")");
    }

    if(ObecnyGracz->getZloto() < (100+(200 * (ObecnyGracz->drugi->getUzbrojenieDodatkowe()))))
    {
        ui->ulepsz24->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(200 * (ObecnyGracz->drugi->getUzbrojenieDodatkowe()))) + ")");
        ui->ulepsz24->setEnabled(false);
    }
    else
    {
    ui->ulepsz24->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(200 * (ObecnyGracz->drugi->getUzbrojenieDodatkowe()))) + ")");
    }

    if(ObecnyGracz->getZloto() < (100+(200 * (ObecnyGracz->drugi->getBonus()))))
    {
        ui->ulepsz25->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(250 * (ObecnyGracz->drugi->getBonus()))) + ")");
        ui->ulepsz25->setEnabled(false);
    }
    else
    {
    ui->ulepsz25->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(250 * (ObecnyGracz->drugi->getBonus()))) + ")");
    }
    // BOMBOWIEC:

    if(ObecnyGracz->getZloto() < ((200 * (ObecnyGracz->trzeci->getZycie()))))
    {
        ui->ulepsz31->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->trzeci->getZycie()))) + ")");
        ui->ulepsz31->setEnabled(false);
    }
    else
    {
    ui->ulepsz31->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->trzeci->getZycie()))) + ")");
    }

    if(ObecnyGracz->getZloto() < ((200 * (ObecnyGracz->trzeci->getOgienPodstawowy()))))
    {
        ui->ulepsz32->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->trzeci->getOgienPodstawowy()))) + ")");
        ui->ulepsz32->setEnabled(false);
    }
    else
    {
    ui->ulepsz32->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->trzeci->getOgienPodstawowy()))) + ")");
    }

    if(ObecnyGracz->getZloto() < ((200 * (ObecnyGracz->trzeci->getPancerz()))))
    {
        ui->ulepsz33->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->trzeci->getPancerz()))) + ")");
        ui->ulepsz33->setEnabled(false);
    }
    else
    {
    ui->ulepsz33->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->trzeci->getPancerz()))) + ")");
    }

    if(ObecnyGracz->getZloto() < (100+(200 * (ObecnyGracz->trzeci->getUzbrojenieDodatkowe()))))
    {
        ui->ulepsz34->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(200 * (ObecnyGracz->trzeci->getUzbrojenieDodatkowe()))) + ")");
        ui->ulepsz34->setEnabled(false);
    }
    else
    {
    ui->ulepsz34->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(200 * (ObecnyGracz->trzeci->getUzbrojenieDodatkowe()))) + ")");
    }

    if(ObecnyGracz->getZloto() < (100+(200 * (ObecnyGracz->trzeci->getBonus()))))
    {
        ui->ulepsz35->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(200 * (ObecnyGracz->trzeci->getBonus()))) + ")");
        ui->ulepsz35->setEnabled(false);
    }
    else
    {
    ui->ulepsz35->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(200 * (ObecnyGracz->trzeci->getBonus()))) + ")");
    }
}


void GlowneOkno::on_pushButton_clicked()
{
    QString nazwaGracza = ui->comboBox->currentText();
    if(nazwaGracza.isNull())
    {
        QMessageBox::information(this, "Błąd!", "Nie wybrano gracza lub lista graczy jest pusta.");
    }
    else
    {
    ObecnyGracz = new Gracz(nazwaGracza);
    ui->nazwaGracza->setText(nazwaGracza);
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    ui->poziom->setText(QString::number((ObecnyGracz->getPoziom())));

    ui->iloscZniszczen->setText(QString::number((ObecnyGracz->pierwszy->getUszkodzenia())));
    ui->iloscZniszczen2->setText(QString::number((ObecnyGracz->drugi->getUszkodzenia())));
    ui->iloscZniszczen3->setText(QString::number((ObecnyGracz->trzeci->getUszkodzenia())));

    ui->iloscZycia->setText((QString::number(ObecnyGracz->pierwszy->getZycie())));
    ui->iloscZycia2->setText((QString::number(ObecnyGracz->drugi->getZycie())));
    ui->iloscZycia3->setText((QString::number(ObecnyGracz->trzeci->getZycie())));

    ui->poziomBroni->setText((QString::number(ObecnyGracz->pierwszy->getOgienPodstawowy())));
    ui->poziomBroni2->setText((QString::number(ObecnyGracz->drugi->getOgienPodstawowy())));
    ui->poziomBroni3->setText((QString::number(ObecnyGracz->trzeci->getOgienPodstawowy())));

    ui->poziomPancerza->setText((QString::number(ObecnyGracz->pierwszy->getPancerz())));
    ui->poziomPancerza2->setText((QString::number(ObecnyGracz->drugi->getPancerz())));
    ui->poziomPancerza3->setText((QString::number(ObecnyGracz->trzeci->getPancerz())));

    ui->poziomDodatkowegoKarabinu->setText((QString::number(ObecnyGracz->pierwszy->getUzbrojenieDodatkowe())));
    ui->poziomRakiet->setText((QString::number(ObecnyGracz->drugi->getUzbrojenieDodatkowe())));
    ui->poziomBomb->setText((QString::number(ObecnyGracz->trzeci->getUzbrojenieDodatkowe())));


    ui->dodatkoweZloto->setText((QString::number(ObecnyGracz->pierwszy->getBonus())));
    ui->poziomDodatkowejSzybkosci->setText((QString::number(ObecnyGracz->drugi->getBonus())));
    ui->poziomDodatkowegoPancerza->setText((QString::number(ObecnyGracz->trzeci->getBonus())));
    sprawdzDostepnoscUlepszen();

    //......
    ui->stackedWidget->setCurrentIndex(2);
    }
}

void GlowneOkno::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void GlowneOkno::on_pushButton_3_clicked()
{
    delete Gameplay;
    delete this;
    qApp->exit();
}

void GlowneOkno::on_pushButton_15_clicked()
{
    QString nazwaGracza = ui->plainTextEdit->toPlainText();
    if(nazwaGracza.isEmpty() || nazwaGracza.isNull() || nazwaGracza.contains(" "))
    {
        QMessageBox::information(this, "Błąd!", "Nazwa gracza nie może być pusta i zawierać spacji.");
    }
    else
    {
    ui->comboBox->addItem(nazwaGracza);
    Gracz::dodajGracza(nazwaGracza);
    ui->comboBox->setCurrentText(nazwaGracza);
    ui->stackedWidget->setCurrentIndex(0);
    }
}

void GlowneOkno::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void GlowneOkno::on_pushButton_11_clicked()
{
    QString nazwaGracza = ui->comboBox->currentText();
    ObecnyGracz->zapiszStanGracza(nazwaGracza);
    delete ObecnyGracz;
    ui->stackedWidget->setCurrentIndex(0);
    ui->napraw1->setEnabled(true);
    ui->napraw2->setEnabled(true);
    ui->napraw3->setEnabled(true);
    ui->ulepsz11->setEnabled(true);
    ui->ulepsz12->setEnabled(true);
    ui->ulepsz13->setEnabled(true);
    ui->ulepsz14->setEnabled(true);
    ui->ulepsz15->setEnabled(true);
    ui->ulepsz21->setEnabled(true);
    ui->ulepsz22->setEnabled(true);
    ui->ulepsz23->setEnabled(true);
    ui->ulepsz24->setEnabled(true);
    ui->ulepsz25->setEnabled(true);
    ui->ulepsz31->setEnabled(true);
    ui->ulepsz32->setEnabled(true);
    ui->ulepsz33->setEnabled(true);
    ui->ulepsz34->setEnabled(true);
    ui->ulepsz35->setEnabled(true);



}

void GlowneOkno::on_pushButton_8_clicked()
{
    if(ui->wybierz1->isChecked())
    {
        wyborPojazdu = 1;
    }
    else if(ui->wybierz2->isChecked())
    {
        wyborPojazdu = 2;
    }
    else if(ui->wybierz3->isChecked())
    {
        wyborPojazdu = 3;
    }

    if(wyborPojazdu == 1)
    {
        ObecnyGracz->pierwszy->setUszkodzenia(ObecnyGracz->pierwszy->getUszkodzenia() + 1);
    }
    if(wyborPojazdu == 2)
    {
        ObecnyGracz->pierwszy->setUszkodzenia(ObecnyGracz->pierwszy->getUszkodzenia() + 1);
    }
    if(wyborPojazdu == 3)
    {
        ObecnyGracz->pierwszy->setUszkodzenia(ObecnyGracz->pierwszy->getUszkodzenia() + 1);
    }

     Gameplay = new GraGameplay();
     this->setEnabled(false);
     Gameplay->show();
     this->close();
     ui->stackedWidget->setCurrentIndex(4);
}

void GlowneOkno::on_pushButton_17_clicked()
{
    QString nazwaGracza = ui->comboBox->currentText();
    ObecnyGracz->zapiszStanGracza(nazwaGracza);

}

void GlowneOkno::on_napraw1_clicked()
{
    if(ObecnyGracz->pierwszy->getUszkodzenia() == 0)
    {
        ui->napraw1->setEnabled(false);
    }
    ObecnyGracz->pierwszy->setUszkodzenia(0);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - 25));
    ui->napraw1->setText(QStringLiteral("NAPRAW") + " (" + 25 + ")");
    ui->iloscZniszczen->setText(0);
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz11_clicked()
{
    ObecnyGracz->pierwszy->setZycie(ObecnyGracz->pierwszy->getZycie() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - ((200 * (ObecnyGracz->pierwszy->getZycie()-1)))));
    ui->ulepsz11->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->pierwszy->getZycie()))) + ")");
    ui->iloscZycia->setText((QString::number(ObecnyGracz->pierwszy->getZycie())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz12_clicked()
{

    ObecnyGracz->pierwszy->setOgienPodstawowy(ObecnyGracz->pierwszy->getOgienPodstawowy() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - ((200 * (ObecnyGracz->pierwszy->getOgienPodstawowy()-1)))));
    ui->ulepsz12->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->pierwszy->getOgienPodstawowy()))) + ")");
    ui->poziomBroni->setText((QString::number(ObecnyGracz->pierwszy->getOgienPodstawowy())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz13_clicked()
{
    ObecnyGracz->pierwszy->setPancerz(ObecnyGracz->pierwszy->getPancerz() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - ((200 * (ObecnyGracz->pierwszy->getPancerz()-1)))));
    ui->ulepsz13->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->pierwszy->getPancerz()))) + ")");
    ui->poziomPancerza->setText((QString::number(ObecnyGracz->pierwszy->getPancerz())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz14_clicked()
{
    ObecnyGracz->pierwszy->setUzbrojenieDodatkowe(ObecnyGracz->pierwszy->getUzbrojenieDodatkowe() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - (100+(200 * (ObecnyGracz->pierwszy->getUzbrojenieDodatkowe()-1)))));
    ui->ulepsz14->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(200 * (ObecnyGracz->pierwszy->getUzbrojenieDodatkowe()))) + ")");
    ui->poziomDodatkowegoKarabinu->setText((QString::number(ObecnyGracz->pierwszy->getUzbrojenieDodatkowe())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();

}

void GlowneOkno::on_ulepsz15_clicked()
{
    ObecnyGracz->pierwszy->setBonus(ObecnyGracz->pierwszy->getBonus() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - (100+(250 * (ObecnyGracz->pierwszy->getBonus()-1)))));
    ui->ulepsz15->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(250 * (ObecnyGracz->pierwszy->getBonus()))) + ")");
    ui->dodatkoweZloto->setText((QString::number(ObecnyGracz->pierwszy->getBonus())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_napraw2_clicked()
{
    if(ObecnyGracz->drugi->getUszkodzenia() == 0)
    {
        ui->napraw2->setEnabled(false);
    }
    ObecnyGracz->drugi->setUszkodzenia(0);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - 25));
    ui->napraw2->setText(QStringLiteral("NAPRAW") + " (" + 25 + ")");
    ui->iloscZniszczen->setText(0);
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz21_clicked()
{
    ObecnyGracz->drugi->setZycie(ObecnyGracz->drugi->getZycie() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - ((200 * (ObecnyGracz->drugi->getZycie()-1)))));
    ui->ulepsz21->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->drugi->getZycie()))) + ")");
    ui->iloscZycia2->setText((QString::number(ObecnyGracz->drugi->getZycie())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz22_clicked()
{

    ObecnyGracz->drugi->setOgienPodstawowy(ObecnyGracz->drugi->getOgienPodstawowy() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - ((200 * (ObecnyGracz->drugi->getOgienPodstawowy()-1)))));
    ui->ulepsz22->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->drugi->getPancerz()))) + ")");
    ui->poziomBroni2->setText((QString::number(ObecnyGracz->drugi->getOgienPodstawowy())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz23_clicked()
{
    ObecnyGracz->drugi->setPancerz(ObecnyGracz->drugi->getPancerz() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - ((200 * (ObecnyGracz->drugi->getPancerz()-1)))));
    ui->ulepsz23->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->drugi->getPancerz()))) + ")");
    ui->poziomPancerza2->setText((QString::number(ObecnyGracz->drugi->getPancerz())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz24_clicked()
{
    ObecnyGracz->drugi->setUzbrojenieDodatkowe(ObecnyGracz->drugi->getUzbrojenieDodatkowe() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - (100+(200 * (ObecnyGracz->drugi->getUzbrojenieDodatkowe()-1)))));
    ui->ulepsz24->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(200 * (ObecnyGracz->drugi->getUzbrojenieDodatkowe()))) + ")");
    ui->poziomRakiet->setText((QString::number(ObecnyGracz->drugi->getUzbrojenieDodatkowe())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz25_clicked()
{
    ObecnyGracz->drugi->setBonus(ObecnyGracz->drugi->getBonus() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - (100+(250 * (ObecnyGracz->drugi->getBonus()-1)))));
    ui->ulepsz25->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(250 * (ObecnyGracz->drugi->getBonus()))) + ")");
    ui->poziomDodatkowejSzybkosci->setText((QString::number(ObecnyGracz->drugi->getBonus())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_napraw3_clicked()
{
    if(ObecnyGracz->trzeci->getUszkodzenia() == 0)
    {
        ui->napraw3->setEnabled(false);
    }
    ObecnyGracz->trzeci->setUszkodzenia(0);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - 25));
    ui->napraw3->setText(QStringLiteral("NAPRAW") + " (" + 25 + ")");
    ui->iloscZniszczen3->setText(0);
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz31_clicked()
{
    ObecnyGracz->trzeci->setZycie(ObecnyGracz->trzeci->getZycie() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - ((200 * (ObecnyGracz->trzeci->getZycie()-1)))));
    ui->ulepsz31->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->trzeci->getZycie()))) + ")");
    ui->iloscZycia3->setText((QString::number(ObecnyGracz->trzeci->getZycie())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz32_clicked()
{
    ObecnyGracz->trzeci->setOgienPodstawowy(ObecnyGracz->trzeci->getOgienPodstawowy() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - ((200 * (ObecnyGracz->trzeci->getOgienPodstawowy()-1)))));
    ui->ulepsz32->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->trzeci->getPancerz()))) + ")");
    ui->poziomBroni3->setText((QString::number(ObecnyGracz->trzeci->getOgienPodstawowy())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz33_clicked()
{
    ObecnyGracz->trzeci->setPancerz(ObecnyGracz->trzeci->getPancerz() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - ((200 * (ObecnyGracz->trzeci->getPancerz()-1)))));
    ui->ulepsz33->setText(QStringLiteral("ULEPSZ") + " (" + QString::number((200 * (ObecnyGracz->trzeci->getPancerz()))) + ")");
    ui->poziomPancerza3->setText((QString::number(ObecnyGracz->trzeci->getPancerz())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz34_clicked()
{
    ObecnyGracz->trzeci->setUzbrojenieDodatkowe(ObecnyGracz->trzeci->getUzbrojenieDodatkowe() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - (100+(200 * (ObecnyGracz->trzeci->getUzbrojenieDodatkowe()-1)))));
    ui->ulepsz24->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(200 * (ObecnyGracz->trzeci->getUzbrojenieDodatkowe()))) + ")");
    ui->poziomBomb->setText((QString::number(ObecnyGracz->trzeci->getUzbrojenieDodatkowe())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_ulepsz35_clicked()
{
    ObecnyGracz->trzeci->setBonus(ObecnyGracz->trzeci->getBonus() + 1);
    ObecnyGracz->setZloto((ObecnyGracz->getZloto() - (100+(200 * (ObecnyGracz->trzeci->getBonus()-1)))));
    ui->ulepsz35->setText(QStringLiteral("ULEPSZ") + " (" + QString::number(100+(200 * (ObecnyGracz->trzeci->getBonus()))) + ")");
    ui->poziomDodatkowegoPancerza->setText((QString::number(ObecnyGracz->trzeci->getBonus())));
    ui->iloscZlota->setText(QString::number((ObecnyGracz->getZloto())));
    sprawdzDostepnoscUlepszen();
}

void GlowneOkno::on_pushButton_5_clicked()
{
    QString nazwaGracza = ui->comboBox->currentText();
    ObecnyGracz->zapiszStanGracza(nazwaGracza);
    delete ObecnyGracz;
    delete Gameplay;
    delete this;
    qApp->exit();
}

void GlowneOkno::on_pushButton_6_clicked()
{

}
