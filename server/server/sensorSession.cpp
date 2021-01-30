#include <boost/asio.hpp>
#include <deque>
#include <iostream>
#include "sensorSession.hpp"

void SensorSession::run()
{
    room.addSensor(shared_from_this());
    readMsg();
}

void SensorSession::readMsg()
{
    auto self(shared_from_this());
    boost::asio::async_read_until(socket, stream_buf, "\n",
                                  [this, self](boost::system::error_code ec, std::size_t) {
                                      if (!ec)
                                      {
                                          std::cout << "Message received" << std::endl;
                                          std::istream is(&stream_buf);
                                          std::string incomingData;
                                          std::getline(is, incomingData);

                                          room.circularBuffer.putData(std::stof(incomingData));

                                          readMsg();
                                      }
                                      else
                                      {
                                          std::cout << ec.message() << std::endl;
                                          room.removeSensor(shared_from_this());
                                      }
                                  });
}
