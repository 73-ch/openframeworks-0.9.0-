#pragma once

#include "ofMain.h"
#include "particle.h"

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
		
    
    ofCamera cam;
    ofVec3f cam_position;
    
    float box_size = 50.0;
    float radius = 1.0;
    float max_pos = box_size - radius;
    int num = 400;
    
    vector <particle> particles;
};
