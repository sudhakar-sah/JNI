javac HelloJNI.java
javah -jni HelloJNI
g++ -c -I"/Applications/Android Studio.app/Contents/jre/jdk/Contents/Home/include/" -I"/Applications/Android Studio.app/Contents/jre/jdk/Contents/Home/include/darwin" HelloJNI.cpp
g++ -dynamiclib -o libhello.jnilib HelloJNI.o
