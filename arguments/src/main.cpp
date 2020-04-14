#include "ofMain.h"
#include "ofApp.h"
#include "ofAppNoWindow.h"  

//====================================================================
int main( int argc, char *argv[] ){

    ofAppNoWindow window;  
    
    ofApp *app = new ofApp();
    
    app->uno = "not assigned";
    app->due = "not assigned";
    app->tre = "not assigned";

    if(argc>1){		
        for( int i=1; i<argc; ++i ){
            switch( i ){
                case 1: app->uno = std::string( argv[i] ); break;
                case 2: app->due = std::string( argv[i] ); break;
                case 3: app->tre = std::string( argv[i] ); break;
                default : break;
            }
        }   
    }

    ofSetupOpenGL(&window, 256,256,OF_WINDOW);  
	ofRunApp( app );

}
