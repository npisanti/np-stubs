#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // usually neural network work better with higher dimensions than these
    examples.setInputAndTargetDimensions( 1, 1 ); 

    unsigned int numInputNeurons = examples.getNumInputDimensions();
    unsigned int numHiddenNeurons = 5; //For more complex problems, increase the number of hidden units
    unsigned int numOutputNeurons = examples.getNumTargetDimensions();

    //Initialize the MLP
    GRT::MLP mlp;
    mlp.init(numInputNeurons, numHiddenNeurons, numOutputNeurons, GRT::Neuron::LINEAR, GRT::Neuron::TANH, GRT::Neuron::TANH );

    mlp.setMaxNumEpochs( 12000 ); 
    mlp.setMinChange( 1.0e-10 ); 
    mlp.setLearningRate( 0.1 ); 
    mlp.setMomentum( 0.5 );
    mlp.setNumRestarts( 1 ); 
    //mlp.setUseValidationSet( false ); 
    mlp.setRandomiseTrainingOrder( true );
    mlp.enableScaling( true );

    pipeline << mlp; 

    ofBackground( 0 );
    
    fbo.allocate( ofGetWidth(), ofGetHeight() );
    fbo.begin();
        ofClear( 0, 0, 0, 0);
    fbo.end();

    ofSetWindowTitle( "neural network regression" );
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    ofNoFill();
    for( size_t i=0; i<examples.getNumSamples(); i++ ){
        float x = examples[i].getInputVector()[0] * ofGetWidth();
        float y = examples[i].getTargetVector()[0] * ofGetHeight();
        ofDrawCircle( x, y, 5 );
    }
    
    if( mode==1 && pipeline.getTrained() ){
        ofSetColor( 120 );
        fbo.draw(0, 0);
    }
    drawInfo();
}

//--------------------------------------------------------------
void ofApp::drawInfo(){
    ofSetColor( 255 );
    string info = "mode = ";
    if( mode == 0 ){ 
        info += "training\n";
        info += "click and drag mouse for example input\n";
        info += "press 'l' to load model\n";
        info += "spacebar to train model and run";
    } else {
        info += "run";
        if(pipeline.getTrained()) { 
            info+= " (training successful)\n"; 
            info += "press 's' to save model\n";
        }else{
            info+= " (training failed)\n"; 
        }
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

    updateCurve();
}
//--------------------------------------------------------------
void ofApp::updateCurve(){
    
    ofFill();
    ofSetColor(255, 80, 80);
    
    fbo.begin();
        ofClear(0, 0, 0, 0);
        
        if(pipeline.getTrained()){
            for( int x=2; x<fbo.getWidth(); x+=4 ){
                GRT::VectorFloat inputVector(1);
                inputVector[0] = double(x) / fbo.getWidth();            
                
                pipeline.predict( inputVector );
                float y = pipeline.getRegressionData()[0] * ofGetHeight();
                
                ofDrawCircle( x, y, 2 );
            }
        }
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(mode==0) mouseInput( x, y );
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(mode==0) mouseInput( x, y );
}

//--------------------------------------------------------------
void ofApp::mouseInput(int x, int y){
    switch( mode ){
        case 0: // training
        {
            double dx = double(x) / ofGetWidth();
            double dy = double(y) / ofGetHeight();
            
            GRT::VectorFloat inputVector(1);
            inputVector[0] = dx;
            GRT::VectorFloat targetVector(1);
            targetVector[0] = dy;
            
            examples.addSample( inputVector, targetVector );
            
            std::cout<< "mapped value "<<dx<<" to output "<<dy<<"\n";    
        }
        break;
        
        case 1: break;
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
    
        case 's':
            if( pipeline.save( ofToDataPath("pipeline.grt") ) ){
                std::cout << "pipeline saved\n";
            }else std::cout << "WARNING: Failed to save pipeline to file\n";
        break;
        
        case 'l':
            if( pipeline.load( ofToDataPath("pipeline.grt") ) ){
                std::cout << "pipeline data loaded to file\n";
                mode = 1;
                updateCurve();
                examples.clear();
            }else std::cout << "WARNING: Failed to load pipeline from file\n";
        break;
        
        case 'i':
            std::cout<< pipeline.getInfo() <<std::endl;
        break;
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
