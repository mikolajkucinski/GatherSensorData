cmake_minimum_required(VERSION 3.5)
project(mainServer)

add_subdirectory(server)

SET(CMAKE_CXX_FLAGS "-lboost_thread -pthread -lboost_system")

find_package(Boost 1.65.1.0 REQUIRED system)
include_directories( ${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

ADD_EXECUTABLE(mainServer main.cpp)

target_link_libraries(mainServer ${Boost_LIBRARIES})
target_link_libraries(mainServer server)
