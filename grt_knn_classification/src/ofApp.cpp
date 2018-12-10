#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    K = 3;
    
    GRT::KNN knn;
    knn.setK( K );
    pipeline << knn;

    examples.setNumDimensions( 2 );
    
    ofBackground( 0 );
    
    guess.x = -100;
    guess.y = -100;
    guess.z = 0;
    
    grid.allocate( ofGetWidth(), ofGetHeight() );
    grid.begin();
        ofClear( 0, 0, 0, 0);
    grid.end();

    ofSetWindowTitle( "knn classification study" );
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    if( mode==1 && pipeline.getTrained() ){
        ofSetColor( 255 );
        grid.draw(0, 0);

        switch( int( guess.z ) ){
            case 1: ofSetColor(255, 0, 0 ); break;
            case 2: ofSetColor(0, 255, 0 ); break;
            case 3: ofSetColor(0, 0, 255 ); break;
            default: ofSetColor(255); break;
        }    
        ofDrawCircle( guess.x, guess.y, 12 );
    }

    for( size_t i=0; i<examples.getNumSamples(); ++i ){
        switch( examples[i].getClassLabel() ){
            case 1: ofSetColor(255, 0, 0 ); break;
            case 2: ofSetColor(0, 255, 0 ); break;
            case 3: ofSetColor(0, 0, 255 ); break;
            default: ofSetColor(255); break;
        }
        float x = examples[i][0]*ofGetWidth();
        float y = examples[i][1]*ofGetHeight();
        ofDrawCircle( x, y, 5 );
    }
    
    drawInfo();
}

//--------------------------------------------------------------
void ofApp::drawInfo(){
    ofSetColor( 255 );
    string info = "mode = ";
    if( mode == 0 ){ 
        info += "training\n";
        info += "click with different mouse buttons for example input\n";
        info += "backspace to clear all the examples\n";
        info += "K=";
        info += ofToString( K );
        info += " press 1-5 to change\n";
        info += "spacebar to train model and run";
    } else {
        info += "run";
        if(pipeline.getTrained()) { 
            info+= " (training successful)\n"; 
            info += "click and drag to test input and output\n";    
        }else{
            info+= " (training failed)\n"; 
        }
        info += "K=";
        info += ofToString( K );
        info += " press 1-5 to change\n";
        info += "spacebar to return to examples input";
    }
    ofDrawBitmapString( info, 20, 20 );
}

//--------------------------------------------------------------
void ofApp::train(){
    pipeline.train( examples );
    if(pipeline.getTrained()){
        std::cout<<"training succesfull\n";
    }else{
        std::cout<<"training failed\n";
    }                        
    guess.x = -100;
    guess.y = -100;
    updateGrid();
}
//--------------------------------------------------------------
void ofApp::updateGrid(){
    grid.begin();
        ofClear(0, 0, 0, 0);
        if(pipeline.getTrained()){
            for( int x = 0; x<grid.getWidth(); x+=10 ){
                for (int y = 0; y<grid.getHeight(); y+=10){
                                                    
                    GRT::VectorFloat sample(2);
                    sample[0] = double(x) / grid.getWidth(); 
                    sample[1] = double(y) / grid.getHeight();
                    
                    pipeline.predict( sample );
                    int output = pipeline.getPredictedClassLabel();

                    switch( output ){
                        case 1: ofSetColor( 80, 0, 0 ); break;
                        case 2: ofSetColor( 0, 80, 0 ); break;
                        case 3: ofSetColor( 0, 0, 80 ); break;
                        default: ofSetColor( 80 ); break;
                    }    
                    ofDrawLine( x, y+5, x+10, y+5);
                    ofDrawLine( x+5, y, x+5, y+10);
                }
            }            
        }
    grid.end();
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if( mode==1 && pipeline.getTrained() ){
        guess.x = x / ofGetWidth();
        guess.y = y / ofGetHeight();
        
        GRT::VectorFloat sample(2);
        sample[0] = double(x); 
        sample[1] = double(y);
        pipeline.predict( sample );
        guess.z = pipeline.getPredictedClassLabel();   
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    switch( mode ){
        case 0: // training
        {
            double dx = double(x) / ofGetWidth();
            double dy = double(y) / ofGetHeight();
            
            GRT::VectorFloat sample(2);
            sample[0] = dx; //mouseX / double(ofGetWidth());
            sample[1] = dy; //mouseY / double(ofGetHeight());
            examples.addSample( button+1, sample ); // class, input

            std::cout<< "added point "<<dx<<" "<<dy<<" to class "<<button+1<<"\n";    
        }
        break;
        
        case 1: // run
        {
            if(pipeline.getTrained()){
                guess.x = double(x) / ofGetWidth();
                guess.y = double(y) / ofGetHeight();
                
                GRT::VectorFloat sample(2);
                sample[0] = double(x); 
                sample[1] = double(y);
                pipeline.predict( sample );
                guess.z = pipeline.getPredictedClassLabel();            
            }
        }
        break;
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
       
    switch( key ){
        case ' ':
            if (mode==0){ train(); }
            mode = mode ? 0 : 1; 
        break;
        
        case OF_KEY_BACKSPACE:
            if( mode==0 ){
                examples.clear();
            }
        break;
    }
    
    int newK = key - '1' + 1;
    
    if(newK>0 && newK<=5){
        K = newK;
        
        GRT::KNN knn;
        knn.setK( K );
        pipeline << knn;
        
        if(mode==1){
            train();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
