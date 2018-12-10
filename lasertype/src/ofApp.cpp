#include "ofApp.h"

float simplify = 0.6f;

//--------------------------------------------------------------
void ofApp::setup(){
	
    std::string fontpath = "/usr/share/fonts/truetype/Archivo-Regular.ttf";
    int fontsize = 120;

    
    // type variables 
    ofTrueTypeFont::setGlobalDpi( 72 );
	font.load( fontpath, fontsize, true, false, true );
    position = glm::vec2( 50, 250 );
    typeStr = "lasertype";
    bFirst = true; 
    
    // --------- laser -----------
	laserWidth = 800;
	laserHeight = 800;
	laser.setup(laserWidth, laserHeight);
    laser.addProjector(dac);
    string dacIP = "10.0.1.3";
    dac.setup(dacIP);
    laser.initGui();
	 
    cgui.setup("color panel", "colors.xml", ofGetWidth()-240, 700 );
    cgui.add(color.set("color", ofColor(0, 255, 0), ofColor(0), ofColor(255)));

}

//--------------------------------------------------------------
void ofApp::update(){
    
    operations.typeops( typeStr, permutated );
    
    laser.update(); // prepares laser manager to receive new points
    
    lines.clear();
    
    std::vector<ofPath> textContour = font.getStringAsPoints( permutated, true, false );
    for( auto & path : textContour ){
        path.translate( position );
        for( auto & line : path.getOutline() ){
            lines.push_back( line );
            // close the outline 
            lines.back().addVertex( lines.back().getVertices()[0] ); 
        }
    }

    operations.polyops( lines, morphed );
    
	// LASER lines
	for(size_t i = 0; i<morphed.size(); i++) {
		laser.drawPoly( morphed[i], color );
	}
    
    laser.send(); // sends points to the DAC
}

void ofApp::draw() {
	
	ofBackground(0);
    
    laser.drawUI();
    cgui.draw();
        
	ofNoFill();
	ofSetLineWidth(1);
	ofDrawRectangle(0,0,laserWidth, laserHeight);
	
	int ypos = laserHeight+20;
    ofDrawBitmapString("TAB to change view, F11 to toggle full screen", 400, ypos);
    ofDrawBitmapString( "fps = " + ofToString(ofGetFrameRate()), 400, ypos+=30);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch( key ){
        case OF_KEY_F5: lines.clear(); break;
        case OF_KEY_F11: ofToggleFullscreen(); break;
        case OF_KEY_TAB: laser.nextProjector(); break;
        
        case OF_KEY_DEL : case OF_KEY_BACKSPACE:
            typeStr = typeStr.substr(0, typeStr.length()-1);
        break;
        
        case OF_KEY_RETURN:
            typeStr += "\n";
        break;
        
        default:
            if( bFirst ){
                typeStr.clear();
                bFirst = false;
            }
            ofUTF8Append(typeStr,key);
        break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){
    position = glm::vec2( x, y );
}

void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::exit(){
    //laser.saveSettings();
    dac.close();
}
