cmake_minimum_required(VERSION 3.14)
project(practice_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(practice_tests
  src/queue.h
  src/heap.h
  src/binary_tree.h
  tests/test_queue.cpp
  tests/test_heap.cpp
  tests/test_tree.cpp
)

target_link_libraries(practice_tests PRIVATE gtest gtest_main)
