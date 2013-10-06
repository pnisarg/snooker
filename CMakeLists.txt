cmake_minimum_required(VERSION 2.6)
project(snooker)
find_package(OpenCV REQUIRED)
add_executable(snooker snooker.cpp ballDetect.cpp)
target_link_libraries(snooker ${OpenCV_LIBS})



