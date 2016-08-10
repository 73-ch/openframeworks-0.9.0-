#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    vidGrabber.initGrabber(320, 240);
    colorImg.allocate(320, 240);
    grayImg.allocate(320, 240);
    grayBg.allocate(320, 240);
    grayDiff.allocate(320, 240);
    bLearnBackground = true;
    threshold = 100;
	maxX = 0.0;
	maxY = 0.0;
	minX = 320.0;
	minY = 240.0;
	point1 = ofPoint(minX,minY);
	point2 = ofPoint(maxX,minY);
	point3 = ofPoint(maxX,maxY);
	point4 = ofPoint(minX,maxY);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    bool bNewFrame = false;
    
    vidGrabber.update();
    bNewFrame = vidGrabber.isFrameNew();
    
    if (bNewFrame) {
        colorImg.setFromPixels(vidGrabber.getPixels(), 320, 240);
        
        grayImg = colorImg;
        
        if (bLearnBackground == true) {
            grayBg = grayImg;
            bLearnBackground = false;
        }
        grayDiff.absDiff(grayBg, grayImg);
        grayDiff.threshold(threshold);
        contourFinder.findContours(grayDiff, 20, (340 * 240) / 3, 1, false);
        for (int i = 0; i < contourFinder.nBlobs; i++) {
			for(int j = 0; j < contourFinder.blobs[i].pts.size(); j += 4){
				ofPoint pts = contourFinder.blobs[i].pts[j];
				if(pts.x > maxX){
					maxX = pts.x;
				}
				if(pts.x < minX){
					minX = pts.x;
				}
				if(pts.y > maxY){
					maxY = pts.y;
				}
				if(pts.y < minY) {
					minY = pts.y;
				}
			}
        }
		point1 = ofPoint(minX,minY);
		point2 = ofPoint(maxX,minY);
		point3 = ofPoint(maxX,maxY);
		point4 = ofPoint(minX,maxY);
		
    }
	
}

//--------------------------------------------------------------
void ofApp::draw(){
    float ratioX = ofGetWidth() / 320;
    float ratioY = ofGetHeight() / 240;
	
    ofScale((float)ofGetWidth() / (float)grayDiff.getWidth(), (float)ofGetHeight() / (float)grayDiff.getHeight());
    ofSetColor(255, 255, 255);
    colorImg.draw(0,0);
    ofNoFill();
//    contourFinder.draw();
	ofFill();
	ofSetColor(0, 0, 0);
	ofBeginShape();
	ofVertex(point1);
	ofVertex(point2);
	ofVertex(point3);
	ofVertex(point4);
	ofEndShape();
	maxX = 0.0;
	maxY = 0.0;
	minX = 320.0;
	minY = 240.0;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            bLearnBackground = true;
            break;
        
        case '+':
            threshold ++;
            if(threshold > 255){
                threshold = 255;
            }
            break;
        
        case '-':
            threshold --;
            if(threshold < 0){
                threshold = 0;
            }
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
