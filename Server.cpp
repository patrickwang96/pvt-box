//
// Created by Ruochen WANG on 8/5/2020.
//

#include "Server.h"
#include "Session.h"

using namespace boost::system;
using namespace boost::asio::ip;


Server::Server(std::string &addr, uint16_t &port, std::string &root) :
        _io_context(1), _singals(_io_context), _acceptor(_io_context),
        _session_manager(), _request_handler() {

    // register the singals so that the server should know when to exit.
    this->_singals.add(SIGINT);
    this->_singals.add(SIGTERM);

    this->do_await_stop();

    // Open the acceptor
    tcp::resolver resolver(_io_context);
    tcp::endpoint endpoint = *resolver.resolve(addr, std::to_string(port)).begin();
    _acceptor.open(endpoint.protocol());
    _acceptor.set_option(tcp::acceptor::reuse_address(true));
    _acceptor.bind(endpoint);
    _acceptor.listen();

    // do_accept is a endless recursion
    do_accept();
}

void Server::run() {
    _io_context.run();
}

void Server::do_accept() {
    _acceptor.async_accept(
            [this](error_code ec, tcp::socket socket) {
                // check if the server has been stop before this handle is called
                if (!_acceptor.is_open()) return;

                if (!ec) {
                    _session_manager.start(
                            std::make_shared<Session>(std::move(socket), _session_manager, _request_handler));
                }
                do_accept();
            });
}

void Server::do_await_stop() {
    this->_singals.async_wait([this]
                                      (error_code, int) {
                                  _acceptor.close();
                                  _session_manager.stop_all();
                              }
    );

}


