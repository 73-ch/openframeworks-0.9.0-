//
//  BoxState.h
//  myLikeableSketch
//
//  Created by nami on 2016/08/10.
//
//
#pragma once

#include "ofxState.h"
#include "SharedData.h"

class BoxState : public itg::ofxState<SharedData>{
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    string getName();
};