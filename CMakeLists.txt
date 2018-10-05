
set(CMAKE_TOOLCHAIN_FILE "$ENV{ANDROID_NDK}/build/cmake/android.toolchain.cmake")
set(ANDROID_PLATFORM "android-21")
cmake_minimum_required (VERSION 3.8)
project (net)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")

set(BOOST_ROOT "/data/cpp_libs/android_libs/boost")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}/include/boost-1_67")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib")
FOREACH(LIB 
    libboost_date_time-clang-mt-s-a32-1_67.a
    libboost_atomic-clang-mt-s-a32-1_67.a
    libboost_filesystem-clang-mt-s-a32-1_67.a
    libboost_iostreams-clang-mt-s-a32-1_67.a
    libboost_system-clang-mt-s-a32-1_67.a
    libboost_timer-clang-mt-s-a32-1_67.a
)
    # MESSAGE("-------- LIB = ${LIB} --------")
    # message("${BOOST_LIBRARYDIR}/${LIB}")
    LIST(APPEND Boost_LIBRARIES "${BOOST_LIBRARYDIR}/${LIB}")
ENDFOREACH(LIB)
# MESSAGE("@@@@@@@ boost libs : ${Boost_LIBRARIES} @@@@@@@")

file(GLOB SOURCE_FILES "src/*.cc" "src/*.cpp" "src/*.h")
# add_executable(${PROJECT_NAME} ${SOURCE_FILES})
add_library(${PROJECT_NAME} ${SOURCE_FILES})

set(HEADER_DIR 
    "/data/cpp_libs/android_libs/openssl/include"
    "/data/cpp_libs/Simple-Web-Server"
    "/data/cpp_libs/Simple-WebSocket-Server"
)
target_include_directories(${PROJECT_NAME} PRIVATE ${HEADER_DIR})

set(OPENSSL_LIBRARYDIR "/data/cpp_libs/android_libs/openssl/lib")
FOREACH(LIB 
    libcrypto.a
    libssl.a
)
    LIST(APPEND OpenSSL_LIBRARIES "${OPENSSL_LIBRARYDIR}/${LIB}")
ENDFOREACH(LIB)

set(IncludeDir 
    ${BOOST_INCLUDEDIR}
    "/data/cpp_libs/spdlog/include"
)
include_directories(${IncludeDir})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${OpenSSL_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION "/data/cpp_libs/android_libs/net")
install(FILES src/export.h DESTINATION "/data/cpp_libs/android_libs/net")