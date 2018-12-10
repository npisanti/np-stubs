
#pragma once

#include <iostream>
#include "ofApp.h"

namespace BINDNAME {

    static void test(){
        ofApp *app = (ofApp *)ofGetAppPtr();
        std::cout<<"lua BINDNAME module : "<< app->forLua <<"\n";
    }
    
}
