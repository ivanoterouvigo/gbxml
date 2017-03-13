//****************************************************************************
//      Class to define space for gbXML
//      Applied Geotechnologies Uvigo
//      Iván Otero (iotero@uvigo.es)
//      22/02/2017
//****************************************************************************
#ifndef STORESPACES_H
#define STORESPACES_H
#include "storeplanes.h"
#include <vector>

class Storespaces
{

public:

    std::string BuildingStoreyName;

    std::vector<Storeplanes> spaces;

};
#endif // STORESPACES_H
