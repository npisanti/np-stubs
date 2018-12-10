#pragma once

#include "ofMain.h"

#include "ofxGui.h"
#include "Laserline.h"
#include "np-extra.h"
#include "scenes/Mapping.h"
#include "scenes/Graphics.h"

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
	

    ofxLaser::DacEtherdream dac;
    
    np::SceneManager manager;
    
    scenes::LaserMapping mappingScene;
    
    scenes::Graphics graphics;
};
