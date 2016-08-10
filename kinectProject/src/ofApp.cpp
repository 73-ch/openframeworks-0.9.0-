#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    kinect.open(true, true, 0, 2);
    kinect.start();
    irShader.setupShaderFromSource(GL_FRAGMENT_SHADER, irFragmentShader);
    irShader.linkProgram();
    width = 1440;
    height = 810;
    
    colorImage.allocate(width, height, OF_IMAGE_COLOR);
    cIrImage.allocate(width, height);
    gIrImage.allocate(width, height);
    irPixels.allocate(width, height, OF_PIXELS_RGB);
    contourFinder.setAnchorPoint(0, 0);
    
    frameBuffer1.allocate(width, height, GL_RGB);
    frameBuffer2.allocate(width, height, GL_RGBA);
    
//    contourFinder.setMinAreaRadius(10);
//    contourFinder.setMaxAreaRadius(400);
    
    gui.setup();
    gui.add(constant.setup("constant", 100000, 0.0, 150000.0));
    gui.add(threshold.setup("threshold", 150, 0, 255));
    gui.add(difference.setup("difference", 0.07, 0.05, 0.09));
    gui.add(framerate.setup(ofToString(ofGetFrameRate())));
    gui.add(devicecount.setup(ofToString(ofxMultiKinectV2::getDeviceCount())));
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
    if(kinect.isFrameNew()){
        colorImage.setFromPixels(kinect.getColorPixelsRef());
        texture2.loadData(kinect.getIrPixelsRef());
        if (texture2.isAllocated()) {
            frameBuffer1.begin();
            irShader.begin();
            irShader.setUniform1f("constant", constant);
            texture2.draw(0, 0, width, height);
            irShader.end();
            frameBuffer1.end();
            frameBuffer1.readToPixels(irPixels);
            
            cIrImage.setFromPixels(irPixels, width, height);
            gIrImage = cIrImage;
            gIrImage.threshold(threshold);
            contourFinder.findContours(gIrImage, 20, (width * height) / 5, 2, false);
            for (unsigned int i =0; i < contourFinder.nBlobs; i++) {
                ofPoint center = contourFinder.blobs[i].centroid;
                centers[i] = center;
            }
            float x0 = centers[0].x + difference * (width - centers[0].x) * sin(DEG_TO_RAD * 90 * (1 - centers[0].x / width));
            float x1 = centers[1].x + difference * (width - centers[1].x) * sin(DEG_TO_RAD * 90 * (1 - centers[1].x / width));
            rect.x = centers[0].x < centers[1].x ? x0 : x1 ;
            rect.y = centers[0].y < centers[1].y ? centers[0].y : centers[1].y;
            rect.width = abs(x0 - x1);
            rect.height = abs(centers[0].y - centers[1].y);
//            ofLog() << centers[1].x;
            
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    frameBuffer2.begin();
    
    ofSetBackgroundAuto(false);
    ofSetColor(0, 0, 0, 10);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(100, 200, 100);
    ofNoFill();
    ofSetLineWidth(5.0);
    ofDrawRectangle(rect);
    
    frameBuffer2.end();
    box = frameBuffer2.getTexture();
    
    
    ofSetBackgroundAuto(true);
    
//    colorImage.draw(0,0, width, height);
    box.draw(0,0);

    gui.draw();
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
