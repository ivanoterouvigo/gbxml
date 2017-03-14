//****************************************************************************
//      Class to define window for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es)
//      25/01/2017
//****************************************************************************
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtXml>
#include <QDomDocument>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // NEW

    QGridLayout *layoutMain = new QGridLayout();
    layoutMain->addWidget(new QLabel("FileName"),0,0);

    edit_fileName = new QLineEdit();
    layoutMain->addWidget(edit_fileName,0,1);

    this->setWindowTitle("Gbxml parser v0.1");
    this->setLayout(layoutMain);

    QString def_fileGbxml   = ui->lineEditFile->text();

    int value_01 = this->ui->comboBox_bt->currentIndex();
    int value_02 = this->ui->comboBox_st->currentIndex();
    int value_03 = this->ui->comboBox_ct->currentIndex();
    int value_04 = this->ui->comboBox_ot->currentIndex();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loadFile_clicked()
{
    QString def_fileNameGbxml   = "default_gbxml";
    QString def_buildingId      = "default_buildingId";
    QString def_buildingType    = "Colegio_default";

    if (def_fileGbxml.size() > 0 )
    {
        def_fileNameGbxml = def_fileGbxml;
    }
    else
    {
        def_fileGbxml = def_fileNameGbxml;
        QMessageBox::StandardButton answer = QMessageBox::question( this,
                                                                    tr("WARNING: Mensaje información"), tr("¿Has comprobado si has introducido el nombre de fichero?\n"),
                                                                    QMessageBox::No | QMessageBox::Yes,
                                                                    QMessageBox::Yes);
    }

    Building building_obj;
    Storespaces storedspaces_new;
    this->setStoreSpaces(storedspaces_new);

    this->makeBuildingFromPoints(building_obj, storedspaces_new); 

    Gbxml  gbxml_obj;
    this->crear_gbxml(gbxml_obj, building_obj);

    QDomDocument document = this->generateGbxml(gbxml_obj);

    this->setFile(def_fileNameGbxml, document);
}

void MainWindow::setStoreSpaces(Storespaces& storedspaces_new)
{
    std::vector<Storeplanes> storeplanes;
    storedspaces_new.BuildingStoreyName = "bldg-stry-1";
    int num_spaces = 2;

    Storeplanes storedplanes_obj_new1;
    this->setStorePlanes(storedplanes_obj_new1);
    storeplanes.push_back(storedplanes_obj_new1);
    storedspaces_new.spaces = storeplanes;
}

void MainWindow::setStorePlanes(Storeplanes& storeplane_new)
{
    std::vector<Plane3d> vector_planes; 
    std::vector<CartesianPoint> normals;  
    std::vector<CartesianPoint> centroids;  
    Plane3d plane_new;
    CartesianPoint normal;
    CartesianPoint centroid;
    std::string plane_type;
    std::string plane_name;
    std::string plane_type_id;
    std::string plane_undergroud;
    std::string plane_roof;
    std::string plane_exteriorwall;
    std::string plane_interiorwall;
    plane_undergroud    = "UndergroundSlab";
    plane_roof          = "Roof";
    plane_exteriorwall  = "ExteriorWall";
    plane_interiorwall  = "InteriorWall";
    storeplane_new.id = "Space_101"; 
    storeplane_new.buildingStoreyIdRef = "bldg-stry-1"; 
    int n_planes = storeplane_new.planes.size();
    plane_new.name = "suelo";
    plane_new.type_plane_id = "UndergroundSlab";
    normal.x = 0;
    normal.y = 0;
    normal.z = -1;
    normals.push_back(normal);
    plane_new.normals = normals;
    normals.clear();
    centroid.x = 0;
    centroid.y = 0;
    centroid.z = 0;
    centroids.push_back(centroid);
    plane_new.centroids = centroids;
    centroids.clear();
    vector_planes.push_back(plane_new);
    plane_new.name = "techo";
    plane_new.type_plane_id = "Roof";
    normal.x = 0;
    normal.y = 0;
    normal.z = 1;
    normals.push_back(normal);
    plane_new.normals = normals;
    normals.clear();
    centroid.x = 0;
    centroid.y = 0;
    centroid.z = 3;
    centroids.push_back(centroid);
    plane_new.centroids = centroids;
    centroids.clear();
    vector_planes.push_back(plane_new);
    plane_new.name = "lateral1";
    plane_new.type_plane_id = "ExteriorWall";
    normal.x = 0;
    normal.y = 1;
    normal.z = 0;
    normals.push_back(normal);
    plane_new.normals = normals;
    normals.clear();
    centroid.x = 0;
    centroid.y = 0;
    centroid.z = 0;
    centroids.push_back(centroid);
    plane_new.centroids = centroids;
    centroids.clear();
    vector_planes.push_back(plane_new);
    plane_new.name = "lateral2";
    plane_new.type_plane_id = "ExteriorWall";
    normal.x = 1;
    normal.y = 0;
    normal.z = 0;
    normals.push_back(normal);
    plane_new.normals = normals;
    normals.clear();
    centroid.x = 4;
    centroid.y = 0;
    centroid.z = 0;
    centroids.push_back(centroid);
    plane_new.centroids = centroids;
    centroids.clear();
    vector_planes.push_back(plane_new);
    plane_new.name = "lateral3";
    plane_new.type_plane_id = "ExteriorWall";
    normal.x = 0;
    normal.y = -1;
    normal.z = 0;
    normals.push_back(normal);
    plane_new.normals = normals;
    normals.clear();
    centroid.x = 4;
    centroid.y = 5;
    centroid.z = 0;
    centroids.push_back(centroid);
    plane_new.centroids = centroids;
    centroids.clear();
    vector_planes.push_back(plane_new);
    plane_new.name = "lateral4";
    plane_new.type_plane_id = "ExteriorWall";
    normal.x = -1;
    normal.y = 0;
    normal.z = 0;
    normals.push_back(normal);
    plane_new.normals = normals;
    normals.clear();
    centroid.x = 0;
    centroid.y = 5;
    centroid.z = 0;
    centroids.push_back(centroid);
    plane_new.centroids = centroids;
    centroids.clear();
    vector_planes.push_back(plane_new);
    storeplane_new.planes = vector_planes;
    vector_planes.clear();
}

void MainWindow::crear_gbxml(Gbxml& gbxml, Building edificio)
{
    gbxml.volumeUnit    = "CubicMeters";
    gbxml.version       = "0.37";
    gbxml.areaUnit      = "SquareMeters";
    gbxml.temperatureUnit   = "C";
    gbxml.lengthUnit        = "Meters";
    gbxml.campus_id         = "Facility";
    Location loc;
    double def_latitud    = 42.16951136317962;
    double def_longitud   = -8.684827910156287;
    double def_elevacion  = 445;
    QString def_name      = "Vigo";
    loc.latitude    = def_latitud;
    loc.longitude   = def_longitud;
    loc.elevation   = def_elevacion;
    loc.name        = def_name;

    gbxml.location = loc;
    gbxml.building = edificio;
}

