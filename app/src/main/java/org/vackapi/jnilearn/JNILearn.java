package org.vackapi.jnilearn;

/**
 * Created by Administrator on 2016/8/23.
 */
public class JNILearn{
    static {
        System.loadLibrary("JNILearn");
    }
    public native void test();
    public native String stringFromJNI();
    public native void show();
}
