//****************************************************************************
//      Class to define space for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es) || (ivanoterouvigo@gmail.com)
//      19/01/2017
//****************************************************************************
#ifndef OPENING_H
#define OPENING_H
#include "cartesianpoint.h"
#include <vector>

class Opening
{

public:


    std::string opening_id;
    std::string opening_type;

    double azimuth;
    double tilt;
    double width;
    double height;

    std::vector<CartesianPoint> points;

};


#endif // OPENING_H
