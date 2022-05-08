// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from info.djinni

#pragma once

#include "djinni_support.hpp"
#include "test_djnni_interface.h"

namespace djinni_generated {

class JNITestDjnniInterface final : ::djinni::JniInterface<::test::hello::TestDjnniInterface, JNITestDjnniInterface> {
public:
    using CppType = std::shared_ptr<::test::hello::TestDjnniInterface>;
    using CppOptType = std::shared_ptr<::test::hello::TestDjnniInterface>;
    using JniType = jobject;

    using Boxed = JNITestDjnniInterface;

    ~JNITestDjnniInterface();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<JNITestDjnniInterface>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<JNITestDjnniInterface>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    JNITestDjnniInterface();
    friend ::djinni::JniClass<JNITestDjnniInterface>;
    friend ::djinni::JniInterface<::test::hello::TestDjnniInterface, JNITestDjnniInterface>;

};

}  // namespace djinni_generated