#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( int argc, char *argv[] ){

	ofSetupOpenGL(1024,768, OF_WINDOW);			// <-------- setup the GL context
    
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

	ofRunApp( app );
}
