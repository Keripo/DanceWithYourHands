#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup()
{
	kinect.init();
	kinect.setUseRGBCamera(false);
	kinect.setVerbose(false);
	kinect.open();

	grayImage.allocate(kinect.width, kinect.height);
	ofSetFrameRate(10);
}

//--------------------------------------------------------------
void testApp::update()
{
	ofBackground(100, 100, 100);
	kinect.update();

	// 640 x 480
	// 4 x (4 x 12 -> 40p x 40p)
	// Each count can max at 48
	// 6 is our experimentally determined threshold of an acceptable "press"
	float *distancePixels = kinect.getDistancePixels();

	count_left = 0;
	for (int column = 0; column < 4; column++) {
		for (int row = 0; row < 12; row++) {
			int count = 0;
			for (int y = 0; y < 40; y++) {
				for (int x = 0; x < 40; x++) {
					int i = (row * 40 + y) * 640 + column * 40 + x;
					if(distancePixels[i] < 100) count++;
				}
			}
			if (count > 800) { // More than half
				count_left++;
			}
		}
	}

	count_down = 0;
	for (int column = 0; column < 4; column++) {
		for (int row = 0; row < 12; row++) {
			int count = 0;
			for (int y = 0; y < 40; y++) {
				for (int x = 0; x < 40; x++) {
					int i = (row * 40 + y) * 640 + column * 40 + x + 160 * 1;
					if(distancePixels[i] < 100) count++;
				}
			}
			if (count > 800) { // More than half
				count_down++;
			}
		}
	}

	count_up = 0;
	for (int column = 0; column < 4; column++) {
		for (int row = 0; row < 12; row++) {
			int count = 0;
			for (int y = 0; y < 40; y++) {
				for (int x = 0; x < 40; x++) {
					int i = (row * 40 + y) * 640 + column * 40 + x + 160 * 2;
					if(distancePixels[i] < 100) count++;
				}
			}
			if (count > 800) { // More than half
				count_up++;
			}
		}
	}

	count_right = 0;
	for (int column = 0; column < 4; column++) {
		for (int row = 0; row < 12; row++) {
			int count = 0;
			for (int y = 0; y < 40; y++) {
				for (int x = 0; x < 40; x++) {
					int i = (row * 40 + y) * 640 + column * 40 + x + 160 * 3;
					if(distancePixels[i] < 100) count++;
				}
			}
			if (count > 800) { // More than half
				count_right++;
			}
		}
	}


	// For graphics
	grayImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
	unsigned char * pix = grayImage.getPixels();
	int numPixels = grayImage.getWidth() * grayImage.getHeight();
	for(int i = 0; i < numPixels; i++){
		if(distancePixels[i] < 100){
			pix[i] = 255;
		}else{
			pix[i] = 0;
		}
	}
}

//--------------------------------------------------------------
void testApp::draw()
{

	ofSetColor(255, 255, 0); // yellow
	grayImage.draw(0, 0, 640, 480);


	ofSetColor(155, 155, 255);
	char reportStr[1024];
	float *distancePixels = kinect.getDistancePixels();
	sprintf(
			reportStr,
			"L %d / D %d / U %d / R %d / dist[200] %f / fps: %f",
			count_left, count_down, count_up, count_right, distancePixels[200], ofGetFrameRate()
			);
	ofDrawBitmapString(reportStr, 10, 270);
}

//--------------------------------------------------------------
void testApp::exit(){
	kinect.close();
	kinect.clear();
}

//--------------------------------------------------------------
void testApp::keyPressed (int key)
{}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{}
