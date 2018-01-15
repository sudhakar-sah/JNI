#include <jni.h>
#include <iostream>
#include "HelloJNI.h"

using namespace std; 

// Implementation of native method sayHello() of HelloJNIclass 
JNIEXPORT jstring JNICALL Java_HelloJNI_sayHello  (JNIEnv *env, jobject thisObj, jint n1, jint n2, jstring inJNIStr) {

	int n3 = n1 + n2;
	const char *inStr = env->GetStringUTFChars( inJNIStr, NULL); 

	cout<<"Received string in C : "<< inStr; 


	cout << "Hello JNI working properly"<<endl;
	cout<< "Printing from C  = "<<n3<<endl; 
	
	char outCStr[128]; 
	printf("Enter a string :"); 
	scanf("%s", outCStr); 

	return env->NewStringUTF(outCStr); 
	
}


JNIEXPORT jdoubleArray JNICALL Java_HelloJNI_sumAndAverage
  (JNIEnv *, jobject, jintArray){
  	

  }


