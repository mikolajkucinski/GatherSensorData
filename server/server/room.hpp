#pragma once

#include <boost/asio.hpp>
#include <memory>
#include <chrono>
#include <set>
#include <thread>
#include "circularBuffer.hpp"

class SensorSession;

class Room
{
public:
    Room() : circularBuffer(5)
    {
        startLoggingThread();
    }

    ~Room()
    {
        if (loggingThread.joinable())
        {
            loggingThread.join();
        }
    }

    void addSensor(std::shared_ptr<SensorSession> person_session);
    void removeSensor(std::shared_ptr<SensorSession> person_session);

    CircularBuffer circularBuffer;

private:
    void deliverMessages();
    void startLoggingThread();
    std::thread loggingThread;
    std::set<std::shared_ptr<SensorSession>> sensorSessions;
};
