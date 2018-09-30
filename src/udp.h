#pragma once

#include <boost/asio.hpp>


class UdpSvr
{    
  public:
    UdpSvr(short port);
    void do_receive();
    void do_send(std::size_t length);
  private:
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint sender_endpoint_;
    enum
    {
        max_length = 1024
    };
    char data_[max_length];
};
