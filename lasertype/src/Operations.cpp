
#include "Operations.h"
#include "components/polyworks.h"

Operations::Operations(){}
    
void Operations::typeops( const std::string & input, std::string & output ){
    output = input;
}

void Operations::polyops( std::vector<ofPolyline> & input, std::vector<ofPolyline> & output ){
    
    glm::vec2 mouse( ofGetMouseX(), ofGetMouseY() );
    
    std::swap( input, output ); // no operation, faster than copy

    /*
    output.resize( input.size() );    
    for( size_t i=0; i<output.size(); ++i ){
        np::polyworks::push( input[i], output[i], mouse, 50 );    
    }
    */

    for( size_t i=0; i<output.size(); ++i ){
        // necessary for cheaper laser calculations 
        np::polyworks::simplify( output[i], 0.7f ); 
    }

}
