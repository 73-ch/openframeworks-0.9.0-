#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableSmoothing();
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    camWidth = 480;
    camHeight = 320;
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(camWidth, camHeight);
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0xFFFFFF);
    vidGrabber.draw(20, 20, 480, 320);
    
    unsigned char * pixels = vidGrabber.getPixels();
    
    for (int i = 0; i < camWidth; i += 10) {
        for (int j = 0; j < camHeight; j += 10) {
            unsigned char r = pixels[(j * camWidth + i) * 3];
            unsigned char g = pixels[(j * camWidth + i) * 3 + 1];
            unsigned char b = pixels[(j * camWidth + i) * 3 + 2];
            ofSetColor(255, 0, 0, 100);
            ofCircle(camWidth + 40 + i, 20 + j, 20.0 * (float)r/255.0);
            ofSetColor(0, 255, 0, 100);
            ofCircle(camWidth + 40 + i, 20 + j, 20.0 * (float)g/255.0);
            ofSetColor(0, 0, 255, 100);
            ofCircle(camWidth + 40 + i, 20 + j, 20.0 * (float)b/255.0);
        }
    }
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


