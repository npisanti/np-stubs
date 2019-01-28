#include "ofApp.h"

ofFbo fbo;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);

    fbo.allocate( ofGetWidth(), ofGetHeight(), GL_RGBA, 0 );

    nvg.allocate( ofGetWidth(), ofGetHeight() );
    clear = true;
    ofSetCircleResolution( 120 );
}

//--------------------------------------------------------------
void ofApp::update(){
    nvg.begin();
        nvg.fillColor( 255 );
		nvg.strokeColor(120);
        nvg.lineWidth( 25 );
        
        nvg.beginPath();
		{
            //nvg.rect( ofGetMouseX(), ofGetMouseY(), 50, 50 );
            //nvg.rect( ofGetMouseX()+100, ofGetMouseY(), 50, 50 );
			nvg.circle( ofGetMouseX(), ofGetMouseY(), 250 );
		}
		nvg.strokePath();
        
    nvg.end();

    
    if( clear ){ clear = false; }
    
    if( ofRandomuf()< 0.01 ){ clear = true; }
    
    fbo.begin();
        ofClear(0, 0, 0, 0);
        nvg.draw( 0, 0 );

        ofSetColor( 255 );
        ofFill();
        ofDrawCircle( ofGetMouseX(), ofGetMouseY(), 150 );
    fbo.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.draw( 0, 0 );
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == ' ' ){ clear = true; }
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
