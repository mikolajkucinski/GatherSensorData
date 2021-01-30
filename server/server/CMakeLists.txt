add_library(
    server
    server.cpp
    room.cpp
    sensorSession.cpp
    circularBuffer.cpp
)

set_target_properties(server PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(server PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")