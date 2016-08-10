#include "ofApp.h"
#include "BoxState.h"
#include "SphereState.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    stateMachine.getSharedData().counter = 0;
    stateMachine.getSharedData().lastUpdate = ofGetElapsedTimeMillis();
    
//    states.push_back(BoxState());
//    states.push_back(SphereState());
    
//    for (unsigned int i = 0; i < states.size(); i++) {
//        stateMachine.addState(&states[i]);
//    }
    
    stateMachine.addState<BoxState>();
    states.push_back("BoxState");
    stateMachine.addState<SphereState>();
    states.push_back("SphereState");
    
    stateMachine.changeState("BoxState");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            stateMachine.changeState(states[ofRandom(states.size())]);
//            stateMachine.changeState("SphereState");
            break;
            
        default:
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
