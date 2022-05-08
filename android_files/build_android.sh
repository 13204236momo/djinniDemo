#!/bin/bash

cd `dirname $0`
work_dir=$(pwd)

#配置环境变量
if [ $ANDROID_NDK_HOME ]; then
	ANDROID_NDK_ROOT= $ANDROID_NDK_HOME
fi

function clean(){
  echo "clean"
	rm -rf CMakeCache.txt
	rm -rf CMakeFiles
	rm -rf cmake_install.cmake
	rm -rf Makefile
}

function unln_source_files {
	echo "unln_source_files"
	cd ..
	base_path=$(pwd)
  library_path=${base_path}/android_files/sample

  dest_support="${library_path}/app/src/main/cpp/support_lib"
  unlink ${dest_support}

  dest_jni="${library_path}/app/src/main/cpp/jni"
  for f in $(find $dest_jni -type l); do rm -rf $f; done

  dest_header="${library_path}/app/src/main/cpp/header"
  for f in $(find $dest_header -type l); do rm -rf $f; done

  dest_src="${library_path}/app/src/main/cpp/common_src"
  for f in $(find $dest_src -type l); do rm -rf $f; done

  dest_java="${library_path}/app/src/main/java/com/zhoumohan/djinni/gen"
  for f in $(find $dest_java -type l); do rm -rf $f; done

  dest_third="${library_path}/app/src/main/cpp/third_part"
  unlink ${dest_third}
}

function ln_source_files {
	echo "ln_source_files"

	base_path=$(pwd)
	library_path=${base_path}/android_files/sample

  # djinni库相关文件软链接
	source_support="${base_path}/api_generator/support_lib"
	dest_support="${library_path}/app/src/main/cpp/support_lib"
	ln -snf $source_support $dest_support

	# djinni生成的JNI接口文件的软链接
	source_jni="${base_path}/api_generator/auto_gen/jni/common/*"
	dest_jni="${library_path}/app/src/main/cpp/jni"
	
	# djinni生成C++头文件的软链接
	source_header="${base_path}/api_generator/auto_gen/public/include/common/*"
  dest_header="${library_path}/app/src/main/cpp/header"
    
  # 自己写的C++文件的软链接
  source_src="${base_path}/src/common/*"
  dest_src="${library_path}/app/src/main/cpp/common_src"

  # 生成的java文件的软链接
  source_java="${base_path}/api_generator/auto_gen/java/common/*"
  dest_java="${library_path}/app/src/main/java/com/zhoumohan/djinni/gen"


  # 第三方库（c++）的软链接
  source_third="${base_path}/third_part"
  dest_third="${library_path}/app/src/main/cpp/third_part"
  ln -snf $source_third $dest_third

  mkdir -p $dest_jni
  mkdir -p $dest_header
  mkdir -p $dest_src
  mkdir -p $dest_java

  ln -snf $source_jni $dest_jni
  ln -snf $source_header $dest_header
  ln -snf $source_src $dest_src
  ln -snf $source_java $dest_java
}

function build_android() {
  echo "build_android"
  pwd

  cd "android_files/sample/app/src/main/cpp"

  cmake . \
      -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_ROOT/build/cmake/android.toolchain.cmake \
      -DCMAKE_SYSTEM_NAME=Android \
      -DANDROID_NDK=$ANDROID_NDK_ROOT \
      -DANDROID_ARM_NEON=ON \
      -DANDROID_PLATFORM=android-14 \
      -DANDROID_STL=c++_shared \
      -DANDROID_TOOLCHAIN=clang \
      -DCMAKE_BUILD_TYPE=Release \
      -DANDROID_ABI=armeabi-v7a

  make -j4
  clean
}


unln_source_files
ln_source_files
build_android

cd $work_dir



