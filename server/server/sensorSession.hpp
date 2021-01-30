#pragma once

#include <boost/asio.hpp>
#include <string>
#include <deque>
#include <memory>
#include "room.hpp"

class Room;

class SensorSession : public std::enable_shared_from_this<SensorSession>
{
public:
    SensorSession(boost::asio::ip::tcp::socket socket, Room &room) : socket(std::move(socket)), room(room)
    {
    }

    void run();
    boost::asio::streambuf stream_buf;

private:
    boost::asio::ip::tcp::socket socket;
    Room &room;
    std::string read_msg_string;
    std::string incomingMessage;
    std::stringstream ss;

    // void sendMsg();
    void readMsg();
};