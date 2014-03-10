#include "ofMain.h"
#include "testApp.h"
#include <jni.h>
#include "ofAppAndroidWindow.h"

//========================================================================
extern "C"{
testApp *kinectApp;

// UNUSED
void Java_cc_openframeworks_OFAndroid_init( JNIEnv*  env, jobject  thiz ){
}

void Java_cc_openframeworks_OFAndroid_setup2( JNIEnv*  env, jobject  thiz ){
	kinectApp = new testApp();
	kinectApp->setup2();
}

void Java_cc_openframeworks_OFAndroid_setThresh( JNIEnv*  env, jobject  thiz, jint thresh){
	kinectApp->setThresh(thresh);
}

void Java_cc_openframeworks_OFAndroid_update2( JNIEnv*  env, jobject  thiz, jint thresh){
	kinectApp->update2();
}

JNIEXPORT
jint
JNICALL Java_cc_openframeworks_OFAndroid_left( JNIEnv*  env, jobject  thiz, jint thresh){
	return kinectApp->left;
}

JNIEXPORT
jint
JNICALL Java_cc_openframeworks_OFAndroid_down( JNIEnv*  env, jobject  thiz, jint thresh){
	return kinectApp->down;
}

JNIEXPORT
jint
JNICALL Java_cc_openframeworks_OFAndroid_up( JNIEnv*  env, jobject  thiz, jint thresh){
	return kinectApp->up;
}

JNIEXPORT
jint
JNICALL Java_cc_openframeworks_OFAndroid_right( JNIEnv*  env, jobject  thiz, jint thresh){
	return kinectApp->right;
}

}

// UNUSED
int main(){
	return 0;
}
