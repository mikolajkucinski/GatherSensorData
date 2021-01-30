#include <boost/lexical_cast.hpp>
#include "sensor.hpp"

void Sensor::connect(boost::asio::ip::tcp::resolver::iterator endpoint)
{
    boost::asio::async_connect(socket, endpoint,
                               [this](boost::system::error_code ec, boost::asio::ip::tcp::resolver::iterator) {
                                   if (not ec)
                                   {
                                       startDataGeneratorThread();
                                   }
                                   else
                                   {
                                       throw std::runtime_error(ec.message());
                                   }
                               });
}

void Sensor::close()
{
    ios.post([this]() { socket.close(); });
}

void Sensor::sendMsg()
{
    boost::asio::async_write(socket, boost::asio::buffer(&data[0], data.size()), [this](boost::system::error_code ec, std::size_t) {
        if (ec)
        {
            throw std::runtime_error(ec.message());
        }
    });
}

void Sensor::generateData()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        float randomData = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 150));
        data = boost::lexical_cast<std::string>(randomData);
        data.append("\n");
        sendMsg();
    }
}

void Sensor::startDataGeneratorThread()
{
    dataGeneratorThread = std::thread(&Sensor::generateData, this);
}