#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    
    radius = 0;
    mySound.loadSound("a-mp3.mp3");
    mySound.setLoop(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    float * val = ofSoundGetSpectrum(1);
    radius = val[0] * 800.0;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 63, 255, 180);
    ofCircle(mouseX, mouseY, radius);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    mySound.setPan(x / (float)ofGetWidth() * 2 - 1.0f);
    mySound.setSpeed(0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight()) * 1.0f);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mySound.setPan(x / (float)ofGetWidth() * 2 - 1.0f);
    mySound.setSpeed(0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight()) * 1.0f);
    mySound.play();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mySound.stop();
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------


