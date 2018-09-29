
set(CMAKE_TOOLCHAIN_FILE "$ENV{ANDROID_NDK}/build/cmake/android.toolchain.cmake")
set(ANDROID_PLATFORM "android-21")
cmake_minimum_required (VERSION 3.8)
project (main)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")

set(BOOST_ROOT "/data/cpp_libs/android_libs/boost")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}/include/boost-1_67")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib")
FOREACH(LIB 
    libboost_atomic-clang-mt-s-a32-1_67.a
    libboost_chrono-clang-mt-s-a32-1_67.a
    libboost_filesystem-clang-mt-s-a32-1_67.a
    libboost_iostreams-clang-mt-s-a32-1_67.a
    libboost_system-clang-mt-s-a32-1_67.a
    libboost_timer-clang-mt-s-a32-1_67.a
)
    MESSAGE("-------- LIB = ${LIB} --------")
    message("${BOOST_LIBRARYDIR}/${LIB}")
    LIST(APPEND Boost_LIBRARIES "${BOOST_LIBRARYDIR}/${LIB}")
ENDFOREACH(LIB)
MESSAGE("@@@@@@@ boost libs : ${Boost_LIBRARIES} @@@@@@@")

# Note: One could use a 'GLOB' here, but newly added source files won't auto-regen build files
# After adding files, you'd need to 'touch' the CMakeLists.txt to re-gen
set(SOURCE_FILES
    src/main.cpp
    src/udp.cpp
)

# Include a location to the header files
include_directories(src)


add_executable(main ${SOURCE_FILES})
include_directories(${BOOST_INCLUDEDIR})
target_link_libraries(main ${Boost_LIBRARIES})