
#include "ofMain.h"

class ofApp : public ofBaseApp{
    
// ---------- variables ----------------------------------------

ofxPanel gui;
bool bDrawGui = true;

pdsp::Engine engine;

//--------------------------------------------------------------
void setup(){
    ofBackground( 0 );





    // -------------- GUI ------------
    gui.setup( "gui", "settings.xml", 20, 20 );

    gui.loadFromFile( "settings.xml" );
    gui.minimizeAll();
    
    
    // ----------- ENGINE ------------- 
    engine.listDevices();
    engine.setDeviceID( 0 ); 
    //engine.setup( 44100, 512, 3); 
}

//--------------------------------------------------------------
void update(){

}

//--------------------------------------------------------------
void draw(){
    
    
    if( bDrawGui ) gui.draw();
}

//--------------------------------------------------------------
void exit(){

}

//--------------------------------------------------------------
void keyPressed(int key){
    switch( key ){    
        case 'g': bDrawGui = !bDrawGui; break;
        
        case '1':  
        
        break;
        
        case '2':  
        
        break;
    }
}

//--------------------------------------------------------------
void mousePressed(int x, int y, int button){}
void mouseDragged(int x, int y, int button){}
void mouseReleased(int x, int y, int button){}

//--------------------------------------------------------------
void keyReleased(int key){}
void mouseMoved(int x, int y){}
void mouseEntered(int x, int y){}
void mouseExited(int x, int y){}
void windowResized(int w, int h){}
void gotMessage(ofMessage msg){}
void dragEvent(ofDragInfo dragInfo){ }
//--------------------------------------------------------------

}; // class ofApp

int main(){
	ofSetupOpenGL( 800, 480, OF_WINDOW);
	ofRunApp( new ofApp() );
}
