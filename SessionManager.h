//
// Created by Ruochen WANG on 12/5/2020.
//

#ifndef CPP_DRIVE_SESSIONMANAGER_H
#define CPP_DRIVE_SESSIONMANAGER_H

#include <set>
#include "Session.h"

class SessionManager {
private:
    // Manager's session objects
    std::set<session_ptr> _sessions;

public:
    // non-copyable
    SessionManager(const SessionManager &) = delete;

    SessionManager &operator=(const SessionManager &) = delete;

    SessionManager();

    // Add the specified connection to the manager and start it
    void start(session_ptr s);

    // Stop the specified connection
    void stop(session_ptr s);

    // Stop all session
    void stop_all();

};


#endif //CPP_DRIVE_SESSIONMANAGER_H
