#include "ws_svr.h"

using namespace std;
WsSvr::WsSvr()
{
    init();
}
void WsSvr::init()
{
    ep_id_card();
}
void WsSvr::ep_id_card()
{
    auto &id_card_endpoint = ws_server_.endpoint["^/id_card/?$"];
    id_card_endpoint.on_open = [&](shared_ptr<WsServer::Connection> connection) {
        auto out_message = make_shared<string>("jiangwei");
        connection->send(*out_message);
        cout << "Server: Opened connection " << connection.get() << endl;
    };

    id_card_endpoint.on_close = [&](shared_ptr<WsServer::Connection> connection, int status, const string &reason) {
        cout << "Server: Closed connection " << connection.get() << " with status code " << status << endl;
    };

    id_card_endpoint.on_error = [&](shared_ptr<WsServer::Connection> connection, const boost::system::error_code &ec) {
        cerr << "Server: Error in connection " << connection.get() << ". "
             << "Error: " << ec << ", error message: " << ec.message() << endl;
    };
    id_card_endpoint.on_message = [](shared_ptr<WsServer::Connection> connection, shared_ptr<WsServer::InMessage> in_message) {
        auto out_message = in_message->string();
        cout << "Server: Message received: \"" << out_message << "\" from " << connection.get() << endl;
        cout << "Server: Sending message \"" << out_message << "\" to " << connection.get() << endl;
        // connection->send is an asynchronous function
        connection->send(out_message, [](const SimpleWeb::error_code &ec) {
            if (ec)
            {
                cout << "Server: Error sending message. " <<
                    // See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
                    "Error: " << ec << ", error message: " << ec.message() << endl;
            }
        });
    };
}