//
// Created by Ruochen WANG on 12/5/2020.
//

#ifndef CPP_DRIVE_REQUESTHANDLER_H
#define CPP_DRIVE_REQUESTHANDLER_H

#include "main.h"
#include "Request.h"
#include "Reply.h"

class RequestHandler {
private:
    // The root dir path
    std::string _root_path;
public:
    RequestHandler(const RequestHandler &) = delete;

    RequestHandler &operator=(const RequestHandler &) = delete;

    // Define the root directory to serve files when constructing requst handler
    explicit RequestHandler(const std::string &root);

    // process the given request and generate the reply object's content
    void handle(const Request &request, Reply &reply);

};


#endif //CPP_DRIVE_REQUESTHANDLER_H
