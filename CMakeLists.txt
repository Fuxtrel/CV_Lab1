cmake_minimum_required(VERSION 3.17)
project(test)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)

add_executable(test my_robot/main.cpp my_robot.cpp my_robot/my_robot.h)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(test ${OpenCV_LIBS})