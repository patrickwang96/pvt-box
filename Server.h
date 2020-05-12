//
// Created by Ruochen WANG on 8/5/2020.
//

#ifndef CPP_DRIVE_SERVER_H
#define CPP_DRIVE_SERVER_H

#include <string>
#include "main.h"
#include "SessionManager.h"
#include "RequestHandler.h"


class Server {
private:
    // boost's io_context, acceptor and signal set for network operation management
    boost::asio::ip::tcp::acceptor _acceptor;
    boost::asio::io_context _io_context;
    boost::asio::signal_set _singals;

    // The session manager will own all existing tcp connection.
    SessionManager _session_manager;

    // The handler for all incoming requests
    RequestHandler _request_handler;

    void do_accept();

    void do_await_stop();

public:

    // Server obviously should be non-copyable
    Server(const Server &) = delete;

    Server &operator=(const Server &) = delete;

    // Construct the server instance with given tcp addr and port. And serve files within
    // the given directory path.
    explicit Server(std::string &addr, std::uint16_t &port, std::string &root);

    void run();

};


#endif //CPP_DRIVE_SERVER_H
