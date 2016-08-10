//
//  boxSceneB.cpp
//  myMasterlySketch
//
//  Created by nami on 2016/08/10.
//
//

#include "boxSceneB.h"
//--------------------------------------------------------------
void boxSceneB::setup(){
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofSetBackgroundColor(0);
    for (unsigned int i = 0; i < boxNum; i++) {
        boxPos[i] = i * 20;
    }
    ofLog() << "read";
    cout << "read B "<< endl;
}

//--------------------------------------------------------------
void boxSceneB::update(){
    
}

//--------------------------------------------------------------
void boxSceneB::draw(){
    cam.begin();
    for (unsigned int i = 0; i < boxNum; i++) {
        ofRotateZ(sin(ofGetElapsedTimef()) * 100);
        ofSetColor(255);
        ofDrawBox(boxPos[i], 50, 0, 10, 10, 10);
        break;

    }
    cam.end();
    ofSetColor(0, 0, 0, 20);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void boxSceneB::keyPressed(int key){
    
}

//--------------------------------------------------------------
void boxSceneB::keyReleased(int key){
    
}

//--------------------------------------------------------------
void boxSceneB::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void boxSceneB::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void boxSceneB::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void boxSceneB::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void boxSceneB::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void boxSceneB::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void boxSceneB::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void boxSceneB::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void boxSceneB::dragEvent(ofDragInfo dragInfo){ 
    
}
