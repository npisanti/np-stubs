#include "ofApp.h"

//------------------ shared resources --------------------------
std::vector<Laserline> lines;

std::vector<ofPolyline> mapping;

ofxLaser::Manager laser;

namespace resources{
    int laserWidth = 700;
    int laserHeight = 700;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle( "laser mapping" );
	
    string dacIP = "10.0.1.3";
    
	laser.setup( resources::laserWidth, resources::laserHeight );
    laser.addProjector(dac);
    dac.setup(dacIP);
    laser.initGui();

    // ---------- scenes -------------
    mappingScene.load();
    
    graphics.setup();
    
    manager.setup( 0, 0, false );
    manager.add( &mappingScene );
    manager.add( &graphics ); 
    manager.add( nullptr ); // nullptr for empty slot
}

//--------------------------------------------------------------
void ofApp::update(){

    // prepares laser manager to receive new points
    laser.update();
	
    manager.update();
    // sends points to the DAC
    laser.send();
}


void ofApp::draw() {
	ofBackground(0);
    
    manager.drawInterface();
    
    ofDrawBitmapString( ofToString(ofGetFrameRate()) + " fps", ofGetWidth()-100, ofGetHeight() - 10 );
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch( key ){
        case OF_KEY_RETURN: manager.next(); break;
        case OF_KEY_BACKSPACE: manager.prev(); break;
        case OF_KEY_TAB: laser.nextProjector(); break;
        case '1': manager.set( 0 ); break;
        case '2': manager.set( 1 ); break;
        case '3': manager.set( 2 ); break;
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
