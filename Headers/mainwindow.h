//****************************************************************************
//      Class to define window for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es) || (ivanoterouvigo@gmail.com)
//      25/01/2017
//****************************************************************************
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// NEW
#include <QMessageBox>

#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QStringList>
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
#include "storeplanes.h"
#include "plane3d.h"
#include <iostream>
#include <stdio.h>
#include <QVarLengthArray>

#include <QtXml>
#include <QDomDocument>
#include "dialog.h"
#include "getlocation.h"
#include <QtOpenGL>
#include <QGL>
#include <QGLWidget>

#include <iostream>
#include <list>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/AABB_tree.h>
#include <CGAL/AABB_traits.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/boost/graph/graph_traits_Polyhedron_3.h>
#include <CGAL/AABB_face_graph_triangle_primitive.h>

typedef CGAL::Simple_cartesian<double> K;
typedef K::Point_3 Point;
typedef K::Plane_3 Plane;
typedef K::Segment_3 Segment;
typedef K::Ray_3 Ray;
typedef CGAL::Polyhedron_3<K> Polyhedron;
typedef CGAL::AABB_face_graph_triangle_primitive<Polyhedron> Primitive;
typedef CGAL::AABB_traits<K, Primitive> Traits;
typedef CGAL::AABB_tree<Traits> Tree;
typedef boost::optional< Tree::Intersection_and_primitive_id<Segment>::Type > Segment_intersection;
typedef boost::optional< Tree::Intersection_and_primitive_id<Plane>::Type > Plane_intersection;
typedef Tree::Primitive_id Primitive_id;

typedef CGAL::Polyhedron_3<K> Surface_3D;

typedef K::Point_3 Point_3D;
typedef K::Plane_3 Plane_3D;
typedef K::Vector_3 Vector;

// TODO: IVAN test code
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/intersections.h>
typedef CGAL::Exact_predicates_exact_constructions_kernel K_01;
typedef K_01::Point_2 Point_2;
typedef K_01::Segment_2 Segment_2;
typedef K_01::Line_2 Line_2;
typedef K_01::Intersect_2 Intersect_2;

// TODO: IVAN step 1
#include <CGAL/Plane_3.h>
#include <CGAL/Point_3.h>
#include <CGAL/Line_3.h>
#include <CGAL/Vector_3.h>
#include <CGAL/Ray_3.h>

// typedef CGAL:Exact_predicates_exact_construtions_kernel Kernel;
typedef K_01::Plane_3 Plane_3;
typedef K_01::Point_3 Point_3;
typedef K_01::Vector_3 Vector_3;
typedef K_01::Line_3 Line_3;

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

    void crear_building (Building& input);

    void crear_header();

    void crear_building2spaces (Building& input);

    void crear_gbxml (Gbxml& gbxml, Building input);

    void crear_storePlanes (Storeplanes& input);

    int getIndexRoofPlane (Storeplanes& input);

    int getIndexUnderPlane (Storeplanes& input);

    int getD1TemIndependent (int v1, int v2, int v3, int p1, int p2, int p3);

    int getIntersect (int v1, int v2, int v3, int p1, int p2, int p3);

    int getDeterminante(QVector<QVector<int>> matriz, int n);

    QVector<QVector<int>> getMatrizA(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9);

    void printMatriz(QVector<QVector<int>> matriz);

    QVector<QVector<int>> getInversaA(QVector<QVector<int>> matriz);

    QVector<QVector<int>> getTranspuesta(QVector<QVector<int>> matriz);

    QVector<QVector<int>> getAdjunta(QVector<QVector<int>> matriz);

    QVector<QVector<int>> getCalculoInversa(QVector<QVector<int>> matriz, int det);

    void setFile(QString nameFile, QDomDocument contenido);

    void readFileGbXML(QString nameFile);

    void on_loadConfig_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_own_math_clicked();

    void on_calculate_clicked();

    void on_cgal_001_clicked();

    void on_cgal_002_clicked();

    void on_getPoints_clicked();

    double getTermIndependent (double v1, double v2, double v3, double p1, double p2, double p3);

    double getIntersection (double d1, double d2, double d3, double v1, double v2, double v3);

    double getDeterminant(QVector<QVector<double>> matrix, double n);

    QVector<QVector<double>> setMatrix(double v1, double v2, double v3, double v4, double v5, double v6, double v7, double v8, double v9);

    void printMatrix(QVector<QVector<double>> matrix);

    QVector<QVector<double>> getInverse(QVector<QVector<double>> matrix);

    QVector<QVector<double>> getTranspose(QVector<QVector<double>> matrix);

    QVector<QVector<double>> getAttache(QVector<QVector<double>> matrix);

    QVector<QVector<double>> getResultInverse(QVector<QVector<double>> matrix, double det);

    void makeBuildingFromPoints (Building& input);

private:
    Ui::MainWindow *ui;

    // NEW
    QLineEdit *edit_fileName;

    QStringList valores_combo;
    QComboBox* combo_buildings;

    QStringList list_buildingTypes;
    QComboBox* cb_buildingType;

    QStringList list_surfaceTypes;
    QComboBox* cb_surfaceTypes;

    QStringList list_constructionIdRefs;
    QComboBox* cb_constructionIdRef;

    QStringList list_openingTypes;
    QComboBox* cb_openingType;

    Dialog* form_dialog;
    GetLocation* form_location;

};

#endif // MAINWINDOW_H
