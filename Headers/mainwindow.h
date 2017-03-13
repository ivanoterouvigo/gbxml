//****************************************************************************
//      Class to define window for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es)
//      25/01/2017
//****************************************************************************
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QStringList>
#include <QMessageBox>
#include <QFileDialog>
#include "gbxml.h"
#include "location.h"
#include "building.h"
#include "buildingstorey.h"
#include "spaceb.h"
#include <vector>
#include "plane3d.h"
#include "storeplanes.h"
#include "storespaces.h"
#include "storebuildingstoreis.h"
#include "cartesianpoint.h"
#include "string"
#include <iostream>
#include <stdio.h>
#include <QVarLengthArray>
#include <QtXml>
#include <QDomDocument>
#include "dialog.h"
#include <QtOpenGL>
#include <QGL>
#include <QGLWidget>
#include <list>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loadFile_clicked();

    void setStoreSpaces (Storespaces& input);

    void setStorePlanes (Storeplanes& input);
    
    void makeBuildingFromPoints (Building& input, Storespaces input2);

    void getPoints(Storespaces storespace, Building& edificio);

    int getIndexRoofPlane (Storeplanes& input);

    int getIndexUnderPlane (Storeplanes& input);

    double getAzimuth(double v1, double v2, double v3);

    double getTilt(double v1, double v2, double v3);

    double getTermIndependent (double v1, double v2, double v3, double p1, double p2, double p3);

    QVector<QVector<double>> setMatrix(double v1, double v2, double v3, double v4, double v5, double v6, double v7, double v8, double v9);

    QVector<QVector<double>> getInverse(QVector<QVector<double>> matrix);

    double getDeterminant(QVector<QVector<double>> matrix, double n);

    QVector<QVector<double>> getTranspose(QVector<QVector<double>> matrix);

    QVector<QVector<double>> getAttache(QVector<QVector<double>> matrix);

    QVector<QVector<double>> getResultInverse(QVector<QVector<double>> matrix, double det);

    double getIntersection (double d1, double d2, double d3, double v1, double v2, double v3);

    double getDistance(double v1, double v2, double v3, double v4, double v5, double v6);

    void crear_gbxml (Gbxml& gbxml, Building input);

    QDomDocument generateGbxml (Gbxml& input);

    void setFile(QString nameFile, QDomDocument contenido);


private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
