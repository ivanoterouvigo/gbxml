//****************************************************************************
//      Class to define space for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es) || (ivanoterouvigo@gmail.com)
//      19/01/2017
//****************************************************************************
#ifndef SURFACE_H
#define SURFACE_H
#include "cartesianpoint.h"
#include "opening.h"
#include "window.h"
#include "door.h"
#include <vector>


class Surface
{

public:


    std::string surface_id;
    std::string surface_type;
    std::string constructionIdRef;
    // std::string space_id_ref;
    // TODO IVAN: set a list of spaceID

    double azimuth;
    double tilt;
    double width;
    double height;

    std::vector<std::string> spaces;
    std::vector<CartesianPoint> points;
    std::vector<Door> doors;
    std::vector<Window> windows;
    std::vector<Opening> openings;


};
#endif // SURFACE_H
