//****************************************************************************
//      Class to define window for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es)
//      25/01/2017
//****************************************************************************
#ifndef BUILDING_H
#define BUILDING_H
#include "buildingstorey.h"
#include <vector>


class Building
{

public:

    std::string building_id;
    std::string building_type;

    double area;
    std::vector<BuildingStorey> buildingstoreis;



};

#endif // BUILDING_H
