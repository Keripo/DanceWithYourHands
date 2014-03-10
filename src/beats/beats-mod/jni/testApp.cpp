#include "testApp.h"

void testApp::setup2()
{
	kinect.init();
	kinect.setUseRGBCamera(false);
	kinect.setVerbose(false);
	kinect.open();
}

void testApp::setThresh(int thresh)
{
	kinectThresh = thresh;
}

void testApp::update2()
{
	kinect.update();
	distancePixels = kinect.getDistancePixels();
	count_tap = 0;
	for (int column = 0; column < 4; column++) {
		for (int row = 3; row < 9; row++) {
			int count = 0;
			for (int y = 0; y < 40; y++) {
				for (int x = 0; x < 40; x++) {
					int i = (row * 40 + y) * 640 + column * 40 + x;
					if(distancePixels[i] < 100) count++;
				}
			}
			if (count > 800) { // More than half
				count_tap++;
			}
		}
	}
	if (count_tap > (kinectThresh * 3) / 4) {
		left = 1; // left
	} else {
		left = 0;
	}
	count_tap = 0;
	for (int column = 0; column < 4; column++) {
		for (int row = 3; row < 9; row++) {
			int count = 0;
			for (int y = 0; y < 40; y++) {
				for (int x = 0; x < 40; x++) {
					int i = (row * 40 + y) * 640 + column * 40 + x + 160 * 3;
					if(distancePixels[i] < 100) count++;
				}
			}
			if (count > 800) { // More than half
				count_tap++;
			}
		}
	}
	if (count_tap > (kinectThresh * 3) / 4) {
		right = 1;
	} else {
		right = 0;
	}
	count_tap = 0;
	for (int column = 0; column < 4; column++) {
		for (int row = 3; row < 9; row++) {
			int count = 0;
			for (int y = 0; y < 40; y++) {
				for (int x = 0; x < 40; x++) {
					int i = (row * 40 + y) * 640 + column * 40 + x + 160 * 1;
					if(distancePixels[i] < 100) count++;
				}
			}
			if (count > 800) { // More than half
				count_tap++;
			}
		}
	}
	if (count_tap > kinectThresh) {
		down = 1;
	} else {
		down = 0;
	}
	count_tap = 0;
	for (int column = 0; column < 4; column++) {
		for (int row = 3; row < 9; row++) {
			int count = 0;
			for (int y = 0; y < 40; y++) {
				for (int x = 0; x < 40; x++) {
					int i = (row * 40 + y) * 640 + column * 40 + x + 160 * 2;
					if(distancePixels[i] < 100) count++;
				}
			}
			if (count > 800) { // More than half
				count_tap++;
			}
		}
	}
	if (count_tap > kinectThresh) {
		up = 1;
	} else {
		up = 0;
	}
}

//--------------------------------------------------------------
void testApp::setup()
{}

//--------------------------------------------------------------
void testApp::update()
{}

//--------------------------------------------------------------
void testApp::draw()
{}

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
