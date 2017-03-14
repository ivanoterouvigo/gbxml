//****************************************************************************
//      Class to define window for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es)
//      25/01/2017
//****************************************************************************
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QDebug>
#include <QtXml>
#include <QDomDocument>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


