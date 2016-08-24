#今天带来的是Android jni入门配置的代码
这里整合了我各种问题

1. 有意思的是gradle在2.0以上对ndk的支持不佳，于是就会出现c层代码红一屏幕的情况，，于是我们使用实验空间
即是 classpath "com.android.tools.build:gradle-experimental:0.7.0"和gradle-2.5-all，值得特别注意的是，build.gradle脚本语言会有所不同
![gradle2.0+对ndk支持不佳](https://github.com/vack2015/JNILearn/blob/master/img/gradle2.0%2B%E6%94%AF%E6%8C%81%E4%B8%8D%E4%BD%B3.png)
2. 脚本语言有所不同，如果使用了不同版本的脚本语言，会有以下错误
![注意这类错误，其实是脚本语言不对](https://github.com/vack2015/JNILearn/blob/master/img/%E6%B3%A8%E6%84%8F%E8%BF%99%E7%B1%BB%E9%94%99%E8%AF%AF.png)
3. 如果你配置完美，那么，如果你写了一个native方法，可以按alt+enter来创建c层代码，  
只是我创建后出现在h文件里，没关系贴过去就好了
4. native方法别写在内部类里面，不然会报错，如下
![native方法别放在内部类里面，不然会让你怀疑人生](https://github.com/vack2015/JNILearn/blob/master/img/native%E4%B8%8D%E5%BA%94%E5%86%99%E5%9C%A8%E5%86%85%E9%83%A8%E7%B1%BB.png)
5. 在你完成c层代码后需要通过javah生成头文件，像我这边的具体命令：
cd app/src/main/java  
javah -d ../jni org.vackapi.jnilearn.JNILearn
如果你不想在每次运行前都打一遍可以在setting-tools里面配置，如下
![这样配置](https://github.com/vack2015/JNILearn/blob/master/img/%E5%A6%82%E6%9E%9C%E4%B8%8D%E6%83%B3%E6%AF%8F%E6%AC%A1%E9%83%BD%E5%9C%A8%E5%91%BD%E4%BB%A4%E8%A1%8C%E6%89%93javah.png)
让后Build-Make Project就可以自动帮你执行一遍了  
name   Generate JNI Header File   
program   javah  
parameters   -d src\main\jni\ -bootclasspath $ModuleSdkPath$\platforms\android-23\android.jar -classpath build\intermediates\classes\debug $FileClass$  
working directory  $ModuleFileDir$
7. 其实我不知道在androidStudio里面怎么看printf的内容  
8. 如果你想在上班之余问问题,划划水扣扣群:537610843
