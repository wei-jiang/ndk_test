
#include <thread>
#include <iostream>
#include <boost/lexical_cast.hpp>

#include "udp.h"

using namespace std;
using boost::asio::ip::udp;
std::shared_ptr<boost::asio::io_context> g_io = make_shared<boost::asio::io_context>();

UdpSvr::UdpSvr(short port)
    : socket_(*g_io, udp::endpoint(udp::v4(), port))
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