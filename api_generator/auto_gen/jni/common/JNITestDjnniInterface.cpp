// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from info.djinni

#include "JNITestDjnniInterface.h"  // my header
#include "JNITestInfoStore.h"
#include "Marshal.hpp"

namespace djinni_generated {

JNITestDjnniInterface::JNITestDjnniInterface() : ::djinni::JniInterface<::test::hello::TestDjnniInterface, JNITestDjnniInterface>("com/zhoumohan/djinni/gen/TestDjnniInterface$CppProxy") {}

JNITestDjnniInterface::~JNITestDjnniInterface() = default;


CJNIEXPORT void JNICALL Java_com_zhoumohan_djinni_gen_TestDjnniInterface_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::test::hello::TestDjnniInterface>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_com_zhoumohan_djinni_gen_TestDjnniInterface_00024CppProxy_native_1show(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_testInfo)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::test::hello::TestDjnniInterface>(nativeRef);
        auto r = ref->Show(::djinni_generated::JNITestInfoStore::toCpp(jniEnv, j_testInfo));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_com_zhoumohan_djinni_gen_TestDjnniInterface_00024CppProxy_newInstance(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::test::hello::TestDjnniInterface::NewInstance();
        return ::djinni::release(::djinni_generated::JNITestDjnniInterface::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated