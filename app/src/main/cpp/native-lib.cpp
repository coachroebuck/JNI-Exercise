#include <jni.h>
#include <string>
#include <cstdio>
#include <vector>
#include <android/log.h>

#define CALLBACK_CLASS_NAME "com/ancestry/jniexcercise/MainActivity$onCreate$1"
#define TAG "JNI"

#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG,__VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG  , TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO   , TAG,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN   , TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , TAG,__VA_ARGS__)

bool javaToC(jboolean value) {
    return (bool)(value != JNI_FALSE);
}
jboolean cToJava(bool value) {
    return (jboolean)(value == true);
}

unsigned char javaToC(jbyte value) {
    return (unsigned char)value;
}
jbyte cToJava(unsigned char value) {
    return (jbyte)value;
}

char javaToC(jchar value) {
    return (char)value;
}
jchar cToJava(char value) {
    return (jchar)value;
}

short javaToC(jshort value) {
    return (short)value;
}
jshort cToJava(short value) {
    return (jshort)value;
}

int javaToC(jint value) {
    return (int)value;
}
jint cToJava(int value) {
    return (jint)value;
}

int64_t jlongToLong(jlong value) {
    return (int64_t)value;
}
jlong longToJlong(long value) {
    return (jlong)value;
}

double javaToC(jdouble value) {
    return (double)value;
}
jdouble cToJava(double value) {
    return (jdouble)value;
}

float javaToC(jfloat value) {
    return (float)value;
}
jfloat cToJava(float value) {
    return (jfloat)value;
}
std::string jstring2string(JNIEnv *env, jstring jStr) {
    if (!jStr)
        return "";

    const jclass stringClass = env->GetObjectClass(jStr);
    const jmethodID getBytes = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    const jbyteArray stringJbytes = (jbyteArray) env->CallObjectMethod(jStr, getBytes, env->NewStringUTF("UTF-8"));

    size_t length = (size_t) env->GetArrayLength(stringJbytes);
    jbyte* pBytes = env->GetByteArrayElements(stringJbytes, NULL);

    std::string ret = std::string((char *)pBytes, length);
    env->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);

    env->DeleteLocalRef(stringJbytes);
    env->DeleteLocalRef(stringClass);
    return ret;
}
std::string getClassName(JNIEnv *env, jobject entity, jclass clazz)
{
    jmethodID mid = env->GetMethodID(clazz, "getClass", "()Ljava/lang/Class;");
    jobject clsObj = env->CallObjectMethod(entity, mid);
    jclass clazzz = env->GetObjectClass(clsObj);
    mid = env->GetMethodID(clazzz, "getName", "()Ljava/lang/String;");
    jstring strObj = (jstring)env->CallObjectMethod(clsObj, mid);

    const char* str = env->GetStringUTFChars(strObj, NULL);
    std::string res(str);

    env->ReleaseStringUTFChars(strObj, str);

    return res;
}
jobject createNewPerson(JNIEnv *env, std::string origFirstName, std::string origLastName) {
    jstring firstName = env->NewStringUTF(origFirstName.c_str());
    jstring lastName = env->NewStringUTF(origLastName.c_str());

    jclass clazz = env->FindClass("com/ancestry/jniexcercise/Person");
    jmethodID methodId = env->GetMethodID(clazz, "<init>", "()V");
    jobject value = env->NewObject(clazz, methodId);

    jfieldID fieldId = env->GetFieldID(clazz, "firstName", "Ljava/lang/String;");
    env->SetObjectField(value, fieldId, firstName);

    fieldId = env->GetFieldID( clazz, "lastName", "Ljava/lang/String;");
    env->SetObjectField(value, fieldId, lastName);

    return value;
}
void freePerson(JNIEnv *env, jobject value) {
    jclass clazz = env->GetObjectClass(value);

    jfieldID fieldId = env->GetFieldID(clazz, "firstName", "Ljava/lang/String;");
    jobject name = env->GetObjectField(value, fieldId);
    env->DeleteLocalRef(name);

    fieldId = env->GetFieldID( clazz, "lastName", "Ljava/lang/String;");
    name = env->GetObjectField(value, fieldId);
    env->DeleteLocalRef(name);

    env->DeleteLocalRef(value);
}

static jobject gCallback = 0;
static jclass callbackClass = 0;

