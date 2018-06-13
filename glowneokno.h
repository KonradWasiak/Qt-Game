#ifndef GLOWNEOKNO_H
#define GLOWNEOKNO_H

#include <QMainWindow>
#include "gracz.h"
#include "przeciwnik.h"
#include "gragameplay.h"
namespace Ui {
class GlowneOkno;
}

class GlowneOkno : public QMainWindow
{
    Q_OBJECT

public:
    explicit GlowneOkno(QWidget *parent = 0);
    void sprawdzDostepnoscUlepszen();
    int wyborPojazdu;
    ~GlowneOkno();
    Ui::GlowneOkno *ui;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_17_clicked();

    void on_napraw1_clicked();

    void on_ulepsz11_clicked();

    void on_ulepsz12_clicked();

    void on_ulepsz13_clicked();

    void on_ulepsz14_clicked();

    void on_ulepsz15_clicked();

    void on_napraw2_clicked();

    void on_ulepsz21_clicked();

    void on_ulepsz22_clicked();

    void on_ulepsz23_clicked();

    void on_ulepsz24_clicked();

    void on_ulepsz25_clicked();

    void on_napraw3_clicked();

    void on_ulepsz31_clicked();

    void on_ulepsz32_clicked();

    void on_ulepsz33_clicked();

    void on_ulepsz34_clicked();

    void on_ulepsz35_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:

};

#endif // GLOWNEOKNO_H
