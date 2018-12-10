
#include "ofMain.h"
#include "serializers/polylines.h"
#include "components/polyworks.h"

class ofApp : public ofBaseApp{
    
// ---------- members ------------------------------------------
        
ofPolyline silhouette;
ofPolyline freehand;
std::vector<ofPolyline> result;    
bool freehandIsDone;

std::vector<ofPolyline> lines;
    
//--------------------------------------------------------------
void setup(){
    
    ofBackground( 0 );
    
    std::vector<std::vector<ofPolyline>> import;
    np::deserialize_polylines( ofToDataPath("silhouette.xml"), import );
    silhouette = import[0][0];
    silhouette.close();
    
    int x = 800;
    int y = 300;
    int side = 250;
    freehand.addVertex( x, y );
    freehand.addVertex( x+side, y );
    freehand.addVertex( x+side, y+side );
    freehand.addVertex( x, y+side );
    freehand.addVertex( x, y );
    freehandIsDone = true;   
    
    result.reserve(12);
}

//--------------------------------------------------------------
void update(){

    float mx = ofGetMouseX() / float( ofGetWidth() );
    float my = ofGetMouseY() / float( ofGetHeight() );
    float base = np::polyworks::find_max_y(silhouette);
    auto center = glm::vec2(ofGetWidth()*0.5f, ofGetHeight()*0.5f);

    auto & src = freehand;

    result.clear();
    
    for( int i=0; i<3; ++i ){
        result.emplace_back();
        auto & dest = result.back();
        dest.resize(src.size());
        float reduce = 1.0f - i*0.25f;
        np::polyworks::stretch( src, dest, reduce, reduce );
    }

    lines.resize(50);
    
    
    auto box = silhouette.getBoundingBox();
    box.scaleFromCenter( 1.2f );
    for( size_t i=0; i<lines.size(); ++i ){
        lines[i].clear();
        float y0 = box.y + ofNoise( i*2.0f, ofGetElapsedTimef()*0.2f ) * box.height;
        float y1 = box.y + ofNoise( i*2.0f + 1.0f, ofGetElapsedTimef()*0.2f ) * box.height;
        lines[i].addVertex( box.x, y0 );
        lines[i].addVertex( box.x + box.width, y0 );
        
        np::polyworks::inside( lines[i], silhouette, result );
    }
}

//--------------------------------------------------------------
void draw(){
    
    
    ofNoFill();

    auto drawpoly = []( ofPolyline & poly, bool close=true ) noexcept { 
        auto & vertices = poly.getVertices();
        ofBeginShape();
        for( size_t v=0; v<vertices.size(); ++v ){
            ofVertex( vertices[v].x, vertices[v].y );
        }
        ofEndShape(close);
    };
    ofSetColor( 120, 0, 0 );
    drawpoly( silhouette );
    drawpoly( freehand );
    ofSetColor( 255 );
    for( auto & poly : result ){
        drawpoly( poly );
    }
    /*
    for( auto & poly : lines ){
        drawpoly( poly );
    }
    */    
   ofDrawBitmapString( "fps: " + ofToString( ofGetFrameRate()), 20, 20 );
}

//--------------------------------------------------------------
void exit(){

}

//--------------------------------------------------------------
void keyPressed(int key){
    switch( key ){    
        case ' ':
            freehand.addVertex( freehand.getVertices()[0] );
            freehandIsDone = true;
        break;
    }
}

void mousePressed(int x, int y, int button){
    if( freehandIsDone ){
        freehand.clear();
        freehandIsDone = false;
    } 
    freehand.addVertex( x, y );
}
void mouseDragged(int x, int y, int button){
    freehand.addVertex( x, y );
}
void mouseReleased(int x, int y, int button){
    freehand.addVertex( x, y );
}
//--------------------------------------------------------------
void keyReleased(int key){}
void mouseMoved(int x, int y){}
void mouseEntered(int x, int y){}
void mouseExited(int x, int y){}
void windowResized(int w, int h){}
void gotMessage(ofMessage msg){}
void dragEvent(ofDragInfo dragInfo){ }
//--------------------------------------------------------------

};

#include "ofAppGLFWWindow.h"
int main(int argc, const char** argv)
{

    #ifdef __ARM_ARCH
            ofGLESWindowSettings settings;
            settings.glesVersion = 2;
            settings.setSize( 1200, 800 );
            ofCreateWindow(settings);
    #else        
            ofGLWindowSettings settings;
            settings.setSize( 1200, 800 );
            ofCreateWindow(settings);      
    #endif
    ofRunApp(new ofApp());
}
