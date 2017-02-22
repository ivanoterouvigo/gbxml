//****************************************************************************
//      Class to define window for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es) || (ivanoterouvigo@gmail.com)
//      25/01/2017
//****************************************************************************
#ifndef BUILDINGSTOREY_H
#define BUILDINGSTOREY_H
#include "cartesianpoint.h"
#include "spaceb.h"
#include <vector>

class BuildingStorey
{

    public:

    std::string name;
    std::string building_storey_id;

    int level;

    std::vector<CartesianPoint> points;
    std::vector<Spaceb> spaces;


};


#endif // BUILDINGSTOREY_H
