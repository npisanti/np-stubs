
#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "np-extra.h"

#include "lua/Lua.h"

#define OVERSAMPLING 0

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    
        void exit();
		
		void keyPressed(int key);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

        void xyControl( float x, float y, int button );
                
        np::miscela::Combination combo;
        std::vector<std::string> paths;

        float mod;
        glm::vec3 position;
        bool bResize;
        int resizeCounter;

        bool		bDrawGui;
        ofxPanel 	gui;

        ofParameter<float> speed;
        std::vector<ofParameter<float>> controls;

        np::PaletteTable palette;
        ofParameter<bool> invertPalette;

        bool bShowFrameRate;
            
        bool                bSave;
        ofParameter<int>    saveFrames;
        ofParameter<int>    saveCountDown;
        int                 saveCounter;
};
