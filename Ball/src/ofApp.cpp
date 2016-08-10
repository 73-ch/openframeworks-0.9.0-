#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetCircleResolution(32);
    ofEnableAlphaBlending();
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < balls.size(); i++){
        balls[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < balls.size(); i++){
        balls[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    ofPoint(speed) = myBall.getSpeed();
//    switch (key) {
//        case 'z':
//            speed.x += ofSign(speed.x);
//            break;
//        case 'x':
//            speed.x -= ofSign(speed.x);
//            break;
//        case 99:
//            speed.y += ofSign(speed.y);
//            break;
//        case 'v':
//            speed.y -= ofSign(speed.y);
//            break;
//    }
//    myBall.setSpeed(speed);
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 'r':
            balls.clear();
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
    int bSize = balls.size();
    if (bSize < 1) {
        Ball b;
        float radius = ofGetHeight() / 3;
        b.setPos(ofPoint(mouseX, mouseY));
        b.setRadius(radius);
        b.setSpeed(ofPoint(ofRandom(-10, 10), ofRandom(-10, 10)));
        balls.push_back(b);
    }
    for (int i = 0; i < bSize; i++) {
        ofPoint pos = balls[i].getPos();
        float radius = balls[i].getRadius();
        float dist = ofDist(pos.x, pos.y, mouseX, mouseY);
        if (dist < radius) {
            balls[i].setRadius(radius * 0.6);
            balls[i].setPos(ofPoint(pos.x - radius * 0.7, pos.y));
            balls[i].setSpeed(ofPoint(ofRandom(-radius / 50, radius / 50), ofRandom(-radius / 50, radius / 150)));
            Ball b1 = Ball();
            b1.setRadius(radius * 0.6);
            b1.setPos(ofPoint(pos.x + radius * 0.7, pos.y));
            b1.setSpeed(ofPoint(ofRandom(-radius / 50, radius / 50), ofRandom(-radius / 50, radius / 50)));
            balls.push_back(b1);
            
            Ball b2 = Ball();
            b2.setRadius(radius * 0.6);
            b2.setPos(ofPoint(pos.x, pos.y - radius * 0.7));
            b2.setSpeed(ofPoint(ofRandom(-radius / 50, radius / 50), ofRandom(-radius / 50, radius / 50)));
            balls.push_back(b2);
            
            Ball b3 = Ball();
            b3.setRadius(radius * 0.6);
            b3.setPos(ofPoint(pos.x, pos.y + radius * 0.7));
            b3.setSpeed(ofPoint(ofRandom(-radius / 50, radius / 50), ofRandom(-radius / 50, radius / 50)));
            balls.push_back(b3);
            
        }
    }
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
