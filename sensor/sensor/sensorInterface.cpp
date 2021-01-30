#include "sensorInterface.hpp"

void SensorInterface::connect(const std::string &ip, const std::string &port)
{
    boost::asio::ip::tcp::resolver resolver(io_service);
    boost::asio::ip::tcp::resolver::iterator endpoint = resolver.resolve({ip, port});
    sensor = std::make_shared<Sensor>(io_service, endpoint);
}

void SensorInterface::close()
{
    sensor->close();
}

std::thread SensorInterface::spawn()
{
    return std::thread([this] { io_service.run(); });
}