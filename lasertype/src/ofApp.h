#pragma once

#include "ofMain.h"
#include "ofxLaserManager.h"
#include "ofxLaserDacEtherdream.h"
#include "ofxGui.h"
#include "np-extra.h"
#include "Operations.h"

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
	bool drawingShape = false;
	int laserWidth;
	int laserHeight;
    
	std::vector<ofPolyline> lines;
	std::vector<ofPolyline> morphed;
		
    ofxPanel cgui;
    ofParameter<ofColor> color;
    
    ofTrueTypeFont font;
    glm::vec2 position;
    std::string typeStr;
    bool bFirst;
    std::string permutated;

    Operations operations;
};
