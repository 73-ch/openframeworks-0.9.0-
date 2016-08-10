//
//  Ball.h
//  Ball
//
//  Created by Emiko Namikawa on 2016/01/07.
//
//

#ifndef Ball_h
#define Ball_h

#pragma once
#include "ofMain.h"

class Ball{
private:
    ofPoint pos;
    float radius;
    ofPoint speed;
    float phase;
    float phaseSpeed;
    float strechedRadius;
public:
    Ball();
    void draw();
    void update();
    void setRadius(float radius);
    float getRadius();
    void setPos(ofPoint pos);
    ofPoint getPos();
    void setSpeed(ofPoint speed);
    ofPoint getSpeed();
};

#endif /* Ball_h */
