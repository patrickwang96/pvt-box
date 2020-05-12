//
// Created by Ruochen WANG on 8/5/2020.
//

#include "Session.h"

using namespace boost::asio;
using namespace boost::system;

Session::Session(boost::asio::ip::tcp::socket socket, SessionManager &manager, RequestHandler &handler) :
        sock(std::move(socket)), _session_manager(manager), _request_handler(handler) {

}

void Session::start() {
    // TODO [enhancement] probably send some stupid welcome msg to client side first
    do_read();
}

void Session::stop() {
    sock.close();
}

void Session::do_read() {
    auto self(shared_from_this());

    sock.async_read_some(buffer(buf), [this, self](error_code ec, std::size_t bytes_transferred){
        if (!ec) {
            // TODO actual logic for ftp server

        } else if (ec != error::operation_aborted) {
            // TODO
//            _session_manager.stop(shared_from_this());
        }
    });
}

void Session::do_write() {
    auto self(shared_from_this());
//    TODO

}




