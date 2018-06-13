#-------------------------------------------------
#
# Project created by QtCreator 2017-12-30T17:02:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIDOGRY
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        glowneokno.cpp \
    pojazd.cpp \
    gracz.cpp \
    samolot.cpp \
    helikopter.cpp \
    bombowiec.cpp \
    przeciwniksamolot.cpp \
    przeciwnikczolg.cpp \
    pojazdgracza.cpp \
    pojazdprzeciwnika.cpp \
    gragameplay.cpp \
    gragameplaygracz.cpp \
    pocisk.cpp \
    przeciwnik.cpp \
    pociskprzeciwpancerny.cpp \
    przeciwnik2.cpp \
    pociskdodatkowy.cpp \
    wyswietlaniezycia.cpp \
    wyswietlaniezlota.cpp

HEADERS += \
        glowneokno.h \
    pojazd.h \
    gracz.h \
    samolot.h \
    helikopter.h \
    bombowiec.h \
    przeciwniksamolot.h \
    przeciwnikczolg.h \
    pojazdgracza.h \
    pojazdprzeciwnika.h \
    gragameplay.h \
    gragameplaygracz.h \
    pocisk.h \
    przeciwnik.h \
    pociskprzeciwpancerny.h \
    przeciwnik2.h \
    pociskdodatkowy.h \
    wyswietlaniezycia.h \
    wyswietlaniezlota.h

FORMS += \
        glowneokno.ui

RESOURCES += \
    zasoby.qrc

DISTFILES += \
    gra.qmodel