void MainWindow::makeBuildingFromPoints (Building& edificio, Storespaces storedspaces_new)
{
    std::vector<BuildingStorey> vbs_obj; 
    std::vector<CartesianPoint> vbs_points; 
    std::vector<Spaceb>         vbs_spaces;
    std::vector<Surface>        vsur_obj;
    std::vector<Surface>        vsur_obj2;
    std::vector<std::string>    v_spaces_surf;
    std::vector<CartesianPoint> vbs_superf_points;
    std::vector<Opening>        vbs_superf_openings;
    std::vector<CartesianPoint> vbs_points_openings;
    BuildingStorey bs_obj;
    CartesianPoint bs_point_obj;
    CartesianPoint superf_point_obj;
    Spaceb  bs_space_obj;
    Surface superf;
    Opening opening;
    edificio.area                 = 0.0;
    edificio.building_id          = "Building_1";
    edificio.building_type        = "Colegio";
    int n_spaces = storedspaces_new.spaces.size();
    if(n_spaces > 0)
    {
        std::string def_consIdRef_roof   = "con-roof_001";
        std::string def_consIdRef_under  = "con-under_001";
        std::string def_consIdRef_exte   = "con-ext_001";
        std::string def_consIdRef_inte   = "con-int_001";
        std::string def_consIdRef_unk    = "con-unknown";
        int index_surf = 0;
        bs_obj.name                 = "Level 1";
        bs_obj.building_storey_id   = "bldg-stry-1";
        bs_obj.level                = 0.000000;
        bs_point_obj.x = 8.000000;
        bs_point_obj.y = 0.000000;
        bs_point_obj.z = 0.000000;
        vbs_points.push_back(bs_point_obj);
        bs_point_obj.x = 8.000000;
        bs_point_obj.y = 5.000000;
        bs_point_obj.z = 0.000000;
        vbs_points.push_back(bs_point_obj);
        bs_point_obj.x = 0.000000;
        bs_point_obj.y = 5.000000;
        bs_point_obj.z = 0.000000;
        vbs_points.push_back(bs_point_obj);
        bs_point_obj.x = 0.000000;
        bs_point_obj.y = 0.000000;
        bs_point_obj.z = 0.000000;
        vbs_points.push_back(bs_point_obj);
        bs_obj.points = vbs_points;
        vbs_points.clear();
        for(int i = 0; i < n_spaces; i++)
        {
            bs_space_obj.space_id               = storedspaces_new.spaces[i].id;
            bs_space_obj.buildingStoreyIdRef    = storedspaces_new.spaces[i].buildingStoreyIdRef;
            int n_sur_spaces = storedspaces_new.spaces[i].planes.size();

            if(n_sur_spaces > 0)
            {
                for(int j = 0; j < n_sur_spaces; j++)
                {
                    index_surf++;
                    superf.surface_id           = "Surface_"+std::to_string(index_surf);
                    superf.surface_type         = "unknown";
                    superf.constructionIdRef    = def_consIdRef_under;
                    v_spaces_surf.push_back(storedspaces_new.spaces[i].id);
                    superf.spaces = v_spaces_surf;
                    v_spaces_surf.clear();

                    superf.azimuth   = storedspaces_new.spaces[i].planes[j].azimuth;
                    superf.tilt      = storedspaces_new.spaces[i].planes[j].tilt;
                    superf.width     = storedspaces_new.spaces[i].planes[j].width;
                    superf.height    = storedspaces_new.spaces[i].planes[j].height;
                    double x_sample = storedspaces_new.spaces[i].planes[j].normals[0].x;
                    double y_sample = storedspaces_new.spaces[i].planes[j].normals[0].y;
                    double z_sample = storedspaces_new.spaces[i].planes[j].normals[0].z;
                    superf.azimuth   = 0;
                    superf.tilt      = 0;
                    superf.width     = 1;
                    superf.height    = 1;
                    superf_point_obj.x = 0;
                    superf_point_obj.y = 0;
                    superf_point_obj.z = 0;
                    vbs_superf_points.push_back(superf_point_obj);
                    superf_point_obj.x = 0;
                    superf_point_obj.y = 0;
                    superf_point_obj.z = 0;
                    vbs_superf_points.push_back(superf_point_obj);
                    superf_point_obj.x = 0;
                    superf_point_obj.y = 0;
                    superf_point_obj.z = 0;
                    vbs_superf_points.push_back(superf_point_obj);
                    superf_point_obj.x = 0;
                    superf_point_obj.y = 0;
                    superf_point_obj.z = 0;
                    vbs_superf_points.push_back(superf_point_obj);
                    superf.points = vbs_superf_points;
                    vbs_superf_points.clear();
                    vsur_obj.push_back(superf);
                }
                bs_space_obj.surfaces = vsur_obj;
                vsur_obj.clear();
            }
            vbs_spaces.push_back(bs_space_obj);
        }
        bs_obj.spaces = vbs_spaces;
        vbs_spaces.clear();
        vbs_obj.push_back(bs_obj);
        edificio.buildingstoreis = vbs_obj;
        vbs_obj.clear();
    }

    this->getPoints(storedspaces_new, edificio);
}

