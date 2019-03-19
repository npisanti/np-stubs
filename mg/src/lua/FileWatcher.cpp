
#include "FileWatcher.h"

np::miscela::FileWatcher::FileWatcher(){
    
    parameters.setName("label me");
    interval = 0.05f;
    timePassed = 0.0f;
    
}

void np::miscela::FileWatcher::load( std::string path, bool watch ) {
    filepath = path;

    if( ! ofFilePath::isAbsolute( filepath )){
        filepath = ofToDataPath( filepath );
    }

    ofFile file( filepath );
    if( file.exists() ){
        if( watch ){
            ofAddListener(ofEvents().update, this, &FileWatcher::checkFile);
            writeTimestamp = boost::filesystem::last_write_time( filepath );
        }
        reload();
    }else{
        ofLogError() << "[np::miscela::DotFrag] file to load does not exists\n";
    }
    
    std::string name = ofFilePath::ofFilePath::getFileName( path );
    parameters.setName( name );
}


void np::miscela::FileWatcher::checkFile(ofEventArgs &args){
    timePassed += ofGetLastFrameTime();
    if( timePassed > interval ){
        time_t checkTimestamp = boost::filesystem::last_write_time( filepath );
        if( checkTimestamp != writeTimestamp){
            writeTimestamp = checkTimestamp;
            reload();
            ofLogNotice() << "["<<filepath<<"] shader reloaded";
        }
    }
}
