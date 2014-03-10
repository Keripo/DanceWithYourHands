LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := OFAndroidApp
LOCAL_SRC_FILES := testApp.cpp main.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../build/prebuilt/linux-x86/arm-eabi-4.4.0/arm-eabi/include/c++/4.4.0 \
			$(LOCAL_PATH)/../../../build/platforms/android-8/arch-arm/usr/include \
			$(LOCAL_PATH)/../../../build/prebuilt/linux-x86/arm-eabi-4.4.0/arm-eabi/include/c++/4.4.0/arm-eabi \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/openFrameworks \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/openFrameworks/app/ \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/openFrameworks/communication \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/openFrameworks/events \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/openFrameworks/graphics \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/openFrameworks/sound \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/openFrameworks/utils \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/freetype/include \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/freetype/include/freetype2 \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/glu/include_android \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/FreeImage/include \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/addons/ofxThread/src \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/addons/ofxVectorMath/src \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/addons/ofxOpenCv/src \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/poco/include \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/openFrameworks/video \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/addons/ofxOpenCv/src/ \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/addons/ofxOpenCv/libs/opencv/include_android/ \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/addons/ofxKinect/libs/includes/ \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/addons/ofxKinect/src/ \
			$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/addons/ofxAndroid/src

LOCAL_CXXFLAGS += -DANDROID -D__ANDROID__ -isystem $(SYSROOT)/usr/include
LOCAL_CFLAGS += -DANDROID -D__ANDROID__  $(LOCAL_C_INCLUDES:%=-I%)

LOCAL_LDLIBS := -L$(LOCAL_PATH)/../../../build/prebuilt/linux-x86/arm-eabi-4.4.0/arm-eabi/lib/ \
		-L$(LOCAL_PATH)/../../../build/platforms/android-8/arch-arm/usr/lib \
		-L$(LOCAL_PATH)/../../../build/prebuilt/linux-x86/arm-eabi-4.4.0/lib/gcc/arm-eabi/4.4.0/ \
		-L$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/openFrameworks/Debug/ \
		-L$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/addons/Debug/ \
		-L$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/poco/lib/android/ \
		-L$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/FreeImage/lib/android/ \
		-L$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/freetype/lib/android/ \
		-L$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/libs/glu/lib/android/ \
		-L$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/addons/ofxOpenCv/libs/opencv/lib/android \
		-L$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/addons/ofxOsc/libs/oscpack/lib/android/ \
		-L$(LOCAL_PATH)/../../../../of_preRelease_v0062_android_FAT/addons/ofxKinect/libs/ \
		-ldl -lstdc++ -lgcc -llog -lm -lc -laddons -loscpack -lopenFrameworks -lPocoUtil \
		-lPocoFoundation -lfreetype -lfreeimage -lcv -lcxcore -lopencv_lapack -lcvaux -lGLU -lz -lGLESv1_CM



include $(BUILD_SHARED_LIBRARY)