void MainWindow::getPoints(Storespaces storespace, Building& edificio)
{
    int index_UndergroundSlab = 0;
    int index_Roof  = 0;
    int index_lat1  = 2;
    int index_lat2  = 3;
    int index_lat3  = 4;
    int index_lat4  = 5;
    int id_surf     = 0;
    std::string def_consIdRef_roof   = "con-roof_001";
    std::string def_consIdRef_under  = "con-under_001";
    std::string def_consIdRef_exte   = "con-ext_001";
    std::string def_consIdRef_inte   = "con-int_001";
    std::string def_consIdRef_unk    = "con-unknown";
    std::string surf_type_under     = "UndergroundSlab";
    std::string surf_type_roof      = "Roof";
    std::string surf_type_exte      = "ExteriorWall";
    std::string surf_type_inte      = "InteriorWall";

    double v1_nor_under_x = 0.0;
    double v1_nor_under_y = 0.0;
    double v1_nor_under_z = 0.0;
    double azimuth_under = 0.0;
    double tilt_under    = 0.0;
    double v1_nor_roof_x = 0.0;
    double v1_nor_roof_y = 0.0;
    double v1_nor_roof_z = 0.0;
    double azimuth_roof = 0.0;
    double tilt_roof    = 0.0;
    double v1_nor_lat1_x = 0.0;
    double v1_nor_lat1_y = 0.0;
    double v1_nor_lat1_z = 0.0;
    double azimuth_lat1 = 0.0;
    double tilt_lat1    = 0.0;
    double v1_nor_lat2_x = 0.0;
    double v1_nor_lat2_y = 0.0;
    double v1_nor_lat2_z = 0.0;
    double azimuth_lat2 = 0.0;
    double tilt_lat2    = 0.0;
    double v1_nor_lat3_x = 0.0;
    double v1_nor_lat3_y = 0.0;
    double v1_nor_lat3_z = 0.0;
    double azimuth_lat3 = 0.0;
    double tilt_lat3    = 0.0;
    double v1_nor_lat4_x = 0.0;
    double v1_nor_lat4_y = 0.0;
    double v1_nor_lat4_z = 0.0;
    double azimuth_lat4 = 0.0;
    double tilt_lat4    = 0.0;
    double p_nor_under_x = 0.0;
    double p_nor_under_y = 0.0;
    double p_nor_under_z = 0.0;
    double p_nor_roof_x = 0.0;
    double p_nor_roof_y = 0.0;
    double p_nor_roof_z = 0.0;
    double p_nor_lat1_x = 0.0;
    double p_nor_lat1_y = 0.0;
    double p_nor_lat1_z = 0.0;
    double p_nor_lat2_x = 0.0;
    double p_nor_lat2_y = 0.0;
    double p_nor_lat2_z = 0.0;
    double p_nor_lat3_x = 0.0;
    double p_nor_lat3_y = 0.0;
    double p_nor_lat3_z = 0.0;
    double p_nor_lat4_x = 0.0;
    double p_nor_lat4_y = 0.0;
    double p_nor_lat4_z = 0.0;
    double d1 = 0.0;
    double d2 = 0.0;
    double d3 = 0.0;
    double d4 = 0.0;
    double d5 = 0.0;
    double d6 = 0.0;
    QVector<QVector<double>> matrix_A1;
    QVector<QVector<double>> inversa_A1;
    QVector<QVector<double>> matrix_A2;
    QVector<QVector<double>> inversa_A2;
    QVector<QVector<double>> matrix_A3;
    QVector<QVector<double>> inversa_A3;
    QVector<QVector<double>> matrix_A4;
    QVector<QVector<double>> inversa_A4;
    QVector<QVector<double>> matrix_A5;
    QVector<QVector<double>> inversa_A5;
    QVector<QVector<double>> matrix_A6;
    QVector<QVector<double>> inversa_A6;
    QVector<QVector<double>> matrix_A7;
    QVector<QVector<double>> inversa_A7;
    QVector<QVector<double>> matrix_A8;
    QVector<QVector<double>> inversa_A8;
    double width_under  = 0.0;
    double height_under = 0.0;
    double height_lat1  = 0.0;
    double point1_x = 0.0;
    double point1_y = 0.0;
    double point1_z = 0.0;
    double point2_x = 0.0;
    double point2_y = 0.0;
    double point2_z = 0.0;
    double point3_x = 0.0;
    double point3_y = 0.0;
    double point3_z = 0.0;
    double point4_x = 0.0;
    double point4_y = 0.0;
    double point4_z = 0.0;
    double point5_x = 0.0;
    double point5_y = 0.0;
    double point5_z = 0.0;
    double point6_x = 0.0;
    double point6_y = 0.0;
    double point6_z = 0.0;
    double point7_x = 0.0;
    double point7_y = 0.0;
    double point7_z = 0.0;
    double point8_x = 0.0;
    double point8_y = 0.0;
    double point8_z = 0.0;
    double area_building;
    area_building = 0.0;

    int n_spaces = storespace.spaces.size();
    if(n_spaces > 0)
    {
        for(int i = 0; i < n_spaces; i++)
        {
            int n_planes = storespace.spaces[i].planes.size();
            if(n_planes > 0)
            {
                Storeplanes storedplanes_obj = storespace.spaces[i];
                index_UndergroundSlab = this->getIndexUnderPlane(storedplanes_obj);
                index_Roof = this->getIndexRoofPlane(storedplanes_obj);
                v1_nor_under_x = storedplanes_obj.planes[index_UndergroundSlab].normals[0].x;
                v1_nor_under_y = storedplanes_obj.planes[index_UndergroundSlab].normals[0].y;
                v1_nor_under_z = storedplanes_obj.planes[index_UndergroundSlab].normals[0].z;
                azimuth_under = this->getAzimuth(v1_nor_under_x, v1_nor_under_y, v1_nor_under_z);
                tilt_under    = this->getTilt(v1_nor_under_x, v1_nor_under_y, v1_nor_under_z);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].azimuth = azimuth_under;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].tilt = tilt_under;
                v1_nor_roof_x = storedplanes_obj.planes[index_Roof].normals[0].x;
                v1_nor_roof_y = storedplanes_obj.planes[index_Roof].normals[0].y;
                v1_nor_roof_z = storedplanes_obj.planes[index_Roof].normals[0].z;
                azimuth_roof = this->getAzimuth(v1_nor_roof_x, v1_nor_roof_y, v1_nor_roof_z);
                tilt_roof    = this->getTilt(v1_nor_roof_x, v1_nor_roof_y, v1_nor_roof_z);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].azimuth = azimuth_roof;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].tilt = tilt_roof;
                v1_nor_lat1_x = storedplanes_obj.planes[index_lat1].normals[0].x;
                v1_nor_lat1_y = storedplanes_obj.planes[index_lat1].normals[0].y;
                v1_nor_lat1_z = storedplanes_obj.planes[index_lat1].normals[0].z;
                azimuth_lat1 = this->getAzimuth(v1_nor_lat1_x, v1_nor_lat1_y, v1_nor_lat1_z);
                tilt_lat1    = this->getTilt(v1_nor_lat1_x, v1_nor_lat1_y, v1_nor_lat1_z);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].azimuth = azimuth_lat1;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].tilt = tilt_lat1;
                v1_nor_lat2_x = storedplanes_obj.planes[index_lat2].normals[0].x;
                v1_nor_lat2_y = storedplanes_obj.planes[index_lat2].normals[0].y;
                v1_nor_lat2_z = storedplanes_obj.planes[index_lat2].normals[0].z;
                azimuth_lat2 = this->getAzimuth(v1_nor_lat2_x, v1_nor_lat2_y, v1_nor_lat2_z);
                tilt_lat2    = this->getTilt(v1_nor_lat2_x, v1_nor_lat2_y, v1_nor_lat2_z);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].azimuth = azimuth_lat2;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].tilt = tilt_lat2;
                v1_nor_lat3_x = storedplanes_obj.planes[index_lat3].normals[0].x;
                v1_nor_lat3_y = storedplanes_obj.planes[index_lat3].normals[0].y;
                v1_nor_lat3_z = storedplanes_obj.planes[index_lat3].normals[0].z;
                azimuth_lat3 = this->getAzimuth(v1_nor_lat3_x, v1_nor_lat3_y, v1_nor_lat3_z);
                tilt_lat3    = this->getTilt(v1_nor_lat3_x, v1_nor_lat3_y, v1_nor_lat3_z);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].azimuth = azimuth_lat3;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].tilt = tilt_lat3;
                v1_nor_lat4_x = storedplanes_obj.planes[index_lat4].normals[0].x;
                v1_nor_lat4_y = storedplanes_obj.planes[index_lat4].normals[0].y;
                v1_nor_lat4_z = storedplanes_obj.planes[index_lat4].normals[0].z;
                azimuth_lat4 = this->getAzimuth(v1_nor_lat4_x, v1_nor_lat4_y, v1_nor_lat4_z);
                tilt_lat4    = this->getTilt(v1_nor_lat4_x, v1_nor_lat4_y, v1_nor_lat4_z);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].azimuth = azimuth_lat4;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].tilt = tilt_lat4;
                p_nor_under_x = storedplanes_obj.planes[index_UndergroundSlab].centroids[0].x;
                p_nor_under_y = storedplanes_obj.planes[index_UndergroundSlab].centroids[0].y;
                p_nor_under_z = storedplanes_obj.planes[index_UndergroundSlab].centroids[0].z;
                p_nor_roof_x = storedplanes_obj.planes[index_Roof].centroids[0].x;
                p_nor_roof_y = storedplanes_obj.planes[index_Roof].centroids[0].y;
                p_nor_roof_z = storedplanes_obj.planes[index_Roof].centroids[0].z;
                p_nor_lat1_x = storedplanes_obj.planes[index_lat1].centroids[0].x;
                p_nor_lat1_y = storedplanes_obj.planes[index_lat1].centroids[0].y;
                p_nor_lat1_z = storedplanes_obj.planes[index_lat1].centroids[0].z;
                p_nor_lat2_x = storedplanes_obj.planes[index_lat2].centroids[0].x;
                p_nor_lat2_y = storedplanes_obj.planes[index_lat2].centroids[0].y;
                p_nor_lat2_z = storedplanes_obj.planes[index_lat2].centroids[0].z;
                p_nor_lat3_x = storedplanes_obj.planes[index_lat3].centroids[0].x;
                p_nor_lat3_y = storedplanes_obj.planes[index_lat3].centroids[0].y;
                p_nor_lat3_z = storedplanes_obj.planes[index_lat3].centroids[0].z;
                p_nor_lat4_x = storedplanes_obj.planes[index_lat4].centroids[0].x;
                p_nor_lat4_y = storedplanes_obj.planes[index_lat4].centroids[0].y;
                p_nor_lat4_z = storedplanes_obj.planes[index_lat4].centroids[0].z;
                d1 = this->getTermIndependent(v1_nor_under_x, v1_nor_under_y, v1_nor_under_z, p_nor_under_x, p_nor_under_y, p_nor_under_z);
                d2 = this->getTermIndependent(v1_nor_lat1_x, v1_nor_lat1_y, v1_nor_lat1_z, p_nor_lat1_x, p_nor_lat1_y, p_nor_lat1_z);
                d3 = this->getTermIndependent(v1_nor_lat2_x, v1_nor_lat2_y, v1_nor_lat2_z, p_nor_lat2_x, p_nor_lat2_y, p_nor_lat2_z);
                d4 = this->getTermIndependent(v1_nor_lat3_x, v1_nor_lat3_y, v1_nor_lat3_z, p_nor_lat3_x, p_nor_lat3_y, p_nor_lat3_z);
                d5 = this->getTermIndependent(v1_nor_lat4_x, v1_nor_lat4_y, v1_nor_lat4_z, p_nor_lat4_x, p_nor_lat4_y, p_nor_lat4_z);
                d6 = this->getTermIndependent(v1_nor_roof_x, v1_nor_roof_y, v1_nor_roof_z, p_nor_roof_x, p_nor_roof_y, p_nor_roof_z);
                matrix_A1 = this->setMatrix(v1_nor_under_x, v1_nor_under_y, v1_nor_under_z, v1_nor_lat1_x, v1_nor_lat1_y, v1_nor_lat1_z, v1_nor_lat2_x, v1_nor_lat2_y, v1_nor_lat2_z);
                inversa_A1 = this->getInverse(matrix_A1);
                matrix_A2 = this->setMatrix(v1_nor_under_x, v1_nor_under_y, v1_nor_under_z, v1_nor_lat2_x, v1_nor_lat2_y, v1_nor_lat2_z, v1_nor_lat3_x, v1_nor_lat3_y, v1_nor_lat3_z);
                inversa_A2 = this->getInverse(matrix_A2);
                matrix_A3 = this->setMatrix(v1_nor_under_x, v1_nor_under_y, v1_nor_under_z, v1_nor_lat3_x, v1_nor_lat3_y, v1_nor_lat3_z, v1_nor_lat4_x, v1_nor_lat4_y, v1_nor_lat4_z);
                inversa_A3 = this->getInverse(matrix_A3);
                matrix_A4 = this->setMatrix(v1_nor_under_x, v1_nor_under_y, v1_nor_under_z, v1_nor_lat4_x, v1_nor_lat4_y, v1_nor_lat4_z, v1_nor_lat1_x, v1_nor_lat1_y, v1_nor_lat1_z);
                inversa_A4 = this->getInverse(matrix_A4);
                matrix_A5 = this->setMatrix(v1_nor_roof_x, v1_nor_roof_y, v1_nor_roof_z, v1_nor_lat1_x, v1_nor_lat1_y, v1_nor_lat1_z, v1_nor_lat2_x, v1_nor_lat2_y, v1_nor_lat2_z);
                inversa_A5 = this->getInverse(matrix_A5);
                matrix_A6 = this->setMatrix(v1_nor_roof_x, v1_nor_roof_y, v1_nor_roof_z, v1_nor_lat2_x, v1_nor_lat2_y, v1_nor_lat2_z, v1_nor_lat3_x, v1_nor_lat3_y, v1_nor_lat3_z);
                inversa_A6 = this->getInverse(matrix_A6);
                matrix_A7 = this->setMatrix(v1_nor_roof_x, v1_nor_roof_y, v1_nor_roof_z, v1_nor_lat3_x, v1_nor_lat3_y, v1_nor_lat3_z, v1_nor_lat4_x, v1_nor_lat4_y, v1_nor_lat4_z);
                inversa_A7 = this->getInverse(matrix_A7);
                matrix_A8 = this->setMatrix(v1_nor_roof_x, v1_nor_roof_y, v1_nor_roof_z, v1_nor_lat4_x, v1_nor_lat4_y, v1_nor_lat4_z, v1_nor_lat1_x, v1_nor_lat1_y, v1_nor_lat1_z);
                inversa_A8 = this->getInverse(matrix_A8);
                point1_x = this->getIntersection(-d1, -d2, -d3, inversa_A1[0][0], inversa_A1[0][1], inversa_A1[0][2]);
                point1_y = this->getIntersection(-d1, -d2, -d3, inversa_A1[1][0], inversa_A1[1][1], inversa_A1[1][2]);
                point1_z = this->getIntersection(-d1, -d2, -d3, inversa_A1[2][0], inversa_A1[2][1], inversa_A1[2][2]);
                point2_x = this->getIntersection(-d1, -d3, -d4, inversa_A2[0][0], inversa_A2[0][1], inversa_A2[0][2]);
                point2_y = this->getIntersection(-d1, -d3, -d4, inversa_A2[1][0], inversa_A2[1][1], inversa_A2[1][2]);
                point2_z = this->getIntersection(-d1, -d3, -d4, inversa_A2[2][0], inversa_A2[2][1], inversa_A2[2][2]);
                point3_x = this->getIntersection(-d1, -d4, -d5, inversa_A3[0][0], inversa_A3[0][1], inversa_A3[0][2]);
                point3_y = this->getIntersection(-d1, -d4, -d5, inversa_A3[1][0], inversa_A3[1][1], inversa_A3[1][2]);
                point3_z = this->getIntersection(-d1, -d4, -d5, inversa_A3[2][0], inversa_A3[2][1], inversa_A3[2][2]);
                point4_x = this->getIntersection(-d1, -d5, -d1, inversa_A4[0][0], inversa_A4[0][1], inversa_A4[0][2]);
                point4_y = this->getIntersection(-d1, -d5, -d1, inversa_A4[1][0], inversa_A4[1][1], inversa_A4[1][2]);
                point4_z = this->getIntersection(-d1, -d5, -d1, inversa_A4[2][0], inversa_A4[2][1], inversa_A4[2][2]);
                point5_x = this->getIntersection(-d6, -d2, -d3, inversa_A5[0][0], inversa_A5[0][1], inversa_A5[0][2]);
                point5_y = this->getIntersection(-d6, -d2, -d3, inversa_A5[1][0], inversa_A5[1][1], inversa_A5[1][2]);
                point5_z = this->getIntersection(-d6, -d2, -d3, inversa_A5[2][0], inversa_A5[2][1], inversa_A5[2][2]);
                point6_x = this->getIntersection(-d6, -d3, -d4, inversa_A6[0][0], inversa_A6[0][1], inversa_A6[0][2]);
                point6_y = this->getIntersection(-d6, -d3, -d4, inversa_A6[1][0], inversa_A6[1][1], inversa_A6[1][2]);
                point6_z = this->getIntersection(-d6, -d3, -d4, inversa_A6[2][0], inversa_A6[2][1], inversa_A6[2][2]);
                point7_x = this->getIntersection(-d6, -d4, -d5, inversa_A7[0][0], inversa_A7[0][1], inversa_A7[0][2]);
                point7_y = this->getIntersection(-d6, -d4, -d5, inversa_A7[1][0], inversa_A7[1][1], inversa_A7[1][2]);
                point7_z = this->getIntersection(-d6, -d4, -d5, inversa_A7[2][0], inversa_A7[2][1], inversa_A7[2][2]);
                point8_x = this->getIntersection(-d6, -d5, -d1, inversa_A8[0][0], inversa_A8[0][1], inversa_A8[0][2]);
                point8_y = this->getIntersection(-d6, -d5, -d1, inversa_A8[1][0], inversa_A8[1][1], inversa_A8[1][2]);
                point8_z = this->getIntersection(-d6, -d5, -d1, inversa_A8[2][0], inversa_A8[2][1], inversa_A8[2][2]);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].points[0].x = point4_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].points[0].y = point4_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].points[0].z = point4_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].points[1].x = point3_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].points[1].y = point3_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].points[1].z = point3_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].points[2].x = point2_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].points[2].y = point2_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].points[2].z = point2_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].points[3].x = point1_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].points[3].y = point1_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].points[3].z = point1_z;
                width_under  = this->getDistance(point4_x, point4_y, point4_z, point3_x, point3_y, point3_z);
                height_under = this->getDistance(point4_x, point4_y, point4_z, point1_x, point1_y, point1_z);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].width  = width_under;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].height = height_under;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].surface_id = "Surface_"+std::to_string(id_surf);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_UndergroundSlab].surface_type = surf_type_under;
                id_surf = id_surf + 1;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].points[0].x = point8_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].points[0].y = point8_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].points[0].z = point8_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].points[1].x = point5_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].points[1].y = point5_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].points[1].z = point5_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].points[2].x = point6_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].points[2].y = point6_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].points[2].z = point6_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].points[3].x = point7_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].points[3].y = point7_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].points[3].z = point7_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].width  = width_under;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].height = height_under;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].surface_id = "Surface_"+std::to_string(id_surf);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_Roof].surface_type = surf_type_roof;
                id_surf = id_surf + 1;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].points[0].x = point4_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].points[0].y = point4_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].points[0].z = point4_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].points[1].x = point1_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].points[1].y = point1_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].points[1].z = point1_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].points[2].x = point5_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].points[2].y = point5_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].points[2].z = point5_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].points[3].x = point8_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].points[3].y = point8_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].points[3].z = point8_z;
                height_lat1 = this->getDistance(point4_x, point4_y, point4_z, point8_x, point8_y, point8_z);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].width  = width_under;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].height = height_lat1;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].surface_id = "Surface_"+std::to_string(id_surf);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat1].surface_type = surf_type_exte;
                id_surf = id_surf + 1;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].points[0].x = point1_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].points[0].y = point1_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].points[0].z = point1_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].points[1].x = point2_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].points[1].y = point2_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].points[1].z = point2_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].points[2].x = point6_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].points[2].y = point6_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].points[2].z = point6_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].points[3].x = point5_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].points[3].y = point5_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].points[3].z = point5_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].width  = height_under;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].height = height_lat1;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].surface_id = "Surface_"+std::to_string(id_surf);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat2].surface_type = surf_type_exte;
                id_surf = id_surf + 1;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].points[0].x = point2_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].points[0].y = point2_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].points[0].z = point2_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].points[1].x = point3_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].points[1].y = point3_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].points[1].z = point3_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].points[2].x = point7_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].points[2].y = point7_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].points[2].z = point7_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].points[3].x = point6_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].points[3].y = point6_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].points[3].z = point6_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].width  = width_under;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].height = height_lat1;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].surface_id = "Surface_"+std::to_string(id_surf);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat3].surface_type = surf_type_exte;
                id_surf = id_surf + 1;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].points[0].x = point3_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].points[0].y = point3_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].points[0].z = point3_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].points[1].x = point4_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].points[1].y = point4_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].points[1].z = point4_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].points[2].x = point8_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].points[2].y = point8_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].points[2].z = point8_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].points[3].x = point7_x;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].points[3].y = point7_y;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].points[3].z = point7_z;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].width  = height_under;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].height = height_lat1;
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].surface_id = "Surface_"+std::to_string(id_surf);
                edificio.buildingstoreis[0].spaces[i].surfaces[index_lat4].surface_type = surf_type_exte;
                id_surf = id_surf + 1;
            }
            area_building = area_building + getAreaSurface(width_under, height_under);
            edificio.area = area_building;
        }
    }
}

