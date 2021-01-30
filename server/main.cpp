#include <boost/asio.hpp>
#include <server.hpp>
#include <iostream>
#include <list>

int main(int argc, char *argv[])
{

    boost::asio::io_service io_service;

    if (std::atoi(argv[1]) < 1024)
    {
        return 0;
    }

    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), std::atoi(argv[1]));
    Server server(io_service, endpoint);

    io_service.run();
    return 0;
}