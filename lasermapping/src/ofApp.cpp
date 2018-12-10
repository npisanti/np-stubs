#include "ofApp.h"

//------------------ shared resources --------------------------
std::vector<Laserline> lines;

std::vector<ofPolyline> mapping;


//--------------------------------------------------------------
void ofApp::setup(){
	
	laserWidth = 800;
	laserHeight = 800;
    string dacIP = "10.0.1.3";
    
	laser.setup( laserWidth, laserHeight );
    laser.addProjector(dac);
    dac.setup(dacIP);
    laser.initGui();

    // ---------- scenes -------------
    test.setup();
    
    manager.setup( 0, 0, false );
    manager.add( nullptr ); // nullptr for empty slot
    manager.add( &test ); // nullptr for empty slot
        
}

//--------------------------------------------------------------
void ofApp::update(){

    // prepares laser manager to receive new points
    laser.update();
	
    // sends points to the DAC
    laser.send();
}


void ofApp::draw() {
	ofBackground(0);
    
    manager.drawInterface();
    
	ofNoFill();
	ofSetLineWidth(1);
	ofDrawRectangle(0,0,laserWidth, laserHeight);
	
	int ypos = laserHeight+20;
    ofDrawBitmapString("TAB to change view, F to toggle full screen", 400, ypos+=30);
    ofDrawBitmapString( ofToString(ofGetFrameRate()) + " fps", 400, ypos+=30);

    laser.drawUI();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch( key ){
        case OF_KEY_RETURN: manager.next(); break;
        case OF_KEY_BACKSPACE: manager.prev(); break;
        case OF_KEY_TAB: laser.nextProjector(); break;
    }
}

//--------------------------------------------------------------

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::exit(){
    //laser.saveSettings();
    dac.close();
}