int MainWindow::getIndexUnderPlane (Storeplanes& store)
{
    std::string type_plane_1 = "UndergroundSlab";
    int result = 0;
    int n_planes = store.planes.size();

    if(n_planes > 0)
    {
        for(int i = 0; i < n_planes; i++)
        {
            if(type_plane_1 == store.planes[i].type_plane_id)
            {
                result = i;
            }
        }
    }

    return result;
}

int MainWindow::getIndexRoofPlane (Storeplanes& store)
{
    std::string type_plane_2 = "Roof";
    int result = 0;
    int n_planes = store.planes.size();

    if(n_planes > 0)
    {
        for(int i = 0; i < n_planes; i++)
        {
            if(type_plane_2 == store.planes[i].type_plane_id)
            {
                result = i;
            }
        }
    }
    return result;
}

double MainWindow::getAzimuth(double v1, double v2, double v3)
{
    double pi;
    pi = 3.14159265358979323846;  /* pi */
    double ang = 0;
    double v_azi_x = 1;
    double v_azi_y = 0;
    double v_azi_z = 0;

    double prod_v       = v_azi_x*v1 + v_azi_y*v2 + v_azi_z*v3;
    double mod_v_azi    = sqrt(v_azi_x*v_azi_x + v_azi_y*v_azi_y + v_azi_z*v_azi_z);
    double mod_v        = sqrt(v1*v1 + v2*v2 + v3*v3);
    double result       = prod_v/(mod_v_azi*mod_v);

    double ang1         = acos(result);

    ang = ang1 * (180/pi);
    return ang;
}

