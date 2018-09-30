#pragma once
#include "common.h"
// #include "server_ws.hpp"
#include "server_http.hpp"

#include "ws_svr.h"
using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;
// typedef SimpleWeb::SocketServer<SimpleWeb::WS> WsServer;

class HttpSvr
{
    HttpServer server_;
    WsSvr ws_svr_;
public:
    HttpSvr(int port);
    void init();
private:
    void static_dir(const std::string& dir);
    void post_test();
    void emplace_ws();
};