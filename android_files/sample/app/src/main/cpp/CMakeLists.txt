
#设置工程名
project("mytest")
#设置最低版本
cmake_minimum_required(VERSION 3.6.0)

#给变量赋值,设置编译参数，指定c++标椎库
#set(CMAKE_C_FLAGS_RELEASE "-std=c++11 -O2 -s ")
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++11 -O2 ")
#set(CMAKE_C_FLAGS_DEBUG "-std=c++11 -O2 ")
set(CMAKE_CXX_FLAGS_DEBUG "-std=c++11 -O2 ")


set(COMMON_SRC_ROOT "./common_src/")
#加载以下路径中的所有文件
file(GLOB all_src
        "${COMMON_SRC_ROOT}/*.hpp"
        "${COMMON_SRC_ROOT}/*.cpp"
        )

#构建一个库供他人使用（库名称(name) 库类型 源文件），
#用于指定从一组源文件 source1 source2 … sourceN 编译出一个库文件且命名为 name
add_library(mytest SHARED
        ${all_src})

file(GLOB jni_src
        "${CMAKE_CURRENT_SOURCE_DIR}/jni/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/jni/*.cpp"
        )
#向test库添加源文件
target_sources(mytest PRIVATE ${jni_src})

#添加头文件
target_include_directories(mytest PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/header
        )

#添加头文件
target_include_directories(mytest PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/support_lib/include/jni
        ${CMAKE_CURRENT_SOURCE_DIR}/support_lib/include
        )

file(GLOB support_src
        "${CMAKE_CURRENT_SOURCE_DIR}/support_lib/*.cpp"
        )
target_sources(mytest PRIVATE ${support_src})

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../..)
if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
    set_target_properties(mytest
            PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_ROOT}/android_files/android_out/${CMAKE_ANDROID_ARCH_ABI}"
            LIBRARY_OUTPUT_DIRECTORY "${PROJECT_ROOT}/android_files/android_out/${CMAKE_ANDROID_ARCH_ABI}")
elseif (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set_target_properties(mytest
            PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_ROOT}/android_files/android_out/${CMAKE_ANDROID_ARCH_ABI}/Debug"
            LIBRARY_OUTPUT_DIRECTORY "${PROJECT_ROOT}/android_files/android_out/${CMAKE_ANDROID_ARCH_ABI}/Debug")
endif()


find_library( log-lib
              log )

target_link_libraries( mytest
                       ${log-lib} )