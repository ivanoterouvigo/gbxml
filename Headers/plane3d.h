//****************************************************************************
//      Class to define space for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es)
//      16/02/2017
//****************************************************************************
#ifndef PLANE3D_H
#define PLANE3D_H
#include "cartesianpoint.h"
#include "vecplane3d.h"
#include <vector>

class Plane3d
{

public:

    std::string name;
    std::string type_plane_id;
    int uuid;

    double azimuth;
    double tilt;
    double width;
    double height;

    std::vector<CartesianPoint> normals;
    std::vector<CartesianPoint> centroids;
};
#endif // PLANE3D_H
