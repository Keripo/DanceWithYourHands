#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "ofxKinect.h"


class testApp : public ofBaseApp
{

	public:
		
		// New stuff
		void setup2();
		void update2();
		void setThresh(int thresh);
		int kinectThresh;
		int count_tap;
		int left;
		int down;
		int up;
		int right;
		float *distancePixels;
		
		// Old dummied stuff
		void setup();
		void update();
		void draw();
		void exit();

		//void drawPointCloud();

		void keyPressed  (int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

		ofxKinect kinect;
};

#endif
