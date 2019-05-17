cmake_minimum_required(VERSION 2.6)

project(myapp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(STEP1_SRC src/step1_source.cpp src/functions.h)
set(STEP1T_SRC src/step1_test.cpp src/functions.h)
set(STEP2_SRC src/step2_source.cpp src/functions.h)
set(STEP2T_SRC src/step2_test.cpp src/functions.h)

add_executable(runStep1 ${STEP1_SRC})
add_executable(runStep1Tests ${STEP1T_SRC})
add_executable(runStep2 ${STEP2_SRC})
add_executable(runStep2Tests ${STEP2T_SRC})

target_link_libraries(runStep1 ${GTEST_LIBRARIES} pthread)
target_link_libraries(runStep1Tests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runStep2 ${GTEST_LIBRARIES} pthread)
target_link_libraries(runStep2Tests ${GTEST_LIBRARIES} pthread)
