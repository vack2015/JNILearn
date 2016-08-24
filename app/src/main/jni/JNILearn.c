#include <jni.h>
#include <android/log.h>
#include <string.h>
#include <stdio.h>

//                               数据类型
//                                     基本数据类型
//            java                  jni                   c/c++               大小
//           Boolean              Jboolean             unsigned char        无符号8位
//           Byte                 Jbyte                     char            有符号8位
//           Char                 Jchar                unsigned short       无符号16位
//           Short                Jshort                   short            有符号16位
//           Int                  Jint                      int             有符号32位
//           Long                 Jlong                   long long         有符号64位
//           Float                Jfloat                   float               32位
//           Double               Jdouble                  double              64位

//                                   引用数据类型
// 与基本数据类型不同引用数据类型对原生方法是不公开的
//             java类型                                         原生类型
//          java.lang.Class                                      jclass
//        java.lang.Throwable                                  jthrowable
//         java.lang.String                                      jstring
//           Other object                                        jobject
//        java.lang.Object[]                                   jobjectArray
//             boolean[]                                      jbooleanArray
//               byte[]                                         jbyteArray
//               char[]                                         jcharArray
//              short[]                                        jshortArray
//               int[]                                          jintArray
//              long[]                                         jlongArray
//              float[]                                        jfloatArray
//             double[]                                        jdoubleArray
//             Other array                                        Jarray
//


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
    //创建java
    jstring javaString=(*env)->NewStringUTF(env,"hello world");
    //把java字符串转换成c字符串
    jboolean isCopy;
    const jbyte *str=(*env)->GetStringUTFChars(env,javaString,&isCopy);
    if(str !=0){
        printf("Java String %s",str);
        __android_log_print(ANDROID_LOG_ERROR,"VACK",str);
        if(isCopy==JNI_TRUE){
            printf("C string is a copy of the Java String .");
            __android_log_write(ANDROID_LOG_ERROR,"VACK","C string is a copy of the Java String .");
        }else{
            printf("C string points to actual string .");
            __android_log_write(ANDROID_LOG_ERROR,"VACK","C string points to actual string .");
        }
        //使用完GetStringChars/GetStringCharUTF函数获得C字符串使用完后必须释放,否则容易引起内存泄漏
        (*env)->ReleaseStringChars(env,javaString,str);
    }
}