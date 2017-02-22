//****************************************************************************
//      Class to define window for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es) || (ivanoterouvigo@gmail.com)
//      25/01/2017
//****************************************************************************

#ifndef GBXML_H
#define GBXML_H

#include <string>
#include "location.h"
#include "building.h"

class Gbxml
{

public:


    std::string volumeUnit;
    std::string version;
    std::string areaUnit;
    std::string temperatureUnit;
    std::string lengthUnit;


    std::string campus_id;
    Location location;
    Building building;


};

#endif // GBXML_H
