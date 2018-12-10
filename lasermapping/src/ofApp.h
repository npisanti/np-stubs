#pragma once

#include "ofMain.h"
#include "ofxLaserManager.h"
#include "ofxLaserDacEtherdream.h"
#include "ofxGui.h"
#include "Laserline.h"
#include "np-extra.h"
#include "modes/LaserMapping.h"

#include "scenes/Test.hpp"

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed  (int key);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	
	ofxLaser::Manager laser;
    ofxLaser::DacEtherdream dac;
    
	int laserWidth;
	int laserHeight;
    
    np::SceneManager manager;
    
    np::modes::LaserMapping mappingMode;
    
    TestScene test;
};
