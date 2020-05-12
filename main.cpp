//#include <iostream>
#include <boost/asio.hpp>
#include <memory>

#include "Session.h"
#include "Server.h"



int main() {

    boost::asio::io_context io_context;

    Server server(io_context, PORT);

    io_context.run();

    return 0;
}