double MainWindow::getTilt(double v1, double v2, double v3)
{
    double pi;
    pi = 3.14159265358979323846;  /* pi */
    double ang = 0;
    double v_tilt_x = 0;
    double v_tilt_y = 0;
    double v_tilt_z = 1;
    double prod_v       = v_tilt_x*v1 + v_tilt_y*v2 + v_tilt_z*v3;
    double mod_v_azi    = sqrt(v_tilt_x*v_tilt_x + v_tilt_y*v_tilt_y + v_tilt_z*v_tilt_z);
    double mod_v        = sqrt(v1*v1 + v2*v2 + v3*v3);
    double result       = prod_v/(mod_v_azi*mod_v);
    double ang1         = acos(result);
    ang = ang1 * (180/pi);
    return ang;
}

double MainWindow::getTermIndependent(double v1, double v2, double v3, double p1, double p2, double p3)
{
    double result = 0;
    result = -((v1*p1)+(v2*p2)+(v3*p3));
    return result;
}

QVector<QVector<double>> MainWindow::setMatrix(double v1, double v2, double v3, double v4, double v5, double v6, double v7, double v8, double v9)
{
    QVector<QVector<double>> matrix;
    double massive[3][3] = { {v1, v2, v3}, {v4, v5, v6}, {v7, v8, v9} };
    for(int i = 0; i < 3; i++)
    {
        QVector<double> tempVector;
        for(int j = 0; j < 3; j++)
        {
            tempVector.push_back(massive[i][j]);
        }
        matrix.push_back(tempVector);
    }
    return matrix;
}

