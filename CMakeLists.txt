
set(CMAKE_TOOLCHAIN_FILE "$ENV{ANDROID_NDK}/build/cmake/android.toolchain.cmake")
set(ANDROID_PLATFORM "android-21")
cmake_minimum_required (VERSION 3.8)
project (main)
add_executable(main main.cpp)