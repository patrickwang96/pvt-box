//
// Created by Ruochen WANG on 12/5/2020.
//

#include "SessionManager.h"

SessionManager::SessionManager() {

}

void SessionManager::start(session_ptr s) {
    _sessions.insert(s);
    s->start();
}

void SessionManager::stop(session_ptr s) {
    _sessions.erase(s);
    s->stop();
}

void SessionManager::stop_all() {
    for (auto s: _sessions)
        s->stop();
    _sessions.clear();
}