QVector<QVector<double>> MainWindow::getInverse(QVector<QVector<double>> matrix)
{
    QVector<QVector<double>> transpuesta_A;
    QVector<QVector<double>> adjunta_A;
    QVector<QVector<double>> inversa_A;

    double detA = this->getDeterminant(matrix, 3);
    if (detA != 0)
    {
        transpuesta_A = this->getTranspose(matrix);
        adjunta_A = this->getAttache(transpuesta_A);
        inversa_A = this->getResultInverse(adjunta_A, detA);
    }
    return inversa_A;
}

double MainWindow::getIntersection (double d1, double d2, double d3, double v1, double v2, double v3)
{
    double result = 0;
    result = ((d1*v1)+(d2*v2)+(d3*v3));
    return result;
}

double MainWindow::getDistance(double v1, double v2, double v3, double v4, double v5, double v6)
{
    double result = 0;
    result = sqrt( pow( (v4 - v1), 2) + pow( (v5 - v2), 2) + pow( (v6 - v3), 2) );
    return result;
}

int MainWindow::getDeterminante(QVector<QVector<int>> matriz, int n)
{
    int det =0;
    QVector<QVector<int>> temp;
    if(n==1)
    {
        return matriz[0][0];
    }
    else if(n==2)
            {
                det=(matriz[0][0]*matriz[1][1]-matriz[0][1]*matriz[1][0]);
                return det;
            } 
            else if (n==3)
                {
                    det=( ( ( matriz[0][0]*matriz[1][1]*matriz[2][2] ) + ( matriz[0][1]*matriz[1][2]*matriz[2][0] ) + (matriz[0][2]*matriz[1][0]*matriz[2][1]) ) - ( ( matriz[0][2]*matriz[1][1]*matriz[2][0] ) + (matriz[0][0]*matriz[1][2]*matriz[2][1]) + (matriz[0][1]*matriz[1][0]*matriz[2][2]) )  );
                    return det;
                }
    return det;
}

QVector<QVector<double>> MainWindow::getTranspose(QVector<QVector<double>> matrix)
{
    QVector<QVector<double>> transpuesta_A;
    double a00 = matrix[0][0];
    double a01 = matrix[0][1];
    double a02 = matrix[0][2];
    double a10 = matrix[1][0];
    double a11 = matrix[1][1];
    double a12 = matrix[1][2];
    double a20 = matrix[2][0];
    double a21 = matrix[2][1];
    double a22 = matrix[2][2];

    transpuesta_A = this->setMatrix(a00, a10, a20, a01, a11, a21, a02, a12, a22);

    return transpuesta_A;
}

QVector<QVector<double>> MainWindow::getAttache(QVector<QVector<double>> matrix)
{
    QVector<QVector<double>> adjunta_A;
    double a00 = (matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1]);
    double a01 = -(matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0]);
    double a02 = (matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0]);
    double a10 = -(matrix[0][1]*matrix[2][2]-matrix[0][2]*matrix[2][1]);
    double a11 = (matrix[0][0]*matrix[2][2]-matrix[0][2]*matrix[2][0]);
    double a12 = -(matrix[0][0]*matrix[2][1]-matrix[0][1]*matrix[2][0]);
    double a20 = (matrix[0][1]*matrix[1][2]-matrix[0][2]*matrix[1][1]);
    double a21 = -(matrix[0][0]*matrix[1][2]-matrix[0][2]*matrix[1][0]);
    double a22 = (matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0]);
    adjunta_A = this->setMatrix(a00, a01, a02, a10, a11, a12, a20, a21, a22);

    return adjunta_A;
}

QVector<QVector<double>> MainWindow::getResultInverse(QVector<QVector<double>> matrix, double det)
{
    QVector<QVector<double>> inversa_A;
    double a00 = matrix[0][0]*det;
    double a01 = matrix[0][1]*det;
    double a02 = matrix[0][2]*det;
    double a10 = matrix[1][0]*det;
    double a11 = matrix[1][1]*det;
    double a12 = matrix[1][2]*det;
    double a20 = matrix[2][0]*det;
    double a21 = matrix[2][1]*det;
    double a22 = matrix[2][2]*det;
    inversa_A = this->setMatrix(a00, a01, a02, a10, a11, a12, a20, a21, a22);

    return inversa_A;
}

