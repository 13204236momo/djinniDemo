#!/bin/bash

#返回这个脚本文件放置的目录
cd `dirname $0`

rm -rf ../auto_gen/*

djinniFile(){
	java -jar ./djinni.jar \
	     --idl ../api_idl/$1\
	     \
	     --cpp-namespace test::hello \
	     --cpp-out ../auto_gen/cpp_impl/ \
	     --cpp-header-out ../auto_gen/public/include/$2 \
	     --hpp-ext h \
	     --ident-cpp-enum FOO_BAR \
	     --ident-cpp-method FooBar \
	     \
	     --java-out ../auto_gen/java/$2/ \
	     --java-package com.zhoumohan.djinni.gen \
	     --java-use-final-for-record true \
	     --jni-out ../auto_gen/jni/$2 \
	     --ident-jni-class JNIFooBar \
	     --ident-jni-file JNIFooBar \
	     --java-implement-android-os-parcelable false \
	     \
	     --objc-out ../auto_gen/objc/$2 \
	     --objcpp-out ../auto_gen/objc-cpp/$2 \
	     --objc-swift-bridging-header "test-hello-Bridging-Header"

}

djinniFile info.djinni "common"

