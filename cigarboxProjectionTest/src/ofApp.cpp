#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
//    ofSetVerticalSync(true);
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    size = [ofGetWidth(), ofGetHeight()];
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetColor(100, 200, 100);
    ofSetLineWidth(3);
    ofDrawBox(0, 0, ofGetWidth(), ofGetHeight());
//    ofDrawBox(size);
//    ofDrawGrid();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
