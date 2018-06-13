#include "glowneokno.h"
#include <QApplication>
#include "gragameplay.h"
GlowneOkno *w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    w = new GlowneOkno();
    w->show();

    return a.exec();
}
