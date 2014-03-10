package org.of;

import android.app.Activity;
import android.os.Bundle;
import android.view.WindowManager;
import cc.openframeworks.OFAndroid;

public class OFsample extends Activity {
	@Override
    public void onCreate(Bundle savedInstanceState) { 
        super.onCreate(savedInstanceState);
        
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        
        String packageName = getPackageName();
        ofApp = new OFAndroid(getResources().getText(R.string.app_name).toString(),packageName,this);
        //setContentView(R.layout.main);
    }
	
	@Override
	public void onDetachedFromWindow() {
	}
	
    @Override
    protected void onPause() {
        super.onPause();
        ofApp.stop();
        OFAndroid.exit();
    }

    @Override
    protected void onResume() {
        super.onResume();
        ofApp.stop();
        OFAndroid.exit();
    }
	
	@Override
	protected void onDestroy() {
		super.onDestroy();
        ofApp.stop();
        OFAndroid.exit();
	}

	@Override
	protected void onRestart() {
		super.onRestart();
        ofApp.stop();
        OFAndroid.exit();
	}

	@Override
	protected void onStop() {
		super.onStop();
        ofApp.stop();
        OFAndroid.exit();

	}

	OFAndroid ofApp;
}