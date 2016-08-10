#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    georgia.loadFont("mplus-1mn-thin.ttf", 60);
    
    fontX = ofGetWidth();
}

//--------------------------------------------------------------
void ofApp::update(){
    fontX -= 5;
    ofRectangle rect = georgia.getStringBoundingBox("Hello! I am openFrameworks.", 0, 0);
    
    if (fontX < -rect.width) {
        fontX = ofGetWidth();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 127, 255);
    georgia.drawString("Hello! I am openFrameworks.", fontX, ofGetHeight() / 2);
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}
