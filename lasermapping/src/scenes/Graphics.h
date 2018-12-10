
#pragma once

#include "components/Scenes.h"
#include "../resources.h"

namespace scenes {

class Graphics : public np::Scene {

public:
    void setup();
	void onStart() override {};
	void loop() override;

    void drawInterface( float & x, float & y, float & width, float & height ) override;
    
private:

};

}
