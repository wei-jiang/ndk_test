#include <stdio.h>
#include <boost/asio.hpp>
#include "udp.h"

extern boost::asio::io_context io_context;
int main() {
  
  int port = 4444;
  UdpSvr us(io_context, port);
  printf("udp server listen on port: %d\n", port);
  io_context.run();
  return 0;
}