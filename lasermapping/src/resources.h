
#pragma once 

#include "ofMain.h"
#include "ofxLaserManager.h"
#include "ofxLaserDacEtherdream.h"
#include "Laserline.h"

// ------- shared resources between ofApp and scenes ----------------
// shared resources are defined in ofApp.cpp, in the global scope
// and declared here as externs

extern std::vector<Laserline> lines;
extern std::vector<ofPolyline> mapping;

extern ofxLaser::Manager laser;

namespace resources{
    extern int laserWidth;
    extern int laserHeight;
}
