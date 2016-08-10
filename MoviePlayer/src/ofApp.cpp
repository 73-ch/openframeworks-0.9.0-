#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableSmoothing();
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    fingersMovie.loadMovie("a.mov");
    
    fingersMovie.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    fingersMovie.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0xFFFFFF);
    
    fingersMovie.draw(20, 20, 480, 320);
    
    unsigned char * pixels = fingersMovie.getPixels();
    
    for (int i = 0; i < 480; i += 10) {
        for (int j = 0; j < 320; j += 10) {
            unsigned char r = pixels[(j * 320 + i)*3];
            unsigned char g = pixels[(j * 320 + i)*3+1];
            unsigned char b = pixels[(j * 320 + i)*3+2];
            
            ofSetColor(255, 0, 0, 100);
            ofCircle(360 + i, 20 + j, 10.0 * (float)r / 255.0);
            ofSetColor(0, 255, 0, 100);
            ofCircle(360 + i, 20 + j, 10.0 * (float)g / 255.0);
            ofSetColor(0, 0, 255, 100);
            ofCircle(360 + i, 20 + j, 10.0 * (float)b / 255.0);
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '0':
            fingersMovie.firstFrame();
            break;
    }
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


