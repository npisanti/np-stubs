
#pragma once

#include "ofMain.h"
#include "np-extra.h"
#include "../resources.h"

namespace scenes{ 
    
class LaserMapping : public np::Scene {
public:
    LaserMapping(){ beginningCursor.zeroTime(); }

    void save();
    void load();
    
private:
	void loop() override;
	
    void keyPressed( int key ) override;
    void mousePressed(int x, int y, int button) override;
    void mouseDragged(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;
 
    void drawInterface( float & x, float & y, float & width, float & height ) override;
    
    ofPoint cursor;
};

    
}
