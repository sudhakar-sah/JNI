#javac HelloJNI.java
#javah -jni HelloJNI
#g++ -c -I"/Applications/Android Studio.app/Contents/jre/jdk/Contents/Home/include/" -I"/Applications/Android Studio.app/Contents/jre/jdk/Contents/Home/include/darwin" HelloJNI.cpp
#g++ -dynamiclib -o libhello.jnilib HelloJNI.o

CLASS_PATH = ./bin
INCLUDE_PATH = "/Applications/Android Studio.app/Contents/jre/jdk/Contents/Home/include/"
INCLUDE_PATH1 = "/Applications/Android Studio.app/Contents/jre/jdk/Contents/Home/include/darwin"

GCC = g++
CFLAGS =-I


all : libhello.jnilib
# $@ matches the target , $<matches the first dependency 
libhello.jnilib : HelloJNI.o
		$(GCC) -Wall -dynamiclib -o $@ $<

# $@ matches the target an $< matches the first dependency 

HelloJNI.o : HelloJNI.cpp HelloJNI.h 
		$(GCC) $(CFLAGS)$(INCLUDE_PATH) $(CFLAGS)$(INCLUDE_PATH1) -c $< -o $@


# $* matches the target filename without the extension 

HelloJNI.h : HelloJNI.class
		javah -jni $* 

HelloJNI.class :
		javac HelloJNI.java

clean :
		rm HelloJNI.h HelloJNI.o libhello.jnilib 
		rm HelloJNI.class  