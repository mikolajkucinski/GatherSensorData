#pragma once

#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <deque>
#include <thread>
#include <iostream>
#include <string>

class Sensor
{
public:
    Sensor(boost::asio::io_service &io_service, boost::asio::ip::tcp::resolver::iterator endpoint) : ios(io_service), socket(io_service) { connect(endpoint); }
    ~Sensor()
    {
        if (dataGeneratorThread.joinable())
        {
            dataGeneratorThread.join();
        }
    }

    void connect(boost::asio::ip::tcp::resolver::iterator);
    void close();

private:
    void sendMsg();
    void generateData();
    void startDataGeneratorThread();

    std::thread dataGeneratorThread;
    boost::asio::streambuf stream_buf;
    boost::asio::io_service &ios;
    boost::asio::ip::tcp::socket socket;
    std::string data;
};
