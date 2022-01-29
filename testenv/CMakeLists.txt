cmake_minimum_required(VERSION "3.21")
project("testenv")

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
message("Binary direcotry: " ${CMAKE_BINARY_DIR})

###############################################################
# EIGEN
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

###############################################################
# GLOG
find_package (glog REQUIRED)
include_directories(${GLOG_INCLUDE_DIR})

###############################################################
# GTEST
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_library(utils SHARED "utils.cpp")

add_executable("${PROJECT_NAME}" "tests.cpp")
target_link_libraries("${PROJECT_NAME}" utils)
target_link_libraries("${PROJECT_NAME}" Eigen3::Eigen)
target_link_libraries("${PROJECT_NAME}" gtest gtest_main)

add_executable(main "main.cpp")
target_link_libraries(main Eigen3::Eigen)
target_link_libraries(main glog::glog)

include(GoogleTest)
gtest_discover_tests("${PROJECT_NAME}")
add_test("${PROJECT_NAME}" "${PROJECT_NAME}")


