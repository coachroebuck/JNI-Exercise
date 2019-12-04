#include <jni.h>

#ifndef PROJECT_MYJNI_H
#define PROJECT_MYJNI_H

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */);

JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_setCallback(
        JNIEnv* env,
        jobject /* this */,
        jobject /* callback */);

JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendBoolean(
        JNIEnv* env,
        jobject /* this */,
        jboolean /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendByte(
        JNIEnv* env,
        jobject /* this */,
        jbyte /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendChar(
        JNIEnv* env,
        jobject /* this */,
        jchar /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendShort(
        JNIEnv* env,
        jobject /* this */
        jshort /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendInt(
        JNIEnv* env,
        jobject /* this */,
        jint /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendLong(
        JNIEnv* env,
        jobject /* this */,
        jlong /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendFloat(
        JNIEnv* env,
        jobject /* this */,
        jfloat /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendDouble(
        JNIEnv* env,
        jobject /* this */,
        jdouble /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendString(
        JNIEnv* env,
        jobject /* this */,
        jobject /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendObject(
        JNIEnv* env,
        jobject /* this */,
        jobject /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendPerson(
        JNIEnv* env,
        jobject /* this */,
        jobject /* value */);

JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendBooleanArray(
        JNIEnv* env,
        jobject /* this */,
        jboolArray /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendByteArray(
        JNIEnv* env,
        jobject /* this */,
        jboolArray /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendCharArray(
        JNIEnv* env,
        jobject /* this */,
        jcharArray /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendShortArray(
        JNIEnv* env,
        jobject /* this */
        jshortArray /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendIntArray(
        JNIEnv* env,
        jobject /* this */,
        jintArray /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendLongArray(
        JNIEnv* env,
        jobject /* this */,
        jlongArray /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendFloatArray(
        JNIEnv* env,
        jobject /* this */,
        jfloatArray /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendDoubleArray(
        JNIEnv* env,
        jobject /* this */,
        jdoubleArray /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendDoubleArray(
        JNIEnv* env,
        jobject /* this */,
        jdoubleArray /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendStringArray(
        JNIEnv* env,
        jobject /* this */,
        jobjectArray /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendObjectArray(
        JNIEnv* env,
        jobject /* this */,
        jobjectArray /* value */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendPersonArray(
        JNIEnv* env,
        jobject /* this */,
        jobjectArray /* value */);

JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getBoolean
		JNIEnv* env,
        jobject /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getChar
		JNIEnv* env,
        jobject /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getShort
		JNIEnv* env,
        jobject /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getInt
		JNIEnv* env,
        jobject /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getByte
		JNIEnv* env,
        jobject /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getLong
		JNIEnv* env,
        jobject /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getFloat
		JNIEnv* env,
        jobject /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getDouble
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getStringFromJni
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getObject
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getPerson
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getBooleanArray
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getByteArray
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getCharArray
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getShortArray
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getIntArray
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getLongArray
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getFloatArray
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getDoubleArray
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getStringArray
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getObjectArray
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);
JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getPersonArray
		JNIEnv* env,
        jobject  /* this */,
        jobject /* callback */);

#ifdef __cplusplus
}
#endif

#endif //PROJECT_MYJNI_H