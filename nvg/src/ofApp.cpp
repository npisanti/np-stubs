#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);

    nvg.allocate( ofGetWidth(), ofGetHeight() );
}

//--------------------------------------------------------------
void ofApp::update(){
    nvg.begin();
        nvg.fillColor(255);
		nvg.strokeColor(255);
        
        nvg.beginPath();
		{
            nvg.rect( 50, 50, 400, 80 );
			nvg.lineWidth(5 + sin(fmodf(ofGetElapsedTimef() * 0.5, PI)) * 8);
		}
		nvg.strokePath();
        
    nvg.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    nvg.draw( 0, 0 );
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
