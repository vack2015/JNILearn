#今天带来的是Android jni入门配置的代码
这里整合了我各种问题
1. 有意思的是gradle在2.0以上对ndk的支持不佳，于是就会出现c层代码红一屏幕的情况，，于是我们使用实验空间
即是 classpath "com.android.tools.build:gradle-experimental:0.7.0"和gradle-2.5-all，值得特别注意的是，build.gradle脚本语言会有所不同
2. 脚本语言有所不同，如果使用了不同版本的脚本语言，会有以下错误
3. 如果你配置完美，那么，如果你写了一个native方法，可以按alt+enter来创建c层代码，只是我创建后出现在h文件里，没关系贴过去就好了
4. native方法别写在内部类里面，不然会报错，如下
5. 在你完成c层代码后需要通过javah生成头文件，像我这边的具体命令：
cd app/src/main/java
javah -d ../jni org.vackapi.jnilearn.JNILearn
如果你不想在每次运行前都打一遍可以在setting-tools里面配置，如下
