#pragma once

#include "ofMain.h"
#include "ofxMultiKinectV2.h"
#include "ofxGui.h"
#include "ofxTurboJpeg.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"

#define USE_OFX_TURBO_JPEG

#define STRINGIFY(x) #x


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxMultiKinectV2 kinect;
    ofTexture texture1;
    ofTexture texture2;
    ofxTurboJpeg turbo;
    ofShader irShader;
    ofImage colorImage;
    ofxCvColorImage cIrImage;
    ofxCvGrayscaleImage gIrImage;
    ofxCvContourFinder contourFinder;
    ofFbo frameBuffer1;
    ofFbo frameBuffer2;
    ofTexture box;
    ofPixels irPixels;
    
    int width;
    int height;
    ofPoint centers[2];
    ofRectangle rect;
    ofxPanel gui;
    ofxFloatSlider difference;
    ofxFloatSlider constant;
    ofxIntSlider threshold;
    ofxLabel framerate;
    ofxLabel devicecount;
};

static string irFragmentShader =
STRINGIFY(
          uniform sampler2DRect tex;
          uniform float constant;
          void main()
          {
              vec4 col = texture2DRect(tex, gl_TexCoord[0].xy);
              float value = col.r / constant;
              gl_FragColor = vec4(vec3(value), 1.0);
          }
          );