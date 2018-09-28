$ANDROID_NDK/build/tools/make_standalone_toolchain.py \
    --arch arm --api 21 --install-dir /data/tools/android-toolchain-21

$ adb push hello /data/local/tmp
$ adb shell
$ cd /data/local/tmp
$ ./hello