//
//  CustomRect.h
//  particleSound
//
//  Created by Emiko Namikawa on 2016/01/08.
//
//

#pragma once
#include "ofxBox2d.h"

class CustomRect : public ofxBox2dRect{
public:
    CustomRect(int _num);
    void update();
    
    int num;
    ofSoundPlayer mySound;
    float soundSpeed;
    float amp;
    float lfo;
    float radius;
};