//****************************************************************************
//      Class to define space for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es)
//      19/01/2017
//****************************************************************************
#ifndef SPACEB_H
#define SPACEB_H
#include "surface.h"
#include <vector>



class Spaceb
{

public:

    std::string space_id;
    std::string buildingStoreyIdRef;
    std::vector<Surface> surfaces;


};
#endif // SPACEB_H
