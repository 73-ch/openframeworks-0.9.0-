//
//  Ball.cpp
//  Ball
//
//  Created by Emiko Namikawa on 2016/01/07.
//
//

#include "Ball.h"

Ball::Ball(){
    pos = ofPoint(400, 300);
    radius = 80.0;
    speed = ofPoint(0, 0);
    phaseSpeed = ofRandom(0.1, 0.5);
    phase = 0;
}

void Ball::draw(){
    ofSetColor(31, 63, 255, 100);
    ofCircle(pos.x, pos.y, strechedRadius);
    
    ofSetColor(255, 0, 0, 100);
    ofCircle(pos.x, pos.y, radius / 10.0);
    ofSetColor(31, 63, 255);
}

void Ball::update(){
    strechedRadius = radius + sin(phase) * radius / 4;
    phase += phaseSpeed;
    if(phase > TWO_PI){
        phase -= TWO_PI;
    }
    
    pos += speed;
    if (pos.x < radius || pos.x > ofGetWidth() - radius) {
        speed.x *= -1;
    }
    if (pos.y < radius || pos.y > ofGetHeight() - radius) {
        speed.y *= -1;
    }
}

void Ball::setPos(ofPoint _pos){
    pos = _pos;
}

ofPoint Ball::getPos(){
    return pos;
}

void Ball::setRadius(float _radius){
    radius = _radius;
}

float Ball::getRadius(){
    return radius;
}

void Ball::setSpeed(ofPoint _speed){
    speed = _speed;
}

ofPoint Ball::getSpeed(){
    return speed;
}

