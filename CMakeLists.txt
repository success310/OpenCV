cmake_minimum_required(VERSION 3.9)
project(OpenCV)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS )
find_package(OpenCV REQUIRED COMPONENTS core imgproc imgcodecs highgui)

set(SOURCE_FILES main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(OpenCV ${SOURCE_FILES})
target_link_libraries(OpenCV ${OpenCV_LIBS})