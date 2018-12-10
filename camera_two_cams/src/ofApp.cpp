#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofDisableAntiAliasing();
    ofSetVerticalSync(true);
    ofSetLineWidth(1.5f);

                        // 8 faces
    pyra.setResolution( 4, 1, 0);
    ofBackground(255);
    
    gui.setup("", "settings.xml", ofGetWidth()-210, 600);
    gui.add( side.set("side", 300.0f, 100.0f, 1000.0f) );
    gui.add( distance.set("distance", 600.0f, 200.f, 1000.0f) );
    gui.add( rotSpeed.set("rotation speed", 1.5f, 0.1f, 3.0f ) );

    gui.loadFromFile("settings.xml");
    
    ofSetWindowTitle("two cameras / two fbos");
    
    rotation0 = 0.0f;
    rotation1 = 0.0f;

    fbo0.allocate(400, 400);
    fbo1.allocate(400, 400);
}


    
//--------------------------------------------------------------
void ofApp::update() {
    
    rotation0 += rotSpeed*0.8f;
    if(rotation0>=360.0f) rotation0 -= 360.0f;
    rotation1 += rotSpeed*1.5f;
    if(rotation1>=360.0f) rotation1 -= 360.0f;

    ofNoFill();
    ofSetDepthTest(true);
    
    camera0.lookAt( ofPoint( 0, 0, 0 ) );    // camera pointing at the origin
    ofVec3f front0 ( 0, 0, distance );       // watching from the front
    ofVec3f rotated0 = front0.getRotated( rotation0, ofVec3f( 0, 1, 0 ) ); // rotate from 0 to 360 degree on the x,y axes
    camera0.setPosition( rotated0 );
    
    pyra.setPosition( 0.0f, -50.0f, 0.0f);
    pyra.set( side*0.45f, side ); // width, height

    fbo0.begin();
    ofClear( 0, 0, 0, 0 );
    camera0.begin();    

        ofSetColor( 255, 255 );     
        pyra.draw();
           
        ofSetColor( 0 );  
        pyra.setScale(1.002f);
        pyra.drawWireframe();
        pyra.setScale(1.f);  

    camera0.end();
    fbo0.end();
    
    camera1.lookAt( ofPoint( 0, 0, 0 ) );    // camera pointing at the origin
    ofVec3f front1 ( 0, 0, distance );       // watching from the front       // watching from the front
    ofVec3f rotated1 = front1.getRotated( rotation1, ofVec3f( 0, 1, 0 ) ); // rotate from 0 to 360 degree on the x,y axes
    camera1.setPosition( rotated1 );    

    fbo1.begin();
    ofClear( 0, 0, 0, 0 );
    camera1.begin();    

        ofSetColor( 255, 255 );     
        pyra.draw();
           
        ofSetColor( 0 );  
        pyra.setScale(1.002f);
        pyra.drawWireframe();
        pyra.setScale(1.f);  

    camera1.end();
    fbo1.end();
    
    ofSetDepthTest(false); // gui won't work good with depth test

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    fbo0.draw( 20, 20 );
    ofSetColor( 0 );
    ofDrawRectangle(21, 21, fbo0.getWidth()-2, fbo0.getHeight()-2 ); 
    
    ofSetColor(255);
    fbo1.draw( 520, 20 );
    ofSetColor( 0 );
    ofDrawRectangle(521, 21, fbo0.getWidth()-2, fbo0.getHeight()-2 ); 

    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::exit(){}
void ofApp::keyPressed(int key){
    switch(key){
        
    }
}
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
