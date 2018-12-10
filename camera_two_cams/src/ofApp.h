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
        ofParameter<float>  distance;
        ofParameter<float>  side;
        ofParameter<float>  rotSpeed;

        ofConePrimitive pyra;
        
        float rotation0;
        float rotation1;

        ofCamera camera0;
        ofCamera camera1;    

        ofFbo fbo0;
        ofFbo fbo1;

};
