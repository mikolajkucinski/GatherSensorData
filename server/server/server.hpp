#pragma once

#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include "room.hpp"
#include "sensorSession.hpp"

class Server
{
public:
    Server(boost::asio::io_service &ios, boost::asio::ip::tcp::endpoint &endpoint) : acceptor(ios, endpoint), socket(ios) { accept(); }
    void accept();

private:
    boost::asio::ip::tcp::acceptor acceptor;
    boost::asio::ip::tcp::socket socket;
    Room room;
};
