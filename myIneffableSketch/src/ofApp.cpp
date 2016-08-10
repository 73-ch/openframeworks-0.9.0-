#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    sys.setup();
    
    group.setup(sys);
    
    group.setFriction(0.1);
    group.setGravity(ofVec3f(0, 0, 100));
    
    group.setColor(ofxSPK::RangeC(ofColor(255, 255, 255, 255),
                                  ofColor(255, 255, 255, 30)),
                                  ofxSPK::RangeC(ofColor(255, 255, 255, 0),
                                    ofColor(255, 255, 255, 0)));
    
    group.setLifeTime(0.5, 20);
    group.setSize(1);
    group.setMass(0.1, 1);
	group.reserve(100000);
    
    mod.setup(SPK::Obstacle::create(SPK::Plane::create(toSPK(ofVec3f(0, 0, 0)))), group);
    mod.setPosition(0, -300, 0);
	
	sound.load("sounds/");
}

//--------------------------------------------------------------
void ofApp::update(){
    group.emitRandom(100000,
                     ofVec3f(0, 0, 0),
                     ofxSPK::RangeF(1, 30));
    
    sys.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    cam.begin();
    
//    sys.debugDraw();
    sys.draw();
    
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
