
#include <thread>
#include <iostream>
#include <boost/lexical_cast.hpp>

#include "udp.h"

using namespace std;
using boost::asio::ip::udp;
boost::asio::io_context io_context;

UdpSvr::UdpSvr(boost::asio::io_context &io_context, short port)
    : socket_(io_context, udp::endpoint(udp::v4(), port))
{
  do_receive();
}
void UdpSvr::do_receive()
{
  socket_.async_receive_from(
      boost::asio::buffer(data_, max_length), sender_endpoint_,
      [this](boost::system::error_code ec, std::size_t bytes_recvd) {
        if (!ec && bytes_recvd > 0)
        {
          do_send( bytes_recvd );
          cout<<"received: " << string(data_, bytes_recvd);
        }
        else
        {
          do_receive();
        }
      });
}

void UdpSvr::do_send(std::size_t length)
{
  socket_.async_send_to(
      boost::asio::buffer(data_, length), sender_endpoint_,
      [this](boost::system::error_code /*ec*/, std::size_t /*bytes_sent*/) {
        do_receive();
      });
}