#include <boost/asio.hpp>
#include <iostream>
#include "server.hpp"

void Server::accept()
{
    acceptor.async_accept(socket,
                          [this](boost::system::error_code ec) {
                              if (not ec)
                              {
                                  std::cout << "Server accepted new sensor connection" << std::endl;
                                  std::make_shared<SensorSession>(std::move(socket), room)
                                      ->run();
                              }
                              accept();
                          });
}