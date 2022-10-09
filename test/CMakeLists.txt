cmake_minimum_required(VERSION 3.22)
project(Common_Code)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(
  ../types/
  ../la/
  ../graphics/
  ../util/
)

add_executable(
  code_test
  code_test.cxx
)

target_link_libraries(
  code_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(code_test)
