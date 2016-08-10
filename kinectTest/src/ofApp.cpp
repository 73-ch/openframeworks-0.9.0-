#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    kinect.open(true, true, 0, 2);
    kinect.start();
    
    mesh.setUsage(GL_DYNAMIC_DRAW);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    ecam.setAutoDistance(false);
    ecam.setDistance(200);
    
    irShader.setupShaderFromSource(GL_FRAGMENT_SHADER, irFragmentShader);
    irShader.linkProgram();
}

void ofApp::update(){
    kinect.update();
    if(kinect.isFrameNew()){
        texture.loadData(kinect.getIrPixelsRef());
        
        
//        mesh.clear();
//        {
//            int step = 1;
//            int h = kinect.getDepthPixelsRef().getHeight();
//            int w = kinect.getDepthPixelsRef().getWidth();
//            for(int y = 0; y < h; y += step) {
//                for(int x = 0; x < w; x += step) {
//                    float dist = kinect.getDistanceAt(x, y);
//                    if(dist > 50 && dist < 500) {
//                        ofVec3f pt = kinect.getWorldCoordinateAt(x, y, dist);
//                        
//                        ofColor c;
//                        float h = ofMap(dist, 50, 200, 0, 255, true);
//                        c.setHsb(h, 255, 255);
//                        mesh.addColor(c);
//                        mesh.addVertex(pt);
//                    }
//                }
//            }
//            
//        }

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(texture.isAllocated()){
        irShader.begin();
        texture.draw(0, 0, 600, 400);
        irShader.end();
    }
//    ofClear(0);
//    
//    if (mesh.getVertices().size()) {
//        ofPushStyle();
//        glPointSize(2);
//        ecam.begin();
//        ofDrawAxis(100);
//        ofPushMatrix();
//        ofTranslate(0, 0, -100);
//        mesh.draw();
//        ofPopMatrix();
//        ecam.end();
//        ofPopStyle();
//    }
    
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapStringHighlight("Device Count : " + ofToString(ofxMultiKinectV2::getDeviceCount()), 10, 40);
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
