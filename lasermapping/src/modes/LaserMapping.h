
#pragma once

#include "ofMain.h"
#include "np-extra.h"

namespace np{ namespace modes{ 
    
class LaserMapping : public Mode {
    
	void draw() override;
	
    void keyPressed( int key ) override;
    void keyReleased( int key ) override;
    void mousePressed(int x, int y, int button) override;
    void mouseDragged(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;
};
    
}}
