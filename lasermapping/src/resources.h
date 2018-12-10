
#pragma once 

#include "ofMain.h"
#include "Laserline.h"

// ------- shared resources between ofApp and scenes ----------------
// shared resources are defined in ofApp.cpp, in the global scope
// and declared here as externs

extern std::vector<Laserline> lines;
extern std::vector<ofPolyline> mapping;

namespace resources{

}
