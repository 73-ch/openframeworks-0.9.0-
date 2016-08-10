//
//  particle.cpp
//  3dtest
//
//  Created by nami on 2016/07/11.
//
//

#include "particle.h"

particle::particle(){
    
}

void particle::init(float max_pos){
    // position setup
    pos.x = ofRandom(-0.5 * max_pos, max_pos / 2.0);
    pos.y = ofRandom(-0.5 * max_pos, max_pos / 2.0);
    pos.z = ofRandom(-0.5 * max_pos, max_pos / 2.0);
    
    // velocity setup
    vel.x = ofRandom(-0.2, 0.2);
    vel.y = ofRandom(-0.2, 0.2);
    vel.z = ofRandom(-0.2, 0.2);
    
    col.x = ofRandom(255);
    col.y = ofRandom(255);
    col.z = ofRandom(255);
}

void particle::update(float max_pos){
    float v_x;
    float v_y;
    float v_z;
    if (abs(pos.x + vel.x) > max_pos) {
        v_x = (pos.x + vel.x - max_pos * float(ofSign(vel.x))) - vel.x;
        vel.x *= -1.0;
    }else{
        v_x = vel.x;
    };
    
    if (abs(pos.y + vel.y) > max_pos) {
        v_y = (pos.y + vel.y - max_pos * float(ofSign(vel.y))) - vel.y;
        vel.y *= -1.0;
    }else{
        v_y = vel.y;
    };
    
    if (abs(pos.z + vel.z) > max_pos) {
        v_z = (pos.z + vel.z - max_pos * float(ofSign(vel.z))) - vel.z;
        vel.z *= -1.0;
    }else{
        v_z = vel.z;
    }
    
    pos.x += v_x;
    pos.y += v_y;
    pos.z += v_z;
}

void particle::draw(float radius){
    ofSetColor(col.x, col.y, col.z, 100);
    ofFill();
    ofDrawSphere(pos, radius);
}