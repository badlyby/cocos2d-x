
#include "Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge.h"

#include <android/log.h>

#include "CCLuaJavaBridge.h"

#define  LOG_TAG    "Cocos2dxLuaJavaBridge_java"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

extern "C" {

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_callLuaFunctionWithString
  (JNIEnv *env, jclass cls, jint functionId, jstring value)
{
    const char *value_ = env->GetStringUTFChars(value, 0);
    int ret = LuaJavaBridge::callLuaFunctionById(functionId, value_);
    env->ReleaseStringUTFChars(value, value_);
    return ret;
}

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_callLuaGlobalFunctionWithString
  (JNIEnv *env, jclass cls, jstring luaFunctionName, jstring value)
{
    const char *luaFunctionName_ = env->GetStringUTFChars(luaFunctionName, 0);
    const char *value_ = env->GetStringUTFChars(value, 0);
    int ret = LuaJavaBridge::callLuaGlobalFunction(luaFunctionName_, value_);
    env->ReleaseStringUTFChars(luaFunctionName, luaFunctionName_);
    env->ReleaseStringUTFChars(value, value_);
    return ret;
}

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_retainLuaFunction
  (JNIEnv *env, jclass cls, jint luaFunctionId)
{
    return LuaJavaBridge::retainLuaFunctionById(luaFunctionId);
}

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_releaseLuaFunction
  (JNIEnv *env, jclass cls, jint luaFunctionId)
{
    return LuaJavaBridge::releaseLuaFunctionById(luaFunctionId);
}

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_getLuaGlobalFunction
  (JNIEnv *env, jclass cls, jstring luaFunctionName)
{
    const char *luaFunctionName_ = env->GetStringUTFChars(luaFunctionName, 0);
    int ret = LuaJavaBridge::getLuaGlobalFunction(luaFunctionName_);
    env->ReleaseStringUTFChars(luaFunctionName, luaFunctionName_);
    return ret;
}

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_executeFunction
  (JNIEnv *env, jclass cls, jint numargs, jint top)
{
    int ret = LuaJavaBridge::executeFunction(numargs, top);
    return ret;
}

JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_pushString
  (JNIEnv *env, jclass cls, jstring stringValue)
{
    const char *value = env->GetStringUTFChars(stringValue, 0);
    int len = env->GetStringUTFLength(stringValue);
    LuaJavaBridge::pushString(value,len);
    env->ReleaseStringUTFChars(stringValue, value);
}

JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_pushInteger
  (JNIEnv *env, jclass cls, jint value)
{
    LuaJavaBridge::pushInteger(value);
}

JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_pushNumber
  (JNIEnv *env, jclass cls, jdouble value)
{
    LuaJavaBridge::pushNumber(value);
}

JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_pushNil
  (JNIEnv *env, jclass cls)
{
    LuaJavaBridge::pushNil();
}

JNIEXPORT void JNICALL Java_org_cocos2dx_lib_Cocos2dxLuaJavaBridge_pushBoolean
  (JNIEnv *env, jclass cls, jboolean value)
{
    LuaJavaBridge::pushBoolean(value);
}

} // extern "C"
