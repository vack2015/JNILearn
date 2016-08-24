#include <jni.h>
#include <android/log.h>
#include <string.h>

JNIEXPORT void JNICALL Java_org_vackapi_jnilearn_JNILearn_test(JNIEnv *env,jobject instance){
    //__android_log_print(ANDROID_LOG_ERROR  , "ProjectName", "jni");
    __android_log_write(ANDROID_LOG_ERROR,"VACK","JNI");
}

JNIEXPORT jstring JNICALL Java_org_vackapi_jnilearn_JNILearn_stringFromJNI(JNIEnv *env,jobject instance){
    return (*env)->NewStringUTF(env,"hello from jni");
}

JNIEXPORT void JNICALL
Java_org_vackapi_jnilearn_JNILearn_show(JNIEnv *env, jobject instance) {
    // TODO
}