#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	#ifdef __ARM_ARCH
    	ofGLESWindowSettings settings;
        settings.setSize( 1024, 768 );
        settings.setGLESVersion(2);
        ofCreateWindow(settings);
	#else
        ofGLFWWindowSettings settings;
        settings.setSize( 1024, 768 );
        //settings.setGLVersion( 3, 2 );
        ofCreateWindow(settings);
	#endif

	ofRunApp( new ofApp());

}
