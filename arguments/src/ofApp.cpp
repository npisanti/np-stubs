#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    std::cout<<uno<<"\n";
    std::cout<<due<<"\n";
    std::cout<<tre<<"\n";
    std::cout<<"--- press Ctrl+C to quit\n";

    ofSetFrameRate( 60 ); // without this loop is executed as soon as possible 
}

//--------------------------------------------------------------
void ofApp::update(){
    if ( ofGetFrameNum()%120 == 0 ){
        std::cout<<"loop\n";
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

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
