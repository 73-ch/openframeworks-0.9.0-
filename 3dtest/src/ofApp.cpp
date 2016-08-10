#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableAlphaBlending();
    cam.setPosition(0, 0, box_size + 20);
    cam.lookAt(ofVec3f(0,0,0));
    
    particles.assign(num, particle());
    
    for (unsigned int i = 0; i < num; i++) {
        particles[i].init(max_pos);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (unsigned int i = 0; i < num; i++) {
        particles[i].update(max_pos / 2.0);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofSetColor(255, 255, 255, 1.0);
    ofNoFill();
    ofDrawBox(box_size);
    for (unsigned int i = 0; i < num; i++) {
        particles[i].draw(radius);
    }
    cam.end();
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
