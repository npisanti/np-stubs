#include "ofApp.h"

// multiple primitive in halo configuration
// example for primitive rotation

//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofDisableAntiAliasing();
    ofSetVerticalSync(true);
    ofSetLineWidth(1.5f);

                        // 4 faces
    pyra.setResolution( 4, 1, 0);
    ofBackground(255);
    
    gui.setup("", "settings.xml", ofGetWidth()-210, 10);
    gui.add( side.set("side", 25.0f, 5.0f, 100.0f) );
    gui.add( nPoints.set("elements", 20, 8, 64) );
    gui.add( distance.set("distance", 600.0f, 200.f, 1000.0f) );
    gui.add( rotSpeed.set("rotation speed", 0.5f, 0.1f, 3.0f ) );
    gui.add( rotSpeedCamera.set("rotation speed camera", 0.5f, 0.1f, 3.0f ) );

    gui.loadFromFile("settings.xml");
    
    ofSetWindowTitle("circular");
    
    rotation = 0.0f;
    
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    rotation += rotSpeed;
    if(rotation>=360.0f) rotation -= 360.0f;
    camRotation += rotSpeedCamera;
    if(camRotation>=360.0f) camRotation -= 360.0f;
}

//--------------------------------------------------------------
void ofApp::draw(){
    

    cube.set( side ); //side
    pyra.set( side*0.45f, side ); // width, height
    
    
    ofNoFill();
    ofSetDepthTest(true);

    camera.lookAt( ofPoint( 0, 0, 0 ) );    // camera pointing at the origin
    ofVec3f front ( 0, 0, distance );       // watching from the front
    ofVec3f rotated = front.getRotated( camRotation, ofVec3f( 0, 1, 0 ) ); // rotate from 0 to 360 degree on the x,y axes
    camera.setPosition( rotated );
    
    nCenter.setPosition( 0, 0, 0 );

    camera.begin();    
        float radius = 200.0f;
        
        float theta = ofDegToRad(rotation);
        float tStep = TWO_PI/ (float) nPoints;

        ofSetColor( 255, 0, 0  );  
        
        for( int i=0; i<nPoints; ++i ){
            pyra.setPosition( cos(theta)*radius, sin(theta)*radius, 0 );
            pyra.lookAt( nCenter, ofVec3f( 0, 1, 0 ) );
            pyra.tilt( - 90.0f);
        
            //pyra.draw();
               
            pyra.setScale(1.002f);
            pyra.drawWireframe();
            cube.setScale(1.f);      
            
            theta += tStep;        
        } 

    camera.end();

    ofSetDepthTest(false); // gui won't work good with depth test

    gui.draw();

}

//--------------------------------------------------------------
void ofApp::exit(){}
void ofApp::keyPressed(int key){
    switch(key){
        case '1':
            pyra.setResolution( 4, 1, 0);
        break;
        
        case '2':
            pyra.setResolution( 6, 1, 0);    
        break;
        
        case '3':
            pyra.setResolution( 8, 1, 0);
        break;
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
