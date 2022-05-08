// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from info.djinni

#pragma once

#include "djinni_support.hpp"
#include "test_info_store.h"

namespace djinni_generated {

class JNITestInfoStore final {
public:
    using CppType = ::test::hello::TestInfoStore;
    using JniType = jobject;

    using Boxed = JNITestInfoStore;

    ~JNITestInfoStore();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    JNITestInfoStore();
    friend ::djinni::JniClass<JNITestInfoStore>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/zhoumohan/djinni/gen/TestInfoStore") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(ILjava/lang/String;Ljava/lang/String;Lcom/zhoumohan/djinni/gen/SexModeEnum;)V") };
    const jfieldID field_id { ::djinni::jniGetFieldID(clazz.get(), "id", "I") };
    const jfieldID field_name { ::djinni::jniGetFieldID(clazz.get(), "name", "Ljava/lang/String;") };
    const jfieldID field_project { ::djinni::jniGetFieldID(clazz.get(), "project", "Ljava/lang/String;") };
    const jfieldID field_sex { ::djinni::jniGetFieldID(clazz.get(), "sex", "Lcom/zhoumohan/djinni/gen/SexModeEnum;") };
};

}  // namespace djinni_generated
