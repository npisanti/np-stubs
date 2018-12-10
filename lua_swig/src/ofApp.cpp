/*
 * Copyright (c) 2012 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxLua for documentation
 *
 */
#include "ofApp.h"


#include "bindings/BINDNAME.h"

extern "C" {
	int luaopen_BINDNAME(lua_State* L);
}


//--------------------------------------------------------------
void ofApp::setup() {
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofSetLogLevel("ofxLua", OF_LOG_VERBOSE);
		
	// init the lua state
	lua.init(true); // true because we want to stop on an error
	
	luaopen_BINDNAME(lua);  // BINDNAME bindings
	
    forLua = "hello world lua";
    //BINDNAME::setglobal( forLua );
    	// listen to error events
	lua.addListener(this);

	lua.doScript( "scripts/fontsExample.lua", true);
	
	// call the script's setup() function
	lua.scriptSetup();
}

//--------------------------------------------------------------
void ofApp::update() {
	// call the script's update() function
	lua.scriptUpdate();
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    lua.setNumber("apptime", ofGetElapsedTimef() );
	// call the script's draw() function
	lua.scriptDraw();
	
}

//--------------------------------------------------------------
void ofApp::exit() {
	// call the script's exit() function
	lua.scriptExit();
	
	// clear the lua state
	lua.clear();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	
	switch(key) {
		case 'r':
			reloadScript();
        break;
        
        case ' ':
            std::cout<<"--------changing global string ------\n";
            forLua = "got it";
        break;
	}
	
	lua.scriptKeyPressed(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	lua.scriptMouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	lua.scriptMouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	lua.scriptMousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	lua.scriptMouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::errorReceived(std::string& msg) {
	ofLogNotice() << "got a script error: " << msg;
}

//--------------------------------------------------------------
void ofApp::reloadScript() {
	// exit, reinit the lua state, and reload the current script
	lua.scriptExit();
	lua.init();
    luaopen_BINDNAME(lua);  // BINDNAME bindings

	lua.doScript( "scripts/fontsExample.lua", true);
	lua.scriptSetup();
}


