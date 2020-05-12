//
// Created by Ruochen WANG on 8/5/2020.
//

#ifndef CPP_DRIVE_SESSION_H
#define CPP_DRIVE_SESSION_H

#include "main.h"
#include "RequestHandler.h"
#include "Request.h"
#include "RequestParser.h"
#include "Reply.h"

class SessionManager; // define a stub here;

class Session : public std::enable_shared_from_this<Session> {
private:
    // socket for the connection
    boost::asio::ip::tcp::socket sock;

    // TODO buffer for the incoming data?
    std::array<uint8_t, BUF_SIZE> buf{};

    // The session manager
    SessionManager &_session_manager;

    // The handler used to process the incoming request from client side
    RequestHandler &_request_handler;

    // The incoming request;
    Request _request;

    // The parser for incoming request
//    RequestParser _request_parser;

    // The reply to be sent back to the client
    Reply _reply;

    // wrapper of the boost asynchronous read method
    void do_read();

    // wrapper of the boost asynchronous write method
    void do_write();

public:
    // Session object is also non-copyable
    Session(const Session &) = delete;

    Session &operator=(const Session &) = delete;

    explicit Session(boost::asio::ip::tcp::socket socket, SessionManager &manager, RequestHandler &handler);

    void start();

    void stop();

};

typedef std::shared_ptr<Session> session_ptr;


#endif //CPP_DRIVE_SESSION_H
