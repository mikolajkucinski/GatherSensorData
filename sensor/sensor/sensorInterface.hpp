#pragma once

#include <string>
#include <thread>
#include <memory>
#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include "sensor.hpp"

class SensorInterface
{
public:
    SensorInterface(boost::asio::io_service &io_service) : io_service(io_service) {}

    void connect(const std::string &, const std::string &);
    void close();
    std::thread spawn();

private:
    std::shared_ptr<Sensor> sensor;
    boost::asio::ip::tcp::resolver::iterator endpoint;
    boost::asio::io_service &io_service;
};
