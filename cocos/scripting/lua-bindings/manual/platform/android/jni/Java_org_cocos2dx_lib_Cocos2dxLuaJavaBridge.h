#ifndef COCOS2DX_SCRIPT_LUA_COCOS2DX_SUPPORT_PLATFORM_ANDROID_JNI_JAVA_ORG_COCOS2DX_LIB_COCOS2DX_LUA_JAVA_BRIDEG_H
#define COCOS2DX_SCRIPT_LUA_COCOS2DX_SUPPORT_PLATFORM_ANDROID_JNI_JAVA_ORG_COCOS2DX_LIB_COCOS2DX_LUA_JAVA_BRIDEG_H

#include <jni.h>

extern "C" {

/*
 * Class:     Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge
 * Method:    callLuaFunctionWithString
 * Signature: (ILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_callLuaFunctionWithString
  (JNIEnv *, jclass, jint, jstring);

/*
 * Class:     Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge
 * Method:    callLuaGlobalFunctionWithString
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_callLuaGlobalFunctionWithString
  (JNIEnv *env, jclass, jstring, jstring);

/*
 * Class:     Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge
 * Method:    retainLuaFunction
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_retainLuaFunction
  (JNIEnv *env, jclass, jint);

/*
 * Class:     Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge
 * Method:    releaseLuaFunction
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_releaseLuaFunction
  (JNIEnv *env, jclass, jint);

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_getLuaGlobalFunction
  (JNIEnv *env, jclass cls, jstring luaFunctionName);

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_executeFunction
  (JNIEnv *env, jclass cls, jint numargs, jint top);

JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_pushString
  (JNIEnv *env, jclass cls, jstring stringValue);

JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_pushInteger
  (JNIEnv *env, jclass cls, jint value);

JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_pushNumber
  (JNIEnv *env, jclass cls, jdouble value);

JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_pushNil
  (JNIEnv *env, jclass cls);

JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_pushBoolean
  (JNIEnv *env, jclass cls, jboolean value);

} // extern "C"

#endif // COCOS2DX_SCRIPT_LUA_COCOS2DX_SUPPORT_PLATFORM_ANDROID_JNI_JAVA_ORG_COCOS2DX_LIB_COCOS2DX_LUA_JAVA_BRIDEG_H