extern "C" JNIEXPORT jstring JNICALL Java_com_ancestry_jniexcercise_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_setCallback(
        JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
            //callbackClass = env->GetObjectClass(callback);
            //gCallback = callback;

            std::string className = getClassName(env, callback, env->GetObjectClass(callback));
            LOGV("className=%s", className.c_str());
        }

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendBoolean(
        JNIEnv* env,
        jobject thisObject /* this */,
        jboolean value /* value */) {
    bool converted = cToJava(value);
    LOGV("sendBoolean(): converted=[%d]", converted);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendByte(
        JNIEnv* env,
        jobject thisObject /* this */,
        jbyte value /* value */) {
    unsigned char converted = cToJava(value);
    LOGV("sendByte(): converted=[%c]", converted);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendChar(
        JNIEnv* env,
        jobject thisObject /* this */,
        jchar value /* value */) {
    char converted = cToJava(value);
    LOGV("sendChar(): converted=[%c]", converted);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendShort(
        JNIEnv* env,
        jobject thisObject /* this */,
        jshort value /* value */) {
    short converted = cToJava(value);
    LOGV("sendShort(): converted=[%hi]", converted);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendInt(
        JNIEnv* env,
        jobject thisObject /* this */,
        jint value /* value */) {
    int converted = cToJava(value);
    LOGV("sendInt(): converted=[%i]", converted);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendLong(
        JNIEnv* env,
        jobject thisObject /* this */,
        jlong value /* value */) {
    long converted = jlongToLong(value);
    LOGV("sendLong(): converted=[%ld]", converted);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendFloat(
        JNIEnv* env,
        jobject thisObject /* this */,
        jfloat value /* value */) {
    float converted = cToJava(value);
    LOGV("sendFloat(): converted=[%f]", converted);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendDouble(
        JNIEnv* env,
        jobject thisObject /* this */,
        jdouble value /* value */) {
    double converted = cToJava(value);
    LOGV("sendDouble(): converted=[%f]", converted);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendString(
        JNIEnv* env,
        jobject thisObject /* this */,
        jstring value /* value */) {
        std::string converted = jstring2string(env, value);
    LOGV("sendString(): converted=[%s]", converted.c_str());
        }

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendObject(
        JNIEnv* env,
        jobject thisObject /* this */,
        jobject value /* value */) {
            std::string className = getClassName(env, value, env->GetObjectClass(value));
            LOGV("sendObject(): className=%s", className.c_str());
         }

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendPerson(
        JNIEnv* env,
        jobject thisObject /* this */,
        jobject value /* value */) {
            std::string className = getClassName(env, value, env->GetObjectClass(value));
            LOGV("sendPerson(): className=%s", className.c_str());
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendBooleanArray(
        JNIEnv* env,
        jobject thisObject /* this */,
        jbooleanArray value /* value */) {
        std::vector<bool> converted;
        int size = env->GetArrayLength(value);
        jboolean * elements = env->GetBooleanArrayElements(value,NULL);

       for (int i = 0; i < size; i++) {
           bool nextConversion = javaToC(elements[i]);
           converted.push_back(nextConversion);
           LOGV("sendBooleanArray(): index=[%d] converted=[%d]", i, nextConversion);
       }

       env->ReleaseBooleanArrayElements(value, elements, 0);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendByteArray(
        JNIEnv* env,
        jobject thisObject /* this */,
        jbyteArray value /* value */) {
        std::vector<unsigned char> converted;
        int size = env->GetArrayLength(value);
        jbyte * elements = env->GetByteArrayElements(value,NULL);

       for (int i = 0; i < size; i++) {
           unsigned char nextConversion = javaToC(elements[i]);
           converted.push_back(nextConversion);
           LOGV("sendByteArray(): index=[%d] converted=[%c]", i, nextConversion);
       }

       env->ReleaseByteArrayElements(value, elements, 0);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendCharArray(
        JNIEnv* env,
        jobject thisObject /* this */,
        jcharArray value /* value */) {
        std::vector<char> converted;
        int size = env->GetArrayLength(value);
        jchar * elements = env->GetCharArrayElements(value,NULL);

       for (int i = 0; i < size; i++) {
           char nextConversion = javaToC(elements[i]);
           converted.push_back(nextConversion);
           LOGV("sendCharArray(): index=[%d] converted=[%c]", i, nextConversion);
       }

       env->ReleaseCharArrayElements(value, elements, 0);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendShortArray(
        JNIEnv* env,
        jobject thisObject /* this */,
        jshortArray value /* value */) {
        std::vector<short> converted;
        int size = env->GetArrayLength(value);
        jshort * elements = env->GetShortArrayElements(value,NULL);

       for (int i = 0; i < size; i++) {
           short nextConversion = javaToC(elements[i]);
           converted.push_back(nextConversion);
           LOGV("sendShortArray(): index=[%d] converted=[%hi]", i, nextConversion);
       }

       env->ReleaseShortArrayElements(value, elements, 0);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendIntArray(
        JNIEnv* env,
        jobject thisObject /* this */,
        jintArray value /* value */) {
        std::vector<int> converted;
        int size = env->GetArrayLength(value);
        jint * elements = env->GetIntArrayElements(value,NULL);

       for (int i = 0; i < size; i++) {
           int nextConversion = javaToC(elements[i]);
           converted.push_back(nextConversion);
           LOGV("sendIntArray(): index=[%d] converted=[%i]", i, nextConversion);
       }

       env->ReleaseIntArrayElements(value, elements, 0);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendLongArray(
        JNIEnv* env,
        jobject thisObject /* this */,
        jlongArray value /* value */) {
        std::vector<long> converted;
        int size = env->GetArrayLength(value);
        jlong * elements = env->GetLongArrayElements(value,NULL);

       for (int i = 0; i < size; i++) {
           long nextConversion = jlongToLong(elements[i]);
           converted.push_back(nextConversion);
           LOGV("sendLongArray(): index=[%d] converted=[%ld]", i, nextConversion);
       }

       env->ReleaseLongArrayElements(value, elements, 0);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendFloatArray(
        JNIEnv* env,
        jobject thisObject /* this */,
        jfloatArray value /* value */) {
        std::vector<float> converted;
        int size = env->GetArrayLength(value);
        jfloat * elements = env->GetFloatArrayElements(value,NULL);

       for (int i = 0; i < size; i++) {
           float nextConversion = javaToC(elements[i]);
           converted.push_back(nextConversion);
           LOGV("sendFloatArray(): index=[%d] converted=[%f]", i, nextConversion);
       }

       env->ReleaseFloatArrayElements(value, elements, 0);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendDoubleArray(
        JNIEnv* env,
        jobject thisObject /* this */,
        jdoubleArray value /* value */) {
        std::vector<double> converted;
        int size = env->GetArrayLength(value);
        jdouble * elements = env->GetDoubleArrayElements(value,NULL);

       for (int i = 0; i < size; i++) {
           double nextConversion = javaToC(elements[i]);
           converted.push_back(nextConversion);
           LOGV("sendDoubleArray(): index=[%d] converted=[%f]", i, nextConversion);
       }

       env->ReleaseDoubleArrayElements(value, elements, 0);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendStringArray(
        JNIEnv* env,
        jobject thisObject /* this */,
        jobjectArray value /* value */) {
    std::vector<std::string> converted;

    std::string className = getClassName(env, value, env->GetObjectClass(value));
    LOGV("sendStringArray(): className=%s", className.c_str());

    int len = env->GetArrayLength(value);
    
    for (int i=0; i<len; i++) {
        // Cast array element to string
        jstring jstr = (jstring) (env->GetObjectArrayElement(value, i));
        std::string nextConversion = jstring2string(env, jstr);
        LOGV("sendStringArray(): index=[%d] converted=[%s]", i, nextConversion.c_str());
        converted.push_back(nextConversion);
        env->DeleteLocalRef(jstr);
    }        
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendObjectArray(
        JNIEnv* env,
        jobject thisObject /* this */,
        jobjectArray value /* value */) {
    //std::vector<std::string> converted;

    std::string className = getClassName(env, value, env->GetObjectClass(value));
    LOGV("sendObjectArray(): className=%s", className.c_str());

    int len = env->GetArrayLength(value);

    for (int i=0; i<len; i++) {
        // Cast array element to string
        jobject nextObject = (jobject) (env->GetObjectArrayElement(value, i));

        std::string nextClassName = getClassName(env, nextObject, env->GetObjectClass(nextObject));
        LOGV("sendObjectArray(): index=[%d] className=[%s]", i, nextClassName.c_str());
        //converted.push_back(nextConversion);
        env->DeleteLocalRef(nextObject);
    }
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_sendPersonArray(
        JNIEnv* env,
        jobject thisObject /* this */,
        jobjectArray value /* value */) {
    //std::vector<std::string> converted;

    std::string className = getClassName(env, value, env->GetObjectClass(value));
    LOGV("sendPersonArray(): className=%s", className.c_str());

    int len = env->GetArrayLength(value);

    for (int i=0; i<len; i++) {
        // Cast array element to string
        jobject nextObject = (jobject) (env->GetObjectArrayElement(value, i));

        std::string nextClassName = getClassName(env, nextObject, env->GetObjectClass(nextObject));
        LOGV("sendPersonArray(): index=[%d] className=[%s]", i, nextClassName.c_str());
        //converted.push_back(nextConversion);
        env->DeleteLocalRef(nextObject);
    }
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getBoolean(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
            jboolean value = cToJava(true);
            jclass clazz = env->GetObjectClass(callback);
            jmethodID methodId = env->GetMethodID(clazz, "onBoolean", "(Z)V");
            env->CallVoidMethod(callback, methodId, value);
            env->DeleteLocalRef(clazz);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getChar(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
            jchar value = cToJava('W');
            jclass clazz = env->GetObjectClass(callback);
            jmethodID methodId = env->GetMethodID(clazz, "onChar", "(C)V");
            env->CallVoidMethod(callback, methodId, value);
            env->DeleteLocalRef(clazz);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getShort(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
            jshort value = cToJava(0x66);
            jclass clazz = env->GetObjectClass(callback);
            jmethodID methodId = env->GetMethodID(clazz, "onShort", "(S)V");
            env->CallVoidMethod(callback, methodId, value);
            env->DeleteLocalRef(clazz);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getInt(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
            jint value = cToJava(255);
            jclass clazz = env->GetObjectClass(callback);
            jmethodID methodId = env->GetMethodID(clazz, "onInt", "(I)V");
            env->CallVoidMethod(callback, methodId, value);
            env->DeleteLocalRef(clazz);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getByte(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
            jbyte value = cToJava(0x64);
            jclass clazz = env->GetObjectClass(callback);
            jmethodID methodId = env->GetMethodID(clazz, "onByte", "(B)V");
            env->CallVoidMethod(callback, methodId, value);
            env->DeleteLocalRef(clazz);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getLong(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
            jlong value = longToJlong(6400L);
            jclass clazz = env->GetObjectClass(callback);
            jmethodID methodId = env->GetMethodID(clazz, "onLong", "(J)V");
            env->CallVoidMethod(callback, methodId, value);
            env->DeleteLocalRef(clazz);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getFloat(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
            jfloat value = cToJava(9100.0f);
            jclass clazz = env->GetObjectClass(callback);
            jmethodID methodId = env->GetMethodID(clazz, "onFloat", "(F)V");
            env->CallVoidMethod(callback, methodId, value);
            env->DeleteLocalRef(clazz);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getDouble(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
            jdouble value = cToJava(32768.0);
            jclass clazz = env->GetObjectClass(callback);
            jmethodID methodId = env->GetMethodID(clazz, "onDouble", "(D)V");
            env->CallVoidMethod(callback, methodId, value);
            env->DeleteLocalRef(clazz);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getStringFromJni(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
    std::string hello = "Hello from C++";
    jstring value = env->NewStringUTF(hello.c_str());
    jclass clazz = env->GetObjectClass(callback);
    jmethodID methodId = env->GetMethodID(clazz, "onString", "(Ljava/lang/String;)V");
    env->CallVoidMethod(callback, methodId, value);
            env->DeleteLocalRef(clazz);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getObject(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
        jmethodID methodId;
        jfieldID fieldId;
        jstring jstr;
        const char *cString;

    std::string origFirstName = "Michael";
    std::string origLastName = "Roebuck";
    jstring firstName = env->NewStringUTF(origFirstName.c_str());
    jstring lastName = env->NewStringUTF(origLastName.c_str());

    jclass clazz = env->FindClass("com/ancestry/jniexcercise/Person");
    methodId = env->GetMethodID(clazz, "<init>", "()V");
    jobject value = env->NewObject(clazz, methodId);

    fieldId = env->GetFieldID(clazz, "firstName", "Ljava/lang/String;");
    env->SetObjectField(value, fieldId, firstName);

    fieldId = env->GetFieldID( clazz, "lastName", "Ljava/lang/String;");
    env->SetObjectField(value, fieldId, lastName);

    clazz = env->GetObjectClass(callback);
    methodId = env->GetMethodID(clazz, "onObject", "(Ljava/lang/Object;)V");
    env->CallVoidMethod(callback, methodId, value);
    env->DeleteLocalRef(clazz);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getPerson(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {

    jobject value = createNewPerson(env, "Michael", "Roebuck");

    jclass clazz = env->GetObjectClass(callback);
    jmethodID methodId = env->GetMethodID(clazz, "onPerson", "(Lcom/ancestry/jniexcercise/Person;)V");
    env->CallVoidMethod(callback, methodId, value);
    env->DeleteLocalRef(clazz);

    freePerson(env, value);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getBooleanArray(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
    bool original[] = {true, false, false, true, true, true, false};
    int size = (sizeof(original)/sizeof(*original));
    jbooleanArray value = env->NewBooleanArray(size);
    jboolean * elements = env->GetBooleanArrayElements(value,NULL);

   for (int i = 0; i < size; i++) {
       elements[i] = original[i];
   }

    env->SetBooleanArrayRegion(value, 0, size, elements);

    jclass clazz = env->GetObjectClass(callback);
    jmethodID methodId = env->GetMethodID(clazz, "onBooleanArray", "([Z)V");
    env->CallVoidMethod(callback, methodId, value);
    
    env->DeleteLocalRef(clazz);
    env->ReleaseBooleanArrayElements(value, elements, 0);
        }

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getByteArray(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
    unsigned char original[] = {2,4,6,8,10,12,14};
    int size = (sizeof(original)/sizeof(*original));
    jbyteArray value = env->NewByteArray(size);
    jbyte * elements = env->GetByteArrayElements(value,NULL);

   for (int i = 0; i < size; i++) {
       elements[i] = original[i];
   }

    env->SetByteArrayRegion(value, 0, size, elements);

    jclass clazz = env->GetObjectClass(callback);
    jmethodID methodId = env->GetMethodID(clazz, "onByteArray", "([B)V");
    env->CallVoidMethod(callback, methodId, value);

    env->DeleteLocalRef(clazz);
    env->ReleaseByteArrayElements(value, elements, 0);
        }

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getCharArray(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
    char original[] = {'a', 'b', 'c', 'd', 'E', 'F', 'G'};
    int size = (sizeof(original)/sizeof(*original));
    jcharArray value = env->NewCharArray(size);
    jchar * elements = env->GetCharArrayElements(value,NULL);

   for (int i = 0; i < size; i++) {
       elements[i] = original[i];
   }

    env->SetCharArrayRegion(value, 0, size, elements);

    jclass clazz = env->GetObjectClass(callback);
    jmethodID methodId = env->GetMethodID(clazz, "onCharArray", "([C)V");
    env->CallVoidMethod(callback, methodId, value);

    env->DeleteLocalRef(clazz);
    env->ReleaseCharArrayElements(value, elements, 0);
        }

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getShortArray(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
    short original[] = {2,4,6,8,10,12,14};
    int size = (sizeof(original)/sizeof(*original));
    jshortArray value = env->NewShortArray(size);
    jshort * elements = env->GetShortArrayElements(value,NULL);

   for (int i = 0; i < size; i++) {
       elements[i] = original[i];
   }

    env->SetShortArrayRegion(value, 0, size, elements);
    jclass clazz = env->GetObjectClass(callback);
    jmethodID methodId = env->GetMethodID(clazz, "onShortArray", "([S)V");
    env->CallVoidMethod(callback, methodId, value);

    env->DeleteLocalRef(clazz);
    env->ReleaseShortArrayElements(value, elements, 0);
        }

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getIntArray(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
    int original[] = {2,4,6,8,10,12,14};
    int size = (sizeof(original)/sizeof(*original));
    jintArray value = env->NewIntArray(size);
    jint * elements = env->GetIntArrayElements(value,NULL);

   for (int i = 0; i < size; i++) {
       elements[i] = original[i];
   }

    env->SetIntArrayRegion(value, 0, size, elements);

    jclass clazz = env->GetObjectClass(callback);
    jmethodID methodId = env->GetMethodID(clazz, "onIntArray", "([I)V");
    env->CallVoidMethod(callback, methodId, value);

    env->DeleteLocalRef(clazz);
    env->ReleaseIntArrayElements(value, elements, 0);
        }

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getLongArray(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
    long original[] = {158L, 358L, 3942L, 8473L};
    int size = (sizeof(original)/sizeof(*original));
    jlongArray value = env->NewLongArray(size);
    jlong * elements = env->GetLongArrayElements(value,NULL);

   for (int i = 0; i < size; i++) {
       elements[i] = original[i];
   }

    env->SetLongArrayRegion(value, 0, size, elements);

    jclass clazz = env->GetObjectClass(callback);
    jmethodID methodId = env->GetMethodID(clazz, "onLongArray", "([J)V");
    env->CallVoidMethod(callback, methodId, value);

    env->DeleteLocalRef(clazz);
    env->ReleaseLongArrayElements(value, elements, 0);
        }

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getFloatArray(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
    float original[] = {293.303f, 238.25f, 3498.3f, 30487.25f, 27272.0f};
    int size = (sizeof(original)/sizeof(*original));
    jfloatArray value = env->NewFloatArray(size);
    jfloat * elements = env->GetFloatArrayElements(value,NULL);

   for (int i = 0; i < size; i++) {
       elements[i] = original[i];
   }

    env->SetFloatArrayRegion(value, 0, size, elements);

    jclass clazz = env->GetObjectClass(callback);
    jmethodID methodId = env->GetMethodID(clazz, "onFloatArray", "([F)V");
    env->CallVoidMethod(callback, methodId, value);

    env->DeleteLocalRef(clazz);
    env->ReleaseFloatArrayElements(value, elements, 0);
        }

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getDoubleArray(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
    double original[] = {-102.0, 838.0, 382.0, -2838.0, -293.383};
    int size = (sizeof(original)/sizeof(*original));
    jdoubleArray value = env->NewDoubleArray(size);
    jdouble * elements = env->GetDoubleArrayElements(value,NULL);

   for (int i = 0; i < size; i++) {
       elements[i] = original[i];
   }

    env->SetDoubleArrayRegion(value, 0, size, elements);

    jclass clazz = env->GetObjectClass(callback);
    jmethodID methodId = env->GetMethodID(clazz, "onDoubleArray", "([D)V");
    env->CallVoidMethod(callback, methodId, value);

    env->DeleteLocalRef(clazz);
    env->ReleaseDoubleArrayElements(value, elements, 0);
        }

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getStringArray(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
        std::string original[] = {"Regina", "Snape", "Roebuck"};
        int size = (sizeof(original)/sizeof(*original));
        jobjectArray value = env->NewObjectArray(size, env->FindClass("java/lang/String"), nullptr);

        for (int i = 0; i < size; ++i) {
            env->SetObjectArrayElement(value, i, env->NewStringUTF(original[i].c_str()));
        }

    jclass clazz = env->GetObjectClass(callback);
    jmethodID methodId = env->GetMethodID(clazz, "onStringArray", "([Ljava/lang/String;)V");
    env->CallVoidMethod(callback, methodId, value);

    env->DeleteLocalRef(clazz);

    for (int i = 0; i < size; ++i) {
        jstring string = (jstring)env->GetObjectArrayElement(value, i);
        env->DeleteLocalRef(string);
    }
    env->DeleteLocalRef(value);
}

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getObjectArray(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
        int size = 3;
        jobjectArray value = env->NewObjectArray(size, env->FindClass("com/ancestry/jniexcercise/Person"), nullptr);

        for (int i = 0; i < size; ++i) {
            jobject nextValue = createNewPerson(env, "Michael", "Roebuck");
            env->SetObjectArrayElement(value, i, nextValue);
        }

    jclass clazz = env->GetObjectClass(callback);
    jmethodID methodId = env->GetMethodID(clazz, "onObjectArray", "([Ljava/lang/Object;)V");
    env->CallVoidMethod(callback, methodId, value);

    env->DeleteLocalRef(clazz);

    for (int i = 0; i < size; ++i) {
        jobject nextObject = (jobject)env->GetObjectArrayElement(value, i);
        freePerson(env, nextObject);
    }

    env->DeleteLocalRef(value);
        }

extern "C" JNIEXPORT void JNICALL Java_com_ancestry_jniexcercise_MainActivity_getPersonArray(
		JNIEnv* env,
        jobject thisObject /* this */,
        jobject callback /* callback */) {
        int size = 3;
        jobjectArray value = env->NewObjectArray(size, env->FindClass("com/ancestry/jniexcercise/Person"), nullptr);

        for (int i = 0; i < size; ++i) {
            jobject nextValue = createNewPerson(env, "Michael", "Roebuck");
            env->SetObjectArrayElement(value, i, nextValue);
        }

    jclass clazz = env->GetObjectClass(callback);
    jmethodID methodId = env->GetMethodID(clazz, "onPersonArray", "([Lcom/ancestry/jniexcercise/Person;)V");
    env->CallVoidMethod(callback, methodId, value);

    env->DeleteLocalRef(clazz);

    for (int i = 0; i < size; ++i) {
        jobject nextObject = (jobject)env->GetObjectArrayElement(value, i);
        freePerson(env, nextObject);
    }

    env->DeleteLocalRef(value);
}