QDomDocument MainWindow::generateGbxml (Gbxml& gbxml_obj)
{
    QString def_volumeUnit      = QString::fromLocal8Bit(gbxml_obj.volumeUnit.c_str()); 
    QString def_version         = QString::fromLocal8Bit(gbxml_obj.version.c_str());  
    QString def_areaUnit        = QString::fromLocal8Bit(gbxml_obj.areaUnit.c_str());  
    QString def_temperaturaUnit = QString::fromLocal8Bit(gbxml_obj.temperatureUnit.c_str());   
    QString def_lengthUnit      = QString::fromLocal8Bit(gbxml_obj.lengthUnit.c_str()); 
    QString def_campus_id       = QString::fromLocal8Bit(gbxml_obj.campus_id.c_str());   
    QString def_name_loc        = QString::fromLocal8Bit(gbxml_obj.location.name.c_str());
    double  def_latitud_loc     = gbxml_obj.location.latitude;  
    double  def_longitud_loc    = gbxml_obj.location.longitude; 
    QString def_latitud_loc_txt     = QString::number(def_latitud_loc);     
    QString def_longitud_loc_txt    = QString::number(def_longitud_loc);

    Building building_obj = gbxml_obj.building;
    QString def_building_id    = QString::fromLocal8Bit(building_obj.building_id.c_str());
    QString def_building_type  = QString::fromLocal8Bit(building_obj.building_type.c_str());
    double  def_area           = building_obj.area;
    QString def_area_txt       = QString::number(def_area);
    QString surf_space_data;
    int levels = building_obj.buildingstoreis.size();
    int ref_cartesian_point = 1;
    QDomDocument document;
    QDomElement root = document.createElement("gbXML");
    root.setAttribute("xmlns:xsi"               , "http://www.w3.org/2001/XMLSchema-instance");
    root.setAttribute("xmlns:xhtml"             , "http://www.w3.org/1999/xhtml");
    root.setAttribute("volumeUnit"              , def_volumeUnit);
    root.setAttribute("version"                 , def_version);
    root.setAttribute("areaUnit"                , def_areaUnit);
    root.setAttribute("xmlns"                   , "http://www.gbxml.org/schema");
    root.setAttribute("temperatureUnit"         , def_temperaturaUnit);
    root.setAttribute("xsi:schemaLocation"      , "http://www.gbxml.org/schema http://www.gbxml.org/schema/0-37/GreenBuildingXML.xsd");
    root.setAttribute("useSIUnitsForResults"    , "true");
    root.setAttribute("xmlns:xsd"               , "http://www.w3.org/2001/XMLSchema");
    root.setAttribute("lengthUnit"              , def_lengthUnit);
    document.appendChild(root);
    QDomElement campus = document.createElement("Campus");
    campus.setAttribute("id", def_campus_id);
    root.appendChild(campus);
    QDomElement location_init = document.createElement("Location");
    campus.appendChild(location_init);
    QDomElement name_loc    = document.createElement("Name");
    QDomText name_loc_text  = document.createTextNode(def_name_loc);
    name_loc.appendChild(name_loc_text);
    location_init.appendChild(name_loc);
    QDomElement lat_loc = document.createElement("Latitude");
    QDomText lat_loc_text  = document.createTextNode(def_latitud_loc_txt);
    lat_loc.appendChild(lat_loc_text);
    location_init.appendChild(lat_loc);
    QDomElement long_loc = document.createElement("Longitude");
    QDomText long_loc_text  = document.createTextNode(def_longitud_loc_txt);
    long_loc.appendChild(long_loc_text);
    location_init.appendChild(long_loc);
    QDomElement building = document.createElement("Building");
    building.setAttribute("id"            , def_building_id);
    building.setAttribute("buildingType"  , def_building_type);
    campus.appendChild(building);
    QDomElement area = document.createElement("Area");
    QDomText area_text  = document.createTextNode(def_area_txt);
    area.appendChild(area_text);
    building.appendChild(area);

    if(levels > 0)
    {
        for(int h = 0; h < levels; h++)
        {
            QDomElement buildingStorey = document.createElement("BuildingStorey");
            buildingStorey.setAttribute("id", QString::fromLocal8Bit(building_obj.buildingstoreis[h].building_storey_id.c_str()));
            building.appendChild(buildingStorey);
            QDomElement name_buildingStorey     = document.createElement("Name");
            QDomText name_buildingStorey_txt    = document.createTextNode(QString::fromLocal8Bit(building_obj.buildingstoreis[h].name.c_str()));
            name_buildingStorey.appendChild(name_buildingStorey_txt);
            buildingStorey.appendChild(name_buildingStorey);
            QDomElement level_buildingStorey    = document.createElement("Level");
            QDomText level_buildingStorey_txt   = document.createTextNode(QString::number(building_obj.buildingstoreis[h].level));
            level_buildingStorey.appendChild(level_buildingStorey_txt);
            buildingStorey.appendChild(level_buildingStorey);
            QDomElement planarGeometry = document.createElement("PlanarGeometry");
            buildingStorey.appendChild(planarGeometry);
            QDomElement polyLoop = document.createElement("PolyLoop");
            planarGeometry.appendChild(polyLoop);
            int   numCartesianPoints = building_obj.buildingstoreis[h].points.size();
            if(numCartesianPoints > 0)
            {
                for(int cp = 0; cp < numCartesianPoints; cp++)
                {
                    QDomElement cartesianPoint = document.createElement("CartesianPoint");
                    polyLoop.appendChild(cartesianPoint);
                    QDomElement coordinate_x = document.createElement("Coordinate");
                    QDomText point_x  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].points[cp].x));
                    coordinate_x.appendChild(point_x);
                    QDomElement coordinate_y = document.createElement("Coordinate");
                    QDomText point_y  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].points[cp].y));
                    coordinate_y.appendChild(point_y);
                    QDomElement coordinate_z = document.createElement("Coordinate");
                    QDomText point_z  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].points[cp].z));
                    coordinate_z.appendChild(point_z);
                    cartesianPoint.appendChild(coordinate_x);
                    cartesianPoint.appendChild(coordinate_y);
                    cartesianPoint.appendChild(coordinate_z);
                }
            }

            int spaces = building_obj.buildingstoreis[h].spaces.size();
            if(spaces > 0)
            {
                for(int s = 0; s < spaces; s++)
                {
                    QDomElement space = document.createElement("Space");
                    space.setAttribute("id"                 , QString::fromLocal8Bit(building_obj.buildingstoreis[h].spaces[s].space_id.c_str()));
                    space.setAttribute("buildingStoreyIdRef", QString::fromLocal8Bit(building_obj.buildingstoreis[h].building_storey_id.c_str()));
                    building.appendChild(space);
                    int surfaces = building_obj.buildingstoreis[h].spaces[s].surfaces.size();
                    if(surfaces > 0)
                    {
                        for(int sur = 0; sur < surfaces; sur++)
                        {
                            QDomElement surface = document.createElement("Surface");
                            surface.setAttribute("surfaceType"          , QString::fromLocal8Bit(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].surface_type.c_str()));
                            surface.setAttribute("constructionIdRef"    , QString::fromLocal8Bit(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].constructionIdRef.c_str()));
                            surface.setAttribute("id"                   , QString::fromLocal8Bit(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].surface_id.c_str()));
                            campus.appendChild(surface);
                            int n_spaces_surf = building_obj.buildingstoreis[h].spaces[s].surfaces[sur].spaces.size();
                            if (n_spaces_surf > 0)
                            {
                                for(int spaces_surf = 0; spaces_surf < n_spaces_surf; spaces_surf++)
                                {
                                    surf_space_data = QString::fromLocal8Bit(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].spaces[spaces_surf].c_str());
                                    QDomElement adjacentSpace = document.createElement("AdjacentSpaceId");
                                    adjacentSpace.setAttribute("spaceIdRef"  , surf_space_data);
                                    surface.appendChild(adjacentSpace);
                                }
                            }
                            QDomElement rectangularGeometry = document.createElement("RectangularGeometry");
                            surface.appendChild(rectangularGeometry);
                            QDomElement azimuth = document.createElement("Azimuth");
                            QDomText azimuth_text  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].azimuth));
                            azimuth.appendChild(azimuth_text);
                            rectangularGeometry.appendChild(azimuth);
                            int numCartesianPoints = building_obj.buildingstoreis[h].spaces[s].surfaces[sur].points.size();
                            if(numCartesianPoints > 0)
                            {
                                QDomElement cartesianPoint = document.createElement("CartesianPoint");
                                rectangularGeometry.appendChild(cartesianPoint);
                                QDomElement coordinate_x = document.createElement("Coordinate");
                                QDomElement coordinate_y = document.createElement("Coordinate");
                                QDomElement coordinate_z = document.createElement("Coordinate");
                                QDomText point_x  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].points[ref_cartesian_point].x));
                                coordinate_x.appendChild(point_x);
                                QDomText point_y  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].points[ref_cartesian_point].y));
                                coordinate_y.appendChild(point_y);
                                QDomText point_z  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].points[ref_cartesian_point].z));
                                coordinate_z.appendChild(point_z);
                                cartesianPoint.appendChild(coordinate_x);
                                cartesianPoint.appendChild(coordinate_y);
                                cartesianPoint.appendChild(coordinate_z);
                            }
                            QDomElement tilt = document.createElement("Tilt");
                            QDomText tilt_text  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].tilt));
                            tilt.appendChild(tilt_text);
                            rectangularGeometry.appendChild(tilt);
                            QDomElement width = document.createElement("Width");
                            QDomText width_text  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].width));
                            width.appendChild(width_text);
                            rectangularGeometry.appendChild(width);
                            QDomElement height = document.createElement("Height");
                            QDomText height_text  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].height));
                            height.appendChild(height_text);
                            rectangularGeometry.appendChild(height);
                            QDomElement planarGeometry = document.createElement("PlanarGeometry");
                            surface.appendChild(planarGeometry);
                            QDomElement polyLoop = document.createElement("PolyLoop");
                            planarGeometry.appendChild(polyLoop);
                            if(numCartesianPoints > 0)
                            {
                                for(int cps = 0; cps < numCartesianPoints; cps++)
                                {
                                    QDomElement cartesianPoint = document.createElement("CartesianPoint");
                                    polyLoop.appendChild(cartesianPoint);
                                    QDomElement coordinate_x = document.createElement("Coordinate");
                                    QDomElement coordinate_y = document.createElement("Coordinate");
                                    QDomElement coordinate_z = document.createElement("Coordinate");
                                    QDomText point_x  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].points[cps].x));
                                    coordinate_x.appendChild(point_x);
                                    QDomText point_y  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].points[cps].y));
                                    coordinate_y.appendChild(point_y);
                                    QDomText point_z  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].points[cps].z));
                                    coordinate_z.appendChild(point_z);
                                    cartesianPoint.appendChild(coordinate_x);
                                    cartesianPoint.appendChild(coordinate_y);
                                    cartesianPoint.appendChild(coordinate_z);
                                }
                            }
                            int numOpenings = building_obj.buildingstoreis[h].spaces[s].surfaces[sur].openings.size();
                            if(numOpenings > 0)
                            {
                                for(int ops = 0; ops < numOpenings; ops++)
                                {
                                    QDomElement opening = document.createElement("Opening");
                                    opening.setAttribute("id"            , QString::fromLocal8Bit(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].openings[ops].opening_id.c_str()));
                                    opening.setAttribute("openingType"   , QString::fromLocal8Bit(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].openings[ops].opening_type.c_str()));
                                    surface.appendChild(opening);
                                    QDomElement rectangularGeometryOpen = document.createElement("RectangularGeometry");
                                    opening.appendChild(rectangularGeometryOpen);
                                    QDomElement azimuthOpen = document.createElement("Azimuth");
                                    QDomText azimuthOpen_text  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].azimuth));
                                    azimuthOpen.appendChild(azimuthOpen_text);
                                    rectangularGeometryOpen.appendChild(azimuthOpen);
                                    int numCartesianPointsOpen = building_obj.buildingstoreis[h].spaces[s].surfaces[sur].openings[ops].points.size();
                                    if(numCartesianPointsOpen > 0)
                                    {
                                        QDomElement cartesianPoint = document.createElement("CartesianPoint");
                                        rectangularGeometryOpen.appendChild(cartesianPoint);
                                        QDomElement coordinate_x = document.createElement("Coordinate");
                                        QDomElement coordinate_y = document.createElement("Coordinate");
                                        QDomElement coordinate_z = document.createElement("Coordinate");
                                        QDomText point_x  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].openings[ops].points[ref_cartesian_point].x));
                                        coordinate_x.appendChild(point_x);
                                        QDomText point_y  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].openings[ops].points[ref_cartesian_point].y));
                                        coordinate_y.appendChild(point_y);
                                        QDomText point_z  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].openings[ops].points[ref_cartesian_point].z));
                                        coordinate_z.appendChild(point_z);
                                        cartesianPoint.appendChild(coordinate_x);
                                        cartesianPoint.appendChild(coordinate_y);
                                        cartesianPoint.appendChild(coordinate_z);
                                    }

                                    QDomElement tiltOpen = document.createElement("Tilt");
                                    QDomText tiltOpen_text  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].tilt));
                                    tiltOpen.appendChild(tiltOpen_text);
                                    rectangularGeometryOpen.appendChild(tiltOpen);
                                    QDomElement widthOpen = document.createElement("Width");
                                    QDomText widthOpen_text  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].openings[ops].width));
                                    widthOpen.appendChild(widthOpen_text);
                                    rectangularGeometryOpen.appendChild(widthOpen);
                                    QDomElement heightOpen = document.createElement("Height");
                                    QDomText heightOpen_text  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].openings[ops].height));
                                    heightOpen.appendChild(heightOpen_text);
                                    rectangularGeometryOpen.appendChild(heightOpen);
                                    QDomElement planarGeometryOpen = document.createElement("PlanarGeometry");
                                    opening.appendChild(planarGeometryOpen);
                                    QDomElement polyLoopOpen = document.createElement("PolyLoop");
                                    planarGeometryOpen.appendChild(polyLoopOpen);

                                    int numCartesianPointsOpenPla = numCartesianPointsOpen;
                                    if(numCartesianPointsOpenPla > 0)
                                    {
                                        for(int cpo = 0; cpo < numCartesianPointsOpenPla; cpo++)
                                        {
                                            QDomElement cartesianPoint = document.createElement("CartesianPoint");
                                            polyLoopOpen.appendChild(cartesianPoint);
                                            QDomElement coordinate_x = document.createElement("Coordinate");
                                            QDomElement coordinate_y = document.createElement("Coordinate");
                                            QDomElement coordinate_z = document.createElement("Coordinate");
                                            QDomText point_x  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].openings[ops].points[cpo].x));
                                            coordinate_x.appendChild(point_x);
                                            QDomText point_y  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].openings[ops].points[cpo].y));
                                            coordinate_y.appendChild(point_y);
                                            QDomText point_z  = document.createTextNode(QString::number(building_obj.buildingstoreis[h].spaces[s].surfaces[sur].openings[ops].points[cpo].z));
                                            coordinate_z.appendChild(point_z);
                                            cartesianPoint.appendChild(coordinate_x);
                                            cartesianPoint.appendChild(coordinate_y);
                                            cartesianPoint.appendChild(coordinate_z);
                                        } 
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return document;
}

void MainWindow::setFile(QString nameFile, QDomDocument contenido)
{
    QFile file("C:/dev/pj_gbxml/gbxmlParser/output/"+nameFile+".xml");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text ))
    {
        QTextStream stream(&file);
        stream << contenido.toString();
        file.close();
    }
}