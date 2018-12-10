#include "ofApp.h"

// example for:
//      fbo to texture
//      cone primitive

//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofDisableAntiAliasing();
    ofSetVerticalSync(true);
    ofSetLineWidth(1.5f);

    cube.setResolution(1);
                        // 4 faces
    pyra.setResolution( 4, 1, 0);
    ofBackground(255);
    
    gui.setup("", "settings.xml", ofGetWidth()-210, 10);
    gui.add( side.set("side", 300.0f, 100.0f, 1000.0f) );
    gui.add( distance.set("distance", 600.0f, 200.f, 1000.0f) );
    gui.add( rotSpeed.set("rotation speed", 1.5f, 0.1f, 3.0f ) );

    gui.loadFromFile("settings.xml");
    
    ofSetWindowTitle("fbo-->texture");
    
    rotation = 0.0f;
    mode = 0;

    ofDisableArbTex();    
    ofFbo::Settings settings;
    settings.width  = 512;
    settings.height = 512;
    settings.minFilter = GL_NEAREST;
    settings.maxFilter = GL_NEAREST;
    texture.allocate( settings );
    texture.getTexture().setTextureWrap( GL_REPEAT, GL_REPEAT );
}


    
//--------------------------------------------------------------
void ofApp::update(){
    rotation += rotSpeed;
    if(rotation>=360.0f) rotation -= 360.0f;

    switch(mode){
        case 0:
        if(ofGetFrameNum()%3==0){
            texture.begin();                
                
                ofClear( 255, 0, 0, 255 );
                ofSetColor( 0, 255 );
                ofFill();
                for( int i=0; i<25; ++i){
                    //ofDrawRectangle( ofRandom(texture.getWidth()), ofRandom(texture.getHeight()), 50, 25 );
                    //int y = ofRandom(ofGetHeight());
                    ofDrawRectangle( 0, ofRandom(texture.getHeight()), texture.getWidth(), ofRandom(5, 50) );
                    //ofDrawLine( 0, y, texture.getWidth(), y);
                }
            texture.end();    
        }
        break;
        
        case 1:
        if(ofGetFrameNum()%3==0){
            texture.begin();                
                
                ofClear( 255, 0, 0, 255 );
                ofSetColor( 0, 255 );
                ofFill();
                for( int i=0; i<25; ++i){
                    ofDrawRectangle( ofRandom(texture.getWidth()), 0, ofRandom(5, 50), texture.getHeight() );
                }
            texture.end();    
        }
        break;

        case 2:
        if(ofGetFrameNum()%120==0){
            texture.begin();                
                
                ofClear( 255, 255, 255, 255 );
                ofSetColor( 255, 0, 0, 255 );
                ofFill();
                for( int i=0; i<25; ++i){
                    ofDrawRectangle( ofRandom(texture.getWidth()), ofRandom(texture.getHeight()), 50, 50 );
                }
            texture.end();    
        }
        break;
                
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofNoFill();
    ofSetDepthTest(true);

    ofSetColor(255);
    texture.draw( 20, 20, 128, 128 );
    ofSetColor(0);
    ofDrawBitmapString("fbo", 70, 14 );
    ofDrawRectangle(20, 20, 128, 128);
    
    camera.lookAt( ofPoint( 0, 0, 0 ) );    // camera pointing at the origin
    ofVec3f front ( 0, 0, distance );       // watching from the front
    ofVec3f rotated = front.getRotated( rotation, ofVec3f( 0, 1, 0 ) ); // rotate from 0 to 360 degree on the x,y axes
    camera.setPosition( rotated );
    
    pyra.setPosition( 0.0f, -50.0f, 0.0f);
    pyra.set( side*0.45f, side ); // width, height

    ofTranslate(200, 0);
    camera.begin();    
    texture.getTexture().bind();
        ofSetColor( 255, 255 );     
        pyra.draw();
           
        if(mode==2){
            ofSetColor( 0 );  
            pyra.setScale(1.002f);
            pyra.drawWireframe();
            pyra.setScale(1.f);  
        }
    texture.getTexture().unbind();     
    camera.end();

    ofTranslate(-200,0);
    ofSetDepthTest(false); // gui won't work good with depth test
    gui.draw();
    ofSetColor(0);
    ofDrawBitmapString( "keys: 1-6=change poly resolution, q-w-e=change mode", 20, ofGetHeight()-18 );
}

//--------------------------------------------------------------
void ofApp::exit(){}
void ofApp::keyPressed(int key){
    switch(key){
        case '1':
            pyra.setResolution( 4, 1, 0);
        break;
        
        case '2':
            pyra.setResolution( 4, 4, 0);        
        break;
        
        case '3':
            pyra.setResolution( 4, 8, 0);
        break;
        
        case '4':
            pyra.setResolution( 4, 16, 0);
        break;
        
        case '5':
            pyra.setResolution( 4, 32, 0);
        break;
        
        case '6':
            pyra.setResolution( 4, 64, 0);
        break;
        
        case 'q': mode=0; break;
        case 'w': mode=1; break;
        case 'e': mode=2; break;
        
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
