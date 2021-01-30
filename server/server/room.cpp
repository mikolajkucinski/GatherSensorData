#include <boost/asio.hpp>
#include <deque>
#include <iostream>
#include "room.hpp"
#include "sensorSession.hpp"

void Room::addSensor(std::shared_ptr<SensorSession> sensorSession)
{
    sensorSessions.insert(sensorSession);
}

void Room::removeSensor(std::shared_ptr<SensorSession> sensorSession)
{
    sensorSessions.erase(sensorSession);
}

void Room::deliverMessages()
{
    while (true)
    {
        std::cout << "Server delivering data from sensors " << std::endl;
        auto availableData = circularBuffer.getAllAvailableData();
        for(const auto data : availableData)
        {
            std::cout << data << ",";
        }
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(7));
    }
}

void Room::startLoggingThread()
{
    loggingThread = std::thread(&Room::deliverMessages, this);
}