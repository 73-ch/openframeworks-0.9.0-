//
//  particle.h
//  3dtest
//
//  Created by nami on 2016/07/11.
//
//

#pragma once

#include "ofMain.h"

class particle {

public:
    particle();
    
    void init(float max_pos);
    void update(float max_pos);
    void draw(float radius);
    
    ofVec3f pos;
    ofVec3f vel;
    ofVec3f col;
};