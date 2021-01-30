cmake_minimum_required(VERSION 3.5)
project(mainSensor)

add_subdirectory(sensor)

SET(CMAKE_CXX_FLAGS "-lboost_thread -pthread -lboost_system")

find_package(Boost 1.65.1.0 REQUIRED system)
include_directories( ${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

ADD_EXECUTABLE(mainSensor main.cpp)

target_link_libraries(mainSensor ${Boost_LIBRARIES})
target_link_libraries(mainSensor sensor)
