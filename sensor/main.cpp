#include <sensorInterface.hpp>
#include <sensor.hpp>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2 and std::stoi(std::string(argv[1])) < 1024)
    {
        return 0;
    }
    boost::asio::io_service io_service;
    SensorInterface sensorInterface(io_service);

    try
    {
        sensorInterface.connect("127.0.0.1", std::string(argv[1]));
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what();
        return 0;
    }

    std::thread thread = sensorInterface.spawn();

    thread.join();
    sensorInterface.close();

    return 0;
}