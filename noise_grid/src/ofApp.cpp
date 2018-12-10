#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofDisableAntiAliasing();
    ofDisableSmoothing();

    gui.setup("", "settings.xml", ofGetWidth()-220, 20 );
    gui.add( rows.set( "rows", 12, 4, 64 ) );
    gui.add( cols.set( "cols", 12, 4, 64 ) );
    gui.add( size.set( "size", 60, 8, 100 ) );
    gui.add( speed.set( "speed", 0.01f, 0.0f, 0.1f ) );
    gui.add( offset.set( "offset", 0.05f, 0.0001f, 0.5f) );
    gui.add( amount.set("amount", 1.0f, 0.0f, 1.0f) );
    gui.add( alpha.set("alpha amount", 0.0f, 0.0f, 1.0f) );
    gui.add( bFill.set("fill", false ) );
    gui.loadFromFile("settings.xml");
    
    cursor = 0.0f;
    
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

    cursor += speed;
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofClear(0, 0, 0, 255);

    gui.draw();
    
    ofSetColor(255);
    if (bFill) { ofFill(); } else { ofNoFill(); }
    ofTranslate( size*0.5f, size*0.5f );
    
    for ( int y=0; y<rows; ++y ){
        for ( int x=0; x<cols; ++x ) {
            
            float noise = ofNoise( x*offset, y*offset, cursor );
            if(alpha>0.0f){
                ofSetColor( ofColor::black.getLerped(ofColor::white, noise*alpha + 1.0f - alpha ) ); 
            }
            float s = size * amount * noise;
            ofDrawRectangle( x*size - s*0.5f, y*size - s*0.5f, s, s );
        }
    }
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){ }
//--------------------------------------------------------------
