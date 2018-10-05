#include "common.h"
#include "udp.h"
#include "http_svr.h"
using namespace std;

int main(int argc, const char *argv[])
{

  int port = 4444;
  UdpSvr us(port);
  HttpSvr server(port);

  g_logger->set_level(spdlog::level::trace);
  // g_logger->trace("c++ web server started at: {}", port);
  // g_logger->debug("c++ web server started at: {}", port);
  // g_logger->info("c++ web server started at: {}", port);
  // g_logger->warn("c++ web server started at: {}", port);
  // g_logger->error("c++ web server started at: {}", port);
  // g_logger->critical("c++ web server started at: {}", port);
  spdlog::flush_every(std::chrono::seconds(2));
  console->info("udp server listen on port: {}", port);
  g_io->run();
  return 0;
}

int start_svr(int port)
{
  std::thread t([port]() {
    UdpSvr us(port);
    HttpSvr server(port);
    g_logger->set_level(spdlog::level::trace);
    // g_logger->trace("c++ web server started at: {}", port);
    // g_logger->debug("c++ web server started at: {}", port);
    // g_logger->info("c++ web server started at: {}", port);
    // g_logger->warn("c++ web server started at: {}", port);
    // g_logger->error("c++ web server started at: {}", port);
    // g_logger->critical("c++ web server started at: {}", port);
    spdlog::flush_every(std::chrono::seconds(2));
    console->info("udp server listen on port: {}", port);
    g_io->run();
  });
  t.detach();
  return 0;
}