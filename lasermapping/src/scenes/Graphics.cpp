
#include "Graphics.h"

void scenes::Graphics::setup(){
    beginningCursor.zeroTime();
}

void scenes::Graphics::loop() {
    if( resourcesAvailable() ){
        
    }
}

void scenes::Graphics::drawInterface( float & x, float & y, float & width, float & height ) {
	ofNoFill();
	ofSetLineWidth(1);
	ofDrawRectangle( 8, 8, resources::laserWidth, resources::laserHeight);
	
	int ypos = resources::laserHeight+20;
    ofDrawBitmapString("TAB to change view, F to toggle full screen", 400, ypos+=30);

    laser.drawUI();
}
