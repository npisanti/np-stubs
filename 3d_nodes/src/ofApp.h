#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
        void exit();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        
        ofxPanel            gui;
        ofParameter<int>    nPoints;
        ofParameter<float>  distance;
        ofParameter<float>  pSide;
        ofParameter<float>  pRadius;
        ofParameter<float>  cSeparation;
        ofParameter<float>  cWidth;
        ofParameter<int>    nx;
        ofParameter<int>    ny;
        ofParameter<int>    nz;
        
        ofParameter<float>  innerSpeed;
        ofParameter<float>  outerSpeed;
        ofParameter<float>  rotSpeed;
        
        float rotation;
        float camRotation;

        ofCamera camera;
        ofBoxPrimitive cube;    
        ofConePrimitive pyra;    
        ofNode haloCenter;
        
        ofNode cubesCenter;
};
