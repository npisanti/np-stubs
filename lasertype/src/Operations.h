
#pragma once 

#include "ofMain.h"
#include "np-extra.h"



class Operations {
public:
    Operations();
    
    void typeops( const std::string & input, std::string & output );
    void polyops( std::vector<ofPolyline> & input, std::vector<ofPolyline> & output );
    
};
