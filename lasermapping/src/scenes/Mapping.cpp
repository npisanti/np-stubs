
#include "Mapping.h"

#define NUDGEAMT 0.25f

void scenes::LaserMapping::loop(){
    if( resourcesAvailable() ){
        laser.drawDot( cursor, ofColor(0, 255, 0) );
        
        for( auto & poly : mapping ){
            laser.drawPoly( poly, ofColor( 255, 0, 0 ) );
        }        
    }
}

void scenes::LaserMapping::keyPressed( int key ){
    switch( key ){
        case OF_KEY_UP: cursor.y -= NUDGEAMT; break;
        case OF_KEY_DOWN: cursor.y += NUDGEAMT; break;
        case OF_KEY_LEFT: cursor.x += NUDGEAMT; break;
        case OF_KEY_RIGHT: cursor.x -= NUDGEAMT; break;
        case ' ': 
            if( mapping.empty() ){ mapping.emplace_back(); }
            mapping.back().addVertex( cursor.x, cursor.y ); 
        break;
        case 'z': 
            if( mapping.size() ){ 
                if( mapping.back().size() ){
                    mapping.back().resize(mapping.back().size()-1);
                }else{
                    mapping.resize( mapping.size()-1 );
                }
            }
        break;
        case 'n': mapping.emplace_back(); break;
        case 's': save(); break;
        case 'l': load(); break;
    }
}

void scenes::LaserMapping::mousePressed(int x, int y, int button){
    cursor.x = x;
    cursor.y = y;
}

void scenes::LaserMapping::mouseDragged(int x, int y, int button){
    cursor.x = x;
    cursor.y = y;
}

void scenes::LaserMapping::mouseReleased(int x, int y, int button){
    cursor.x = x;
    cursor.y = y;
}

void scenes::LaserMapping::save(){
    np::serialize_polylines( ofToDataPath("mapping.xml"), mapping ); 
}

void scenes::LaserMapping::load(){
    np::deserialize_polylines( ofToDataPath("mapping.xml"), mapping ); 
}

void scenes::LaserMapping::drawInterface( float & x, float & y, float & width, float & height ) {
	ofNoFill();
	ofSetLineWidth(1);
	ofDrawRectangle( 8, 8, resources::laserWidth, resources::laserHeight);
	
	int ypos = resources::laserHeight+20;
    ofDrawBitmapString("TAB to change view, F to toggle full screen", 400, ypos+=30);

    laser.drawUI();
}
