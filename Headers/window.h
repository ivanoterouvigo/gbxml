//****************************************************************************
//      Class to define space for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es)
//      19/01/2017
//****************************************************************************
#ifndef WINDOW_H
#define WINDOW_H
#include "cartesianpoint.h"
#include <vector>


class Window
{

public:

    std::string opening_id;
    std::string opening_type;

    double azimuth;
    double tilt;
    double width;
    double height;


};
#endif // WINDOW_H
