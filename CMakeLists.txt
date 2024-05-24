cmake_minimum_required(VERSION 3.10)
project(USBDeviceInteractions)

set(CMAKE_CXX_STANDARD 17)


# Add the executable for your test
add_executable(runTests USBDeviceReaderTests.cpp USBDeviceReader.cpp)

# Add Google Test
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Add test executable
target_link_libraries(runTests gtest gtest_main)
target_sources(runTests PRIVATE USBDeviceReader.cpp USBDeviceReaderTests.cpp)

# Add tests
include(GoogleTest)
gtest_discover_tests(runTests)