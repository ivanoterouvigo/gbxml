//****************************************************************************
//      Class to define space for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es)
//      16/02/2017
//****************************************************************************
#ifndef STORE_PLANES_H
#define STORE_PLANES_H
#include "plane3d.h"
#include <vector>

class Storeplanes
{

public:

    std::string id;
    std::string buildingStoreyIdRef;

    std::vector<Plane3d> planes;

};
#endif // STORE_PLANES_H
