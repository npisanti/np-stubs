#include "ofApp.h"

// noise cube
// example for:
//      box primitive
//      basic camera
//      3d perlin noise

//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofDisableAntiAliasing();
    ofSetVerticalSync(true);

    cube.setResolution(1);
    ofBackground(255);
    
    cursor = ofRandom( 100.0f );
    
    gui.setup("", "settings.xml", ofGetWidth()-210, 10);
    gui.add( totalSide.set("side", 300.0f, 100.0f, 1000.0f) );
    gui.add( num.set("squares L", 6, 4, 12 ) );
    gui.add( spacing.set("spacing", 1.5f, 1.0f, 4.0f ) );
    gui.add( distance.set("distance", 600.0f, 200.f, 1000.0f) );
    gui.add( speed.set( "speed", 0.01f, 0.0f, 0.05f ) );
    gui.add( offset.set( "offset", 0.05f, 0.00001f, 0.5f) );
    gui.add( amount.set("amount", 1.0f, 0.0f, 1.0f) );
    gui.loadFromFile("settings.xml");
    
    ofSetWindowTitle("noisecube");
}

//--------------------------------------------------------------
void ofApp::update(){
    cursor += speed;
}

//--------------------------------------------------------------
void ofApp::draw(){

    float side = totalSide / (num*spacing);
    
    ofNoFill();
    ofSetDepthTest(true);

    
    glm::vec3 front ( 0, 0, distance );       // watching from the front
    float rotation = ofGetElapsedTimef() * 360.0f * 0.03f;
    glm::vec3 rotated = front.getRotated( rotation, ofVec3f( 0, 1, 0 ) ); 
    // rotate from 0 to 360 degree on the x,y axes
    camera.setPosition( rotated );
    
    camera.lookAt( glm::vec3( 0, 0, 0 ) );    // camera pointing at the origin

    camera.begin();
    for( int z=0; z<num; ++z){
        for( int y=0; y<num; ++y){
            for( int x=0; x<num; ++x){             
                
                float noiseMult = (1.0f - amount) + ofNoise( x*offset, y*offset, z*offset, cursor )*amount;
                cube.set( side * noiseMult );
                
                cube.setPosition( 
                        (0.5f+x-num*0.5f)*side*spacing, 
                        (0.5f+y-num*0.5f)*side*spacing, 
                        (0.5f+z-num*0.5f)*side*spacing
                );
                
                //cube.set( 0.0f, 0.0f, 0.0f );

                ofSetColor(0);     
                cube.draw();
                    
                ofSetColor(255);  
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
void ofApp::keyPressed(int key){}
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
