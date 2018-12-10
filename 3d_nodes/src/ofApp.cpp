#include "ofApp.h"

// multiple primitive in halo configuration
// example for primitive rotation
// example for setting nodes as parents

//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofDisableAntiAliasing();
    ofSetVerticalSync(true);
    ofSetLineWidth(1.5f);

                        // 4 faces
    pyra.setResolution( 4, 1, 0);
    cube.setResolution(1);
    
    ofBackground(255);
    
    gui.setup("", "settings.xml", ofGetWidth()-210, 10);

    gui.add( pSide.set("pyra side", 25.0f, 5.0f, 100.0f) );
    gui.add( nPoints.set("pyra elements", 20, 8, 64) );
    gui.add( pRadius.set("pyras radius", 200.0f, 100.0f, 500.0f ) );
    gui.add( rotSpeed.set("pyra angle speed", 0.5f, 0.1f, 3.0f ) );
    gui.add( outerSpeed.set("pyra rotation speed", 0.5f, 0.1f, 3.0f ) );

    gui.add( cWidth.set("cube space", 25.0f, 5.0f, 100.0f) );
    gui.add( cSeparation.set("cube separation", 0.5f, 0.0f, 1.0f) );
    gui.add( nx.set("x cubes", 3, 1, 7) );
    gui.add( ny.set("y cubes", 3, 1, 7) );
    gui.add( nz.set("z cubes", 3, 1, 7) );
    gui.add( innerSpeed.set("cube speed", 0.5f, 0.1f, 3.0f ) );

    gui.add( distance.set("cam distance", 600.0f, 200.f, 1000.0f) );

    gui.loadFromFile("settings.xml");
    
    ofSetWindowTitle("inner/outer nodes");
    
    rotation = 0.0f;
    
    ofBackground(0);
    
    haloCenter.setPosition( 0, 0, 0 );
    pyra.setParent( haloCenter );  
    
    cubesCenter.setPosition( 0, 0, 0 );
    cube.setParent( cubesCenter );
}

//--------------------------------------------------------------
void ofApp::update(){
    rotation += rotSpeed;
    if(rotation>=360.0f) rotation -= 360.0f;
    
    // fixed camera from front
    camera.lookAt( ofPoint( 0, 0, 0 ) );    // camera pointing at the origin
    ofVec3f front ( 0, 0, distance );       // watching from the front
    camera.setPosition( front );
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(80, 0, 0);
    ofDrawLine( ofGetWidth()*0.5f, 0, ofGetWidth()*0.5f, ofGetHeight()); 
    ofDrawLine( 0, ofGetHeight()*0.5f, ofGetWidth(), ofGetHeight()*0.5f); 

    pyra.set( pSide*0.45f, pSide ); // width, height

    ofColor color (255, 0, 0 );
    
    ofNoFill();
    ofSetColor( color );  
    ofSetDepthTest(true);

    haloCenter.rotate( outerSpeed, ofVec3f( 0, 1, 0 ) );
    cubesCenter.rotate( innerSpeed, ofVec3f( 1, 1, 0 ) );

    camera.begin();    
        float theta = ofDegToRad(rotation);
        float tStep = TWO_PI/ (float) nPoints;
        
        for( int i=0; i<nPoints; ++i ){
            pyra.setPosition( cos(theta)*pRadius, sin(theta)*pRadius, 0 );
            pyra.lookAt( haloCenter, ofVec3f( 0, 1, 0 ) );
            pyra.tilt( - 90.0f);

            pyra.drawWireframe();
            theta += tStep;        
        } 

        float cSide = cWidth * (1.0f-cSeparation);
        
        cube.set( cSide ); //side        

        float xoffset = (cWidth*(nx-1))*0.5f;
        float yoffset = (cWidth*(ny-1))*0.5f;
        float zoffset = (cWidth*(nz-1))*0.5f;
        
        for( int x=0; x<nx; ++x ){
            for ( int y=0; y<ny; ++y ){
                for ( int z=0; z<nz; ++z ){
                    cube.setPosition( x*cWidth - xoffset, y*cWidth - yoffset, z*cWidth - zoffset );
                    ofSetColor(0);
                    cube.draw();

                    ofSetColor( color );  
                    cube.setScale(1.01f);
                    cube.drawWireframe();
                    cube.setScale(1.f);    
                }    
            }
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
