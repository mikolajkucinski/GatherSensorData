add_library(
    sensor
    sensor.cpp
    sensorInterface.cpp
)

set_target_properties(sensor PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(sensor PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")